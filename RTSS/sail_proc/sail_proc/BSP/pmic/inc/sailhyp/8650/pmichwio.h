/*
===========================================================================
*/
/**
    @file  pmicel2hwio.h
    @brief HWIO created for TI PMIC Offset as per as safety guide shared

*/
/*
    ===========================================================================

    Copyright (c) Qualcomm Technologies, Inc.
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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/


/* Include header file guard */

#ifndef PMICEHWIO_H
#define PMICEHWIO_H


/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <hw_io.h>
#include <HALhwio.h>

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define HWIO_PMIC(reg) (uint32) TI_PMIC_##reg##_ADD
#define PMIC_BMSK(reg, field) (uint8) TI_PMIC_##reg##_##field##_BMSK
#define PMIC_SHFT(reg, field) TI_PMIC_##reg##_##field##_SHFT


/* PAGE 0 MASK */

#define TI_PMIC_BUCK_CTRL_BUCK_FPWM_BMSK                    0x2U
#define TI_PMIC_BUCK_CTRL_BUCK_FPWM_SHFT                    0x1U
#define TI_PMIC_BUCK_CTRL_BUCK_EN_BMSK                      0x1U
#define TI_PMIC_BUCK_CTRL_BUCK_EN_SHFT                      0x0U
#define TI_PMIC_BUCK_CTRL_BUCK_VSEL_BMSK                    0x8U
#define TI_PMIC_BUCK_CTRL_BUCK_VSEL_SHFT                    0x3U
#define TI_PMIC_BUCK_CTRL_BUCK_VMON_EN_BMSK                 0x30U
#define TI_PMIC_BUCK_CTRL_BUCK_VMON_EN_SHFT                 0x4U
#define TI_PMIC_BUCK_CTRL_BUCK_SLEW_RATE_SHFT               0x0U
#define TI_PMIC_BUCK_CTRL_BUCK_SLEW_RATE_BMSK               0x7U
#define TI_PMIC_MISC_CTRL_LPM_EN_BMSK                       0x4U
#define TI_PMIC_MISC_CTRL_LPM_EN_SHFT                       0x2U


#define TI_PMIC_BUCK5_CONF_BUCK5_SLEW_RATE_SHFT             0x0U
#define TI_PMIC_BUCK5_CONF_BUCK5_SLEW_RATE_BMSK             0x7U

#define TI_PMIC_FSM_I2C_TRIGGERS_TRIGGER_I2C_6_SHFT         0x6
#define TI_PMIC_FSM_I2C_TRIGGERS_TRIGGER_I2C_6_BMSK         0x40


#define TI_PMIC_LDO_CTRL_LDO_VMON_EN_BMSK                   0x10U
#define TI_PMIC_LDO_CTRL_LDO_VMON_EN_SHFT                   0x4U
#define TI_PMIC_LDO_CTRL_LDO_EN_BMSK                        0x1U
#define TI_PMIC_LDO_CTRL_LDO_EN_SHFT                        0x0U
#define TI_PMIC_LDO_VOUT_1_LDO_VSET_BMSK                    0x7EU
#define TI_PMIC_LDO_VOUT_1_LDO_VSET_SHFT                    0x1U
#define TI_PMIC_LDO_VOUT_4_LDO_VSET_BMSK                    0x7FU
#define TI_PMIC_LDO_VOUT_4_LDO_VSET_SHFT                    0x0U
#define TI_PMIC_LDO_CTRL_LDO_SLOW_RAMP_BMSK                 0x2U
#define TI_PMIC_LDO_CTRL_LDO_SLOW_RAMP_SHFT                 0x1U

#define TI_PMIC_MASK_VMON_VCCA_UV_MASK_BMSK                 0x2U
#define TI_PMIC_MASK_VMON_VCCA_UV_MASK_SHFT                 0x1U

#define TI_PMIC_MASK_VMON_VCCA_OV_MASK_BMSK                 0x1U
#define TI_PMIC_MASK_VMON_VCCA_OV_MASK_SHFT                 0x0U

