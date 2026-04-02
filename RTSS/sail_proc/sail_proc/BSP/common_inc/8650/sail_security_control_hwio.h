#ifndef __SAIL_SECURITY_CONTROL_HWIO_H__
#define __SAIL_SECURITY_CONTROL_HWIO_H__
/*
===========================================================================
*/
/**
    @file sail_security_control_hwio.h

*/
/*
    ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/common_inc/8650/sail_security_control_hwio.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

#ifdef monaco
#include <../monaco/sail_security_csr_hwio_monaco.h>
#include <../monaco/sail_tcsr_hwio_monaco.h>
#include <../monaco/sail_to_md_tlmm_hwio_monaco.h>

#else
#include <./8650/sail_security_csr_hwio_8650.h>
#include <./8650/sail_tcsr_hwio_8650.h>
#include <./8650/sail_to_md_tlmm_hwio_8650.h>
#endif

#define CHIPINFO_QCOM_MFG_ID_REG SAILSS_TLMM_SAILSS_TLMM_HW_REVISION_NUMBER_0
#define CHIPINFO_JTAG_ID_REG SAILSS_TLMM_SAILSS_TLMM_HW_REVISION_NUMBER_1
#define CHIPINFO_REVISION_NUMBER_REG SAILSS_TLMM_SAILSS_TLMM_HW_REVISION_NUMBER_2
#define CHIPINFO_TCSR_SOC_HW_VERSION SAILSS_CSR_SAIL_HW_VER /*TCSR Version same as SAILSS CSR */
#define CHIPINFO_FOUNDRY_ID_REG SAILSS_SECURITY_CONTROL_QFPROM_CORR_FEATURE_CONFIG_NM_ROW2_LSB
#define CHIPINFO_SERIAL_NUM_REG SAILSS_SECURITY_CONTROL_SERIAL_NUM
#define CHIPINFO_QFPROM_CHIP_ID_REG SAILSS_SECURITY_CONTROL_CHIP_ID

#endif
