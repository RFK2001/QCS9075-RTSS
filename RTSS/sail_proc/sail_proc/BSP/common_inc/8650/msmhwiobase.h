#ifndef __MSMHWIOBASE_H__
#define __MSMHWIOBASE_H__
/*
===========================================================================
*/
/**
  @file msmhwiobase.h
  @brief Auto-generated HWIO base include file.
*/
/*
  ===========================================================================
  
  Copyright (c) 2022 Qualcomm Technologies Incorporated.
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

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/common_inc/8650/msmhwiobase.h#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  ===========================================================================
*/

/*----------------------------------------------------------------------------
 * BASE: SAILSS_BOOT_ROM_SAILSS_BOOT_ROM
 *--------------------------------------------------------------------------*/

#define SAILSS_BOOT_ROM_SAILSS_BOOT_ROM_BASE                               0x0u
#define SAILSS_BOOT_ROM_SAILSS_BOOT_ROM_BASE_SIZE                   0x00100000ul
#define SAILSS_BOOT_ROM_SAILSS_BOOT_ROM_BASE_PHYS                   0x00000000u

/*----------------------------------------------------------------------------
 * BASE: SAIL_TO_MD_SAILS_TO_MD_CONFIG
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE                          0xc0000000ul
#define SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE_SIZE                     0x30000000ul
#define SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE_PHYS                     0xc0000000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_TLMM_SAILSS_TLMM
 *--------------------------------------------------------------------------*/

#define SAILSS_TLMM_SAILSS_TLMM_BASE                                0xf0100000ul
#define SAILSS_TLMM_SAILSS_TLMM_BASE_SIZE                           0x00100000ul
#define SAILSS_TLMM_SAILSS_TLMM_BASE_PHYS                           0xf0100000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CSR_SAILSS_CSR
 *--------------------------------------------------------------------------*/

#define SAILSS_CSR_SAILSS_CSR_BASE                                  0xf0300000ul
#define SAILSS_CSR_SAILSS_CSR_BASE_SIZE                             0x0000a000u
#define SAILSS_CSR_SAILSS_CSR_BASE_PHYS                             0xf0300000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_TSCSS_SYS_TSCSS
 *--------------------------------------------------------------------------*/

#define SAILSS_TSCSS_SYS_TSCSS_BASE                                 0xf0500000ul
#define SAILSS_TSCSS_SYS_TSCSS_BASE_SIZE                            0x00020000ul
#define SAILSS_TSCSS_SYS_TSCSS_BASE_PHYS                            0xf0500000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_TSCSS_PTP_ETH_TSCSS
 *--------------------------------------------------------------------------*/

#define SAILSS_TSCSS_PTP_ETH_TSCSS_BASE                             0xf0520000ul
#define SAILSS_TSCSS_PTP_ETH_TSCSS_BASE_SIZE                        0x00020000ul
#define SAILSS_TSCSS_PTP_ETH_TSCSS_BASE_PHYS                        0xf0520000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_RTCU_WDOG_0_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_0_RTCU_WWDOG_BASE                          0xf0600000ul
#define SAILSS_RTCU_WDOG_0_RTCU_WWDOG_BASE_SIZE                     0x00001000u
#define SAILSS_RTCU_WDOG_0_RTCU_WWDOG_BASE_PHYS                     0xf0600000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_RTCU_WDOG_1_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_1_RTCU_WWDOG_BASE                          0xf0601000ul
#define SAILSS_RTCU_WDOG_1_RTCU_WWDOG_BASE_SIZE                     0x00001000u
#define SAILSS_RTCU_WDOG_1_RTCU_WWDOG_BASE_PHYS                     0xf0601000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_RTCU_WDOG_2_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_2_RTCU_WWDOG_BASE                          0xf0602000ul
#define SAILSS_RTCU_WDOG_2_RTCU_WWDOG_BASE_SIZE                     0x00001000u
#define SAILSS_RTCU_WDOG_2_RTCU_WWDOG_BASE_PHYS                     0xf0602000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_RTCU_WDOG_3_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_3_RTCU_WWDOG_BASE                          0xf0603000ul
#define SAILSS_RTCU_WDOG_3_RTCU_WWDOG_BASE_SIZE                     0x00001000u
#define SAILSS_RTCU_WDOG_3_RTCU_WWDOG_BASE_PHYS                     0xf0603000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_ACMU_0_SM_ACMU
 *--------------------------------------------------------------------------*/