#define TI_PMIC_MASK_BUCK_BUCK1_UV_MASK_BMSK                0x2U
#define TI_PMIC_MASK_BUCK_BUCK1_UV_MASK_SHFT                0x1U
#define TI_PMIC_MASK_BUCK_BUCK1_OV_MASK_BMSK                0x1U
#define TI_PMIC_MASK_BUCK_BUCK1_OV_MASK_SHFT                0x0U


#define TI_PMIC_MASK_LDO_LDO1_UV_MASK_BMSK                  0x2U
#define TI_PMIC_MASK_LDO_LDO1_UV_MASK_SHFT                  0x1U
#define TI_PMIC_MASK_LDO_LDO1_OV_MASK_BMSK                  0x1U
#define TI_PMIC_MASK_LDO_LDO1_OV_MASK_SHFT                  0x0U



#define TI_PMIC_REGISTER_LOCK_REGISTER_LOCK_STATUS_BMSK     0x1U
#define TI_PMIC_REGISTER_LOCK_REGISTER_LOCK_STATUS_SHFT     0x0U

#define TI_PMIC_WD_THR_CFG_WD_EN_BMSK                       0x40U
#define TI_PMIC_WD_THR_CFG_WD_EN_SHFT                       0x6U
#define TI_PMIC_WD_THR_CFG_WD_FAIL_TH_BMSK                  0x38U
#define TI_PMIC_WD_THR_CFG_WD_FAIL_TH_SHFT                  0x3U
#define TI_PMIC_WD_THR_CFG_WD_RST_TH_BMSK                   0x7U
#define TI_PMIC_WD_THR_CFG_WD_RST_TH_SHFT                   0x0U
#define TI_PMIC_WD_WIN1_CFG_WD_WIN_BMSK                     0x7FU

#define TI_PMIC_WD_FAIL_CNT_REG_WD_FAIL_CNT_BMSK            0xFU
#define TI_PMIC_WD_FAIL_CNT_REG_WD_FAIL_CNT_SHFT            0x0U

#define TI_PMIC_WD_MODE_REG_WD_PWRHOLD_BMSK                 0x4U
#define TI_PMIC_WD_MODE_REG_WD_PWRHOLD_SHFT                 0x2U


#define TI_PMIC_WD_QUESTION_ANSW_CNT_WD_QUESTION_BMSK       0xFU
#define TI_PMIC_WD_QUESTION_ANSW_CNT_WD_QUESTION_SHFT       0x0U



#define TI_PMIC_ENABLE_DRV_STAT_FORCE_EN_DRV_LOW_BMSK       0x8U
#define TI_PMIC_ENABLE_DRV_STAT_FORCE_EN_DRV_LOW_SHFT       0x3U
#define TI_PMIC_ENABLE_DRV_REG_ENABLE_DRV_BMSK              0x1U
#define TI_PMIC_ENABLE_DRV_REG_ENABLE_DRV_SHFT              0x0U
#define TI_PMIC_ENABLE_DRV_STAT_EN_DRV_IN_BMSK              0x1U
#define TI_PMIC_ENABLE_DRV_STAT_EN_DRV_IN_SHFT              0x0U

#define TI_PMIC_WD_THR_CFG_WD_EN_BMSK                       0x40U
#define TI_PMIC_WD_THR_CFG_WD_EN_SHFT                       0x6U

