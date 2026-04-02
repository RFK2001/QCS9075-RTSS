#ifndef __HALVMIDMTHWIOTARGET_H__
#define __HALVMIDMTHWIOTARGET_H__
/*
===========================================================================
*/
/**
  @file HALvmidmtHWIOTarget.h
  @brief Auto-generated HWIO interface include file.

  This file contains HWIO register definitions for the following modules:
    .*VMIDMT.*

  'Include' filters applied: .*VMIDMT.* 
  'Exclude' filters applied: RESERVED DUMMY 
*/
/*
  ===========================================================================

  Copyright (c) 2015 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  Qualcomm Confidential and Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/security/accesscontrol/vmidmt/config/hal/stubs/HALvmidmtHWIOTarget.h#1 $
  $DateTime: 2025/07/09 22:36:30 $
  $Author: rmunibyr $

  ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SPDM_VMIDMT_IDX_1_SSD0
 *--------------------------------------------------------------------------*/

#define SPDM_VMIDMT_IDX_1_SSD0_REG_BASE                           (0      + 0x00005000)
#define SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS                      0x00005000

#define HWIO_SPDM_VMIDMT_SCR0_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000000)
#define HWIO_SPDM_VMIDMT_SCR0_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000000)
#define HWIO_SPDM_VMIDMT_SCR0_RMSK                                0x3fd707f5
#define HWIO_SPDM_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SCR0_ADDR, HWIO_SPDM_VMIDMT_SCR0_RMSK)
#define HWIO_SPDM_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SCR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_SCR0_ADDR,v)
#define HWIO_SPDM_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_SCR0_ADDR,m,v,HWIO_SPDM_VMIDMT_SCR0_IN)
#define HWIO_SPDM_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_SPDM_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_SPDM_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_SPDM_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_SPDM_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_SPDM_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_SPDM_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_SPDM_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_SPDM_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_SPDM_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_SPDM_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_SPDM_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_SPDM_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_SPDM_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_SPDM_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_SPDM_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_SPDM_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_SPDM_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_SPDM_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_SPDM_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_SPDM_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_SPDM_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_SPDM_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_SPDM_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_SPDM_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_SPDM_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_SPDM_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_SPDM_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_SPDM_VMIDMT_SCR1_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000004)
#define HWIO_SPDM_VMIDMT_SCR1_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000004)
#define HWIO_SPDM_VMIDMT_SCR1_RMSK                                 0x1000100
#define HWIO_SPDM_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SCR1_ADDR, HWIO_SPDM_VMIDMT_SCR1_RMSK)
#define HWIO_SPDM_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SCR1_ADDR, m)
#define HWIO_SPDM_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_SCR1_ADDR,v)
#define HWIO_SPDM_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_SCR1_ADDR,m,v,HWIO_SPDM_VMIDMT_SCR1_IN)
#define HWIO_SPDM_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_SPDM_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_SPDM_VMIDMT_SCR1_NSNUMSMRGO_BMSK                          0x100
#define HWIO_SPDM_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_SPDM_VMIDMT_SCR2_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000008)
#define HWIO_SPDM_VMIDMT_SCR2_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000008)
#define HWIO_SPDM_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_SPDM_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SCR2_ADDR, HWIO_SPDM_VMIDMT_SCR2_RMSK)
#define HWIO_SPDM_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SCR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_SCR2_ADDR,v)
#define HWIO_SPDM_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_SCR2_ADDR,m,v,HWIO_SPDM_VMIDMT_SCR2_IN)
#define HWIO_SPDM_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_SPDM_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_SPDM_VMIDMT_SACR_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000010)
#define HWIO_SPDM_VMIDMT_SACR_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000010)
#define HWIO_SPDM_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_SPDM_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SACR_ADDR, HWIO_SPDM_VMIDMT_SACR_RMSK)
#define HWIO_SPDM_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SACR_ADDR, m)
#define HWIO_SPDM_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_SACR_ADDR,v)
#define HWIO_SPDM_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_SACR_ADDR,m,v,HWIO_SPDM_VMIDMT_SACR_IN)
#define HWIO_SPDM_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_SPDM_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_SPDM_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_SPDM_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_SPDM_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_SPDM_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_SPDM_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_SPDM_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_SPDM_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_SPDM_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_SPDM_VMIDMT_SIDR0_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000020)
#define HWIO_SPDM_VMIDMT_SIDR0_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000020)
#define HWIO_SPDM_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_SPDM_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR0_ADDR, HWIO_SPDM_VMIDMT_SIDR0_RMSK)
#define HWIO_SPDM_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_SPDM_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_SPDM_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_SPDM_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_SPDM_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_SPDM_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_SPDM_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_SPDM_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_SPDM_VMIDMT_SIDR1_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000024)
#define HWIO_SPDM_VMIDMT_SIDR1_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000024)
#define HWIO_SPDM_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_SPDM_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR1_ADDR, HWIO_SPDM_VMIDMT_SIDR1_RMSK)
#define HWIO_SPDM_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR1_ADDR, m)
#define HWIO_SPDM_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_SPDM_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_SPDM_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_SPDM_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_SPDM_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_SPDM_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_SPDM_VMIDMT_SIDR2_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000028)
#define HWIO_SPDM_VMIDMT_SIDR2_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000028)
#define HWIO_SPDM_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_SPDM_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR2_ADDR, HWIO_SPDM_VMIDMT_SIDR2_RMSK)
#define HWIO_SPDM_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_SPDM_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_SPDM_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_SPDM_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_SPDM_VMIDMT_SIDR4_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000030)
#define HWIO_SPDM_VMIDMT_SIDR4_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000030)
#define HWIO_SPDM_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_SPDM_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR4_ADDR, HWIO_SPDM_VMIDMT_SIDR4_RMSK)
#define HWIO_SPDM_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR4_ADDR, m)
#define HWIO_SPDM_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_SPDM_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_SPDM_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_SPDM_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_SPDM_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_SPDM_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_SPDM_VMIDMT_SIDR5_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000034)
#define HWIO_SPDM_VMIDMT_SIDR5_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000034)
#define HWIO_SPDM_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_SPDM_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR5_ADDR, HWIO_SPDM_VMIDMT_SIDR5_RMSK)
#define HWIO_SPDM_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR5_ADDR, m)
#define HWIO_SPDM_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_SPDM_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_SPDM_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_SPDM_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_SPDM_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_SPDM_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_SPDM_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_SPDM_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_SPDM_VMIDMT_SIDR7_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x0000003c)
#define HWIO_SPDM_VMIDMT_SIDR7_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x0000003c)
#define HWIO_SPDM_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_SPDM_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR7_ADDR, HWIO_SPDM_VMIDMT_SIDR7_RMSK)
#define HWIO_SPDM_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SIDR7_ADDR, m)
#define HWIO_SPDM_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_SPDM_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_SPDM_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_SPDM_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_SPDM_VMIDMT_SGFAR0_ADDR                              (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000040)
#define HWIO_SPDM_VMIDMT_SGFAR0_OFFS                              (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000040)
#define HWIO_SPDM_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_SPDM_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFAR0_ADDR, HWIO_SPDM_VMIDMT_SGFAR0_RMSK)
#define HWIO_SPDM_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_SPDM_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_SPDM_VMIDMT_SGFSR_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000048)
#define HWIO_SPDM_VMIDMT_SGFSR_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000048)
#define HWIO_SPDM_VMIDMT_SGFSR_RMSK                               0xc0000022
#define HWIO_SPDM_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSR_ADDR, HWIO_SPDM_VMIDMT_SGFSR_RMSK)
#define HWIO_SPDM_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSR_ADDR, m)
#define HWIO_SPDM_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_SGFSR_ADDR,v)
#define HWIO_SPDM_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_SGFSR_ADDR,m,v,HWIO_SPDM_VMIDMT_SGFSR_IN)
#define HWIO_SPDM_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_SPDM_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_SPDM_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_SPDM_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_SPDM_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_SPDM_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_SPDM_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_SPDM_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_ADDR                        (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x0000004c)
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_OFFS                        (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x0000004c)
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000022
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSRRESTORE_ADDR, HWIO_SPDM_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_SPDM_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_SPDM_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_SPDM_VMIDMT_SGFSYNDR0_ADDR                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000050)
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_OFFS                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000050)
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSYNDR0_ADDR, HWIO_SPDM_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_SPDM_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_SPDM_VMIDMT_SGFSYNDR1_ADDR                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000054)
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_OFFS                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000054)
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_RMSK                              0x10001
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSYNDR1_ADDR, HWIO_SPDM_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                      0x1
#define HWIO_SPDM_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_SPDM_VMIDMT_SGFSYNDR2_ADDR                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000058)
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_OFFS                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000058)
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSYNDR2_ADDR, HWIO_SPDM_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_SPDM_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_ADDR                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000090)
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_OFFS                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000090)
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_VMIDMTSCR0_ADDR, HWIO_SPDM_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_SPDM_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_SPDM_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_SPDM_VMIDMT_CR0_ADDR                                 (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000000)
#define HWIO_SPDM_VMIDMT_CR0_OFFS                                 (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000000)
#define HWIO_SPDM_VMIDMT_CR0_RMSK                                  0xfd70ff5
#define HWIO_SPDM_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_CR0_ADDR, HWIO_SPDM_VMIDMT_CR0_RMSK)
#define HWIO_SPDM_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_CR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_CR0_ADDR,v)
#define HWIO_SPDM_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_CR0_ADDR,m,v,HWIO_SPDM_VMIDMT_CR0_IN)
#define HWIO_SPDM_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_SPDM_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_SPDM_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_SPDM_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_SPDM_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_SPDM_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_SPDM_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_SPDM_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_SPDM_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_SPDM_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_SPDM_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_SPDM_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_SPDM_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_SPDM_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_SPDM_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_SPDM_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_SPDM_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_SPDM_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_SPDM_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_SPDM_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_SPDM_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_SPDM_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_SPDM_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_SPDM_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_SPDM_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_SPDM_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_SPDM_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_SPDM_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_SPDM_VMIDMT_CR2_ADDR                                 (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000008)
#define HWIO_SPDM_VMIDMT_CR2_OFFS                                 (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000008)
#define HWIO_SPDM_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_SPDM_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_CR2_ADDR, HWIO_SPDM_VMIDMT_CR2_RMSK)
#define HWIO_SPDM_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_CR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_CR2_ADDR,v)
#define HWIO_SPDM_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_CR2_ADDR,m,v,HWIO_SPDM_VMIDMT_CR2_IN)
#define HWIO_SPDM_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_SPDM_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_SPDM_VMIDMT_ACR_ADDR                                 (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000010)
#define HWIO_SPDM_VMIDMT_ACR_OFFS                                 (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000010)
#define HWIO_SPDM_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_SPDM_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_ACR_ADDR, HWIO_SPDM_VMIDMT_ACR_RMSK)
#define HWIO_SPDM_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_ACR_ADDR, m)
#define HWIO_SPDM_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_ACR_ADDR,v)
#define HWIO_SPDM_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_ACR_ADDR,m,v,HWIO_SPDM_VMIDMT_ACR_IN)
#define HWIO_SPDM_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_SPDM_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_SPDM_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_SPDM_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_SPDM_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_SPDM_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_SPDM_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_SPDM_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_SPDM_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_SPDM_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_SPDM_VMIDMT_IDR0_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000020)
#define HWIO_SPDM_VMIDMT_IDR0_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000020)
#define HWIO_SPDM_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_SPDM_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR0_ADDR, HWIO_SPDM_VMIDMT_IDR0_RMSK)
#define HWIO_SPDM_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_SPDM_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_SPDM_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_SPDM_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_SPDM_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_SPDM_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_SPDM_VMIDMT_IDR1_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000024)
#define HWIO_SPDM_VMIDMT_IDR1_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000024)
#define HWIO_SPDM_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_SPDM_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR1_ADDR, HWIO_SPDM_VMIDMT_IDR1_RMSK)
#define HWIO_SPDM_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR1_ADDR, m)
#define HWIO_SPDM_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_SPDM_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_SPDM_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_SPDM_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_SPDM_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_SPDM_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_SPDM_VMIDMT_IDR2_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000028)
#define HWIO_SPDM_VMIDMT_IDR2_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000028)
#define HWIO_SPDM_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_SPDM_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR2_ADDR, HWIO_SPDM_VMIDMT_IDR2_RMSK)
#define HWIO_SPDM_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_SPDM_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_SPDM_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_SPDM_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_SPDM_VMIDMT_IDR4_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000030)
#define HWIO_SPDM_VMIDMT_IDR4_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000030)
#define HWIO_SPDM_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_SPDM_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR4_ADDR, HWIO_SPDM_VMIDMT_IDR4_RMSK)
#define HWIO_SPDM_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR4_ADDR, m)
#define HWIO_SPDM_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_SPDM_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_SPDM_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_SPDM_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_SPDM_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_SPDM_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_SPDM_VMIDMT_IDR5_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000034)
#define HWIO_SPDM_VMIDMT_IDR5_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000034)
#define HWIO_SPDM_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_SPDM_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR5_ADDR, HWIO_SPDM_VMIDMT_IDR5_RMSK)
#define HWIO_SPDM_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR5_ADDR, m)
#define HWIO_SPDM_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_SPDM_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_SPDM_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_SPDM_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_SPDM_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_SPDM_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_SPDM_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_SPDM_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_SPDM_VMIDMT_IDR7_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x0000003c)
#define HWIO_SPDM_VMIDMT_IDR7_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x0000003c)
#define HWIO_SPDM_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_SPDM_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR7_ADDR, HWIO_SPDM_VMIDMT_IDR7_RMSK)
#define HWIO_SPDM_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_IDR7_ADDR, m)
#define HWIO_SPDM_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_SPDM_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_SPDM_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_SPDM_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_SPDM_VMIDMT_GFAR0_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000040)
#define HWIO_SPDM_VMIDMT_GFAR0_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000040)
#define HWIO_SPDM_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_SPDM_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFAR0_ADDR, HWIO_SPDM_VMIDMT_GFAR0_RMSK)
#define HWIO_SPDM_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFAR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_SPDM_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_SPDM_VMIDMT_GFSR_ADDR                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000048)
#define HWIO_SPDM_VMIDMT_GFSR_OFFS                                (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000048)
#define HWIO_SPDM_VMIDMT_GFSR_RMSK                                0xc00000a2
#define HWIO_SPDM_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSR_ADDR, HWIO_SPDM_VMIDMT_GFSR_RMSK)
#define HWIO_SPDM_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSR_ADDR, m)
#define HWIO_SPDM_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_GFSR_ADDR,v)
#define HWIO_SPDM_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_GFSR_ADDR,m,v,HWIO_SPDM_VMIDMT_GFSR_IN)
#define HWIO_SPDM_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_SPDM_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_SPDM_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_SPDM_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_SPDM_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_SPDM_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_SPDM_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_SPDM_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_SPDM_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_SPDM_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_SPDM_VMIDMT_GFSRRESTORE_ADDR                         (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x0000004c)
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_OFFS                         (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x0000004c)
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a2
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSRRESTORE_ADDR, HWIO_SPDM_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_SPDM_VMIDMT_GFSRRESTORE_IN)
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_SPDM_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_SPDM_VMIDMT_GFSYNDR0_ADDR                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000050)
#define HWIO_SPDM_VMIDMT_GFSYNDR0_OFFS                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000050)
#define HWIO_SPDM_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_SPDM_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSYNDR0_ADDR, HWIO_SPDM_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_SPDM_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_SPDM_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_SPDM_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_SPDM_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_SPDM_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_SPDM_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_SPDM_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_SPDM_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_SPDM_VMIDMT_GFSYNDR1_ADDR                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000054)
#define HWIO_SPDM_VMIDMT_GFSYNDR1_OFFS                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000054)
#define HWIO_SPDM_VMIDMT_GFSYNDR1_RMSK                               0x10001
#define HWIO_SPDM_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSYNDR1_ADDR, HWIO_SPDM_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_SPDM_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_SPDM_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000
#define HWIO_SPDM_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_SPDM_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                       0x1
#define HWIO_SPDM_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_SPDM_VMIDMT_GFSYNDR2_ADDR                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000058)
#define HWIO_SPDM_VMIDMT_GFSYNDR2_OFFS                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000058)
#define HWIO_SPDM_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_SPDM_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSYNDR2_ADDR, HWIO_SPDM_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_SPDM_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_SPDM_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_SPDM_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_SPDM_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_SPDM_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_SPDM_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_SPDM_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_SPDM_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_SPDM_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_SPDM_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_SPDM_VMIDMT_VMIDMTCR0_ADDR                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000090)
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_OFFS                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000090)
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_VMIDMTCR0_ADDR, HWIO_SPDM_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_SPDM_VMIDMT_VMIDMTCR0_IN)
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_SPDM_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_SPDM_VMIDMT_VMIDMTACR_ADDR                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x0000009c)
#define HWIO_SPDM_VMIDMT_VMIDMTACR_OFFS                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x0000009c)
#define HWIO_SPDM_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_SPDM_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_VMIDMTACR_ADDR, HWIO_SPDM_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_SPDM_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_SPDM_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_SPDM_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_SPDM_VMIDMT_VMIDMTACR_IN)
#define HWIO_SPDM_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_SPDM_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_SPDM_VMIDMT_NSCR0_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000400)
#define HWIO_SPDM_VMIDMT_NSCR0_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000400)
#define HWIO_SPDM_VMIDMT_NSCR0_RMSK                                0xfd70ff5
#define HWIO_SPDM_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSCR0_ADDR, HWIO_SPDM_VMIDMT_NSCR0_RMSK)
#define HWIO_SPDM_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSCR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_NSCR0_ADDR,v)
#define HWIO_SPDM_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_NSCR0_ADDR,m,v,HWIO_SPDM_VMIDMT_NSCR0_IN)
#define HWIO_SPDM_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_SPDM_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_SPDM_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_SPDM_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_SPDM_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_SPDM_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_SPDM_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_SPDM_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_SPDM_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_SPDM_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_SPDM_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_SPDM_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_SPDM_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_SPDM_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_SPDM_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_SPDM_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_SPDM_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_SPDM_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_SPDM_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_SPDM_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_SPDM_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_SPDM_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_SPDM_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_SPDM_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_SPDM_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_SPDM_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_SPDM_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_SPDM_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_SPDM_VMIDMT_NSCR2_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000408)
#define HWIO_SPDM_VMIDMT_NSCR2_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000408)
#define HWIO_SPDM_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_SPDM_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSCR2_ADDR, HWIO_SPDM_VMIDMT_NSCR2_RMSK)
#define HWIO_SPDM_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSCR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_NSCR2_ADDR,v)
#define HWIO_SPDM_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_NSCR2_ADDR,m,v,HWIO_SPDM_VMIDMT_NSCR2_IN)
#define HWIO_SPDM_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_SPDM_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_SPDM_VMIDMT_NSACR_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000410)
#define HWIO_SPDM_VMIDMT_NSACR_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000410)
#define HWIO_SPDM_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_SPDM_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSACR_ADDR, HWIO_SPDM_VMIDMT_NSACR_RMSK)
#define HWIO_SPDM_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSACR_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_NSACR_ADDR,v)
#define HWIO_SPDM_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_NSACR_ADDR,m,v,HWIO_SPDM_VMIDMT_NSACR_IN)
#define HWIO_SPDM_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_SPDM_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_SPDM_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_SPDM_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_SPDM_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_SPDM_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_SPDM_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_SPDM_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_SPDM_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_SPDM_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_SPDM_VMIDMT_NSGFAR0_ADDR                             (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000440)
#define HWIO_SPDM_VMIDMT_NSGFAR0_OFFS                             (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000440)
#define HWIO_SPDM_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_SPDM_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFAR0_ADDR, HWIO_SPDM_VMIDMT_NSGFAR0_RMSK)
#define HWIO_SPDM_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_SPDM_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_SPDM_VMIDMT_NSGFSR_ADDR                              (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000448)
#define HWIO_SPDM_VMIDMT_NSGFSR_OFFS                              (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000448)
#define HWIO_SPDM_VMIDMT_NSGFSR_RMSK                              0xc00000a2
#define HWIO_SPDM_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSR_ADDR, HWIO_SPDM_VMIDMT_NSGFSR_RMSK)
#define HWIO_SPDM_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_SPDM_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_NSGFSR_ADDR,m,v,HWIO_SPDM_VMIDMT_NSGFSR_IN)
#define HWIO_SPDM_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_SPDM_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_SPDM_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_SPDM_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_SPDM_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_SPDM_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_SPDM_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_SPDM_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_SPDM_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_SPDM_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_ADDR                       (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x0000044c)
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_OFFS                       (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x0000044c)
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a2
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_SPDM_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_SPDM_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_SPDM_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_ADDR                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000450)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_OFFS                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000450)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSYNDR0_ADDR, HWIO_SPDM_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_SPDM_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_ADDR                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000454)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_OFFS                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000454)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_RMSK                             0x10001
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSYNDR1_ADDR, HWIO_SPDM_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                     0x1
#define HWIO_SPDM_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_ADDR                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000458)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_OFFS                          (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000458)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSYNDR2_ADDR, HWIO_SPDM_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_SPDM_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_ADDR                         (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000490)
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_OFFS                         (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000490)
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_SPDM_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_SPDM_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_SPDM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_SPDM_VMIDMT_SSDR0_ADDR                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000080)
#define HWIO_SPDM_VMIDMT_SSDR0_OFFS                               (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000080)
#define HWIO_SPDM_VMIDMT_SSDR0_RMSK                                      0x1
#define HWIO_SPDM_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_SPDM_VMIDMT_SSDR0_ADDR, HWIO_SPDM_VMIDMT_SSDR0_RMSK)
#define HWIO_SPDM_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_SPDM_VMIDMT_SSDR0_ADDR, m)
#define HWIO_SPDM_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_SPDM_VMIDMT_SSDR0_ADDR,v)
#define HWIO_SPDM_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_SSDR0_ADDR,m,v,HWIO_SPDM_VMIDMT_SSDR0_IN)
#define HWIO_SPDM_VMIDMT_SSDR0_RWE_BMSK                                  0x1
#define HWIO_SPDM_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_SPDM_VMIDMT_S2VRn_ADDR(n)                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_SPDM_VMIDMT_S2VRn_OFFS(n)                            (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_SPDM_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_SPDM_VMIDMT_S2VRn_MAXn                                        0
#define HWIO_SPDM_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_SPDM_VMIDMT_S2VRn_ADDR(n), HWIO_SPDM_VMIDMT_S2VRn_RMSK)
#define HWIO_SPDM_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_SPDM_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_SPDM_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_SPDM_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_SPDM_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_SPDM_VMIDMT_S2VRn_INI(n))
#define HWIO_SPDM_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_SPDM_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_SPDM_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_SPDM_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_SPDM_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_SPDM_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_SPDM_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_SPDM_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_SPDM_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_SPDM_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_SPDM_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_SPDM_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_SPDM_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_SPDM_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_SPDM_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_SPDM_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_SPDM_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_SPDM_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_SPDM_VMIDMT_AS2VRn_ADDR(n)                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_SPDM_VMIDMT_AS2VRn_OFFS(n)                           (SPDM_VMIDMT_IDX_1_SSD0_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_SPDM_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_SPDM_VMIDMT_AS2VRn_MAXn                                       0
#define HWIO_SPDM_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_SPDM_VMIDMT_AS2VRn_ADDR(n), HWIO_SPDM_VMIDMT_AS2VRn_RMSK)
#define HWIO_SPDM_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_SPDM_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_SPDM_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_SPDM_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_SPDM_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_SPDM_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_SPDM_VMIDMT_AS2VRn_INI(n))
#define HWIO_SPDM_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_SPDM_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_SPDM_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_SPDM_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_SPDM_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_SPDM_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_SPDM_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_SPDM_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_SPDM_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_SPDM_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