#define SAILSS_ACMU_0_SM_ACMU_BASE                                  0xf0900000ul
#define SAILSS_ACMU_0_SM_ACMU_BASE_SIZE                             0x00010000ul
#define SAILSS_ACMU_0_SM_ACMU_BASE_PHYS                             0xf0900000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_ACMU_1_SM_ACMU
 *--------------------------------------------------------------------------*/

#define SAILSS_ACMU_1_SM_ACMU_BASE                                  0xf0910000ul
#define SAILSS_ACMU_1_SM_ACMU_BASE_SIZE                             0x00010000ul
#define SAILSS_ACMU_1_SM_ACMU_BASE_PHYS                             0xf0910000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_TSENS_0_TSENS_TOP
 *--------------------------------------------------------------------------*/

#define SAILSS_TSENS_0_TSENS_TOP_BASE                               0xf0a00000ul
#define SAILSS_TSENS_0_TSENS_TOP_BASE_SIZE                          0x00002000u
#define SAILSS_TSENS_0_TSENS_TOP_BASE_PHYS                          0xf0a00000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_TSENS_1_TSENS_TOP
 *--------------------------------------------------------------------------*/

#define SAILSS_TSENS_1_TSENS_TOP_BASE                               0xf0a02000ul
#define SAILSS_TSENS_1_TSENS_TOP_BASE_SIZE                          0x00002000u
#define SAILSS_TSENS_1_TSENS_TOP_BASE_PHYS                          0xf0a02000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER
 *--------------------------------------------------------------------------*/

#define SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_BASE                 0xf0b01000ul
#define SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_BASE_SIZE            0x00001000u
#define SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_BASE_PHYS            0xf0b01000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER
 *--------------------------------------------------------------------------*/

#define SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_BASE                 0xf0b02000ul
#define SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_BASE_SIZE            0x00001000u
#define SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_BASE_PHYS            0xf0b02000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_BASE        0xf0c00000ul
#define SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_BASE_SIZE   0x00001000u
#define SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_BASE_PHYS   0xf0c00000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE            0xf0c01000ul
#define SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE_SIZE       0x00001000u
#define SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE_PHYS       0xf0c01000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE            0xf0c02000ul
#define SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE_SIZE       0x00001000u
#define SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE_PHYS       0xf0c02000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_ASIL_D_SAIL_ASIL_D_NOC_WRAPPER
 *--------------------------------------------------------------------------*/

#define SAILSS_ASIL_D_SAIL_ASIL_D_NOC_WRAPPER_BASE                  0xf0d00000ul
#define SAILSS_ASIL_D_SAIL_ASIL_D_NOC_WRAPPER_BASE_SIZE             0x00046a00ul
#define SAILSS_ASIL_D_SAIL_ASIL_D_NOC_WRAPPER_BASE_PHYS             0xf0d00000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER
 *--------------------------------------------------------------------------*/

#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE                0xf1000000ul
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE_SIZE           0x00010000ul
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE_PHYS           0xf1000000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CLKCTL_SAILSS_CC
 *--------------------------------------------------------------------------*/

#define SAILSS_CLKCTL_SAILSS_CC_BASE                                0xf1100000ul
#define SAILSS_CLKCTL_SAILSS_CC_BASE_SIZE                           0x00100000ul
#define SAILSS_CLKCTL_SAILSS_CC_BASE_PHYS                           0xf1100000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CPR_CPR3
 *--------------------------------------------------------------------------*/

#define SAILSS_CPR_CPR3_BASE                                        0xf1300000ul
#define SAILSS_CPR_CPR3_BASE_SIZE                                   0x00004000u
#define SAILSS_CPR_CPR3_BASE_PHYS                                   0xf1300000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_QTMR_SAILSS_QTMR
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_SAILSS_QTMR_BASE                                0xf1400000ul
#define SAILSS_QTMR_SAILSS_QTMR_BASE_SIZE                           0x0000f000u
#define SAILSS_QTMR_SAILSS_QTMR_BASE_PHYS                           0xf1400000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_IPC_ROUTER_IPC_ROUTER_SAIL_TOP
 *--------------------------------------------------------------------------*/