#define TI_PMIC_INT_TOP_FSM_ERR_INT_BMSK                    0x80U
#define TI_PMIC_INT_TOP_FSM_ERR_INT_SHFT                    0x7U
#define TI_PMIC_INT_TOP_SEVERE_ERR_INT_BMSK                 0x40U
#define TI_PMIC_INT_TOP_SEVERE_ERR_INT_SHFT                 0x6U
#define TI_PMIC_INT_TOP_MODERATE_ERR_INT_BMSK               0x20U
#define TI_PMIC_INT_TOP_MODERATE_ERR_INT_SHFT               0x5U
#define TI_PMIC_INT_TOP_MISC_INT_BMSK                       0x10U
#define TI_PMIC_INT_TOP_MISC_INT_SHFT                       0x4U
#define TI_PMIC_INT_TOP_STARTUP_INT_BMSK                    0x8U
#define TI_PMIC_INT_TOP_STARTUP_INT_SHFT                    0x3U
#define TI_PMIC_INT_TOP_GPIO_INT_BMSK                       0x4U
#define TI_PMIC_INT_TOP_GPIO_INT_SHFT                       0x2U
#define TI_PMIC_INT_TOP_LDO_VMON_INT_BMSK                   0x2U
#define TI_PMIC_INT_TOP_LDO_VMON_INT_SHFT                   0x1U
#define TI_PMIC_INT_TOP_BUCK_INT_BMSK                       0x1U
#define TI_PMIC_INT_TOP_BUCK_INT_SHFT                       0x0U

#define TI_PMIC_INT_FSM_ERR_WD_INT_BMSK                     0x80U
#define TI_PMIC_INT_FSM_ERR_WD_INT_SHFT                     0x7U
#define TI_PMIC_INT_FSM_ERR_ESM_INT_BMSK                    0x40U
#define TI_PMIC_INT_FSM_ERR_ESM_INT_SHFT                    0x6U
#define TI_PMIC_INT_FSM_ERR_READBACK_ERR_INT_BMSK           0x20U
#define TI_PMIC_INT_FSM_ERR_READBACK_ERR_INT_SHFT           0x5U
#define TI_PMIC_INT_FSM_ERR_COMM_ERR_INT_BMSK               0x10U
#define TI_PMIC_INT_FSM_ERR_COMM_ERR_INT_SHFT               0x4U
#define TI_PMIC_INT_FSM_ERR_SOC_PWR_ERR_INT_BMSK            0x8U
#define TI_PMIC_INT_FSM_ERR_SOC_PWR_ERR_INT_SHFT            0x3U
#define TI_PMIC_INT_FSM_ERR_MCU_PWR_ERR_INT_BMSK            0x4U
#define TI_PMIC_INT_FSM_ERR_MCU_PWR_ERR_INT_SHFT            0x2U
#define TI_PMIC_INT_FSM_ERR_ORD_SHUTDOWN_INT_BMSK           0x2U
#define TI_PMIC_INT_FSM_ERR_ORD_SHUTDOWN_INT_SHFT           0x1U
#define TI_PMIC_INT_FSM_ERR_IMM_SHUTDOWN_INT_BMSK           0x1U
#define TI_PMIC_INT_FSM_ERR_IMM_SHUTDOWN_INT_SHFT           0x0U

#define TI_PMIC_INT_MISC_BIST_PASS_INT_BMSK                 0x1U
#define TI_PMIC_INT_MISC_BIST_PASS_INT_SHFT                 0x0U

#define TI_PMIC_INT_GPIO_GPIO1_8_INT_BMSK                   0x8U
#define TI_PMIC_INT_GPIO_GPIO1_8_INT_SHFT                   0x3U


#define TI_PMIC_INT_LDO_VMON_VCCA_INT_BMSK                  0x10U
#define TI_PMIC_INT_LDO_VMON_VCCA_INT_SHFT                  0x4U
#define TI_PMIC_INT_LDO_VMON_LDO3_4_INT_BMSK                0x2U
#define TI_PMIC_INT_LDO_VMON_LDO3_4_INT_SHFT                0x1U
#define TI_PMIC_INT_LDO_VMON_LDO1_2_INT_BMSK                0x1U
#define TI_PMIC_INT_LDO_VMON_LDO1_2_INT_SHFT                0x0U


