/* ============================================================================
 * @file  secboot_swid.h
 * @brief Define image sw type
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SECBOOT_SWID_H
#define SECBOOT_SWID_H

/**
@brief List of Software IDs
**/

/* SW Types for each of the subsystems; used during image authentication */

#define SECBOOT_SBL_SW_TYPE         0x0U
#define SECBOOT_MBA_SW_TYPE         0x1U
#define SECBOOT_MPSS_SW_TYPE        0x2U
#define SECBOOT_EHOSTDL_SW_TYPE     0x3U
#define SECBOOT_ADSP_SW_TYPE        0x4U
#define SECBOOT_QSEE_DEVCFG_SW_TYPE 0x5U
#define SECBOOT_SPSS_SW_TYPE        0x6U
#define SECBOOT_TZ_KERNEL_SW_TYPE   0x7U
#define SECBOOT_QSEE_SW_TYPE        0x7U
#define SECBOOT_APPSBL_SW_TYPE      0x9U
#define SECBOOT_RPM_FW_SW_TYPE      0xAU
#define SECBOOT_APPS_SEC_SW_TYPE    0xBU
#define SECBOOT_TZ_APP_SW_TYPE      0xCU
#define SECBOOT_WCNSS_SW_TYPE       0xDU
#define SECBOOT_VIDEO_SW_TYPE       0xEU
#define SECBOOT_HLOS_APPS_SW_TYPE   0xEU
#define SECBOOT_VPU_SW_TYPE         0xFU
#define SECBOOT_BCSS_SW_TYPE        0x10U
#define SECBOOT_STI_SW_TYPE         0x11U
#define SECBOOT_WDT_SW_TYPE         0x12U
#define SECBOOT_ACPI_SW_TYPE        0x13U
#define SECBOOT_GPU_UCODE_SW_TYPE   0x14U
#define SECBOOT_QHEE_SW_TYPE        0x15U
#define SECBOOT_PMIC_SW_TYPE        0x16U
#define SECBOOT_CDSP_SW_TYPE        0x17U
#define SECBOOT_SLPI_SW_TYPE        0x18U
#define SECBOOT_EOSFW_SW_TYPE       0x19U
#define SECBOOT_EFSTAR_SW_TYPE      0x1BU
#define SECBOOT_ABLFV_SW_TYPE       0x1CU
#define SECBOOT_IPA_GSI_SW_TYPE     0x1DU
#define SECBOOT_TZ_TEE_SW_TYPE      0x1EU
#define SECBOOT_TZ_LIB_SW_TYPE      0x1FU
#define SECBOOT_SHRM_SW_TYPE        0x20U
#define SECBOOT_AOP_SW_TYPE         0x21U
#define SECBOOT_OEM_MISC_SW_TYPE    0x22U
#define SECBOOT_QTI_MISC_SW_TYPE    0x23U
#define SECBOOT_QUP_SW_TYPE         0x24U
#define SECBOOT_XBL_CONFIG_SW_TYPE  0x25U
#define SECBOOT_UEFIFV_SW_TYPE      0x27U
#define SECBOOT_NPU_SW_TYPE         0x28U
#define SECBOOT_FMAC_SW_TYPE        0x29U
#define SECBOOT_FACE_AUTH_SW_TYPE   0x2AU
#define SECBOOT_SEC_ELF_SW_TYPE     0x2BU
#define SECBOOT_EXT_DSP_SW_TYPE     0x2CU
#define SECBOOT_IPA_UC_SW_TYPE      0x2DU
#define SECBOOT_CVP_FW_SW_TYPE      0x2EU
#define SECBOOT_MLVM_SW_TYPE        0x2FU
#define SECBOOT_DAM_APP_SW_TYPE     0x30U
#define SECBOOT_CPUCP_SW_TYPE       0x31U
#define SECBOOT_APPS_CPU_GUEST_OS_SW_TYPE	0x32U
#define SECBOOT_DEVTREE_SW_TYPE     0x33U
#define SECBOOT_CAMERA_FW_SW_TYPE   0x34U
#define SECBOOT_SMSS_SW_TYPE        0x39U
#define SECBOOT_TOOLS_SW_TYPE       0x3AU
#define SECBOOT_QUANTUM_SW_TYPE     0x3BU
#define SECBOOT_QUEST_SW_TYPE       0x3CU
#define SECBOOT_XBL_RAMDUMP_SW_TYPE       0x42U
#define SECBOOT_USB_FW_SW_TYPE      0x43U
#define SECBOOT_CDSP1_SW_TYPE       0x44U
#define SECBOOT_ADSP_LITE_SW_TYPE   0x45U

#define SECBOOT_SAIL_HYP_SW_TYPE   0x54U
#define SECBOOT_SAIL_SW1_SW_TYPE   0x55U
#define SECBOOT_SAIL_SW2_SW_TYPE   0x56U
#define SECBOOT_SAIL_SW3_SW_TYPE   0x77U
#define SECBOOT_SAIL_SW4_SW_TYPE   0x78U

#define SECBOOT_APDP_SW_TYPE        0x200U

#define SECBOOT_INVALID_SW_TYPE     (-1)
#define SECBOOT_MAX_SW_TYPE         0x7FFFFFFFUL
#endif /* SECBOOT_SWID_H */