#define SAILSS_IPC_ROUTER_IPC_ROUTER_SAIL_TOP_BASE                  0xf1600000ul
#define SAILSS_IPC_ROUTER_IPC_ROUTER_SAIL_TOP_BASE_SIZE             0x00100000ul
#define SAILSS_IPC_ROUTER_IPC_ROUTER_SAIL_TOP_BASE_PHYS             0xf1600000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_DMA_CRC_WFSS_CE_REG
 *--------------------------------------------------------------------------*/

#define SAILSS_DMA_CRC_WFSS_CE_REG_BASE                             0xf1800000ul
#define SAILSS_DMA_CRC_WFSS_CE_REG_BASE_SIZE                        0x00009000u
#define SAILSS_DMA_CRC_WFSS_CE_REG_BASE_PHYS                        0xf1800000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_QUPV3_1_QUPV3_ID_1
 *--------------------------------------------------------------------------*/

#define SAILSS_QUPV3_1_QUPV3_ID_1_BASE                              0xf1900000ul
#define SAILSS_QUPV3_1_QUPV3_ID_1_BASE_SIZE                         0x00100000ul
#define SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS                         0xf1900000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_0_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_0_CANSS_BASE                                   0xf8000000ul
#define SAILSS_CANSS_0_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_0_CANSS_BASE_PHYS                              0xf8000000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_1_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_1_CANSS_BASE                                   0xf8010000ul
#define SAILSS_CANSS_1_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_1_CANSS_BASE_PHYS                              0xf8010000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_2_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_2_CANSS_BASE                                   0xf8020000ul
#define SAILSS_CANSS_2_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_2_CANSS_BASE_PHYS                              0xf8020000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_3_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_3_CANSS_BASE                                   0xf8030000ul
#define SAILSS_CANSS_3_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_3_CANSS_BASE_PHYS                              0xf8030000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_4_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_4_CANSS_BASE                                   0xf8040000ul
#define SAILSS_CANSS_4_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_4_CANSS_BASE_PHYS                              0xf8040000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_5_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_5_CANSS_BASE                                   0xf8050000ul
#define SAILSS_CANSS_5_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_5_CANSS_BASE_PHYS                              0xf8050000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_6_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_6_CANSS_BASE                                   0xf8060000ul
#define SAILSS_CANSS_6_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_6_CANSS_BASE_PHYS                              0xf8060000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CANSS_7_CANSS
 *--------------------------------------------------------------------------*/

#define SAILSS_CANSS_7_CANSS_BASE                                   0xf8070000ul
#define SAILSS_CANSS_7_CANSS_BASE_SIZE                              0x00010000ul
#define SAILSS_CANSS_7_CANSS_BASE_PHYS                              0xf8070000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_ETHERNET_CFG_0_EMAC_WRAPPER_4CH
 *--------------------------------------------------------------------------*/

#define SAILSS_ETHERNET_CFG_0_EMAC_WRAPPER_4CH_BASE                 0xf8200000ul
#define SAILSS_ETHERNET_CFG_0_EMAC_WRAPPER_4CH_BASE_SIZE            0x00020000ul
#define SAILSS_ETHERNET_CFG_0_EMAC_WRAPPER_4CH_BASE_PHYS            0xf8200000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_QSPI_QSPI_TOP
 *--------------------------------------------------------------------------*/

#define SAILSS_QSPI_QSPI_TOP_BASE                                   0xf8300000ul
#define SAILSS_QSPI_QSPI_TOP_BASE_SIZE                              0x00004000u
#define SAILSS_QSPI_QSPI_TOP_BASE_PHYS                              0xf8300000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_CRYPTO0_CRYPTO_TOP
 *--------------------------------------------------------------------------*/

#define SAILSS_CRYPTO0_CRYPTO_TOP_BASE                              0xf8400000ul
#define SAILSS_CRYPTO0_CRYPTO_TOP_BASE_SIZE                         0x00040000ul
#define SAILSS_CRYPTO0_CRYPTO_TOP_BASE_PHYS                         0xf8400000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_HWKM_MASTER_CFG_KEYMANAGER_MASTER_REGS
 *--------------------------------------------------------------------------*/