#define TI_PMIC_INT_BUCK_BUCK5_INT_BMSK                     0x4U
#define TI_PMIC_INT_BUCK_BUCK5_INT_SHFT                     0x2U
#define TI_PMIC_INT_BUCK_BUCK3_4_INT_BMSK                   0x2U
#define TI_PMIC_INT_BUCK_BUCK3_4_INT_SHFT                   0x1U
#define TI_PMIC_INT_BUCK_BUCK1_2_INT_BMSK                   0x1U
#define TI_PMIC_INT_BUCK_BUCK1_2_INT_SHFT                   0x0U


#define TI_PMIC_STAT_READBACK_ERR_NINT_READBACK_STAT_BMSK   0x2U
#define TI_PMIC_STAT_READBACK_ERR_NINT_READBACK_STAT_SHFT   0x1U

#define TI_PMIC_MISC_CTRL_CLKMON_EN_BMSK                    0x8U
#define TI_PMIC_MISC_CTRL_CLKMON_EN_SHFT                    0x3U

#define TI_PMIC_SCRATCH_PAD_REG_2_BUCK_BMSK                 0xFU

#define TI_PMIC_INT_STARTUP_ENABLE_INT_BMSK                 0x2U
#define TI_PMIC_INT_STARTUP_ENABLE_INT_SHFT                 0x1U


/* PAGE 1 MASK */


#define TI_PMIC_SERIAL_IF_CONFIG_I2C2_CRC_EN_BMSK           0x4U
#define TI_PMIC_SERIAL_IF_CONFIG_I2C2_CRC_EN_SHFT           0x2U
#define TI_PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_BMSK       0x2U
#define TI_PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_SHFT       0x1U


/* TI PMIC Registers */

/* PAGE 0 Registers */

