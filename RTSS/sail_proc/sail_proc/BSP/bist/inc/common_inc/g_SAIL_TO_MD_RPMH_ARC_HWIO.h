#ifndef __G_SAIL_TO_MD_RPMH_ARC_HWIO_H__
#define __G_SAIL_TO_MD_RPMH_ARC_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_RPMH_ARC_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_RPMH_ARC_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/common_inc/g_SAIL_TO_MD_RPMH_ARC_HWIO.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE                                                     (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x0b7fea00ul)
#define SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_SIZE                                                0x500u
#define SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_USED                                                0x3f4u
#define SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS                                                0x0b7fea00ul

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_ADDR(m)                                    (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X40 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_OFFS(m)                                    (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X40 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_MAXm                                               13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_OVERRIDE_PWR_CTRL_VAL_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_VAL_RMm_OVERRIDE_PWR_CTRL_VAL_SHFT                          0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_ADDR(m)                                   (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X80 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_OFFS(m)                                   (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X80 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_MAXm                                              13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_OVERRIDE_PWR_CTRL2_VAL_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_VAL_RMm_OVERRIDE_PWR_CTRL2_VAL_SHFT                        0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_ADDR(m)                                   (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0XC0 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_OFFS(m)                                   (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0XC0 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_MAXm                                              13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_OVERRIDE_PWR_CTRL_MASK_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm_OVERRIDE_PWR_CTRL_MASK_SHFT                        0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_ADDR(m)                                  (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X100 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_OFFS(m)                                  (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X100 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_MAXm                                             13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_OVERRIDE_PWR_CTRL2_MASK_BMSK             0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm_OVERRIDE_PWR_CTRL2_MASK_SHFT                      0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_ADDR(m)                                  (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X140 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_OFFS(m)                                  (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X140 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_MAXm                                             13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_OVERRIDE_WAIT_EVENT_VAL_BMSK             0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_VAL_RMm_OVERRIDE_WAIT_EVENT_VAL_SHFT                      0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_ADDR(m)                                 (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X180 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_OFFS(m)                                 (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X180 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_RMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_MAXm                                            13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_OVERRIDE_WAIT_EVENT_MASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT_MASK_RMm_OVERRIDE_WAIT_EVENT_MASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_ADDR(m)                                    (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X1C0 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_OFFS(m)                                    (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X1C0 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_MAXm                                               13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_OVERRIDE_BR_EVENT_VAL_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_VAL_RMm_OVERRIDE_BR_EVENT_VAL_SHFT                          0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_ADDR(m)                                   (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X200 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_OFFS(m)                                   (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X200 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_MAXm                                              13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_OVERRIDE_BR_EVENT_MASK_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_BR_EVENT_MASK_RMm_OVERRIDE_BR_EVENT_MASK_SHFT                        0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_ADDR(m)                                     (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X240 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_OFFS(m)                                     (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X240 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_RMSK                                               0x3u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_MAXm                                                13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_OVERRIDE_MEM_ACC_VAL_BMSK                          0x3u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_VAL_RMm_OVERRIDE_MEM_ACC_VAL_SHFT                            0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_ADDR(m)                                    (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X280 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_OFFS(m)                                    (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X280 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_RMSK                                              0x3u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_MAXm                                               13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_OVERRIDE_MEM_ACC_MASK_BMSK                        0x3u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_MEM_ACC_MASK_RMm_OVERRIDE_MEM_ACC_MASK_SHFT                          0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_ADDR(m)                                          (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X300 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_OFFS(m)                                          (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X300 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_RMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_MAXm                                                     13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_UNBLOCK_SEQ_PRE_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_PRE_RMm_UNBLOCK_SEQ_PRE_SHFT                                      0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_ADDR(m)                                         (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X340 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_OFFS(m)                                         (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X340 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_RMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_MAXm                                                    13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_UNBLOCK_SEQ_POST_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_UNBLOCK_SEQ_POST_RMm_UNBLOCK_SEQ_POST_SHFT                                    0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_ADDR(m)                                 (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X380 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_OFFS(m)                                 (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X380 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_RMSK                                        0xffffu
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_MAXm                                            13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_OVERRIDE_WAIT_EVENT_VAL_BMSK                0xffffu
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_VAL_RMm_OVERRIDE_WAIT_EVENT_VAL_SHFT                     0u

#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_ADDR(m)                                (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE      + 0X3C0 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_OFFS(m)                                (SAIL_TO_MD_RPMH_ARC_ARC_SW_OVERRIDE_REG_BASE_OFFS + 0X3C0 + (0x4*(m)))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_RMSK                                       0xffffu
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_MAXm                                           13u
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_INI(m)                \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_ADDR(m), HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_RMSK)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_INMI(m,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_ADDR(m), mask)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_OUTI(m,val)        \
                out_dword(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_ADDR(m),val)
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_ADDR(m),mask,val,HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_INI(m))
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_OVERRIDE_WAIT_EVENT_MASK_BMSK              0xffffu
#define HWIO_SAIL_TO_MD_RPMH_ARC_SW_OVERRIDE_WAIT_EVENT2_MASK_RMm_OVERRIDE_WAIT_EVENT_MASK_SHFT                   0u


#endif /* __G_SAIL_TO_MD_RPMH_ARC_HWIO_H__ */