#define SAILSS_HWKM_MASTER_CFG_KEYMANAGER_MASTER_REGS_BASE          0xf8500000ul
#define SAILSS_HWKM_MASTER_CFG_KEYMANAGER_MASTER_REGS_BASE_SIZE     0x00020000ul
#define SAILSS_HWKM_MASTER_CFG_KEYMANAGER_MASTER_REGS_BASE_PHYS     0xf8500000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_PKE_PKE_WRAPPER
 *--------------------------------------------------------------------------*/

#define SAILSS_PKE_PKE_WRAPPER_BASE                                 0xf8600000ul
#define SAILSS_PKE_PKE_WRAPPER_BASE_SIZE                            0x00071280ul
#define SAILSS_PKE_PKE_WRAPPER_BASE_PHYS                            0xf8600000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL
 *--------------------------------------------------------------------------*/

#define SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE          0xf8700000ul
#define SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE_SIZE     0x00010000ul
#define SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE_PHYS     0xf8700000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_HBCU_HBCU
 *--------------------------------------------------------------------------*/

#define SAILSS_HBCU_HBCU_BASE                                       0xf8800000ul
#define SAILSS_HBCU_HBCU_BASE_SIZE                                  0x00020000ul
#define SAILSS_HBCU_HBCU_BASE_PHYS                                  0xf8800000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_HBCU_SAFE_APB_SHS_SLBRIDGE
 *--------------------------------------------------------------------------*/

#define SAILSS_HBCU_SAFE_APB_SHS_SLBRIDGE_BASE                      0xf8900000ul
#define SAILSS_HBCU_SAFE_APB_SHS_SLBRIDGE_BASE_SIZE                 0x00001000u
#define SAILSS_HBCU_SAFE_APB_SHS_SLBRIDGE_BASE_PHYS                 0xf8900000ul

/*----------------------------------------------------------------------------
 * BASE: MD_SAFE_APB_SHS_MLBRIDGE
 *--------------------------------------------------------------------------*/

#define MD_SAFE_APB_SHS_MLBRIDGE_BASE                               0xf8a00000ul
#define MD_SAFE_APB_SHS_MLBRIDGE_BASE_SIZE                          0x00001000u
#define MD_SAFE_APB_SHS_MLBRIDGE_BASE_PHYS                          0xf8a00000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_BASE   0xf8b00000ul
#define SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_BASE_SIZE 0x00001000u
#define SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_BASE_PHYS 0xf8b00000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_ASIL_B_SAIL_ASIL_B_NOC_WRAPPER
 *--------------------------------------------------------------------------*/

#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_WRAPPER_BASE                  0xf8d00000ul
#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_WRAPPER_BASE_SIZE             0x00063000ul
#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_WRAPPER_BASE_PHYS             0xf8d00000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_ASIL_B_SAIL_ASIL_B_NOC_BASE : hand edited
 *--------------------------------------------------------------------------*/

#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_BASE                          0xf8d00000ul
#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_BASE_SIZE                     0x00063000ul
#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_BASE_PHYS                     0xf8d00000ul


/*----------------------------------------------------------------------------
 * BASE: SAILSS_DBG_SAILSS_SOC_DBG
 *--------------------------------------------------------------------------*/

#define SAILSS_DBG_SAILSS_SOC_DBG_BASE                              0xfa000000ul
#define SAILSS_DBG_SAILSS_SOC_DBG_BASE_SIZE                         0x02000000ul
#define SAILSS_DBG_SAILSS_SOC_DBG_BASE_PHYS                         0xfa000000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_GIC0_KITE_GIC
 *--------------------------------------------------------------------------*/

#define SAILSS_GIC0_KITE_GIC_BASE                                   0xfd200000ul
#define SAILSS_GIC0_KITE_GIC_BASE_SIZE                              0x00200000ul
#define SAILSS_GIC0_KITE_GIC_BASE_PHYS                              0xfd200000ul

/*----------------------------------------------------------------------------
 * BASE: SAILSS_GIC1_KITE_GIC
 *--------------------------------------------------------------------------*/

#define SAILSS_GIC1_KITE_GIC_BASE                                   0xfd400000ul
#define SAILSS_GIC1_KITE_GIC_BASE_SIZE                              0x00200000ul
#define SAILSS_GIC1_KITE_GIC_BASE_PHYS                              0xfd400000ul


#endif /* __MSMHWIOBASE_H__ */