#define    TI_PMIC_DEV_REV_ADD                       0x1U 
#define    TI_PMIC_NVM_CODE_1_ADD                    0x2U 
#define    TI_PMIC_NVM_CODE_2_ADD                    0x3U 
#define    TI_PMIC_BUCK1_CTRL_ADD                    0x4U 
#define    TI_PMIC_BUCK1_CONF_ADD                    0x5U 
#define    TI_PMIC_BUCK2_CTRL_ADD                    0x6U 
#define    TI_PMIC_BUCK2_CONF_ADD                    0x7U 
#define    TI_PMIC_BUCK3_CTRL_ADD                    0x8U 
#define    TI_PMIC_BUCK3_CONF_ADD                    0x9U 
#define    TI_PMIC_BUCK4_CTRL_ADD                    0xAU 
#define    TI_PMIC_BUCK4_CONF_ADD                    0xBU 
#define    TI_PMIC_BUCK5_CTRL_ADD                    0xCU 
#define    TI_PMIC_BUCK5_CONF_ADD                    0xDU 
#define    TI_PMIC_BUCK1_VOUT_1_ADD                  0xEU 
#define    TI_PMIC_BUCK1_VOUT_2_ADD                  0xFU 
#define    TI_PMIC_BUCK2_VOUT_1_ADD                  0x10U 
#define    TI_PMIC_BUCK2_VOUT_2_ADD                  0x11U 
#define    TI_PMIC_BUCK3_VOUT_1_ADD                  0x12U 
#define    TI_PMIC_BUCK3_VOUT_2_ADD                  0x13U 
#define    TI_PMIC_BUCK4_VOUT_1_ADD                  0x14U 
#define    TI_PMIC_BUCK4_VOUT_2_ADD                  0x15U 
#define    TI_PMIC_BUCK5_VOUT_1_ADD                  0x16U 
#define    TI_PMIC_BUCK5_VOUT_2_ADD                  0x17U 
#define    TI_PMIC_BUCK1_PG_WINDOW_ADD               0x18U 
#define    TI_PMIC_BUCK2_PG_WINDOW_ADD               0x19U 
#define    TI_PMIC_BUCK3_PG_WINDOW_ADD               0x1AU 
#define    TI_PMIC_BUCK4_PG_WINDOW_ADD               0x1BU 
#define    TI_PMIC_BUCK5_PG_WINDOW_ADD               0x1CU 
#define    TI_PMIC_LDO1_CTRL_ADD                     0x1DU 
#define    TI_PMIC_LDO2_CTRL_ADD                     0x1EU 
#define    TI_PMIC_LDO3_CTRL_ADD                     0x1FU 
#define    TI_PMIC_LDO4_CTRL_ADD                     0x20U 
#define    TI_PMIC_LDORTC_CTRL_ADD                   0x22U 
#define    TI_PMIC_LDO1_VOUT_ADD                     0x23U 
#define    TI_PMIC_LDO2_VOUT_ADD                     0x24U 
#define    TI_PMIC_LDO3_VOUT_ADD                     0x25U 
#define    TI_PMIC_LDO4_VOUT_ADD                     0x26U 
#define    TI_PMIC_LDO1_PG_WINDOW_ADD                0x27U 
#define    TI_PMIC_LDO2_PG_WINDOW_ADD                0x28U 
#define    TI_PMIC_LDO3_PG_WINDOW_ADD                0x29U 
#define    TI_PMIC_LDO4_PG_WINDOW_ADD                0x2AU 
#define    TI_PMIC_VCCA_VMON_CTRL_ADD                0x2BU 
#define    TI_PMIC_VCCA_PG_WINDOW_ADD                0x2CU 
#define    TI_PMIC_GPIO1_CONF_ADD                    0x31U 
#define    TI_PMIC_GPIO2_CONF_ADD                    0x32U 
#define    TI_PMIC_GPIO3_CONF_ADD                    0x33U 
#define    TI_PMIC_GPIO4_CONF_ADD                    0x34U 
#define    TI_PMIC_GPIO5_CONF_ADD                    0x35U 
#define    TI_PMIC_GPIO6_CONF_ADD                    0x36U 
#define    TI_PMIC_GPIO7_CONF_ADD                    0x37U 
#define    TI_PMIC_GPIO8_CONF_ADD                    0x38U 
#define    TI_PMIC_GPIO9_CONF_ADD                    0x39U 
#define    TI_PMIC_GPIO10_CONF_ADD                   0x3AU 
#define    TI_PMIC_GPIO11_CONF_ADD                   0x3BU 
#define    TI_PMIC_NPWRON_CONF_ADD                   0x3CU 
#define    TI_PMIC_GPIO_OUT_1_ADD                    0x3DU 
#define    TI_PMIC_GPIO_OUT_2_ADD                    0x3EU 
#define    TI_PMIC_GPIO_IN_1_ADD                     0x3FU 
#define    TI_PMIC_GPIO_IN_2_ADD                     0x40U 
#define    TI_PMIC_RAIL_SEL_1_ADD                    0x41U 
#define    TI_PMIC_RAIL_SEL_2_ADD                    0x42U 
#define    TI_PMIC_RAIL_SEL_3_ADD                    0x43U 
#define    TI_PMIC_FSM_TRIG_SEL_1_ADD                0x44U 
#define    TI_PMIC_FSM_TRIG_SEL_2_ADD                0x45U 
#define    TI_PMIC_FSM_TRIG_MASK_1_ADD               0x46U 
#define    TI_PMIC_FSM_TRIG_MASK_2_ADD               0x47U 
#define    TI_PMIC_FSM_TRIG_MASK_3_ADD               0x48U 
#define    TI_PMIC_MASK_BUCK1_2_ADD                  0x49U 
#define    TI_PMIC_MASK_BUCK3_4_ADD                  0x4AU 
#define    TI_PMIC_MASK_BUCK5_ADD                    0x4BU 
#define    TI_PMIC_MASK_LDO1_2_ADD                   0x4CU 
#define    TI_PMIC_MASK_LDO3_4_ADD                   0x4DU 
#define    TI_PMIC_MASK_VMON_ADD                     0x4EU 
#define    TI_PMIC_MASK_GPIO1_8_FALL_ADD             0x4FU 
#define    TI_PMIC_MASK_GPIO1_8_RISE_ADD             0x50U 
#define    TI_PMIC_MASK_GPIO9_11_ADD                 0x51U 
#define    TI_PMIC_MASK_STARTUP_ADD                  0x52U 
#define    TI_PMIC_MASK_MISC_ADD                     0x53U 
#define    TI_PMIC_MASK_MODERATE_ERR_ADD             0x54U 
#define    TI_PMIC_MASK_FSM_ERR_ADD                  0x56U 
#define    TI_PMIC_MASK_COMM_ERR_ADD                 0x57U 
#define    TI_PMIC_MASK_READBACK_ERR_ADD             0x58U 
#define    TI_PMIC_MASK_ESM_ADD                      0x59U 
#define    TI_PMIC_INT_TOP_ADD                       0x5AU 
#define    TI_PMIC_INT_BUCK_ADD                      0x5BU 
#define    TI_PMIC_INT_BUCK1_2_ADD                   0x5CU 
#define    TI_PMIC_INT_BUCK3_4_ADD                   0x5DU 
#define    TI_PMIC_INT_BUCK5_ADD                     0x5EU 
#define    TI_PMIC_INT_LDO_VMON_ADD                  0x5FU 
#define    TI_PMIC_INT_LDO1_2_ADD                    0x60U 
#define    TI_PMIC_INT_LDO3_4_ADD                    0x61U 
#define    TI_PMIC_INT_VMON_ADD                      0x62U 
#define    TI_PMIC_INT_GPIO_ADD                      0x63U 
#define    TI_PMIC_INT_GPIO1_8_ADD                   0x64U 
#define    TI_PMIC_INT_STARTUP_ADD                   0x65U 
#define    TI_PMIC_INT_MISC_ADD                      0x66U 
#define    TI_PMIC_INT_MODERATE_ERR_ADD              0x67U 
#define    TI_PMIC_INT_SEVERE_ERR_ADD                0x68U 
#define    TI_PMIC_INT_FSM_ERR_ADD                   0x69U 
#define    TI_PMIC_INT_COMM_ERR_ADD                  0x6AU 
#define    TI_PMIC_INT_READBACK_ERR_ADD              0x6BU 
#define    TI_PMIC_INT_ESM_ADD                       0x6CU 
#define    TI_PMIC_STAT_BUCK1_2_ADD                  0x6DU 
#define    TI_PMIC_STAT_BUCK3_4_ADD                  0x6EU 
#define    TI_PMIC_STAT_BUCK5_ADD                    0x6FU 
#define    TI_PMIC_STAT_LDO1_2_ADD                   0x70U 
#define    TI_PMIC_STAT_LDO3_4_ADD                   0x71U 
#define    TI_PMIC_STAT_VMON_ADD                     0x72U 
#define    TI_PMIC_STAT_STARTUP_ADD                  0x73U 
#define    TI_PMIC_STAT_MISC_ADD                     0x74U 
#define    TI_PMIC_STAT_MODERATE_ERR_ADD             0x75U 
#define    TI_PMIC_STAT_SEVERE_ERR_ADD               0x76U 
#define    TI_PMIC_STAT_READBACK_ERR_ADD             0x77U 
#define    TI_PMIC_PGOOD_SEL_1_ADD                   0x78U 
#define    TI_PMIC_PGOOD_SEL_2_ADD                   0x79U 
#define    TI_PMIC_PGOOD_SEL_3_ADD                   0x7AU 
#define    TI_PMIC_PGOOD_SEL_4_ADD                   0x7BU 
#define    TI_PMIC_PLL_CTRL_ADD                      0x7CU 
#define    TI_PMIC_CONFIG_1_ADD                      0x7DU 
#define    TI_PMIC_CONFIG_2_ADD                      0x7EU 
#define    TI_PMIC_ENABLE_DRV_REG_ADD                0x80U 
#define    TI_PMIC_MISC_CTRL_ADD                     0x81U
#define    TI_PMIC_ENABLE_DRV_STAT_ADD               0x82U 
#define    TI_PMIC_RECOV_CNT_REG_1_ADD               0x83U 
#define    TI_PMIC_RECOV_CNT_REG_2_ADD               0x84U 
#define    TI_PMIC_FSM_I2C_TRIGGERS_ADD              0x85U 
#define    TI_PMIC_FSM_NSLEEP_TRIGGERS_ADD           0x86U 
#define    TI_PMIC_BUCK_RESET_REG_ADD                0x87U 
#define    TI_PMIC_SPREAD_SPECTRUM_1_ADD             0x88U 
#define    TI_PMIC_FREQ_SEL_ADD                      0x8AU 
#define    TI_PMIC_FSM_STEP_SIZE_ADD                 0x8BU 
#define    TI_PMIC_LDO_RV_TIMEOUT_REG_1_ADD          0x8CU 
#define    TI_PMIC_LDO_RV_TIMEOUT_REG_2_ADD          0x8DU 
#define    TI_PMIC_USER_SPARE_REGS_ADD               0x8EU 
#define    TI_PMIC_ESM_MCU_START_REG_ADD             0x8FU 
#define    TI_PMIC_ESM_MCU_DELAY1_REG_ADD            0x90U 
#define    TI_PMIC_ESM_MCU_DELAY2_REG_ADD            0x91U 
#define    TI_PMIC_ESM_MCU_MODE_CFG_ADD              0x92U 
#define    TI_PMIC_ESM_MCU_HMAX_REG_ADD              0x93U 
#define    TI_PMIC_ESM_MCU_HMIN_REG_ADD              0x94U 
#define    TI_PMIC_ESM_MCU_LMAX_REG_ADD              0x95U 
#define    TI_PMIC_ESM_MCU_LMIN_REG_ADD              0x96U 
#define    TI_PMIC_ESM_MCU_ERR_CNT_REG_ADD           0x97U 
#define    TI_PMIC_ESM_SOC_START_REG_ADD             0x98U 
#define    TI_PMIC_ESM_SOC_DELAY1_REG_ADD            0x99U 
#define    TI_PMIC_ESM_SOC_DELAY2_REG_ADD            0x9AU 
#define    TI_PMIC_ESM_SOC_MODE_CFG_ADD              0x9BU 
#define    TI_PMIC_ESM_SOC_HMAX_REG_ADD              0x9CU 
#define    TI_PMIC_ESM_SOC_HMIN_REG_ADD              0x9DU 
#define    TI_PMIC_ESM_SOC_LMAX_REG_ADD              0x9EU 
#define    TI_PMIC_ESM_SOC_LMIN_REG_ADD              0x9FU 
#define    TI_PMIC_ESM_SOC_ERR_CNT_REG_ADD           0xA0U 
#define    TI_PMIC_REGISTER_LOCK_ADD                 0xA1U 
#define    TI_PMIC_MANUFACTURING_VER_ADD             0xA6U 
#define    TI_PMIC_CUSTOMER_NVM_ID_REG_ADD           0xA7U 
#define    TI_PMIC_SOFT_REBOOT_REG_ADD               0xABU 
#define    TI_PMIC_RTC_SECONDS_ADD                   0xB5U 
#define    TI_PMIC_RTC_MINUTES_ADD                   0xB6U 
#define    TI_PMIC_RTC_HOURS_ADD                     0xB7U 
#define    TI_PMIC_RTC_DAYS_ADD                      0xB8U 
#define    TI_PMIC_RTC_MONTHS_ADD                    0xB9U 
#define    TI_PMIC_RTC_YEARS_ADD                     0xBAU 
#define    TI_PMIC_RTC_WEEKS_ADD                     0xBBU 
#define    TI_PMIC_ALARM_SECONDS_ADD                 0xBCU 
#define    TI_PMIC_ALARM_MINUTES_ADD                 0xBDU 
#define    TI_PMIC_ALARM_HOURS_ADD                   0xBEU 
#define    TI_PMIC_ALARM_DAYS_ADD                    0xBFU 
#define    TI_PMIC_ALARM_MONTHS_ADD                  0xC0U 
#define    TI_PMIC_ALARM_YEARS_ADD                   0xC1U 
#define    TI_PMIC_RTC_CTRL_1_ADD                    0xC2U 
#define    TI_PMIC_RTC_CTRL_2_ADD                    0xC3U 
#define    TI_PMIC_RTC_STATUS_ADD                    0xC4U 
#define    TI_PMIC_RTC_INTERRUPTS_ADD                0xC5U 
#define    TI_PMIC_RTC_COMP_LSB_ADD                  0xC6U 
#define    TI_PMIC_RTC_COMP_MSB_ADD                  0xC7U 
#define    TI_PMIC_RTC_RESET_STATUS_ADD              0xC8U 
#define    TI_PMIC_SCRATCH_PAD_REG_1_ADD             0xC9U 
#define    TI_PMIC_SCRATCH_PAD_REG_2_ADD             0xCAU 
#define    TI_PMIC_SCRATCH_PAD_REG_3_ADD             0xCBU 
#define    TI_PMIC_SCRATCH_PAD_REG_4_ADD             0xCCU 
#define    TI_PMIC_PFSM_DELAY_REG_1_ADD              0xCDU 
#define    TI_PMIC_PFSM_DELAY_REG_2_ADD              0xCEU 
#define    TI_PMIC_PFSM_DELAY_REG_3_ADD              0xCFU 
#define    TI_PMIC_PFSM_DELAY_REG_4_ADD              0xD0U 
#define    TI_PMIC_WD_ANSWER_REG_ADD                 0x01U
#define    TI_PMIC_WD_QUESTION_ANSW_CNT_ADD          0x02U
#define    TI_PMIC_WD_WIN1_CFG_ADD                   0x03U
#define    TI_PMIC_WD_WIN2_CFG_ADD                   0x04U
#define    TI_PMIC_WD_LONGWIN_CFG_ADD                0x05U
#define    TI_PMIC_WD_MODE_REG_ADD                   0x06U
#define    TI_PMIC_WD_QA_CFG_ADD                     0x07U
#define    TI_PMIC_WD_ERR_STATUS_ADD                 0x08U
#define    TI_PMIC_WD_THR_CFG_ADD                    0x09U
#define    TI_PMIC_WD_FAIL_CNT_REG_ADD               0x0AU