/*----------------------------------------------------------------------------
 * MODULE: RPM_VMIDMT
 *--------------------------------------------------------------------------*/

#define RPM_VMIDMT_REG_BASE                                      (0      + 0x00088000)
#define RPM_VMIDMT_REG_BASE_OFFS                                 0x00088000

#define HWIO_RPM_VMIDMT_SCR0_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_RPM_VMIDMT_SCR0_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_RPM_VMIDMT_SCR0_RMSK                                0x3fd707f5
#define HWIO_RPM_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SCR0_ADDR, HWIO_RPM_VMIDMT_SCR0_RMSK)
#define HWIO_RPM_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SCR0_ADDR, m)
#define HWIO_RPM_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_SCR0_ADDR,v)
#define HWIO_RPM_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_SCR0_ADDR,m,v,HWIO_RPM_VMIDMT_SCR0_IN)
#define HWIO_RPM_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_RPM_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_RPM_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_RPM_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_RPM_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_RPM_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_RPM_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_RPM_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_RPM_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_RPM_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_RPM_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_RPM_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_RPM_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_RPM_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_RPM_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_RPM_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_RPM_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_RPM_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_RPM_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_RPM_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_RPM_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_RPM_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_RPM_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_RPM_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_RPM_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_RPM_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_RPM_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_RPM_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_RPM_VMIDMT_SCR1_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000004)
#define HWIO_RPM_VMIDMT_SCR1_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000004)
#define HWIO_RPM_VMIDMT_SCR1_RMSK                                 0x1000100
#define HWIO_RPM_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SCR1_ADDR, HWIO_RPM_VMIDMT_SCR1_RMSK)
#define HWIO_RPM_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SCR1_ADDR, m)
#define HWIO_RPM_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_SCR1_ADDR,v)
#define HWIO_RPM_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_SCR1_ADDR,m,v,HWIO_RPM_VMIDMT_SCR1_IN)
#define HWIO_RPM_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_RPM_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_RPM_VMIDMT_SCR1_NSNUMSMRGO_BMSK                          0x100
#define HWIO_RPM_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_RPM_VMIDMT_SCR2_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_RPM_VMIDMT_SCR2_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_RPM_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_RPM_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SCR2_ADDR, HWIO_RPM_VMIDMT_SCR2_RMSK)
#define HWIO_RPM_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SCR2_ADDR, m)
#define HWIO_RPM_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_SCR2_ADDR,v)
#define HWIO_RPM_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_SCR2_ADDR,m,v,HWIO_RPM_VMIDMT_SCR2_IN)
#define HWIO_RPM_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_RPM_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_RPM_VMIDMT_SACR_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_RPM_VMIDMT_SACR_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_RPM_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_RPM_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SACR_ADDR, HWIO_RPM_VMIDMT_SACR_RMSK)
#define HWIO_RPM_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SACR_ADDR, m)
#define HWIO_RPM_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_SACR_ADDR,v)
#define HWIO_RPM_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_SACR_ADDR,m,v,HWIO_RPM_VMIDMT_SACR_IN)
#define HWIO_RPM_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_RPM_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_RPM_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_RPM_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_RPM_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_RPM_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_RPM_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_RPM_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_RPM_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_RPM_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_RPM_VMIDMT_SIDR0_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_RPM_VMIDMT_SIDR0_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_RPM_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_RPM_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR0_ADDR, HWIO_RPM_VMIDMT_SIDR0_RMSK)
#define HWIO_RPM_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR0_ADDR, m)
#define HWIO_RPM_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_RPM_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_RPM_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_RPM_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_RPM_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_RPM_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_RPM_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_RPM_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_RPM_VMIDMT_SIDR1_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_RPM_VMIDMT_SIDR1_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_RPM_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_RPM_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR1_ADDR, HWIO_RPM_VMIDMT_SIDR1_RMSK)
#define HWIO_RPM_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR1_ADDR, m)
#define HWIO_RPM_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_RPM_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_RPM_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_RPM_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_RPM_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_RPM_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_RPM_VMIDMT_SIDR2_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_RPM_VMIDMT_SIDR2_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_RPM_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_RPM_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR2_ADDR, HWIO_RPM_VMIDMT_SIDR2_RMSK)
#define HWIO_RPM_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR2_ADDR, m)
#define HWIO_RPM_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_RPM_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_RPM_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_RPM_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_RPM_VMIDMT_SIDR4_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_RPM_VMIDMT_SIDR4_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_RPM_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_RPM_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR4_ADDR, HWIO_RPM_VMIDMT_SIDR4_RMSK)
#define HWIO_RPM_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR4_ADDR, m)
#define HWIO_RPM_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_RPM_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_RPM_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_RPM_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_RPM_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_RPM_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_RPM_VMIDMT_SIDR5_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_RPM_VMIDMT_SIDR5_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_RPM_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_RPM_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR5_ADDR, HWIO_RPM_VMIDMT_SIDR5_RMSK)
#define HWIO_RPM_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR5_ADDR, m)
#define HWIO_RPM_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_RPM_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_RPM_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_RPM_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_RPM_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_RPM_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_RPM_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_RPM_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_RPM_VMIDMT_SIDR7_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_RPM_VMIDMT_SIDR7_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_RPM_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_RPM_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR7_ADDR, HWIO_RPM_VMIDMT_SIDR7_RMSK)
#define HWIO_RPM_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SIDR7_ADDR, m)
#define HWIO_RPM_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_RPM_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_RPM_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_RPM_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_RPM_VMIDMT_SGFAR0_ADDR                              (RPM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_RPM_VMIDMT_SGFAR0_OFFS                              (RPM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_RPM_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_RPM_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFAR0_ADDR, HWIO_RPM_VMIDMT_SGFAR0_RMSK)
#define HWIO_RPM_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_RPM_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_RPM_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_RPM_VMIDMT_SGFSR_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_RPM_VMIDMT_SGFSR_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_RPM_VMIDMT_SGFSR_RMSK                               0xc0000022
#define HWIO_RPM_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSR_ADDR, HWIO_RPM_VMIDMT_SGFSR_RMSK)
#define HWIO_RPM_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSR_ADDR, m)
#define HWIO_RPM_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_SGFSR_ADDR,v)
#define HWIO_RPM_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_SGFSR_ADDR,m,v,HWIO_RPM_VMIDMT_SGFSR_IN)
#define HWIO_RPM_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_RPM_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_RPM_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_RPM_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_RPM_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_RPM_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_RPM_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_RPM_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_RPM_VMIDMT_SGFSRRESTORE_ADDR                        (RPM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_OFFS                        (RPM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000022
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSRRESTORE_ADDR, HWIO_RPM_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_RPM_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_RPM_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_RPM_VMIDMT_SGFSYNDR0_ADDR                           (RPM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_RPM_VMIDMT_SGFSYNDR0_OFFS                           (RPM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_RPM_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_RPM_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSYNDR0_ADDR, HWIO_RPM_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_RPM_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_RPM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_RPM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_RPM_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_RPM_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_RPM_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_RPM_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_RPM_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_RPM_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_RPM_VMIDMT_SGFSYNDR1_ADDR                           (RPM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_RPM_VMIDMT_SGFSYNDR1_OFFS                           (RPM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_RPM_VMIDMT_SGFSYNDR1_RMSK                            0x1010001
#define HWIO_RPM_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSYNDR1_ADDR, HWIO_RPM_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_RPM_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_RPM_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                   0x1000000
#define HWIO_RPM_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                        0x18
#define HWIO_RPM_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000
#define HWIO_RPM_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_RPM_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                      0x1
#define HWIO_RPM_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_RPM_VMIDMT_SGFSYNDR2_ADDR                           (RPM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_RPM_VMIDMT_SGFSYNDR2_OFFS                           (RPM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_RPM_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_RPM_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSYNDR2_ADDR, HWIO_RPM_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_RPM_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_RPM_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_RPM_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_RPM_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_RPM_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_RPM_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_RPM_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_RPM_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_RPM_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_RPM_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_RPM_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_RPM_VMIDMT_VMIDMTSCR0_ADDR                          (RPM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_OFFS                          (RPM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_VMIDMTSCR0_ADDR, HWIO_RPM_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_RPM_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_RPM_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_RPM_VMIDMT_CR0_ADDR                                 (RPM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_RPM_VMIDMT_CR0_OFFS                                 (RPM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_RPM_VMIDMT_CR0_RMSK                                  0xfd70ff5
#define HWIO_RPM_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_CR0_ADDR, HWIO_RPM_VMIDMT_CR0_RMSK)
#define HWIO_RPM_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_CR0_ADDR, m)
#define HWIO_RPM_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_CR0_ADDR,v)
#define HWIO_RPM_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_CR0_ADDR,m,v,HWIO_RPM_VMIDMT_CR0_IN)
#define HWIO_RPM_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_RPM_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_RPM_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_RPM_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_RPM_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_RPM_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_RPM_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_RPM_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_RPM_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_RPM_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_RPM_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_RPM_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_RPM_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_RPM_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_RPM_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_RPM_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_RPM_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_RPM_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_RPM_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_RPM_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_RPM_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_RPM_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_RPM_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_RPM_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_RPM_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_RPM_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_RPM_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_RPM_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_RPM_VMIDMT_CR2_ADDR                                 (RPM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_RPM_VMIDMT_CR2_OFFS                                 (RPM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_RPM_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_RPM_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_CR2_ADDR, HWIO_RPM_VMIDMT_CR2_RMSK)
#define HWIO_RPM_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_CR2_ADDR, m)
#define HWIO_RPM_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_CR2_ADDR,v)
#define HWIO_RPM_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_CR2_ADDR,m,v,HWIO_RPM_VMIDMT_CR2_IN)
#define HWIO_RPM_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_RPM_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_RPM_VMIDMT_ACR_ADDR                                 (RPM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_RPM_VMIDMT_ACR_OFFS                                 (RPM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_RPM_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_RPM_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_ACR_ADDR, HWIO_RPM_VMIDMT_ACR_RMSK)
#define HWIO_RPM_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_ACR_ADDR, m)
#define HWIO_RPM_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_ACR_ADDR,v)
#define HWIO_RPM_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_ACR_ADDR,m,v,HWIO_RPM_VMIDMT_ACR_IN)
#define HWIO_RPM_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_RPM_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_RPM_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_RPM_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_RPM_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_RPM_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_RPM_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_RPM_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_RPM_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_RPM_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_RPM_VMIDMT_IDR0_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_RPM_VMIDMT_IDR0_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_RPM_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_RPM_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR0_ADDR, HWIO_RPM_VMIDMT_IDR0_RMSK)
#define HWIO_RPM_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR0_ADDR, m)
#define HWIO_RPM_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_RPM_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_RPM_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_RPM_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_RPM_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_RPM_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_RPM_VMIDMT_IDR1_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_RPM_VMIDMT_IDR1_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_RPM_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_RPM_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR1_ADDR, HWIO_RPM_VMIDMT_IDR1_RMSK)
#define HWIO_RPM_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR1_ADDR, m)
#define HWIO_RPM_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_RPM_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_RPM_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_RPM_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_RPM_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_RPM_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_RPM_VMIDMT_IDR2_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_RPM_VMIDMT_IDR2_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_RPM_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_RPM_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR2_ADDR, HWIO_RPM_VMIDMT_IDR2_RMSK)
#define HWIO_RPM_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR2_ADDR, m)
#define HWIO_RPM_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_RPM_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_RPM_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_RPM_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_RPM_VMIDMT_IDR4_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_RPM_VMIDMT_IDR4_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_RPM_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_RPM_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR4_ADDR, HWIO_RPM_VMIDMT_IDR4_RMSK)
#define HWIO_RPM_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR4_ADDR, m)
#define HWIO_RPM_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_RPM_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_RPM_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_RPM_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_RPM_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_RPM_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_RPM_VMIDMT_IDR5_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_RPM_VMIDMT_IDR5_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_RPM_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_RPM_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR5_ADDR, HWIO_RPM_VMIDMT_IDR5_RMSK)
#define HWIO_RPM_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR5_ADDR, m)
#define HWIO_RPM_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_RPM_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_RPM_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_RPM_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_RPM_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_RPM_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_RPM_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_RPM_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_RPM_VMIDMT_IDR7_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_RPM_VMIDMT_IDR7_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_RPM_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_RPM_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR7_ADDR, HWIO_RPM_VMIDMT_IDR7_RMSK)
#define HWIO_RPM_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_IDR7_ADDR, m)
#define HWIO_RPM_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_RPM_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_RPM_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_RPM_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_RPM_VMIDMT_GFAR0_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_RPM_VMIDMT_GFAR0_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_RPM_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_RPM_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_GFAR0_ADDR, HWIO_RPM_VMIDMT_GFAR0_RMSK)
#define HWIO_RPM_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_GFAR0_ADDR, m)
#define HWIO_RPM_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_RPM_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_RPM_VMIDMT_GFSR_ADDR                                (RPM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_RPM_VMIDMT_GFSR_OFFS                                (RPM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_RPM_VMIDMT_GFSR_RMSK                                0xc00000a2
#define HWIO_RPM_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSR_ADDR, HWIO_RPM_VMIDMT_GFSR_RMSK)
#define HWIO_RPM_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSR_ADDR, m)
#define HWIO_RPM_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_GFSR_ADDR,v)
#define HWIO_RPM_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_GFSR_ADDR,m,v,HWIO_RPM_VMIDMT_GFSR_IN)
#define HWIO_RPM_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_RPM_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_RPM_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_RPM_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_RPM_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_RPM_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_RPM_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_RPM_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_RPM_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_RPM_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_RPM_VMIDMT_GFSRRESTORE_ADDR                         (RPM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_RPM_VMIDMT_GFSRRESTORE_OFFS                         (RPM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_RPM_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a2
#define HWIO_RPM_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSRRESTORE_ADDR, HWIO_RPM_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_RPM_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_RPM_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_RPM_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_RPM_VMIDMT_GFSRRESTORE_IN)
#define HWIO_RPM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_RPM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_RPM_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_RPM_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_RPM_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_RPM_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_RPM_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_RPM_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_RPM_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_RPM_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_RPM_VMIDMT_GFSYNDR0_ADDR                            (RPM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_RPM_VMIDMT_GFSYNDR0_OFFS                            (RPM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_RPM_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_RPM_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSYNDR0_ADDR, HWIO_RPM_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_RPM_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_RPM_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_RPM_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_RPM_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_RPM_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_RPM_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_RPM_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_RPM_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_RPM_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_RPM_VMIDMT_GFSYNDR1_ADDR                            (RPM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_RPM_VMIDMT_GFSYNDR1_OFFS                            (RPM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_RPM_VMIDMT_GFSYNDR1_RMSK                             0x1010001
#define HWIO_RPM_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSYNDR1_ADDR, HWIO_RPM_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_RPM_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_RPM_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                    0x1000000
#define HWIO_RPM_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                         0x18
#define HWIO_RPM_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000
#define HWIO_RPM_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_RPM_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                       0x1
#define HWIO_RPM_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_RPM_VMIDMT_GFSYNDR2_ADDR                            (RPM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_RPM_VMIDMT_GFSYNDR2_OFFS                            (RPM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_RPM_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_RPM_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSYNDR2_ADDR, HWIO_RPM_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_RPM_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_RPM_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_RPM_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_RPM_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_RPM_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_RPM_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_RPM_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_RPM_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_RPM_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_RPM_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_RPM_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_RPM_VMIDMT_VMIDMTCR0_ADDR                           (RPM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_RPM_VMIDMT_VMIDMTCR0_OFFS                           (RPM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_RPM_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_RPM_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_VMIDMTCR0_ADDR, HWIO_RPM_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_RPM_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_RPM_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_RPM_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_RPM_VMIDMT_VMIDMTCR0_IN)
#define HWIO_RPM_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_RPM_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_RPM_VMIDMT_VMIDMTACR_ADDR                           (RPM_VMIDMT_REG_BASE      + 0x0000009c)
#define HWIO_RPM_VMIDMT_VMIDMTACR_OFFS                           (RPM_VMIDMT_REG_BASE_OFFS + 0x0000009c)
#define HWIO_RPM_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_RPM_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_VMIDMTACR_ADDR, HWIO_RPM_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_RPM_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_RPM_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_RPM_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_RPM_VMIDMT_VMIDMTACR_IN)
#define HWIO_RPM_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_RPM_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_RPM_VMIDMT_NSCR0_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000400)
#define HWIO_RPM_VMIDMT_NSCR0_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000400)
#define HWIO_RPM_VMIDMT_NSCR0_RMSK                                0xfd70ff5
#define HWIO_RPM_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSCR0_ADDR, HWIO_RPM_VMIDMT_NSCR0_RMSK)
#define HWIO_RPM_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSCR0_ADDR, m)
#define HWIO_RPM_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_NSCR0_ADDR,v)
#define HWIO_RPM_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_NSCR0_ADDR,m,v,HWIO_RPM_VMIDMT_NSCR0_IN)
#define HWIO_RPM_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_RPM_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_RPM_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_RPM_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_RPM_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_RPM_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_RPM_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_RPM_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_RPM_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_RPM_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_RPM_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_RPM_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_RPM_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_RPM_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_RPM_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_RPM_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_RPM_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_RPM_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_RPM_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_RPM_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_RPM_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_RPM_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_RPM_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_RPM_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_RPM_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_RPM_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_RPM_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_RPM_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_RPM_VMIDMT_NSCR2_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000408)
#define HWIO_RPM_VMIDMT_NSCR2_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000408)
#define HWIO_RPM_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_RPM_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSCR2_ADDR, HWIO_RPM_VMIDMT_NSCR2_RMSK)
#define HWIO_RPM_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSCR2_ADDR, m)
#define HWIO_RPM_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_NSCR2_ADDR,v)
#define HWIO_RPM_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_NSCR2_ADDR,m,v,HWIO_RPM_VMIDMT_NSCR2_IN)
#define HWIO_RPM_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_RPM_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_RPM_VMIDMT_NSACR_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000410)
#define HWIO_RPM_VMIDMT_NSACR_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000410)
#define HWIO_RPM_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_RPM_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSACR_ADDR, HWIO_RPM_VMIDMT_NSACR_RMSK)
#define HWIO_RPM_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSACR_ADDR, m)
#define HWIO_RPM_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_NSACR_ADDR,v)
#define HWIO_RPM_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_NSACR_ADDR,m,v,HWIO_RPM_VMIDMT_NSACR_IN)
#define HWIO_RPM_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_RPM_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_RPM_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_RPM_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_RPM_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_RPM_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_RPM_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_RPM_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_RPM_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_RPM_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_RPM_VMIDMT_NSGFAR0_ADDR                             (RPM_VMIDMT_REG_BASE      + 0x00000440)
#define HWIO_RPM_VMIDMT_NSGFAR0_OFFS                             (RPM_VMIDMT_REG_BASE_OFFS + 0x00000440)
#define HWIO_RPM_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_RPM_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFAR0_ADDR, HWIO_RPM_VMIDMT_NSGFAR0_RMSK)
#define HWIO_RPM_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_RPM_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_RPM_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_RPM_VMIDMT_NSGFSR_ADDR                              (RPM_VMIDMT_REG_BASE      + 0x00000448)
#define HWIO_RPM_VMIDMT_NSGFSR_OFFS                              (RPM_VMIDMT_REG_BASE_OFFS + 0x00000448)
#define HWIO_RPM_VMIDMT_NSGFSR_RMSK                              0xc00000a2
#define HWIO_RPM_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSR_ADDR, HWIO_RPM_VMIDMT_NSGFSR_RMSK)
#define HWIO_RPM_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_RPM_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_RPM_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_NSGFSR_ADDR,m,v,HWIO_RPM_VMIDMT_NSGFSR_IN)
#define HWIO_RPM_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_RPM_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_RPM_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_RPM_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_RPM_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_RPM_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_RPM_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_RPM_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_RPM_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_RPM_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_ADDR                       (RPM_VMIDMT_REG_BASE      + 0x0000044c)
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_OFFS                       (RPM_VMIDMT_REG_BASE_OFFS + 0x0000044c)
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a2
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_RPM_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_RPM_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_RPM_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_RPM_VMIDMT_NSGFSYNDR0_ADDR                          (RPM_VMIDMT_REG_BASE      + 0x00000450)
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_OFFS                          (RPM_VMIDMT_REG_BASE_OFFS + 0x00000450)
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSYNDR0_ADDR, HWIO_RPM_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_RPM_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_RPM_VMIDMT_NSGFSYNDR1_ADDR                          (RPM_VMIDMT_REG_BASE      + 0x00000454)
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_OFFS                          (RPM_VMIDMT_REG_BASE_OFFS + 0x00000454)
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_RMSK                           0x1010001
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSYNDR1_ADDR, HWIO_RPM_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                  0x1000000
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                       0x18
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                     0x1
#define HWIO_RPM_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_RPM_VMIDMT_NSGFSYNDR2_ADDR                          (RPM_VMIDMT_REG_BASE      + 0x00000458)
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_OFFS                          (RPM_VMIDMT_REG_BASE_OFFS + 0x00000458)
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSYNDR2_ADDR, HWIO_RPM_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_RPM_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_ADDR                         (RPM_VMIDMT_REG_BASE      + 0x00000490)
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_OFFS                         (RPM_VMIDMT_REG_BASE_OFFS + 0x00000490)
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_RPM_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_RPM_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_RPM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_RPM_VMIDMT_SSDR0_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000080)
#define HWIO_RPM_VMIDMT_SSDR0_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000080)
#define HWIO_RPM_VMIDMT_SSDR0_RMSK                                      0x1
#define HWIO_RPM_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_SSDR0_ADDR, HWIO_RPM_VMIDMT_SSDR0_RMSK)
#define HWIO_RPM_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_SSDR0_ADDR, m)
#define HWIO_RPM_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_SSDR0_ADDR,v)
#define HWIO_RPM_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_SSDR0_ADDR,m,v,HWIO_RPM_VMIDMT_SSDR0_IN)
#define HWIO_RPM_VMIDMT_SSDR0_RWE_BMSK                                  0x1
#define HWIO_RPM_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_RPM_VMIDMT_MSDR0_ADDR                               (RPM_VMIDMT_REG_BASE      + 0x00000480)
#define HWIO_RPM_VMIDMT_MSDR0_OFFS                               (RPM_VMIDMT_REG_BASE_OFFS + 0x00000480)
#define HWIO_RPM_VMIDMT_MSDR0_RMSK                                      0x1
#define HWIO_RPM_VMIDMT_MSDR0_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_MSDR0_ADDR, HWIO_RPM_VMIDMT_MSDR0_RMSK)
#define HWIO_RPM_VMIDMT_MSDR0_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_MSDR0_ADDR, m)
#define HWIO_RPM_VMIDMT_MSDR0_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_MSDR0_ADDR,v)
#define HWIO_RPM_VMIDMT_MSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_MSDR0_ADDR,m,v,HWIO_RPM_VMIDMT_MSDR0_IN)
#define HWIO_RPM_VMIDMT_MSDR0_RWE_BMSK                                  0x1
#define HWIO_RPM_VMIDMT_MSDR0_RWE_SHFT                                  0x0

#define HWIO_RPM_VMIDMT_MCR_ADDR                                 (RPM_VMIDMT_REG_BASE      + 0x00000494)
#define HWIO_RPM_VMIDMT_MCR_OFFS                                 (RPM_VMIDMT_REG_BASE_OFFS + 0x00000494)
#define HWIO_RPM_VMIDMT_MCR_RMSK                                        0x7
#define HWIO_RPM_VMIDMT_MCR_IN          \
        in_dword_masked(HWIO_RPM_VMIDMT_MCR_ADDR, HWIO_RPM_VMIDMT_MCR_RMSK)
#define HWIO_RPM_VMIDMT_MCR_INM(m)      \
        in_dword_masked(HWIO_RPM_VMIDMT_MCR_ADDR, m)
#define HWIO_RPM_VMIDMT_MCR_OUT(v)      \
        out_dword(HWIO_RPM_VMIDMT_MCR_ADDR,v)
#define HWIO_RPM_VMIDMT_MCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_MCR_ADDR,m,v,HWIO_RPM_VMIDMT_MCR_IN)
#define HWIO_RPM_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4
#define HWIO_RPM_VMIDMT_MCR_CLKONOFFE_SHFT                              0x2
#define HWIO_RPM_VMIDMT_MCR_BPMSACFG_BMSK                               0x2
#define HWIO_RPM_VMIDMT_MCR_BPMSACFG_SHFT                               0x1
#define HWIO_RPM_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1
#define HWIO_RPM_VMIDMT_MCR_BPSMSACFG_SHFT                              0x0

#define HWIO_RPM_VMIDMT_S2VRn_ADDR(n)                            (RPM_VMIDMT_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_RPM_VMIDMT_S2VRn_OFFS(n)                            (RPM_VMIDMT_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_RPM_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_RPM_VMIDMT_S2VRn_MAXn                                        0
#define HWIO_RPM_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_RPM_VMIDMT_S2VRn_ADDR(n), HWIO_RPM_VMIDMT_S2VRn_RMSK)
#define HWIO_RPM_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_RPM_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_RPM_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_RPM_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_RPM_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_RPM_VMIDMT_S2VRn_INI(n))
#define HWIO_RPM_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_RPM_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_RPM_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_RPM_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_RPM_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_RPM_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_RPM_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_RPM_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_RPM_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_RPM_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_RPM_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_RPM_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_RPM_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_RPM_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_RPM_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_RPM_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_RPM_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_RPM_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_RPM_VMIDMT_AS2VRn_ADDR(n)                           (RPM_VMIDMT_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_RPM_VMIDMT_AS2VRn_OFFS(n)                           (RPM_VMIDMT_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_RPM_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_RPM_VMIDMT_AS2VRn_MAXn                                       0
#define HWIO_RPM_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_RPM_VMIDMT_AS2VRn_ADDR(n), HWIO_RPM_VMIDMT_AS2VRn_RMSK)
#define HWIO_RPM_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_RPM_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_RPM_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_RPM_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_RPM_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_RPM_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_RPM_VMIDMT_AS2VRn_INI(n))
#define HWIO_RPM_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_RPM_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_RPM_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_RPM_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_RPM_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_RPM_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_RPM_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_RPM_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_RPM_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_RPM_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

/*----------------------------------------------------------------------------
 * MODULE: CRYPTO0_CRYPTO_BAM_VMIDMT_BAM
 *--------------------------------------------------------------------------*/

#define CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE                                  (CRYPTO0_CRYPTO_TOP_BASE      + 0x00000000)
#define CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS                             0x00000000

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000000)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000000)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_RMSK                                0x3ff707f5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SMCFCFG_SHFT                              0x15
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000004)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000004)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_RMSK                                 0x1001f00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0x1f00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000008)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000008)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000010)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000010)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000020)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000020)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000024)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000024)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000028)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000028)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000030)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000030)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000034)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000034)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0000003c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0000003c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_ADDR                              (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000040)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_OFFS                              (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000040)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000048)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000048)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_RMSK                               0xc0000026
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_SMCF_BMSK                                 0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_SMCF_SHFT                                 0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR                        (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0000004c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_OFFS                        (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0000004c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_SMCF_SHFT                          0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_ADDR                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000050)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_OFFS                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000050)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_ADDR                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000054)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_OFFS                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000054)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_RMSK                           0x1f1f001f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                  0x1f000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                        0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                    0x1f0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                     0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ADDR                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000058)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_OFFS                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000058)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000090)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_OFFS                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000090)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000000)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_OFFS                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000000)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_RMSK                                  0xff70ff5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SMCFCFG_SHFT                               0x15
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000008)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_OFFS                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000008)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000010)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_OFFS                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000010)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000020)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000020)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000024)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000024)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000028)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000028)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000030)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000030)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000034)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000034)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0000003c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0000003c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000040)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000040)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000048)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_OFFS                                (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000048)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_RMSK                                0xc00000a6
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_SMCF_BMSK                                  0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_SMCF_SHFT                                  0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR                         (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0000004c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_OFFS                         (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0000004c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_SMCF_SHFT                           0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_ADDR                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000050)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_OFFS                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000050)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_ADDR                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000054)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_OFFS                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000054)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_RMSK                            0x1f1f001f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                   0x1f000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                         0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                     0x1f0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                      0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ADDR                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000058)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_OFFS                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000058)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000090)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_OFFS                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000090)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0000009c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_OFFS                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0000009c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000400)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000400)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_RMSK                                0xff70ff5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SMCFCFG_SHFT                             0x15
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000408)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000408)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000410)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000410)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_ADDR                             (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000440)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_OFFS                             (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000440)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR                              (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000448)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_OFFS                              (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000448)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_RMSK                              0xc00000a6
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_SMCF_BMSK                                0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_SMCF_SHFT                                0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR                       (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0000044c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_OFFS                       (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0000044c)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                         0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_ADDR                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000450)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_OFFS                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000450)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_ADDR                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000454)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_OFFS                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000454)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_RMSK                          0x1f1f001f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                 0x1f000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                       0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                   0x1f0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                    0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ADDR                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000458)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_OFFS                          (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000458)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR                         (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000490)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_OFFS                         (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000490)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000080)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000080)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_RMSK                               0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_RWE_BMSK                           0xffffffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000480)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_OFFS                               (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000480)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_RMSK                                  0x1ffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_RWE_BMSK                              0x1ffff
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_RWE_SHFT                                  0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000494)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_OFFS                                 (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000494)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_RMSK                                        0x7
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_IN          \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR, HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_INM(m)      \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR, m)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_OUT(v)      \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR,v)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR,m,v,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_IN)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_CLKONOFFE_SHFT                              0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPMSACFG_BMSK                               0x2
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPMSACFG_SHFT                               0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPSMSACFG_SHFT                              0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n)                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_OFFS(n)                            (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MAXn                                       16
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n), HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_INI(n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n)                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_OFFS(n)                           (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_MAXn                                      16
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n), HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_INI(n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n)                             (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x00000800 + 0x4 * (n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_OFFS(n)                             (CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x00000800 + 0x4 * (n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_RMSK                                0x801f001f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_MAXn                                        16
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_INI(n)        \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n), HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_RMSK)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_INMI(n,mask)    \
        in_dword_masked(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_OUTI(n,val)    \
        out_dword(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_INI(n))
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_VALID_BMSK                          0x80000000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_VALID_SHFT                                0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_MASK_BMSK                             0x1f0000
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_MASK_SHFT                                 0x10
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ID_BMSK                                   0x1f
#define HWIO_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ID_SHFT                                    0x0

/*----------------------------------------------------------------------------
 * MODULE: IPA_0_IPA_VMIDMT
 *--------------------------------------------------------------------------*/

#define IPA_0_IPA_VMIDMT_REG_BASE                                      (0      + 0x00030000)
#define IPA_0_IPA_VMIDMT_REG_BASE_OFFS                                 0x00030000

#define HWIO_IPA_0_IPA_VMIDMT_SCR0_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_RMSK                                0x3ff707f5
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SCR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_SCR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SCR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SCR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SCR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_SCR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_SMCFCFG_SHFT                              0x15
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_IPA_0_IPA_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_IPA_0_IPA_VMIDMT_SCR1_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000004)
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000004)
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_RMSK                                 0x1003f00
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SCR1_ADDR, HWIO_IPA_0_IPA_VMIDMT_SCR1_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SCR1_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SCR1_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SCR1_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_SCR1_IN)
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0x3f00
#define HWIO_IPA_0_IPA_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_IPA_0_IPA_VMIDMT_SCR2_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SCR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_SCR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SCR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SCR2_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SCR2_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_SCR2_IN)
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_IPA_0_IPA_VMIDMT_SACR_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_IPA_0_IPA_VMIDMT_SACR_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_IPA_0_IPA_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_IPA_0_IPA_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SACR_ADDR, HWIO_IPA_0_IPA_VMIDMT_SACR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SACR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SACR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SACR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_SACR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_IPA_0_IPA_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_SIDR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR1_ADDR, HWIO_IPA_0_IPA_VMIDMT_SIDR1_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR1_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_IPA_0_IPA_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_SIDR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_IPA_0_IPA_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR4_ADDR, HWIO_IPA_0_IPA_VMIDMT_SIDR4_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR4_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR5_ADDR, HWIO_IPA_0_IPA_VMIDMT_SIDR5_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR5_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR7_ADDR, HWIO_IPA_0_IPA_VMIDMT_SIDR7_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SIDR7_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_IPA_0_IPA_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_IPA_0_IPA_VMIDMT_SGFAR0_ADDR                              (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_IPA_0_IPA_VMIDMT_SGFAR0_OFFS                              (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_IPA_0_IPA_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFAR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_SGFAR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_RMSK                               0xc0000026
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSR_ADDR, HWIO_IPA_0_IPA_VMIDMT_SGFSR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SGFSR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SGFSR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_SGFSR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_SMCF_BMSK                                 0x4
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_SMCF_SHFT                                 0x2
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_IPA_0_IPA_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_ADDR                        (IPA_0_IPA_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_OFFS                        (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_ADDR, HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_SMCF_SHFT                          0x2
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_IPA_0_IPA_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_ADDR                           (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_OFFS                           (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_ADDR                           (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_OFFS                           (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_RMSK                           0x1f1f001f
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_ADDR, HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                  0x1f000000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                        0x18
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                    0x1f0000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                     0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_ADDR                           (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_OFFS                           (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_RMSK                            0x71fffff
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_ATID_BMSK                       0x7000000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_IPA_0_IPA_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_ADDR                          (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_OFFS                          (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_IPA_0_IPA_VMIDMT_CR0_ADDR                                 (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_IPA_0_IPA_VMIDMT_CR0_OFFS                                 (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_IPA_0_IPA_VMIDMT_CR0_RMSK                                  0xff70ff5
#define HWIO_IPA_0_IPA_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_CR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_CR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_CR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_CR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_CR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_CR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_IPA_0_IPA_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_IPA_0_IPA_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_IPA_0_IPA_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_IPA_0_IPA_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_IPA_0_IPA_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_IPA_0_IPA_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000
#define HWIO_IPA_0_IPA_VMIDMT_CR0_SMCFCFG_SHFT                               0x15
#define HWIO_IPA_0_IPA_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_IPA_0_IPA_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_IPA_0_IPA_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_IPA_0_IPA_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_IPA_0_IPA_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_IPA_0_IPA_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_IPA_0_IPA_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_IPA_0_IPA_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_IPA_0_IPA_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_IPA_0_IPA_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_IPA_0_IPA_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_IPA_0_IPA_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_IPA_0_IPA_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_IPA_0_IPA_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_IPA_0_IPA_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_IPA_0_IPA_VMIDMT_CR2_ADDR                                 (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_IPA_0_IPA_VMIDMT_CR2_OFFS                                 (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_IPA_0_IPA_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_IPA_0_IPA_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_CR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_CR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_CR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_CR2_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_CR2_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_CR2_IN)
#define HWIO_IPA_0_IPA_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_IPA_0_IPA_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_IPA_0_IPA_VMIDMT_ACR_ADDR                                 (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_IPA_0_IPA_VMIDMT_ACR_OFFS                                 (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_IPA_0_IPA_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_IPA_0_IPA_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_ACR_ADDR, HWIO_IPA_0_IPA_VMIDMT_ACR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_ACR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_ACR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_ACR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_ACR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_IPA_0_IPA_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_IPA_0_IPA_VMIDMT_IDR0_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_IDR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_IPA_0_IPA_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_IPA_0_IPA_VMIDMT_IDR1_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR1_ADDR, HWIO_IPA_0_IPA_VMIDMT_IDR1_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR1_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_IPA_0_IPA_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_IPA_0_IPA_VMIDMT_IDR2_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_IDR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_IPA_0_IPA_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_IPA_0_IPA_VMIDMT_IDR4_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR4_ADDR, HWIO_IPA_0_IPA_VMIDMT_IDR4_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR4_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_IPA_0_IPA_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_IPA_0_IPA_VMIDMT_IDR5_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR5_ADDR, HWIO_IPA_0_IPA_VMIDMT_IDR5_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR5_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_IPA_0_IPA_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_IPA_0_IPA_VMIDMT_IDR7_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR7_ADDR, HWIO_IPA_0_IPA_VMIDMT_IDR7_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_IDR7_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_IPA_0_IPA_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_IPA_0_IPA_VMIDMT_GFAR0_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_IPA_0_IPA_VMIDMT_GFAR0_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_IPA_0_IPA_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFAR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_GFAR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFAR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_IPA_0_IPA_VMIDMT_GFSR_ADDR                                (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_OFFS                                (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_RMSK                                0xc00000a6
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSR_ADDR, HWIO_IPA_0_IPA_VMIDMT_GFSR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_GFSR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_GFSR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_GFSR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_SMCF_BMSK                                  0x4
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_SMCF_SHFT                                  0x2
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_IPA_0_IPA_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_ADDR                         (IPA_0_IPA_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_OFFS                         (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_ADDR, HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_IN)
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_SMCF_SHFT                           0x2
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_IPA_0_IPA_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_ADDR                            (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_OFFS                            (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_ADDR                            (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_OFFS                            (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_RMSK                            0x1f1f001f
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_ADDR, HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                   0x1f000000
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                         0x18
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                     0x1f0000
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                      0x1f
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_ADDR                            (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_OFFS                            (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_RMSK                             0x71fffff
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_ATID_BMSK                        0x7000000
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_IPA_0_IPA_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_ADDR                           (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_OFFS                           (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_ADDR                           (IPA_0_IPA_VMIDMT_REG_BASE      + 0x0000009c)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_OFFS                           (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x0000009c)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_ADDR, HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000400)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000400)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_RMSK                                0xff70ff5
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSCR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSCR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSCR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_NSCR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_NSCR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_NSCR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_SMCFCFG_SHFT                             0x15
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_IPA_0_IPA_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000408)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000408)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSCR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSCR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSCR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_NSCR2_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_NSCR2_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_NSCR2_IN)
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_IPA_0_IPA_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_IPA_0_IPA_VMIDMT_NSACR_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000410)
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000410)
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSACR_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSACR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSACR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_NSACR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_NSACR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_NSACR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_IPA_0_IPA_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_ADDR                             (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000440)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_OFFS                             (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000440)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_ADDR                              (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000448)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_OFFS                              (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000448)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_RMSK                              0xc00000a6
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSR_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSGFSR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_NSGFSR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_NSGFSR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_SMCF_BMSK                                0x4
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_SMCF_SHFT                                0x2
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_ADDR                       (IPA_0_IPA_VMIDMT_REG_BASE      + 0x0000044c)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_OFFS                       (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x0000044c)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                         0x2
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_ADDR                          (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000450)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_OFFS                          (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000450)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_ADDR                          (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000454)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_OFFS                          (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000454)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_RMSK                          0x1f1f001f
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                 0x1f000000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                       0x18
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                   0x1f0000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                    0x1f
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_ADDR                          (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000458)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_OFFS                          (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000458)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_RMSK                           0x71fffff
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_ATID_BMSK                      0x7000000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_IPA_0_IPA_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_ADDR                         (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000490)
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_OFFS                         (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000490)
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_IPA_0_IPA_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000080)
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000080)
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_RMSK                               0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SSDR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_SSDR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SSDR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SSDR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SSDR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_SSDR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_RWE_BMSK                           0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_ADDR                               (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000480)
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_OFFS                               (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000480)
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_RMSK                               0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_MSDR0_ADDR, HWIO_IPA_0_IPA_VMIDMT_MSDR0_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_MSDR0_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_MSDR0_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_MSDR0_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_MSDR0_IN)
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_RWE_BMSK                           0xffffffff
#define HWIO_IPA_0_IPA_VMIDMT_MSDR0_RWE_SHFT                                  0x0

#define HWIO_IPA_0_IPA_VMIDMT_MCR_ADDR                                 (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000494)
#define HWIO_IPA_0_IPA_VMIDMT_MCR_OFFS                                 (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000494)
#define HWIO_IPA_0_IPA_VMIDMT_MCR_RMSK                                        0x7
#define HWIO_IPA_0_IPA_VMIDMT_MCR_IN          \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_MCR_ADDR, HWIO_IPA_0_IPA_VMIDMT_MCR_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_MCR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_MCR_ADDR, m)
#define HWIO_IPA_0_IPA_VMIDMT_MCR_OUT(v)      \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_MCR_ADDR,v)
#define HWIO_IPA_0_IPA_VMIDMT_MCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_MCR_ADDR,m,v,HWIO_IPA_0_IPA_VMIDMT_MCR_IN)
#define HWIO_IPA_0_IPA_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4
#define HWIO_IPA_0_IPA_VMIDMT_MCR_CLKONOFFE_SHFT                              0x2
#define HWIO_IPA_0_IPA_VMIDMT_MCR_BPMSACFG_BMSK                               0x2
#define HWIO_IPA_0_IPA_VMIDMT_MCR_BPMSACFG_SHFT                               0x1
#define HWIO_IPA_0_IPA_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1
#define HWIO_IPA_0_IPA_VMIDMT_MCR_BPSMSACFG_SHFT                              0x0

#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_ADDR(n)                            (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_OFFS(n)                            (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_MAXn                                       31
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_S2VRn_ADDR(n), HWIO_IPA_0_IPA_VMIDMT_S2VRn_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_IPA_0_IPA_VMIDMT_S2VRn_INI(n))
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_IPA_0_IPA_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_ADDR(n)                           (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_OFFS(n)                           (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_MAXn                                      31
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_AS2VRn_ADDR(n), HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_IPA_0_IPA_VMIDMT_AS2VRn_INI(n))
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_IPA_0_IPA_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

#define HWIO_IPA_0_IPA_VMIDMT_SMRn_ADDR(n)                             (IPA_0_IPA_VMIDMT_REG_BASE      + 0x00000800 + 0x4 * (n))
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_OFFS(n)                             (IPA_0_IPA_VMIDMT_REG_BASE_OFFS + 0x00000800 + 0x4 * (n))
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_RMSK                                0x801f001f
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_MAXn                                        31
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_INI(n)        \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SMRn_ADDR(n), HWIO_IPA_0_IPA_VMIDMT_SMRn_RMSK)
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_IPA_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_IPA_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_IPA_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_IPA_0_IPA_VMIDMT_SMRn_INI(n))
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_VALID_BMSK                          0x80000000
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_VALID_SHFT                                0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_MASK_BMSK                             0x1f0000
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_MASK_SHFT                                 0x10
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_ID_BMSK                                   0x1f
#define HWIO_IPA_0_IPA_VMIDMT_SMRn_ID_SHFT                                    0x0

/*----------------------------------------------------------------------------
 * MODULE: SSC_BLSP_BLSP_BAM_VMIDMT
 *--------------------------------------------------------------------------*/

#define SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE                                      (0      + 0x00680000)
#define SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS                                 0x00680000

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_RMSK                                0x3ff707f5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_SMCFCFG_SHFT                              0x15
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000004)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000004)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_RMSK                                 0x1000f00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_NSNUMSMRGO_BMSK                          0xf00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_ADDR                              (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_OFFS                              (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_RMSK                               0xc0000026
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_SMCF_BMSK                                 0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_SMCF_SHFT                                 0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR                        (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_OFFS                        (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_SMCF_SHFT                          0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_OFFS                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_OFFS                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_RMSK                            0xf0f000f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                   0xf000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                        0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0xf0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                      0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_OFFS                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_OFFS                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_ADDR                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_OFFS                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_RMSK                                  0xff70ff5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_SMCFCFG_SHFT                               0x15
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_ADDR                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_OFFS                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_ADDR                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_OFFS                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_ADDR                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_OFFS                                (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_RMSK                                0xc00000a6
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_SMCF_BMSK                                  0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_SMCF_SHFT                                  0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR                         (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_OFFS                         (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_SMCF_SHFT                           0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_OFFS                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_OFFS                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_RMSK                             0xf0f000f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                    0xf000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                         0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0xf0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                       0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_OFFS                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_OFFS                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000009c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_OFFS                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000009c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000400)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000400)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_RMSK                                0xff70ff5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_SMCFCFG_SHFT                             0x15
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000408)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000408)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000410)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000410)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_ADDR                             (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000440)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_OFFS                             (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000440)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_ADDR                              (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000448)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_OFFS                              (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000448)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_RMSK                              0xc00000a6
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_SMCF_BMSK                                0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_SMCF_SHFT                                0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR                       (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000044c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OFFS                       (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000044c)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                         0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000450)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_OFFS                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000450)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000454)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_OFFS                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000454)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_RMSK                           0xf0f000f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                  0xf000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                       0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0xf0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                     0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000458)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_OFFS                          (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000458)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR                         (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000490)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OFFS                         (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000490)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000080)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000080)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_RMSK                                   0xffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_RWE_BMSK                               0xffff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_ADDR                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000480)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_OFFS                               (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000480)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_RMSK                                   0x1fff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_RWE_BMSK                               0x1fff
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MSDR0_RWE_SHFT                                  0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_ADDR                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000494)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_OFFS                                 (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000494)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_RMSK                                        0x7
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_IN          \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_ADDR, HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_INM(m)      \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_ADDR, m)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_OUT(v)      \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_ADDR,v)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_ADDR,m,v,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_IN)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_CLKONOFFE_SHFT                              0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_BPMSACFG_BMSK                               0x2
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_BPMSACFG_SHFT                               0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_MCR_BPSMSACFG_SHFT                              0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_ADDR(n)                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_OFFS(n)                            (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_MAXn                                       12
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_ADDR(n), HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_INI(n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n)                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_OFFS(n)                           (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_MAXn                                      12
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n), HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_INI(n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_ADDR(n)                             (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000800 + 0x4 * (n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_OFFS(n)                             (SSC_BLSP_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000800 + 0x4 * (n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_RMSK                                0x800f000f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_MAXn                                        12
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_INI(n)        \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_ADDR(n), HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_RMSK)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_INMI(n,mask)    \
        in_dword_masked(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_OUTI(n,val)    \
        out_dword(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_INI(n))
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_VALID_BMSK                          0x80000000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_VALID_SHFT                                0x1f
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_MASK_BMSK                              0xf0000
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_MASK_SHFT                                 0x10
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_ID_BMSK                                    0xf
#define HWIO_SSC_BLSP_BLSP_BAM_VMIDMT_SMRn_ID_SHFT                                    0x0

/*----------------------------------------------------------------------------
 * MODULE: QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1
 *--------------------------------------------------------------------------*/

#define QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE                   (0      + 0x00076000)
#define QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS              0x00076000

#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000000)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000000)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_RMSK                                0x3fd707f5
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000004)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000004)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_RMSK                                 0x1000300
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_NSNUMSMRGO_BMSK                          0x300
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000008)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000008)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000010)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000010)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SACR_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SACR_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SACR_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_SACR_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_SACR_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_SACR_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_QDSS_VMIDDAP_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000020)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000020)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000024)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000024)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000028)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000028)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000030)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000030)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000034)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000034)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000003c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000003c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_QDSS_VMIDDAP_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_ADDR                              (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000040)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_OFFS                              (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000040)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000048)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000048)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_RMSK                               0xc0000022
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_ADDR                        (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000004c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_OFFS                        (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000004c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000022
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_ADDR                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000050)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_OFFS                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000050)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_ADDR                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000054)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_OFFS                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000054)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_RMSK                              0x10001
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                      0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_ADDR                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000058)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_OFFS                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000058)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_ADDR                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000090)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_OFFS                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000090)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_ADDR                                 (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000000)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_OFFS                                 (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000000)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_RMSK                                  0xfd70ff5
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_CR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_CR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_CR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_CR0_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_CR0_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_CR0_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_ADDR                                 (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000008)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_OFFS                                 (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000008)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_CR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_CR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_CR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_CR2_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_CR2_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_CR2_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_ADDR                                 (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000010)
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_OFFS                                 (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000010)
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_ACR_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_ACR_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_ACR_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_ACR_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_ACR_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_ACR_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_QDSS_VMIDDAP_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000020)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000020)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000024)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000024)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000028)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000028)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000030)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000030)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000034)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000034)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000003c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000003c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_QDSS_VMIDDAP_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000040)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000040)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_ADDR                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000048)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_OFFS                                (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000048)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_RMSK                                0xc00000a2
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_ADDR                         (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000004c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_OFFS                         (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000004c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a2
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_ADDR                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000050)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_OFFS                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000050)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_ADDR                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000054)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_OFFS                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000054)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_RMSK                               0x10001
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                       0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_ADDR                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000058)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_OFFS                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000058)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_ADDR                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000090)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_OFFS                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000090)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_ADDR                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000009c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_OFFS                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000009c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000400)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000400)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_RMSK                                0xfd70ff5
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000408)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000408)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000410)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000410)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_ADDR                             (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000440)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_OFFS                             (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000440)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_ADDR                              (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000448)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_OFFS                              (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000448)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_RMSK                              0xc00000a2
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_ADDR                       (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000044c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_OFFS                       (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000044c)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a2
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_ADDR                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000450)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_OFFS                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000450)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_ADDR                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000454)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_OFFS                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000454)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_RMSK                             0x10001
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                     0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_ADDR                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000458)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_OFFS                          (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000458)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_ADDR                         (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000490)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_OFFS                         (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000490)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_QDSS_VMIDDAP_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_ADDR                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000080)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_OFFS                               (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000080)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_RMSK                                      0x3
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_ADDR, HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_ADDR, m)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_ADDR,v)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_ADDR,m,v,HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_IN)
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_RWE_BMSK                                  0x3
#define HWIO_QDSS_VMIDDAP_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_ADDR(n)                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_OFFS(n)                            (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_MAXn                                        1
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_ADDR(n), HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_INI(n))
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_QDSS_VMIDDAP_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_ADDR(n)                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_OFFS(n)                           (QDSS_VMIDDAP_VMIDDAP_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_MAXn                                       1
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_ADDR(n), HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RMSK)
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_INI(n))
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_QDSS_VMIDDAP_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

