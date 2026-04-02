#ifndef __PSAILHWIO__
#define __PSAILHWIO__
/*
===========================================================================
*/
/**
    @file psailHWIO
    @brief Auto-generated HWIO interface include file.

    This file contains HWIO register definitions for the following modules:
        REVID
        FAULT_AGG
        SDAM01
        LDO04_MON_MM
        BIST_CTL
        PON_PBS

    'Include' filters applied: <none>
    'Exclude' filters applied: <none>
*/
/*
    ===========================================================================
  
  Copyright (c) 2023 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  Qualcomm Confidential and Proprietary
  
  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.
  
  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly
  reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.
  
===========================================================================

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * PERIPHERAL: REVID
 *--------------------------------------------------------------------------*/

#define REVID_BASE                                               0x00000100

#define HWIO_REVID_REVISION1_ADDR                                (REVID_BASE            + 0x00000000)
#define HWIO_REVID_REVISION1_OFFS                                0x00000000
#define HWIO_REVID_REVISION1_RMSK                                      0xff
#define HWIO_REVID_REVISION1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION1_ADDR, HWIO_REVID_REVISION1_RMSK, 0, val)
#define HWIO_REVID_REVISION1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION1_ADDR, mask, shift, val)
#define HWIO_REVID_REVISION1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_REVISION1_ADDR, val, len)
#define HWIO_REVID_REVISION1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_REVISION1_ADDR, val)
#define HWIO_REVID_REVISION1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION1_ADDR, mask, shift, val)
#define HWIO_REVID_REVISION1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_REVISION1_ADDR, val, len)
#define HWIO_REVID_REVISION1_ALL_LAYER_BMSK                            0xf0
#define HWIO_REVID_REVISION1_ALL_LAYER_SHFT                             0x4
#define HWIO_REVID_REVISION1_METAL_BMSK                                 0xf
#define HWIO_REVID_REVISION1_METAL_SHFT                                 0x0

#define HWIO_REVID_REVISION2_ADDR                                (REVID_BASE            + 0x00000001)
#define HWIO_REVID_REVISION2_OFFS                                0x00000001
#define HWIO_REVID_REVISION2_RMSK                                       0xf
#define HWIO_REVID_REVISION2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION2_ADDR, HWIO_REVID_REVISION2_RMSK, 0, val)
#define HWIO_REVID_REVISION2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION2_ADDR, mask, shift, val)
#define HWIO_REVID_REVISION2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_REVISION2_ADDR, val, len)
#define HWIO_REVID_REVISION2_VARIANT_BMSK                               0xf
#define HWIO_REVID_REVISION2_VARIANT_SHFT                               0x0

#define HWIO_REVID_REVISION3_ADDR                                (REVID_BASE            + 0x00000002)
#define HWIO_REVID_REVISION3_OFFS                                0x00000002
#define HWIO_REVID_REVISION3_RMSK                                       0xf
#define HWIO_REVID_REVISION3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION3_ADDR, HWIO_REVID_REVISION3_RMSK, 0, val)
#define HWIO_REVID_REVISION3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION3_ADDR, mask, shift, val)
#define HWIO_REVID_REVISION3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_REVISION3_ADDR, val, len)
#define HWIO_REVID_REVISION3_METAL_BMSK                                 0xf
#define HWIO_REVID_REVISION3_METAL_SHFT                                 0x0

#define HWIO_REVID_REVISION4_ADDR                                (REVID_BASE            + 0x00000003)
#define HWIO_REVID_REVISION4_OFFS                                0x00000003
#define HWIO_REVID_REVISION4_RMSK                                       0xf
#define HWIO_REVID_REVISION4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION4_ADDR, HWIO_REVID_REVISION4_RMSK, 0, val)
#define HWIO_REVID_REVISION4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVISION4_ADDR, mask, shift, val)
#define HWIO_REVID_REVISION4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_REVISION4_ADDR, val, len)
#define HWIO_REVID_REVISION4_ALL_LAYER_BMSK                             0xf
#define HWIO_REVID_REVISION4_ALL_LAYER_SHFT                             0x0

#define HWIO_REVID_PERPH_TYPE_ADDR                               (REVID_BASE            + 0x00000004)
#define HWIO_REVID_PERPH_TYPE_OFFS                               0x00000004
#define HWIO_REVID_PERPH_TYPE_RMSK                                     0xff
#define HWIO_REVID_PERPH_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_PERPH_TYPE_ADDR, HWIO_REVID_PERPH_TYPE_RMSK, 0, val)
#define HWIO_REVID_PERPH_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_PERPH_TYPE_ADDR, mask, shift, val)
#define HWIO_REVID_PERPH_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_PERPH_TYPE_ADDR, val, len)
#define HWIO_REVID_PERPH_TYPE_TYPE_BMSK                                0xff
#define HWIO_REVID_PERPH_TYPE_TYPE_SHFT                                 0x0

#define HWIO_REVID_PERPH_SUBTYPE_ADDR                            (REVID_BASE            + 0x00000005)
#define HWIO_REVID_PERPH_SUBTYPE_OFFS                            0x00000005
#define HWIO_REVID_PERPH_SUBTYPE_RMSK                                  0xff
#define HWIO_REVID_PERPH_SUBTYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_PERPH_SUBTYPE_ADDR, HWIO_REVID_PERPH_SUBTYPE_RMSK, 0, val)
#define HWIO_REVID_PERPH_SUBTYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_PERPH_SUBTYPE_ADDR, mask, shift, val)
#define HWIO_REVID_PERPH_SUBTYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_PERPH_SUBTYPE_ADDR, val, len)
#define HWIO_REVID_PERPH_SUBTYPE_SUBTYPE_BMSK                          0xff
#define HWIO_REVID_PERPH_SUBTYPE_SUBTYPE_SHFT                           0x0

#define HWIO_REVID_SLAVE_COUNT_ADDR                              (REVID_BASE            + 0x00000006)
#define HWIO_REVID_SLAVE_COUNT_OFFS                              0x00000006
#define HWIO_REVID_SLAVE_COUNT_RMSK                                    0xff
#define HWIO_REVID_SLAVE_COUNT_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SLAVE_COUNT_ADDR, HWIO_REVID_SLAVE_COUNT_RMSK, 0, val)
#define HWIO_REVID_SLAVE_COUNT_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SLAVE_COUNT_ADDR, mask, shift, val)
#define HWIO_REVID_SLAVE_COUNT_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_SLAVE_COUNT_ADDR, val, len)
#define HWIO_REVID_SLAVE_COUNT_SLAVE_COUNT_BMSK                        0xff
#define HWIO_REVID_SLAVE_COUNT_SLAVE_COUNT_SHFT                         0x0

#define HWIO_REVID_SBL_ID_0_ADDR                                 (REVID_BASE            + 0x00000050)
#define HWIO_REVID_SBL_ID_0_OFFS                                 0x00000050
#define HWIO_REVID_SBL_ID_0_RMSK                                       0xff
#define HWIO_REVID_SBL_ID_0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SBL_ID_0_ADDR, HWIO_REVID_SBL_ID_0_RMSK, 0, val)
#define HWIO_REVID_SBL_ID_0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SBL_ID_0_ADDR, mask, shift, val)
#define HWIO_REVID_SBL_ID_0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_SBL_ID_0_ADDR, val, len)
#define HWIO_REVID_SBL_ID_0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_SBL_ID_0_ADDR, val)
#define HWIO_REVID_SBL_ID_0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_SBL_ID_0_ADDR, mask, shift, val)
#define HWIO_REVID_SBL_ID_0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_SBL_ID_0_ADDR, val, len)
#define HWIO_REVID_SBL_ID_0_VERSION_BMSK                               0xff
#define HWIO_REVID_SBL_ID_0_VERSION_SHFT                                0x0

#define HWIO_REVID_SBL_ID_1_ADDR                                 (REVID_BASE            + 0x00000051)
#define HWIO_REVID_SBL_ID_1_OFFS                                 0x00000051
#define HWIO_REVID_SBL_ID_1_RMSK                                       0xff
#define HWIO_REVID_SBL_ID_1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SBL_ID_1_ADDR, HWIO_REVID_SBL_ID_1_RMSK, 0, val)
#define HWIO_REVID_SBL_ID_1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SBL_ID_1_ADDR, mask, shift, val)
#define HWIO_REVID_SBL_ID_1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_SBL_ID_1_ADDR, val, len)
#define HWIO_REVID_SBL_ID_1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_SBL_ID_1_ADDR, val)
#define HWIO_REVID_SBL_ID_1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_SBL_ID_1_ADDR, mask, shift, val)
#define HWIO_REVID_SBL_ID_1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_SBL_ID_1_ADDR, val, len)
#define HWIO_REVID_SBL_ID_1_VERSION_BMSK                               0xff
#define HWIO_REVID_SBL_ID_1_VERSION_SHFT                                0x0

#define HWIO_REVID_PBS_OTP_ID_0_ADDR                             (REVID_BASE            + 0x00000054)
#define HWIO_REVID_PBS_OTP_ID_0_OFFS                             0x00000054
#define HWIO_REVID_PBS_OTP_ID_0_RMSK                                   0xff
#define HWIO_REVID_PBS_OTP_ID_0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_PBS_OTP_ID_0_ADDR, HWIO_REVID_PBS_OTP_ID_0_RMSK, 0, val)
#define HWIO_REVID_PBS_OTP_ID_0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_PBS_OTP_ID_0_ADDR, mask, shift, val)
#define HWIO_REVID_PBS_OTP_ID_0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_PBS_OTP_ID_0_ADDR, val, len)
#define HWIO_REVID_PBS_OTP_ID_0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_PBS_OTP_ID_0_ADDR, val)
#define HWIO_REVID_PBS_OTP_ID_0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_PBS_OTP_ID_0_ADDR, mask, shift, val)
#define HWIO_REVID_PBS_OTP_ID_0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_PBS_OTP_ID_0_ADDR, val, len)
#define HWIO_REVID_PBS_OTP_ID_0_VERSION_BMSK                           0xff
#define HWIO_REVID_PBS_OTP_ID_0_VERSION_SHFT                            0x0

#define HWIO_REVID_REVID_SPARE_0_ADDR                            (REVID_BASE            + 0x00000060)
#define HWIO_REVID_REVID_SPARE_0_OFFS                            0x00000060
#define HWIO_REVID_REVID_SPARE_0_RMSK                                  0xff
#define HWIO_REVID_REVID_SPARE_0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVID_SPARE_0_ADDR, HWIO_REVID_REVID_SPARE_0_RMSK, 0, val)
#define HWIO_REVID_REVID_SPARE_0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVID_SPARE_0_ADDR, mask, shift, val)
#define HWIO_REVID_REVID_SPARE_0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_REVID_SPARE_0_ADDR, val, len)
#define HWIO_REVID_REVID_SPARE_0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_REVID_SPARE_0_ADDR, val)
#define HWIO_REVID_REVID_SPARE_0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_REVID_SPARE_0_ADDR, mask, shift, val)
#define HWIO_REVID_REVID_SPARE_0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_REVID_SPARE_0_ADDR, val, len)
#define HWIO_REVID_REVID_SPARE_0_SPARE_BMSK                            0xff
#define HWIO_REVID_REVID_SPARE_0_SPARE_SHFT                             0x0

#define HWIO_REVID_REVID_SPARE_1_ADDR                            (REVID_BASE            + 0x00000061)
#define HWIO_REVID_REVID_SPARE_1_OFFS                            0x00000061
#define HWIO_REVID_REVID_SPARE_1_RMSK                                  0xff
#define HWIO_REVID_REVID_SPARE_1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVID_SPARE_1_ADDR, HWIO_REVID_REVID_SPARE_1_RMSK, 0, val)
#define HWIO_REVID_REVID_SPARE_1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_REVID_SPARE_1_ADDR, mask, shift, val)
#define HWIO_REVID_REVID_SPARE_1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_REVID_SPARE_1_ADDR, val, len)
#define HWIO_REVID_REVID_SPARE_1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_REVID_SPARE_1_ADDR, val)
#define HWIO_REVID_REVID_SPARE_1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_REVID_SPARE_1_ADDR, mask, shift, val)
#define HWIO_REVID_REVID_SPARE_1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_REVID_SPARE_1_ADDR, val, len)
#define HWIO_REVID_REVID_SPARE_1_SPARE_BMSK                            0xff
#define HWIO_REVID_REVID_SPARE_1_SPARE_SHFT                             0x0

#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_ADDR                (REVID_BASE            + 0x00000087)
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_OFFS                0x00000087
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_RMSK                      0xff
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_ADDR, HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_RMSK, 0, val)
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_ADDR, mask, shift, val)
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_ADDR, val, len)
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_ADDR, val)
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_ADDR, mask, shift, val)
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_ADDR, val, len)
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_SPARE_BMSK                0xff
#define HWIO_REVID_SPMI_PBUS_INTEGRITY_CHECK_SPARE_SHFT                 0x0

#define HWIO_REVID_LOCKBIT_D1_ADDR                               (REVID_BASE            + 0x000000d1)
#define HWIO_REVID_LOCKBIT_D1_OFFS                               0x000000d1
#define HWIO_REVID_LOCKBIT_D1_RMSK                                      0x3
#define HWIO_REVID_LOCKBIT_D1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOCKBIT_D1_ADDR, HWIO_REVID_LOCKBIT_D1_RMSK, 0, val)
#define HWIO_REVID_LOCKBIT_D1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_REVID_LOCKBIT_D1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOCKBIT_D1_ADDR, val, len)
#define HWIO_REVID_LOCKBIT_D1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOCKBIT_D1_ADDR, val)
#define HWIO_REVID_LOCKBIT_D1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_REVID_LOCKBIT_D1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOCKBIT_D1_ADDR, val, len)
#define HWIO_REVID_LOCKBIT_D1_LOCKBIT_D1_BMSK                           0x3
#define HWIO_REVID_LOCKBIT_D1_LOCKBIT_D1_SHFT                           0x0

#define HWIO_REVID_ILLEGAL_WRITE_STATUS_ADDR                     (REVID_BASE            + 0x000000d4)
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_OFFS                     0x000000d4
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_RMSK                            0x1
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_ILLEGAL_WRITE_STATUS_ADDR, HWIO_REVID_ILLEGAL_WRITE_STATUS_RMSK, 0, val)
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_ILLEGAL_WRITE_STATUS_ADDR, val)
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_BMSK                 0x1
#define HWIO_REVID_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_SHFT                 0x0

#define HWIO_REVID_TRIM_NUM_ADDR                                 (REVID_BASE            + 0x000000f0)
#define HWIO_REVID_TRIM_NUM_OFFS                                 0x000000f0
#define HWIO_REVID_TRIM_NUM_RMSK                                       0xff
#define HWIO_REVID_TRIM_NUM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_TRIM_NUM_ADDR, HWIO_REVID_TRIM_NUM_RMSK, 0, val)
#define HWIO_REVID_TRIM_NUM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_TRIM_NUM_ADDR, mask, shift, val)
#define HWIO_REVID_TRIM_NUM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_TRIM_NUM_ADDR, val, len)
#define HWIO_REVID_TRIM_NUM_TRIM_NUM_BMSK                              0xff
#define HWIO_REVID_TRIM_NUM_TRIM_NUM_SHFT                               0x0

#define HWIO_REVID_TP_REV_ADDR                                   (REVID_BASE            + 0x000000f1)
#define HWIO_REVID_TP_REV_OFFS                                   0x000000f1
#define HWIO_REVID_TP_REV_RMSK                                         0xff
#define HWIO_REVID_TP_REV_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_TP_REV_ADDR, HWIO_REVID_TP_REV_RMSK, 0, val)
#define HWIO_REVID_TP_REV_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_TP_REV_ADDR, mask, shift, val)
#define HWIO_REVID_TP_REV_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_TP_REV_ADDR, val, len)
#define HWIO_REVID_TP_REV_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_TP_REV_ADDR, val)
#define HWIO_REVID_TP_REV_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_TP_REV_ADDR, mask, shift, val)
#define HWIO_REVID_TP_REV_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_TP_REV_ADDR, val, len)
#define HWIO_REVID_TP_REV_TP_REV_BMSK                                  0xff
#define HWIO_REVID_TP_REV_TP_REV_SHFT                                   0x0

#define HWIO_REVID_FAB_ID_ADDR                                   (REVID_BASE            + 0x000000f2)
#define HWIO_REVID_FAB_ID_OFFS                                   0x000000f2
#define HWIO_REVID_FAB_ID_RMSK                                         0xff
#define HWIO_REVID_FAB_ID_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_FAB_ID_ADDR, HWIO_REVID_FAB_ID_RMSK, 0, val)
#define HWIO_REVID_FAB_ID_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_FAB_ID_ADDR, mask, shift, val)
#define HWIO_REVID_FAB_ID_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_FAB_ID_ADDR, val, len)
#define HWIO_REVID_FAB_ID_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_FAB_ID_ADDR, val)
#define HWIO_REVID_FAB_ID_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_FAB_ID_ADDR, mask, shift, val)
#define HWIO_REVID_FAB_ID_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_FAB_ID_ADDR, val, len)
#define HWIO_REVID_FAB_ID_FAB_ID_BMSK                                  0xff
#define HWIO_REVID_FAB_ID_FAB_ID_SHFT                                   0x0

#define HWIO_REVID_WAFER_ID_ADDR                                 (REVID_BASE            + 0x000000f3)
#define HWIO_REVID_WAFER_ID_OFFS                                 0x000000f3
#define HWIO_REVID_WAFER_ID_RMSK                                       0xff
#define HWIO_REVID_WAFER_ID_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_WAFER_ID_ADDR, HWIO_REVID_WAFER_ID_RMSK, 0, val)
#define HWIO_REVID_WAFER_ID_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_WAFER_ID_ADDR, mask, shift, val)
#define HWIO_REVID_WAFER_ID_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_WAFER_ID_ADDR, val, len)
#define HWIO_REVID_WAFER_ID_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_WAFER_ID_ADDR, val)
#define HWIO_REVID_WAFER_ID_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_WAFER_ID_ADDR, mask, shift, val)
#define HWIO_REVID_WAFER_ID_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_WAFER_ID_ADDR, val, len)
#define HWIO_REVID_WAFER_ID_WAFER_ID_BMSK                              0xff
#define HWIO_REVID_WAFER_ID_WAFER_ID_SHFT                               0x0

#define HWIO_REVID_X_COORD_ADDR                                  (REVID_BASE            + 0x000000f4)
#define HWIO_REVID_X_COORD_OFFS                                  0x000000f4
#define HWIO_REVID_X_COORD_RMSK                                        0xff
#define HWIO_REVID_X_COORD_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_X_COORD_ADDR, HWIO_REVID_X_COORD_RMSK, 0, val)
#define HWIO_REVID_X_COORD_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_X_COORD_ADDR, mask, shift, val)
#define HWIO_REVID_X_COORD_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_X_COORD_ADDR, val, len)
#define HWIO_REVID_X_COORD_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_X_COORD_ADDR, val)
#define HWIO_REVID_X_COORD_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_X_COORD_ADDR, mask, shift, val)
#define HWIO_REVID_X_COORD_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_X_COORD_ADDR, val, len)
#define HWIO_REVID_X_COORD_X_COORD_BMSK                                0xff
#define HWIO_REVID_X_COORD_X_COORD_SHFT                                 0x0

#define HWIO_REVID_Y_COORD_ADDR                                  (REVID_BASE            + 0x000000f5)
#define HWIO_REVID_Y_COORD_OFFS                                  0x000000f5
#define HWIO_REVID_Y_COORD_RMSK                                        0xff
#define HWIO_REVID_Y_COORD_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_Y_COORD_ADDR, HWIO_REVID_Y_COORD_RMSK, 0, val)
#define HWIO_REVID_Y_COORD_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_Y_COORD_ADDR, mask, shift, val)
#define HWIO_REVID_Y_COORD_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_Y_COORD_ADDR, val, len)
#define HWIO_REVID_Y_COORD_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_Y_COORD_ADDR, val)
#define HWIO_REVID_Y_COORD_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_Y_COORD_ADDR, mask, shift, val)
#define HWIO_REVID_Y_COORD_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_Y_COORD_ADDR, val, len)
#define HWIO_REVID_Y_COORD_Y_COORD_BMSK                                0xff
#define HWIO_REVID_Y_COORD_Y_COORD_SHFT                                 0x0

#define HWIO_REVID_LOT_ID_11_10_ADDR                             (REVID_BASE            + 0x000000f6)
#define HWIO_REVID_LOT_ID_11_10_OFFS                             0x000000f6
#define HWIO_REVID_LOT_ID_11_10_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_11_10_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_11_10_ADDR, HWIO_REVID_LOT_ID_11_10_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_11_10_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_11_10_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_11_10_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_11_10_ADDR, val, len)
#define HWIO_REVID_LOT_ID_11_10_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_11_10_ADDR, val)
#define HWIO_REVID_LOT_ID_11_10_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_11_10_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_11_10_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_11_10_ADDR, val, len)
#define HWIO_REVID_LOT_ID_11_10_LOT_ID_11_5_0_BMSK                     0xfc
#define HWIO_REVID_LOT_ID_11_10_LOT_ID_11_5_0_SHFT                      0x2
#define HWIO_REVID_LOT_ID_11_10_LOT_ID_10_5_4_BMSK                      0x3
#define HWIO_REVID_LOT_ID_11_10_LOT_ID_10_5_4_SHFT                      0x0

#define HWIO_REVID_LOT_ID_10_09_ADDR                             (REVID_BASE            + 0x000000f7)
#define HWIO_REVID_LOT_ID_10_09_OFFS                             0x000000f7
#define HWIO_REVID_LOT_ID_10_09_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_10_09_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_10_09_ADDR, HWIO_REVID_LOT_ID_10_09_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_10_09_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_10_09_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_10_09_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_10_09_ADDR, val, len)
#define HWIO_REVID_LOT_ID_10_09_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_10_09_ADDR, val)
#define HWIO_REVID_LOT_ID_10_09_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_10_09_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_10_09_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_10_09_ADDR, val, len)
#define HWIO_REVID_LOT_ID_10_09_LOT_ID_10_3_0_BMSK                     0xf0
#define HWIO_REVID_LOT_ID_10_09_LOT_ID_10_3_0_SHFT                      0x4
#define HWIO_REVID_LOT_ID_10_09_LOT_ID_09_5_2_BMSK                      0xf
#define HWIO_REVID_LOT_ID_10_09_LOT_ID_09_5_2_SHFT                      0x0

#define HWIO_REVID_LOT_ID_09_08_ADDR                             (REVID_BASE            + 0x000000f8)
#define HWIO_REVID_LOT_ID_09_08_OFFS                             0x000000f8
#define HWIO_REVID_LOT_ID_09_08_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_09_08_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_09_08_ADDR, HWIO_REVID_LOT_ID_09_08_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_09_08_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_09_08_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_09_08_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_09_08_ADDR, val, len)
#define HWIO_REVID_LOT_ID_09_08_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_09_08_ADDR, val)
#define HWIO_REVID_LOT_ID_09_08_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_09_08_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_09_08_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_09_08_ADDR, val, len)
#define HWIO_REVID_LOT_ID_09_08_LOT_ID_09_1_0_BMSK                     0xc0
#define HWIO_REVID_LOT_ID_09_08_LOT_ID_09_1_0_SHFT                      0x6
#define HWIO_REVID_LOT_ID_09_08_LOT_ID_08_5_0_BMSK                     0x3f
#define HWIO_REVID_LOT_ID_09_08_LOT_ID_08_5_0_SHFT                      0x0

#define HWIO_REVID_LOT_ID_07_06_ADDR                             (REVID_BASE            + 0x000000f9)
#define HWIO_REVID_LOT_ID_07_06_OFFS                             0x000000f9
#define HWIO_REVID_LOT_ID_07_06_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_07_06_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_07_06_ADDR, HWIO_REVID_LOT_ID_07_06_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_07_06_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_07_06_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_07_06_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_07_06_ADDR, val, len)
#define HWIO_REVID_LOT_ID_07_06_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_07_06_ADDR, val)
#define HWIO_REVID_LOT_ID_07_06_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_07_06_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_07_06_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_07_06_ADDR, val, len)
#define HWIO_REVID_LOT_ID_07_06_LOT_ID_07_5_0_BMSK                     0xfc
#define HWIO_REVID_LOT_ID_07_06_LOT_ID_07_5_0_SHFT                      0x2
#define HWIO_REVID_LOT_ID_07_06_LOT_ID_06_5_4_BMSK                      0x3
#define HWIO_REVID_LOT_ID_07_06_LOT_ID_06_5_4_SHFT                      0x0

#define HWIO_REVID_LOT_ID_06_05_ADDR                             (REVID_BASE            + 0x000000fa)
#define HWIO_REVID_LOT_ID_06_05_OFFS                             0x000000fa
#define HWIO_REVID_LOT_ID_06_05_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_06_05_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_06_05_ADDR, HWIO_REVID_LOT_ID_06_05_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_06_05_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_06_05_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_06_05_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_06_05_ADDR, val, len)
#define HWIO_REVID_LOT_ID_06_05_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_06_05_ADDR, val)
#define HWIO_REVID_LOT_ID_06_05_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_06_05_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_06_05_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_06_05_ADDR, val, len)
#define HWIO_REVID_LOT_ID_06_05_LOT_ID_06_3_0_BMSK                     0xf0
#define HWIO_REVID_LOT_ID_06_05_LOT_ID_06_3_0_SHFT                      0x4
#define HWIO_REVID_LOT_ID_06_05_LOT_ID_05_5_2_BMSK                      0xf
#define HWIO_REVID_LOT_ID_06_05_LOT_ID_05_5_2_SHFT                      0x0

#define HWIO_REVID_LOT_ID_05_04_ADDR                             (REVID_BASE            + 0x000000fb)
#define HWIO_REVID_LOT_ID_05_04_OFFS                             0x000000fb
#define HWIO_REVID_LOT_ID_05_04_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_05_04_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_05_04_ADDR, HWIO_REVID_LOT_ID_05_04_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_05_04_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_05_04_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_05_04_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_05_04_ADDR, val, len)
#define HWIO_REVID_LOT_ID_05_04_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_05_04_ADDR, val)
#define HWIO_REVID_LOT_ID_05_04_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_05_04_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_05_04_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_05_04_ADDR, val, len)
#define HWIO_REVID_LOT_ID_05_04_LOT_ID_05_1_0_BMSK                     0xc0
#define HWIO_REVID_LOT_ID_05_04_LOT_ID_05_1_0_SHFT                      0x6
#define HWIO_REVID_LOT_ID_05_04_LOT_ID_04_5_0_BMSK                     0x3f
#define HWIO_REVID_LOT_ID_05_04_LOT_ID_04_5_0_SHFT                      0x0

#define HWIO_REVID_LOT_ID_03_02_ADDR                             (REVID_BASE            + 0x000000fc)
#define HWIO_REVID_LOT_ID_03_02_OFFS                             0x000000fc
#define HWIO_REVID_LOT_ID_03_02_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_03_02_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_03_02_ADDR, HWIO_REVID_LOT_ID_03_02_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_03_02_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_03_02_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_03_02_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_03_02_ADDR, val, len)
#define HWIO_REVID_LOT_ID_03_02_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_03_02_ADDR, val)
#define HWIO_REVID_LOT_ID_03_02_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_03_02_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_03_02_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_03_02_ADDR, val, len)
#define HWIO_REVID_LOT_ID_03_02_LOT_ID_03_5_0_BMSK                     0xfc
#define HWIO_REVID_LOT_ID_03_02_LOT_ID_03_5_0_SHFT                      0x2
#define HWIO_REVID_LOT_ID_03_02_LOT_ID_02_5_4_BMSK                      0x3
#define HWIO_REVID_LOT_ID_03_02_LOT_ID_02_5_4_SHFT                      0x0

#define HWIO_REVID_LOT_ID_02_01_ADDR                             (REVID_BASE            + 0x000000fd)
#define HWIO_REVID_LOT_ID_02_01_OFFS                             0x000000fd
#define HWIO_REVID_LOT_ID_02_01_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_02_01_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_02_01_ADDR, HWIO_REVID_LOT_ID_02_01_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_02_01_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_02_01_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_02_01_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_02_01_ADDR, val, len)
#define HWIO_REVID_LOT_ID_02_01_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_02_01_ADDR, val)
#define HWIO_REVID_LOT_ID_02_01_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_02_01_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_02_01_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_02_01_ADDR, val, len)
#define HWIO_REVID_LOT_ID_02_01_LOT_ID_02_3_0_BMSK                     0xf0
#define HWIO_REVID_LOT_ID_02_01_LOT_ID_02_3_0_SHFT                      0x4
#define HWIO_REVID_LOT_ID_02_01_LOT_ID_01_5_2_BMSK                      0xf
#define HWIO_REVID_LOT_ID_02_01_LOT_ID_01_5_2_SHFT                      0x0

#define HWIO_REVID_LOT_ID_01_00_ADDR                             (REVID_BASE            + 0x000000fe)
#define HWIO_REVID_LOT_ID_01_00_OFFS                             0x000000fe
#define HWIO_REVID_LOT_ID_01_00_RMSK                                   0xff
#define HWIO_REVID_LOT_ID_01_00_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_01_00_ADDR, HWIO_REVID_LOT_ID_01_00_RMSK, 0, val)
#define HWIO_REVID_LOT_ID_01_00_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_01_00_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_01_00_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_01_00_ADDR, val, len)
#define HWIO_REVID_LOT_ID_01_00_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_LOT_ID_01_00_ADDR, val)
#define HWIO_REVID_LOT_ID_01_00_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_LOT_ID_01_00_ADDR, mask, shift, val)
#define HWIO_REVID_LOT_ID_01_00_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_LOT_ID_01_00_ADDR, val, len)
#define HWIO_REVID_LOT_ID_01_00_LOT_ID_01_1_0_BMSK                     0xc0
#define HWIO_REVID_LOT_ID_01_00_LOT_ID_01_1_0_SHFT                      0x6
#define HWIO_REVID_LOT_ID_01_00_LOT_ID_00_5_0_BMSK                     0x3f
#define HWIO_REVID_LOT_ID_01_00_LOT_ID_00_5_0_SHFT                      0x0

#define HWIO_REVID_MFG_ID_SPARE_ADDR                             (REVID_BASE            + 0x000000ff)
#define HWIO_REVID_MFG_ID_SPARE_OFFS                             0x000000ff
#define HWIO_REVID_MFG_ID_SPARE_RMSK                                   0xff
#define HWIO_REVID_MFG_ID_SPARE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_MFG_ID_SPARE_ADDR, HWIO_REVID_MFG_ID_SPARE_RMSK, 0, val)
#define HWIO_REVID_MFG_ID_SPARE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_REVID_MFG_ID_SPARE_ADDR, mask, shift, val)
#define HWIO_REVID_MFG_ID_SPARE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_REVID_MFG_ID_SPARE_ADDR, val, len)
#define HWIO_REVID_MFG_ID_SPARE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_REVID_MFG_ID_SPARE_ADDR, val)
#define HWIO_REVID_MFG_ID_SPARE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_REVID_MFG_ID_SPARE_ADDR, mask, shift, val)
#define HWIO_REVID_MFG_ID_SPARE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_REVID_MFG_ID_SPARE_ADDR, val, len)
#define HWIO_REVID_MFG_ID_SPARE_SPARE_BMSK                             0xff
#define HWIO_REVID_MFG_ID_SPARE_SPARE_SHFT                              0x0

/*----------------------------------------------------------------------------
 * PERIPHERAL: FAULT_AGG
 *--------------------------------------------------------------------------*/

#define FAULT_AGG_BASE                                                              0x0000f900

#define HWIO_FAULT_AGG_REVISION1_ADDR                                               (FAULT_AGG_BASE            + 0x00000000)
#define HWIO_FAULT_AGG_REVISION1_OFFS                                               0x00000000
#define HWIO_FAULT_AGG_REVISION1_RMSK                                                     0xff
#define HWIO_FAULT_AGG_REVISION1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION1_ADDR, HWIO_FAULT_AGG_REVISION1_RMSK, 0, val)
#define HWIO_FAULT_AGG_REVISION1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_REVISION1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_REVISION1_ADDR, val, len)
#define HWIO_FAULT_AGG_REVISION1_DIG_MINOR_BMSK                                           0xff
#define HWIO_FAULT_AGG_REVISION1_DIG_MINOR_SHFT                                            0x0

#define HWIO_FAULT_AGG_REVISION2_ADDR                                               (FAULT_AGG_BASE            + 0x00000001)
#define HWIO_FAULT_AGG_REVISION2_OFFS                                               0x00000001
#define HWIO_FAULT_AGG_REVISION2_RMSK                                                     0xff
#define HWIO_FAULT_AGG_REVISION2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION2_ADDR, HWIO_FAULT_AGG_REVISION2_RMSK, 0, val)
#define HWIO_FAULT_AGG_REVISION2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION2_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_REVISION2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_REVISION2_ADDR, val, len)
#define HWIO_FAULT_AGG_REVISION2_DIG_MAJOR_BMSK                                           0xff
#define HWIO_FAULT_AGG_REVISION2_DIG_MAJOR_SHFT                                            0x0

#define HWIO_FAULT_AGG_REVISION3_ADDR                                               (FAULT_AGG_BASE            + 0x00000002)
#define HWIO_FAULT_AGG_REVISION3_OFFS                                               0x00000002
#define HWIO_FAULT_AGG_REVISION3_RMSK                                                     0xff
#define HWIO_FAULT_AGG_REVISION3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION3_ADDR, HWIO_FAULT_AGG_REVISION3_RMSK, 0, val)
#define HWIO_FAULT_AGG_REVISION3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION3_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_REVISION3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_REVISION3_ADDR, val, len)
#define HWIO_FAULT_AGG_REVISION3_ANA_MINOR_BMSK                                           0xff
#define HWIO_FAULT_AGG_REVISION3_ANA_MINOR_SHFT                                            0x0

#define HWIO_FAULT_AGG_REVISION4_ADDR                                               (FAULT_AGG_BASE            + 0x00000003)
#define HWIO_FAULT_AGG_REVISION4_OFFS                                               0x00000003
#define HWIO_FAULT_AGG_REVISION4_RMSK                                                     0xff
#define HWIO_FAULT_AGG_REVISION4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION4_ADDR, HWIO_FAULT_AGG_REVISION4_RMSK, 0, val)
#define HWIO_FAULT_AGG_REVISION4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_REVISION4_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_REVISION4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_REVISION4_ADDR, val, len)
#define HWIO_FAULT_AGG_REVISION4_ANA_MAJOR_BMSK                                           0xff
#define HWIO_FAULT_AGG_REVISION4_ANA_MAJOR_SHFT                                            0x0

#define HWIO_FAULT_AGG_PERPH_TYPE_ADDR                                              (FAULT_AGG_BASE            + 0x00000004)
#define HWIO_FAULT_AGG_PERPH_TYPE_OFFS                                              0x00000004
#define HWIO_FAULT_AGG_PERPH_TYPE_RMSK                                                    0xff
#define HWIO_FAULT_AGG_PERPH_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_TYPE_ADDR, HWIO_FAULT_AGG_PERPH_TYPE_RMSK, 0, val)
#define HWIO_FAULT_AGG_PERPH_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_TYPE_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_TYPE_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_TYPE_TYPE_BMSK                                               0xff
#define HWIO_FAULT_AGG_PERPH_TYPE_TYPE_SHFT                                                0x0

#define HWIO_FAULT_AGG_PERPH_SUBTYPE_ADDR                                           (FAULT_AGG_BASE            + 0x00000005)
#define HWIO_FAULT_AGG_PERPH_SUBTYPE_OFFS                                           0x00000005
#define HWIO_FAULT_AGG_PERPH_SUBTYPE_RMSK                                                 0xff
#define HWIO_FAULT_AGG_PERPH_SUBTYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_SUBTYPE_ADDR, HWIO_FAULT_AGG_PERPH_SUBTYPE_RMSK, 0, val)
#define HWIO_FAULT_AGG_PERPH_SUBTYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_SUBTYPE_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_SUBTYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_SUBTYPE_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_SUBTYPE_SUBTYPE_BMSK                                         0xff
#define HWIO_FAULT_AGG_PERPH_SUBTYPE_SUBTYPE_SHFT                                          0x0

#define HWIO_FAULT_AGG_STATUS1_ADDR                                                 (FAULT_AGG_BASE            + 0x00000008)
#define HWIO_FAULT_AGG_STATUS1_OFFS                                                 0x00000008
#define HWIO_FAULT_AGG_STATUS1_RMSK                                                       0x7f
#define HWIO_FAULT_AGG_STATUS1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS1_ADDR, HWIO_FAULT_AGG_STATUS1_RMSK, 0, val)
#define HWIO_FAULT_AGG_STATUS1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_STATUS1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_STATUS1_ADDR, val, len)
#define HWIO_FAULT_AGG_STATUS1_GP_FAULT_PRE_FORCE_BMSK                                    0x40
#define HWIO_FAULT_AGG_STATUS1_GP_FAULT_PRE_FORCE_SHFT                                     0x6
#define HWIO_FAULT_AGG_STATUS1_PSAIL_ERR_N_PRE_FORCE_BMSK                                 0x20
#define HWIO_FAULT_AGG_STATUS1_PSAIL_ERR_N_PRE_FORCE_SHFT                                  0x5
#define HWIO_FAULT_AGG_STATUS1_EXTERNAL_PSAIL_ERR_N_BMSK                                  0x10
#define HWIO_FAULT_AGG_STATUS1_EXTERNAL_PSAIL_ERR_N_SHFT                                   0x4
#define HWIO_FAULT_AGG_STATUS1_LOCAL_PSAIL_ERR_N_BMSK                                      0x8
#define HWIO_FAULT_AGG_STATUS1_LOCAL_PSAIL_ERR_N_SHFT                                      0x3
#define HWIO_FAULT_AGG_STATUS1_GP_FAULT_TO_PON_BMSK                                        0x4
#define HWIO_FAULT_AGG_STATUS1_GP_FAULT_TO_PON_SHFT                                        0x2
#define HWIO_FAULT_AGG_STATUS1_LEVEL2_FAULT_BMSK                                           0x2
#define HWIO_FAULT_AGG_STATUS1_LEVEL2_FAULT_SHFT                                           0x1
#define HWIO_FAULT_AGG_STATUS1_LEVEL1_FAULT_BMSK                                           0x1
#define HWIO_FAULT_AGG_STATUS1_LEVEL1_FAULT_SHFT                                           0x0

#define HWIO_FAULT_AGG_STATUS2_ADDR                                                 (FAULT_AGG_BASE            + 0x00000009)
#define HWIO_FAULT_AGG_STATUS2_OFFS                                                 0x00000009
#define HWIO_FAULT_AGG_STATUS2_RMSK                                                       0xff
#define HWIO_FAULT_AGG_STATUS2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS2_ADDR, HWIO_FAULT_AGG_STATUS2_RMSK, 0, val)
#define HWIO_FAULT_AGG_STATUS2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS2_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_STATUS2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_STATUS2_ADDR, val, len)
#define HWIO_FAULT_AGG_STATUS2_FIRST_LEVEL2_PID_BMSK                                      0xff
#define HWIO_FAULT_AGG_STATUS2_FIRST_LEVEL2_PID_SHFT                                       0x0

#define HWIO_FAULT_AGG_STATUS3_ADDR                                                 (FAULT_AGG_BASE            + 0x0000000a)
#define HWIO_FAULT_AGG_STATUS3_OFFS                                                 0x0000000a
#define HWIO_FAULT_AGG_STATUS3_RMSK                                                        0x7
#define HWIO_FAULT_AGG_STATUS3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS3_ADDR, HWIO_FAULT_AGG_STATUS3_RMSK, 0, val)
#define HWIO_FAULT_AGG_STATUS3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS3_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_STATUS3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_STATUS3_ADDR, val, len)
#define HWIO_FAULT_AGG_STATUS3_FIRST_LEVEL2_M_IX_BMSK                                      0x7
#define HWIO_FAULT_AGG_STATUS3_FIRST_LEVEL2_M_IX_SHFT                                      0x0

#define HWIO_FAULT_AGG_STATUS4_ADDR                                                 (FAULT_AGG_BASE            + 0x0000000b)
#define HWIO_FAULT_AGG_STATUS4_OFFS                                                 0x0000000b
#define HWIO_FAULT_AGG_STATUS4_RMSK                                                        0xf
#define HWIO_FAULT_AGG_STATUS4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS4_ADDR, HWIO_FAULT_AGG_STATUS4_RMSK, 0, val)
#define HWIO_FAULT_AGG_STATUS4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS4_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_STATUS4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_STATUS4_ADDR, val, len)
#define HWIO_FAULT_AGG_STATUS4_LOGGER_OVERFLOW_BMSK                                        0x8
#define HWIO_FAULT_AGG_STATUS4_LOGGER_OVERFLOW_SHFT                                        0x3
#define HWIO_FAULT_AGG_STATUS4_LOGGER_FULL_BMSK                                            0x4
#define HWIO_FAULT_AGG_STATUS4_LOGGER_FULL_SHFT                                            0x2
#define HWIO_FAULT_AGG_STATUS4_LOGGER_NEARLY_FULL_BMSK                                     0x2
#define HWIO_FAULT_AGG_STATUS4_LOGGER_NEARLY_FULL_SHFT                                     0x1
#define HWIO_FAULT_AGG_STATUS4_LOGGER_EMPTY_BMSK                                           0x1
#define HWIO_FAULT_AGG_STATUS4_LOGGER_EMPTY_SHFT                                           0x0

#define HWIO_FAULT_AGG_STATUS5_ADDR                                                 (FAULT_AGG_BASE            + 0x0000000c)
#define HWIO_FAULT_AGG_STATUS5_OFFS                                                 0x0000000c
#define HWIO_FAULT_AGG_STATUS5_RMSK                                                       0xff
#define HWIO_FAULT_AGG_STATUS5_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS5_ADDR, HWIO_FAULT_AGG_STATUS5_RMSK, 0, val)
#define HWIO_FAULT_AGG_STATUS5_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_STATUS5_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_STATUS5_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_STATUS5_ADDR, val, len)
#define HWIO_FAULT_AGG_STATUS5_NUM_LOGGING_ENTRIES_BMSK                                   0xff
#define HWIO_FAULT_AGG_STATUS5_NUM_LOGGING_ENTRIES_SHFT                                    0x0

#define HWIO_FAULT_AGG_FIFO_SIZE_ADDR                                               (FAULT_AGG_BASE            + 0x0000000d)
#define HWIO_FAULT_AGG_FIFO_SIZE_OFFS                                               0x0000000d
#define HWIO_FAULT_AGG_FIFO_SIZE_RMSK                                                      0x3
#define HWIO_FAULT_AGG_FIFO_SIZE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FIFO_SIZE_ADDR, HWIO_FAULT_AGG_FIFO_SIZE_RMSK, 0, val)
#define HWIO_FAULT_AGG_FIFO_SIZE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FIFO_SIZE_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FIFO_SIZE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FIFO_SIZE_ADDR, val, len)
#define HWIO_FAULT_AGG_FIFO_SIZE_FIFO_SIZE_BMSK                                            0x3
#define HWIO_FAULT_AGG_FIFO_SIZE_FIFO_SIZE_SHFT                                            0x0

#define HWIO_FAULT_AGG_BIST_RESULT_ADDR                                             (FAULT_AGG_BASE            + 0x0000000e)
#define HWIO_FAULT_AGG_BIST_RESULT_OFFS                                             0x0000000e
#define HWIO_FAULT_AGG_BIST_RESULT_RMSK                                                   0xff
#define HWIO_FAULT_AGG_BIST_RESULT_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_BIST_RESULT_ADDR, HWIO_FAULT_AGG_BIST_RESULT_RMSK, 0, val)
#define HWIO_FAULT_AGG_BIST_RESULT_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_BIST_RESULT_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_BIST_RESULT_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_BIST_RESULT_ADDR, val, len)
#define HWIO_FAULT_AGG_BIST_RESULT_MM_MBIST_RESULT_BMSK                                   0xc0
#define HWIO_FAULT_AGG_BIST_RESULT_MM_MBIST_RESULT_SHFT                                    0x6
#define HWIO_FAULT_AGG_BIST_RESULT_MM_LBIST_RESULT_BMSK                                   0x30
#define HWIO_FAULT_AGG_BIST_RESULT_MM_LBIST_RESULT_SHFT                                    0x4
#define HWIO_FAULT_AGG_BIST_RESULT_PSAIL_MBIST_RESULT_BMSK                                 0xc
#define HWIO_FAULT_AGG_BIST_RESULT_PSAIL_MBIST_RESULT_SHFT                                 0x2
#define HWIO_FAULT_AGG_BIST_RESULT_PSAIL_LBIST_RESULT_BMSK                                 0x3
#define HWIO_FAULT_AGG_BIST_RESULT_PSAIL_LBIST_RESULT_SHFT                                 0x0

#define HWIO_FAULT_AGG_INT_RT_STS_ADDR                                              (FAULT_AGG_BASE            + 0x00000010)
#define HWIO_FAULT_AGG_INT_RT_STS_OFFS                                              0x00000010
#define HWIO_FAULT_AGG_INT_RT_STS_RMSK                                                     0xf
#define HWIO_FAULT_AGG_INT_RT_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_RT_STS_ADDR, HWIO_FAULT_AGG_INT_RT_STS_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_RT_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_RT_STS_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_RT_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_RT_STS_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_RT_STS_LEVEL2_FAULT_RT_STS_BMSK                                 0x8
#define HWIO_FAULT_AGG_INT_RT_STS_LEVEL2_FAULT_RT_STS_SHFT                                 0x3
#define HWIO_FAULT_AGG_INT_RT_STS_LOGGER_OVERFLOW_RT_STS_BMSK                              0x4
#define HWIO_FAULT_AGG_INT_RT_STS_LOGGER_OVERFLOW_RT_STS_SHFT                              0x2
#define HWIO_FAULT_AGG_INT_RT_STS_LOGGER_NEARLY_FULL_RT_STS_BMSK                           0x2
#define HWIO_FAULT_AGG_INT_RT_STS_LOGGER_NEARLY_FULL_RT_STS_SHFT                           0x1
#define HWIO_FAULT_AGG_INT_RT_STS_LOGGER_UNDERFLOW_RT_STS_BMSK                             0x1
#define HWIO_FAULT_AGG_INT_RT_STS_LOGGER_UNDERFLOW_RT_STS_SHFT                             0x0

#define HWIO_FAULT_AGG_INT_SET_TYPE_ADDR                                            (FAULT_AGG_BASE            + 0x00000011)
#define HWIO_FAULT_AGG_INT_SET_TYPE_OFFS                                            0x00000011
#define HWIO_FAULT_AGG_INT_SET_TYPE_RMSK                                                   0xf
#define HWIO_FAULT_AGG_INT_SET_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_SET_TYPE_ADDR, HWIO_FAULT_AGG_INT_SET_TYPE_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_SET_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_SET_TYPE_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_SET_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_SET_TYPE_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_SET_TYPE_LEVEL2_FAULT_TYPE_BMSK                                 0x8
#define HWIO_FAULT_AGG_INT_SET_TYPE_LEVEL2_FAULT_TYPE_SHFT                                 0x3
#define HWIO_FAULT_AGG_INT_SET_TYPE_LOGGER_OVERFLOW_TYPE_BMSK                              0x4
#define HWIO_FAULT_AGG_INT_SET_TYPE_LOGGER_OVERFLOW_TYPE_SHFT                              0x2
#define HWIO_FAULT_AGG_INT_SET_TYPE_LOGGER_NEARLY_FULL_TYPE_BMSK                           0x2
#define HWIO_FAULT_AGG_INT_SET_TYPE_LOGGER_NEARLY_FULL_TYPE_SHFT                           0x1
#define HWIO_FAULT_AGG_INT_SET_TYPE_LOGGER_UNDERFLOW_TYPE_BMSK                             0x1
#define HWIO_FAULT_AGG_INT_SET_TYPE_LOGGER_UNDERFLOW_TYPE_SHFT                             0x0

#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_ADDR                                       (FAULT_AGG_BASE            + 0x00000012)
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_OFFS                                       0x00000012
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_RMSK                                              0xf
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_POLARITY_HIGH_ADDR, HWIO_FAULT_AGG_INT_POLARITY_HIGH_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_POLARITY_HIGH_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_POLARITY_HIGH_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LEVEL2_FAULT_HIGH_BMSK                            0x8
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LEVEL2_FAULT_HIGH_SHFT                            0x3
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LOGGER_OVERFLOW_HIGH_BMSK                         0x4
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LOGGER_OVERFLOW_HIGH_SHFT                         0x2
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LOGGER_NEARLY_FULL_HIGH_BMSK                      0x2
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LOGGER_NEARLY_FULL_HIGH_SHFT                      0x1
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LOGGER_UNDERFLOW_HIGH_BMSK                        0x1
#define HWIO_FAULT_AGG_INT_POLARITY_HIGH_LOGGER_UNDERFLOW_HIGH_SHFT                        0x0

#define HWIO_FAULT_AGG_INT_POLARITY_LOW_ADDR                                        (FAULT_AGG_BASE            + 0x00000013)
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_OFFS                                        0x00000013
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_RMSK                                               0xf
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_POLARITY_LOW_ADDR, HWIO_FAULT_AGG_INT_POLARITY_LOW_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_POLARITY_LOW_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_POLARITY_LOW_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LEVEL2_FAULT_LOW_BMSK                              0x8
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LEVEL2_FAULT_LOW_SHFT                              0x3
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LOGGER_OVERFLOW_LOW_BMSK                           0x4
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LOGGER_OVERFLOW_LOW_SHFT                           0x2
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LOGGER_NEARLY_FULL_LOW_BMSK                        0x2
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LOGGER_NEARLY_FULL_LOW_SHFT                        0x1
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LOGGER_UNDERFLOW_LOW_BMSK                          0x1
#define HWIO_FAULT_AGG_INT_POLARITY_LOW_LOGGER_UNDERFLOW_LOW_SHFT                          0x0

#define HWIO_FAULT_AGG_INT_LATCHED_CLR_ADDR                                         (FAULT_AGG_BASE            + 0x00000014)
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_OFFS                                         0x00000014
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_RMSK                                                0xf
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_LATCHED_CLR_ADDR, val)
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_INT_LATCHED_CLR_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LEVEL2_FAULT_LATCHED_CLR_BMSK                       0x8
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LEVEL2_FAULT_LATCHED_CLR_SHFT                       0x3
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LOGGER_OVERFLOW_LATCHED_CLR_BMSK                    0x4
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LOGGER_OVERFLOW_LATCHED_CLR_SHFT                    0x2
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LOGGER_NEARLY_FULL_LATCHED_CLR_BMSK                 0x2
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LOGGER_NEARLY_FULL_LATCHED_CLR_SHFT                 0x1
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LOGGER_UNDERFLOW_LATCHED_CLR_BMSK                   0x1
#define HWIO_FAULT_AGG_INT_LATCHED_CLR_LOGGER_UNDERFLOW_LATCHED_CLR_SHFT                   0x0

#define HWIO_FAULT_AGG_INT_EN_SET_ADDR                                              (FAULT_AGG_BASE            + 0x00000015)
#define HWIO_FAULT_AGG_INT_EN_SET_OFFS                                              0x00000015
#define HWIO_FAULT_AGG_INT_EN_SET_RMSK                                                     0xf
#define HWIO_FAULT_AGG_INT_EN_SET_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_SET_ADDR, HWIO_FAULT_AGG_INT_EN_SET_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_EN_SET_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_SET_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_EN_SET_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_SET_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_EN_SET_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_SET_ADDR, val)
#define HWIO_FAULT_AGG_INT_EN_SET_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_SET_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_EN_SET_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_SET_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_EN_SET_LEVEL2_FAULT_EN_BMSK                                     0x8
#define HWIO_FAULT_AGG_INT_EN_SET_LEVEL2_FAULT_EN_SHFT                                     0x3
#define HWIO_FAULT_AGG_INT_EN_SET_LOGGER_OVERFLOW_EN_BMSK                                  0x4
#define HWIO_FAULT_AGG_INT_EN_SET_LOGGER_OVERFLOW_EN_SHFT                                  0x2
#define HWIO_FAULT_AGG_INT_EN_SET_LOGGER_NEARLY_FULL_EN_BMSK                               0x2
#define HWIO_FAULT_AGG_INT_EN_SET_LOGGER_NEARLY_FULL_EN_SHFT                               0x1
#define HWIO_FAULT_AGG_INT_EN_SET_LOGGER_UNDERFLOW_EN_BMSK                                 0x1
#define HWIO_FAULT_AGG_INT_EN_SET_LOGGER_UNDERFLOW_EN_SHFT                                 0x0

#define HWIO_FAULT_AGG_INT_EN_CLR_ADDR                                              (FAULT_AGG_BASE            + 0x00000016)
#define HWIO_FAULT_AGG_INT_EN_CLR_OFFS                                              0x00000016
#define HWIO_FAULT_AGG_INT_EN_CLR_RMSK                                                     0xf
#define HWIO_FAULT_AGG_INT_EN_CLR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_CLR_ADDR, HWIO_FAULT_AGG_INT_EN_CLR_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_EN_CLR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_CLR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_EN_CLR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_CLR_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_EN_CLR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_CLR_ADDR, val)
#define HWIO_FAULT_AGG_INT_EN_CLR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_CLR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_EN_CLR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_INT_EN_CLR_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_EN_CLR_LEVEL2_FAULT_EN_BMSK                                     0x8
#define HWIO_FAULT_AGG_INT_EN_CLR_LEVEL2_FAULT_EN_SHFT                                     0x3
#define HWIO_FAULT_AGG_INT_EN_CLR_LOGGER_OVERFLOW_EN_BMSK                                  0x4
#define HWIO_FAULT_AGG_INT_EN_CLR_LOGGER_OVERFLOW_EN_SHFT                                  0x2
#define HWIO_FAULT_AGG_INT_EN_CLR_LOGGER_NEARLY_FULL_EN_BMSK                               0x2
#define HWIO_FAULT_AGG_INT_EN_CLR_LOGGER_NEARLY_FULL_EN_SHFT                               0x1
#define HWIO_FAULT_AGG_INT_EN_CLR_LOGGER_UNDERFLOW_EN_BMSK                                 0x1
#define HWIO_FAULT_AGG_INT_EN_CLR_LOGGER_UNDERFLOW_EN_SHFT                                 0x0

#define HWIO_FAULT_AGG_INT_LATCHED_STS_ADDR                                         (FAULT_AGG_BASE            + 0x00000018)
#define HWIO_FAULT_AGG_INT_LATCHED_STS_OFFS                                         0x00000018
#define HWIO_FAULT_AGG_INT_LATCHED_STS_RMSK                                                0xf
#define HWIO_FAULT_AGG_INT_LATCHED_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_LATCHED_STS_ADDR, HWIO_FAULT_AGG_INT_LATCHED_STS_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_LATCHED_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_LATCHED_STS_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_LATCHED_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_LATCHED_STS_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LEVEL2_FAULT_LATCHED_STS_BMSK                       0x8
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LEVEL2_FAULT_LATCHED_STS_SHFT                       0x3
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LOGGER_OVERFLOW_LATCHED_STS_BMSK                    0x4
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LOGGER_OVERFLOW_LATCHED_STS_SHFT                    0x2
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LOGGER_NEARLY_FULL_LATCHED_STS_BMSK                 0x2
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LOGGER_NEARLY_FULL_LATCHED_STS_SHFT                 0x1
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LOGGER_UNDERFLOW_LATCHED_STS_BMSK                   0x1
#define HWIO_FAULT_AGG_INT_LATCHED_STS_LOGGER_UNDERFLOW_LATCHED_STS_SHFT                   0x0

#define HWIO_FAULT_AGG_INT_PENDING_STS_ADDR                                         (FAULT_AGG_BASE            + 0x00000019)
#define HWIO_FAULT_AGG_INT_PENDING_STS_OFFS                                         0x00000019
#define HWIO_FAULT_AGG_INT_PENDING_STS_RMSK                                                0xf
#define HWIO_FAULT_AGG_INT_PENDING_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_PENDING_STS_ADDR, HWIO_FAULT_AGG_INT_PENDING_STS_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_PENDING_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_PENDING_STS_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_PENDING_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_PENDING_STS_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_PENDING_STS_LEVEL2_FAULT_PENDING_STS_BMSK                       0x8
#define HWIO_FAULT_AGG_INT_PENDING_STS_LEVEL2_FAULT_PENDING_STS_SHFT                       0x3
#define HWIO_FAULT_AGG_INT_PENDING_STS_LOGGER_OVERFLOW_PENDING_STS_BMSK                    0x4
#define HWIO_FAULT_AGG_INT_PENDING_STS_LOGGER_OVERFLOW_PENDING_STS_SHFT                    0x2
#define HWIO_FAULT_AGG_INT_PENDING_STS_LOGGER_NEARLY_FULL_PENDING_STS_BMSK                 0x2
#define HWIO_FAULT_AGG_INT_PENDING_STS_LOGGER_NEARLY_FULL_PENDING_STS_SHFT                 0x1
#define HWIO_FAULT_AGG_INT_PENDING_STS_LOGGER_UNDERFLOW_PENDING_STS_BMSK                   0x1
#define HWIO_FAULT_AGG_INT_PENDING_STS_LOGGER_UNDERFLOW_PENDING_STS_SHFT                   0x0

#define HWIO_FAULT_AGG_INT_MID_SEL_ADDR                                             (FAULT_AGG_BASE            + 0x0000001a)
#define HWIO_FAULT_AGG_INT_MID_SEL_OFFS                                             0x0000001a
#define HWIO_FAULT_AGG_INT_MID_SEL_RMSK                                                    0x3
#define HWIO_FAULT_AGG_INT_MID_SEL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_MID_SEL_ADDR, HWIO_FAULT_AGG_INT_MID_SEL_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_MID_SEL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_MID_SEL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_MID_SEL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_MID_SEL_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_MID_SEL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_MID_SEL_ADDR, val)
#define HWIO_FAULT_AGG_INT_MID_SEL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_MID_SEL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_MID_SEL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_INT_MID_SEL_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_MID_SEL_INT_MID_SEL_BMSK                                        0x3
#define HWIO_FAULT_AGG_INT_MID_SEL_INT_MID_SEL_SHFT                                        0x0

#define HWIO_FAULT_AGG_INT_PRIORITY_ADDR                                            (FAULT_AGG_BASE            + 0x0000001b)
#define HWIO_FAULT_AGG_INT_PRIORITY_OFFS                                            0x0000001b
#define HWIO_FAULT_AGG_INT_PRIORITY_RMSK                                                   0x1
#define HWIO_FAULT_AGG_INT_PRIORITY_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_PRIORITY_ADDR, HWIO_FAULT_AGG_INT_PRIORITY_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_PRIORITY_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_PRIORITY_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_PRIORITY_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_PRIORITY_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_PRIORITY_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_PRIORITY_ADDR, val)
#define HWIO_FAULT_AGG_INT_PRIORITY_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_PRIORITY_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_PRIORITY_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_INT_PRIORITY_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_PRIORITY_INT_PRIORITY_BMSK                                      0x1
#define HWIO_FAULT_AGG_INT_PRIORITY_INT_PRIORITY_SHFT                                      0x0

#define HWIO_FAULT_AGG_FAULT_EN_ADDR                                                (FAULT_AGG_BASE            + 0x00000043)
#define HWIO_FAULT_AGG_FAULT_EN_OFFS                                                0x00000043
#define HWIO_FAULT_AGG_FAULT_EN_RMSK                                                      0x80
#define HWIO_FAULT_AGG_FAULT_EN_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FAULT_EN_ADDR, HWIO_FAULT_AGG_FAULT_EN_RMSK, 0, val)
#define HWIO_FAULT_AGG_FAULT_EN_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FAULT_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FAULT_EN_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FAULT_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_FAULT_EN_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FAULT_EN_ADDR, val)
#define HWIO_FAULT_AGG_FAULT_EN_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FAULT_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FAULT_EN_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_FAULT_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_FAULT_EN_LEVEL2_EN_BMSK                                            0x80
#define HWIO_FAULT_AGG_FAULT_EN_LEVEL2_EN_SHFT                                             0x7

#define HWIO_FAULT_AGG_LOGGER_EN_ADDR                                               (FAULT_AGG_BASE            + 0x00000046)
#define HWIO_FAULT_AGG_LOGGER_EN_OFFS                                               0x00000046
#define HWIO_FAULT_AGG_LOGGER_EN_RMSK                                                     0x80
#define HWIO_FAULT_AGG_LOGGER_EN_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_EN_ADDR, HWIO_FAULT_AGG_LOGGER_EN_RMSK, 0, val)
#define HWIO_FAULT_AGG_LOGGER_EN_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOGGER_EN_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_LOGGER_EN_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_EN_ADDR, val)
#define HWIO_FAULT_AGG_LOGGER_EN_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOGGER_EN_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_LOGGER_EN_LOGGER_EN_BMSK                                           0x80
#define HWIO_FAULT_AGG_LOGGER_EN_LOGGER_EN_SHFT                                            0x7

#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_ADDR                                   (FAULT_AGG_BASE            + 0x00000047)
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_OFFS                                   0x00000047
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_RMSK                                          0x1
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_ADDR, HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_RMSK, 0, val)
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_ADDR, val, len)
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_ADDR, val)
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_ADDR, val, len)
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_LOGGER_TIMESTAMP_SYNC_BMSK                    0x1
#define HWIO_FAULT_AGG_LOGGER_TIMESTAMP_SYNC_LOGGER_TIMESTAMP_SYNC_SHFT                    0x0

#define HWIO_FAULT_AGG_LOG_RAM_ADDR_ADDR                                            (FAULT_AGG_BASE            + 0x00000052)
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_OFFS                                            0x00000052
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_RMSK                                                  0xff
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOG_RAM_ADDR_ADDR, HWIO_FAULT_AGG_LOG_RAM_ADDR_RMSK, 0, val)
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOG_RAM_ADDR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOG_RAM_ADDR_ADDR, val, len)
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOG_RAM_ADDR_ADDR, val)
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOG_RAM_ADDR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_LOG_RAM_ADDR_ADDR, val, len)
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_LOG_RAM_ADDR_BMSK                                     0xff
#define HWIO_FAULT_AGG_LOG_RAM_ADDR_LOG_RAM_ADDR_SHFT                                      0x0

#define HWIO_FAULT_AGG_MEM_INTF_ADDR_ADDR                                           (FAULT_AGG_BASE            + 0x00000054)
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_OFFS                                           0x00000054
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_RMSK                                                 0xff
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_ADDR_ADDR, HWIO_FAULT_AGG_MEM_INTF_ADDR_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_ADDR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_ADDR_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_ADDR_ADDR, val)
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_ADDR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_ADDR_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_MEM_INTF_ADDR_BMSK                                   0xff
#define HWIO_FAULT_AGG_MEM_INTF_ADDR_MEM_INTF_ADDR_SHFT                                    0x0

#define HWIO_FAULT_AGG_CAPTURE_INC_ADDR                                             (FAULT_AGG_BASE            + 0x00000056)
#define HWIO_FAULT_AGG_CAPTURE_INC_OFFS                                             0x00000056
#define HWIO_FAULT_AGG_CAPTURE_INC_RMSK                                                    0x1
#define HWIO_FAULT_AGG_CAPTURE_INC_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_CAPTURE_INC_ADDR, HWIO_FAULT_AGG_CAPTURE_INC_RMSK, 0, val)
#define HWIO_FAULT_AGG_CAPTURE_INC_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_CAPTURE_INC_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_CAPTURE_INC_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_CAPTURE_INC_ADDR, val, len)
#define HWIO_FAULT_AGG_CAPTURE_INC_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_CAPTURE_INC_ADDR, val)
#define HWIO_FAULT_AGG_CAPTURE_INC_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_CAPTURE_INC_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_CAPTURE_INC_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_CAPTURE_INC_ADDR, val, len)
#define HWIO_FAULT_AGG_CAPTURE_INC_CAPTURE_INC_BMSK                                        0x1
#define HWIO_FAULT_AGG_CAPTURE_INC_CAPTURE_INC_SHFT                                        0x0

#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_ADDR                                       (FAULT_AGG_BASE            + 0x00000058)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_OFFS                                       0x00000058
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_ADDR, HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_TIMESTAMP_BYTE0_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA0_TIMESTAMP_BYTE0_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_ADDR                                       (FAULT_AGG_BASE            + 0x00000059)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_OFFS                                       0x00000059
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_ADDR, HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_TIMESTAMP_BYTE1_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA1_TIMESTAMP_BYTE1_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_ADDR                                       (FAULT_AGG_BASE            + 0x0000005a)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_OFFS                                       0x0000005a
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_ADDR, HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_TIMESTAMP_BYTE2_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA2_TIMESTAMP_BYTE2_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_ADDR                                       (FAULT_AGG_BASE            + 0x0000005b)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_OFFS                                       0x0000005b
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_ADDR, HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_TIMESTAMP_BYTE3_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA3_TIMESTAMP_BYTE3_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_ADDR                                       (FAULT_AGG_BASE            + 0x0000005c)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_OFFS                                       0x0000005c
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_ADDR, HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_MONITOR_PID_BMSK                                 0xff
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA4_MONITOR_PID_SHFT                                  0x0

#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_ADDR                                       (FAULT_AGG_BASE            + 0x0000005d)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_OFFS                                       0x0000005d
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_RMSK                                             0x7f
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_ADDR, HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_MONITOR_INDEX_BMSK                               0x70
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_MONITOR_INDEX_SHFT                                0x4
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_NEW_ERROR_BMSK                                    0xc
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_NEW_ERROR_SHFT                                    0x2
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_OLD_ERROR_BMSK                                    0x3
#define HWIO_FAULT_AGG_MEM_INTF_RD_DATA5_OLD_ERROR_SHFT                                    0x0

#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_ADDR                                 (FAULT_AGG_BASE            + 0x00000060)
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_OFFS                                 0x00000060
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_RMSK                                        0x1
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_ADDR, HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_RMSK, 0, val)
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_ADDR, val, len)
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_ADDR, val)
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_ADDR, val, len)
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_LATCH_CLEAR_BMSK                            0x1
#define HWIO_FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR_LATCH_CLEAR_SHFT                            0x0

#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_ADDR                             (FAULT_AGG_BASE            + 0x00000061)
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_OFFS                             0x00000061
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_RMSK                                    0x1
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_ADDR, HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_RMSK, 0, val)
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_ADDR, val, len)
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_ADDR, val)
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_ADDR, val, len)
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_LATCH_CLEAR_BMSK                        0x1
#define HWIO_FAULT_AGG_GP_FAULT_TO_PON_LATCH_CLEAR_LATCH_CLEAR_SHFT                        0x0

#define HWIO_FAULT_AGG_OVERFLOW_EN_ADDR                                             (FAULT_AGG_BASE            + 0x00000062)
#define HWIO_FAULT_AGG_OVERFLOW_EN_OFFS                                             0x00000062
#define HWIO_FAULT_AGG_OVERFLOW_EN_RMSK                                                   0x80
#define HWIO_FAULT_AGG_OVERFLOW_EN_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_OVERFLOW_EN_ADDR, HWIO_FAULT_AGG_OVERFLOW_EN_RMSK, 0, val)
#define HWIO_FAULT_AGG_OVERFLOW_EN_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_OVERFLOW_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_OVERFLOW_EN_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_OVERFLOW_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_OVERFLOW_EN_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_OVERFLOW_EN_ADDR, val)
#define HWIO_FAULT_AGG_OVERFLOW_EN_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_OVERFLOW_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_OVERFLOW_EN_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_OVERFLOW_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_OVERFLOW_EN_OVERFLOW_EN_BMSK                                       0x80
#define HWIO_FAULT_AGG_OVERFLOW_EN_OVERFLOW_EN_SHFT                                        0x7

#define HWIO_FAULT_AGG_PULL_CTL_ADDR                                                (FAULT_AGG_BASE            + 0x00000063)
#define HWIO_FAULT_AGG_PULL_CTL_OFFS                                                0x00000063
#define HWIO_FAULT_AGG_PULL_CTL_RMSK                                                      0x81
#define HWIO_FAULT_AGG_PULL_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PULL_CTL_ADDR, HWIO_FAULT_AGG_PULL_CTL_RMSK, 0, val)
#define HWIO_FAULT_AGG_PULL_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PULL_CTL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PULL_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PULL_CTL_ADDR, val, len)
#define HWIO_FAULT_AGG_PULL_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PULL_CTL_ADDR, val)
#define HWIO_FAULT_AGG_PULL_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PULL_CTL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PULL_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_PULL_CTL_ADDR, val, len)
#define HWIO_FAULT_AGG_PULL_CTL_PSAIL_ERR_N_PU_EN_BMSK                                    0x80
#define HWIO_FAULT_AGG_PULL_CTL_PSAIL_ERR_N_PU_EN_SHFT                                     0x7
#define HWIO_FAULT_AGG_PULL_CTL_PSAIL_ERR_N_PU_SEL_BMSK                                    0x1
#define HWIO_FAULT_AGG_PULL_CTL_PSAIL_ERR_N_PU_SEL_SHFT                                    0x0

#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_ADDR                                     (FAULT_AGG_BASE            + 0x000000c8)
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_OFFS                                     0x000000c8
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_RMSK                                            0x7
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_ADDR, HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_RMSK, 0, val)
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_ADDR, val, len)
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_ADDR, val)
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_ADDR, val, len)
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_SW_CLK_REQ_BMSK                                 0x4
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_SW_CLK_REQ_SHFT                                 0x2
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_SW_CLK_REQ_MODE_BMSK                            0x2
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_SW_CLK_REQ_MODE_SHFT                            0x1
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_BYPASS_BMSK                                     0x1
#define HWIO_FAULT_AGG_PBUS_WRITE_SYNC_CTL_BYPASS_SHFT                                     0x0

#define HWIO_FAULT_AGG_LOCKBIT_D1_ADDR                                              (FAULT_AGG_BASE            + 0x000000d1)
#define HWIO_FAULT_AGG_LOCKBIT_D1_OFFS                                              0x000000d1
#define HWIO_FAULT_AGG_LOCKBIT_D1_RMSK                                                     0x3
#define HWIO_FAULT_AGG_LOCKBIT_D1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOCKBIT_D1_ADDR, HWIO_FAULT_AGG_LOCKBIT_D1_RMSK, 0, val)
#define HWIO_FAULT_AGG_LOCKBIT_D1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOCKBIT_D1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOCKBIT_D1_ADDR, val, len)
#define HWIO_FAULT_AGG_LOCKBIT_D1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_LOCKBIT_D1_ADDR, val)
#define HWIO_FAULT_AGG_LOCKBIT_D1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_LOCKBIT_D1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_LOCKBIT_D1_ADDR, val, len)
#define HWIO_FAULT_AGG_LOCKBIT_D1_LOCKBIT_D1_BMSK                                          0x3
#define HWIO_FAULT_AGG_LOCKBIT_D1_LOCKBIT_D1_SHFT                                          0x0

#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_ADDR                                    (FAULT_AGG_BASE            + 0x000000d4)
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_OFFS                                    0x000000d4
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_RMSK                                           0x1
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_ADDR, HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_RMSK, 0, val)
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_ADDR, val)
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_BMSK                                0x1
#define HWIO_FAULT_AGG_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_SHFT                                0x0

#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_ADDR                                        (FAULT_AGG_BASE            + 0x000000d8)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_OFFS                                        0x000000d8
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_RMSK                                               0x1
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL1_ADDR, HWIO_FAULT_AGG_PERPH_RESET_CTL1_RMSK, 0, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL1_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL1_ADDR, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL1_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_ENABLE_PRESET_BMSK                                 0x1
#define HWIO_FAULT_AGG_PERPH_RESET_CTL1_ENABLE_PRESET_SHFT                                 0x0

#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_ADDR                                        (FAULT_AGG_BASE            + 0x000000da)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_OFFS                                        0x000000da
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_RMSK                                               0x5
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL3_ADDR, HWIO_FAULT_AGG_PERPH_RESET_CTL3_RMSK, 0, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL3_ADDR, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_FOLLOW_WARM_RB_BMSK                                0x4
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_FOLLOW_WARM_RB_SHFT                                0x2
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_BMSK                           0x1
#define HWIO_FAULT_AGG_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_SHFT                           0x0

#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_ADDR                                        (FAULT_AGG_BASE            + 0x000000db)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_OFFS                                        0x000000db
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_RMSK                                               0x1
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL4_ADDR, HWIO_FAULT_AGG_PERPH_RESET_CTL4_RMSK, 0, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL4_ADDR, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_BMSK                              0x1
#define HWIO_FAULT_AGG_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_SHFT                              0x0

#define HWIO_FAULT_AGG_INT_TEST1_ADDR                                               (FAULT_AGG_BASE            + 0x000000e0)
#define HWIO_FAULT_AGG_INT_TEST1_OFFS                                               0x000000e0
#define HWIO_FAULT_AGG_INT_TEST1_RMSK                                                     0x80
#define HWIO_FAULT_AGG_INT_TEST1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST1_ADDR, HWIO_FAULT_AGG_INT_TEST1_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_TEST1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_TEST1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST1_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_TEST1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST1_ADDR, val)
#define HWIO_FAULT_AGG_INT_TEST1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_TEST1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST1_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_TEST1_INT_TEST_MODE_EN_BMSK                                    0x80
#define HWIO_FAULT_AGG_INT_TEST1_INT_TEST_MODE_EN_SHFT                                     0x7

#define HWIO_FAULT_AGG_INT_TEST_VAL_ADDR                                            (FAULT_AGG_BASE            + 0x000000e1)
#define HWIO_FAULT_AGG_INT_TEST_VAL_OFFS                                            0x000000e1
#define HWIO_FAULT_AGG_INT_TEST_VAL_RMSK                                                   0xf
#define HWIO_FAULT_AGG_INT_TEST_VAL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST_VAL_ADDR, HWIO_FAULT_AGG_INT_TEST_VAL_RMSK, 0, val)
#define HWIO_FAULT_AGG_INT_TEST_VAL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_TEST_VAL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST_VAL_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_TEST_VAL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST_VAL_ADDR, val)
#define HWIO_FAULT_AGG_INT_TEST_VAL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_INT_TEST_VAL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_INT_TEST_VAL_ADDR, val, len)
#define HWIO_FAULT_AGG_INT_TEST_VAL_LEVEL2_FAULT_INT_TEST_VAL_BMSK                         0x8
#define HWIO_FAULT_AGG_INT_TEST_VAL_LEVEL2_FAULT_INT_TEST_VAL_SHFT                         0x3
#define HWIO_FAULT_AGG_INT_TEST_VAL_LOGGER_OVERFLOW_INT_TEST_VAL_BMSK                      0x4
#define HWIO_FAULT_AGG_INT_TEST_VAL_LOGGER_OVERFLOW_INT_TEST_VAL_SHFT                      0x2
#define HWIO_FAULT_AGG_INT_TEST_VAL_LOGGER_NEARLY_FULL_INT_TEST_VAL_BMSK                   0x2
#define HWIO_FAULT_AGG_INT_TEST_VAL_LOGGER_NEARLY_FULL_INT_TEST_VAL_SHFT                   0x1
#define HWIO_FAULT_AGG_INT_TEST_VAL_LOGGER_UNDERFLOW_INT_TEST_VAL_BMSK                     0x1
#define HWIO_FAULT_AGG_INT_TEST_VAL_LOGGER_UNDERFLOW_INT_TEST_VAL_SHFT                     0x0

#define HWIO_FAULT_AGG_TEST1_ADDR                                                   (FAULT_AGG_BASE            + 0x000000e2)
#define HWIO_FAULT_AGG_TEST1_OFFS                                                   0x000000e2
#define HWIO_FAULT_AGG_TEST1_RMSK                                                         0xff
#define HWIO_FAULT_AGG_TEST1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_TEST1_ADDR, HWIO_FAULT_AGG_TEST1_RMSK, 0, val)
#define HWIO_FAULT_AGG_TEST1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_TEST1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_TEST1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_TEST1_ADDR, val, len)
#define HWIO_FAULT_AGG_TEST1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_TEST1_ADDR, val)
#define HWIO_FAULT_AGG_TEST1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_TEST1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_TEST1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_TEST1_ADDR, val, len)
#define HWIO_FAULT_AGG_TEST1_DTEST_EN_BMSK                                                0xf0
#define HWIO_FAULT_AGG_TEST1_DTEST_EN_SHFT                                                 0x4
#define HWIO_FAULT_AGG_TEST1_DTEST_BMSK                                                    0xf
#define HWIO_FAULT_AGG_TEST1_DTEST_SHFT                                                    0x0

#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_ADDR                              (FAULT_AGG_BASE            + 0x000000e3)
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_OFFS                              0x000000e3
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_RMSK                                    0x1f
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_ADDR, HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_RMSK, 0, val)
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_ADDR, val, len)
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_ADDR, val)
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_ADDR, val, len)
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_MS_BMSK                                 0x1e
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_MS_SHFT                                  0x1
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_MSE_BMSK                                 0x1
#define HWIO_FAULT_AGG_PMIC5_RAM_RD_WR_MARGIN_CFG_MSE_SHFT                                 0x0

#define HWIO_FAULT_AGG_FORCE_FAULT_EN_ADDR                                          (FAULT_AGG_BASE            + 0x000000e4)
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_OFFS                                          0x000000e4
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_RMSK                                                0x1b
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_EN_ADDR, HWIO_FAULT_AGG_FORCE_FAULT_EN_RMSK, 0, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_EN_ADDR, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_EN_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_EN_ADDR, val, len)
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_PSAIL_ERR_N_EN_BMSK                           0x10
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_PSAIL_ERR_N_EN_SHFT                            0x4
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_GP_FAULT_EN_BMSK                               0x8
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_GP_FAULT_EN_SHFT                               0x3
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_LEVEL2_EN_BMSK                                 0x2
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_LEVEL2_EN_SHFT                                 0x1
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_LEVEL1_EN_BMSK                                 0x1
#define HWIO_FAULT_AGG_FORCE_FAULT_EN_FORCE_LEVEL1_EN_SHFT                                 0x0

#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_ADDR                                         (FAULT_AGG_BASE            + 0x000000e5)
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_OFFS                                         0x000000e5
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_RMSK                                               0x1b
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_VAL_ADDR, HWIO_FAULT_AGG_FORCE_FAULT_VAL_RMSK, 0, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_VAL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_VAL_ADDR, val, len)
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_VAL_ADDR, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_VAL_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_FORCE_FAULT_VAL_ADDR, val, len)
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_PSAIL_ERR_N_VAL_BMSK                         0x10
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_PSAIL_ERR_N_VAL_SHFT                          0x4
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_GP_FAULT_VAL_BMSK                             0x8
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_GP_FAULT_VAL_SHFT                             0x3
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_LEVEL2_VAL_BMSK                               0x2
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_LEVEL2_VAL_SHFT                               0x1
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_LEVEL1_VAL_BMSK                               0x1
#define HWIO_FAULT_AGG_FORCE_FAULT_VAL_FORCE_LEVEL1_VAL_SHFT                               0x0

#define HWIO_FAULT_AGG_STATUS_OVERRIDE_ADDR                                         (FAULT_AGG_BASE            + 0x000000e6)
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_OFFS                                         0x000000e6
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_RMSK                                               0x1f
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_STATUS_OVERRIDE_ADDR, val)
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_STATUS_OVERRIDE_ADDR, val, len)
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_FIRST_LEVEL2_RESET_BMSK                            0x10
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_FIRST_LEVEL2_RESET_SHFT                             0x4
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_OVERFLOW_BMSK                                0x8
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_OVERFLOW_SHFT                                0x3
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_FULL_BMSK                                    0x4
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_FULL_SHFT                                    0x2
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_NEARLY_FULL_BMSK                             0x2
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_NEARLY_FULL_SHFT                             0x1
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_EMPTY_BMSK                                   0x1
#define HWIO_FAULT_AGG_STATUS_OVERRIDE_LOGGER_EMPTY_SHFT                                   0x0

#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_ADDR                                       (FAULT_AGG_BASE            + 0x000000e7)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_OFFS                                       0x000000e7
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_ADDR, HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_ADDR, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_TIMESTAMP_BYTE0_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA0_TIMESTAMP_BYTE0_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_ADDR                                       (FAULT_AGG_BASE            + 0x000000e8)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_OFFS                                       0x000000e8
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_ADDR, HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_ADDR, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_TIMESTAMP_BYTE1_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA1_TIMESTAMP_BYTE1_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_ADDR                                       (FAULT_AGG_BASE            + 0x000000e9)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_OFFS                                       0x000000e9
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_ADDR, HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_ADDR, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_TIMESTAMP_BYTE2_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA2_TIMESTAMP_BYTE2_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_ADDR                                       (FAULT_AGG_BASE            + 0x000000ea)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_OFFS                                       0x000000ea
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_ADDR, HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_ADDR, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_TIMESTAMP_BYTE3_BMSK                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA3_TIMESTAMP_BYTE3_SHFT                              0x0

#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_ADDR                                       (FAULT_AGG_BASE            + 0x000000eb)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_OFFS                                       0x000000eb
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_RMSK                                             0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_ADDR, HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_ADDR, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_MONITOR_PID_BMSK                                 0xff
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA4_MONITOR_PID_SHFT                                  0x0

#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_ADDR                                       (FAULT_AGG_BASE            + 0x000000ec)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_OFFS                                       0x000000ec
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_RMSK                                             0x7f
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_ADDR, HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_RMSK, 0, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_ADDR, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_ADDR, val, len)
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_MONITOR_INDEX_BMSK                               0x70
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_MONITOR_INDEX_SHFT                                0x4
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_NEW_ERROR_BMSK                                    0xc
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_NEW_ERROR_SHFT                                    0x2
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_OLD_ERROR_BMSK                                    0x3
#define HWIO_FAULT_AGG_MEM_INTF_WR_DATA5_OLD_ERROR_SHFT                                    0x0

#define HWIO_FAULT_AGG_FORCE_CLK_REQ_ADDR                                           (FAULT_AGG_BASE            + 0x000000ed)
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_OFFS                                           0x000000ed
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_RMSK                                                  0x1
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_CLK_REQ_ADDR, HWIO_FAULT_AGG_FORCE_CLK_REQ_RMSK, 0, val)
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_CLK_REQ_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FORCE_CLK_REQ_ADDR, val, len)
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_FAULT_AGG_FORCE_CLK_REQ_ADDR, val)
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_FAULT_AGG_FORCE_CLK_REQ_ADDR, mask, shift, val)
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_FAULT_AGG_FORCE_CLK_REQ_ADDR, val, len)
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_FORCE_CLK_REQ_BMSK                                    0x1
#define HWIO_FAULT_AGG_FORCE_CLK_REQ_FORCE_CLK_REQ_SHFT                                    0x0

/*----------------------------------------------------------------------------
 * PERIPHERAL: SDAM01
 *--------------------------------------------------------------------------*/

#define SDAM01_BASE                                                      0x00007000

#define HWIO_SDAM01_REVISION1_ADDR                                       (SDAM01_BASE            + 0x00000000)
#define HWIO_SDAM01_REVISION1_OFFS                                       0x00000000
#define HWIO_SDAM01_REVISION1_RMSK                                             0xff
#define HWIO_SDAM01_REVISION1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION1_ADDR, HWIO_SDAM01_REVISION1_RMSK, 0, val)
#define HWIO_SDAM01_REVISION1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION1_ADDR, mask, shift, val)
#define HWIO_SDAM01_REVISION1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_REVISION1_ADDR, val, len)
#define HWIO_SDAM01_REVISION1_DIG_MINOR_BMSK                                   0xff
#define HWIO_SDAM01_REVISION1_DIG_MINOR_SHFT                                    0x0

#define HWIO_SDAM01_REVISION2_ADDR                                       (SDAM01_BASE            + 0x00000001)
#define HWIO_SDAM01_REVISION2_OFFS                                       0x00000001
#define HWIO_SDAM01_REVISION2_RMSK                                             0xff
#define HWIO_SDAM01_REVISION2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION2_ADDR, HWIO_SDAM01_REVISION2_RMSK, 0, val)
#define HWIO_SDAM01_REVISION2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION2_ADDR, mask, shift, val)
#define HWIO_SDAM01_REVISION2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_REVISION2_ADDR, val, len)
#define HWIO_SDAM01_REVISION2_DIG_MAJOR_BMSK                                   0xff
#define HWIO_SDAM01_REVISION2_DIG_MAJOR_SHFT                                    0x0

#define HWIO_SDAM01_REVISION3_ADDR                                       (SDAM01_BASE            + 0x00000002)
#define HWIO_SDAM01_REVISION3_OFFS                                       0x00000002
#define HWIO_SDAM01_REVISION3_RMSK                                             0xff
#define HWIO_SDAM01_REVISION3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION3_ADDR, HWIO_SDAM01_REVISION3_RMSK, 0, val)
#define HWIO_SDAM01_REVISION3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION3_ADDR, mask, shift, val)
#define HWIO_SDAM01_REVISION3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_REVISION3_ADDR, val, len)
#define HWIO_SDAM01_REVISION3_ANA_MINOR_BMSK                                   0xff
#define HWIO_SDAM01_REVISION3_ANA_MINOR_SHFT                                    0x0

#define HWIO_SDAM01_REVISION4_ADDR                                       (SDAM01_BASE            + 0x00000003)
#define HWIO_SDAM01_REVISION4_OFFS                                       0x00000003
#define HWIO_SDAM01_REVISION4_RMSK                                             0xff
#define HWIO_SDAM01_REVISION4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION4_ADDR, HWIO_SDAM01_REVISION4_RMSK, 0, val)
#define HWIO_SDAM01_REVISION4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_REVISION4_ADDR, mask, shift, val)
#define HWIO_SDAM01_REVISION4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_REVISION4_ADDR, val, len)
#define HWIO_SDAM01_REVISION4_ANA_MAJOR_BMSK                                   0xff
#define HWIO_SDAM01_REVISION4_ANA_MAJOR_SHFT                                    0x0

#define HWIO_SDAM01_PERPH_TYPE_ADDR                                      (SDAM01_BASE            + 0x00000004)
#define HWIO_SDAM01_PERPH_TYPE_OFFS                                      0x00000004
#define HWIO_SDAM01_PERPH_TYPE_RMSK                                            0xff
#define HWIO_SDAM01_PERPH_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_TYPE_ADDR, HWIO_SDAM01_PERPH_TYPE_RMSK, 0, val)
#define HWIO_SDAM01_PERPH_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_TYPE_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_TYPE_ADDR, val, len)
#define HWIO_SDAM01_PERPH_TYPE_TYPE_BMSK                                       0xff
#define HWIO_SDAM01_PERPH_TYPE_TYPE_SHFT                                        0x0

#define HWIO_SDAM01_PERPH_SUBTYPE_ADDR                                   (SDAM01_BASE            + 0x00000005)
#define HWIO_SDAM01_PERPH_SUBTYPE_OFFS                                   0x00000005
#define HWIO_SDAM01_PERPH_SUBTYPE_RMSK                                         0xff
#define HWIO_SDAM01_PERPH_SUBTYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_SUBTYPE_ADDR, HWIO_SDAM01_PERPH_SUBTYPE_RMSK, 0, val)
#define HWIO_SDAM01_PERPH_SUBTYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_SUBTYPE_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_SUBTYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_SUBTYPE_ADDR, val, len)
#define HWIO_SDAM01_PERPH_SUBTYPE_SUBTYPE_BMSK                                 0xff
#define HWIO_SDAM01_PERPH_SUBTYPE_SUBTYPE_SHFT                                  0x0

#define HWIO_SDAM01_INT_RT_STS_ADDR                                      (SDAM01_BASE            + 0x00000010)
#define HWIO_SDAM01_INT_RT_STS_OFFS                                      0x00000010
#define HWIO_SDAM01_INT_RT_STS_RMSK                                             0x2
#define HWIO_SDAM01_INT_RT_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_RT_STS_ADDR, HWIO_SDAM01_INT_RT_STS_RMSK, 0, val)
#define HWIO_SDAM01_INT_RT_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_RT_STS_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_RT_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_RT_STS_ADDR, val, len)
#define HWIO_SDAM01_INT_RT_STS_STS_BMSK                                         0x2
#define HWIO_SDAM01_INT_RT_STS_STS_SHFT                                         0x1

#define HWIO_SDAM01_INT_SET_TYPE_ADDR                                    (SDAM01_BASE            + 0x00000011)
#define HWIO_SDAM01_INT_SET_TYPE_OFFS                                    0x00000011
#define HWIO_SDAM01_INT_SET_TYPE_RMSK                                           0x2
#define HWIO_SDAM01_INT_SET_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_SET_TYPE_ADDR, HWIO_SDAM01_INT_SET_TYPE_RMSK, 0, val)
#define HWIO_SDAM01_INT_SET_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_SET_TYPE_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_SET_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_SET_TYPE_ADDR, val, len)
#define HWIO_SDAM01_INT_SET_TYPE_TYPE_BMSK                                      0x2
#define HWIO_SDAM01_INT_SET_TYPE_TYPE_SHFT                                      0x1

#define HWIO_SDAM01_INT_POLARITY_HIGH_ADDR                               (SDAM01_BASE            + 0x00000012)
#define HWIO_SDAM01_INT_POLARITY_HIGH_OFFS                               0x00000012
#define HWIO_SDAM01_INT_POLARITY_HIGH_RMSK                                      0x2
#define HWIO_SDAM01_INT_POLARITY_HIGH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_POLARITY_HIGH_ADDR, HWIO_SDAM01_INT_POLARITY_HIGH_RMSK, 0, val)
#define HWIO_SDAM01_INT_POLARITY_HIGH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_POLARITY_HIGH_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_POLARITY_HIGH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_POLARITY_HIGH_ADDR, val, len)
#define HWIO_SDAM01_INT_POLARITY_HIGH_POLARITY_BMSK                             0x2
#define HWIO_SDAM01_INT_POLARITY_HIGH_POLARITY_SHFT                             0x1

#define HWIO_SDAM01_INT_POLARITY_LOW_ADDR                                (SDAM01_BASE            + 0x00000013)
#define HWIO_SDAM01_INT_POLARITY_LOW_OFFS                                0x00000013
#define HWIO_SDAM01_INT_POLARITY_LOW_RMSK                                       0x2
#define HWIO_SDAM01_INT_POLARITY_LOW_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_POLARITY_LOW_ADDR, HWIO_SDAM01_INT_POLARITY_LOW_RMSK, 0, val)
#define HWIO_SDAM01_INT_POLARITY_LOW_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_POLARITY_LOW_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_POLARITY_LOW_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_POLARITY_LOW_ADDR, val, len)
#define HWIO_SDAM01_INT_POLARITY_LOW_POLARITY_BMSK                              0x2
#define HWIO_SDAM01_INT_POLARITY_LOW_POLARITY_SHFT                              0x1

#define HWIO_SDAM01_INT_LATCHED_CLR_ADDR                                 (SDAM01_BASE            + 0x00000014)
#define HWIO_SDAM01_INT_LATCHED_CLR_OFFS                                 0x00000014
#define HWIO_SDAM01_INT_LATCHED_CLR_RMSK                                        0x2
#define HWIO_SDAM01_INT_LATCHED_CLR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_INT_LATCHED_CLR_ADDR, val)
#define HWIO_SDAM01_INT_LATCHED_CLR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_INT_LATCHED_CLR_ADDR, val, len)
#define HWIO_SDAM01_INT_LATCHED_CLR_INT_LATCHED_CLR_BMSK                        0x2
#define HWIO_SDAM01_INT_LATCHED_CLR_INT_LATCHED_CLR_SHFT                        0x1

#define HWIO_SDAM01_INT_EN_SET_ADDR                                      (SDAM01_BASE            + 0x00000015)
#define HWIO_SDAM01_INT_EN_SET_OFFS                                      0x00000015
#define HWIO_SDAM01_INT_EN_SET_RMSK                                             0x2
#define HWIO_SDAM01_INT_EN_SET_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_EN_SET_ADDR, HWIO_SDAM01_INT_EN_SET_RMSK, 0, val)
#define HWIO_SDAM01_INT_EN_SET_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_EN_SET_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_EN_SET_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_EN_SET_ADDR, val, len)
#define HWIO_SDAM01_INT_EN_SET_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_INT_EN_SET_ADDR, val)
#define HWIO_SDAM01_INT_EN_SET_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_EN_SET_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_EN_SET_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_INT_EN_SET_ADDR, val, len)
#define HWIO_SDAM01_INT_EN_SET_INT_EN_BMSK                                      0x2
#define HWIO_SDAM01_INT_EN_SET_INT_EN_SHFT                                      0x1

#define HWIO_SDAM01_INT_EN_CLR_ADDR                                      (SDAM01_BASE            + 0x00000016)
#define HWIO_SDAM01_INT_EN_CLR_OFFS                                      0x00000016
#define HWIO_SDAM01_INT_EN_CLR_RMSK                                             0x2
#define HWIO_SDAM01_INT_EN_CLR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_EN_CLR_ADDR, HWIO_SDAM01_INT_EN_CLR_RMSK, 0, val)
#define HWIO_SDAM01_INT_EN_CLR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_EN_CLR_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_EN_CLR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_EN_CLR_ADDR, val, len)
#define HWIO_SDAM01_INT_EN_CLR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_INT_EN_CLR_ADDR, val)
#define HWIO_SDAM01_INT_EN_CLR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_EN_CLR_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_EN_CLR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_INT_EN_CLR_ADDR, val, len)
#define HWIO_SDAM01_INT_EN_CLR_INT_EN_BMSK                                      0x2
#define HWIO_SDAM01_INT_EN_CLR_INT_EN_SHFT                                      0x1

#define HWIO_SDAM01_INT_LATCHED_STS_ADDR                                 (SDAM01_BASE            + 0x00000018)
#define HWIO_SDAM01_INT_LATCHED_STS_OFFS                                 0x00000018
#define HWIO_SDAM01_INT_LATCHED_STS_RMSK                                        0x2
#define HWIO_SDAM01_INT_LATCHED_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_LATCHED_STS_ADDR, HWIO_SDAM01_INT_LATCHED_STS_RMSK, 0, val)
#define HWIO_SDAM01_INT_LATCHED_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_LATCHED_STS_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_LATCHED_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_LATCHED_STS_ADDR, val, len)
#define HWIO_SDAM01_INT_LATCHED_STS_INT_LATCHED_STS_BMSK                        0x2
#define HWIO_SDAM01_INT_LATCHED_STS_INT_LATCHED_STS_SHFT                        0x1

#define HWIO_SDAM01_INT_PENDING_STS_ADDR                                 (SDAM01_BASE            + 0x00000019)
#define HWIO_SDAM01_INT_PENDING_STS_OFFS                                 0x00000019
#define HWIO_SDAM01_INT_PENDING_STS_RMSK                                        0x2
#define HWIO_SDAM01_INT_PENDING_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_PENDING_STS_ADDR, HWIO_SDAM01_INT_PENDING_STS_RMSK, 0, val)
#define HWIO_SDAM01_INT_PENDING_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_PENDING_STS_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_PENDING_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_PENDING_STS_ADDR, val, len)
#define HWIO_SDAM01_INT_PENDING_STS_INT_PENDING_STS_BMSK                        0x2
#define HWIO_SDAM01_INT_PENDING_STS_INT_PENDING_STS_SHFT                        0x1

#define HWIO_SDAM01_INT_MID_SEL_ADDR                                     (SDAM01_BASE            + 0x0000001a)
#define HWIO_SDAM01_INT_MID_SEL_OFFS                                     0x0000001a
#define HWIO_SDAM01_INT_MID_SEL_RMSK                                            0x3
#define HWIO_SDAM01_INT_MID_SEL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_MID_SEL_ADDR, HWIO_SDAM01_INT_MID_SEL_RMSK, 0, val)
#define HWIO_SDAM01_INT_MID_SEL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_MID_SEL_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_MID_SEL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_MID_SEL_ADDR, val, len)
#define HWIO_SDAM01_INT_MID_SEL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_INT_MID_SEL_ADDR, val)
#define HWIO_SDAM01_INT_MID_SEL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_MID_SEL_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_MID_SEL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_INT_MID_SEL_ADDR, val, len)
#define HWIO_SDAM01_INT_MID_SEL_INT_MID_SEL_BMSK                                0x3
#define HWIO_SDAM01_INT_MID_SEL_INT_MID_SEL_SHFT                                0x0

#define HWIO_SDAM01_INT_PRIORITY_ADDR                                    (SDAM01_BASE            + 0x0000001b)
#define HWIO_SDAM01_INT_PRIORITY_OFFS                                    0x0000001b
#define HWIO_SDAM01_INT_PRIORITY_RMSK                                           0x1
#define HWIO_SDAM01_INT_PRIORITY_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_PRIORITY_ADDR, HWIO_SDAM01_INT_PRIORITY_RMSK, 0, val)
#define HWIO_SDAM01_INT_PRIORITY_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_PRIORITY_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_PRIORITY_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_PRIORITY_ADDR, val, len)
#define HWIO_SDAM01_INT_PRIORITY_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_INT_PRIORITY_ADDR, val)
#define HWIO_SDAM01_INT_PRIORITY_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_PRIORITY_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_PRIORITY_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_INT_PRIORITY_ADDR, val, len)
#define HWIO_SDAM01_INT_PRIORITY_INT_PRIORITY_BMSK                              0x1
#define HWIO_SDAM01_INT_PRIORITY_INT_PRIORITY_SHFT                              0x0

#define HWIO_TZ_SDAM_REGISTER_MAP_ID_ADDR                                (SDAM01_BASE            + 0x00000040)
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_OFFS                                0x00000040
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_RMSK                                      0xff
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_ID_ADDR, HWIO_TZ_SDAM_REGISTER_MAP_ID_RMSK, 0, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_ID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_ID_ADDR, val, len)
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_ID_ADDR, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_ID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_ID_ADDR, val, len)
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_REGISTER_MAP_ID_BMSK                      0xff
#define HWIO_TZ_SDAM_REGISTER_MAP_ID_REGISTER_MAP_ID_SHFT                       0x0

#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_ADDR                           (SDAM01_BASE            + 0x00000041)
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_OFFS                           0x00000041
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_RMSK                                 0xff
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_VERSION_ADDR, HWIO_TZ_SDAM_REGISTER_MAP_VERSION_RMSK, 0, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_VERSION_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_VERSION_ADDR, val, len)
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_VERSION_ADDR, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_VERSION_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_REGISTER_MAP_VERSION_ADDR, val, len)
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_REGISTER_MAP_VERSION_BMSK            0xff
#define HWIO_TZ_SDAM_REGISTER_MAP_VERSION_REGISTER_MAP_VERSION_SHFT             0x0

#define HWIO_TZ_SDAM_PBS_ARG_ADDR                                        (SDAM01_BASE            + 0x00000042)
#define HWIO_TZ_SDAM_PBS_ARG_OFFS                                        0x00000042
#define HWIO_TZ_SDAM_PBS_ARG_RMSK                                              0xff
#define HWIO_TZ_SDAM_PBS_ARG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_ARG_ADDR, HWIO_TZ_SDAM_PBS_ARG_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_ARG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_ARG_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_ARG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_ARG_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_ARG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_ARG_ADDR, val)
#define HWIO_TZ_SDAM_PBS_ARG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_ARG_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_ARG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_ARG_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_ARG_PBS_ARG_BMSK                                      0xff
#define HWIO_TZ_SDAM_PBS_ARG_PBS_ARG_SHFT                                       0x0

#define HWIO_TZ_SDAM_PBS_RET_ADDR                                        (SDAM01_BASE            + 0x00000043)
#define HWIO_TZ_SDAM_PBS_RET_OFFS                                        0x00000043
#define HWIO_TZ_SDAM_PBS_RET_RMSK                                              0xff
#define HWIO_TZ_SDAM_PBS_RET_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RET_ADDR, HWIO_TZ_SDAM_PBS_RET_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_RET_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RET_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RET_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RET_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RET_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RET_ADDR, val)
#define HWIO_TZ_SDAM_PBS_RET_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RET_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RET_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_RET_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RET_PBS_RET_BMSK                                      0xff
#define HWIO_TZ_SDAM_PBS_RET_PBS_RET_SHFT                                       0x0

#define HWIO_TZ_SDAM_SDAM_SIZE_ADDR                                      (SDAM01_BASE            + 0x00000044)
#define HWIO_TZ_SDAM_SDAM_SIZE_OFFS                                      0x00000044
#define HWIO_TZ_SDAM_SDAM_SIZE_RMSK                                            0xff
#define HWIO_TZ_SDAM_SDAM_SIZE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SDAM_SIZE_ADDR, HWIO_TZ_SDAM_SDAM_SIZE_RMSK, 0, val)
#define HWIO_TZ_SDAM_SDAM_SIZE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SDAM_SIZE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SDAM_SIZE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SDAM_SIZE_ADDR, val, len)
#define HWIO_TZ_SDAM_SDAM_SIZE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SDAM_SIZE_ADDR, val)
#define HWIO_TZ_SDAM_SDAM_SIZE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SDAM_SIZE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SDAM_SIZE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_SDAM_SIZE_ADDR, val, len)
#define HWIO_TZ_SDAM_SDAM_SIZE_SDAM_SIZE_BMSK                                  0xff
#define HWIO_TZ_SDAM_SDAM_SIZE_SDAM_SIZE_SHFT                                   0x0

#define HWIO_SDAM01_MEM_005_ADDR                                         (SDAM01_BASE            + 0x00000045)
#define HWIO_SDAM01_MEM_005_OFFS                                         0x00000045
#define HWIO_SDAM01_MEM_005_RMSK                                               0xff
#define HWIO_SDAM01_MEM_005_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_005_ADDR, HWIO_SDAM01_MEM_005_RMSK, 0, val)
#define HWIO_SDAM01_MEM_005_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_005_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_005_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_005_ADDR, val, len)
#define HWIO_SDAM01_MEM_005_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_005_ADDR, val)
#define HWIO_SDAM01_MEM_005_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_005_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_005_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_005_ADDR, val, len)
#define HWIO_SDAM01_MEM_005_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_005_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_006_ADDR                                         (SDAM01_BASE            + 0x00000046)
#define HWIO_SDAM01_MEM_006_OFFS                                         0x00000046
#define HWIO_SDAM01_MEM_006_RMSK                                               0xff
#define HWIO_SDAM01_MEM_006_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_006_ADDR, HWIO_SDAM01_MEM_006_RMSK, 0, val)
#define HWIO_SDAM01_MEM_006_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_006_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_006_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_006_ADDR, val, len)
#define HWIO_SDAM01_MEM_006_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_006_ADDR, val)
#define HWIO_SDAM01_MEM_006_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_006_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_006_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_006_ADDR, val, len)
#define HWIO_SDAM01_MEM_006_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_006_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_007_ADDR                                         (SDAM01_BASE            + 0x00000047)
#define HWIO_SDAM01_MEM_007_OFFS                                         0x00000047
#define HWIO_SDAM01_MEM_007_RMSK                                               0xff
#define HWIO_SDAM01_MEM_007_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_007_ADDR, HWIO_SDAM01_MEM_007_RMSK, 0, val)
#define HWIO_SDAM01_MEM_007_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_007_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_007_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_007_ADDR, val, len)
#define HWIO_SDAM01_MEM_007_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_007_ADDR, val)
#define HWIO_SDAM01_MEM_007_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_007_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_007_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_007_ADDR, val, len)
#define HWIO_SDAM01_MEM_007_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_007_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_008_ADDR                                         (SDAM01_BASE            + 0x00000048)
#define HWIO_SDAM01_MEM_008_OFFS                                         0x00000048
#define HWIO_SDAM01_MEM_008_RMSK                                               0xff
#define HWIO_SDAM01_MEM_008_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_008_ADDR, HWIO_SDAM01_MEM_008_RMSK, 0, val)
#define HWIO_SDAM01_MEM_008_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_008_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_008_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_008_ADDR, val, len)
#define HWIO_SDAM01_MEM_008_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_008_ADDR, val)
#define HWIO_SDAM01_MEM_008_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_008_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_008_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_008_ADDR, val, len)
#define HWIO_SDAM01_MEM_008_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_008_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_009_ADDR                                         (SDAM01_BASE            + 0x00000049)
#define HWIO_SDAM01_MEM_009_OFFS                                         0x00000049
#define HWIO_SDAM01_MEM_009_RMSK                                               0xff
#define HWIO_SDAM01_MEM_009_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_009_ADDR, HWIO_SDAM01_MEM_009_RMSK, 0, val)
#define HWIO_SDAM01_MEM_009_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_009_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_009_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_009_ADDR, val, len)
#define HWIO_SDAM01_MEM_009_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_009_ADDR, val)
#define HWIO_SDAM01_MEM_009_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_009_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_009_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_009_ADDR, val, len)
#define HWIO_SDAM01_MEM_009_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_009_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_010_ADDR                                         (SDAM01_BASE            + 0x0000004a)
#define HWIO_SDAM01_MEM_010_OFFS                                         0x0000004a
#define HWIO_SDAM01_MEM_010_RMSK                                               0xff
#define HWIO_SDAM01_MEM_010_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_010_ADDR, HWIO_SDAM01_MEM_010_RMSK, 0, val)
#define HWIO_SDAM01_MEM_010_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_010_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_010_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_010_ADDR, val, len)
#define HWIO_SDAM01_MEM_010_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_010_ADDR, val)
#define HWIO_SDAM01_MEM_010_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_010_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_010_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_010_ADDR, val, len)
#define HWIO_SDAM01_MEM_010_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_010_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_011_ADDR                                         (SDAM01_BASE            + 0x0000004b)
#define HWIO_SDAM01_MEM_011_OFFS                                         0x0000004b
#define HWIO_SDAM01_MEM_011_RMSK                                               0xff
#define HWIO_SDAM01_MEM_011_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_011_ADDR, HWIO_SDAM01_MEM_011_RMSK, 0, val)
#define HWIO_SDAM01_MEM_011_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_011_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_011_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_011_ADDR, val, len)
#define HWIO_SDAM01_MEM_011_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_011_ADDR, val)
#define HWIO_SDAM01_MEM_011_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_011_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_011_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_011_ADDR, val, len)
#define HWIO_SDAM01_MEM_011_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_011_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_012_ADDR                                         (SDAM01_BASE            + 0x0000004c)
#define HWIO_SDAM01_MEM_012_OFFS                                         0x0000004c
#define HWIO_SDAM01_MEM_012_RMSK                                               0xff
#define HWIO_SDAM01_MEM_012_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_012_ADDR, HWIO_SDAM01_MEM_012_RMSK, 0, val)
#define HWIO_SDAM01_MEM_012_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_012_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_012_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_012_ADDR, val, len)
#define HWIO_SDAM01_MEM_012_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_012_ADDR, val)
#define HWIO_SDAM01_MEM_012_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_012_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_012_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_012_ADDR, val, len)
#define HWIO_SDAM01_MEM_012_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_012_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_013_ADDR                                         (SDAM01_BASE            + 0x0000004d)
#define HWIO_SDAM01_MEM_013_OFFS                                         0x0000004d
#define HWIO_SDAM01_MEM_013_RMSK                                               0xff
#define HWIO_SDAM01_MEM_013_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_013_ADDR, HWIO_SDAM01_MEM_013_RMSK, 0, val)
#define HWIO_SDAM01_MEM_013_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_013_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_013_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_013_ADDR, val, len)
#define HWIO_SDAM01_MEM_013_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_013_ADDR, val)
#define HWIO_SDAM01_MEM_013_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_013_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_013_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_013_ADDR, val, len)
#define HWIO_SDAM01_MEM_013_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_013_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_014_ADDR                                         (SDAM01_BASE            + 0x0000004e)
#define HWIO_SDAM01_MEM_014_OFFS                                         0x0000004e
#define HWIO_SDAM01_MEM_014_RMSK                                               0xff
#define HWIO_SDAM01_MEM_014_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_014_ADDR, HWIO_SDAM01_MEM_014_RMSK, 0, val)
#define HWIO_SDAM01_MEM_014_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_014_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_014_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_014_ADDR, val, len)
#define HWIO_SDAM01_MEM_014_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_014_ADDR, val)
#define HWIO_SDAM01_MEM_014_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_014_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_014_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_014_ADDR, val, len)
#define HWIO_SDAM01_MEM_014_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_014_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_015_ADDR                                         (SDAM01_BASE            + 0x0000004f)
#define HWIO_SDAM01_MEM_015_OFFS                                         0x0000004f
#define HWIO_SDAM01_MEM_015_RMSK                                               0xff
#define HWIO_SDAM01_MEM_015_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_015_ADDR, HWIO_SDAM01_MEM_015_RMSK, 0, val)
#define HWIO_SDAM01_MEM_015_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_015_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_015_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_015_ADDR, val, len)
#define HWIO_SDAM01_MEM_015_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_015_ADDR, val)
#define HWIO_SDAM01_MEM_015_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_015_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_015_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_015_ADDR, val, len)
#define HWIO_SDAM01_MEM_015_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_015_DATA_SHFT                                           0x0

#define HWIO_TZ_SDAM_SBL_ID_0_ADDR                                       (SDAM01_BASE            + 0x00000050)
#define HWIO_TZ_SDAM_SBL_ID_0_OFFS                                       0x00000050
#define HWIO_TZ_SDAM_SBL_ID_0_RMSK                                             0xff
#define HWIO_TZ_SDAM_SBL_ID_0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_0_ADDR, HWIO_TZ_SDAM_SBL_ID_0_RMSK, 0, val)
#define HWIO_TZ_SDAM_SBL_ID_0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_0_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SBL_ID_0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_0_ADDR, val, len)
#define HWIO_TZ_SDAM_SBL_ID_0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_0_ADDR, val)
#define HWIO_TZ_SDAM_SBL_ID_0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_0_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SBL_ID_0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_0_ADDR, val, len)
#define HWIO_TZ_SDAM_SBL_ID_0_SBL_ID_0_BMSK                                    0xff
#define HWIO_TZ_SDAM_SBL_ID_0_SBL_ID_0_SHFT                                     0x0

#define HWIO_TZ_SDAM_SBL_ID_1_ADDR                                       (SDAM01_BASE            + 0x00000051)
#define HWIO_TZ_SDAM_SBL_ID_1_OFFS                                       0x00000051
#define HWIO_TZ_SDAM_SBL_ID_1_RMSK                                             0xff
#define HWIO_TZ_SDAM_SBL_ID_1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_1_ADDR, HWIO_TZ_SDAM_SBL_ID_1_RMSK, 0, val)
#define HWIO_TZ_SDAM_SBL_ID_1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_1_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SBL_ID_1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_1_ADDR, val, len)
#define HWIO_TZ_SDAM_SBL_ID_1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_1_ADDR, val)
#define HWIO_TZ_SDAM_SBL_ID_1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_1_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SBL_ID_1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_SBL_ID_1_ADDR, val, len)
#define HWIO_TZ_SDAM_SBL_ID_1_SBL_ID_1_BMSK                                    0xff
#define HWIO_TZ_SDAM_SBL_ID_1_SBL_ID_1_SHFT                                     0x0

#define HWIO_SDAM01_MEM_018_ADDR                                         (SDAM01_BASE            + 0x00000052)
#define HWIO_SDAM01_MEM_018_OFFS                                         0x00000052
#define HWIO_SDAM01_MEM_018_RMSK                                               0xff
#define HWIO_SDAM01_MEM_018_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_018_ADDR, HWIO_SDAM01_MEM_018_RMSK, 0, val)
#define HWIO_SDAM01_MEM_018_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_018_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_018_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_018_ADDR, val, len)
#define HWIO_SDAM01_MEM_018_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_018_ADDR, val)
#define HWIO_SDAM01_MEM_018_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_018_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_018_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_018_ADDR, val, len)
#define HWIO_SDAM01_MEM_018_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_018_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_019_ADDR                                         (SDAM01_BASE            + 0x00000053)
#define HWIO_SDAM01_MEM_019_OFFS                                         0x00000053
#define HWIO_SDAM01_MEM_019_RMSK                                               0xff
#define HWIO_SDAM01_MEM_019_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_019_ADDR, HWIO_SDAM01_MEM_019_RMSK, 0, val)
#define HWIO_SDAM01_MEM_019_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_019_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_019_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_019_ADDR, val, len)
#define HWIO_SDAM01_MEM_019_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_019_ADDR, val)
#define HWIO_SDAM01_MEM_019_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_019_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_019_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_019_ADDR, val, len)
#define HWIO_SDAM01_MEM_019_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_019_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_020_ADDR                                         (SDAM01_BASE            + 0x00000054)
#define HWIO_SDAM01_MEM_020_OFFS                                         0x00000054
#define HWIO_SDAM01_MEM_020_RMSK                                               0xff
#define HWIO_SDAM01_MEM_020_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_020_ADDR, HWIO_SDAM01_MEM_020_RMSK, 0, val)
#define HWIO_SDAM01_MEM_020_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_020_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_020_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_020_ADDR, val, len)
#define HWIO_SDAM01_MEM_020_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_020_ADDR, val)
#define HWIO_SDAM01_MEM_020_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_020_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_020_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_020_ADDR, val, len)
#define HWIO_SDAM01_MEM_020_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_020_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_021_ADDR                                         (SDAM01_BASE            + 0x00000055)
#define HWIO_SDAM01_MEM_021_OFFS                                         0x00000055
#define HWIO_SDAM01_MEM_021_RMSK                                               0xff
#define HWIO_SDAM01_MEM_021_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_021_ADDR, HWIO_SDAM01_MEM_021_RMSK, 0, val)
#define HWIO_SDAM01_MEM_021_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_021_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_021_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_021_ADDR, val, len)
#define HWIO_SDAM01_MEM_021_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_021_ADDR, val)
#define HWIO_SDAM01_MEM_021_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_021_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_021_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_021_ADDR, val, len)
#define HWIO_SDAM01_MEM_021_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_021_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_022_ADDR                                         (SDAM01_BASE            + 0x00000056)
#define HWIO_SDAM01_MEM_022_OFFS                                         0x00000056
#define HWIO_SDAM01_MEM_022_RMSK                                               0xff
#define HWIO_SDAM01_MEM_022_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_022_ADDR, HWIO_SDAM01_MEM_022_RMSK, 0, val)
#define HWIO_SDAM01_MEM_022_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_022_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_022_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_022_ADDR, val, len)
#define HWIO_SDAM01_MEM_022_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_022_ADDR, val)
#define HWIO_SDAM01_MEM_022_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_022_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_022_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_022_ADDR, val, len)
#define HWIO_SDAM01_MEM_022_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_022_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_023_ADDR                                         (SDAM01_BASE            + 0x00000057)
#define HWIO_SDAM01_MEM_023_OFFS                                         0x00000057
#define HWIO_SDAM01_MEM_023_RMSK                                               0xff
#define HWIO_SDAM01_MEM_023_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_023_ADDR, HWIO_SDAM01_MEM_023_RMSK, 0, val)
#define HWIO_SDAM01_MEM_023_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_023_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_023_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_023_ADDR, val, len)
#define HWIO_SDAM01_MEM_023_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_023_ADDR, val)
#define HWIO_SDAM01_MEM_023_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_023_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_023_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_023_ADDR, val, len)
#define HWIO_SDAM01_MEM_023_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_023_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_024_ADDR                                         (SDAM01_BASE            + 0x00000058)
#define HWIO_SDAM01_MEM_024_OFFS                                         0x00000058
#define HWIO_SDAM01_MEM_024_RMSK                                               0xff
#define HWIO_SDAM01_MEM_024_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_024_ADDR, HWIO_SDAM01_MEM_024_RMSK, 0, val)
#define HWIO_SDAM01_MEM_024_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_024_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_024_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_024_ADDR, val, len)
#define HWIO_SDAM01_MEM_024_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_024_ADDR, val)
#define HWIO_SDAM01_MEM_024_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_024_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_024_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_024_ADDR, val, len)
#define HWIO_SDAM01_MEM_024_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_024_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_025_ADDR                                         (SDAM01_BASE            + 0x00000059)
#define HWIO_SDAM01_MEM_025_OFFS                                         0x00000059
#define HWIO_SDAM01_MEM_025_RMSK                                               0xff
#define HWIO_SDAM01_MEM_025_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_025_ADDR, HWIO_SDAM01_MEM_025_RMSK, 0, val)
#define HWIO_SDAM01_MEM_025_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_025_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_025_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_025_ADDR, val, len)
#define HWIO_SDAM01_MEM_025_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_025_ADDR, val)
#define HWIO_SDAM01_MEM_025_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_025_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_025_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_025_ADDR, val, len)
#define HWIO_SDAM01_MEM_025_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_025_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_026_ADDR                                         (SDAM01_BASE            + 0x0000005a)
#define HWIO_SDAM01_MEM_026_OFFS                                         0x0000005a
#define HWIO_SDAM01_MEM_026_RMSK                                               0xff
#define HWIO_SDAM01_MEM_026_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_026_ADDR, HWIO_SDAM01_MEM_026_RMSK, 0, val)
#define HWIO_SDAM01_MEM_026_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_026_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_026_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_026_ADDR, val, len)
#define HWIO_SDAM01_MEM_026_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_026_ADDR, val)
#define HWIO_SDAM01_MEM_026_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_026_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_026_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_026_ADDR, val, len)
#define HWIO_SDAM01_MEM_026_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_026_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_027_ADDR                                         (SDAM01_BASE            + 0x0000005b)
#define HWIO_SDAM01_MEM_027_OFFS                                         0x0000005b
#define HWIO_SDAM01_MEM_027_RMSK                                               0xff
#define HWIO_SDAM01_MEM_027_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_027_ADDR, HWIO_SDAM01_MEM_027_RMSK, 0, val)
#define HWIO_SDAM01_MEM_027_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_027_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_027_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_027_ADDR, val, len)
#define HWIO_SDAM01_MEM_027_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_027_ADDR, val)
#define HWIO_SDAM01_MEM_027_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_027_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_027_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_027_ADDR, val, len)
#define HWIO_SDAM01_MEM_027_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_027_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_028_ADDR                                         (SDAM01_BASE            + 0x0000005c)
#define HWIO_SDAM01_MEM_028_OFFS                                         0x0000005c
#define HWIO_SDAM01_MEM_028_RMSK                                               0xff
#define HWIO_SDAM01_MEM_028_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_028_ADDR, HWIO_SDAM01_MEM_028_RMSK, 0, val)
#define HWIO_SDAM01_MEM_028_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_028_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_028_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_028_ADDR, val, len)
#define HWIO_SDAM01_MEM_028_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_028_ADDR, val)
#define HWIO_SDAM01_MEM_028_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_028_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_028_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_028_ADDR, val, len)
#define HWIO_SDAM01_MEM_028_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_028_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_029_ADDR                                         (SDAM01_BASE            + 0x0000005d)
#define HWIO_SDAM01_MEM_029_OFFS                                         0x0000005d
#define HWIO_SDAM01_MEM_029_RMSK                                               0xff
#define HWIO_SDAM01_MEM_029_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_029_ADDR, HWIO_SDAM01_MEM_029_RMSK, 0, val)
#define HWIO_SDAM01_MEM_029_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_029_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_029_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_029_ADDR, val, len)
#define HWIO_SDAM01_MEM_029_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_029_ADDR, val)
#define HWIO_SDAM01_MEM_029_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_029_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_029_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_029_ADDR, val, len)
#define HWIO_SDAM01_MEM_029_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_029_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_030_ADDR                                         (SDAM01_BASE            + 0x0000005e)
#define HWIO_SDAM01_MEM_030_OFFS                                         0x0000005e
#define HWIO_SDAM01_MEM_030_RMSK                                               0xff
#define HWIO_SDAM01_MEM_030_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_030_ADDR, HWIO_SDAM01_MEM_030_RMSK, 0, val)
#define HWIO_SDAM01_MEM_030_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_030_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_030_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_030_ADDR, val, len)
#define HWIO_SDAM01_MEM_030_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_030_ADDR, val)
#define HWIO_SDAM01_MEM_030_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_030_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_030_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_030_ADDR, val, len)
#define HWIO_SDAM01_MEM_030_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_030_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_031_ADDR                                         (SDAM01_BASE            + 0x0000005f)
#define HWIO_SDAM01_MEM_031_OFFS                                         0x0000005f
#define HWIO_SDAM01_MEM_031_RMSK                                               0xff
#define HWIO_SDAM01_MEM_031_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_031_ADDR, HWIO_SDAM01_MEM_031_RMSK, 0, val)
#define HWIO_SDAM01_MEM_031_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_031_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_031_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_031_ADDR, val, len)
#define HWIO_SDAM01_MEM_031_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_031_ADDR, val)
#define HWIO_SDAM01_MEM_031_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_031_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_031_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_031_ADDR, val, len)
#define HWIO_SDAM01_MEM_031_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_031_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_032_ADDR                                         (SDAM01_BASE            + 0x00000060)
#define HWIO_SDAM01_MEM_032_OFFS                                         0x00000060
#define HWIO_SDAM01_MEM_032_RMSK                                               0xff
#define HWIO_SDAM01_MEM_032_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_032_ADDR, HWIO_SDAM01_MEM_032_RMSK, 0, val)
#define HWIO_SDAM01_MEM_032_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_032_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_032_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_032_ADDR, val, len)
#define HWIO_SDAM01_MEM_032_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_032_ADDR, val)
#define HWIO_SDAM01_MEM_032_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_032_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_032_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_032_ADDR, val, len)
#define HWIO_SDAM01_MEM_032_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_032_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_033_ADDR                                         (SDAM01_BASE            + 0x00000061)
#define HWIO_SDAM01_MEM_033_OFFS                                         0x00000061
#define HWIO_SDAM01_MEM_033_RMSK                                               0xff
#define HWIO_SDAM01_MEM_033_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_033_ADDR, HWIO_SDAM01_MEM_033_RMSK, 0, val)
#define HWIO_SDAM01_MEM_033_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_033_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_033_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_033_ADDR, val, len)
#define HWIO_SDAM01_MEM_033_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_033_ADDR, val)
#define HWIO_SDAM01_MEM_033_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_033_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_033_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_033_ADDR, val, len)
#define HWIO_SDAM01_MEM_033_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_033_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_034_ADDR                                         (SDAM01_BASE            + 0x00000062)
#define HWIO_SDAM01_MEM_034_OFFS                                         0x00000062
#define HWIO_SDAM01_MEM_034_RMSK                                               0xff
#define HWIO_SDAM01_MEM_034_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_034_ADDR, HWIO_SDAM01_MEM_034_RMSK, 0, val)
#define HWIO_SDAM01_MEM_034_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_034_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_034_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_034_ADDR, val, len)
#define HWIO_SDAM01_MEM_034_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_034_ADDR, val)
#define HWIO_SDAM01_MEM_034_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_034_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_034_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_034_ADDR, val, len)
#define HWIO_SDAM01_MEM_034_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_034_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_035_ADDR                                         (SDAM01_BASE            + 0x00000063)
#define HWIO_SDAM01_MEM_035_OFFS                                         0x00000063
#define HWIO_SDAM01_MEM_035_RMSK                                               0xff
#define HWIO_SDAM01_MEM_035_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_035_ADDR, HWIO_SDAM01_MEM_035_RMSK, 0, val)
#define HWIO_SDAM01_MEM_035_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_035_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_035_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_035_ADDR, val, len)
#define HWIO_SDAM01_MEM_035_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_035_ADDR, val)
#define HWIO_SDAM01_MEM_035_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_035_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_035_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_035_ADDR, val, len)
#define HWIO_SDAM01_MEM_035_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_035_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_036_ADDR                                         (SDAM01_BASE            + 0x00000064)
#define HWIO_SDAM01_MEM_036_OFFS                                         0x00000064
#define HWIO_SDAM01_MEM_036_RMSK                                               0xff
#define HWIO_SDAM01_MEM_036_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_036_ADDR, HWIO_SDAM01_MEM_036_RMSK, 0, val)
#define HWIO_SDAM01_MEM_036_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_036_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_036_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_036_ADDR, val, len)
#define HWIO_SDAM01_MEM_036_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_036_ADDR, val)
#define HWIO_SDAM01_MEM_036_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_036_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_036_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_036_ADDR, val, len)
#define HWIO_SDAM01_MEM_036_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_036_DATA_SHFT                                           0x0

#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ADDR                               (SDAM01_BASE            + 0x00000065)
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_OFFS                               0x00000065
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_RMSK                                     0xff
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ADDR, HWIO_TZ_SDAM_ENABLE_CRC_CHECK_RMSK, 0, val)
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ADDR, val, len)
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ADDR, val)
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ADDR, val, len)
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ENABLE_CRC_CHECK_BMSK                    0xff
#define HWIO_TZ_SDAM_ENABLE_CRC_CHECK_ENABLE_CRC_CHECK_SHFT                     0x0

#define HWIO_SDAM01_MEM_038_ADDR                                         (SDAM01_BASE            + 0x00000066)
#define HWIO_SDAM01_MEM_038_OFFS                                         0x00000066
#define HWIO_SDAM01_MEM_038_RMSK                                               0xff
#define HWIO_SDAM01_MEM_038_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_038_ADDR, HWIO_SDAM01_MEM_038_RMSK, 0, val)
#define HWIO_SDAM01_MEM_038_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_038_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_038_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_038_ADDR, val, len)
#define HWIO_SDAM01_MEM_038_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_038_ADDR, val)
#define HWIO_SDAM01_MEM_038_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_038_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_038_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_038_ADDR, val, len)
#define HWIO_SDAM01_MEM_038_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_038_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_039_ADDR                                         (SDAM01_BASE            + 0x00000067)
#define HWIO_SDAM01_MEM_039_OFFS                                         0x00000067
#define HWIO_SDAM01_MEM_039_RMSK                                               0xff
#define HWIO_SDAM01_MEM_039_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_039_ADDR, HWIO_SDAM01_MEM_039_RMSK, 0, val)
#define HWIO_SDAM01_MEM_039_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_039_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_039_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_039_ADDR, val, len)
#define HWIO_SDAM01_MEM_039_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_039_ADDR, val)
#define HWIO_SDAM01_MEM_039_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_039_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_039_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_039_ADDR, val, len)
#define HWIO_SDAM01_MEM_039_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_039_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_040_ADDR                                         (SDAM01_BASE            + 0x00000068)
#define HWIO_SDAM01_MEM_040_OFFS                                         0x00000068
#define HWIO_SDAM01_MEM_040_RMSK                                               0xff
#define HWIO_SDAM01_MEM_040_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_040_ADDR, HWIO_SDAM01_MEM_040_RMSK, 0, val)
#define HWIO_SDAM01_MEM_040_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_040_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_040_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_040_ADDR, val, len)
#define HWIO_SDAM01_MEM_040_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_040_ADDR, val)
#define HWIO_SDAM01_MEM_040_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_040_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_040_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_040_ADDR, val, len)
#define HWIO_SDAM01_MEM_040_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_040_DATA_SHFT                                           0x0

#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_ADDR                             (SDAM01_BASE            + 0x00000069)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_OFFS                             0x00000069
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_RMSK                                   0xff
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_ADDR, HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_PBS_OTP_CRC_STATUS_BMSK                0xff
#define HWIO_TZ_SDAM_PBS_OTP_CRC_STATUS_PBS_OTP_CRC_STATUS_SHFT                 0x0

#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_ADDR                               (SDAM01_BASE            + 0x0000006a)
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_OFFS                               0x0000006a
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_RMSK                                     0xff
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBUS_BIST_STATUS_ADDR, HWIO_TZ_SDAM_PBUS_BIST_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBUS_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBUS_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBUS_BIST_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBUS_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBUS_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_PBUS_BIST_STATUS_BMSK                    0xff
#define HWIO_TZ_SDAM_PBUS_BIST_STATUS_PBUS_BIST_STATUS_SHFT                     0x0

#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_ADDR                               (SDAM01_BASE            + 0x0000006b)
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_OFFS                               0x0000006b
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_RMSK                                     0xff
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_STATUS_ADDR, HWIO_TZ_SDAM_SPMI_BIST_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_SPMI_BIST_STATUS_BMSK                    0xff
#define HWIO_TZ_SDAM_SPMI_BIST_STATUS_SPMI_BIST_STATUS_SHFT                     0x0

#define HWIO_TZ_SDAM_ABIST_STATUS_ADDR                                   (SDAM01_BASE            + 0x0000006c)
#define HWIO_TZ_SDAM_ABIST_STATUS_OFFS                                   0x0000006c
#define HWIO_TZ_SDAM_ABIST_STATUS_RMSK                                         0xff
#define HWIO_TZ_SDAM_ABIST_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_STATUS_ADDR, HWIO_TZ_SDAM_ABIST_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_ABIST_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ABIST_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ABIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_ABIST_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ABIST_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_ABIST_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ABIST_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_ABIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_ABIST_STATUS_ABIST_STATUS_BMSK                            0xff
#define HWIO_TZ_SDAM_ABIST_STATUS_ABIST_STATUS_SHFT                             0x0

#define HWIO_TZ_SDAM_ADC_BIST_STATUS_ADDR                                (SDAM01_BASE            + 0x0000006d)
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_OFFS                                0x0000006d
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_RMSK                                      0xff
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ADC_BIST_STATUS_ADDR, HWIO_TZ_SDAM_ADC_BIST_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ADC_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ADC_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ADC_BIST_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ADC_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_ADC_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_ADC_BIST_STATUS_BMSK                      0xff
#define HWIO_TZ_SDAM_ADC_BIST_STATUS_ADC_BIST_STATUS_SHFT                       0x0

#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_ADDR                             (SDAM01_BASE            + 0x0000006e)
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_OFFS                             0x0000006e
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_RMSK                                   0xff
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_STATUS_ADDR, HWIO_TZ_SDAM_FAULTN_BIST_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_FAULTN_BIST_STATUS_BMSK                0xff
#define HWIO_TZ_SDAM_FAULTN_BIST_STATUS_FAULTN_BIST_STATUS_SHFT                 0x0

#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_ADDR                             (SDAM01_BASE            + 0x0000006f)
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_OFFS                             0x0000006f
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_RMSK                                   0xff
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_ADDR, HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_PSHOLD_BIST_STATUS_BMSK                0xff
#define HWIO_TZ_SDAM_PSHOLD_BIST_STATUS_PSHOLD_BIST_STATUS_SHFT                 0x0

#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_ADDR                             (SDAM01_BASE            + 0x00000070)
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_OFFS                             0x00000070
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_RMSK                                   0xff
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_STATUS_ADDR, HWIO_TZ_SDAM_LMBIST_POLL_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_LMBIST_POLL_STATUS_BMSK                0xff
#define HWIO_TZ_SDAM_LMBIST_POLL_STATUS_LMBIST_POLL_STATUS_SHFT                 0x0

#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_ADDR                             (SDAM01_BASE            + 0x00000071)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_OFFS                             0x00000071
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_RMSK                                   0xff
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_ADDR, HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_ADDR, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_PBS_RAM_CRC_STATUS_BMSK                0xff
#define HWIO_TZ_SDAM_PBS_RAM_CRC_STATUS_PBS_RAM_CRC_STATUS_SHFT                 0x0

#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_ADDR                        (SDAM01_BASE            + 0x00000072)
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_OFFS                        0x00000072
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_RMSK                              0xff
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_ADDR, HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_RMSK, 0, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_ADDR, val, len)
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_ADDR, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_ADDR, val, len)
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_LMBIST_POLL_FAILING_SID_BMSK       0xff
#define HWIO_TZ_SDAM_LMBIST_POLL_FAILING_SID_LMBIST_POLL_FAILING_SID_SHFT        0x0

#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_ADDR                          (SDAM01_BASE            + 0x00000073)
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_OFFS                          0x00000073
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_RMSK                                0xff
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_ADDR, HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_RMSK, 0, val)
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_ADDR, val, len)
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_ADDR, val)
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_ADDR, val, len)
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_SPMI_BIST_FAILING_SID_BMSK          0xff
#define HWIO_TZ_SDAM_SPMI_BIST_FAILING_SID_SPMI_BIST_FAILING_SID_SHFT           0x0

#define HWIO_TZ_SDAM_BIST_FAIL_CODE_ADDR                                 (SDAM01_BASE            + 0x00000074)
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_OFFS                                 0x00000074
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_RMSK                                       0xff
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_BIST_FAIL_CODE_ADDR, HWIO_TZ_SDAM_BIST_FAIL_CODE_RMSK, 0, val)
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_BIST_FAIL_CODE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_BIST_FAIL_CODE_ADDR, val, len)
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_BIST_FAIL_CODE_ADDR, val)
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_BIST_FAIL_CODE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_BIST_FAIL_CODE_ADDR, val, len)
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_BIST_FAIL_CODE_BMSK                        0xff
#define HWIO_TZ_SDAM_BIST_FAIL_CODE_BIST_FAIL_CODE_SHFT                         0x0

#define HWIO_TZ_SDAM_PBS_NACK_REASON_ADDR                                (SDAM01_BASE            + 0x00000075)
#define HWIO_TZ_SDAM_PBS_NACK_REASON_OFFS                                0x00000075
#define HWIO_TZ_SDAM_PBS_NACK_REASON_RMSK                                      0xff
#define HWIO_TZ_SDAM_PBS_NACK_REASON_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_NACK_REASON_ADDR, HWIO_TZ_SDAM_PBS_NACK_REASON_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_NACK_REASON_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_NACK_REASON_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_NACK_REASON_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_NACK_REASON_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_NACK_REASON_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_NACK_REASON_ADDR, val)
#define HWIO_TZ_SDAM_PBS_NACK_REASON_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_NACK_REASON_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_NACK_REASON_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_NACK_REASON_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_NACK_REASON_PBS_NACK_REASON_BMSK                      0xff
#define HWIO_TZ_SDAM_PBS_NACK_REASON_PBS_NACK_REASON_SHFT                       0x0

#define HWIO_SDAM01_MEM_054_ADDR                                         (SDAM01_BASE            + 0x00000076)
#define HWIO_SDAM01_MEM_054_OFFS                                         0x00000076
#define HWIO_SDAM01_MEM_054_RMSK                                               0xff
#define HWIO_SDAM01_MEM_054_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_054_ADDR, HWIO_SDAM01_MEM_054_RMSK, 0, val)
#define HWIO_SDAM01_MEM_054_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_054_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_054_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_054_ADDR, val, len)
#define HWIO_SDAM01_MEM_054_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_054_ADDR, val)
#define HWIO_SDAM01_MEM_054_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_054_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_054_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_054_ADDR, val, len)
#define HWIO_SDAM01_MEM_054_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_054_DATA_SHFT                                           0x0

#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_ADDR                           (SDAM01_BASE            + 0x00000077)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_OFFS                           0x00000077
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_RMSK                                 0xff
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_ADDR, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_ADDR, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_PBS_OTP_CRC_CODE_LSB_BMSK            0xff
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_LSB_PBS_OTP_CRC_CODE_LSB_SHFT             0x0

#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_ADDR                           (SDAM01_BASE            + 0x00000078)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_OFFS                           0x00000078
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_RMSK                                 0xff
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_ADDR, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_ADDR, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_PBS_OTP_CRC_CODE_MSB_BMSK            0xff
#define HWIO_TZ_SDAM_PBS_OTP_CRC_CODE_MSB_PBS_OTP_CRC_CODE_MSB_SHFT             0x0

#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_ADDR                    (SDAM01_BASE            + 0x00000079)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_OFFS                    0x00000079
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_RMSK                          0xff
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_ADDR, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_RMSK, 0, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_ADDR, val, len)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_ADDR, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_ADDR, val, len)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_MM_VREF_1P25_ADC_CONV_DATA0_BMSK       0xff
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA0_MM_VREF_1P25_ADC_CONV_DATA0_SHFT        0x0

#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_ADDR                    (SDAM01_BASE            + 0x0000007a)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_OFFS                    0x0000007a
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_RMSK                          0xff
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_ADDR, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_RMSK, 0, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_ADDR, val, len)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_ADDR, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_ADDR, val, len)
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_MM_VREF_1P25_ADC_CONV_DATA1_BMSK       0xff
#define HWIO_TZ_SDAM_MM_VREF_1P25_ADC_CONV_DATA1_MM_VREF_1P25_ADC_CONV_DATA1_SHFT        0x0

#define HWIO_TZ_SDAM_ABIST_FAIL_PID_ADDR                                 (SDAM01_BASE            + 0x0000007b)
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_OFFS                                 0x0000007b
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_RMSK                                       0xff
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_PID_ADDR, HWIO_TZ_SDAM_ABIST_FAIL_PID_RMSK, 0, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_PID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_PID_ADDR, val, len)
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_PID_ADDR, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_PID_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_PID_ADDR, val, len)
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_ABIST_FAIL_PID_BMSK                        0xff
#define HWIO_TZ_SDAM_ABIST_FAIL_PID_ABIST_FAIL_PID_SHFT                         0x0

#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ADDR                              (SDAM01_BASE            + 0x0000007c)
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_OFFS                              0x0000007c
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_RMSK                                    0xff
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ADDR, HWIO_TZ_SDAM_ABIST_FAIL_RESULT_RMSK, 0, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ADDR, val, len)
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ADDR, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ADDR, val, len)
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ABIST_FAIL_RESULT_BMSK                  0xff
#define HWIO_TZ_SDAM_ABIST_FAIL_RESULT_ABIST_FAIL_RESULT_SHFT                   0x0

#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_ADDR                           (SDAM01_BASE            + 0x0000007d)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_OFFS                           0x0000007d
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_RMSK                                 0xff
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_ADDR, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_ADDR, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_PBS_RAM_CRC_CODE_LSB_BMSK            0xff
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_LSB_PBS_RAM_CRC_CODE_LSB_SHFT             0x0

#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_ADDR                           (SDAM01_BASE            + 0x0000007e)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_OFFS                           0x0000007e
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_RMSK                                 0xff
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_ADDR, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_ADDR, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_PBS_RAM_CRC_CODE_MSB_BMSK            0xff
#define HWIO_TZ_SDAM_PBS_RAM_CRC_CODE_MSB_PBS_RAM_CRC_CODE_MSB_SHFT             0x0

#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_ADDR                           (SDAM01_BASE            + 0x0000007f)
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_OFFS                           0x0000007f
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_RMSK                                 0xff
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_ADDR, HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_RMSK, 0, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_ADDR, val, len)
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_ADDR, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_ADDR, val, len)
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_FAULTN_BIST_ERR_CODE_BMSK            0xff
#define HWIO_TZ_SDAM_FAULTN_BIST_ERR_CODE_FAULTN_BIST_ERR_CODE_SHFT             0x0

#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_ADDR                       (SDAM01_BASE            + 0x00000080)
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_OFFS                       0x00000080
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_RMSK                             0xff
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_ADDR, HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_RMSK, 0, val)
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_ADDR, val, len)
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_ADDR, val)
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_ADDR, val, len)
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_WRITE_READ_VERIFY_RESULT_BMSK       0xff
#define HWIO_TZ_SDAM_WRITE_READ_VERIFY_RESULT_WRITE_READ_VERIFY_RESULT_SHFT        0x0

#define HWIO_SDAM01_MEM_065_ADDR                                         (SDAM01_BASE            + 0x00000081)
#define HWIO_SDAM01_MEM_065_OFFS                                         0x00000081
#define HWIO_SDAM01_MEM_065_RMSK                                               0xff
#define HWIO_SDAM01_MEM_065_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_065_ADDR, HWIO_SDAM01_MEM_065_RMSK, 0, val)
#define HWIO_SDAM01_MEM_065_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_065_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_065_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_065_ADDR, val, len)
#define HWIO_SDAM01_MEM_065_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_065_ADDR, val)
#define HWIO_SDAM01_MEM_065_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_065_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_065_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_065_ADDR, val, len)
#define HWIO_SDAM01_MEM_065_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_065_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_066_ADDR                                         (SDAM01_BASE            + 0x00000082)
#define HWIO_SDAM01_MEM_066_OFFS                                         0x00000082
#define HWIO_SDAM01_MEM_066_RMSK                                               0xff
#define HWIO_SDAM01_MEM_066_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_066_ADDR, HWIO_SDAM01_MEM_066_RMSK, 0, val)
#define HWIO_SDAM01_MEM_066_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_066_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_066_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_066_ADDR, val, len)
#define HWIO_SDAM01_MEM_066_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_066_ADDR, val)
#define HWIO_SDAM01_MEM_066_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_066_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_066_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_066_ADDR, val, len)
#define HWIO_SDAM01_MEM_066_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_066_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_067_ADDR                                         (SDAM01_BASE            + 0x00000083)
#define HWIO_SDAM01_MEM_067_OFFS                                         0x00000083
#define HWIO_SDAM01_MEM_067_RMSK                                               0xff
#define HWIO_SDAM01_MEM_067_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_067_ADDR, HWIO_SDAM01_MEM_067_RMSK, 0, val)
#define HWIO_SDAM01_MEM_067_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_067_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_067_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_067_ADDR, val, len)
#define HWIO_SDAM01_MEM_067_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_067_ADDR, val)
#define HWIO_SDAM01_MEM_067_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_067_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_067_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_067_ADDR, val, len)
#define HWIO_SDAM01_MEM_067_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_067_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_068_ADDR                                         (SDAM01_BASE            + 0x00000084)
#define HWIO_SDAM01_MEM_068_OFFS                                         0x00000084
#define HWIO_SDAM01_MEM_068_RMSK                                               0xff
#define HWIO_SDAM01_MEM_068_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_068_ADDR, HWIO_SDAM01_MEM_068_RMSK, 0, val)
#define HWIO_SDAM01_MEM_068_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_068_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_068_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_068_ADDR, val, len)
#define HWIO_SDAM01_MEM_068_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_068_ADDR, val)
#define HWIO_SDAM01_MEM_068_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_068_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_068_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_068_ADDR, val, len)
#define HWIO_SDAM01_MEM_068_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_068_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_069_ADDR                                         (SDAM01_BASE            + 0x00000085)
#define HWIO_SDAM01_MEM_069_OFFS                                         0x00000085
#define HWIO_SDAM01_MEM_069_RMSK                                               0xff
#define HWIO_SDAM01_MEM_069_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_069_ADDR, HWIO_SDAM01_MEM_069_RMSK, 0, val)
#define HWIO_SDAM01_MEM_069_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_069_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_069_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_069_ADDR, val, len)
#define HWIO_SDAM01_MEM_069_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_069_ADDR, val)
#define HWIO_SDAM01_MEM_069_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_069_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_069_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_069_ADDR, val, len)
#define HWIO_SDAM01_MEM_069_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_069_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_070_ADDR                                         (SDAM01_BASE            + 0x00000086)
#define HWIO_SDAM01_MEM_070_OFFS                                         0x00000086
#define HWIO_SDAM01_MEM_070_RMSK                                               0xff
#define HWIO_SDAM01_MEM_070_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_070_ADDR, HWIO_SDAM01_MEM_070_RMSK, 0, val)
#define HWIO_SDAM01_MEM_070_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_070_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_070_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_070_ADDR, val, len)
#define HWIO_SDAM01_MEM_070_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_070_ADDR, val)
#define HWIO_SDAM01_MEM_070_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_070_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_070_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_070_ADDR, val, len)
#define HWIO_SDAM01_MEM_070_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_070_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_071_ADDR                                         (SDAM01_BASE            + 0x00000087)
#define HWIO_SDAM01_MEM_071_OFFS                                         0x00000087
#define HWIO_SDAM01_MEM_071_RMSK                                               0xff
#define HWIO_SDAM01_MEM_071_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_071_ADDR, HWIO_SDAM01_MEM_071_RMSK, 0, val)
#define HWIO_SDAM01_MEM_071_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_071_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_071_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_071_ADDR, val, len)
#define HWIO_SDAM01_MEM_071_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_071_ADDR, val)
#define HWIO_SDAM01_MEM_071_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_071_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_071_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_071_ADDR, val, len)
#define HWIO_SDAM01_MEM_071_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_071_DATA_SHFT                                           0x0

#define HWIO_TZ_SDAM_OTP_VERSION_ADDR                                    (SDAM01_BASE            + 0x00000088)
#define HWIO_TZ_SDAM_OTP_VERSION_OFFS                                    0x00000088
#define HWIO_TZ_SDAM_OTP_VERSION_RMSK                                          0xff
#define HWIO_TZ_SDAM_OTP_VERSION_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_OTP_VERSION_ADDR, HWIO_TZ_SDAM_OTP_VERSION_RMSK, 0, val)
#define HWIO_TZ_SDAM_OTP_VERSION_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_OTP_VERSION_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_OTP_VERSION_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_OTP_VERSION_ADDR, val, len)
#define HWIO_TZ_SDAM_OTP_VERSION_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_OTP_VERSION_ADDR, val)
#define HWIO_TZ_SDAM_OTP_VERSION_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_OTP_VERSION_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_OTP_VERSION_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_OTP_VERSION_ADDR, val, len)
#define HWIO_TZ_SDAM_OTP_VERSION_OTP_VERSION_BMSK                              0xff
#define HWIO_TZ_SDAM_OTP_VERSION_OTP_VERSION_SHFT                               0x0

#define HWIO_TZ_SDAM_OTP_BRANCH_ADDR                                     (SDAM01_BASE            + 0x00000089)
#define HWIO_TZ_SDAM_OTP_BRANCH_OFFS                                     0x00000089
#define HWIO_TZ_SDAM_OTP_BRANCH_RMSK                                           0xff
#define HWIO_TZ_SDAM_OTP_BRANCH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_OTP_BRANCH_ADDR, HWIO_TZ_SDAM_OTP_BRANCH_RMSK, 0, val)
#define HWIO_TZ_SDAM_OTP_BRANCH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_OTP_BRANCH_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_OTP_BRANCH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_OTP_BRANCH_ADDR, val, len)
#define HWIO_TZ_SDAM_OTP_BRANCH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_OTP_BRANCH_ADDR, val)
#define HWIO_TZ_SDAM_OTP_BRANCH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_OTP_BRANCH_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_OTP_BRANCH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_OTP_BRANCH_ADDR, val, len)
#define HWIO_TZ_SDAM_OTP_BRANCH_OTP_BRANCH_BMSK                                0xff
#define HWIO_TZ_SDAM_OTP_BRANCH_OTP_BRANCH_SHFT                                 0x0

#define HWIO_TZ_SDAM_RAM_VERSION_ADDR                                    (SDAM01_BASE            + 0x0000008a)
#define HWIO_TZ_SDAM_RAM_VERSION_OFFS                                    0x0000008a
#define HWIO_TZ_SDAM_RAM_VERSION_RMSK                                          0xff
#define HWIO_TZ_SDAM_RAM_VERSION_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_RAM_VERSION_ADDR, HWIO_TZ_SDAM_RAM_VERSION_RMSK, 0, val)
#define HWIO_TZ_SDAM_RAM_VERSION_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_RAM_VERSION_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_RAM_VERSION_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_RAM_VERSION_ADDR, val, len)
#define HWIO_TZ_SDAM_RAM_VERSION_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_RAM_VERSION_ADDR, val)
#define HWIO_TZ_SDAM_RAM_VERSION_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_RAM_VERSION_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_RAM_VERSION_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_RAM_VERSION_ADDR, val, len)
#define HWIO_TZ_SDAM_RAM_VERSION_RAM_VERSION_BMSK                              0xff
#define HWIO_TZ_SDAM_RAM_VERSION_RAM_VERSION_SHFT                               0x0

#define HWIO_SDAM01_MEM_075_ADDR                                         (SDAM01_BASE            + 0x0000008b)
#define HWIO_SDAM01_MEM_075_OFFS                                         0x0000008b
#define HWIO_SDAM01_MEM_075_RMSK                                               0xff
#define HWIO_SDAM01_MEM_075_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_075_ADDR, HWIO_SDAM01_MEM_075_RMSK, 0, val)
#define HWIO_SDAM01_MEM_075_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_075_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_075_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_075_ADDR, val, len)
#define HWIO_SDAM01_MEM_075_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_075_ADDR, val)
#define HWIO_SDAM01_MEM_075_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_075_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_075_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_075_ADDR, val, len)
#define HWIO_SDAM01_MEM_075_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_075_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_076_ADDR                                         (SDAM01_BASE            + 0x0000008c)
#define HWIO_SDAM01_MEM_076_OFFS                                         0x0000008c
#define HWIO_SDAM01_MEM_076_RMSK                                               0xff
#define HWIO_SDAM01_MEM_076_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_076_ADDR, HWIO_SDAM01_MEM_076_RMSK, 0, val)
#define HWIO_SDAM01_MEM_076_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_076_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_076_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_076_ADDR, val, len)
#define HWIO_SDAM01_MEM_076_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_076_ADDR, val)
#define HWIO_SDAM01_MEM_076_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_076_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_076_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_076_ADDR, val, len)
#define HWIO_SDAM01_MEM_076_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_076_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_077_ADDR                                         (SDAM01_BASE            + 0x0000008d)
#define HWIO_SDAM01_MEM_077_OFFS                                         0x0000008d
#define HWIO_SDAM01_MEM_077_RMSK                                               0xff
#define HWIO_SDAM01_MEM_077_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_077_ADDR, HWIO_SDAM01_MEM_077_RMSK, 0, val)
#define HWIO_SDAM01_MEM_077_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_077_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_077_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_077_ADDR, val, len)
#define HWIO_SDAM01_MEM_077_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_077_ADDR, val)
#define HWIO_SDAM01_MEM_077_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_077_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_077_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_077_ADDR, val, len)
#define HWIO_SDAM01_MEM_077_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_077_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_078_ADDR                                         (SDAM01_BASE            + 0x0000008e)
#define HWIO_SDAM01_MEM_078_OFFS                                         0x0000008e
#define HWIO_SDAM01_MEM_078_RMSK                                               0xff
#define HWIO_SDAM01_MEM_078_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_078_ADDR, HWIO_SDAM01_MEM_078_RMSK, 0, val)
#define HWIO_SDAM01_MEM_078_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_078_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_078_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_078_ADDR, val, len)
#define HWIO_SDAM01_MEM_078_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_078_ADDR, val)
#define HWIO_SDAM01_MEM_078_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_078_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_078_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_078_ADDR, val, len)
#define HWIO_SDAM01_MEM_078_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_078_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_079_ADDR                                         (SDAM01_BASE            + 0x0000008f)
#define HWIO_SDAM01_MEM_079_OFFS                                         0x0000008f
#define HWIO_SDAM01_MEM_079_RMSK                                               0xff
#define HWIO_SDAM01_MEM_079_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_079_ADDR, HWIO_SDAM01_MEM_079_RMSK, 0, val)
#define HWIO_SDAM01_MEM_079_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_079_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_079_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_079_ADDR, val, len)
#define HWIO_SDAM01_MEM_079_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_079_ADDR, val)
#define HWIO_SDAM01_MEM_079_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_079_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_079_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_079_ADDR, val, len)
#define HWIO_SDAM01_MEM_079_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_079_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_080_ADDR                                         (SDAM01_BASE            + 0x00000090)
#define HWIO_SDAM01_MEM_080_OFFS                                         0x00000090
#define HWIO_SDAM01_MEM_080_RMSK                                               0xff
#define HWIO_SDAM01_MEM_080_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_080_ADDR, HWIO_SDAM01_MEM_080_RMSK, 0, val)
#define HWIO_SDAM01_MEM_080_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_080_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_080_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_080_ADDR, val, len)
#define HWIO_SDAM01_MEM_080_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_080_ADDR, val)
#define HWIO_SDAM01_MEM_080_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_080_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_080_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_080_ADDR, val, len)
#define HWIO_SDAM01_MEM_080_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_080_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_081_ADDR                                         (SDAM01_BASE            + 0x00000091)
#define HWIO_SDAM01_MEM_081_OFFS                                         0x00000091
#define HWIO_SDAM01_MEM_081_RMSK                                               0xff
#define HWIO_SDAM01_MEM_081_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_081_ADDR, HWIO_SDAM01_MEM_081_RMSK, 0, val)
#define HWIO_SDAM01_MEM_081_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_081_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_081_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_081_ADDR, val, len)
#define HWIO_SDAM01_MEM_081_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_081_ADDR, val)
#define HWIO_SDAM01_MEM_081_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_081_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_081_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_081_ADDR, val, len)
#define HWIO_SDAM01_MEM_081_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_081_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_082_ADDR                                         (SDAM01_BASE            + 0x00000092)
#define HWIO_SDAM01_MEM_082_OFFS                                         0x00000092
#define HWIO_SDAM01_MEM_082_RMSK                                               0xff
#define HWIO_SDAM01_MEM_082_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_082_ADDR, HWIO_SDAM01_MEM_082_RMSK, 0, val)
#define HWIO_SDAM01_MEM_082_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_082_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_082_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_082_ADDR, val, len)
#define HWIO_SDAM01_MEM_082_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_082_ADDR, val)
#define HWIO_SDAM01_MEM_082_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_082_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_082_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_082_ADDR, val, len)
#define HWIO_SDAM01_MEM_082_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_082_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_083_ADDR                                         (SDAM01_BASE            + 0x00000093)
#define HWIO_SDAM01_MEM_083_OFFS                                         0x00000093
#define HWIO_SDAM01_MEM_083_RMSK                                               0xff
#define HWIO_SDAM01_MEM_083_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_083_ADDR, HWIO_SDAM01_MEM_083_RMSK, 0, val)
#define HWIO_SDAM01_MEM_083_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_083_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_083_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_083_ADDR, val, len)
#define HWIO_SDAM01_MEM_083_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_083_ADDR, val)
#define HWIO_SDAM01_MEM_083_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_083_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_083_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_083_ADDR, val, len)
#define HWIO_SDAM01_MEM_083_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_083_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_084_ADDR                                         (SDAM01_BASE            + 0x00000094)
#define HWIO_SDAM01_MEM_084_OFFS                                         0x00000094
#define HWIO_SDAM01_MEM_084_RMSK                                               0xff
#define HWIO_SDAM01_MEM_084_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_084_ADDR, HWIO_SDAM01_MEM_084_RMSK, 0, val)
#define HWIO_SDAM01_MEM_084_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_084_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_084_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_084_ADDR, val, len)
#define HWIO_SDAM01_MEM_084_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_084_ADDR, val)
#define HWIO_SDAM01_MEM_084_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_084_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_084_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_084_ADDR, val, len)
#define HWIO_SDAM01_MEM_084_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_084_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_085_ADDR                                         (SDAM01_BASE            + 0x00000095)
#define HWIO_SDAM01_MEM_085_OFFS                                         0x00000095
#define HWIO_SDAM01_MEM_085_RMSK                                               0xff
#define HWIO_SDAM01_MEM_085_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_085_ADDR, HWIO_SDAM01_MEM_085_RMSK, 0, val)
#define HWIO_SDAM01_MEM_085_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_085_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_085_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_085_ADDR, val, len)
#define HWIO_SDAM01_MEM_085_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_085_ADDR, val)
#define HWIO_SDAM01_MEM_085_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_085_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_085_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_085_ADDR, val, len)
#define HWIO_SDAM01_MEM_085_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_085_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_086_ADDR                                         (SDAM01_BASE            + 0x00000096)
#define HWIO_SDAM01_MEM_086_OFFS                                         0x00000096
#define HWIO_SDAM01_MEM_086_RMSK                                               0xff
#define HWIO_SDAM01_MEM_086_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_086_ADDR, HWIO_SDAM01_MEM_086_RMSK, 0, val)
#define HWIO_SDAM01_MEM_086_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_086_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_086_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_086_ADDR, val, len)
#define HWIO_SDAM01_MEM_086_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_086_ADDR, val)
#define HWIO_SDAM01_MEM_086_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_086_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_086_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_086_ADDR, val, len)
#define HWIO_SDAM01_MEM_086_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_086_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_087_ADDR                                         (SDAM01_BASE            + 0x00000097)
#define HWIO_SDAM01_MEM_087_OFFS                                         0x00000097
#define HWIO_SDAM01_MEM_087_RMSK                                               0xff
#define HWIO_SDAM01_MEM_087_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_087_ADDR, HWIO_SDAM01_MEM_087_RMSK, 0, val)
#define HWIO_SDAM01_MEM_087_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_087_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_087_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_087_ADDR, val, len)
#define HWIO_SDAM01_MEM_087_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_087_ADDR, val)
#define HWIO_SDAM01_MEM_087_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_087_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_087_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_087_ADDR, val, len)
#define HWIO_SDAM01_MEM_087_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_087_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_088_ADDR                                         (SDAM01_BASE            + 0x00000098)
#define HWIO_SDAM01_MEM_088_OFFS                                         0x00000098
#define HWIO_SDAM01_MEM_088_RMSK                                               0xff
#define HWIO_SDAM01_MEM_088_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_088_ADDR, HWIO_SDAM01_MEM_088_RMSK, 0, val)
#define HWIO_SDAM01_MEM_088_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_088_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_088_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_088_ADDR, val, len)
#define HWIO_SDAM01_MEM_088_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_088_ADDR, val)
#define HWIO_SDAM01_MEM_088_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_088_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_088_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_088_ADDR, val, len)
#define HWIO_SDAM01_MEM_088_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_088_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_089_ADDR                                         (SDAM01_BASE            + 0x00000099)
#define HWIO_SDAM01_MEM_089_OFFS                                         0x00000099
#define HWIO_SDAM01_MEM_089_RMSK                                               0xff
#define HWIO_SDAM01_MEM_089_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_089_ADDR, HWIO_SDAM01_MEM_089_RMSK, 0, val)
#define HWIO_SDAM01_MEM_089_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_089_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_089_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_089_ADDR, val, len)
#define HWIO_SDAM01_MEM_089_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_089_ADDR, val)
#define HWIO_SDAM01_MEM_089_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_089_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_089_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_089_ADDR, val, len)
#define HWIO_SDAM01_MEM_089_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_089_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_090_ADDR                                         (SDAM01_BASE            + 0x0000009a)
#define HWIO_SDAM01_MEM_090_OFFS                                         0x0000009a
#define HWIO_SDAM01_MEM_090_RMSK                                               0xff
#define HWIO_SDAM01_MEM_090_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_090_ADDR, HWIO_SDAM01_MEM_090_RMSK, 0, val)
#define HWIO_SDAM01_MEM_090_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_090_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_090_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_090_ADDR, val, len)
#define HWIO_SDAM01_MEM_090_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_090_ADDR, val)
#define HWIO_SDAM01_MEM_090_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_090_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_090_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_090_ADDR, val, len)
#define HWIO_SDAM01_MEM_090_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_090_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_091_ADDR                                         (SDAM01_BASE            + 0x0000009b)
#define HWIO_SDAM01_MEM_091_OFFS                                         0x0000009b
#define HWIO_SDAM01_MEM_091_RMSK                                               0xff
#define HWIO_SDAM01_MEM_091_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_091_ADDR, HWIO_SDAM01_MEM_091_RMSK, 0, val)
#define HWIO_SDAM01_MEM_091_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_091_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_091_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_091_ADDR, val, len)
#define HWIO_SDAM01_MEM_091_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_091_ADDR, val)
#define HWIO_SDAM01_MEM_091_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_091_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_091_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_091_ADDR, val, len)
#define HWIO_SDAM01_MEM_091_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_091_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_092_ADDR                                         (SDAM01_BASE            + 0x0000009c)
#define HWIO_SDAM01_MEM_092_OFFS                                         0x0000009c
#define HWIO_SDAM01_MEM_092_RMSK                                               0xff
#define HWIO_SDAM01_MEM_092_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_092_ADDR, HWIO_SDAM01_MEM_092_RMSK, 0, val)
#define HWIO_SDAM01_MEM_092_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_092_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_092_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_092_ADDR, val, len)
#define HWIO_SDAM01_MEM_092_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_092_ADDR, val)
#define HWIO_SDAM01_MEM_092_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_092_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_092_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_092_ADDR, val, len)
#define HWIO_SDAM01_MEM_092_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_092_DATA_SHFT                                           0x0

#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ADDR                             (SDAM01_BASE            + 0x0000009d)
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_OFFS                             0x0000009d
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_RMSK                                   0xff
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ADDR, HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_RMSK, 0, val)
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ADDR, val, len)
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ADDR, val)
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ADDR, val, len)
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ISR_LOGGING_ENABLE_BMSK                0xff
#define HWIO_TZ_SDAM_ISR_LOGGING_ENABLE_ISR_LOGGING_ENABLE_SHFT                 0x0

#define HWIO_SDAM01_MEM_094_ADDR                                         (SDAM01_BASE            + 0x0000009e)
#define HWIO_SDAM01_MEM_094_OFFS                                         0x0000009e
#define HWIO_SDAM01_MEM_094_RMSK                                               0xff
#define HWIO_SDAM01_MEM_094_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_094_ADDR, HWIO_SDAM01_MEM_094_RMSK, 0, val)
#define HWIO_SDAM01_MEM_094_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_094_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_094_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_094_ADDR, val, len)
#define HWIO_SDAM01_MEM_094_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_094_ADDR, val)
#define HWIO_SDAM01_MEM_094_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_094_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_094_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_094_ADDR, val, len)
#define HWIO_SDAM01_MEM_094_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_094_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_095_ADDR                                         (SDAM01_BASE            + 0x0000009f)
#define HWIO_SDAM01_MEM_095_OFFS                                         0x0000009f
#define HWIO_SDAM01_MEM_095_RMSK                                               0xff
#define HWIO_SDAM01_MEM_095_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_095_ADDR, HWIO_SDAM01_MEM_095_RMSK, 0, val)
#define HWIO_SDAM01_MEM_095_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_095_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_095_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_095_ADDR, val, len)
#define HWIO_SDAM01_MEM_095_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_095_ADDR, val)
#define HWIO_SDAM01_MEM_095_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_095_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_095_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_095_ADDR, val, len)
#define HWIO_SDAM01_MEM_095_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_095_DATA_SHFT                                           0x0

#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_ADDR                            (SDAM01_BASE            + 0x000000a0)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_OFFS                            0x000000a0
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_RMSK                                  0xff
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_ADDR, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_ADDR, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_PBS1_ERR_PC_STATUS0_BMSK              0xff
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS0_PBS1_ERR_PC_STATUS0_SHFT               0x0

#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_ADDR                            (SDAM01_BASE            + 0x000000a1)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_OFFS                            0x000000a1
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_RMSK                                  0xff
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_ADDR, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_RMSK, 0, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_ADDR, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_ADDR, mask, shift, val)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_ADDR, val, len)
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_PBS1_ERR_PC_STATUS1_BMSK              0xff
#define HWIO_TZ_SDAM_PBS1_ERR_PC_STATUS1_PBS1_ERR_PC_STATUS1_SHFT               0x0

#define HWIO_SDAM01_MEM_098_ADDR                                         (SDAM01_BASE            + 0x000000a2)
#define HWIO_SDAM01_MEM_098_OFFS                                         0x000000a2
#define HWIO_SDAM01_MEM_098_RMSK                                               0xff
#define HWIO_SDAM01_MEM_098_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_098_ADDR, HWIO_SDAM01_MEM_098_RMSK, 0, val)
#define HWIO_SDAM01_MEM_098_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_098_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_098_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_098_ADDR, val, len)
#define HWIO_SDAM01_MEM_098_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_098_ADDR, val)
#define HWIO_SDAM01_MEM_098_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_098_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_098_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_098_ADDR, val, len)
#define HWIO_SDAM01_MEM_098_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_098_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_099_ADDR                                         (SDAM01_BASE            + 0x000000a3)
#define HWIO_SDAM01_MEM_099_OFFS                                         0x000000a3
#define HWIO_SDAM01_MEM_099_RMSK                                               0xff
#define HWIO_SDAM01_MEM_099_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_099_ADDR, HWIO_SDAM01_MEM_099_RMSK, 0, val)
#define HWIO_SDAM01_MEM_099_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_099_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_099_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_099_ADDR, val, len)
#define HWIO_SDAM01_MEM_099_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_099_ADDR, val)
#define HWIO_SDAM01_MEM_099_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_099_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_099_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_099_ADDR, val, len)
#define HWIO_SDAM01_MEM_099_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_099_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_100_ADDR                                         (SDAM01_BASE            + 0x000000a4)
#define HWIO_SDAM01_MEM_100_OFFS                                         0x000000a4
#define HWIO_SDAM01_MEM_100_RMSK                                               0xff
#define HWIO_SDAM01_MEM_100_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_100_ADDR, HWIO_SDAM01_MEM_100_RMSK, 0, val)
#define HWIO_SDAM01_MEM_100_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_100_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_100_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_100_ADDR, val, len)
#define HWIO_SDAM01_MEM_100_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_100_ADDR, val)
#define HWIO_SDAM01_MEM_100_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_100_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_100_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_100_ADDR, val, len)
#define HWIO_SDAM01_MEM_100_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_100_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_101_ADDR                                         (SDAM01_BASE            + 0x000000a5)
#define HWIO_SDAM01_MEM_101_OFFS                                         0x000000a5
#define HWIO_SDAM01_MEM_101_RMSK                                               0xff
#define HWIO_SDAM01_MEM_101_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_101_ADDR, HWIO_SDAM01_MEM_101_RMSK, 0, val)
#define HWIO_SDAM01_MEM_101_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_101_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_101_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_101_ADDR, val, len)
#define HWIO_SDAM01_MEM_101_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_101_ADDR, val)
#define HWIO_SDAM01_MEM_101_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_101_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_101_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_101_ADDR, val, len)
#define HWIO_SDAM01_MEM_101_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_101_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_102_ADDR                                         (SDAM01_BASE            + 0x000000a6)
#define HWIO_SDAM01_MEM_102_OFFS                                         0x000000a6
#define HWIO_SDAM01_MEM_102_RMSK                                               0xff
#define HWIO_SDAM01_MEM_102_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_102_ADDR, HWIO_SDAM01_MEM_102_RMSK, 0, val)
#define HWIO_SDAM01_MEM_102_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_102_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_102_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_102_ADDR, val, len)
#define HWIO_SDAM01_MEM_102_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_102_ADDR, val)
#define HWIO_SDAM01_MEM_102_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_102_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_102_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_102_ADDR, val, len)
#define HWIO_SDAM01_MEM_102_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_102_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_103_ADDR                                         (SDAM01_BASE            + 0x000000a7)
#define HWIO_SDAM01_MEM_103_OFFS                                         0x000000a7
#define HWIO_SDAM01_MEM_103_RMSK                                               0xff
#define HWIO_SDAM01_MEM_103_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_103_ADDR, HWIO_SDAM01_MEM_103_RMSK, 0, val)
#define HWIO_SDAM01_MEM_103_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_103_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_103_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_103_ADDR, val, len)
#define HWIO_SDAM01_MEM_103_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_103_ADDR, val)
#define HWIO_SDAM01_MEM_103_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_103_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_103_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_103_ADDR, val, len)
#define HWIO_SDAM01_MEM_103_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_103_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_104_ADDR                                         (SDAM01_BASE            + 0x000000a8)
#define HWIO_SDAM01_MEM_104_OFFS                                         0x000000a8
#define HWIO_SDAM01_MEM_104_RMSK                                               0xff
#define HWIO_SDAM01_MEM_104_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_104_ADDR, HWIO_SDAM01_MEM_104_RMSK, 0, val)
#define HWIO_SDAM01_MEM_104_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_104_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_104_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_104_ADDR, val, len)
#define HWIO_SDAM01_MEM_104_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_104_ADDR, val)
#define HWIO_SDAM01_MEM_104_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_104_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_104_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_104_ADDR, val, len)
#define HWIO_SDAM01_MEM_104_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_104_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_105_ADDR                                         (SDAM01_BASE            + 0x000000a9)
#define HWIO_SDAM01_MEM_105_OFFS                                         0x000000a9
#define HWIO_SDAM01_MEM_105_RMSK                                               0xff
#define HWIO_SDAM01_MEM_105_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_105_ADDR, HWIO_SDAM01_MEM_105_RMSK, 0, val)
#define HWIO_SDAM01_MEM_105_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_105_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_105_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_105_ADDR, val, len)
#define HWIO_SDAM01_MEM_105_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_105_ADDR, val)
#define HWIO_SDAM01_MEM_105_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_105_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_105_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_105_ADDR, val, len)
#define HWIO_SDAM01_MEM_105_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_105_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_106_ADDR                                         (SDAM01_BASE            + 0x000000aa)
#define HWIO_SDAM01_MEM_106_OFFS                                         0x000000aa
#define HWIO_SDAM01_MEM_106_RMSK                                               0xff
#define HWIO_SDAM01_MEM_106_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_106_ADDR, HWIO_SDAM01_MEM_106_RMSK, 0, val)
#define HWIO_SDAM01_MEM_106_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_106_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_106_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_106_ADDR, val, len)
#define HWIO_SDAM01_MEM_106_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_106_ADDR, val)
#define HWIO_SDAM01_MEM_106_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_106_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_106_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_106_ADDR, val, len)
#define HWIO_SDAM01_MEM_106_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_106_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_107_ADDR                                         (SDAM01_BASE            + 0x000000ab)
#define HWIO_SDAM01_MEM_107_OFFS                                         0x000000ab
#define HWIO_SDAM01_MEM_107_RMSK                                               0xff
#define HWIO_SDAM01_MEM_107_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_107_ADDR, HWIO_SDAM01_MEM_107_RMSK, 0, val)
#define HWIO_SDAM01_MEM_107_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_107_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_107_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_107_ADDR, val, len)
#define HWIO_SDAM01_MEM_107_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_107_ADDR, val)
#define HWIO_SDAM01_MEM_107_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_107_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_107_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_107_ADDR, val, len)
#define HWIO_SDAM01_MEM_107_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_107_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_108_ADDR                                         (SDAM01_BASE            + 0x000000ac)
#define HWIO_SDAM01_MEM_108_OFFS                                         0x000000ac
#define HWIO_SDAM01_MEM_108_RMSK                                               0xff
#define HWIO_SDAM01_MEM_108_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_108_ADDR, HWIO_SDAM01_MEM_108_RMSK, 0, val)
#define HWIO_SDAM01_MEM_108_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_108_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_108_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_108_ADDR, val, len)
#define HWIO_SDAM01_MEM_108_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_108_ADDR, val)
#define HWIO_SDAM01_MEM_108_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_108_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_108_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_108_ADDR, val, len)
#define HWIO_SDAM01_MEM_108_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_108_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_109_ADDR                                         (SDAM01_BASE            + 0x000000ad)
#define HWIO_SDAM01_MEM_109_OFFS                                         0x000000ad
#define HWIO_SDAM01_MEM_109_RMSK                                               0xff
#define HWIO_SDAM01_MEM_109_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_109_ADDR, HWIO_SDAM01_MEM_109_RMSK, 0, val)
#define HWIO_SDAM01_MEM_109_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_109_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_109_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_109_ADDR, val, len)
#define HWIO_SDAM01_MEM_109_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_109_ADDR, val)
#define HWIO_SDAM01_MEM_109_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_109_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_109_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_109_ADDR, val, len)
#define HWIO_SDAM01_MEM_109_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_109_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_110_ADDR                                         (SDAM01_BASE            + 0x000000ae)
#define HWIO_SDAM01_MEM_110_OFFS                                         0x000000ae
#define HWIO_SDAM01_MEM_110_RMSK                                               0xff
#define HWIO_SDAM01_MEM_110_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_110_ADDR, HWIO_SDAM01_MEM_110_RMSK, 0, val)
#define HWIO_SDAM01_MEM_110_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_110_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_110_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_110_ADDR, val, len)
#define HWIO_SDAM01_MEM_110_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_110_ADDR, val)
#define HWIO_SDAM01_MEM_110_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_110_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_110_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_110_ADDR, val, len)
#define HWIO_SDAM01_MEM_110_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_110_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_111_ADDR                                         (SDAM01_BASE            + 0x000000af)
#define HWIO_SDAM01_MEM_111_OFFS                                         0x000000af
#define HWIO_SDAM01_MEM_111_RMSK                                               0xff
#define HWIO_SDAM01_MEM_111_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_111_ADDR, HWIO_SDAM01_MEM_111_RMSK, 0, val)
#define HWIO_SDAM01_MEM_111_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_111_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_111_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_111_ADDR, val, len)
#define HWIO_SDAM01_MEM_111_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_111_ADDR, val)
#define HWIO_SDAM01_MEM_111_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_111_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_111_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_111_ADDR, val, len)
#define HWIO_SDAM01_MEM_111_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_111_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_112_ADDR                                         (SDAM01_BASE            + 0x000000b0)
#define HWIO_SDAM01_MEM_112_OFFS                                         0x000000b0
#define HWIO_SDAM01_MEM_112_RMSK                                               0xff
#define HWIO_SDAM01_MEM_112_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_112_ADDR, HWIO_SDAM01_MEM_112_RMSK, 0, val)
#define HWIO_SDAM01_MEM_112_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_112_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_112_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_112_ADDR, val, len)
#define HWIO_SDAM01_MEM_112_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_112_ADDR, val)
#define HWIO_SDAM01_MEM_112_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_112_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_112_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_112_ADDR, val, len)
#define HWIO_SDAM01_MEM_112_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_112_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_113_ADDR                                         (SDAM01_BASE            + 0x000000b1)
#define HWIO_SDAM01_MEM_113_OFFS                                         0x000000b1
#define HWIO_SDAM01_MEM_113_RMSK                                               0xff
#define HWIO_SDAM01_MEM_113_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_113_ADDR, HWIO_SDAM01_MEM_113_RMSK, 0, val)
#define HWIO_SDAM01_MEM_113_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_113_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_113_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_113_ADDR, val, len)
#define HWIO_SDAM01_MEM_113_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_113_ADDR, val)
#define HWIO_SDAM01_MEM_113_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_113_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_113_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_113_ADDR, val, len)
#define HWIO_SDAM01_MEM_113_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_113_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_114_ADDR                                         (SDAM01_BASE            + 0x000000b2)
#define HWIO_SDAM01_MEM_114_OFFS                                         0x000000b2
#define HWIO_SDAM01_MEM_114_RMSK                                               0xff
#define HWIO_SDAM01_MEM_114_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_114_ADDR, HWIO_SDAM01_MEM_114_RMSK, 0, val)
#define HWIO_SDAM01_MEM_114_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_114_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_114_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_114_ADDR, val, len)
#define HWIO_SDAM01_MEM_114_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_114_ADDR, val)
#define HWIO_SDAM01_MEM_114_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_114_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_114_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_114_ADDR, val, len)
#define HWIO_SDAM01_MEM_114_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_114_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_115_ADDR                                         (SDAM01_BASE            + 0x000000b3)
#define HWIO_SDAM01_MEM_115_OFFS                                         0x000000b3
#define HWIO_SDAM01_MEM_115_RMSK                                               0xff
#define HWIO_SDAM01_MEM_115_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_115_ADDR, HWIO_SDAM01_MEM_115_RMSK, 0, val)
#define HWIO_SDAM01_MEM_115_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_115_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_115_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_115_ADDR, val, len)
#define HWIO_SDAM01_MEM_115_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_115_ADDR, val)
#define HWIO_SDAM01_MEM_115_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_115_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_115_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_115_ADDR, val, len)
#define HWIO_SDAM01_MEM_115_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_115_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_116_ADDR                                         (SDAM01_BASE            + 0x000000b4)
#define HWIO_SDAM01_MEM_116_OFFS                                         0x000000b4
#define HWIO_SDAM01_MEM_116_RMSK                                               0xff
#define HWIO_SDAM01_MEM_116_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_116_ADDR, HWIO_SDAM01_MEM_116_RMSK, 0, val)
#define HWIO_SDAM01_MEM_116_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_116_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_116_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_116_ADDR, val, len)
#define HWIO_SDAM01_MEM_116_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_116_ADDR, val)
#define HWIO_SDAM01_MEM_116_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_116_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_116_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_116_ADDR, val, len)
#define HWIO_SDAM01_MEM_116_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_116_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_117_ADDR                                         (SDAM01_BASE            + 0x000000b5)
#define HWIO_SDAM01_MEM_117_OFFS                                         0x000000b5
#define HWIO_SDAM01_MEM_117_RMSK                                               0xff
#define HWIO_SDAM01_MEM_117_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_117_ADDR, HWIO_SDAM01_MEM_117_RMSK, 0, val)
#define HWIO_SDAM01_MEM_117_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_117_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_117_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_117_ADDR, val, len)
#define HWIO_SDAM01_MEM_117_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_117_ADDR, val)
#define HWIO_SDAM01_MEM_117_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_117_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_117_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_117_ADDR, val, len)
#define HWIO_SDAM01_MEM_117_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_117_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_118_ADDR                                         (SDAM01_BASE            + 0x000000b6)
#define HWIO_SDAM01_MEM_118_OFFS                                         0x000000b6
#define HWIO_SDAM01_MEM_118_RMSK                                               0xff
#define HWIO_SDAM01_MEM_118_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_118_ADDR, HWIO_SDAM01_MEM_118_RMSK, 0, val)
#define HWIO_SDAM01_MEM_118_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_118_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_118_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_118_ADDR, val, len)
#define HWIO_SDAM01_MEM_118_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_118_ADDR, val)
#define HWIO_SDAM01_MEM_118_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_118_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_118_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_118_ADDR, val, len)
#define HWIO_SDAM01_MEM_118_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_118_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_119_ADDR                                         (SDAM01_BASE            + 0x000000b7)
#define HWIO_SDAM01_MEM_119_OFFS                                         0x000000b7
#define HWIO_SDAM01_MEM_119_RMSK                                               0xff
#define HWIO_SDAM01_MEM_119_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_119_ADDR, HWIO_SDAM01_MEM_119_RMSK, 0, val)
#define HWIO_SDAM01_MEM_119_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_119_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_119_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_119_ADDR, val, len)
#define HWIO_SDAM01_MEM_119_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_119_ADDR, val)
#define HWIO_SDAM01_MEM_119_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_119_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_119_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_119_ADDR, val, len)
#define HWIO_SDAM01_MEM_119_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_119_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_120_ADDR                                         (SDAM01_BASE            + 0x000000b8)
#define HWIO_SDAM01_MEM_120_OFFS                                         0x000000b8
#define HWIO_SDAM01_MEM_120_RMSK                                               0xff
#define HWIO_SDAM01_MEM_120_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_120_ADDR, HWIO_SDAM01_MEM_120_RMSK, 0, val)
#define HWIO_SDAM01_MEM_120_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_120_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_120_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_120_ADDR, val, len)
#define HWIO_SDAM01_MEM_120_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_120_ADDR, val)
#define HWIO_SDAM01_MEM_120_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_120_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_120_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_120_ADDR, val, len)
#define HWIO_SDAM01_MEM_120_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_120_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_121_ADDR                                         (SDAM01_BASE            + 0x000000b9)
#define HWIO_SDAM01_MEM_121_OFFS                                         0x000000b9
#define HWIO_SDAM01_MEM_121_RMSK                                               0xff
#define HWIO_SDAM01_MEM_121_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_121_ADDR, HWIO_SDAM01_MEM_121_RMSK, 0, val)
#define HWIO_SDAM01_MEM_121_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_121_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_121_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_121_ADDR, val, len)
#define HWIO_SDAM01_MEM_121_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_121_ADDR, val)
#define HWIO_SDAM01_MEM_121_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_121_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_121_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_121_ADDR, val, len)
#define HWIO_SDAM01_MEM_121_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_121_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_122_ADDR                                         (SDAM01_BASE            + 0x000000ba)
#define HWIO_SDAM01_MEM_122_OFFS                                         0x000000ba
#define HWIO_SDAM01_MEM_122_RMSK                                               0xff
#define HWIO_SDAM01_MEM_122_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_122_ADDR, HWIO_SDAM01_MEM_122_RMSK, 0, val)
#define HWIO_SDAM01_MEM_122_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_122_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_122_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_122_ADDR, val, len)
#define HWIO_SDAM01_MEM_122_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_122_ADDR, val)
#define HWIO_SDAM01_MEM_122_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_122_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_122_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_122_ADDR, val, len)
#define HWIO_SDAM01_MEM_122_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_122_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_123_ADDR                                         (SDAM01_BASE            + 0x000000bb)
#define HWIO_SDAM01_MEM_123_OFFS                                         0x000000bb
#define HWIO_SDAM01_MEM_123_RMSK                                               0xff
#define HWIO_SDAM01_MEM_123_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_123_ADDR, HWIO_SDAM01_MEM_123_RMSK, 0, val)
#define HWIO_SDAM01_MEM_123_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_123_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_123_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_123_ADDR, val, len)
#define HWIO_SDAM01_MEM_123_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_123_ADDR, val)
#define HWIO_SDAM01_MEM_123_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_123_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_123_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_123_ADDR, val, len)
#define HWIO_SDAM01_MEM_123_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_123_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_124_ADDR                                         (SDAM01_BASE            + 0x000000bc)
#define HWIO_SDAM01_MEM_124_OFFS                                         0x000000bc
#define HWIO_SDAM01_MEM_124_RMSK                                               0xff
#define HWIO_SDAM01_MEM_124_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_124_ADDR, HWIO_SDAM01_MEM_124_RMSK, 0, val)
#define HWIO_SDAM01_MEM_124_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_124_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_124_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_124_ADDR, val, len)
#define HWIO_SDAM01_MEM_124_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_124_ADDR, val)
#define HWIO_SDAM01_MEM_124_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_124_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_124_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_124_ADDR, val, len)
#define HWIO_SDAM01_MEM_124_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_124_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_125_ADDR                                         (SDAM01_BASE            + 0x000000bd)
#define HWIO_SDAM01_MEM_125_OFFS                                         0x000000bd
#define HWIO_SDAM01_MEM_125_RMSK                                               0xff
#define HWIO_SDAM01_MEM_125_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_125_ADDR, HWIO_SDAM01_MEM_125_RMSK, 0, val)
#define HWIO_SDAM01_MEM_125_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_125_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_125_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_125_ADDR, val, len)
#define HWIO_SDAM01_MEM_125_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_125_ADDR, val)
#define HWIO_SDAM01_MEM_125_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_125_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_125_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_125_ADDR, val, len)
#define HWIO_SDAM01_MEM_125_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_125_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_126_ADDR                                         (SDAM01_BASE            + 0x000000be)
#define HWIO_SDAM01_MEM_126_OFFS                                         0x000000be
#define HWIO_SDAM01_MEM_126_RMSK                                               0xff
#define HWIO_SDAM01_MEM_126_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_126_ADDR, HWIO_SDAM01_MEM_126_RMSK, 0, val)
#define HWIO_SDAM01_MEM_126_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_126_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_126_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_126_ADDR, val, len)
#define HWIO_SDAM01_MEM_126_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_126_ADDR, val)
#define HWIO_SDAM01_MEM_126_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_126_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_126_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_126_ADDR, val, len)
#define HWIO_SDAM01_MEM_126_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_126_DATA_SHFT                                           0x0

#define HWIO_SDAM01_MEM_127_ADDR                                         (SDAM01_BASE            + 0x000000bf)
#define HWIO_SDAM01_MEM_127_OFFS                                         0x000000bf
#define HWIO_SDAM01_MEM_127_RMSK                                               0xff
#define HWIO_SDAM01_MEM_127_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_127_ADDR, HWIO_SDAM01_MEM_127_RMSK, 0, val)
#define HWIO_SDAM01_MEM_127_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_127_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_127_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_127_ADDR, val, len)
#define HWIO_SDAM01_MEM_127_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_MEM_127_ADDR, val)
#define HWIO_SDAM01_MEM_127_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_MEM_127_ADDR, mask, shift, val)
#define HWIO_SDAM01_MEM_127_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_MEM_127_ADDR, val, len)
#define HWIO_SDAM01_MEM_127_DATA_BMSK                                          0xff
#define HWIO_SDAM01_MEM_127_DATA_SHFT                                           0x0

#define HWIO_SDAM01_PERPH_RESET_CTL2_ADDR                                (SDAM01_BASE            + 0x000000d9)
#define HWIO_SDAM01_PERPH_RESET_CTL2_OFFS                                0x000000d9
#define HWIO_SDAM01_PERPH_RESET_CTL2_RMSK                                       0x1
#define HWIO_SDAM01_PERPH_RESET_CTL2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL2_ADDR, HWIO_SDAM01_PERPH_RESET_CTL2_RMSK, 0, val)
#define HWIO_SDAM01_PERPH_RESET_CTL2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL2_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_RESET_CTL2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL2_ADDR, val, len)
#define HWIO_SDAM01_PERPH_RESET_CTL2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL2_ADDR, val)
#define HWIO_SDAM01_PERPH_RESET_CTL2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL2_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_RESET_CTL2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL2_ADDR, val, len)
#define HWIO_SDAM01_PERPH_RESET_CTL2_FOLLOW_GLOBAL_SOFT_RB_BMSK                 0x1
#define HWIO_SDAM01_PERPH_RESET_CTL2_FOLLOW_GLOBAL_SOFT_RB_SHFT                 0x0

#define HWIO_SDAM01_PERPH_RESET_CTL3_ADDR                                (SDAM01_BASE            + 0x000000da)
#define HWIO_SDAM01_PERPH_RESET_CTL3_OFFS                                0x000000da
#define HWIO_SDAM01_PERPH_RESET_CTL3_RMSK                                       0x7
#define HWIO_SDAM01_PERPH_RESET_CTL3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL3_ADDR, HWIO_SDAM01_PERPH_RESET_CTL3_RMSK, 0, val)
#define HWIO_SDAM01_PERPH_RESET_CTL3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_RESET_CTL3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_SDAM01_PERPH_RESET_CTL3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL3_ADDR, val)
#define HWIO_SDAM01_PERPH_RESET_CTL3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_RESET_CTL3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_SDAM01_PERPH_RESET_CTL3_FOLLOW_WARM_RB_BMSK                        0x4
#define HWIO_SDAM01_PERPH_RESET_CTL3_FOLLOW_WARM_RB_SHFT                        0x2
#define HWIO_SDAM01_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN1_RB_BMSK                   0x2
#define HWIO_SDAM01_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN1_RB_SHFT                   0x1
#define HWIO_SDAM01_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_BMSK                   0x1
#define HWIO_SDAM01_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_SHFT                   0x0

#define HWIO_SDAM01_PERPH_RESET_CTL4_ADDR                                (SDAM01_BASE            + 0x000000db)
#define HWIO_SDAM01_PERPH_RESET_CTL4_OFFS                                0x000000db
#define HWIO_SDAM01_PERPH_RESET_CTL4_RMSK                                       0x1
#define HWIO_SDAM01_PERPH_RESET_CTL4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL4_ADDR, HWIO_SDAM01_PERPH_RESET_CTL4_RMSK, 0, val)
#define HWIO_SDAM01_PERPH_RESET_CTL4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_RESET_CTL4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_SDAM01_PERPH_RESET_CTL4_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL4_ADDR, val)
#define HWIO_SDAM01_PERPH_RESET_CTL4_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_SDAM01_PERPH_RESET_CTL4_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_SDAM01_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_BMSK                      0x1
#define HWIO_SDAM01_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_SHFT                      0x0

#define HWIO_SDAM01_INT_TEST1_ADDR                                       (SDAM01_BASE            + 0x000000e0)
#define HWIO_SDAM01_INT_TEST1_OFFS                                       0x000000e0
#define HWIO_SDAM01_INT_TEST1_RMSK                                             0x80
#define HWIO_SDAM01_INT_TEST1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_TEST1_ADDR, HWIO_SDAM01_INT_TEST1_RMSK, 0, val)
#define HWIO_SDAM01_INT_TEST1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_TEST1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_TEST1_ADDR, val, len)
#define HWIO_SDAM01_INT_TEST1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_INT_TEST1_ADDR, val)
#define HWIO_SDAM01_INT_TEST1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_TEST1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_INT_TEST1_ADDR, val, len)
#define HWIO_SDAM01_INT_TEST1_TEST_MODE_EN_BMSK                                0x80
#define HWIO_SDAM01_INT_TEST1_TEST_MODE_EN_SHFT                                 0x7

#define HWIO_SDAM01_INT_TEST_VAL_ADDR                                    (SDAM01_BASE            + 0x000000e1)
#define HWIO_SDAM01_INT_TEST_VAL_OFFS                                    0x000000e1
#define HWIO_SDAM01_INT_TEST_VAL_RMSK                                           0x2
#define HWIO_SDAM01_INT_TEST_VAL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_TEST_VAL_ADDR, HWIO_SDAM01_INT_TEST_VAL_RMSK, 0, val)
#define HWIO_SDAM01_INT_TEST_VAL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_TEST_VAL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_INT_TEST_VAL_ADDR, val, len)
#define HWIO_SDAM01_INT_TEST_VAL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_INT_TEST_VAL_ADDR, val)
#define HWIO_SDAM01_INT_TEST_VAL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_SDAM01_INT_TEST_VAL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_INT_TEST_VAL_ADDR, val, len)
#define HWIO_SDAM01_INT_TEST_VAL_VAL_BMSK                                       0x2
#define HWIO_SDAM01_INT_TEST_VAL_VAL_SHFT                                       0x1

#define HWIO_SDAM01_PBS_TRIG_SET_ADDR                                    (SDAM01_BASE            + 0x000000e5)
#define HWIO_SDAM01_PBS_TRIG_SET_OFFS                                    0x000000e5
#define HWIO_SDAM01_PBS_TRIG_SET_RMSK                                           0x1
#define HWIO_SDAM01_PBS_TRIG_SET_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_SET_ADDR, HWIO_SDAM01_PBS_TRIG_SET_RMSK, 0, val)
#define HWIO_SDAM01_PBS_TRIG_SET_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_SET_ADDR, mask, shift, val)
#define HWIO_SDAM01_PBS_TRIG_SET_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_SET_ADDR, val, len)
#define HWIO_SDAM01_PBS_TRIG_SET_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_SET_ADDR, val)
#define HWIO_SDAM01_PBS_TRIG_SET_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_SET_ADDR, mask, shift, val)
#define HWIO_SDAM01_PBS_TRIG_SET_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_SET_ADDR, val, len)
#define HWIO_SDAM01_PBS_TRIG_SET_TRIG_BMSK                                      0x1
#define HWIO_SDAM01_PBS_TRIG_SET_TRIG_SHFT                                      0x0

#define HWIO_SDAM01_PBS_TRIG_CLR_ADDR                                    (SDAM01_BASE            + 0x000000e6)
#define HWIO_SDAM01_PBS_TRIG_CLR_OFFS                                    0x000000e6
#define HWIO_SDAM01_PBS_TRIG_CLR_RMSK                                           0x1
#define HWIO_SDAM01_PBS_TRIG_CLR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_CLR_ADDR, HWIO_SDAM01_PBS_TRIG_CLR_RMSK, 0, val)
#define HWIO_SDAM01_PBS_TRIG_CLR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_CLR_ADDR, mask, shift, val)
#define HWIO_SDAM01_PBS_TRIG_CLR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_CLR_ADDR, val, len)
#define HWIO_SDAM01_PBS_TRIG_CLR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_CLR_ADDR, val)
#define HWIO_SDAM01_PBS_TRIG_CLR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_CLR_ADDR, mask, shift, val)
#define HWIO_SDAM01_PBS_TRIG_CLR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_SDAM01_PBS_TRIG_CLR_ADDR, val, len)
#define HWIO_SDAM01_PBS_TRIG_CLR_TRIG_BMSK                                      0x1
#define HWIO_SDAM01_PBS_TRIG_CLR_TRIG_SHFT                                      0x0

/*----------------------------------------------------------------------------
 * PERIPHERAL: LDO04_MON_MM
 *--------------------------------------------------------------------------*/

#define LDO04_MON_MM_BASE                                                                  0x0000c400

#define HWIO_LDO04_MON_MM_REVISION1_ADDR                                                   (LDO04_MON_MM_BASE            + 0x00000000)
#define HWIO_LDO04_MON_MM_REVISION1_OFFS                                                   0x00000000
#define HWIO_LDO04_MON_MM_REVISION1_RMSK                                                          0x7
#define HWIO_LDO04_MON_MM_REVISION1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION1_ADDR, HWIO_LDO04_MON_MM_REVISION1_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_REVISION1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_REVISION1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_REVISION1_DIG_MINOR_BMSK                                                0x7
#define HWIO_LDO04_MON_MM_REVISION1_DIG_MINOR_SHFT                                                0x0

#define HWIO_LDO04_MON_MM_REVISION2_ADDR                                                   (LDO04_MON_MM_BASE            + 0x00000001)
#define HWIO_LDO04_MON_MM_REVISION2_OFFS                                                   0x00000001
#define HWIO_LDO04_MON_MM_REVISION2_RMSK                                                          0x7
#define HWIO_LDO04_MON_MM_REVISION2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION2_ADDR, HWIO_LDO04_MON_MM_REVISION2_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_REVISION2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_REVISION2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_REVISION2_DIG_MAJOR_BMSK                                                0x7
#define HWIO_LDO04_MON_MM_REVISION2_DIG_MAJOR_SHFT                                                0x0

#define HWIO_LDO04_MON_MM_REVISION3_ADDR                                                   (LDO04_MON_MM_BASE            + 0x00000002)
#define HWIO_LDO04_MON_MM_REVISION3_OFFS                                                   0x00000002
#define HWIO_LDO04_MON_MM_REVISION3_RMSK                                                          0x7
#define HWIO_LDO04_MON_MM_REVISION3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION3_ADDR, HWIO_LDO04_MON_MM_REVISION3_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_REVISION3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION3_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_REVISION3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION3_ADDR, val, len)
#define HWIO_LDO04_MON_MM_REVISION3_ANA_MINOR_BMSK                                                0x7
#define HWIO_LDO04_MON_MM_REVISION3_ANA_MINOR_SHFT                                                0x0

#define HWIO_LDO04_MON_MM_REVISION4_ADDR                                                   (LDO04_MON_MM_BASE            + 0x00000003)
#define HWIO_LDO04_MON_MM_REVISION4_OFFS                                                   0x00000003
#define HWIO_LDO04_MON_MM_REVISION4_RMSK                                                          0x7
#define HWIO_LDO04_MON_MM_REVISION4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION4_ADDR, HWIO_LDO04_MON_MM_REVISION4_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_REVISION4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION4_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_REVISION4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_REVISION4_ADDR, val, len)
#define HWIO_LDO04_MON_MM_REVISION4_ANA_MAJOR_BMSK                                                0x7
#define HWIO_LDO04_MON_MM_REVISION4_ANA_MAJOR_SHFT                                                0x0

#define HWIO_LDO04_MON_MM_PERPH_TYPE_ADDR                                                  (LDO04_MON_MM_BASE            + 0x00000004)
#define HWIO_LDO04_MON_MM_PERPH_TYPE_OFFS                                                  0x00000004
#define HWIO_LDO04_MON_MM_PERPH_TYPE_RMSK                                                        0xff
#define HWIO_LDO04_MON_MM_PERPH_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_TYPE_ADDR, HWIO_LDO04_MON_MM_PERPH_TYPE_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_PERPH_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_TYPE_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_TYPE_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_TYPE_TYPE_BMSK                                                   0xff
#define HWIO_LDO04_MON_MM_PERPH_TYPE_TYPE_SHFT                                                    0x0

#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000005)
#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_OFFS                                               0x00000005
#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_RMSK                                                     0xff
#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_SUBTYPE_ADDR, HWIO_LDO04_MON_MM_PERPH_SUBTYPE_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_SUBTYPE_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_SUBTYPE_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_SUBTYPE_BMSK                                             0xff
#define HWIO_LDO04_MON_MM_PERPH_SUBTYPE_SUBTYPE_SHFT                                              0x0

#define HWIO_LDO04_MON_MM_FAULT_STATUS_ADDR                                                (LDO04_MON_MM_BASE            + 0x00000008)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_OFFS                                                0x00000008
#define HWIO_LDO04_MON_MM_FAULT_STATUS_RMSK                                                      0xc0
#define HWIO_LDO04_MON_MM_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_MODULE_FAULT_STS_BMSK                                     0xc0
#define HWIO_LDO04_MON_MM_FAULT_STATUS_MODULE_FAULT_STS_SHFT                                      0x6

#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ADDR                                            (LDO04_MON_MM_BASE            + 0x00000009)
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_OFFS                                            0x00000009
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_RMSK                                                  0xff
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ADDR, HWIO_LDO04_MON_MM_ABIST_MON_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON4_STATE_STS_BMSK                             0xc0
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON4_STATE_STS_SHFT                              0x6
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON3_STATE_STS_BMSK                             0x30
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON3_STATE_STS_SHFT                              0x4
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON2_STATE_STS_BMSK                              0xc
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON2_STATE_STS_SHFT                              0x2
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON1_STATE_STS_BMSK                              0x3
#define HWIO_LDO04_MON_MM_ABIST_MON_STATUS_ABIST_MON1_STATE_STS_SHFT                              0x0

#define HWIO_LDO04_MON_MM_HW_MON_STATUS_ADDR                                               (LDO04_MON_MM_BASE            + 0x0000000a)
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_OFFS                                               0x0000000a
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_RMSK                                                     0xff
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_STATUS_ADDR, HWIO_LDO04_MON_MM_HW_MON_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON8_PRESENT_BMSK                                        0x80
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON8_PRESENT_SHFT                                         0x7
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON7_PRESENT_BMSK                                        0x40
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON7_PRESENT_SHFT                                         0x6
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON6_PRESENT_BMSK                                        0x20
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON6_PRESENT_SHFT                                         0x5
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON5_PRESENT_BMSK                                        0x10
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON5_PRESENT_SHFT                                         0x4
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON4_PRESENT_BMSK                                         0x8
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON4_PRESENT_SHFT                                         0x3
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON3_PRESENT_BMSK                                         0x4
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON3_PRESENT_SHFT                                         0x2
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON2_PRESENT_BMSK                                         0x2
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON2_PRESENT_SHFT                                         0x1
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON1_PRESENT_BMSK                                         0x1
#define HWIO_LDO04_MON_MM_HW_MON_STATUS_MON1_PRESENT_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_ADDR                                        (LDO04_MON_MM_BASE            + 0x0000000b)
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_OFFS                                        0x0000000b
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_RMSK                                              0xff
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_ADDR, HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON4_LVL_UP_PRESENT_BMSK                          0x80
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON4_LVL_UP_PRESENT_SHFT                           0x7
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON4_LVL_LO_PRESENT_BMSK                          0x40
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON4_LVL_LO_PRESENT_SHFT                           0x6
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON3_LVL_UP_PRESENT_BMSK                          0x20
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON3_LVL_UP_PRESENT_SHFT                           0x5
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON3_LVL_LO_PRESENT_BMSK                          0x10
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON3_LVL_LO_PRESENT_SHFT                           0x4
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON2_LVL_UP_PRESENT_BMSK                           0x8
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON2_LVL_UP_PRESENT_SHFT                           0x3
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON2_LVL_LO_PRESENT_BMSK                           0x4
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON2_LVL_LO_PRESENT_SHFT                           0x2
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON1_LVL_UP_PRESENT_BMSK                           0x2
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON1_LVL_UP_PRESENT_SHFT                           0x1
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON1_LVL_LO_PRESENT_BMSK                           0x1
#define HWIO_LDO04_MON_MM_HW_MON_THRESH_STATUS_MON1_LVL_LO_PRESENT_SHFT                           0x0

#define HWIO_LDO04_MON_MM_MON_EN_STATUS_ADDR                                               (LDO04_MON_MM_BASE            + 0x0000000c)
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_OFFS                                               0x0000000c
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_RMSK                                                     0xff
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_EN_STATUS_ADDR, HWIO_LDO04_MON_MM_MON_EN_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_EN_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_EN_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON8_EN_BMSK                                             0x80
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON8_EN_SHFT                                              0x7
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON7_EN_BMSK                                             0x40
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON7_EN_SHFT                                              0x6
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON6_EN_BMSK                                             0x20
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON6_EN_SHFT                                              0x5
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON5_EN_BMSK                                             0x10
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON5_EN_SHFT                                              0x4
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON4_EN_BMSK                                              0x8
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON4_EN_SHFT                                              0x3
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON3_EN_BMSK                                              0x4
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON3_EN_SHFT                                              0x2
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON2_EN_BMSK                                              0x2
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON2_EN_SHFT                                              0x1
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON1_EN_BMSK                                              0x1
#define HWIO_LDO04_MON_MM_MON_EN_STATUS_MON1_EN_SHFT                                              0x0

#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_ADDR                                    (LDO04_MON_MM_BASE            + 0x0000000d)
#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_OFFS                                    0x0000000d
#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_RMSK                                           0x1
#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_ADDR, HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_LVL3_PRESENT_BMSK                              0x1
#define HWIO_LDO04_MON_MM_FAULT_LVL_SUPPORT_STATUS_LVL3_PRESENT_SHFT                              0x0

#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_ADDR                                      (LDO04_MON_MM_BASE            + 0x0000000e)
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_OFFS                                      0x0000000e
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_RMSK                                            0xf0
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_ADDR, HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON4_SYMMETRY_PRESENT_BMSK                      0x80
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON4_SYMMETRY_PRESENT_SHFT                       0x7
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON3_SYMMETRY_PRESENT_BMSK                      0x40
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON3_SYMMETRY_PRESENT_SHFT                       0x6
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON2_SYMMETRY_PRESENT_BMSK                      0x20
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON2_SYMMETRY_PRESENT_SHFT                       0x5
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON1_SYMMETRY_PRESENT_BMSK                      0x10
#define HWIO_LDO04_MON_MM_HW_MON_SYMMETRY_STATUS_MON1_SYMMETRY_PRESENT_SHFT                       0x4

#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_ADDR                                       (LDO04_MON_MM_BASE            + 0x0000000f)
#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_OFFS                                       0x0000000f
#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_RMSK                                              0x1
#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_ADDR, HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_PBUS_WRITE_SYNC_CTL_PRESENT_BMSK                  0x1
#define HWIO_LDO04_MON_MM_HW_PBUS_BRIDGE_STATUS_PBUS_WRITE_SYNC_CTL_PRESENT_SHFT                  0x0

#define HWIO_LDO04_MON_MM_INT_RT_STS_ADDR                                                  (LDO04_MON_MM_BASE            + 0x00000010)
#define HWIO_LDO04_MON_MM_INT_RT_STS_OFFS                                                  0x00000010
#define HWIO_LDO04_MON_MM_INT_RT_STS_RMSK                                                         0x1
#define HWIO_LDO04_MON_MM_INT_RT_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_RT_STS_ADDR, HWIO_LDO04_MON_MM_INT_RT_STS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_RT_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_RT_STS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_RT_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_RT_STS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_RT_STS_MON_WARNING_RT_STS_BMSK                                      0x1
#define HWIO_LDO04_MON_MM_INT_RT_STS_MON_WARNING_RT_STS_SHFT                                      0x0

#define HWIO_LDO04_MON_MM_INT_SET_TYPE_ADDR                                                (LDO04_MON_MM_BASE            + 0x00000011)
#define HWIO_LDO04_MON_MM_INT_SET_TYPE_OFFS                                                0x00000011
#define HWIO_LDO04_MON_MM_INT_SET_TYPE_RMSK                                                       0x1
#define HWIO_LDO04_MON_MM_INT_SET_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_SET_TYPE_ADDR, HWIO_LDO04_MON_MM_INT_SET_TYPE_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_SET_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_SET_TYPE_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_SET_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_SET_TYPE_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_SET_TYPE_MON_WARNING_TYPE_BMSK                                      0x1
#define HWIO_LDO04_MON_MM_INT_SET_TYPE_MON_WARNING_TYPE_SHFT                                      0x0

#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_ADDR                                           (LDO04_MON_MM_BASE            + 0x00000012)
#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_OFFS                                           0x00000012
#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_RMSK                                                  0x1
#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_ADDR, HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_MON_WARNING_HIGH_BMSK                                 0x1
#define HWIO_LDO04_MON_MM_INT_POLARITY_HIGH_MON_WARNING_HIGH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_ADDR                                            (LDO04_MON_MM_BASE            + 0x00000013)
#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_OFFS                                            0x00000013
#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_RMSK                                                   0x1
#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_POLARITY_LOW_ADDR, HWIO_LDO04_MON_MM_INT_POLARITY_LOW_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_POLARITY_LOW_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_POLARITY_LOW_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_MON_WARNING_LOW_BMSK                                   0x1
#define HWIO_LDO04_MON_MM_INT_POLARITY_LOW_MON_WARNING_LOW_SHFT                                   0x0

#define HWIO_LDO04_MON_MM_INT_LATCHED_CLR_ADDR                                             (LDO04_MON_MM_BASE            + 0x00000014)
#define HWIO_LDO04_MON_MM_INT_LATCHED_CLR_OFFS                                             0x00000014
#define HWIO_LDO04_MON_MM_INT_LATCHED_CLR_RMSK                                                    0x1
#define HWIO_LDO04_MON_MM_INT_LATCHED_CLR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_LATCHED_CLR_ADDR, val)
#define HWIO_LDO04_MON_MM_INT_LATCHED_CLR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_INT_LATCHED_CLR_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_LATCHED_CLR_MON_WARNING_LATCHED_CLR_BMSK                            0x1
#define HWIO_LDO04_MON_MM_INT_LATCHED_CLR_MON_WARNING_LATCHED_CLR_SHFT                            0x0

#define HWIO_LDO04_MON_MM_INT_EN_SET_ADDR                                                  (LDO04_MON_MM_BASE            + 0x00000015)
#define HWIO_LDO04_MON_MM_INT_EN_SET_OFFS                                                  0x00000015
#define HWIO_LDO04_MON_MM_INT_EN_SET_RMSK                                                         0x1
#define HWIO_LDO04_MON_MM_INT_EN_SET_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_SET_ADDR, HWIO_LDO04_MON_MM_INT_EN_SET_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_EN_SET_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_SET_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_EN_SET_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_SET_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_EN_SET_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_SET_ADDR, val)
#define HWIO_LDO04_MON_MM_INT_EN_SET_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_SET_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_EN_SET_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_SET_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_EN_SET_MON_WARNING_EN_SET_BMSK                                      0x1
#define HWIO_LDO04_MON_MM_INT_EN_SET_MON_WARNING_EN_SET_SHFT                                      0x0

#define HWIO_LDO04_MON_MM_INT_EN_CLR_ADDR                                                  (LDO04_MON_MM_BASE            + 0x00000016)
#define HWIO_LDO04_MON_MM_INT_EN_CLR_OFFS                                                  0x00000016
#define HWIO_LDO04_MON_MM_INT_EN_CLR_RMSK                                                         0x1
#define HWIO_LDO04_MON_MM_INT_EN_CLR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_CLR_ADDR, HWIO_LDO04_MON_MM_INT_EN_CLR_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_EN_CLR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_CLR_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_EN_CLR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_CLR_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_EN_CLR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_CLR_ADDR, val)
#define HWIO_LDO04_MON_MM_INT_EN_CLR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_CLR_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_EN_CLR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_INT_EN_CLR_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_EN_CLR_MON_WARNING_EN_CLR_BMSK                                      0x1
#define HWIO_LDO04_MON_MM_INT_EN_CLR_MON_WARNING_EN_CLR_SHFT                                      0x0

#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_ADDR                                             (LDO04_MON_MM_BASE            + 0x00000018)
#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_OFFS                                             0x00000018
#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_RMSK                                                    0x1
#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_LATCHED_STS_ADDR, HWIO_LDO04_MON_MM_INT_LATCHED_STS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_LATCHED_STS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_LATCHED_STS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_MON_WARNING_LATCHED_STS_BMSK                            0x1
#define HWIO_LDO04_MON_MM_INT_LATCHED_STS_MON_WARNING_LATCHED_STS_SHFT                            0x0

#define HWIO_LDO04_MON_MM_INT_PENDING_STS_ADDR                                             (LDO04_MON_MM_BASE            + 0x00000019)
#define HWIO_LDO04_MON_MM_INT_PENDING_STS_OFFS                                             0x00000019
#define HWIO_LDO04_MON_MM_INT_PENDING_STS_RMSK                                                    0x1
#define HWIO_LDO04_MON_MM_INT_PENDING_STS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PENDING_STS_ADDR, HWIO_LDO04_MON_MM_INT_PENDING_STS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_PENDING_STS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PENDING_STS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_PENDING_STS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PENDING_STS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_PENDING_STS_MON_WARNING_PENDING_STS_BMSK                            0x1
#define HWIO_LDO04_MON_MM_INT_PENDING_STS_MON_WARNING_PENDING_STS_SHFT                            0x0

#define HWIO_LDO04_MON_MM_INT_MID_SEL_ADDR                                                 (LDO04_MON_MM_BASE            + 0x0000001a)
#define HWIO_LDO04_MON_MM_INT_MID_SEL_OFFS                                                 0x0000001a
#define HWIO_LDO04_MON_MM_INT_MID_SEL_RMSK                                                        0x3
#define HWIO_LDO04_MON_MM_INT_MID_SEL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_MID_SEL_ADDR, HWIO_LDO04_MON_MM_INT_MID_SEL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_MID_SEL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_MID_SEL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_MID_SEL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_MID_SEL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_MID_SEL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_MID_SEL_ADDR, val)
#define HWIO_LDO04_MON_MM_INT_MID_SEL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_MID_SEL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_MID_SEL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_INT_MID_SEL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_MID_SEL_INT_MID_SEL_BMSK                                            0x3
#define HWIO_LDO04_MON_MM_INT_MID_SEL_INT_MID_SEL_SHFT                                            0x0

#define HWIO_LDO04_MON_MM_INT_PRIORITY_ADDR                                                (LDO04_MON_MM_BASE            + 0x0000001b)
#define HWIO_LDO04_MON_MM_INT_PRIORITY_OFFS                                                0x0000001b
#define HWIO_LDO04_MON_MM_INT_PRIORITY_RMSK                                                       0x1
#define HWIO_LDO04_MON_MM_INT_PRIORITY_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PRIORITY_ADDR, HWIO_LDO04_MON_MM_INT_PRIORITY_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_PRIORITY_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PRIORITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_PRIORITY_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PRIORITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_PRIORITY_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PRIORITY_ADDR, val)
#define HWIO_LDO04_MON_MM_INT_PRIORITY_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PRIORITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_PRIORITY_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_INT_PRIORITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_PRIORITY_INT_PRIORITY_BMSK                                          0x1
#define HWIO_LDO04_MON_MM_INT_PRIORITY_INT_PRIORITY_SHFT                                          0x0

#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_ADDR                                          (LDO04_MON_MM_BASE            + 0x00000028)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_OFFS                                          0x00000028
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_RMSK                                                0xff
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_ADDR, HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_ADDR, val)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON8_STS_CLEAR_BMSK                                 0x80
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON8_STS_CLEAR_SHFT                                  0x7
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON7_STS_CLEAR_BMSK                                 0x40
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON7_STS_CLEAR_SHFT                                  0x6
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON6_STS_CLEAR_BMSK                                 0x20
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON6_STS_CLEAR_SHFT                                  0x5
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON5_STS_CLEAR_BMSK                                 0x10
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON5_STS_CLEAR_SHFT                                  0x4
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON4_STS_CLEAR_BMSK                                  0x8
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON4_STS_CLEAR_SHFT                                  0x3
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON3_STS_CLEAR_BMSK                                  0x4
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON3_STS_CLEAR_SHFT                                  0x2
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON2_STS_CLEAR_BMSK                                  0x2
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON2_STS_CLEAR_SHFT                                  0x1
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON1_STS_CLEAR_BMSK                                  0x1
#define HWIO_LDO04_MON_MM_FAULT_STATUS_CLEAR_MON1_STS_CLEAR_SHFT                                  0x0

#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000030)
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_OFFS                                               0x00000030
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_RMSK                                                     0x80
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MASTER_EN_CTL_ADDR, HWIO_LDO04_MON_MM_MASTER_EN_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MASTER_EN_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MASTER_EN_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MASTER_EN_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MASTER_EN_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MASTER_EN_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_MASTER_EN_BMSK                                           0x80
#define HWIO_LDO04_MON_MM_MASTER_EN_CTL_MASTER_EN_SHFT                                            0x7

#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000031)
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_OFFS                                               0x00000031
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_RMSK                                                     0xff
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FOLLOW_REG_EN_ADDR, HWIO_LDO04_MON_MM_FOLLOW_REG_EN_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FOLLOW_REG_EN_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FOLLOW_REG_EN_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FOLLOW_REG_EN_ADDR, val)
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FOLLOW_REG_EN_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_FOLLOW_REG_EN_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON8_FOLLOW_REG_EN_BMSK                                  0x80
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON8_FOLLOW_REG_EN_SHFT                                   0x7
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON7_FOLLOW_REG_EN_BMSK                                  0x40
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON7_FOLLOW_REG_EN_SHFT                                   0x6
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON6_FOLLOW_REG_EN_BMSK                                  0x20
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON6_FOLLOW_REG_EN_SHFT                                   0x5
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON5_FOLLOW_REG_EN_BMSK                                  0x10
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON5_FOLLOW_REG_EN_SHFT                                   0x4
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON4_FOLLOW_REG_EN_BMSK                                   0x8
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON4_FOLLOW_REG_EN_SHFT                                   0x3
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON3_FOLLOW_REG_EN_BMSK                                   0x4
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON3_FOLLOW_REG_EN_SHFT                                   0x2
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON2_FOLLOW_REG_EN_BMSK                                   0x2
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON2_FOLLOW_REG_EN_SHFT                                   0x1
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON1_FOLLOW_REG_EN_BMSK                                   0x1
#define HWIO_LDO04_MON_MM_FOLLOW_REG_EN_MON1_FOLLOW_REG_EN_SHFT                                   0x0

#define HWIO_LDO04_MON_MM_TIMER_CTL_ADDR                                                   (LDO04_MON_MM_BASE            + 0x00000038)
#define HWIO_LDO04_MON_MM_TIMER_CTL_OFFS                                                   0x00000038
#define HWIO_LDO04_MON_MM_TIMER_CTL_RMSK                                                         0xc1
#define HWIO_LDO04_MON_MM_TIMER_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_TIMER_CTL_ADDR, HWIO_LDO04_MON_MM_TIMER_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_TIMER_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_TIMER_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_TIMER_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_TIMER_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_TIMER_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_TIMER_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_TIMER_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_TIMER_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_TIMER_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_TIMER_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_TIMER_CTL_TIME_SHARE_PERIOD_SEL_BMSK                                   0xc0
#define HWIO_LDO04_MON_MM_TIMER_CTL_TIME_SHARE_PERIOD_SEL_SHFT                                    0x6
#define HWIO_LDO04_MON_MM_TIMER_CTL_EN_TS_TIMER_WAIT_BMSK                                         0x1
#define HWIO_LDO04_MON_MM_TIMER_CTL_EN_TS_TIMER_WAIT_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_ADDR                                                (LDO04_MON_MM_BASE            + 0x0000003c)
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_OFFS                                                0x0000003c
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_RMSK                                                       0xf
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_DIAG_MON_CTL_ADDR, HWIO_LDO04_MON_MM_DIAG_MON_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_DIAG_MON_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_DIAG_MON_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_DIAG_MON_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_DIAG_MON_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_DIAG_MON_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_DIAG_MON_INPUT_SEL_BMSK                                    0xf
#define HWIO_LDO04_MON_MM_DIAG_MON_CTL_DIAG_MON_INPUT_SEL_SHFT                                    0x0

#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_ADDR                                           (LDO04_MON_MM_BASE            + 0x00000040)
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_OFFS                                           0x00000040
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_RMSK                                                 0xf0
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_MON_FAULT_STATUS_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_MON_FAULT_STATUS_SHFT                                 0x6
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_BMSK                       0x30
#define HWIO_LDO04_MON_MM_MON1_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_SHFT                        0x4

#define HWIO_LDO04_MON_MM_MON1_CTL_ADDR                                                    (LDO04_MON_MM_BASE            + 0x00000041)
#define HWIO_LDO04_MON_MM_MON1_CTL_OFFS                                                    0x00000041
#define HWIO_LDO04_MON_MM_MON1_CTL_RMSK                                                          0xe0
#define HWIO_LDO04_MON_MM_MON1_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_CTL_ADDR, HWIO_LDO04_MON_MM_MON1_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_CTL_MON_EN_BMSK                                                   0x80
#define HWIO_LDO04_MON_MM_MON1_CTL_MON_EN_SHFT                                                    0x7
#define HWIO_LDO04_MON_MM_MON1_CTL_INTR_AGG_EN_BMSK                                              0x40
#define HWIO_LDO04_MON_MM_MON1_CTL_INTR_AGG_EN_SHFT                                               0x6
#define HWIO_LDO04_MON_MM_MON1_CTL_TARGET_SEL_BMSK                                               0x20
#define HWIO_LDO04_MON_MM_MON1_CTL_TARGET_SEL_SHFT                                                0x5

#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000042)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_OFFS                                        0x00000042
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_RMSK                                              0xf8
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_ADDR, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_FIXED_TARGET_LB_BMSK                              0xf8
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_LB_FIXED_TARGET_LB_SHFT                               0x3

#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000043)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_OFFS                                        0x00000043
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_RMSK                                               0xf
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_ADDR, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_FIXED_TARGET_UB_BMSK                               0xf
#define HWIO_LDO04_MON_MM_MON1_FIXED_TARGET_UB_FIXED_TARGET_UB_SHFT                               0x0

#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000044)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_OFFS                                        0x00000044
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_RMSK                                              0xf8
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_ADDR, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_TARGET_VALID_LB_BMSK                              0xf8
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_LB_TARGET_VALID_LB_SHFT                               0x3

#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000045)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_OFFS                                        0x00000045
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_RMSK                                               0xf
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_ADDR, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_TARGET_VALID_UB_BMSK                               0xf
#define HWIO_LDO04_MON_MM_MON1_TARGET_VALID_UB_TARGET_VALID_UB_SHFT                               0x0

#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000046)
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_OFFS                                               0x00000046
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_RMSK                                                     0xf0
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_HYST_CTL_ADDR, HWIO_LDO04_MON_MM_MON1_HYST_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_HYST_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_TIME_HYSTERESIS_BMSK                                     0xc0
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_TIME_HYSTERESIS_SHFT                                      0x6
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_ERROR_FLT_CFG_BMSK                                       0x30
#define HWIO_LDO04_MON_MM_MON1_HYST_CTL_ERROR_FLT_CFG_SHFT                                        0x4

#define HWIO_LDO04_MON_MM_MON1_TD_CTL_ADDR                                                 (LDO04_MON_MM_BASE            + 0x00000048)
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_OFFS                                                 0x00000048
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_RMSK                                                       0xfc
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TD_CTL_ADDR, HWIO_LDO04_MON_MM_MON1_TD_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TD_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TD_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TD_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TD_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_TD_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_TIME_DELAY_FALL_SEL_BMSK                                   0xc0
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_TIME_DELAY_FALL_SEL_SHFT                                    0x6
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_TIME_DELAY_RISE_SEL_BMSK                                   0x30
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_TIME_DELAY_RISE_SEL_SHFT                                    0x4
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_TIME_DELAY_FALL_REG_DIS_SEL_BMSK                            0xc
#define HWIO_LDO04_MON_MM_MON1_TD_CTL_TIME_DELAY_FALL_REG_DIS_SEL_SHFT                            0x2

#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x00000049)
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_OFFS                                         0x00000049
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_RMSK                                               0x3f
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_LVL1_UP_THRESH_BMSK                                0x3f
#define HWIO_LDO04_MON_MM_MON1_LVL1_UP_THRESH_LVL1_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000004a)
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_OFFS                                         0x0000004a
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_RMSK                                               0x3f
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_ADDR, HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_LVL1_LO_THRESH_BMSK                                0x3f
#define HWIO_LDO04_MON_MM_MON1_LVL1_LO_THRESH_LVL1_LO_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000004b)
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_OFFS                                         0x0000004b
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_RMSK                                               0xff
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_LVL2_UP_THRESH_BMSK                                0xff
#define HWIO_LDO04_MON_MM_MON1_LVL2_UP_THRESH_LVL2_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000004c)
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_OFFS                                         0x0000004c
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_RMSK                                               0xff
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_ADDR, HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_LVL2_LO_THRESH_BMSK                                0xff
#define HWIO_LDO04_MON_MM_MON1_LVL2_LO_THRESH_LVL2_LO_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_ADDR                                               (LDO04_MON_MM_BASE            + 0x0000004f)
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_OFFS                                               0x0000004f
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_RMSK                                                     0x3f
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_MISC_CFG_ADDR, HWIO_LDO04_MON_MM_MON1_MISC_CFG_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_MISC_CFG_ADDR, val)
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON1_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_BMSK                               0x30
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_SHFT                                0x4
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_BMSK                                0xc
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_SHFT                                0x2
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_UP_THRESH_EN_BMSK                                         0x2
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_UP_THRESH_EN_SHFT                                         0x1
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_LO_THRESH_EN_BMSK                                         0x1
#define HWIO_LDO04_MON_MM_MON1_MISC_CFG_LO_THRESH_EN_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_ADDR                                           (LDO04_MON_MM_BASE            + 0x00000050)
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_OFFS                                           0x00000050
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_RMSK                                                 0xf0
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_MON_FAULT_STATUS_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_MON_FAULT_STATUS_SHFT                                 0x6
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_BMSK                       0x30
#define HWIO_LDO04_MON_MM_MON2_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_SHFT                        0x4

#define HWIO_LDO04_MON_MM_MON2_CTL_ADDR                                                    (LDO04_MON_MM_BASE            + 0x00000051)
#define HWIO_LDO04_MON_MM_MON2_CTL_OFFS                                                    0x00000051
#define HWIO_LDO04_MON_MM_MON2_CTL_RMSK                                                          0xc0
#define HWIO_LDO04_MON_MM_MON2_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_CTL_ADDR, HWIO_LDO04_MON_MM_MON2_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON2_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_CTL_MON_EN_BMSK                                                   0x80
#define HWIO_LDO04_MON_MM_MON2_CTL_MON_EN_SHFT                                                    0x7
#define HWIO_LDO04_MON_MM_MON2_CTL_INTR_AGG_EN_BMSK                                              0x40
#define HWIO_LDO04_MON_MM_MON2_CTL_INTR_AGG_EN_SHFT                                               0x6

#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000052)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_OFFS                                        0x00000052
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_RMSK                                              0xf8
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_ADDR, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_FIXED_TARGET_LB_BMSK                              0xf8
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_LB_FIXED_TARGET_LB_SHFT                               0x3

#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000053)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_OFFS                                        0x00000053
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_RMSK                                               0xf
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_ADDR, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_FIXED_TARGET_UB_BMSK                               0xf
#define HWIO_LDO04_MON_MM_MON2_FIXED_TARGET_UB_FIXED_TARGET_UB_SHFT                               0x0

#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000056)
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_OFFS                                               0x00000056
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_RMSK                                                     0xf0
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_HYST_CTL_ADDR, HWIO_LDO04_MON_MM_MON2_HYST_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_HYST_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_TIME_HYSTERESIS_BMSK                                     0xc0
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_TIME_HYSTERESIS_SHFT                                      0x6
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_ERROR_FLT_CFG_BMSK                                       0x30
#define HWIO_LDO04_MON_MM_MON2_HYST_CTL_ERROR_FLT_CFG_SHFT                                        0x4

#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x00000059)
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_OFFS                                         0x00000059
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_RMSK                                               0x3f
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_LVL1_UP_THRESH_BMSK                                0x3f
#define HWIO_LDO04_MON_MM_MON2_LVL1_UP_THRESH_LVL1_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000005b)
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_OFFS                                         0x0000005b
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_RMSK                                               0xff
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_LVL2_UP_THRESH_BMSK                                0xff
#define HWIO_LDO04_MON_MM_MON2_LVL2_UP_THRESH_LVL2_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_ADDR                                               (LDO04_MON_MM_BASE            + 0x0000005f)
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_OFFS                                               0x0000005f
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_RMSK                                                     0x3f
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_MISC_CFG_ADDR, HWIO_LDO04_MON_MM_MON2_MISC_CFG_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_MISC_CFG_ADDR, val)
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON2_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_BMSK                               0x30
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_SHFT                                0x4
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_BMSK                                0xc
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_SHFT                                0x2
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_UP_THRESH_EN_BMSK                                         0x2
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_UP_THRESH_EN_SHFT                                         0x1
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_LO_THRESH_EN_BMSK                                         0x1
#define HWIO_LDO04_MON_MM_MON2_MISC_CFG_LO_THRESH_EN_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_ADDR                                           (LDO04_MON_MM_BASE            + 0x00000060)
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_OFFS                                           0x00000060
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_RMSK                                                 0xf0
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_MON_FAULT_STATUS_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_MON_FAULT_STATUS_SHFT                                 0x6
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_BMSK                       0x30
#define HWIO_LDO04_MON_MM_MON3_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_SHFT                        0x4

#define HWIO_LDO04_MON_MM_MON3_CTL_ADDR                                                    (LDO04_MON_MM_BASE            + 0x00000061)
#define HWIO_LDO04_MON_MM_MON3_CTL_OFFS                                                    0x00000061
#define HWIO_LDO04_MON_MM_MON3_CTL_RMSK                                                          0xc0
#define HWIO_LDO04_MON_MM_MON3_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_CTL_ADDR, HWIO_LDO04_MON_MM_MON3_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON3_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_CTL_MON_EN_BMSK                                                   0x80
#define HWIO_LDO04_MON_MM_MON3_CTL_MON_EN_SHFT                                                    0x7
#define HWIO_LDO04_MON_MM_MON3_CTL_INTR_AGG_EN_BMSK                                              0x40
#define HWIO_LDO04_MON_MM_MON3_CTL_INTR_AGG_EN_SHFT                                               0x6

#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000062)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_OFFS                                        0x00000062
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_RMSK                                              0xf8
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_ADDR, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_FIXED_TARGET_LB_BMSK                              0xf8
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_LB_FIXED_TARGET_LB_SHFT                               0x3

#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000063)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_OFFS                                        0x00000063
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_RMSK                                               0xf
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_ADDR, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_FIXED_TARGET_UB_BMSK                               0xf
#define HWIO_LDO04_MON_MM_MON3_FIXED_TARGET_UB_FIXED_TARGET_UB_SHFT                               0x0

#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000066)
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_OFFS                                               0x00000066
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_RMSK                                                     0xf0
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_HYST_CTL_ADDR, HWIO_LDO04_MON_MM_MON3_HYST_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_HYST_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_TIME_HYSTERESIS_BMSK                                     0xc0
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_TIME_HYSTERESIS_SHFT                                      0x6
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_ERROR_FLT_CFG_BMSK                                       0x30
#define HWIO_LDO04_MON_MM_MON3_HYST_CTL_ERROR_FLT_CFG_SHFT                                        0x4

#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x00000069)
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_OFFS                                         0x00000069
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_RMSK                                               0x3f
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_LVL1_UP_THRESH_BMSK                                0x3f
#define HWIO_LDO04_MON_MM_MON3_LVL1_UP_THRESH_LVL1_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000006b)
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_OFFS                                         0x0000006b
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_RMSK                                               0xff
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_LVL2_UP_THRESH_BMSK                                0xff
#define HWIO_LDO04_MON_MM_MON3_LVL2_UP_THRESH_LVL2_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_ADDR                                               (LDO04_MON_MM_BASE            + 0x0000006f)
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_OFFS                                               0x0000006f
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_RMSK                                                     0x3f
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_MISC_CFG_ADDR, HWIO_LDO04_MON_MM_MON3_MISC_CFG_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_MISC_CFG_ADDR, val)
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON3_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_BMSK                               0x30
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_SHFT                                0x4
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_BMSK                                0xc
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_SHFT                                0x2
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_UP_THRESH_EN_BMSK                                         0x2
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_UP_THRESH_EN_SHFT                                         0x1
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_LO_THRESH_EN_BMSK                                         0x1
#define HWIO_LDO04_MON_MM_MON3_MISC_CFG_LO_THRESH_EN_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_ADDR                                           (LDO04_MON_MM_BASE            + 0x00000070)
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_OFFS                                           0x00000070
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_RMSK                                                 0xf0
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_MON_FAULT_STATUS_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_MON_FAULT_STATUS_SHFT                                 0x6
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_BMSK                       0x30
#define HWIO_LDO04_MON_MM_MON4_FAULT_STATUS_MON_FAULT_POLARITY_STATUS_SHFT                        0x4

#define HWIO_LDO04_MON_MM_MON4_CTL_ADDR                                                    (LDO04_MON_MM_BASE            + 0x00000071)
#define HWIO_LDO04_MON_MM_MON4_CTL_OFFS                                                    0x00000071
#define HWIO_LDO04_MON_MM_MON4_CTL_RMSK                                                          0xc0
#define HWIO_LDO04_MON_MM_MON4_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_CTL_ADDR, HWIO_LDO04_MON_MM_MON4_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_CTL_MON_EN_BMSK                                                   0x80
#define HWIO_LDO04_MON_MM_MON4_CTL_MON_EN_SHFT                                                    0x7
#define HWIO_LDO04_MON_MM_MON4_CTL_INTR_AGG_EN_BMSK                                              0x40
#define HWIO_LDO04_MON_MM_MON4_CTL_INTR_AGG_EN_SHFT                                               0x6

#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000072)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_OFFS                                        0x00000072
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_RMSK                                              0xf8
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_ADDR, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_FIXED_TARGET_LB_BMSK                              0xf8
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_LB_FIXED_TARGET_LB_SHFT                               0x3

#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_ADDR                                        (LDO04_MON_MM_BASE            + 0x00000073)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_OFFS                                        0x00000073
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_RMSK                                               0xf
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_ADDR, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_FIXED_TARGET_UB_BMSK                               0xf
#define HWIO_LDO04_MON_MM_MON4_FIXED_TARGET_UB_FIXED_TARGET_UB_SHFT                               0x0

#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000076)
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_OFFS                                               0x00000076
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_RMSK                                                     0xf0
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_HYST_CTL_ADDR, HWIO_LDO04_MON_MM_MON4_HYST_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_HYST_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_HYST_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_HYST_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_TIME_HYSTERESIS_BMSK                                     0xc0
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_TIME_HYSTERESIS_SHFT                                      0x6
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_ERROR_FLT_CFG_BMSK                                       0x30
#define HWIO_LDO04_MON_MM_MON4_HYST_CTL_ERROR_FLT_CFG_SHFT                                        0x4

#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_ADDR                                                (LDO04_MON_MM_BASE            + 0x00000077)
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_OFFS                                                0x00000077
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_RMSK                                                      0x70
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_SEC_CTL_ADDR, HWIO_LDO04_MON_MM_MON4_SEC_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_SEC_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_SEC_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_SEC_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_SEC_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_SEC_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_SECONDARY_SIG_SEL_BMSK                                    0x70
#define HWIO_LDO04_MON_MM_MON4_SEC_CTL_SECONDARY_SIG_SEL_SHFT                                     0x4

#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x00000079)
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_OFFS                                         0x00000079
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_RMSK                                               0x3f
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_LVL1_UP_THRESH_BMSK                                0x3f
#define HWIO_LDO04_MON_MM_MON4_LVL1_UP_THRESH_LVL1_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000007a)
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_OFFS                                         0x0000007a
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_RMSK                                               0x3f
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_ADDR, HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_LVL1_LO_THRESH_BMSK                                0x3f
#define HWIO_LDO04_MON_MM_MON4_LVL1_LO_THRESH_LVL1_LO_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000007b)
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_OFFS                                         0x0000007b
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_RMSK                                               0xff
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_ADDR, HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_LVL2_UP_THRESH_BMSK                                0xff
#define HWIO_LDO04_MON_MM_MON4_LVL2_UP_THRESH_LVL2_UP_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_ADDR                                         (LDO04_MON_MM_BASE            + 0x0000007c)
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_OFFS                                         0x0000007c
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_RMSK                                               0xff
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_ADDR, HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_LVL2_LO_THRESH_BMSK                                0xff
#define HWIO_LDO04_MON_MM_MON4_LVL2_LO_THRESH_LVL2_LO_THRESH_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_ADDR                                               (LDO04_MON_MM_BASE            + 0x0000007f)
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_OFFS                                               0x0000007f
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_RMSK                                                     0x3f
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_MISC_CFG_ADDR, HWIO_LDO04_MON_MM_MON4_MISC_CFG_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_MISC_CFG_ADDR, val)
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_MISC_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON4_MISC_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_BMSK                               0x30
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_MAX_UPPER_LVL_ERR_CFG_SHFT                                0x4
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_BMSK                                0xc
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_MAX_LOWER_LVL_ERR_CFG_SHFT                                0x2
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_UP_THRESH_EN_BMSK                                         0x2
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_UP_THRESH_EN_SHFT                                         0x1
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_LO_THRESH_EN_BMSK                                         0x1
#define HWIO_LDO04_MON_MM_MON4_MISC_CFG_LO_THRESH_EN_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_ADDR                                           (LDO04_MON_MM_BASE            + 0x00000080)
#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_OFFS                                           0x00000080
#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_RMSK                                                 0xc0
#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_MON_FAULT_STATUS_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_MON5_FAULT_STATUS_MON_FAULT_STATUS_SHFT                                 0x6

#define HWIO_LDO04_MON_MM_MON5_CTL_ADDR                                                    (LDO04_MON_MM_BASE            + 0x00000081)
#define HWIO_LDO04_MON_MM_MON5_CTL_OFFS                                                    0x00000081
#define HWIO_LDO04_MON_MM_MON5_CTL_RMSK                                                          0xc0
#define HWIO_LDO04_MON_MM_MON5_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_CTL_ADDR, HWIO_LDO04_MON_MM_MON5_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON5_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON5_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_CTL_MON_EN_BMSK                                                   0x80
#define HWIO_LDO04_MON_MM_MON5_CTL_MON_EN_SHFT                                                    0x7
#define HWIO_LDO04_MON_MM_MON5_CTL_INTR_AGG_EN_BMSK                                              0x40
#define HWIO_LDO04_MON_MM_MON5_CTL_INTR_AGG_EN_SHFT                                               0x6

#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000082)
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_OFFS                                               0x00000082
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_RMSK                                                      0x7
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_DEB_TIME_ADDR, HWIO_LDO04_MON_MM_MON5_DEB_TIME_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_DEB_TIME_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_DEB_TIME_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_DEB_TIME_ADDR, val)
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_DEB_TIME_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_DEB_TIME_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_DEB_TIME_BMSK                                             0x7
#define HWIO_LDO04_MON_MM_MON5_DEB_TIME_DEB_TIME_SHFT                                             0x0

#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_ADDR                                          (LDO04_MON_MM_BASE            + 0x00000083)
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_OFFS                                          0x00000083
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_RMSK                                                 0x3
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_ADDR, HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_ADDR, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_MAPPING_BMSK                                         0x3
#define HWIO_LDO04_MON_MM_MON5_FAULT_MAPPING_MAPPING_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ADDR                                         (LDO04_MON_MM_BASE            + 0x00000084)
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_OFFS                                         0x00000084
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_RMSK                                                0x1
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ADDR, HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ADDR, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ACTIVE_HIGH_BMSK                                    0x1
#define HWIO_LDO04_MON_MM_MON5_FAULT_POLARITY_ACTIVE_HIGH_SHFT                                    0x0

#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_ADDR                                           (LDO04_MON_MM_BASE            + 0x00000090)
#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_OFFS                                           0x00000090
#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_RMSK                                                 0xc0
#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_MON_FAULT_STATUS_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_MON6_FAULT_STATUS_MON_FAULT_STATUS_SHFT                                 0x6

#define HWIO_LDO04_MON_MM_MON6_CTL_ADDR                                                    (LDO04_MON_MM_BASE            + 0x00000091)
#define HWIO_LDO04_MON_MM_MON6_CTL_OFFS                                                    0x00000091
#define HWIO_LDO04_MON_MM_MON6_CTL_RMSK                                                          0xc0
#define HWIO_LDO04_MON_MM_MON6_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_CTL_ADDR, HWIO_LDO04_MON_MM_MON6_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON6_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON6_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_CTL_MON_EN_BMSK                                                   0x80
#define HWIO_LDO04_MON_MM_MON6_CTL_MON_EN_SHFT                                                    0x7
#define HWIO_LDO04_MON_MM_MON6_CTL_INTR_AGG_EN_BMSK                                              0x40
#define HWIO_LDO04_MON_MM_MON6_CTL_INTR_AGG_EN_SHFT                                               0x6

#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_ADDR                                               (LDO04_MON_MM_BASE            + 0x00000092)
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_OFFS                                               0x00000092
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_RMSK                                                      0x7
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_DEB_TIME_ADDR, HWIO_LDO04_MON_MM_MON6_DEB_TIME_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_DEB_TIME_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_DEB_TIME_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_DEB_TIME_ADDR, val)
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_DEB_TIME_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_DEB_TIME_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_DEB_TIME_BMSK                                             0x7
#define HWIO_LDO04_MON_MM_MON6_DEB_TIME_DEB_TIME_SHFT                                             0x0

#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_ADDR                                          (LDO04_MON_MM_BASE            + 0x00000093)
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_OFFS                                          0x00000093
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_RMSK                                                 0x3
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_ADDR, HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_ADDR, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_MAPPING_BMSK                                         0x3
#define HWIO_LDO04_MON_MM_MON6_FAULT_MAPPING_MAPPING_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ADDR                                         (LDO04_MON_MM_BASE            + 0x00000094)
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_OFFS                                         0x00000094
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_RMSK                                                0x1
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ADDR, HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ADDR, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ACTIVE_HIGH_BMSK                                    0x1
#define HWIO_LDO04_MON_MM_MON6_FAULT_POLARITY_ACTIVE_HIGH_SHFT                                    0x0

#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_ADDR                                           (LDO04_MON_MM_BASE            + 0x000000a0)
#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_OFFS                                           0x000000a0
#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_RMSK                                                 0xc0
#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_ADDR, HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_MON_FAULT_STATUS_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_MON7_FAULT_STATUS_MON_FAULT_STATUS_SHFT                                 0x6

#define HWIO_LDO04_MON_MM_MON7_CTL_ADDR                                                    (LDO04_MON_MM_BASE            + 0x000000a1)
#define HWIO_LDO04_MON_MM_MON7_CTL_OFFS                                                    0x000000a1
#define HWIO_LDO04_MON_MM_MON7_CTL_RMSK                                                          0xc0
#define HWIO_LDO04_MON_MM_MON7_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_CTL_ADDR, HWIO_LDO04_MON_MM_MON7_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON7_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_MON7_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_CTL_MON_EN_BMSK                                                   0x80
#define HWIO_LDO04_MON_MM_MON7_CTL_MON_EN_SHFT                                                    0x7
#define HWIO_LDO04_MON_MM_MON7_CTL_INTR_AGG_EN_BMSK                                              0x40
#define HWIO_LDO04_MON_MM_MON7_CTL_INTR_AGG_EN_SHFT                                               0x6

#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_ADDR                                               (LDO04_MON_MM_BASE            + 0x000000a2)
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_OFFS                                               0x000000a2
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_RMSK                                                      0x7
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_DEB_TIME_ADDR, HWIO_LDO04_MON_MM_MON7_DEB_TIME_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_DEB_TIME_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_DEB_TIME_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_DEB_TIME_ADDR, val)
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_DEB_TIME_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_DEB_TIME_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_DEB_TIME_BMSK                                             0x7
#define HWIO_LDO04_MON_MM_MON7_DEB_TIME_DEB_TIME_SHFT                                             0x0

#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_ADDR                                          (LDO04_MON_MM_BASE            + 0x000000a3)
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_OFFS                                          0x000000a3
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_RMSK                                                 0x3
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_ADDR, HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_ADDR, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_MAPPING_BMSK                                         0x3
#define HWIO_LDO04_MON_MM_MON7_FAULT_MAPPING_MAPPING_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ADDR                                         (LDO04_MON_MM_BASE            + 0x000000a4)
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_OFFS                                         0x000000a4
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_RMSK                                                0x1
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ADDR, HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ADDR, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ACTIVE_HIGH_BMSK                                    0x1
#define HWIO_LDO04_MON_MM_MON7_FAULT_POLARITY_ACTIVE_HIGH_SHFT                                    0x0

#define HWIO_LDO04_MON_MM_GANG_CTL1_ADDR                                                   (LDO04_MON_MM_BASE            + 0x000000c0)
#define HWIO_LDO04_MON_MM_GANG_CTL1_OFFS                                                   0x000000c0
#define HWIO_LDO04_MON_MM_GANG_CTL1_RMSK                                                         0xff
#define HWIO_LDO04_MON_MM_GANG_CTL1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL1_ADDR, HWIO_LDO04_MON_MM_GANG_CTL1_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_GANG_CTL1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_GANG_CTL1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_GANG_CTL1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL1_ADDR, val)
#define HWIO_LDO04_MON_MM_GANG_CTL1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_GANG_CTL1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_GANG_CTL1_GANG_LEADER_PID_BMSK                                         0xff
#define HWIO_LDO04_MON_MM_GANG_CTL1_GANG_LEADER_PID_SHFT                                          0x0

#define HWIO_LDO04_MON_MM_GANG_CTL2_ADDR                                                   (LDO04_MON_MM_BASE            + 0x000000c1)
#define HWIO_LDO04_MON_MM_GANG_CTL2_OFFS                                                   0x000000c1
#define HWIO_LDO04_MON_MM_GANG_CTL2_RMSK                                                         0x80
#define HWIO_LDO04_MON_MM_GANG_CTL2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL2_ADDR, HWIO_LDO04_MON_MM_GANG_CTL2_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_GANG_CTL2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_GANG_CTL2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_GANG_CTL2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL2_ADDR, val)
#define HWIO_LDO04_MON_MM_GANG_CTL2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_GANG_CTL2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_GANG_CTL2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_GANG_CTL2_GANG_EN_BMSK                                                 0x80
#define HWIO_LDO04_MON_MM_GANG_CTL2_GANG_EN_SHFT                                                  0x7

#define HWIO_LDO04_MON_MM_MON_AHM_EN_ADDR                                                  (LDO04_MON_MM_BASE            + 0x000000cc)
#define HWIO_LDO04_MON_MM_MON_AHM_EN_OFFS                                                  0x000000cc
#define HWIO_LDO04_MON_MM_MON_AHM_EN_RMSK                                                        0xc7
#define HWIO_LDO04_MON_MM_MON_AHM_EN_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_EN_ADDR, HWIO_LDO04_MON_MM_MON_AHM_EN_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_AHM_EN_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_EN_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_AHM_EN_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_EN_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_AHM_EN_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_EN_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_AHM_EN_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_EN_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_AHM_EN_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_EN_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_AHM_EN_TMR_SEL_CFG_BMSK                                            0xc0
#define HWIO_LDO04_MON_MM_MON_AHM_EN_TMR_SEL_CFG_SHFT                                             0x6
#define HWIO_LDO04_MON_MM_MON_AHM_EN_TRIM_EN_BMSK                                                 0x4
#define HWIO_LDO04_MON_MM_MON_AHM_EN_TRIM_EN_SHFT                                                 0x2
#define HWIO_LDO04_MON_MM_MON_AHM_EN_I2V_EN_BMSK                                                  0x2
#define HWIO_LDO04_MON_MM_MON_AHM_EN_I2V_EN_SHFT                                                  0x1
#define HWIO_LDO04_MON_MM_MON_AHM_EN_SPK_DET_EN_BMSK                                              0x1
#define HWIO_LDO04_MON_MM_MON_AHM_EN_SPK_DET_EN_SHFT                                              0x0

#define HWIO_LDO04_MON_MM_SPK_CFG_ADDR                                                     (LDO04_MON_MM_BASE            + 0x000000cd)
#define HWIO_LDO04_MON_MM_SPK_CFG_OFFS                                                     0x000000cd
#define HWIO_LDO04_MON_MM_SPK_CFG_RMSK                                                           0x7f
#define HWIO_LDO04_MON_MM_SPK_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_SPK_CFG_ADDR, HWIO_LDO04_MON_MM_SPK_CFG_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_SPK_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_SPK_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_SPK_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_SPK_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_SPK_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_SPK_CFG_ADDR, val)
#define HWIO_LDO04_MON_MM_SPK_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_SPK_CFG_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_SPK_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_SPK_CFG_ADDR, val, len)
#define HWIO_LDO04_MON_MM_SPK_CFG_SPK_DET_GAIN_BMSK                                              0x70
#define HWIO_LDO04_MON_MM_SPK_CFG_SPK_DET_GAIN_SHFT                                               0x4
#define HWIO_LDO04_MON_MM_SPK_CFG_SPK_DET_SPEED_BMSK                                              0xc
#define HWIO_LDO04_MON_MM_SPK_CFG_SPK_DET_SPEED_SHFT                                              0x2
#define HWIO_LDO04_MON_MM_SPK_CFG_SPK_DET_ADJ_BMSK                                                0x3
#define HWIO_LDO04_MON_MM_SPK_CFG_SPK_DET_ADJ_SHFT                                                0x0

#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_ADDR                                               (LDO04_MON_MM_BASE            + 0x000000ce)
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_OFFS                                               0x000000ce
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_RMSK                                                     0xff
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_SPARE_ADDR, HWIO_LDO04_MON_MM_MON_AHM_SPARE_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_SPARE_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_SPARE_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_SPARE_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_SPARE_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_AHM_SPARE_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_SPARE_IN_CFG_BMSK                                        0xff
#define HWIO_LDO04_MON_MM_MON_AHM_SPARE_SPARE_IN_CFG_SHFT                                         0x0

#define HWIO_LDO04_MON_MM_LOCKBIT_D1_ADDR                                                  (LDO04_MON_MM_BASE            + 0x000000d1)
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_OFFS                                                  0x000000d1
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_RMSK                                                         0x3
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_LOCKBIT_D1_ADDR, HWIO_LDO04_MON_MM_LOCKBIT_D1_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_LOCKBIT_D1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_LOCKBIT_D1_ADDR, val)
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_LOCKBIT_D1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_LOCKBIT_D1_BMSK                                              0x3
#define HWIO_LDO04_MON_MM_LOCKBIT_D1_LOCKBIT_D1_SHFT                                              0x0

#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_ADDR                                        (LDO04_MON_MM_BASE            + 0x000000d4)
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_OFFS                                        0x000000d4
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_RMSK                                               0x1
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_ADDR, HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_ADDR, val)
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_BMSK                                    0x1
#define HWIO_LDO04_MON_MM_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_SHFT                                    0x0

#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_ADDR                                            (LDO04_MON_MM_BASE            + 0x000000d5)
#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_OFFS                                            0x000000d5
#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_RMSK                                                   0x1
#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PMIC_COST_SAVING_ADDR, HWIO_LDO04_MON_MM_PMIC_COST_SAVING_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PMIC_COST_SAVING_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PMIC_COST_SAVING_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_PMIC_COST_SAVING_BMSK                                  0x1
#define HWIO_LDO04_MON_MM_PMIC_COST_SAVING_PMIC_COST_SAVING_SHFT                                  0x0

#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ADDR                                            (LDO04_MON_MM_BASE            + 0x000000d8)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_OFFS                                            0x000000d8
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_RMSK                                                   0x1
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ADDR, HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ADDR, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ENABLE_PRESET_BMSK                                     0x1
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL1_ENABLE_PRESET_SHFT                                     0x0

#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_ADDR                                            (LDO04_MON_MM_BASE            + 0x000000da)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_OFFS                                            0x000000da
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_RMSK                                                   0x5
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_ADDR, HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_ADDR, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_FOLLOW_WARM_RB_BMSK                                    0x4
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_FOLLOW_WARM_RB_SHFT                                    0x2
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_BMSK                               0x1
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_SHFT                               0x0

#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_ADDR                                            (LDO04_MON_MM_BASE            + 0x000000db)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_OFFS                                            0x000000db
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_RMSK                                                   0x1
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_ADDR, HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_ADDR, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_BMSK                                  0x1
#define HWIO_LDO04_MON_MM_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_SHFT                                  0x0

#define HWIO_LDO04_MON_MM_INT_TEST1_ADDR                                                   (LDO04_MON_MM_BASE            + 0x000000e0)
#define HWIO_LDO04_MON_MM_INT_TEST1_OFFS                                                   0x000000e0
#define HWIO_LDO04_MON_MM_INT_TEST1_RMSK                                                         0x80
#define HWIO_LDO04_MON_MM_INT_TEST1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST1_ADDR, HWIO_LDO04_MON_MM_INT_TEST1_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_TEST1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_TEST1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_TEST1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST1_ADDR, val)
#define HWIO_LDO04_MON_MM_INT_TEST1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_TEST1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_TEST1_INT_TEST_MODE_EN_BMSK                                        0x80
#define HWIO_LDO04_MON_MM_INT_TEST1_INT_TEST_MODE_EN_SHFT                                         0x7

#define HWIO_LDO04_MON_MM_INT_TEST_VAL_ADDR                                                (LDO04_MON_MM_BASE            + 0x000000e1)
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_OFFS                                                0x000000e1
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_RMSK                                                       0x1
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST_VAL_ADDR, HWIO_LDO04_MON_MM_INT_TEST_VAL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST_VAL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST_VAL_ADDR, val)
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_INT_TEST_VAL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_MON_WARNING_INT_TEST_VAL_BMSK                              0x1
#define HWIO_LDO04_MON_MM_INT_TEST_VAL_MON_WARNING_INT_TEST_VAL_SHFT                              0x0

#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ADDR                                                 (LDO04_MON_MM_BASE            + 0x000000e2)
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_OFFS                                                 0x000000e2
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_RMSK                                                       0xff
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_EN_ADDR, HWIO_LDO04_MON_MM_ERR_TEST_EN_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_EN_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_EN_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_EN_ADDR, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_EN_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_EN_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON8_TEST_MODE_EN_BMSK                                 0x80
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON8_TEST_MODE_EN_SHFT                                  0x7
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON7_TEST_MODE_EN_BMSK                                 0x40
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON7_TEST_MODE_EN_SHFT                                  0x6
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON6_TEST_MODE_EN_BMSK                                 0x20
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON6_TEST_MODE_EN_SHFT                                  0x5
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON5_TEST_MODE_EN_BMSK                                 0x10
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON5_TEST_MODE_EN_SHFT                                  0x4
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON4_TEST_MODE_EN_BMSK                                  0x8
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON4_TEST_MODE_EN_SHFT                                  0x3
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON3_TEST_MODE_EN_BMSK                                  0x4
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON3_TEST_MODE_EN_SHFT                                  0x2
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON2_TEST_MODE_EN_BMSK                                  0x2
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON2_TEST_MODE_EN_SHFT                                  0x1
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON1_TEST_MODE_EN_BMSK                                  0x1
#define HWIO_LDO04_MON_MM_ERR_TEST_EN_ERR_MON1_TEST_MODE_EN_SHFT                                  0x0

#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ADDR                                              (LDO04_MON_MM_BASE            + 0x000000e3)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_OFFS                                              0x000000e3
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_RMSK                                                    0xff
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ADDR, HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ADDR, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON4_TEST_VAL_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON4_TEST_VAL_SHFT                                 0x6
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON3_TEST_VAL_BMSK                                0x30
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON3_TEST_VAL_SHFT                                 0x4
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON2_TEST_VAL_BMSK                                 0xc
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON2_TEST_VAL_SHFT                                 0x2
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON1_TEST_VAL_BMSK                                 0x3
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_1_ERROR_MON1_TEST_VAL_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ADDR                                              (LDO04_MON_MM_BASE            + 0x000000e4)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_OFFS                                              0x000000e4
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_RMSK                                                    0xff
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ADDR, HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ADDR, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON8_TEST_VAL_BMSK                                0xc0
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON8_TEST_VAL_SHFT                                 0x6
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON7_TEST_VAL_BMSK                                0x30
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON7_TEST_VAL_SHFT                                 0x4
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON6_TEST_VAL_BMSK                                 0xc
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON6_TEST_VAL_SHFT                                 0x2
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON5_TEST_VAL_BMSK                                 0x3
#define HWIO_LDO04_MON_MM_ERR_TEST_VAL_2_ERROR_MON5_TEST_VAL_SHFT                                 0x0

#define HWIO_LDO04_MON_MM_FAULT_CTL_ADDR                                                   (LDO04_MON_MM_BASE            + 0x000000e5)
#define HWIO_LDO04_MON_MM_FAULT_CTL_OFFS                                                   0x000000e5
#define HWIO_LDO04_MON_MM_FAULT_CTL_RMSK                                                         0x80
#define HWIO_LDO04_MON_MM_FAULT_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_CTL_ADDR, HWIO_LDO04_MON_MM_FAULT_CTL_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_FAULT_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FAULT_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FAULT_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_CTL_ADDR, val)
#define HWIO_LDO04_MON_MM_FAULT_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_CTL_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_FAULT_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_FAULT_CTL_ADDR, val, len)
#define HWIO_LDO04_MON_MM_FAULT_CTL_BLOCK_ALL_FAULT_OUTPUTS_BMSK                                 0x80
#define HWIO_LDO04_MON_MM_FAULT_CTL_BLOCK_ALL_FAULT_OUTPUTS_SHFT                                  0x7

#define HWIO_LDO04_MON_MM_ABIST_CTL1_ADDR                                                  (LDO04_MON_MM_BASE            + 0x000000e6)
#define HWIO_LDO04_MON_MM_ABIST_CTL1_OFFS                                                  0x000000e6
#define HWIO_LDO04_MON_MM_ABIST_CTL1_RMSK                                                         0xf
#define HWIO_LDO04_MON_MM_ABIST_CTL1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL1_ADDR, HWIO_LDO04_MON_MM_ABIST_CTL1_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ABIST_CTL1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL1_ADDR, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL1_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL1_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON4_ABIST_EN_BMSK                                           0x8
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON4_ABIST_EN_SHFT                                           0x3
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON3_ABIST_EN_BMSK                                           0x4
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON3_ABIST_EN_SHFT                                           0x2
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON2_ABIST_EN_BMSK                                           0x2
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON2_ABIST_EN_SHFT                                           0x1
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON1_ABIST_EN_BMSK                                           0x1
#define HWIO_LDO04_MON_MM_ABIST_CTL1_MON1_ABIST_EN_SHFT                                           0x0

#define HWIO_LDO04_MON_MM_ABIST_CTL2_ADDR                                                  (LDO04_MON_MM_BASE            + 0x000000e7)
#define HWIO_LDO04_MON_MM_ABIST_CTL2_OFFS                                                  0x000000e7
#define HWIO_LDO04_MON_MM_ABIST_CTL2_RMSK                                                        0xf8
#define HWIO_LDO04_MON_MM_ABIST_CTL2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL2_ADDR, HWIO_LDO04_MON_MM_ABIST_CTL2_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ABIST_CTL2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL2_ADDR, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ABIST_CTL2_DAC_TARGET_ABOVE_BMSK                                       0xf8
#define HWIO_LDO04_MON_MM_ABIST_CTL2_DAC_TARGET_ABOVE_SHFT                                        0x3

#define HWIO_LDO04_MON_MM_ABIST_CTL3_ADDR                                                  (LDO04_MON_MM_BASE            + 0x000000e8)
#define HWIO_LDO04_MON_MM_ABIST_CTL3_OFFS                                                  0x000000e8
#define HWIO_LDO04_MON_MM_ABIST_CTL3_RMSK                                                        0xf8
#define HWIO_LDO04_MON_MM_ABIST_CTL3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL3_ADDR, HWIO_LDO04_MON_MM_ABIST_CTL3_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL3_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL3_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ABIST_CTL3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL3_ADDR, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL3_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_ABIST_CTL3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_ABIST_CTL3_ADDR, val, len)
#define HWIO_LDO04_MON_MM_ABIST_CTL3_DAC_TARGET_BELOW_BMSK                                       0xf8
#define HWIO_LDO04_MON_MM_ABIST_CTL3_DAC_TARGET_BELOW_SHFT                                        0x3

#define HWIO_LDO04_MON_MM_CFG_ATEST_12_ADDR                                                (LDO04_MON_MM_BASE            + 0x000000e9)
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_OFFS                                                0x000000e9
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_RMSK                                                      0x77
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_ATEST_12_ADDR, HWIO_LDO04_MON_MM_CFG_ATEST_12_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_ATEST_12_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_ATEST_12_ADDR, val, len)
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_ATEST_12_ADDR, val)
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_ATEST_12_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_ATEST_12_ADDR, val, len)
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_CFG_ATEST2_BMSK                                           0x70
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_CFG_ATEST2_SHFT                                            0x4
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_CFG_ATEST1_BMSK                                            0x7
#define HWIO_LDO04_MON_MM_CFG_ATEST_12_CFG_ATEST1_SHFT                                            0x0

#define HWIO_LDO04_MON_MM_CFG_DTEST_12_ADDR                                                (LDO04_MON_MM_BASE            + 0x000000eb)
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_OFFS                                                0x000000eb
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_RMSK                                                      0xff
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_12_ADDR, HWIO_LDO04_MON_MM_CFG_DTEST_12_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_12_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_12_ADDR, val, len)
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_12_ADDR, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_12_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_12_ADDR, val, len)
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_CFG_DTEST2_BMSK                                           0xf0
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_CFG_DTEST2_SHFT                                            0x4
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_CFG_DTEST1_BMSK                                            0xf
#define HWIO_LDO04_MON_MM_CFG_DTEST_12_CFG_DTEST1_SHFT                                            0x0

#define HWIO_LDO04_MON_MM_CFG_DTEST_34_ADDR                                                (LDO04_MON_MM_BASE            + 0x000000ec)
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_OFFS                                                0x000000ec
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_RMSK                                                      0xff
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_34_ADDR, HWIO_LDO04_MON_MM_CFG_DTEST_34_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_34_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_34_ADDR, val, len)
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_34_ADDR, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_34_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_CFG_DTEST_34_ADDR, val, len)
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_CFG_DTEST4_BMSK                                           0xf0
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_CFG_DTEST4_SHFT                                            0x4
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_CFG_DTEST3_BMSK                                            0xf
#define HWIO_LDO04_MON_MM_CFG_DTEST_34_CFG_DTEST3_SHFT                                            0x0

#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_ADDR                                   (LDO04_MON_MM_BASE            + 0x000000ee)
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_OFFS                                   0x000000ee
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_RMSK                                         0xff
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_ADDR, HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON8_INPUT_TEST_OVERRIDE_BMSK                0xc0
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON8_INPUT_TEST_OVERRIDE_SHFT                 0x6
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON7_INPUT_TEST_OVERRIDE_BMSK                0x30
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON7_INPUT_TEST_OVERRIDE_SHFT                 0x4
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON6_INPUT_TEST_OVERRIDE_BMSK                 0xc
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON6_INPUT_TEST_OVERRIDE_SHFT                 0x2
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON5_INPUT_TEST_OVERRIDE_BMSK                 0x3
#define HWIO_LDO04_MON_MM_MON_INPUT_TEST_OVERRIDE_2_MON5_INPUT_TEST_OVERRIDE_SHFT                 0x0

#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_ADDR                                      (LDO04_MON_MM_BASE            + 0x000000ef)
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_OFFS                                      0x000000ef
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_RMSK                                             0x3
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_ADDR, HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_MON_COMP_TEST_OVERRIDE_BMSK                      0x3
#define HWIO_LDO04_MON_MM_MON_COMP_TEST_OVERRIDE_MON_COMP_TEST_OVERRIDE_SHFT                      0x0

#define HWIO_LDO04_MON_MM_TRIM_NUM_ADDR                                                    (LDO04_MON_MM_BASE            + 0x000000f0)
#define HWIO_LDO04_MON_MM_TRIM_NUM_OFFS                                                    0x000000f0
#define HWIO_LDO04_MON_MM_TRIM_NUM_RMSK                                                          0xff
#define HWIO_LDO04_MON_MM_TRIM_NUM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_TRIM_NUM_ADDR, HWIO_LDO04_MON_MM_TRIM_NUM_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_TRIM_NUM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_TRIM_NUM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_TRIM_NUM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_TRIM_NUM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_TRIM_NUM_TRIM_NUM_BMSK                                                 0xff
#define HWIO_LDO04_MON_MM_TRIM_NUM_TRIM_NUM_SHFT                                                  0x0

#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_ADDR                                        (LDO04_MON_MM_BASE            + 0x000000f1)
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_OFFS                                        0x000000f1
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_RMSK                                              0x1f
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_ADDR, HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_MON_COMP_OFFSET_TRIM_BMSK                         0x1f
#define HWIO_LDO04_MON_MM_MON_COMP_OFFSET_TRIM_MON_COMP_OFFSET_TRIM_SHFT                          0x0

#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_ADDR                                         (LDO04_MON_MM_BASE            + 0x000000f2)
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_OFFS                                         0x000000f2
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_RMSK                                               0x1f
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_ADDR, HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_MON_DAC_OFFSET_TRIM_BMSK                           0x1f
#define HWIO_LDO04_MON_MM_MON_DAC_OFFSET_TRIM_MON_DAC_OFFSET_TRIM_SHFT                            0x0

#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_ADDR                                            (LDO04_MON_MM_BASE            + 0x000000f3)
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_OFFS                                            0x000000f3
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_RMSK                                                   0xf
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_ADDR, HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_MON_SPK_POS_TRIM_BMSK                                  0xf
#define HWIO_LDO04_MON_MM_MON_SPK_POS_TRIM_MON_SPK_POS_TRIM_SHFT                                  0x0

#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_ADDR                                            (LDO04_MON_MM_BASE            + 0x000000f4)
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_OFFS                                            0x000000f4
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_RMSK                                                   0xf
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_ADDR, HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_MON_SPK_NEG_TRIM_BMSK                                  0xf
#define HWIO_LDO04_MON_MM_MON_SPK_NEG_TRIM_MON_SPK_NEG_TRIM_SHFT                                  0x0

#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_ADDR                                                (LDO04_MON_MM_BASE            + 0x000000f5)
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_OFFS                                                0x000000f5
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_RMSK                                                       0xf
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_I2V_TRIM_ADDR, HWIO_LDO04_MON_MM_MON_I2V_TRIM_RMSK, 0, val)
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_I2V_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_I2V_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_LDO04_MON_MM_MON_I2V_TRIM_ADDR, val)
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_LDO04_MON_MM_MON_I2V_TRIM_ADDR, mask, shift, val)
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_LDO04_MON_MM_MON_I2V_TRIM_ADDR, val, len)
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_MON_I2V_TRIM_BMSK                                          0xf
#define HWIO_LDO04_MON_MM_MON_I2V_TRIM_MON_I2V_TRIM_SHFT                                          0x0

/*----------------------------------------------------------------------------
 * PERIPHERAL: BIST_CTL
 *--------------------------------------------------------------------------*/

#define BIST_CTL_BASE                                                     0x0000ff00

#define HWIO_BIST_CTL_REVISION1_ADDR                                      (BIST_CTL_BASE            + 0x00000000)
#define HWIO_BIST_CTL_REVISION1_OFFS                                      0x00000000
#define HWIO_BIST_CTL_REVISION1_RMSK                                            0xff
#define HWIO_BIST_CTL_REVISION1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION1_ADDR, HWIO_BIST_CTL_REVISION1_RMSK, 0, val)
#define HWIO_BIST_CTL_REVISION1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION1_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_REVISION1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_REVISION1_ADDR, val, len)
#define HWIO_BIST_CTL_REVISION1_DIG_MINOR_BMSK                                  0xff
#define HWIO_BIST_CTL_REVISION1_DIG_MINOR_SHFT                                   0x0

#define HWIO_BIST_CTL_REVISION2_ADDR                                      (BIST_CTL_BASE            + 0x00000001)
#define HWIO_BIST_CTL_REVISION2_OFFS                                      0x00000001
#define HWIO_BIST_CTL_REVISION2_RMSK                                            0xff
#define HWIO_BIST_CTL_REVISION2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION2_ADDR, HWIO_BIST_CTL_REVISION2_RMSK, 0, val)
#define HWIO_BIST_CTL_REVISION2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION2_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_REVISION2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_REVISION2_ADDR, val, len)
#define HWIO_BIST_CTL_REVISION2_DIG_MAJOR_BMSK                                  0xff
#define HWIO_BIST_CTL_REVISION2_DIG_MAJOR_SHFT                                   0x0

#define HWIO_BIST_CTL_REVISION3_ADDR                                      (BIST_CTL_BASE            + 0x00000002)
#define HWIO_BIST_CTL_REVISION3_OFFS                                      0x00000002
#define HWIO_BIST_CTL_REVISION3_RMSK                                            0xff
#define HWIO_BIST_CTL_REVISION3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION3_ADDR, HWIO_BIST_CTL_REVISION3_RMSK, 0, val)
#define HWIO_BIST_CTL_REVISION3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION3_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_REVISION3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_REVISION3_ADDR, val, len)
#define HWIO_BIST_CTL_REVISION3_ANA_MINOR_BMSK                                  0xff
#define HWIO_BIST_CTL_REVISION3_ANA_MINOR_SHFT                                   0x0

#define HWIO_BIST_CTL_REVISION4_ADDR                                      (BIST_CTL_BASE            + 0x00000003)
#define HWIO_BIST_CTL_REVISION4_OFFS                                      0x00000003
#define HWIO_BIST_CTL_REVISION4_RMSK                                            0xff
#define HWIO_BIST_CTL_REVISION4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION4_ADDR, HWIO_BIST_CTL_REVISION4_RMSK, 0, val)
#define HWIO_BIST_CTL_REVISION4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_REVISION4_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_REVISION4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_REVISION4_ADDR, val, len)
#define HWIO_BIST_CTL_REVISION4_ANA_MAJOR_BMSK                                  0xff
#define HWIO_BIST_CTL_REVISION4_ANA_MAJOR_SHFT                                   0x0

#define HWIO_BIST_CTL_PERPH_TYPE_ADDR                                     (BIST_CTL_BASE            + 0x00000004)
#define HWIO_BIST_CTL_PERPH_TYPE_OFFS                                     0x00000004
#define HWIO_BIST_CTL_PERPH_TYPE_RMSK                                           0xff
#define HWIO_BIST_CTL_PERPH_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_PERPH_TYPE_ADDR, HWIO_BIST_CTL_PERPH_TYPE_RMSK, 0, val)
#define HWIO_BIST_CTL_PERPH_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_PERPH_TYPE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_PERPH_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_PERPH_TYPE_ADDR, val, len)
#define HWIO_BIST_CTL_PERPH_TYPE_TYPE_BMSK                                      0xff
#define HWIO_BIST_CTL_PERPH_TYPE_TYPE_SHFT                                       0x0

#define HWIO_BIST_CTL_PERPH_SUBTYPE_ADDR                                  (BIST_CTL_BASE            + 0x00000005)
#define HWIO_BIST_CTL_PERPH_SUBTYPE_OFFS                                  0x00000005
#define HWIO_BIST_CTL_PERPH_SUBTYPE_RMSK                                        0xff
#define HWIO_BIST_CTL_PERPH_SUBTYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_PERPH_SUBTYPE_ADDR, HWIO_BIST_CTL_PERPH_SUBTYPE_RMSK, 0, val)
#define HWIO_BIST_CTL_PERPH_SUBTYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_PERPH_SUBTYPE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_PERPH_SUBTYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_PERPH_SUBTYPE_ADDR, val, len)
#define HWIO_BIST_CTL_PERPH_SUBTYPE_SUBTYPE_BMSK                                0xff
#define HWIO_BIST_CTL_PERPH_SUBTYPE_SUBTYPE_SHFT                                 0x0

#define HWIO_BIST_CTL_STATUS_ADDR                                         (BIST_CTL_BASE            + 0x00000009)
#define HWIO_BIST_CTL_STATUS_OFFS                                         0x00000009
#define HWIO_BIST_CTL_STATUS_RMSK                                               0x1f
#define HWIO_BIST_CTL_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_STATUS_ADDR, HWIO_BIST_CTL_STATUS_RMSK, 0, val)
#define HWIO_BIST_CTL_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_STATUS_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_STATUS_ADDR, val, len)
#define HWIO_BIST_CTL_STATUS_INVALID_INDEX_BMSK                                 0x10
#define HWIO_BIST_CTL_STATUS_INVALID_INDEX_SHFT                                  0x4
#define HWIO_BIST_CTL_STATUS_BIST_WD_TO_BMSK                                     0x8
#define HWIO_BIST_CTL_STATUS_BIST_WD_TO_SHFT                                     0x3
#define HWIO_BIST_CTL_STATUS_BIST_RUN_BMSK                                       0x4
#define HWIO_BIST_CTL_STATUS_BIST_RUN_SHFT                                       0x2
#define HWIO_BIST_CTL_STATUS_FSM_STATUS_BMSK                                     0x3
#define HWIO_BIST_CTL_STATUS_FSM_STATUS_SHFT                                     0x0

#define HWIO_BIST_CTL_BIST_RESULTS_ADDR                                   (BIST_CTL_BASE            + 0x0000000a)
#define HWIO_BIST_CTL_BIST_RESULTS_OFFS                                   0x0000000a
#define HWIO_BIST_CTL_BIST_RESULTS_RMSK                                          0xf
#define HWIO_BIST_CTL_BIST_RESULTS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_BIST_RESULTS_ADDR, HWIO_BIST_CTL_BIST_RESULTS_RMSK, 0, val)
#define HWIO_BIST_CTL_BIST_RESULTS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_BIST_RESULTS_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_BIST_RESULTS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_BIST_RESULTS_ADDR, val, len)
#define HWIO_BIST_CTL_BIST_RESULTS_LBIST_RESULT_BMSK                             0xc
#define HWIO_BIST_CTL_BIST_RESULTS_LBIST_RESULT_SHFT                             0x2
#define HWIO_BIST_CTL_BIST_RESULTS_MBIST_RESULT_BMSK                             0x3
#define HWIO_BIST_CTL_BIST_RESULTS_MBIST_RESULT_SHFT                             0x0

#define HWIO_BIST_CTL_INCL_FEATURE_ADDR                                   (BIST_CTL_BASE            + 0x0000000f)
#define HWIO_BIST_CTL_INCL_FEATURE_OFFS                                   0x0000000f
#define HWIO_BIST_CTL_INCL_FEATURE_RMSK                                          0x1
#define HWIO_BIST_CTL_INCL_FEATURE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_INCL_FEATURE_ADDR, HWIO_BIST_CTL_INCL_FEATURE_RMSK, 0, val)
#define HWIO_BIST_CTL_INCL_FEATURE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_INCL_FEATURE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_INCL_FEATURE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_INCL_FEATURE_ADDR, val, len)
#define HWIO_BIST_CTL_INCL_FEATURE_RTC_EXIST_BMSK                                0x1
#define HWIO_BIST_CTL_INCL_FEATURE_RTC_EXIST_SHFT                                0x0

#define HWIO_BIST_CTL_RTC_ENABLE_STATE_ADDR                               (BIST_CTL_BASE            + 0x00000028)
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_OFFS                               0x00000028
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_RMSK                                      0x3
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_RTC_ENABLE_STATE_ADDR, HWIO_BIST_CTL_RTC_ENABLE_STATE_RMSK, 0, val)
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_RTC_ENABLE_STATE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_RTC_ENABLE_STATE_ADDR, val, len)
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_RTC_ENABLE_BMSK                           0x2
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_RTC_ENABLE_SHFT                           0x1
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_RTC_ALARM_ENABLE_BMSK                     0x1
#define HWIO_BIST_CTL_RTC_ENABLE_STATE_RTC_ALARM_ENABLE_SHFT                     0x0

#define HWIO_BIST_CTL_WDOG_CTL_ADDR                                       (BIST_CTL_BASE            + 0x00000031)
#define HWIO_BIST_CTL_WDOG_CTL_OFFS                                       0x00000031
#define HWIO_BIST_CTL_WDOG_CTL_RMSK                                              0x1
#define HWIO_BIST_CTL_WDOG_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_WDOG_CTL_ADDR, HWIO_BIST_CTL_WDOG_CTL_RMSK, 0, val)
#define HWIO_BIST_CTL_WDOG_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_WDOG_CTL_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_WDOG_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_WDOG_CTL_ADDR, val, len)
#define HWIO_BIST_CTL_WDOG_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_WDOG_CTL_ADDR, val)
#define HWIO_BIST_CTL_WDOG_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_WDOG_CTL_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_WDOG_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_WDOG_CTL_ADDR, val, len)
#define HWIO_BIST_CTL_WDOG_CTL_ENABLE_BMSK                                       0x1
#define HWIO_BIST_CTL_WDOG_CTL_ENABLE_SHFT                                       0x0

#define HWIO_BIST_CTL_WDOG_PET_ADDR                                       (BIST_CTL_BASE            + 0x00000032)
#define HWIO_BIST_CTL_WDOG_PET_OFFS                                       0x00000032
#define HWIO_BIST_CTL_WDOG_PET_RMSK                                              0x1
#define HWIO_BIST_CTL_WDOG_PET_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_WDOG_PET_ADDR, val)
#define HWIO_BIST_CTL_WDOG_PET_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_WDOG_PET_ADDR, val, len)
#define HWIO_BIST_CTL_WDOG_PET_PET_BMSK                                          0x1
#define HWIO_BIST_CTL_WDOG_PET_PET_SHFT                                          0x0

#define HWIO_BIST_CTL_WDOG_MAX_CNT_ADDR                                   (BIST_CTL_BASE            + 0x00000033)
#define HWIO_BIST_CTL_WDOG_MAX_CNT_OFFS                                   0x00000033
#define HWIO_BIST_CTL_WDOG_MAX_CNT_RMSK                                          0x3
#define HWIO_BIST_CTL_WDOG_MAX_CNT_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_WDOG_MAX_CNT_ADDR, HWIO_BIST_CTL_WDOG_MAX_CNT_RMSK, 0, val)
#define HWIO_BIST_CTL_WDOG_MAX_CNT_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_WDOG_MAX_CNT_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_WDOG_MAX_CNT_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_WDOG_MAX_CNT_ADDR, val, len)
#define HWIO_BIST_CTL_WDOG_MAX_CNT_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_WDOG_MAX_CNT_ADDR, val)
#define HWIO_BIST_CTL_WDOG_MAX_CNT_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_WDOG_MAX_CNT_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_WDOG_MAX_CNT_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_WDOG_MAX_CNT_ADDR, val, len)
#define HWIO_BIST_CTL_WDOG_MAX_CNT_WDOG_MAX_CNT_SEL_BMSK                         0x3
#define HWIO_BIST_CTL_WDOG_MAX_CNT_WDOG_MAX_CNT_SEL_SHFT                         0x0

#define HWIO_BIST_CTL_SCAN_RESET_OVRD_ADDR                                (BIST_CTL_BASE            + 0x00000034)
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_OFFS                                0x00000034
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_RMSK                                       0x3
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCAN_RESET_OVRD_ADDR, HWIO_BIST_CTL_SCAN_RESET_OVRD_RMSK, 0, val)
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCAN_RESET_OVRD_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCAN_RESET_OVRD_ADDR, val, len)
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCAN_RESET_OVRD_ADDR, val)
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCAN_RESET_OVRD_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCAN_RESET_OVRD_ADDR, val, len)
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_MBIST_SCAN_RESET_OVRD_BMSK                 0x2
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_MBIST_SCAN_RESET_OVRD_SHFT                 0x1
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_LBIST_SCAN_RESET_OVRD_BMSK                 0x1
#define HWIO_BIST_CTL_SCAN_RESET_OVRD_LBIST_SCAN_RESET_OVRD_SHFT                 0x0

#define HWIO_BIST_CTL_HFRC_DIV_CFG_ADDR                                   (BIST_CTL_BASE            + 0x00000035)
#define HWIO_BIST_CTL_HFRC_DIV_CFG_OFFS                                   0x00000035
#define HWIO_BIST_CTL_HFRC_DIV_CFG_RMSK                                         0x13
#define HWIO_BIST_CTL_HFRC_DIV_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_DIV_CFG_ADDR, HWIO_BIST_CTL_HFRC_DIV_CFG_RMSK, 0, val)
#define HWIO_BIST_CTL_HFRC_DIV_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_DIV_CFG_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_HFRC_DIV_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_HFRC_DIV_CFG_ADDR, val, len)
#define HWIO_BIST_CTL_HFRC_DIV_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_HFRC_DIV_CFG_ADDR, val)
#define HWIO_BIST_CTL_HFRC_DIV_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_DIV_CFG_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_HFRC_DIV_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_HFRC_DIV_CFG_ADDR, val, len)
#define HWIO_BIST_CTL_HFRC_DIV_CFG_LBIST_CAPT_DIV_RATIO_BMSK                    0x10
#define HWIO_BIST_CTL_HFRC_DIV_CFG_LBIST_CAPT_DIV_RATIO_SHFT                     0x4
#define HWIO_BIST_CTL_HFRC_DIV_CFG_LBIST_SHIFT_DIV_RATIO_BMSK                    0x3
#define HWIO_BIST_CTL_HFRC_DIV_CFG_LBIST_SHIFT_DIV_RATIO_SHFT                    0x0

#define HWIO_BIST_CTL_PMIC_STATE_ADDR                                     (BIST_CTL_BASE            + 0x00000040)
#define HWIO_BIST_CTL_PMIC_STATE_OFFS                                     0x00000040
#define HWIO_BIST_CTL_PMIC_STATE_RMSK                                            0x1
#define HWIO_BIST_CTL_PMIC_STATE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_PMIC_STATE_ADDR, HWIO_BIST_CTL_PMIC_STATE_RMSK, 0, val)
#define HWIO_BIST_CTL_PMIC_STATE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_PMIC_STATE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_PMIC_STATE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_PMIC_STATE_ADDR, val, len)
#define HWIO_BIST_CTL_PMIC_STATE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_PMIC_STATE_ADDR, val)
#define HWIO_BIST_CTL_PMIC_STATE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_PMIC_STATE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_PMIC_STATE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_PMIC_STATE_ADDR, val, len)
#define HWIO_BIST_CTL_PMIC_STATE_PMIC_OFF_BMSK                                   0x1
#define HWIO_BIST_CTL_PMIC_STATE_PMIC_OFF_SHFT                                   0x0

#define HWIO_BIST_CTL_SKIP_BIST_ADDR                                      (BIST_CTL_BASE            + 0x00000041)
#define HWIO_BIST_CTL_SKIP_BIST_OFFS                                      0x00000041
#define HWIO_BIST_CTL_SKIP_BIST_RMSK                                             0x3
#define HWIO_BIST_CTL_SKIP_BIST_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SKIP_BIST_ADDR, HWIO_BIST_CTL_SKIP_BIST_RMSK, 0, val)
#define HWIO_BIST_CTL_SKIP_BIST_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SKIP_BIST_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SKIP_BIST_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SKIP_BIST_ADDR, val, len)
#define HWIO_BIST_CTL_SKIP_BIST_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SKIP_BIST_ADDR, val)
#define HWIO_BIST_CTL_SKIP_BIST_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SKIP_BIST_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SKIP_BIST_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SKIP_BIST_ADDR, val, len)
#define HWIO_BIST_CTL_SKIP_BIST_SKIP_MBIST_BMSK                                  0x2
#define HWIO_BIST_CTL_SKIP_BIST_SKIP_MBIST_SHFT                                  0x1
#define HWIO_BIST_CTL_SKIP_BIST_SKIP_LBIST_BMSK                                  0x1
#define HWIO_BIST_CTL_SKIP_BIST_SKIP_LBIST_SHFT                                  0x0

#define HWIO_BIST_CTL_GPIO_ENABLE_ADDR                                    (BIST_CTL_BASE            + 0x00000042)
#define HWIO_BIST_CTL_GPIO_ENABLE_OFFS                                    0x00000042
#define HWIO_BIST_CTL_GPIO_ENABLE_RMSK                                           0x1
#define HWIO_BIST_CTL_GPIO_ENABLE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_GPIO_ENABLE_ADDR, HWIO_BIST_CTL_GPIO_ENABLE_RMSK, 0, val)
#define HWIO_BIST_CTL_GPIO_ENABLE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_GPIO_ENABLE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_GPIO_ENABLE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_GPIO_ENABLE_ADDR, val, len)
#define HWIO_BIST_CTL_GPIO_ENABLE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_GPIO_ENABLE_ADDR, val)
#define HWIO_BIST_CTL_GPIO_ENABLE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_GPIO_ENABLE_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_GPIO_ENABLE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_GPIO_ENABLE_ADDR, val, len)
#define HWIO_BIST_CTL_GPIO_ENABLE_EN_INPUT_BUF_GPIO_BMSK                         0x1
#define HWIO_BIST_CTL_GPIO_ENABLE_EN_INPUT_BUF_GPIO_SHFT                         0x0

#define HWIO_BIST_CTL_HFRC_CFG_ADDR                                       (BIST_CTL_BASE            + 0x00000043)
#define HWIO_BIST_CTL_HFRC_CFG_OFFS                                       0x00000043
#define HWIO_BIST_CTL_HFRC_CFG_RMSK                                             0x80
#define HWIO_BIST_CTL_HFRC_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_CFG_ADDR, HWIO_BIST_CTL_HFRC_CFG_RMSK, 0, val)
#define HWIO_BIST_CTL_HFRC_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_CFG_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_HFRC_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_HFRC_CFG_ADDR, val, len)
#define HWIO_BIST_CTL_HFRC_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_HFRC_CFG_ADDR, val)
#define HWIO_BIST_CTL_HFRC_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_CFG_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_HFRC_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_HFRC_CFG_ADDR, val, len)
#define HWIO_BIST_CTL_HFRC_CFG_FORCE_HFRC_OSC_ON_BMSK                           0x80
#define HWIO_BIST_CTL_HFRC_CFG_FORCE_HFRC_OSC_ON_SHFT                            0x7

#define HWIO_BIST_CTL_BIST_CTL1_ADDR                                      (BIST_CTL_BASE            + 0x00000044)
#define HWIO_BIST_CTL_BIST_CTL1_OFFS                                      0x00000044
#define HWIO_BIST_CTL_BIST_CTL1_RMSK                                             0x3
#define HWIO_BIST_CTL_BIST_CTL1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_BIST_CTL1_ADDR, val)
#define HWIO_BIST_CTL_BIST_CTL1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_BIST_CTL1_ADDR, val, len)
#define HWIO_BIST_CTL_BIST_CTL1_CLEAR_BIST_RESULTS_BMSK                          0x2
#define HWIO_BIST_CTL_BIST_CTL1_CLEAR_BIST_RESULTS_SHFT                          0x1
#define HWIO_BIST_CTL_BIST_CTL1_TRIGGER_BIST_BMSK                                0x1
#define HWIO_BIST_CTL_BIST_CTL1_TRIGGER_BIST_SHFT                                0x0

#define HWIO_BIST_CTL_DEBUG_ADDR                                          (BIST_CTL_BASE            + 0x00000045)
#define HWIO_BIST_CTL_DEBUG_OFFS                                          0x00000045
#define HWIO_BIST_CTL_DEBUG_RMSK                                                 0x1
#define HWIO_BIST_CTL_DEBUG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_DEBUG_ADDR, HWIO_BIST_CTL_DEBUG_RMSK, 0, val)
#define HWIO_BIST_CTL_DEBUG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_DEBUG_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_DEBUG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_DEBUG_ADDR, val, len)
#define HWIO_BIST_CTL_DEBUG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_DEBUG_ADDR, val)
#define HWIO_BIST_CTL_DEBUG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_DEBUG_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_DEBUG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_DEBUG_ADDR, val, len)
#define HWIO_BIST_CTL_DEBUG_DEBUG_MODE_BMSK                                      0x1
#define HWIO_BIST_CTL_DEBUG_DEBUG_MODE_SHFT                                      0x0

#define HWIO_BIST_CTL_SCRATCH_0_ADDR                                      (BIST_CTL_BASE            + 0x00000050)
#define HWIO_BIST_CTL_SCRATCH_0_OFFS                                      0x00000050
#define HWIO_BIST_CTL_SCRATCH_0_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_0_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_0_ADDR, HWIO_BIST_CTL_SCRATCH_0_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_0_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_0_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_0_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_0_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_0_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_0_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_0_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_0_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_0_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_0_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_0_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_0_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_1_ADDR                                      (BIST_CTL_BASE            + 0x00000051)
#define HWIO_BIST_CTL_SCRATCH_1_OFFS                                      0x00000051
#define HWIO_BIST_CTL_SCRATCH_1_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_1_ADDR, HWIO_BIST_CTL_SCRATCH_1_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_1_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_1_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_1_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_1_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_1_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_1_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_1_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_2_ADDR                                      (BIST_CTL_BASE            + 0x00000052)
#define HWIO_BIST_CTL_SCRATCH_2_OFFS                                      0x00000052
#define HWIO_BIST_CTL_SCRATCH_2_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_2_ADDR, HWIO_BIST_CTL_SCRATCH_2_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_2_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_2_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_2_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_2_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_2_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_2_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_2_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_3_ADDR                                      (BIST_CTL_BASE            + 0x00000053)
#define HWIO_BIST_CTL_SCRATCH_3_OFFS                                      0x00000053
#define HWIO_BIST_CTL_SCRATCH_3_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_3_ADDR, HWIO_BIST_CTL_SCRATCH_3_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_3_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_3_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_3_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_3_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_3_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_3_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_3_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_4_ADDR                                      (BIST_CTL_BASE            + 0x00000054)
#define HWIO_BIST_CTL_SCRATCH_4_OFFS                                      0x00000054
#define HWIO_BIST_CTL_SCRATCH_4_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_4_ADDR, HWIO_BIST_CTL_SCRATCH_4_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_4_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_4_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_4_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_4_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_4_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_4_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_4_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_4_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_4_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_4_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_5_ADDR                                      (BIST_CTL_BASE            + 0x00000055)
#define HWIO_BIST_CTL_SCRATCH_5_OFFS                                      0x00000055
#define HWIO_BIST_CTL_SCRATCH_5_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_5_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_5_ADDR, HWIO_BIST_CTL_SCRATCH_5_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_5_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_5_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_5_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_5_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_5_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_5_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_5_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_5_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_5_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_5_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_5_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_5_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_6_ADDR                                      (BIST_CTL_BASE            + 0x00000056)
#define HWIO_BIST_CTL_SCRATCH_6_OFFS                                      0x00000056
#define HWIO_BIST_CTL_SCRATCH_6_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_6_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_6_ADDR, HWIO_BIST_CTL_SCRATCH_6_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_6_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_6_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_6_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_6_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_6_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_6_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_6_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_6_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_6_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_6_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_6_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_6_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_7_ADDR                                      (BIST_CTL_BASE            + 0x00000057)
#define HWIO_BIST_CTL_SCRATCH_7_OFFS                                      0x00000057
#define HWIO_BIST_CTL_SCRATCH_7_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_7_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_7_ADDR, HWIO_BIST_CTL_SCRATCH_7_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_7_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_7_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_7_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_7_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_7_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_7_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_7_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_7_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_7_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_7_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_7_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_7_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_8_ADDR                                      (BIST_CTL_BASE            + 0x00000058)
#define HWIO_BIST_CTL_SCRATCH_8_OFFS                                      0x00000058
#define HWIO_BIST_CTL_SCRATCH_8_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_8_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_8_ADDR, HWIO_BIST_CTL_SCRATCH_8_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_8_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_8_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_8_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_8_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_8_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_8_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_8_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_8_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_8_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_8_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_8_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_8_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_9_ADDR                                      (BIST_CTL_BASE            + 0x00000059)
#define HWIO_BIST_CTL_SCRATCH_9_OFFS                                      0x00000059
#define HWIO_BIST_CTL_SCRATCH_9_RMSK                                            0xff
#define HWIO_BIST_CTL_SCRATCH_9_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_9_ADDR, HWIO_BIST_CTL_SCRATCH_9_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_9_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_9_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_9_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_9_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_9_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_9_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_9_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_9_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_9_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_9_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_9_SCRATCH_VAL_BMSK                                0xff
#define HWIO_BIST_CTL_SCRATCH_9_SCRATCH_VAL_SHFT                                 0x0

#define HWIO_BIST_CTL_SCRATCH_10_ADDR                                     (BIST_CTL_BASE            + 0x0000005a)
#define HWIO_BIST_CTL_SCRATCH_10_OFFS                                     0x0000005a
#define HWIO_BIST_CTL_SCRATCH_10_RMSK                                           0xff
#define HWIO_BIST_CTL_SCRATCH_10_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_10_ADDR, HWIO_BIST_CTL_SCRATCH_10_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_10_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_10_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_10_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_10_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_10_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_10_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_10_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_10_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_10_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_10_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_10_SCRATCH_VAL_BMSK                               0xff
#define HWIO_BIST_CTL_SCRATCH_10_SCRATCH_VAL_SHFT                                0x0

#define HWIO_BIST_CTL_SCRATCH_11_ADDR                                     (BIST_CTL_BASE            + 0x0000005b)
#define HWIO_BIST_CTL_SCRATCH_11_OFFS                                     0x0000005b
#define HWIO_BIST_CTL_SCRATCH_11_RMSK                                           0xff
#define HWIO_BIST_CTL_SCRATCH_11_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_11_ADDR, HWIO_BIST_CTL_SCRATCH_11_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_11_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_11_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_11_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_11_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_11_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_11_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_11_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_11_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_11_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_11_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_11_SCRATCH_VAL_BMSK                               0xff
#define HWIO_BIST_CTL_SCRATCH_11_SCRATCH_VAL_SHFT                                0x0

#define HWIO_BIST_CTL_SCRATCH_12_ADDR                                     (BIST_CTL_BASE            + 0x0000005c)
#define HWIO_BIST_CTL_SCRATCH_12_OFFS                                     0x0000005c
#define HWIO_BIST_CTL_SCRATCH_12_RMSK                                           0xff
#define HWIO_BIST_CTL_SCRATCH_12_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_12_ADDR, HWIO_BIST_CTL_SCRATCH_12_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_12_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_12_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_12_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_12_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_12_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_12_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_12_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_12_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_12_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_12_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_12_SCRATCH_VAL_BMSK                               0xff
#define HWIO_BIST_CTL_SCRATCH_12_SCRATCH_VAL_SHFT                                0x0

#define HWIO_BIST_CTL_SCRATCH_13_ADDR                                     (BIST_CTL_BASE            + 0x0000005d)
#define HWIO_BIST_CTL_SCRATCH_13_OFFS                                     0x0000005d
#define HWIO_BIST_CTL_SCRATCH_13_RMSK                                           0xff
#define HWIO_BIST_CTL_SCRATCH_13_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_13_ADDR, HWIO_BIST_CTL_SCRATCH_13_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_13_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_13_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_13_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_13_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_13_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_13_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_13_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_13_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_13_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_13_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_13_SCRATCH_VAL_BMSK                               0xff
#define HWIO_BIST_CTL_SCRATCH_13_SCRATCH_VAL_SHFT                                0x0

#define HWIO_BIST_CTL_SCRATCH_14_ADDR                                     (BIST_CTL_BASE            + 0x0000005e)
#define HWIO_BIST_CTL_SCRATCH_14_OFFS                                     0x0000005e
#define HWIO_BIST_CTL_SCRATCH_14_RMSK                                           0xff
#define HWIO_BIST_CTL_SCRATCH_14_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_14_ADDR, HWIO_BIST_CTL_SCRATCH_14_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_14_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_14_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_14_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_14_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_14_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_14_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_14_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_14_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_14_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_14_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_14_SCRATCH_VAL_BMSK                               0xff
#define HWIO_BIST_CTL_SCRATCH_14_SCRATCH_VAL_SHFT                                0x0

#define HWIO_BIST_CTL_SCRATCH_15_ADDR                                     (BIST_CTL_BASE            + 0x0000005f)
#define HWIO_BIST_CTL_SCRATCH_15_OFFS                                     0x0000005f
#define HWIO_BIST_CTL_SCRATCH_15_RMSK                                           0xff
#define HWIO_BIST_CTL_SCRATCH_15_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_15_ADDR, HWIO_BIST_CTL_SCRATCH_15_RMSK, 0, val)
#define HWIO_BIST_CTL_SCRATCH_15_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_15_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_15_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_15_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_15_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_15_ADDR, val)
#define HWIO_BIST_CTL_SCRATCH_15_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_15_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_SCRATCH_15_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_SCRATCH_15_ADDR, val, len)
#define HWIO_BIST_CTL_SCRATCH_15_SCRATCH_VAL_BMSK                               0xff
#define HWIO_BIST_CTL_SCRATCH_15_SCRATCH_VAL_SHFT                                0x0

#define HWIO_BIST_CTL_LOCKBIT_D1_ADDR                                     (BIST_CTL_BASE            + 0x000000d1)
#define HWIO_BIST_CTL_LOCKBIT_D1_OFFS                                     0x000000d1
#define HWIO_BIST_CTL_LOCKBIT_D1_RMSK                                            0x3
#define HWIO_BIST_CTL_LOCKBIT_D1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_LOCKBIT_D1_ADDR, HWIO_BIST_CTL_LOCKBIT_D1_RMSK, 0, val)
#define HWIO_BIST_CTL_LOCKBIT_D1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_LOCKBIT_D1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_LOCKBIT_D1_ADDR, val, len)
#define HWIO_BIST_CTL_LOCKBIT_D1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_LOCKBIT_D1_ADDR, val)
#define HWIO_BIST_CTL_LOCKBIT_D1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_LOCKBIT_D1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_LOCKBIT_D1_ADDR, val, len)
#define HWIO_BIST_CTL_LOCKBIT_D1_LOCKBIT_D1_BMSK                                 0x3
#define HWIO_BIST_CTL_LOCKBIT_D1_LOCKBIT_D1_SHFT                                 0x0

#define HWIO_BIST_CTL_DTEST_ADDR                                          (BIST_CTL_BASE            + 0x000000e2)
#define HWIO_BIST_CTL_DTEST_OFFS                                          0x000000e2
#define HWIO_BIST_CTL_DTEST_RMSK                                                 0x7
#define HWIO_BIST_CTL_DTEST_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_DTEST_ADDR, HWIO_BIST_CTL_DTEST_RMSK, 0, val)
#define HWIO_BIST_CTL_DTEST_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_DTEST_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_DTEST_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_DTEST_ADDR, val, len)
#define HWIO_BIST_CTL_DTEST_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_DTEST_ADDR, val)
#define HWIO_BIST_CTL_DTEST_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_DTEST_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_DTEST_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_DTEST_ADDR, val, len)
#define HWIO_BIST_CTL_DTEST_SEL_BMSK                                             0x7
#define HWIO_BIST_CTL_DTEST_SEL_SHFT                                             0x0

#define HWIO_BIST_CTL_TRIM_NUM_ADDR                                       (BIST_CTL_BASE            + 0x000000f0)
#define HWIO_BIST_CTL_TRIM_NUM_OFFS                                       0x000000f0
#define HWIO_BIST_CTL_TRIM_NUM_RMSK                                              0xf
#define HWIO_BIST_CTL_TRIM_NUM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_TRIM_NUM_ADDR, HWIO_BIST_CTL_TRIM_NUM_RMSK, 0, val)
#define HWIO_BIST_CTL_TRIM_NUM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_TRIM_NUM_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_TRIM_NUM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_TRIM_NUM_ADDR, val, len)
#define HWIO_BIST_CTL_TRIM_NUM_TRIM_NUM_BMSK                                     0xf
#define HWIO_BIST_CTL_TRIM_NUM_TRIM_NUM_SHFT                                     0x0

#define HWIO_BIST_CTL_HFRC_TRIM_ADDR                                      (BIST_CTL_BASE            + 0x000000f1)
#define HWIO_BIST_CTL_HFRC_TRIM_OFFS                                      0x000000f1
#define HWIO_BIST_CTL_HFRC_TRIM_RMSK                                            0x3f
#define HWIO_BIST_CTL_HFRC_TRIM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_TRIM_ADDR, HWIO_BIST_CTL_HFRC_TRIM_RMSK, 0, val)
#define HWIO_BIST_CTL_HFRC_TRIM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_TRIM_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_HFRC_TRIM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_BIST_CTL_HFRC_TRIM_ADDR, val, len)
#define HWIO_BIST_CTL_HFRC_TRIM_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_BIST_CTL_HFRC_TRIM_ADDR, val)
#define HWIO_BIST_CTL_HFRC_TRIM_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_BIST_CTL_HFRC_TRIM_ADDR, mask, shift, val)
#define HWIO_BIST_CTL_HFRC_TRIM_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_BIST_CTL_HFRC_TRIM_ADDR, val, len)
#define HWIO_BIST_CTL_HFRC_TRIM_HFRC_TRIM_BMSK                                  0x3f
#define HWIO_BIST_CTL_HFRC_TRIM_HFRC_TRIM_SHFT                                   0x0

/*----------------------------------------------------------------------------
 * PERIPHERAL: PON_PBS
 *--------------------------------------------------------------------------*/

#define PON_PBS_BASE                                                          0x00000800

#define HWIO_PON_PBS_REVISION1_ADDR                                           (PON_PBS_BASE            + 0x00000000)
#define HWIO_PON_PBS_REVISION1_OFFS                                           0x00000000
#define HWIO_PON_PBS_REVISION1_RMSK                                                 0xff
#define HWIO_PON_PBS_REVISION1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION1_ADDR, HWIO_PON_PBS_REVISION1_RMSK, 0, val)
#define HWIO_PON_PBS_REVISION1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_REVISION1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_REVISION1_ADDR, val, len)
#define HWIO_PON_PBS_REVISION1_DIG_MINOR_BMSK                                       0xff
#define HWIO_PON_PBS_REVISION1_DIG_MINOR_SHFT                                        0x0

#define HWIO_PON_PBS_REVISION2_ADDR                                           (PON_PBS_BASE            + 0x00000001)
#define HWIO_PON_PBS_REVISION2_OFFS                                           0x00000001
#define HWIO_PON_PBS_REVISION2_RMSK                                                 0xff
#define HWIO_PON_PBS_REVISION2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION2_ADDR, HWIO_PON_PBS_REVISION2_RMSK, 0, val)
#define HWIO_PON_PBS_REVISION2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_REVISION2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_REVISION2_ADDR, val, len)
#define HWIO_PON_PBS_REVISION2_DIG_MAJOR_BMSK                                       0xff
#define HWIO_PON_PBS_REVISION2_DIG_MAJOR_SHFT                                        0x0

#define HWIO_PON_PBS_REVISION3_ADDR                                           (PON_PBS_BASE            + 0x00000002)
#define HWIO_PON_PBS_REVISION3_OFFS                                           0x00000002
#define HWIO_PON_PBS_REVISION3_RMSK                                                 0xff
#define HWIO_PON_PBS_REVISION3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION3_ADDR, HWIO_PON_PBS_REVISION3_RMSK, 0, val)
#define HWIO_PON_PBS_REVISION3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION3_ADDR, mask, shift, val)
#define HWIO_PON_PBS_REVISION3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_REVISION3_ADDR, val, len)
#define HWIO_PON_PBS_REVISION3_ANA_MINOR_BMSK                                       0xff
#define HWIO_PON_PBS_REVISION3_ANA_MINOR_SHFT                                        0x0

#define HWIO_PON_PBS_REVISION4_ADDR                                           (PON_PBS_BASE            + 0x00000003)
#define HWIO_PON_PBS_REVISION4_OFFS                                           0x00000003
#define HWIO_PON_PBS_REVISION4_RMSK                                                 0xff
#define HWIO_PON_PBS_REVISION4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION4_ADDR, HWIO_PON_PBS_REVISION4_RMSK, 0, val)
#define HWIO_PON_PBS_REVISION4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REVISION4_ADDR, mask, shift, val)
#define HWIO_PON_PBS_REVISION4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_REVISION4_ADDR, val, len)
#define HWIO_PON_PBS_REVISION4_ANA_MAJOR_BMSK                                       0xff
#define HWIO_PON_PBS_REVISION4_ANA_MAJOR_SHFT                                        0x0

#define HWIO_PON_PBS_PERPH_TYPE_ADDR                                          (PON_PBS_BASE            + 0x00000004)
#define HWIO_PON_PBS_PERPH_TYPE_OFFS                                          0x00000004
#define HWIO_PON_PBS_PERPH_TYPE_RMSK                                                0xff
#define HWIO_PON_PBS_PERPH_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_TYPE_ADDR, HWIO_PON_PBS_PERPH_TYPE_RMSK, 0, val)
#define HWIO_PON_PBS_PERPH_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_TYPE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_TYPE_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_TYPE_TYPE_BMSK                                           0xff
#define HWIO_PON_PBS_PERPH_TYPE_TYPE_SHFT                                            0x0

#define HWIO_PON_PBS_PERPH_SUBTYPE_ADDR                                       (PON_PBS_BASE            + 0x00000005)
#define HWIO_PON_PBS_PERPH_SUBTYPE_OFFS                                       0x00000005
#define HWIO_PON_PBS_PERPH_SUBTYPE_RMSK                                             0xff
#define HWIO_PON_PBS_PERPH_SUBTYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_SUBTYPE_ADDR, HWIO_PON_PBS_PERPH_SUBTYPE_RMSK, 0, val)
#define HWIO_PON_PBS_PERPH_SUBTYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_SUBTYPE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_SUBTYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_SUBTYPE_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_SUBTYPE_SUBTYPE_BMSK                                     0xff
#define HWIO_PON_PBS_PERPH_SUBTYPE_SUBTYPE_SHFT                                      0x0

#define HWIO_PON_PBS_SOFT_TYPE_ADDR                                           (PON_PBS_BASE            + 0x00000006)
#define HWIO_PON_PBS_SOFT_TYPE_OFFS                                           0x00000006
#define HWIO_PON_PBS_SOFT_TYPE_RMSK                                                 0xff
#define HWIO_PON_PBS_SOFT_TYPE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_SOFT_TYPE_ADDR, HWIO_PON_PBS_SOFT_TYPE_RMSK, 0, val)
#define HWIO_PON_PBS_SOFT_TYPE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_SOFT_TYPE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_SOFT_TYPE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_SOFT_TYPE_ADDR, val, len)
#define HWIO_PON_PBS_SOFT_TYPE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_SOFT_TYPE_ADDR, val)
#define HWIO_PON_PBS_SOFT_TYPE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_SOFT_TYPE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_SOFT_TYPE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_SOFT_TYPE_ADDR, val, len)
#define HWIO_PON_PBS_SOFT_TYPE_SOFTTYPE_BMSK                                        0xff
#define HWIO_PON_PBS_SOFT_TYPE_SOFTTYPE_SHFT                                         0x0

#define HWIO_PON_PBS_PON_PBL_STATUS_ADDR                                      (PON_PBS_BASE            + 0x00000007)
#define HWIO_PON_PBS_PON_PBL_STATUS_OFFS                                      0x00000007
#define HWIO_PON_PBS_PON_PBL_STATUS_RMSK                                            0xc0
#define HWIO_PON_PBS_PON_PBL_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PON_PBL_STATUS_ADDR, HWIO_PON_PBS_PON_PBL_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_PON_PBL_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PON_PBL_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PON_PBL_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PON_PBL_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_PON_PBL_STATUS_DVDD_RB_OCCURRED_BMSK                           0x80
#define HWIO_PON_PBS_PON_PBL_STATUS_DVDD_RB_OCCURRED_SHFT                            0x7
#define HWIO_PON_PBS_PON_PBL_STATUS_XVDD_RB_OCCURRED_BMSK                           0x40
#define HWIO_PON_PBS_PON_PBL_STATUS_XVDD_RB_OCCURRED_SHFT                            0x6

#define HWIO_PON_PBS_HW_STATUS_ADDR                                           (PON_PBS_BASE            + 0x00000008)
#define HWIO_PON_PBS_HW_STATUS_OFFS                                           0x00000008
#define HWIO_PON_PBS_HW_STATUS_RMSK                                                  0x3
#define HWIO_PON_PBS_HW_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_HW_STATUS_ADDR, HWIO_PON_PBS_HW_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_HW_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_HW_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_HW_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_HW_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_HW_STATUS_FAULT_N_PIN_BMSK                                      0x2
#define HWIO_PON_PBS_HW_STATUS_FAULT_N_PIN_SHFT                                      0x1
#define HWIO_PON_PBS_HW_STATUS_FSM_STATE_BMSK                                        0x1
#define HWIO_PON_PBS_HW_STATUS_FSM_STATE_SHFT                                        0x0

#define HWIO_PON_PBS_PBS_FSM_STATUS_ADDR                                      (PON_PBS_BASE            + 0x00000009)
#define HWIO_PON_PBS_PBS_FSM_STATUS_OFFS                                      0x00000009
#define HWIO_PON_PBS_PBS_FSM_STATUS_RMSK                                            0xff
#define HWIO_PON_PBS_PBS_FSM_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PBS_FSM_STATUS_ADDR, HWIO_PON_PBS_PBS_FSM_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_PBS_FSM_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PBS_FSM_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PBS_FSM_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PBS_FSM_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_PBS_FSM_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_PBS_FSM_STATUS_ADDR, val)
#define HWIO_PON_PBS_PBS_FSM_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PBS_FSM_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PBS_FSM_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_PBS_FSM_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_PBS_FSM_STATUS_PBS_FSM_STATE_BMSK                              0xff
#define HWIO_PON_PBS_PBS_FSM_STATUS_PBS_FSM_STATE_SHFT                               0x0

#define HWIO_PON_PBS_PAR1_ADDR                                                (PON_PBS_BASE            + 0x0000000a)
#define HWIO_PON_PBS_PAR1_OFFS                                                0x0000000a
#define HWIO_PON_PBS_PAR1_RMSK                                                      0xf7
#define HWIO_PON_PBS_PAR1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR1_ADDR, HWIO_PON_PBS_PAR1_RMSK, 0, val)
#define HWIO_PON_PBS_PAR1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PAR1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PAR1_ADDR, val, len)
#define HWIO_PON_PBS_PAR1_HAS_KPD_RESIN_BMSK                                        0x80
#define HWIO_PON_PBS_PAR1_HAS_KPD_RESIN_SHFT                                         0x7
#define HWIO_PON_PBS_PAR1_RESIN_TYPE_BMSK                                           0x70
#define HWIO_PON_PBS_PAR1_RESIN_TYPE_SHFT                                            0x4
#define HWIO_PON_PBS_PAR1_KPD_TYPE_BMSK                                              0x7
#define HWIO_PON_PBS_PAR1_KPD_TYPE_SHFT                                              0x0

#define HWIO_PON_PBS_PAR2_ADDR                                                (PON_PBS_BASE            + 0x0000000b)
#define HWIO_PON_PBS_PAR2_OFFS                                                0x0000000b
#define HWIO_PON_PBS_PAR2_RMSK                                                      0xf7
#define HWIO_PON_PBS_PAR2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR2_ADDR, HWIO_PON_PBS_PAR2_RMSK, 0, val)
#define HWIO_PON_PBS_PAR2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PAR2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PAR2_ADDR, val, len)
#define HWIO_PON_PBS_PAR2_HAS_PMIC_WDOG_BMSK                                        0x80
#define HWIO_PON_PBS_PAR2_HAS_PMIC_WDOG_SHFT                                         0x7
#define HWIO_PON_PBS_PAR2_PSHOLD_TYPE_BMSK                                          0x70
#define HWIO_PON_PBS_PAR2_PSHOLD_TYPE_SHFT                                           0x4
#define HWIO_PON_PBS_PAR2_PON_RESET_N_TYPE_BMSK                                      0x7
#define HWIO_PON_PBS_PAR2_PON_RESET_N_TYPE_SHFT                                      0x0

#define HWIO_PON_PBS_PAR3_ADDR                                                (PON_PBS_BASE            + 0x0000000c)
#define HWIO_PON_PBS_PAR3_OFFS                                                0x0000000c
#define HWIO_PON_PBS_PAR3_RMSK                                                      0xf3
#define HWIO_PON_PBS_PAR3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR3_ADDR, HWIO_PON_PBS_PAR3_RMSK, 0, val)
#define HWIO_PON_PBS_PAR3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR3_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PAR3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PAR3_ADDR, val, len)
#define HWIO_PON_PBS_PAR3_NUM_OF_RESET_TRIGGER_BMSK                                 0xc0
#define HWIO_PON_PBS_PAR3_NUM_OF_RESET_TRIGGER_SHFT                                  0x6
#define HWIO_PON_PBS_PAR3_XVLO_TYPE_BMSK                                            0x30
#define HWIO_PON_PBS_PAR3_XVLO_TYPE_SHFT                                             0x4
#define HWIO_PON_PBS_PAR3_PMIC_RB_TYPE_BMSK                                          0x3
#define HWIO_PON_PBS_PAR3_PMIC_RB_TYPE_SHFT                                          0x0

#define HWIO_PON_PBS_PAR4_ADDR                                                (PON_PBS_BASE            + 0x0000000d)
#define HWIO_PON_PBS_PAR4_OFFS                                                0x0000000d
#define HWIO_PON_PBS_PAR4_RMSK                                                       0xf
#define HWIO_PON_PBS_PAR4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR4_ADDR, HWIO_PON_PBS_PAR4_RMSK, 0, val)
#define HWIO_PON_PBS_PAR4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PAR4_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PAR4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PAR4_ADDR, val, len)
#define HWIO_PON_PBS_PAR4_PON_1_TYPE_BMSK                                            0xc
#define HWIO_PON_PBS_PAR4_PON_1_TYPE_SHFT                                            0x2
#define HWIO_PON_PBS_PAR4_FAULTN_TYPE_BMSK                                           0x3
#define HWIO_PON_PBS_PAR4_FAULTN_TYPE_SHFT                                           0x0

#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_ADDR                              (PON_PBS_BASE            + 0x00000044)
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_OFFS                              0x00000044
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_RMSK                                     0xf
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_ADDR, HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_ADDR, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_S1_TIMER_BMSK                            0xf
#define HWIO_PON_PBS_RESIN_N_RESET_S1_TIMER_S1_TIMER_SHFT                            0x0

#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_ADDR                              (PON_PBS_BASE            + 0x00000045)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_OFFS                              0x00000045
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_RMSK                                     0x7
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_ADDR, HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_ADDR, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_S2_TIMER_BMSK                            0x7
#define HWIO_PON_PBS_RESIN_N_RESET_S2_TIMER_S2_TIMER_SHFT                            0x0

#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_ADDR                                (PON_PBS_BASE            + 0x00000046)
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_OFFS                                0x00000046
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_RMSK                                      0xff
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_ADDR, HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_ADDR, val)
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_RESET_TYPE_BMSK                           0xff
#define HWIO_PON_PBS_RESIN_N_RESET_SW_CTL_RESET_TYPE_SHFT                            0x0

#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_ADDR                               (PON_PBS_BASE            + 0x00000047)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_OFFS                               0x00000047
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_RMSK                                     0x80
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_ADDR, HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_ADDR, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_S2_RESET_EN_BMSK                         0x80
#define HWIO_PON_PBS_RESIN_N_RESET_S2_CTL2_S2_RESET_EN_SHFT                          0x7

#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_ADDR                     (PON_PBS_BASE            + 0x00000048)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_OFFS                     0x00000048
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_RMSK                            0xf
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_ADDR, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_ADDR, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_S1_TIMER_BMSK                   0xf
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S1_TIMER_S1_TIMER_SHFT                   0x0

#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_ADDR                     (PON_PBS_BASE            + 0x00000049)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_OFFS                     0x00000049
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_RMSK                            0x7
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_ADDR, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_ADDR, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_S2_TIMER_BMSK                   0x7
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_TIMER_S2_TIMER_SHFT                   0x0

#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_ADDR                       (PON_PBS_BASE            + 0x0000004a)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_OFFS                       0x0000004a
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_RMSK                             0xff
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_ADDR, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_ADDR, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_RESET_TYPE_BMSK                  0xff
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_SW_CTL_RESET_TYPE_SHFT                   0x0

#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_ADDR                      (PON_PBS_BASE            + 0x0000004b)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_OFFS                      0x0000004b
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_RMSK                            0x80
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_ADDR, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_RMSK, 0, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_ADDR, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_ADDR, val, len)
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_S2_RESET_EN_BMSK                0x80
#define HWIO_PON_PBS_RESIN_AND_KPDPWR_RESET_S2_CTL2_S2_RESET_EN_SHFT                 0x7

#define HWIO_PON_PBS_SW_RESET_SW_CTL_ADDR                                     (PON_PBS_BASE            + 0x00000056)
#define HWIO_PON_PBS_SW_RESET_SW_CTL_OFFS                                     0x00000056
#define HWIO_PON_PBS_SW_RESET_SW_CTL_RMSK                                           0xff
#define HWIO_PON_PBS_SW_RESET_SW_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_SW_RESET_SW_CTL_ADDR, HWIO_PON_PBS_SW_RESET_SW_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_SW_RESET_SW_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_SW_RESET_SW_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_SW_RESET_SW_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_SW_RESET_SW_CTL_ADDR, val, len)
#define HWIO_PON_PBS_SW_RESET_SW_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_SW_RESET_SW_CTL_ADDR, val)
#define HWIO_PON_PBS_SW_RESET_SW_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_SW_RESET_SW_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_SW_RESET_SW_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_SW_RESET_SW_CTL_ADDR, val, len)
#define HWIO_PON_PBS_SW_RESET_SW_CTL_RESET_TYPE_BMSK                                0xff
#define HWIO_PON_PBS_SW_RESET_SW_CTL_RESET_TYPE_SHFT                                 0x0

#define HWIO_PON_PBS_SW_RESET_GO_ADDR                                         (PON_PBS_BASE            + 0x00000057)
#define HWIO_PON_PBS_SW_RESET_GO_OFFS                                         0x00000057
#define HWIO_PON_PBS_SW_RESET_GO_RMSK                                               0xff
#define HWIO_PON_PBS_SW_RESET_GO_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_SW_RESET_GO_ADDR, val)
#define HWIO_PON_PBS_SW_RESET_GO_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_SW_RESET_GO_ADDR, val, len)
#define HWIO_PON_PBS_SW_RESET_GO_SW_RESET_GO_BMSK                                   0xff
#define HWIO_PON_PBS_SW_RESET_GO_SW_RESET_GO_SHFT                                    0x0

#define HWIO_PON_PBS_PON_SW_CFG_ADDR                                          (PON_PBS_BASE            + 0x00000060)
#define HWIO_PON_PBS_PON_SW_CFG_OFFS                                          0x00000060
#define HWIO_PON_PBS_PON_SW_CFG_RMSK                                                0x80
#define HWIO_PON_PBS_PON_SW_CFG_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PON_SW_CFG_ADDR, HWIO_PON_PBS_PON_SW_CFG_RMSK, 0, val)
#define HWIO_PON_PBS_PON_SW_CFG_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PON_SW_CFG_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PON_SW_CFG_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PON_SW_CFG_ADDR, val, len)
#define HWIO_PON_PBS_PON_SW_CFG_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_PON_SW_CFG_ADDR, val)
#define HWIO_PON_PBS_PON_SW_CFG_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PON_SW_CFG_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PON_SW_CFG_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_PON_SW_CFG_ADDR, val, len)
#define HWIO_PON_PBS_PON_SW_CFG_WARM_RESET_BMSK                                     0x80
#define HWIO_PON_PBS_PON_SW_CFG_WARM_RESET_SHFT                                      0x7

#define HWIO_PON_PBS_PULL_CTL_ADDR                                            (PON_PBS_BASE            + 0x00000070)
#define HWIO_PON_PBS_PULL_CTL_OFFS                                            0x00000070
#define HWIO_PON_PBS_PULL_CTL_RMSK                                                  0x7f
#define HWIO_PON_PBS_PULL_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PULL_CTL_ADDR, HWIO_PON_PBS_PULL_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_PULL_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PULL_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PULL_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PULL_CTL_ADDR, val, len)
#define HWIO_PON_PBS_PULL_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_PULL_CTL_ADDR, val)
#define HWIO_PON_PBS_PULL_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PULL_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PULL_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_PULL_CTL_ADDR, val, len)
#define HWIO_PON_PBS_PULL_CTL_PS_HOLD_PD_EN_BMSK                                    0x40
#define HWIO_PON_PBS_PULL_CTL_PS_HOLD_PD_EN_SHFT                                     0x6
#define HWIO_PON_PBS_PULL_CTL_KPDPWR_N_PD_EN_BMSK                                   0x20
#define HWIO_PON_PBS_PULL_CTL_KPDPWR_N_PD_EN_SHFT                                    0x5
#define HWIO_PON_PBS_PULL_CTL_RESIN_N_PD_EN_BMSK                                    0x10
#define HWIO_PON_PBS_PULL_CTL_RESIN_N_PD_EN_SHFT                                     0x4
#define HWIO_PON_PBS_PULL_CTL_PON1_PD_EN_BMSK                                        0x8
#define HWIO_PON_PBS_PULL_CTL_PON1_PD_EN_SHFT                                        0x3
#define HWIO_PON_PBS_PULL_CTL_CBLPWR_N_PU_EN_BMSK                                    0x4
#define HWIO_PON_PBS_PULL_CTL_CBLPWR_N_PU_EN_SHFT                                    0x2
#define HWIO_PON_PBS_PULL_CTL_KPDPWR_N_PU_EN_BMSK                                    0x2
#define HWIO_PON_PBS_PULL_CTL_KPDPWR_N_PU_EN_SHFT                                    0x1
#define HWIO_PON_PBS_PULL_CTL_RESIN_N_PU_EN_BMSK                                     0x1
#define HWIO_PON_PBS_PULL_CTL_RESIN_N_PU_EN_SHFT                                     0x0

#define HWIO_PON_PBS_DEBOUNCE_CTL_ADDR                                        (PON_PBS_BASE            + 0x00000071)
#define HWIO_PON_PBS_DEBOUNCE_CTL_OFFS                                        0x00000071
#define HWIO_PON_PBS_DEBOUNCE_CTL_RMSK                                               0xf
#define HWIO_PON_PBS_DEBOUNCE_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBOUNCE_CTL_ADDR, HWIO_PON_PBS_DEBOUNCE_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_DEBOUNCE_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBOUNCE_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DEBOUNCE_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DEBOUNCE_CTL_ADDR, val, len)
#define HWIO_PON_PBS_DEBOUNCE_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_DEBOUNCE_CTL_ADDR, val)
#define HWIO_PON_PBS_DEBOUNCE_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBOUNCE_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DEBOUNCE_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_DEBOUNCE_CTL_ADDR, val, len)
#define HWIO_PON_PBS_DEBOUNCE_CTL_DEBOUNCE_BMSK                                      0xf
#define HWIO_PON_PBS_DEBOUNCE_CTL_DEBOUNCE_SHFT                                      0x0

#define HWIO_PON_PBS_RESET_S3_SRC_n_ADDR(n)                                   (PON_PBS_BASE            + (0X74 + (0x1*n)))
#define HWIO_PON_PBS_RESET_S3_SRC_n_OFFS(n)                                   (0X74 + (0x1*n))
#define HWIO_PON_PBS_RESET_S3_SRC_n_RMSK                                             0x3
#define HWIO_PON_PBS_RESET_S3_SRC_n_INI(ctxt, pmic, n, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESET_S3_SRC_n_ADDR(n), HWIO_PON_PBS_RESET_S3_SRC_n_RMSK, 0, val)
#define HWIO_PON_PBS_RESET_S3_SRC_n_INFI(ctxt, pmic, n, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESET_S3_SRC_n_ADDR(n), mask, shift, val)
#define HWIO_PON_PBS_RESET_S3_SRC_n_INNI(ctxt, pmic, n, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESET_S3_SRC_n_ADDR(n), val, len)
#define HWIO_PON_PBS_RESET_S3_SRC_n_OUTI(ctxt, pmic, n, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESET_S3_SRC_n_ADDR(n), val)
#define HWIO_PON_PBS_RESET_S3_SRC_n_OUTFI(ctxt, pmic, n, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESET_S3_SRC_n_ADDR(n), mask, shift, val)
#define HWIO_PON_PBS_RESET_S3_SRC_n_OUTNI(ctxt, pmic, n, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESET_S3_SRC_n_ADDR(n), val, len)
#define HWIO_PON_PBS_RESET_S3_SRC_n_RESET_S3_SOURCE_BMSK                             0x3
#define HWIO_PON_PBS_RESET_S3_SRC_n_RESET_S3_SOURCE_SHFT                             0x0

#define HWIO_PON_PBS_RESET_S3_TIMER_n_ADDR(n)                                 (PON_PBS_BASE            + (0X75 + (0x1*n)))
#define HWIO_PON_PBS_RESET_S3_TIMER_n_OFFS(n)                                 (0X75 + (0x1*n))
#define HWIO_PON_PBS_RESET_S3_TIMER_n_RMSK                                           0xf
#define HWIO_PON_PBS_RESET_S3_TIMER_n_INI(ctxt, pmic, n, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESET_S3_TIMER_n_ADDR(n), HWIO_PON_PBS_RESET_S3_TIMER_n_RMSK, 0, val)
#define HWIO_PON_PBS_RESET_S3_TIMER_n_INFI(ctxt, pmic, n, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESET_S3_TIMER_n_ADDR(n), mask, shift, val)
#define HWIO_PON_PBS_RESET_S3_TIMER_n_INNI(ctxt, pmic, n, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_RESET_S3_TIMER_n_ADDR(n), val, len)
#define HWIO_PON_PBS_RESET_S3_TIMER_n_OUTI(ctxt, pmic, n, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_RESET_S3_TIMER_n_ADDR(n), val)
#define HWIO_PON_PBS_RESET_S3_TIMER_n_OUTFI(ctxt, pmic, n, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_RESET_S3_TIMER_n_ADDR(n), mask, shift, val)
#define HWIO_PON_PBS_RESET_S3_TIMER_n_OUTNI(ctxt, pmic, n, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_RESET_S3_TIMER_n_ADDR(n), val, len)
#define HWIO_PON_PBS_RESET_S3_TIMER_n_S3_TIMER_BMSK                                  0xf
#define HWIO_PON_PBS_RESET_S3_TIMER_n_S3_TIMER_SHFT                                  0x0

#define HWIO_PON_PBS_UVLO_RB_STATUS_ADDR                                      (PON_PBS_BASE            + 0x00000085)
#define HWIO_PON_PBS_UVLO_RB_STATUS_OFFS                                      0x00000085
#define HWIO_PON_PBS_UVLO_RB_STATUS_RMSK                                            0x80
#define HWIO_PON_PBS_UVLO_RB_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_UVLO_RB_STATUS_ADDR, HWIO_PON_PBS_UVLO_RB_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_UVLO_RB_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_UVLO_RB_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_UVLO_RB_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_UVLO_RB_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_UVLO_RB_STATUS_UVLO_RB_BMSK                                    0x80
#define HWIO_PON_PBS_UVLO_RB_STATUS_UVLO_RB_SHFT                                     0x7

#define HWIO_PON_PBS_OVLO_RB_STATUS_ADDR                                      (PON_PBS_BASE            + 0x00000087)
#define HWIO_PON_PBS_OVLO_RB_STATUS_OFFS                                      0x00000087
#define HWIO_PON_PBS_OVLO_RB_STATUS_RMSK                                            0x80
#define HWIO_PON_PBS_OVLO_RB_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_OVLO_RB_STATUS_ADDR, HWIO_PON_PBS_OVLO_RB_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_OVLO_RB_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_OVLO_RB_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_OVLO_RB_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_OVLO_RB_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_OVLO_RB_STATUS_OVLO_RB_BMSK                                    0x80
#define HWIO_PON_PBS_OVLO_RB_STATUS_OVLO_RB_SHFT                                     0x7

#define HWIO_PON_PBS_PERPH_RB_SPARE_ADDR                                      (PON_PBS_BASE            + 0x0000008c)
#define HWIO_PON_PBS_PERPH_RB_SPARE_OFFS                                      0x0000008c
#define HWIO_PON_PBS_PERPH_RB_SPARE_RMSK                                            0xff
#define HWIO_PON_PBS_PERPH_RB_SPARE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RB_SPARE_ADDR, HWIO_PON_PBS_PERPH_RB_SPARE_RMSK, 0, val)
#define HWIO_PON_PBS_PERPH_RB_SPARE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RB_SPARE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_RB_SPARE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_RB_SPARE_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_RB_SPARE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_RB_SPARE_ADDR, val)
#define HWIO_PON_PBS_PERPH_RB_SPARE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RB_SPARE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_RB_SPARE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_PERPH_RB_SPARE_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_RB_SPARE_SPARE_BMSK                                      0xff
#define HWIO_PON_PBS_PERPH_RB_SPARE_SPARE_SHFT                                       0x0

#define HWIO_PON_PBS_DVDD_RB_SPARE_ADDR                                       (PON_PBS_BASE            + 0x0000008d)
#define HWIO_PON_PBS_DVDD_RB_SPARE_OFFS                                       0x0000008d
#define HWIO_PON_PBS_DVDD_RB_SPARE_RMSK                                             0xff
#define HWIO_PON_PBS_DVDD_RB_SPARE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DVDD_RB_SPARE_ADDR, HWIO_PON_PBS_DVDD_RB_SPARE_RMSK, 0, val)
#define HWIO_PON_PBS_DVDD_RB_SPARE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DVDD_RB_SPARE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DVDD_RB_SPARE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DVDD_RB_SPARE_ADDR, val, len)
#define HWIO_PON_PBS_DVDD_RB_SPARE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_DVDD_RB_SPARE_ADDR, val)
#define HWIO_PON_PBS_DVDD_RB_SPARE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DVDD_RB_SPARE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DVDD_RB_SPARE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_DVDD_RB_SPARE_ADDR, val, len)
#define HWIO_PON_PBS_DVDD_RB_SPARE_SPARE_BMSK                                       0xff
#define HWIO_PON_PBS_DVDD_RB_SPARE_SPARE_SHFT                                        0x0

#define HWIO_PON_PBS_XVDD_RB_SPARE_ADDR                                       (PON_PBS_BASE            + 0x0000008e)
#define HWIO_PON_PBS_XVDD_RB_SPARE_OFFS                                       0x0000008e
#define HWIO_PON_PBS_XVDD_RB_SPARE_RMSK                                             0xff
#define HWIO_PON_PBS_XVDD_RB_SPARE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE_ADDR, HWIO_PON_PBS_XVDD_RB_SPARE_RMSK, 0, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE_ADDR, val, len)
#define HWIO_PON_PBS_XVDD_RB_SPARE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE_ADDR, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE_ADDR, val, len)
#define HWIO_PON_PBS_XVDD_RB_SPARE_SPARE_BMSK                                       0xff
#define HWIO_PON_PBS_XVDD_RB_SPARE_SPARE_SHFT                                        0x0

#define HWIO_PON_PBS_XVDD_RB_SPARE2_ADDR                                      (PON_PBS_BASE            + 0x0000008f)
#define HWIO_PON_PBS_XVDD_RB_SPARE2_OFFS                                      0x0000008f
#define HWIO_PON_PBS_XVDD_RB_SPARE2_RMSK                                            0xff
#define HWIO_PON_PBS_XVDD_RB_SPARE2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE2_ADDR, HWIO_PON_PBS_XVDD_RB_SPARE2_RMSK, 0, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE2_ADDR, val, len)
#define HWIO_PON_PBS_XVDD_RB_SPARE2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE2_ADDR, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_XVDD_RB_SPARE2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_XVDD_RB_SPARE2_ADDR, val, len)
#define HWIO_PON_PBS_XVDD_RB_SPARE2_SPARE_BMSK                                      0xff
#define HWIO_PON_PBS_XVDD_RB_SPARE2_SPARE_SHFT                                       0x0

#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_ADDR                                 (PON_PBS_BASE            + 0x00000091)
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_OFFS                                 0x00000091
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_RMSK                                       0x40
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_PBS_INTERFACE_ADDR, HWIO_PON_PBS_FAULT_PBS_INTERFACE_RMSK, 0, val)
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_PBS_INTERFACE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_PBS_INTERFACE_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_PBS_INTERFACE_ADDR, val)
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_PBS_INTERFACE_ADDR, mask, shift, val)
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_FAULT_PBS_INTERFACE_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_ACK_NACK_BMSK                              0x40
#define HWIO_PON_PBS_FAULT_PBS_INTERFACE_ACK_NACK_SHFT                               0x6

#define HWIO_PON_PBS_FAULT_WDOG_PET_ADDR                                      (PON_PBS_BASE            + 0x00000092)
#define HWIO_PON_PBS_FAULT_WDOG_PET_OFFS                                      0x00000092
#define HWIO_PON_PBS_FAULT_WDOG_PET_RMSK                                            0x80
#define HWIO_PON_PBS_FAULT_WDOG_PET_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_WDOG_PET_ADDR, val)
#define HWIO_PON_PBS_FAULT_WDOG_PET_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_FAULT_WDOG_PET_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_WDOG_PET_WATCHDOG_PET_BMSK                               0x80
#define HWIO_PON_PBS_FAULT_WDOG_PET_WATCHDOG_PET_SHFT                                0x7

#define HWIO_PON_PBS_FAULT_EN_CTL_ADDR                                        (PON_PBS_BASE            + 0x00000093)
#define HWIO_PON_PBS_FAULT_EN_CTL_OFFS                                        0x00000093
#define HWIO_PON_PBS_FAULT_EN_CTL_RMSK                                               0x1
#define HWIO_PON_PBS_FAULT_EN_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_EN_CTL_ADDR, HWIO_PON_PBS_FAULT_EN_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_FAULT_EN_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_EN_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_FAULT_EN_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_EN_CTL_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_EN_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_EN_CTL_ADDR, val)
#define HWIO_PON_PBS_FAULT_EN_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_EN_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_FAULT_EN_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_FAULT_EN_CTL_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_EN_CTL_PBS_NACK_BMSK                                      0x1
#define HWIO_PON_PBS_FAULT_EN_CTL_PBS_NACK_SHFT                                      0x0

#define HWIO_PON_PBS_DEBUG_CTL_ADDR                                           (PON_PBS_BASE            + 0x00000094)
#define HWIO_PON_PBS_DEBUG_CTL_OFFS                                           0x00000094
#define HWIO_PON_PBS_DEBUG_CTL_RMSK                                                 0x6f
#define HWIO_PON_PBS_DEBUG_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBUG_CTL_ADDR, HWIO_PON_PBS_DEBUG_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_DEBUG_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBUG_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DEBUG_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DEBUG_CTL_ADDR, val, len)
#define HWIO_PON_PBS_DEBUG_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_DEBUG_CTL_ADDR, val)
#define HWIO_PON_PBS_DEBUG_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBUG_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DEBUG_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_DEBUG_CTL_ADDR, val, len)
#define HWIO_PON_PBS_DEBUG_CTL_DEBUG_CLOCK_BMSK                                     0x40
#define HWIO_PON_PBS_DEBUG_CTL_DEBUG_CLOCK_SHFT                                      0x6
#define HWIO_PON_PBS_DEBUG_CTL_DEBUG_CLOCK_SRC_BMSK                                 0x20
#define HWIO_PON_PBS_DEBUG_CTL_DEBUG_CLOCK_SRC_SHFT                                  0x5
#define HWIO_PON_PBS_DEBUG_CTL_SEL_DEBUG_BMSK                                        0xf
#define HWIO_PON_PBS_DEBUG_CTL_SEL_DEBUG_SHFT                                        0x0

#define HWIO_PON_PBS_DEBUG_STATUS_ADDR                                        (PON_PBS_BASE            + 0x00000095)
#define HWIO_PON_PBS_DEBUG_STATUS_OFFS                                        0x00000095
#define HWIO_PON_PBS_DEBUG_STATUS_RMSK                                              0xff
#define HWIO_PON_PBS_DEBUG_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBUG_STATUS_ADDR, HWIO_PON_PBS_DEBUG_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_DEBUG_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DEBUG_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DEBUG_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DEBUG_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_DEBUG_STATUS_DEBUG_STATE_BMSK                                  0xff
#define HWIO_PON_PBS_DEBUG_STATUS_DEBUG_STATE_SHFT                                   0x0

#define HWIO_PON_PBS_VDD_RESET_CTL_ADDR                                       (PON_PBS_BASE            + 0x00000097)
#define HWIO_PON_PBS_VDD_RESET_CTL_OFFS                                       0x00000097
#define HWIO_PON_PBS_VDD_RESET_CTL_RMSK                                              0x3
#define HWIO_PON_PBS_VDD_RESET_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_VDD_RESET_CTL_ADDR, val)
#define HWIO_PON_PBS_VDD_RESET_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_VDD_RESET_CTL_ADDR, val, len)
#define HWIO_PON_PBS_VDD_RESET_CTL_DVDD_RB_BMSK                                      0x2
#define HWIO_PON_PBS_VDD_RESET_CTL_DVDD_RB_SHFT                                      0x1
#define HWIO_PON_PBS_VDD_RESET_CTL_XVDD_RB_BMSK                                      0x1
#define HWIO_PON_PBS_VDD_RESET_CTL_XVDD_RB_SHFT                                      0x0

#define HWIO_PON_PBS_SYS_RESET_CTL_ADDR                                       (PON_PBS_BASE            + 0x00000098)
#define HWIO_PON_PBS_SYS_RESET_CTL_OFFS                                       0x00000098
#define HWIO_PON_PBS_SYS_RESET_CTL_RMSK                                              0x7
#define HWIO_PON_PBS_SYS_RESET_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_SYS_RESET_CTL_ADDR, val)
#define HWIO_PON_PBS_SYS_RESET_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_SYS_RESET_CTL_ADDR, val, len)
#define HWIO_PON_PBS_SYS_RESET_CTL_WARM_RB_BMSK                                      0x4
#define HWIO_PON_PBS_SYS_RESET_CTL_WARM_RB_SHFT                                      0x2
#define HWIO_PON_PBS_SYS_RESET_CTL_SHUTDOWN1_RB_BMSK                                 0x2
#define HWIO_PON_PBS_SYS_RESET_CTL_SHUTDOWN1_RB_SHFT                                 0x1
#define HWIO_PON_PBS_SYS_RESET_CTL_SHUTDOWN2_RB_BMSK                                 0x1
#define HWIO_PON_PBS_SYS_RESET_CTL_SHUTDOWN2_RB_SHFT                                 0x0

#define HWIO_PON_PBS_PS_HOLD_STATUS_ADDR                                      (PON_PBS_BASE            + 0x0000009a)
#define HWIO_PON_PBS_PS_HOLD_STATUS_OFFS                                      0x0000009a
#define HWIO_PON_PBS_PS_HOLD_STATUS_RMSK                                            0x80
#define HWIO_PON_PBS_PS_HOLD_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PS_HOLD_STATUS_ADDR, HWIO_PON_PBS_PS_HOLD_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_PS_HOLD_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PS_HOLD_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PS_HOLD_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PS_HOLD_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_PS_HOLD_STATUS_PS_HOLD_BMSK                                    0x80
#define HWIO_PON_PBS_PS_HOLD_STATUS_PS_HOLD_SHFT                                     0x7

#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ADDR                                   (PON_PBS_BASE            + 0x0000009e)
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_OFFS                                   0x0000009e
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_RMSK                                         0x83
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ADDR, HWIO_PON_PBS_PMIC_RB_INPUT_CTL_RMSK, 0, val)
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ADDR, val, len)
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ADDR, val)
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ADDR, val, len)
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ENABLE_BUFFER_BMSK                           0x80
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_ENABLE_BUFFER_SHFT                            0x7
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_MASK_INTERNAL_PMIC_RB_BMSK                    0x2
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_MASK_INTERNAL_PMIC_RB_SHFT                    0x1
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_FOLLOW_PMIC_RB_BMSK                           0x1
#define HWIO_PON_PBS_PMIC_RB_INPUT_CTL_FOLLOW_PMIC_RB_SHFT                           0x0

#define HWIO_PON_PBS_PMIC_RB_STATUS_ADDR                                      (PON_PBS_BASE            + 0x0000009f)
#define HWIO_PON_PBS_PMIC_RB_STATUS_OFFS                                      0x0000009f
#define HWIO_PON_PBS_PMIC_RB_STATUS_RMSK                                            0xb7
#define HWIO_PON_PBS_PMIC_RB_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_STATUS_ADDR, HWIO_PON_PBS_PMIC_RB_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_PMIC_RB_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PMIC_RB_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PMIC_RB_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_PMIC_RB_STATUS_UNMASKED_PMIC_RB_BMSK                           0x80
#define HWIO_PON_PBS_PMIC_RB_STATUS_UNMASKED_PMIC_RB_SHFT                            0x7
#define HWIO_PON_PBS_PMIC_RB_STATUS_RAW_OVLO_RB_BMSK                                0x20
#define HWIO_PON_PBS_PMIC_RB_STATUS_RAW_OVLO_RB_SHFT                                 0x5
#define HWIO_PON_PBS_PMIC_RB_STATUS_RAW_UVLO_RB_BMSK                                0x10
#define HWIO_PON_PBS_PMIC_RB_STATUS_RAW_UVLO_RB_SHFT                                 0x4
#define HWIO_PON_PBS_PMIC_RB_STATUS_CBOOST_OK_BMSK                                   0x4
#define HWIO_PON_PBS_PMIC_RB_STATUS_CBOOST_OK_SHFT                                   0x2
#define HWIO_PON_PBS_PMIC_RB_STATUS_PVDD_OK_BMSK                                     0x2
#define HWIO_PON_PBS_PMIC_RB_STATUS_PVDD_OK_SHFT                                     0x1
#define HWIO_PON_PBS_PMIC_RB_STATUS_V1P2_SYS_OK_BMSK                                 0x1
#define HWIO_PON_PBS_PMIC_RB_STATUS_V1P2_SYS_OK_SHFT                                 0x0

#define HWIO_PON_PBS_FAULT_REASON1_ADDR                                       (PON_PBS_BASE            + 0x000000c7)
#define HWIO_PON_PBS_FAULT_REASON1_OFFS                                       0x000000c7
#define HWIO_PON_PBS_FAULT_REASON1_RMSK                                             0xff
#define HWIO_PON_PBS_FAULT_REASON1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON1_ADDR, HWIO_PON_PBS_FAULT_REASON1_RMSK, 0, val)
#define HWIO_PON_PBS_FAULT_REASON1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_FAULT_REASON1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON1_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_REASON1_AVDD_RB_BMSK                                     0x80
#define HWIO_PON_PBS_FAULT_REASON1_AVDD_RB_SHFT                                      0x7
#define HWIO_PON_PBS_FAULT_REASON1_UVLO_BMSK                                        0x40
#define HWIO_PON_PBS_FAULT_REASON1_UVLO_SHFT                                         0x6
#define HWIO_PON_PBS_FAULT_REASON1_OVLO_BMSK                                        0x20
#define HWIO_PON_PBS_FAULT_REASON1_OVLO_SHFT                                         0x5
#define HWIO_PON_PBS_FAULT_REASON1_MBG_FAULT_BMSK                                   0x10
#define HWIO_PON_PBS_FAULT_REASON1_MBG_FAULT_SHFT                                    0x4
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT3_BMSK                                    0x8
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT3_SHFT                                    0x3
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT2_BMSK                                    0x4
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT2_SHFT                                    0x2
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT1_BMSK                                    0x2
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT1_SHFT                                    0x1
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT0_BMSK                                    0x1
#define HWIO_PON_PBS_FAULT_REASON1_GP_FAULT0_SHFT                                    0x0

#define HWIO_PON_PBS_FAULT_REASON2_ADDR                                       (PON_PBS_BASE            + 0x000000c8)
#define HWIO_PON_PBS_FAULT_REASON2_OFFS                                       0x000000c8
#define HWIO_PON_PBS_FAULT_REASON2_RMSK                                             0xfc
#define HWIO_PON_PBS_FAULT_REASON2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON2_ADDR, HWIO_PON_PBS_FAULT_REASON2_RMSK, 0, val)
#define HWIO_PON_PBS_FAULT_REASON2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_FAULT_REASON2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON2_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_REASON2_OTST3_BMSK                                       0x80
#define HWIO_PON_PBS_FAULT_REASON2_OTST3_SHFT                                        0x7
#define HWIO_PON_PBS_FAULT_REASON2_RESTART_PON_BMSK                                 0x40
#define HWIO_PON_PBS_FAULT_REASON2_RESTART_PON_SHFT                                  0x6
#define HWIO_PON_PBS_FAULT_REASON2_PBS_NACK_BMSK                                    0x20
#define HWIO_PON_PBS_FAULT_REASON2_PBS_NACK_SHFT                                     0x5
#define HWIO_PON_PBS_FAULT_REASON2_FAULT_WATCHDOG_TO_BMSK                           0x10
#define HWIO_PON_PBS_FAULT_REASON2_FAULT_WATCHDOG_TO_SHFT                            0x4
#define HWIO_PON_PBS_FAULT_REASON2_FAULT_N_BMSK                                      0x8
#define HWIO_PON_PBS_FAULT_REASON2_FAULT_N_SHFT                                      0x3
#define HWIO_PON_PBS_FAULT_REASON2_PMIC_RB_BMSK                                      0x4
#define HWIO_PON_PBS_FAULT_REASON2_PMIC_RB_SHFT                                      0x2

#define HWIO_PON_PBS_FAULT_REASON3_ADDR                                       (PON_PBS_BASE            + 0x000000c9)
#define HWIO_PON_PBS_FAULT_REASON3_OFFS                                       0x000000c9
#define HWIO_PON_PBS_FAULT_REASON3_RMSK                                             0xff
#define HWIO_PON_PBS_FAULT_REASON3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON3_ADDR, HWIO_PON_PBS_FAULT_REASON3_RMSK, 0, val)
#define HWIO_PON_PBS_FAULT_REASON3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON3_ADDR, mask, shift, val)
#define HWIO_PON_PBS_FAULT_REASON3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_FAULT_REASON3_ADDR, val, len)
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT11_BMSK                                  0x80
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT11_SHFT                                   0x7
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT10_BMSK                                  0x40
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT10_SHFT                                   0x6
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT9_BMSK                                   0x20
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT9_SHFT                                    0x5
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT8_BMSK                                   0x10
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT8_SHFT                                    0x4
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT7_BMSK                                    0x8
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT7_SHFT                                    0x3
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT6_BMSK                                    0x4
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT6_SHFT                                    0x2
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT5_BMSK                                    0x2
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT5_SHFT                                    0x1
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT4_BMSK                                    0x1
#define HWIO_PON_PBS_FAULT_REASON3_GP_FAULT4_SHFT                                    0x0

#define HWIO_PON_PBS_S3_RESET_REASON_ADDR                                     (PON_PBS_BASE            + 0x000000ca)
#define HWIO_PON_PBS_S3_RESET_REASON_OFFS                                     0x000000ca
#define HWIO_PON_PBS_S3_RESET_REASON_RMSK                                           0xf0
#define HWIO_PON_PBS_S3_RESET_REASON_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_S3_RESET_REASON_ADDR, HWIO_PON_PBS_S3_RESET_REASON_RMSK, 0, val)
#define HWIO_PON_PBS_S3_RESET_REASON_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_S3_RESET_REASON_ADDR, mask, shift, val)
#define HWIO_PON_PBS_S3_RESET_REASON_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_S3_RESET_REASON_ADDR, val, len)
#define HWIO_PON_PBS_S3_RESET_REASON_KPDPWR_ANDOR_RESIN_BMSK                        0x80
#define HWIO_PON_PBS_S3_RESET_REASON_KPDPWR_ANDOR_RESIN_SHFT                         0x7
#define HWIO_PON_PBS_S3_RESET_REASON_PBS_NACK_BMSK                                  0x40
#define HWIO_PON_PBS_S3_RESET_REASON_PBS_NACK_SHFT                                   0x6
#define HWIO_PON_PBS_S3_RESET_REASON_FAULT_WATCHDOG_TO_BMSK                         0x20
#define HWIO_PON_PBS_S3_RESET_REASON_FAULT_WATCHDOG_TO_SHFT                          0x5
#define HWIO_PON_PBS_S3_RESET_REASON_FAULT_N_BMSK                                   0x10
#define HWIO_PON_PBS_S3_RESET_REASON_FAULT_N_SHFT                                    0x4

#define HWIO_PON_PBS_LOCKBIT_D1_ADDR                                          (PON_PBS_BASE            + 0x000000d1)
#define HWIO_PON_PBS_LOCKBIT_D1_OFFS                                          0x000000d1
#define HWIO_PON_PBS_LOCKBIT_D1_RMSK                                                 0x3
#define HWIO_PON_PBS_LOCKBIT_D1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_LOCKBIT_D1_ADDR, HWIO_PON_PBS_LOCKBIT_D1_RMSK, 0, val)
#define HWIO_PON_PBS_LOCKBIT_D1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_LOCKBIT_D1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_LOCKBIT_D1_ADDR, val, len)
#define HWIO_PON_PBS_LOCKBIT_D1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_LOCKBIT_D1_ADDR, val)
#define HWIO_PON_PBS_LOCKBIT_D1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_LOCKBIT_D1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_LOCKBIT_D1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_LOCKBIT_D1_ADDR, val, len)
#define HWIO_PON_PBS_LOCKBIT_D1_LOCKBIT_D1_BMSK                                      0x3
#define HWIO_PON_PBS_LOCKBIT_D1_LOCKBIT_D1_SHFT                                      0x0

#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_ADDR                                (PON_PBS_BASE            + 0x000000d4)
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_OFFS                                0x000000d4
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_RMSK                                       0x1
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_ADDR, HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_ADDR, val)
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_BMSK                            0x1
#define HWIO_PON_PBS_ILLEGAL_WRITE_STATUS_LOCKBIT_D1_SHFT                            0x0

#define HWIO_PON_PBS_PERPH_RESET_CTL3_ADDR                                    (PON_PBS_BASE            + 0x000000da)
#define HWIO_PON_PBS_PERPH_RESET_CTL3_OFFS                                    0x000000da
#define HWIO_PON_PBS_PERPH_RESET_CTL3_RMSK                                           0x5
#define HWIO_PON_PBS_PERPH_RESET_CTL3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL3_ADDR, HWIO_PON_PBS_PERPH_RESET_CTL3_RMSK, 0, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_RESET_CTL3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL3_ADDR, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL3_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL3_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_RESET_CTL3_FOLLOW_WARM_RB_BMSK                            0x4
#define HWIO_PON_PBS_PERPH_RESET_CTL3_FOLLOW_WARM_RB_SHFT                            0x2
#define HWIO_PON_PBS_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_BMSK                       0x1
#define HWIO_PON_PBS_PERPH_RESET_CTL3_FOLLOW_SHUTDOWN2_RB_SHFT                       0x0

#define HWIO_PON_PBS_PERPH_RESET_CTL4_ADDR                                    (PON_PBS_BASE            + 0x000000db)
#define HWIO_PON_PBS_PERPH_RESET_CTL4_OFFS                                    0x000000db
#define HWIO_PON_PBS_PERPH_RESET_CTL4_RMSK                                           0x1
#define HWIO_PON_PBS_PERPH_RESET_CTL4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL4_ADDR, HWIO_PON_PBS_PERPH_RESET_CTL4_RMSK, 0, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_RESET_CTL4_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL4_ADDR, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL4_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL4_ADDR, mask, shift, val)
#define HWIO_PON_PBS_PERPH_RESET_CTL4_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_PERPH_RESET_CTL4_ADDR, val, len)
#define HWIO_PON_PBS_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_BMSK                          0x1
#define HWIO_PON_PBS_PERPH_RESET_CTL4_LOCAL_SOFT_RESET_SHFT                          0x0

#define HWIO_PON_PBS_INT_TEST1_ADDR                                           (PON_PBS_BASE            + 0x000000e0)
#define HWIO_PON_PBS_INT_TEST1_OFFS                                           0x000000e0
#define HWIO_PON_PBS_INT_TEST1_RMSK                                                 0x80
#define HWIO_PON_PBS_INT_TEST1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_INT_TEST1_ADDR, HWIO_PON_PBS_INT_TEST1_RMSK, 0, val)
#define HWIO_PON_PBS_INT_TEST1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_INT_TEST1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_INT_TEST1_ADDR, val, len)
#define HWIO_PON_PBS_INT_TEST1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_INT_TEST1_ADDR, val)
#define HWIO_PON_PBS_INT_TEST1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_INT_TEST1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_INT_TEST1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_INT_TEST1_ADDR, val, len)
#define HWIO_PON_PBS_INT_TEST1_INT_TEST_MODE_EN_BMSK                                0x80
#define HWIO_PON_PBS_INT_TEST1_INT_TEST_MODE_EN_SHFT                                 0x7

#define HWIO_PON_PBS_INT_TEST_VAL_ADDR                                        (PON_PBS_BASE            + 0x000000e1)
#define HWIO_PON_PBS_INT_TEST_VAL_OFFS                                        0x000000e1
#define HWIO_PON_PBS_INT_TEST_VAL_RMSK                                              0xff
#define HWIO_PON_PBS_INT_TEST_VAL_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_INT_TEST_VAL_ADDR, HWIO_PON_PBS_INT_TEST_VAL_RMSK, 0, val)
#define HWIO_PON_PBS_INT_TEST_VAL_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_INT_TEST_VAL_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_INT_TEST_VAL_ADDR, val, len)
#define HWIO_PON_PBS_INT_TEST_VAL_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_INT_TEST_VAL_ADDR, val)
#define HWIO_PON_PBS_INT_TEST_VAL_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_INT_TEST_VAL_ADDR, mask, shift, val)
#define HWIO_PON_PBS_INT_TEST_VAL_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_INT_TEST_VAL_ADDR, val, len)
#define HWIO_PON_PBS_INT_TEST_VAL_KPD_PWR_N_DEB_BMSK                                0x80
#define HWIO_PON_PBS_INT_TEST_VAL_KPD_PWR_N_DEB_SHFT                                 0x7
#define HWIO_PON_PBS_INT_TEST_VAL_RESIN_N_DEB_BMSK                                  0x40
#define HWIO_PON_PBS_INT_TEST_VAL_RESIN_N_DEB_SHFT                                   0x6
#define HWIO_PON_PBS_INT_TEST_VAL_SW_RESET_BMSK                                     0x20
#define HWIO_PON_PBS_INT_TEST_VAL_SW_RESET_SHFT                                      0x5
#define HWIO_PON_PBS_INT_TEST_VAL_PS_HOLD_BMSK                                      0x10
#define HWIO_PON_PBS_INT_TEST_VAL_PS_HOLD_SHFT                                       0x4
#define HWIO_PON_PBS_INT_TEST_VAL_PMIC_WDOG_S2_BMSK                                  0x8
#define HWIO_PON_PBS_INT_TEST_VAL_PMIC_WDOG_S2_SHFT                                  0x3
#define HWIO_PON_PBS_INT_TEST_VAL_RESIN_AND_KPDPWR_S2_BMSK                           0x4
#define HWIO_PON_PBS_INT_TEST_VAL_RESIN_AND_KPDPWR_S2_SHFT                           0x2
#define HWIO_PON_PBS_INT_TEST_VAL_RESIN_N_S2_BMSK                                    0x2
#define HWIO_PON_PBS_INT_TEST_VAL_RESIN_N_S2_SHFT                                    0x1
#define HWIO_PON_PBS_INT_TEST_VAL_KPD_PWR_N_S2_BMSK                                  0x1
#define HWIO_PON_PBS_INT_TEST_VAL_KPD_PWR_N_S2_SHFT                                  0x0

#define HWIO_PON_PBS_DTEST1_ADDR                                              (PON_PBS_BASE            + 0x000000e2)
#define HWIO_PON_PBS_DTEST1_OFFS                                              0x000000e2
#define HWIO_PON_PBS_DTEST1_RMSK                                                    0x3f
#define HWIO_PON_PBS_DTEST1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST1_ADDR, HWIO_PON_PBS_DTEST1_RMSK, 0, val)
#define HWIO_PON_PBS_DTEST1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST1_ADDR, val, len)
#define HWIO_PON_PBS_DTEST1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST1_ADDR, val)
#define HWIO_PON_PBS_DTEST1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_DTEST1_ADDR, val, len)
#define HWIO_PON_PBS_DTEST1_SEL_BMSK                                                0x3f
#define HWIO_PON_PBS_DTEST1_SEL_SHFT                                                 0x0

#define HWIO_PON_PBS_DTEST2_ADDR                                              (PON_PBS_BASE            + 0x000000e3)
#define HWIO_PON_PBS_DTEST2_OFFS                                              0x000000e3
#define HWIO_PON_PBS_DTEST2_RMSK                                                    0x3f
#define HWIO_PON_PBS_DTEST2_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST2_ADDR, HWIO_PON_PBS_DTEST2_RMSK, 0, val)
#define HWIO_PON_PBS_DTEST2_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST2_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST2_ADDR, val, len)
#define HWIO_PON_PBS_DTEST2_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST2_ADDR, val)
#define HWIO_PON_PBS_DTEST2_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST2_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST2_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_DTEST2_ADDR, val, len)
#define HWIO_PON_PBS_DTEST2_SEL_BMSK                                                0x3f
#define HWIO_PON_PBS_DTEST2_SEL_SHFT                                                 0x0

#define HWIO_PON_PBS_DTEST3_ADDR                                              (PON_PBS_BASE            + 0x000000e4)
#define HWIO_PON_PBS_DTEST3_OFFS                                              0x000000e4
#define HWIO_PON_PBS_DTEST3_RMSK                                                    0x3f
#define HWIO_PON_PBS_DTEST3_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST3_ADDR, HWIO_PON_PBS_DTEST3_RMSK, 0, val)
#define HWIO_PON_PBS_DTEST3_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST3_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST3_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST3_ADDR, val, len)
#define HWIO_PON_PBS_DTEST3_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST3_ADDR, val)
#define HWIO_PON_PBS_DTEST3_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST3_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST3_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_DTEST3_ADDR, val, len)
#define HWIO_PON_PBS_DTEST3_SEL_BMSK                                                0x3f
#define HWIO_PON_PBS_DTEST3_SEL_SHFT                                                 0x0

#define HWIO_PON_PBS_DTEST4_ADDR                                              (PON_PBS_BASE            + 0x000000e5)
#define HWIO_PON_PBS_DTEST4_OFFS                                              0x000000e5
#define HWIO_PON_PBS_DTEST4_RMSK                                                    0x3f
#define HWIO_PON_PBS_DTEST4_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST4_ADDR, HWIO_PON_PBS_DTEST4_RMSK, 0, val)
#define HWIO_PON_PBS_DTEST4_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST4_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST4_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST4_ADDR, val, len)
#define HWIO_PON_PBS_DTEST4_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_DTEST4_ADDR, val)
#define HWIO_PON_PBS_DTEST4_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_DTEST4_ADDR, mask, shift, val)
#define HWIO_PON_PBS_DTEST4_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_DTEST4_ADDR, val, len)
#define HWIO_PON_PBS_DTEST4_SEL_BMSK                                                0x3f
#define HWIO_PON_PBS_DTEST4_SEL_SHFT                                                 0x0

#define HWIO_PON_PBS_TEST5_ADDR                                               (PON_PBS_BASE            + 0x000000e6)
#define HWIO_PON_PBS_TEST5_OFFS                                               0x000000e6
#define HWIO_PON_PBS_TEST5_RMSK                                                     0x18
#define HWIO_PON_PBS_TEST5_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TEST5_ADDR, HWIO_PON_PBS_TEST5_RMSK, 0, val)
#define HWIO_PON_PBS_TEST5_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TEST5_ADDR, mask, shift, val)
#define HWIO_PON_PBS_TEST5_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_TEST5_ADDR, val, len)
#define HWIO_PON_PBS_TEST5_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_TEST5_ADDR, val)
#define HWIO_PON_PBS_TEST5_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TEST5_ADDR, mask, shift, val)
#define HWIO_PON_PBS_TEST5_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_TEST5_ADDR, val, len)
#define HWIO_PON_PBS_TEST5_MASK_SHUTDOWN2_RB_BMSK                                   0x10
#define HWIO_PON_PBS_TEST5_MASK_SHUTDOWN2_RB_SHFT                                    0x4
#define HWIO_PON_PBS_TEST5_MASK_WARM_RB_BMSK                                         0x8
#define HWIO_PON_PBS_TEST5_MASK_WARM_RB_SHFT                                         0x3

#define HWIO_PON_PBS_TEST7_ADDR                                               (PON_PBS_BASE            + 0x000000e8)
#define HWIO_PON_PBS_TEST7_OFFS                                               0x000000e8
#define HWIO_PON_PBS_TEST7_RMSK                                                      0xf
#define HWIO_PON_PBS_TEST7_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TEST7_ADDR, HWIO_PON_PBS_TEST7_RMSK, 0, val)
#define HWIO_PON_PBS_TEST7_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TEST7_ADDR, mask, shift, val)
#define HWIO_PON_PBS_TEST7_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_TEST7_ADDR, val, len)
#define HWIO_PON_PBS_TEST7_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_TEST7_ADDR, val)
#define HWIO_PON_PBS_TEST7_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TEST7_ADDR, mask, shift, val)
#define HWIO_PON_PBS_TEST7_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_TEST7_ADDR, val, len)
#define HWIO_PON_PBS_TEST7_FORCE_FAULT_N_LOW_BMSK                                    0x8
#define HWIO_PON_PBS_TEST7_FORCE_FAULT_N_LOW_SHFT                                    0x3
#define HWIO_PON_PBS_TEST7_FAULT_N_LOOPBACK_BMSK                                     0x4
#define HWIO_PON_PBS_TEST7_FAULT_N_LOOPBACK_SHFT                                     0x2
#define HWIO_PON_PBS_TEST7_DISCONNECT_FAULT_N_BMSK                                   0x2
#define HWIO_PON_PBS_TEST7_DISCONNECT_FAULT_N_SHFT                                   0x1
#define HWIO_PON_PBS_TEST7_IGNORE_FAULT_N_BMSK                                       0x1
#define HWIO_PON_PBS_TEST7_IGNORE_FAULT_N_SHFT                                       0x0

#define HWIO_PON_PBS_UVLO_TEST1_ADDR                                          (PON_PBS_BASE            + 0x000000e9)
#define HWIO_PON_PBS_UVLO_TEST1_OFFS                                          0x000000e9
#define HWIO_PON_PBS_UVLO_TEST1_RMSK                                                0xc0
#define HWIO_PON_PBS_UVLO_TEST1_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_UVLO_TEST1_ADDR, HWIO_PON_PBS_UVLO_TEST1_RMSK, 0, val)
#define HWIO_PON_PBS_UVLO_TEST1_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_UVLO_TEST1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_UVLO_TEST1_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_UVLO_TEST1_ADDR, val, len)
#define HWIO_PON_PBS_UVLO_TEST1_OUT(ctxt, pmic, val)\
                out_HWIO(ctxt, pmic, HWIO_PON_PBS_UVLO_TEST1_ADDR, val)
#define HWIO_PON_PBS_UVLO_TEST1_OUTF(ctxt, pmic, mask, shift, val)\
                out_HWIO_field(ctxt, pmic, HWIO_PON_PBS_UVLO_TEST1_ADDR, mask, shift, val)
#define HWIO_PON_PBS_UVLO_TEST1_OUTN(ctxt, pmic, val, len)\
                out_HWIO_array(ctxt, pmic, HWIO_PON_PBS_UVLO_TEST1_ADDR, val, len)
#define HWIO_PON_PBS_UVLO_TEST1_UVLO_TEST_EN_BMSK                                   0x80
#define HWIO_PON_PBS_UVLO_TEST1_UVLO_TEST_EN_SHFT                                    0x7
#define HWIO_PON_PBS_UVLO_TEST1_OVLO_TEST_EN_BMSK                                   0x40
#define HWIO_PON_PBS_UVLO_TEST1_OVLO_TEST_EN_SHFT                                    0x6

#define HWIO_PON_PBS_REG_WRITE_STATUS_ADDR                                    (PON_PBS_BASE            + 0x000000ef)
#define HWIO_PON_PBS_REG_WRITE_STATUS_OFFS                                    0x000000ef
#define HWIO_PON_PBS_REG_WRITE_STATUS_RMSK                                          0x81
#define HWIO_PON_PBS_REG_WRITE_STATUS_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REG_WRITE_STATUS_ADDR, HWIO_PON_PBS_REG_WRITE_STATUS_RMSK, 0, val)
#define HWIO_PON_PBS_REG_WRITE_STATUS_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_REG_WRITE_STATUS_ADDR, mask, shift, val)
#define HWIO_PON_PBS_REG_WRITE_STATUS_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_REG_WRITE_STATUS_ADDR, val, len)
#define HWIO_PON_PBS_REG_WRITE_STATUS_WR_RDY_BMSK                                   0x80
#define HWIO_PON_PBS_REG_WRITE_STATUS_WR_RDY_SHFT                                    0x7
#define HWIO_PON_PBS_REG_WRITE_STATUS_WR_ILG_BMSK                                    0x1
#define HWIO_PON_PBS_REG_WRITE_STATUS_WR_ILG_SHFT                                    0x0

#define HWIO_PON_PBS_TRIM_NUM_ADDR                                            (PON_PBS_BASE            + 0x000000f0)
#define HWIO_PON_PBS_TRIM_NUM_OFFS                                            0x000000f0
#define HWIO_PON_PBS_TRIM_NUM_RMSK                                                  0xff
#define HWIO_PON_PBS_TRIM_NUM_IN(ctxt, pmic, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TRIM_NUM_ADDR, HWIO_PON_PBS_TRIM_NUM_RMSK, 0, val)
#define HWIO_PON_PBS_TRIM_NUM_INF(ctxt, pmic, mask, shift, val)\
                in_HWIO_field(ctxt, pmic, HWIO_PON_PBS_TRIM_NUM_ADDR, mask, shift, val)
#define HWIO_PON_PBS_TRIM_NUM_INN(ctxt, pmic, val, len)\
                in_HWIO(ctxt, pmic, HWIO_PON_PBS_TRIM_NUM_ADDR, val, len)
#define HWIO_PON_PBS_TRIM_NUM_TRIM_NUM_BMSK                                         0xff
#define HWIO_PON_PBS_TRIM_NUM_TRIM_NUM_SHFT                                          0x0


#endif /* __PSAILHWIO__ */