#define    TI_PMIC_USER_EE_CTRL_1_ADD                0xA2U
#define    TI_PMIC_USER_EE_CTRL_2_ADD                0xA3U


/* PAGE 1 Registers */

#define TI_PMIC_SERIAL_IF_CONFIG_ADD                 0x1AU
#define TI_PMIC_GENERAL_REG_1_ADD                    0x18U
#define TI_PMIC_EEPROM_CONTROL_2_ADD                 0xE1U
#define TI_PMIC_EECTRL3_ADDRESSCTRL_ADD              0xE2U
#define TI_PMIC_EECTRL8_WRITEDATA3_ADD               0xE7U
#define TI_PMIC_EECTRL9_WRITEDATA2_ADD               0xE8U
#define TI_PMIC_EECTRL10_WRITEDATA1_ADD              0xE9U
#define TI_PMIC_EECTRL11_WRITEDATA0_ADD              0xEAU
#define TI_PMIC_EECTRL12_READDATA3_ADD               0xEBU
#define TI_PMIC_EECTRL13_READDATA2_ADD               0xECU
#define TI_PMIC_EECTRL14_READDATA1_ADD               0xEDU
#define TI_PMIC_EECTRL15_READDATA0_ADD               0xEEU
#define TI_PMIC_EECTRL16_READWRITE_CMD_ADD           0xEFU
#define TI_PMIC_EECTRL20_ACTIVEPOLL_ADD              0xF3U
#define TI_PMIC_USER_EE_PROG_UNLOCK_ADD              0x41U

#endif /* PMICEL2HWIO_H  */

/**********************************************************************************************************
**                                  End of file pmichwio.h                                               **
**********************************************************************************************************/