/*----------------------------------------------------------------------------
 * MODULE: QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1
 *--------------------------------------------------------------------------*/

#define QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE                   (0      + 0x00077000)
#define QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS              0x00077000

#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000000)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000000)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_RMSK                                0x3fd707f5
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SCR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SCR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SCR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_SCR0_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_SCR0_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_SCR0_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000004)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000004)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_RMSK                                 0x1000300
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SCR1_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SCR1_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SCR1_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_SCR1_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_SCR1_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_SCR1_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_NSNUMSMRGO_BMSK                          0x300
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000008)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000008)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SCR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SCR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SCR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_SCR2_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_SCR2_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_SCR2_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000010)
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000010)
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SACR_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SACR_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SACR_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_SACR_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_SACR_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_SACR_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_QDSS_VMIDETR_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000020)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000020)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000024)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000024)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000028)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000028)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000030)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000030)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000034)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000034)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000003c)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000003c)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_QDSS_VMIDETR_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_ADDR                              (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000040)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_OFFS                              (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000040)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000048)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000048)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_RMSK                               0xc0000022
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_ADDR                        (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000004c)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_OFFS                        (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000004c)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000022
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_ADDR                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000050)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_OFFS                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000050)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_ADDR                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000054)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_OFFS                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000054)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_RMSK                              0x10001
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                      0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_ADDR                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000058)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_OFFS                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000058)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_ADDR                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000090)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_OFFS                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000090)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_ADDR                                 (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000000)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_OFFS                                 (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000000)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_RMSK                                  0xfd70ff5
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_CR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_CR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_CR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_CR0_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_CR0_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_CR0_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_ADDR                                 (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000008)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_OFFS                                 (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000008)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_CR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_CR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_CR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_CR2_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_CR2_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_CR2_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_ADDR                                 (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000010)
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_OFFS                                 (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000010)
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_ACR_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_ACR_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_ACR_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_ACR_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_ACR_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_ACR_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_QDSS_VMIDETR_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000020)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000020)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_IDR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000024)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000024)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR1_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_IDR1_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR1_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000028)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000028)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_IDR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000030)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000030)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR4_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_IDR4_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR4_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000034)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000034)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR5_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_IDR5_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR5_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000003c)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000003c)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR7_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_IDR7_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_IDR7_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_QDSS_VMIDETR_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000040)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000040)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_ADDR                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000048)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_OFFS                                (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000048)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_RMSK                                0xc00000a2
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSR_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_GFSR_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSR_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_GFSR_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_GFSR_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_GFSR_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_ADDR                         (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000004c)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_OFFS                         (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000004c)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a2
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_ADDR                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000050)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_OFFS                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000050)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_ADDR                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000054)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_OFFS                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000054)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_RMSK                               0x10001
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                       0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_ADDR                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000058)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_OFFS                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000058)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_ADDR                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000090)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_OFFS                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000090)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_ADDR                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000009c)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_OFFS                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000009c)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000400)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000400)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_RMSK                                0xfd70ff5
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000408)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000408)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000410)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000410)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSACR_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSACR_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSACR_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_NSACR_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_NSACR_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_NSACR_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_QDSS_VMIDETR_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_ADDR                             (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000440)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_OFFS                             (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000440)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_ADDR                              (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000448)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_OFFS                              (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000448)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_RMSK                              0xc00000a2
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_ADDR                       (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x0000044c)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_OFFS                       (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x0000044c)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a2
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_ADDR                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000450)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_OFFS                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000450)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_ADDR                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000454)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_OFFS                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000454)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_RMSK                             0x10001
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                     0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_ADDR                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000458)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_OFFS                          (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000458)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_QDSS_VMIDETR_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_ADDR                         (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000490)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_OFFS                         (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000490)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_QDSS_VMIDETR_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_ADDR                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000080)
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_OFFS                               (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000080)
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_RMSK                                      0x3
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_ADDR, HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_ADDR, m)
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_ADDR,v)
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_ADDR,m,v,HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_IN)
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_RWE_BMSK                                  0x3
#define HWIO_QDSS_VMIDETR_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_ADDR(n)                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_OFFS(n)                            (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_MAXn                                        1
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_ADDR(n), HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_INI(n))
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_QDSS_VMIDETR_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_ADDR(n)                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_OFFS(n)                           (QDSS_VMIDETR_VMIDETR_VMIDMT_IDX_2_SSD1_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_MAXn                                       1
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_ADDR(n), HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RMSK)
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_INI(n))
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_QDSS_VMIDETR_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

/*----------------------------------------------------------------------------
 * MODULE: PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT
 *--------------------------------------------------------------------------*/

#define PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE                                      (0      + 0x00140000)
#define PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS                                 0x00140000

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_RMSK                                0x3ff707f5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_SMCFCFG_SHFT                              0x15
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000004)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000004)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_RMSK                                 0x1001f00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0x1f00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_ADDR                              (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_OFFS                              (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_RMSK                               0xc0000026
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_SMCF_BMSK                                 0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_SMCF_SHFT                                 0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR                        (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_OFFS                        (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_SMCF_SHFT                          0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_OFFS                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_OFFS                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_RMSK                           0x1f1f001f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                  0x1f000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                        0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                    0x1f0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                     0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_OFFS                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_OFFS                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_ADDR                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_OFFS                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_RMSK                                  0xff70ff5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_SMCFCFG_SHFT                               0x15
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_ADDR                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_OFFS                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_ADDR                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_OFFS                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_ADDR                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_OFFS                                (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_RMSK                                0xc00000a6
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_SMCF_BMSK                                  0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_SMCF_SHFT                                  0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR                         (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_OFFS                         (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_SMCF_SHFT                           0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_OFFS                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_OFFS                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_RMSK                            0x1f1f001f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                   0x1f000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                         0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                     0x1f0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                      0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_OFFS                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_OFFS                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000009c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_OFFS                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000009c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000400)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000400)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_RMSK                                0xff70ff5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_SMCFCFG_SHFT                             0x15
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000408)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000408)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000410)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000410)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_ADDR                             (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000440)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_OFFS                             (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000440)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_ADDR                              (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000448)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_OFFS                              (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000448)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_RMSK                              0xc00000a6
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_SMCF_BMSK                                0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_SMCF_SHFT                                0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR                       (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000044c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OFFS                       (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000044c)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                         0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000450)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_OFFS                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000450)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000454)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_OFFS                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000454)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_RMSK                          0x1f1f001f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                 0x1f000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                       0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                   0x1f0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                    0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000458)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_OFFS                          (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000458)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR                         (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000490)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OFFS                         (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000490)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000080)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000080)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_RMSK                               0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_RWE_BMSK                           0xffffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_ADDR                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000480)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_OFFS                               (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000480)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_RMSK                                0x1ffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_RWE_BMSK                            0x1ffffff
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MSDR0_RWE_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_ADDR                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000494)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_OFFS                                 (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000494)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_RMSK                                        0x7
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_ADDR, HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_ADDR,m,v,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_IN)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_CLKONOFFE_SHFT                              0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_BPMSACFG_BMSK                               0x2
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_BPMSACFG_SHFT                               0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_MCR_BPSMSACFG_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_ADDR(n)                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_OFFS(n)                            (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_MAXn                                       24
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_ADDR(n), HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_INI(n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n)                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_OFFS(n)                           (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_MAXn                                      24
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n), HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_INI(n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_ADDR(n)                             (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000800 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_OFFS(n)                             (PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000800 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_RMSK                                0x801f001f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_MAXn                                        24
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_INI(n)        \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_ADDR(n), HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_RMSK)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_INMI(n,mask)    \
        in_dword_masked(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_OUTI(n,val)    \
        out_dword(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_INI(n))
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_VALID_BMSK                          0x80000000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_VALID_SHFT                                0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_MASK_BMSK                             0x1f0000
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_MASK_SHFT                                 0x10
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_ID_BMSK                                   0x1f
#define HWIO_PERIPH_SS_BLSP1_BLSP_BAM_VMIDMT_SMRn_ID_SHFT                                    0x0

/*----------------------------------------------------------------------------
 * MODULE: PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT
 *--------------------------------------------------------------------------*/

#define PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE                                      (0      + 0x00180000)
#define PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS                                 0x00180000

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_RMSK                                0x3ff707f5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_NSCFG_SHFT                                0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_WACFG_BMSK                           0xc000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_WACFG_SHFT                                0x1a
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_RACFG_BMSK                           0x3000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_RACFG_SHFT                                0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_SHCFG_SHFT                                0x16
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_SMCFCFG_SHFT                              0x15
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_MTCFG_BMSK                            0x100000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_MTCFG_SHFT                                0x14
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_MEMATTR_SHFT                              0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_USFCFG_BMSK                              0x400
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_USFCFG_SHFT                                0xa
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GSE_BMSK                                 0x200
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GSE_SHFT                                   0x9
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_STALLD_BMSK                              0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_STALLD_SHFT                                0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_TRANSIENTCFG_SHFT                          0x6
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GCFGFIE_SHFT                               0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GCFGERE_BMSK                              0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GCFGERE_SHFT                               0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GFIE_BMSK                                  0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_GFIE_SHFT                                  0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR0_CLIENTPD_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000004)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000004)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_RMSK                                 0x1001f00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_GASRAE_SHFT                               0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0x1f00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR1_NSNUMSMRGO_SHFT                            0x8

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_RMSK                                      0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_BPVMID_BMSK                               0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SCR2_BPVMID_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_RMSK                                0x70000013
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPRCNSH_SHFT                              0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPRCISH_SHFT                              0x1d
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPRCOSH_SHFT                              0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                      0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SACR_BPREQPRIORITY_SHFT                         0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_RMSK                               0x88001eff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_SES_BMSK                           0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_SES_SHFT                                 0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_SMS_BMSK                            0x8000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_SMS_SHFT                                 0x1b
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_NUMSIDB_SHFT                              0x9
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR0_NUMSMRG_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_RMSK                                   0x9f00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_SMCD_BMSK                              0x8000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_SMCD_SHFT                                 0xf
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_SSDTP_SHFT                                0xc
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR1_NUMSSDNDX_SHFT                            0x8

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_RMSK                                     0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_OAS_BMSK                                 0xf0
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_OAS_SHFT                                  0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_IAS_BMSK                                  0xf
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR2_IAS_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_RMSK                               0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_MAJOR_SHFT                               0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_MINOR_SHFT                               0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_STEP_BMSK                              0xffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR4_STEP_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_RMSK                                 0xff03ff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_NUMMSDRB_SHFT                            0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_MSAE_BMSK                               0x200
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_MSAE_SHFT                                 0x9
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_QRIBE_BMSK                              0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_QRIBE_SHFT                                0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_NVMID_BMSK                               0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR5_NVMID_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_RMSK                                     0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_MAJOR_SHFT                                0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_MINOR_BMSK                                0xf
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SIDR7_MINOR_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_ADDR                              (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_OFFS                              (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_RMSK                              0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFAR0_SGFEA0_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_RMSK                               0xc0000026
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                        0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_MULTI_CFG_SHFT                           0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_CAF_BMSK                                 0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_CAF_SHFT                                  0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_SMCF_BMSK                                 0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_SMCF_SHFT                                 0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_USF_BMSK                                  0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSR_USF_SHFT                                  0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR                        (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_OFFS                        (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                 0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                    0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_CAF_SHFT                           0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_SMCF_SHFT                          0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSRRESTORE_USF_SHFT                           0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_OFFS                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_RMSK                                0x132
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                      0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_NSATTR_SHFT                           0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                          0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR0_WNR_SHFT                              0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_OFFS                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_RMSK                           0x1f1f001f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                  0x1f000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                        0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                    0x1f0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                        0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                     0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                      0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_OFFS                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_ATID_SHFT                            0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_AVMID_SHFT                           0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_ABID_SHFT                             0xd
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_APID_SHFT                             0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SGFSYNDR2_AMID_SHFT                             0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_OFFS                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_RMSK                                 0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                       0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_ADDR                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000000)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_OFFS                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000000)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_RMSK                                  0xff70ff5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_WACFG_BMSK                            0xc000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_WACFG_SHFT                                 0x1a
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_RACFG_BMSK                            0x3000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_RACFG_SHFT                                 0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_SHCFG_BMSK                             0xc00000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_SHCFG_SHFT                                 0x16
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_SMCFCFG_SHFT                               0x15
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_MTCFG_BMSK                             0x100000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_MTCFG_SHFT                                 0x14
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_MEMATTR_BMSK                            0x70000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_MEMATTR_SHFT                               0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_VMIDPNE_BMSK                              0x800
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_VMIDPNE_SHFT                                0xb
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_USFCFG_BMSK                               0x400
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_USFCFG_SHFT                                 0xa
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GSE_BMSK                                  0x200
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GSE_SHFT                                    0x9
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_STALLD_BMSK                               0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_STALLD_SHFT                                 0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_TRANSIENTCFG_SHFT                           0x6
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GCFGFIE_BMSK                               0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GCFGFIE_SHFT                                0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GCFGERE_BMSK                               0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GCFGERE_SHFT                                0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GFIE_BMSK                                   0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_GFIE_SHFT                                   0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_CLIENTPD_BMSK                               0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR0_CLIENTPD_SHFT                               0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_ADDR                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000008)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_OFFS                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000008)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_RMSK                                       0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_BPVMID_BMSK                                0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_CR2_BPVMID_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_ADDR                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000010)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_OFFS                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000010)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_RMSK                                 0x70000013
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPRCNSH_SHFT                               0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPRCISH_SHFT                               0x1d
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPRCOSH_SHFT                               0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                       0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_ACR_BPREQPRIORITY_SHFT                          0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000020)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000020)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_RMSK                                 0x8001eff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_SMS_BMSK                             0x8000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_SMS_SHFT                                  0x1b
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_NUMSIDB_SHFT                               0x9
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_NUMSMRG_BMSK                              0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR0_NUMSMRG_SHFT                               0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000024)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000024)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_RMSK                                    0x9f00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_SMCD_BMSK                               0x8000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_SMCD_SHFT                                  0xf
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_SSDTP_BMSK                              0x1000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_SSDTP_SHFT                                 0xc
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR1_NUMSSDNDX_SHFT                             0x8

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000028)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000028)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_RMSK                                      0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_OAS_BMSK                                  0xf0
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_OAS_SHFT                                   0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_IAS_BMSK                                   0xf
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR2_IAS_SHFT                                   0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000030)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000030)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_RMSK                                0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_MAJOR_SHFT                                0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_MINOR_SHFT                                0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_STEP_BMSK                               0xffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR4_STEP_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000034)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000034)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_RMSK                                  0xff03ff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_NUMMSDRB_SHFT                             0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_MSAE_BMSK                                0x200
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_MSAE_SHFT                                  0x9
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_QRIBE_BMSK                               0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_QRIBE_SHFT                                 0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_NVMID_BMSK                                0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR5_NVMID_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000003c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_RMSK                                      0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_MAJOR_BMSK                                0xf0
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_MAJOR_SHFT                                 0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_MINOR_BMSK                                 0xf
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_IDR7_MINOR_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000040)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000040)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_RMSK                               0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFAR0_GFEA0_SHFT                                0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_ADDR                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000048)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_OFFS                                (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000048)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_RMSK                                0xc00000a6
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_MULTI_CLIENT_SHFT                         0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_MULTI_CFG_SHFT                            0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_PF_BMSK                                   0x80
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_PF_SHFT                                    0x7
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_CAF_BMSK                                  0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_CAF_SHFT                                   0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_SMCF_BMSK                                  0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_SMCF_SHFT                                  0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_USF_BMSK                                   0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSR_USF_SHFT                                   0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR                         (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_OFFS                         (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000004c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                  0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                     0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_PF_SHFT                             0x7
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_CAF_SHFT                            0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_SMCF_SHFT                           0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSRRESTORE_USF_SHFT                            0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000050)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_OFFS                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000050)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_RMSK                                 0x132
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                       0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_NSATTR_SHFT                            0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_NSSTATE_SHFT                           0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR0_WNR_SHFT                               0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000054)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_OFFS                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000054)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_RMSK                            0x1f1f001f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                   0x1f000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                         0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                     0x1f0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                         0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                      0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                       0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000058)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_OFFS                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000058)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_ATID_SHFT                             0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_AVMID_SHFT                            0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_ABID_SHFT                              0xd
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_APID_SHFT                              0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_AMID_BMSK                             0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_GFSYNDR2_AMID_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000090)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_OFFS                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000090)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_RMSK                                  0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                        0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000009c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_OFFS                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000009c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_RMSK                           0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_VMIDMTACR_RWE_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000400)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000400)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_RMSK                                0xff70ff5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_WACFG_SHFT                               0x1a
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_RACFG_SHFT                               0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_SHCFG_SHFT                               0x16
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_SMCFCFG_SHFT                             0x15
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_MTCFG_SHFT                               0x14
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_MEMATTR_SHFT                             0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_VMIDPNE_SHFT                              0xb
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_USFCFG_BMSK                             0x400
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_USFCFG_SHFT                               0xa
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GSE_BMSK                                0x200
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GSE_SHFT                                  0x9
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_STALLD_BMSK                             0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_STALLD_SHFT                               0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                         0x6
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GCFGFIE_SHFT                              0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GCFGERE_SHFT                              0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GFIE_BMSK                                 0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_GFIE_SHFT                                 0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR0_CLIENTPD_SHFT                             0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000408)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000408)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_RMSK                                     0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_BPVMID_BMSK                              0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSCR2_BPVMID_SHFT                               0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000410)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000410)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_RMSK                               0x70000013
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPRCNSH_SHFT                             0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPRCISH_SHFT                             0x1d
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPRCOSH_SHFT                             0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                     0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSACR_BPREQPRIORITY_SHFT                        0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_ADDR                             (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000440)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_OFFS                             (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000440)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_RMSK                             0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFAR0_GFEA0_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_ADDR                              (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000448)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_OFFS                              (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000448)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_RMSK                              0xc00000a6
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                       0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_MULTI_CFG_SHFT                          0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_PF_BMSK                                 0x80
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_PF_SHFT                                  0x7
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_CAF_BMSK                                0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_CAF_SHFT                                 0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_SMCF_BMSK                                0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_SMCF_SHFT                                0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_USF_BMSK                                 0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSR_USF_SHFT                                 0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR                       (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x0000044c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OFFS                       (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x0000044c)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                   0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_PF_SHFT                           0x7
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_CAF_SHFT                          0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                         0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSRRESTORE_USF_SHFT                          0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000450)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_OFFS                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000450)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_RMSK                               0x132
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                     0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                          0x5
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                         0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR0_WNR_SHFT                             0x1

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000454)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_OFFS                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000454)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_RMSK                          0x1f1f001f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                 0x1f000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                       0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                   0x1f0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                       0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                    0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                     0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000458)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_OFFS                          (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000458)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_ATID_SHFT                           0x18
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_AVMID_SHFT                          0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_ABID_SHFT                            0xd
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_APID_SHFT                            0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSGFSYNDR2_AMID_SHFT                            0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR                         (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000490)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OFFS                         (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000490)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_RMSK                                0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                      0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000080)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000080)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_RMSK                               0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_RWE_BMSK                           0xffffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SSDR0_RWE_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_ADDR                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000480)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_OFFS                               (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000480)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_RMSK                                0x1ffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_RWE_BMSK                            0x1ffffff
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MSDR0_RWE_SHFT                                  0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_ADDR                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000494)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_OFFS                                 (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000494)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_RMSK                                        0x7
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_IN          \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_ADDR, HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_INM(m)      \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_ADDR, m)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_OUT(v)      \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_ADDR,v)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_ADDR,m,v,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_IN)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_CLKONOFFE_SHFT                              0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_BPMSACFG_BMSK                               0x2
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_BPMSACFG_SHFT                               0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_MCR_BPSMSACFG_SHFT                              0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_ADDR(n)                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000c00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_OFFS(n)                            (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000c00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_RMSK                               0x30ff7b1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_MAXn                                       24
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_INI(n)        \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_ADDR(n), HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_OUTI(n,val)    \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_INI(n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                        0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_WACFG_SHFT                               0x16
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_RACFG_BMSK                           0x300000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_RACFG_SHFT                               0x14
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_NSCFG_SHFT                               0x12
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_TYPE_BMSK                             0x30000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_TYPE_SHFT                                0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_MEMATTR_SHFT                              0xc
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_MTCFG_BMSK                              0x800
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_MTCFG_SHFT                                0xb
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_SHCFG_BMSK                              0x300
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_SHCFG_SHFT                                0x8
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_VMID_BMSK                                0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_S2VRn_VMID_SHFT                                 0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n)                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000e00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_OFFS(n)                           (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000e00 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RMSK                              0x70000013
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_MAXn                                      24
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_INI(n)        \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n), HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_INMI(n,mask)    \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_OUTI(n,val)    \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_INI(n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RCNSH_SHFT                              0x1e
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RCISH_SHFT                              0x1d
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_RCOSH_SHFT                              0x1c
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                      0x4
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_AS2VRn_REQPRIORITY_SHFT                         0x0

#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_ADDR(n)                             (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE      + 0x00000800 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_OFFS(n)                             (PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_REG_BASE_OFFS + 0x00000800 + 0x4 * (n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_RMSK                                0x801f001f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_MAXn                                        24
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_INI(n)        \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_ADDR(n), HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_RMSK)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_INMI(n,mask)    \
        in_dword_masked(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_OUTI(n,val)    \
        out_dword(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_INI(n))
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_VALID_BMSK                          0x80000000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_VALID_SHFT                                0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_MASK_BMSK                             0x1f0000
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_MASK_SHFT                                 0x10
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_ID_BMSK                                   0x1f
#define HWIO_PERIPH_SS_BLSP2_BLSP_BAM_VMIDMT_SMRn_ID_SHFT                                    0x0


#endif /* __HALVMIDMTHWIOTARGET_H__ */
