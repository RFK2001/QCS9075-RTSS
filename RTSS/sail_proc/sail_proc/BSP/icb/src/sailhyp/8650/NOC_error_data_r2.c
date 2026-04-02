/*==============================================================================

FILE:      NOC_error_data.c

DESCRIPTION: This file contains target/platform specific configuration data.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A
 
Edit History

When        Who    What, where, why
----------  ---    -----------------------------------------------------------
    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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
==============================================================================*/
#include "NOC_error.h"
#include "NOC_error_HWIO_R2.h"
#include "HALhwio.h"
#include "HALclkHWIO.h"
#include "debug_log.h"

/*============================================================================
                        DEVICE CONFIG PROPERTY DATA
============================================================================*/
/* Internal NOC Configuration Data for Lemans Auto */

NOCERR_info_type NOCERR_cfgdata_R2[4] =
{ 
  [0] = {
    .name            = "ASIL_D_NOC",
    .erl_hw          = &QNOC_4_0,
    .erl_base_addr   = (uint32_t *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ERL_SWID_LOW),
    .intr_vector     = {73U,79U, 81U},  /* sail_asild_noc_Fault, Level trigger interrupt */
    .num_sbms        = 1U,
    .sb_hw           = (NOC_sideband_hw_type *[]){ &QNOC_SB_4_0 },
    .sb_base_addrs   = (void *[]){ (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SBM_SWID_LOW) },
    .num_tos         = 42U,
    .to_addrs        = (void *[]){ (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TRCHECK_REFERENCEGENERATOR_0_REFGEN_REFCTL0_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TRCHECK_REFERENCEGENERATOR_0_REFGEN_MAINCTL_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TRCHECK_REFERENCEGENERATOR_1_REFGEN_REFCTL0_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TRCHECK_REFERENCEGENERATOR_1_REFGEN_MAINCTL_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL0_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL1_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL2_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL3_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL4_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL5_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL6_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL7_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL8_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL9_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL10_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL11_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL12_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL13_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL14_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL15_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL16_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL17_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL18_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL19_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL20_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL21_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL22_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL23_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL24_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL25_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL26_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL27_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL28_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL29_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL30_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL31_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL32_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL33_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL34_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL35_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL36_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_MAINCTL_LOW ),
                                   },
    .syndrome        = { .sbms = (NOCERR_sbm_syndrome_type []){ {0U, 0U} },
                         .sfty_ctl = (NOCERR_sfty_ctl_syndrome_type []){ {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } },
                         .sfty_agg = (NOCERR_sfty_agg_syndrome_type []){ [107U] = {0U, 0U, 0U} }, },
    .num_sfty_ctl    = 1U,
    .sfty_ctl_hw     = (NOC_sfty_ctl_hw_type *[]){ &QNOC_SFTY_CTL_1_0_B },
    .sfty_ctl_addrs  = (void *[]){(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_SWID_LOW)},
    .num_sfty_aggs = (uint32_t []){107U},
    .sfty_aggs = (NOC_sfty_agg_type *[]){
      [0] = (NOC_sfty_agg_type []){ /* SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK */
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_ASILB_NOC_MS_MPU_SFTYAGGREG_SWID_LOW                  ), &QNOC_SFTY_AGG_1_0_XC,     0U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_DMA_MS_MPU_SFTYAGGREG_SWID_LOW                    ), &QNOC_SFTY_AGG_1_0_XC,     1U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TRCHECK_REFERENCEGENERATOR_0_SFTYAGGREG_SWID_LOW  ), &QNOC_SFTY_AGG_1_0_XC,     2U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TRCHECK_REFERENCEGENERATOR_1_SFTYAGGREG_SWID_LOW  ), &QNOC_SFTY_AGG_1_0_XC,     3U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_FAULTS_SFTYAGGREG_SWID_LOW                        ), &QNOC_SFTY_AGG_1_0_XC,     4U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_ASILD_NOC_TIMEOUT_REFERENCEGENERATOR_SFTYAGGREG_SWID_LOW    ), &QNOC_SFTY_AGG_1_0_XC,     5U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_DCD_ASILD_ASILB_DATA_CLK_SFTYAGGREG_SWID_LOW                ), &QNOC_SFTY_AGG_1_0_XC,     6U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_DCD_ASILD_BUSMATRIX_CLK_SFTYAGGREG_SWID_LOW                 ), &QNOC_SFTY_AGG_1_0_XC,     7U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_DCD_ASILD_CPU_QX_CLK_SFTYAGGREG_SWID_LOW                    ), &QNOC_SFTY_AGG_1_0_XC,     8U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_DCD_ASILD_DMA_APB_CLK_SFTYAGGREG_SWID_LOW                   ), &QNOC_SFTY_AGG_1_0_XC,     9U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_DCD_ASILD_DMA_CLK_SFTYAGGREG_SWID_LOW                       ), &QNOC_SFTY_AGG_1_0_XC,     10U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_DCD_ASILD_QUP_CLK_SFTYAGGREG_SWID_LOW                       ), &QNOC_SFTY_AGG_1_0_XC,     11U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_DCD_ASILD_SAIL_QH_CLK_SFTYAGGREG_SWID_LOW                   ), &QNOC_SFTY_AGG_1_0_XC,     12U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_PS_DMA_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0_XC,     13U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_PS_DMA_T_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0,        14U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHM_QUP_SFTYAGGREG_SWID_LOW                                 ), &QNOC_SFTY_AGG_1_0_XC,     15U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHM_QUP_I_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0,        16U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_ACMU_0_SFTYAGGREG_SWID_LOW                              ), &QNOC_SFTY_AGG_1_0_XC,     17U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_ACMU_0_T_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0,        18U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_ACMU_1_SFTYAGGREG_SWID_LOW                              ), &QNOC_SFTY_AGG_1_0_XC,     19U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_ACMU_1_T_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0,        20U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_ASILD_ASILB_NOC_MS_MPU_CFG_SFTYAGGREG_SWID_LOW          ), &QNOC_SFTY_AGG_1_0_XC,     21U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_ASILD_ASILB_NOC_MS_MPU_CFG_T_SFTYAGGREG_SWID_LOW        ), &QNOC_SFTY_AGG_1_0,        22U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_BOOT_ROM_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0_XC,     23U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_BOOT_ROM_T_SFTYAGGREG_SWID_LOW                          ), &QNOC_SFTY_AGG_1_0,        24U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_CPR_CTRL_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0_XC,     25U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_CPR_CTRL_T_SFTYAGGREG_SWID_LOW                          ), &QNOC_SFTY_AGG_1_0,        26U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_DMA_MS_MPU_CFG_SFTYAGGREG_SWID_LOW                      ), &QNOC_SFTY_AGG_1_0_XC,     27U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_DMA_MS_MPU_CFG_T_SFTYAGGREG_SWID_LOW                    ), &QNOC_SFTY_AGG_1_0,        28U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_IPCC_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0_XC,     29U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_IPCC_T_SFTYAGGREG_SWID_LOW                              ), &QNOC_SFTY_AGG_1_0,        30U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_QTIMER_SFTYAGGREG_SWID_LOW                              ), &QNOC_SFTY_AGG_1_0_XC,     31U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_QTIMER_T_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0,        32U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_QUP_CFG_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0_XC,     33U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_QUP_CFG_T_SFTYAGGREG_SWID_LOW                           ), &QNOC_SFTY_AGG_1_0,        34U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_QUP_MEM_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0_XC,     35U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_QUP_MEM_T_SFTYAGGREG_SWID_LOW                           ), &QNOC_SFTY_AGG_1_0,        36U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_SAIL_CSR_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0_XC,     37U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_SAIL_CSR_T_SFTYAGGREG_SWID_LOW                          ), &QNOC_SFTY_AGG_1_0,        38U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_SAILSS_BUSMATRIX_SFTYAGGREG_SWID_LOW                    ), &QNOC_SFTY_AGG_1_0_XC,     39U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_SAILSS_BUSMATRIX_T_SFTYAGGREG_SWID_LOW                  ), &QNOC_SFTY_AGG_1_0,        40U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TLMM_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0_XC,     41U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TLMM_T_SFTYAGGREG_SWID_LOW                              ), &QNOC_SFTY_AGG_1_0,        42U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSC_0_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0_XC,     43U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSC_0_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,        44U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSC_1_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0_XC,     45U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSC_1_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,        46U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSENSE_CTRL_0_SFTYAGGREG_SWID_LOW                       ), &QNOC_SFTY_AGG_1_0_XC,     47U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSENSE_CTRL_0_T_SFTYAGGREG_SWID_LOW                     ), &QNOC_SFTY_AGG_1_0,        48U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSENSE_CTRL_1_SFTYAGGREG_SWID_LOW                       ), &QNOC_SFTY_AGG_1_0_XC,     49U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_TSENSE_CTRL_1_T_SFTYAGGREG_SWID_LOW                     ), &QNOC_SFTY_AGG_1_0,        50U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VMIDMT_0_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0_XC,     51U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VMIDMT_0_T_SFTYAGGREG_SWID_LOW                          ), &QNOC_SFTY_AGG_1_0,        52U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VMIDMT_1_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0_XC,     53U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VMIDMT_1_T_SFTYAGGREG_SWID_LOW                          ), &QNOC_SFTY_AGG_1_0,        54U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VMIDMT_2_SFTYAGGREG_SWID_LOW                            ), &QNOC_SFTY_AGG_1_0_XC,     55U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VMIDMT_2_T_SFTYAGGREG_SWID_LOW                          ), &QNOC_SFTY_AGG_1_0,        56U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VSENSE_CTRL_0_SFTYAGGREG_SWID_LOW                       ), &QNOC_SFTY_AGG_1_0_XC,     57U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VSENSE_CTRL_0_T_SFTYAGGREG_SWID_LOW                     ), &QNOC_SFTY_AGG_1_0,        58U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VSENSE_CTRL_1_SFTYAGGREG_SWID_LOW                       ), &QNOC_SFTY_AGG_1_0_XC,     59U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_VSENSE_CTRL_1_T_SFTYAGGREG_SWID_LOW                     ), &QNOC_SFTY_AGG_1_0,        60U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_0_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0_XC,     61U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_0_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,        62U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_1_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0_XC,     63U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_1_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,        64U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_2_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0_XC,     65U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_2_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,        66U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_3_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0_XC,     67U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QHS_WDT_3_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,        68U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNM_ASILD_ASILB_NOC_DATA_SFTYAGGREG_SWID_LOW                ), &QNOC_SFTY_AGG_1_0_XC,     69U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNM_ASILD_ASILB_NOC_DATA_I_SFTYAGGREG_SWID_LOW              ), &QNOC_SFTY_AGG_1_0_XC,     70U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNS_ASILD_ASILB_CONFIG_SFTYAGGREG_SWID_LOW                  ), &QNOC_SFTY_AGG_1_0_XC,     71U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNS_ASILD_ASILB_CONFIG_T_SFTYAGGREG_SWID_LOW                ), &QNOC_SFTY_AGG_1_0_XC,     72U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNS_ASILD_NOC_MD_0_SFTYAGGREG_SWID_LOW                      ), &QNOC_SFTY_AGG_1_0_XC,     73U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNS_ASILD_NOC_MD_0_T_SFTYAGGREG_SWID_LOW                    ), &QNOC_SFTY_AGG_1_0_XC,     74U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNS_ISOLATION_CFG_SFTYAGGREG_SWID_LOW                       ), &QNOC_SFTY_AGG_1_0_XC,     75U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_QNS_ISOLATION_CFG_T_SFTYAGGREG_SWID_LOW                     ), &QNOC_SFTY_AGG_1_0_XC,     76U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_0_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0,        67U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_0_T_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0,        68U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_1_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0,        69U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_1_T_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0,        80U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_2_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0,        81U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_2_T_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0,        82U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_3_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0,        83U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_3_T_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0,        84U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_4_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0,        85U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_4_T_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0,        86U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_5_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0,        87U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRAM_5_T_SFTYAGGREG_SWID_LOW                                ), &QNOC_SFTY_AGG_1_0,        88U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRVC_ASILD_NOC_SAIL_0_SFTYAGGREG_SWID_LOW                     ), &QNOC_SFTY_AGG_1_0_XC,    89U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRVC_ASILD_NOC_SAIL_0_T_SFTYAGGREG_SWID_LOW                   ), &QNOC_SFTY_AGG_1_0,       90U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRVC_ASILD_NOC_SAIL_1_SFTYAGGREG_SWID_LOW                     ), &QNOC_SFTY_AGG_1_0_XC,    91U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_SRVC_ASILD_NOC_SAIL_1_T_SFTYAGGREG_SWID_LOW                   ), &QNOC_SFTY_AGG_1_0,       92U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_DMA_SFTYAGGREG_SWID_LOW                                    ), &QNOC_SFTY_AGG_1_0_XC,    93U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_DMA_I_SFTYAGGREG_SWID_LOW                                  ), &QNOC_SFTY_AGG_1_0,       94U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_0_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,       95U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_0_I_SFTYAGGREG_SWID_LOW                           ), &QNOC_SFTY_AGG_1_0,       96U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_1_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,       97U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_1_I_SFTYAGGREG_SWID_LOW                           ), &QNOC_SFTY_AGG_1_0,       98U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_0_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,       99U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_0_I_SFTYAGGREG_SWID_LOW                           ), &QNOC_SFTY_AGG_1_0,       100U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_1_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,       101U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_1_I_SFTYAGGREG_SWID_LOW                           ), &QNOC_SFTY_AGG_1_0,       102U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XS_R52_TCM0_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0,       103U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XS_R52_TCM0_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,       104U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XS_R52_TCM1_SFTYAGGREG_SWID_LOW                               ), &QNOC_SFTY_AGG_1_0,       105U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_D_ASIL_D_NOC_XS_R52_TCM1_T_SFTYAGGREG_SWID_LOW                             ), &QNOC_SFTY_AGG_1_0,       106U},
      },
    },
  },
  [1] = {
    .name            = "ASIL_B_NOC",
    .erl_hw          = &QNOC_4_0,
    .erl_base_addr   = (uint32_t *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ERL_SWID_LOW),
    .intr_vector     = {54U, 57U, 58U}, /* sail_asil_b_noc_Fault */
    .num_sbms        = 2U,
    .sb_hw           = (NOC_sideband_hw_type *[]){ &QNOC_SB_4_0_IO_L, &QNOC_SB_4_0_OS_L },
    .sb_base_addrs   = (void *[]){ (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_SAIL_TIMEOUT_SBM_SBM_SWID_LOW),
                                   (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_SWID_LOW) },
    .num_tos         = 27U,
    .to_addrs        = (void *[]){  (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TRCHECK_REFERENCEGENERATOR_0_REFGEN_MAINCTL_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TRCHECK_REFERENCEGENERATOR_0_REFGEN_REFCTL0_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TRCHECK_REFERENCEGENERATOR_1_REFGEN_MAINCTL_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TRCHECK_REFERENCEGENERATOR_1_REFGEN_REFCTL0_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL0_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL1_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL2_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL3_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL4_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL5_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL6_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL7_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL8_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL9_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL10_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL11_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL12_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL13_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL14_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL15_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL16_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL17_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL18_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL19_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL20_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL21_LOW),
                                    (void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_REFCTL22_LOW),
                                    (void*)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_REFGEN_MAINCTL_LOW),
                                   },
    .syndrome        = { .sbms = (NOCERR_sbm_syndrome_type []){ {0U, 0U} },
                         .sfty_ctl = (NOCERR_sfty_ctl_syndrome_type []){ {0U, 0U, 0U, 0U, 0U} },
                         .sfty_agg = (NOCERR_sfty_agg_syndrome_type []){ [47] = {0U, 0U, 0U} }, },
    .num_sfty_ctl    = 1U,
    .sfty_ctl_hw     = (NOC_sfty_ctl_hw_type *[]){ &QNOC_SFTY_CTL_1_0 },
    .sfty_ctl_addrs  = (void *[]){(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_SWID_LOW)}, /* A2NOC safety feeds into A1NOC ctl */
    .num_sfty_aggs = (uint32_t []){47U},
    .sfty_aggs = (NOC_sfty_agg_type *[]){
      [0] = (NOC_sfty_agg_type []){ /* SAILSS_ASIL_B_SAIL_ASIL_B_NOC  */
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TRCHECK_REFERENCEGENERATOR_0_SFTYAGGREG_SWID_LOW),  &QNOC_SFTY_AGG_1_0_XC, 0U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TRCHECK_REFERENCEGENERATOR_1_SFTYAGGREG_SWID_LOW),  &QNOC_SFTY_AGG_1_0_XC, 1U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SFTYAGGREG_SWID_LOW            ),  &QNOC_SFTY_AGG_1_0_XC, 2U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_SAIL_TIMEOUT_SBM_SFTYAGGREG_SWID_LOW            ),  &QNOC_SFTY_AGG_1_0_XC, 3U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_TIMEOUT_REFERENCEGENERATOR_SFTYAGGREG_SWID_LOW  ),  &QNOC_SFTY_AGG_1_0_XC, 4U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_PS_HBCU_SAFE_APB_T_SFTYAGGREG_SWID_LOW                     ),  &QNOC_SFTY_AGG_1_0,    5U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_PS_MD_SAFE_APB_T_SFTYAGGREG_SWID_LOW                       ),  &QNOC_SFTY_AGG_1_0_XC, 6U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_0_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    7U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_1_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    8U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_2_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    9U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_3_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    10U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_4_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    11U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_5_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    12U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_6_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    13U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_CAN_7_I_SFTYAGGREG_SWID_LOW                            ),  &QNOC_SFTY_AGG_1_0,    14U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_QDSS_DCC_I_SFTYAGGREG_SWID_LOW                         ),  &QNOC_SFTY_AGG_1_0,    15U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_QSPI_I_SFTYAGGREG_SWID_LOW                             ),  &QNOC_SFTY_AGG_1_0,    16U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHM_TIC_I_SFTYAGGREG_SWID_LOW                              ),  &QNOC_SFTY_AGG_1_0,    17U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_0_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    18U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_1_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    19U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_2_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    20U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_3_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    21U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_4_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    22U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_5_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    23U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_6_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    24U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_CAN_S_7_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    25U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_ETH_S_0_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    26U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_GPCE_T_SFTYAGGREG_SWID_LOW                             ),  &QNOC_SFTY_AGG_1_0,    27U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_HBCU_T_SFTYAGGREG_SWID_LOW                             ),  &QNOC_SFTY_AGG_1_0,    28U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_HWKM_T_SFTYAGGREG_SWID_LOW                             ),  &QNOC_SFTY_AGG_1_0,    29U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_PKE_T_SFTYAGGREG_SWID_LOW                              ),  &QNOC_SFTY_AGG_1_0,    30U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_QDSS_CFG_T_SFTYAGGREG_SWID_LOW                         ),  &QNOC_SFTY_AGG_1_0,    31U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_QSPI_S_T_SFTYAGGREG_SWID_LOW                           ),  &QNOC_SFTY_AGG_1_0,    32U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_SPARE_AHB_1_T_SFTYAGGREG_SWID_LOW                      ),  &QNOC_SFTY_AGG_1_0,    34U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_SECURE_CTRL_T_SFTYAGGREG_SWID_LOW                      ),  &QNOC_SFTY_AGG_1_0,    34U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QHS_SPARE_AHB_2_T_SFTYAGGREG_SWID_LOW                      ),  &QNOC_SFTY_AGG_1_0,    35U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QNM_ASILD_ASILB_CONFIG_I_SFTYAGGREG_SWID_LOW               ),  &QNOC_SFTY_AGG_1_0_XC, 36U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QNS_ASIL_B_ISOLATION_NOC_CFG_T_SFTYAGGREG_SWID_LOW         ),  &QNOC_SFTY_AGG_1_0,    37U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QNS_ASIL_B_NOC_MD1_T_SFTYAGGREG_SWID_LOW                   ),  &QNOC_SFTY_AGG_1_0_XC, 38U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QNS_ASILD_ASILB_DATA_T_SFTYAGGREG_SWID_LOW                 ),  &QNOC_SFTY_AGG_1_0_XC, 39U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_QXM_GPCE_I_SFTYAGGREG_SWID_LOW                             ),  &QNOC_SFTY_AGG_1_0,    40U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_SRVC_ASIL_B_NOC_SAIL_SFTYAGGREG_SWID_LOW                   ),  &QNOC_SFTY_AGG_1_0_XC, 41U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_SRVC_ASIL_B_NOC_SAIL_T_SFTYAGGREG_SWID_LOW                 ),  &QNOC_SFTY_AGG_1_0,    42U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_XM_ETH_0_I_SFTYAGGREG_SWID_LOW                             ),  &QNOC_SFTY_AGG_1_0,    43U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_XM_QDSS_DAP_I_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    44U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_XM_QDSS_ETR_I_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    45U},
          {(void *)HWIO_ADDR(SAILSS_ASIL_B_ASIL_B_NOC_XS_QDSS_STM_T_SFTYAGGREG_SWID_LOW                          ),  &QNOC_SFTY_AGG_1_0,    46U},
        /*
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SERVICE_ASIL_B_ISOLATION_SAIL_SFTYAGGREG_SWID_LOW	    ), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SERVICE_ASIL_B_ISOLATION_SAIL_T_SFTYAGGREG_SWID_LOW	), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_QNM_ASIL_B_NOC_IN_I_SFTYAGGREG_SWID_LOW		    	), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_QNM_ASIL_B_ISOLATION_NOC_CFG_I_SFTYAGGREG_SWID_LOW	), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_REFGEN_0_SFTYAGGREG_SWID_LOW			), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_REFGEN_1_SFTYAGGREG_SWID_LOW			), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_TIMEOUT_REFGEN_SFTYAGGREG_SWID_LOW	    ), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_QNS_SAILSS_MD1_T_SFTYAGGREG_SWID_LOW					), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_MD1_REFGEN_SFTYAGGREG_SWID_LOW		    ), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_ASIL_B_ISOLATION_NOC_SBM_SFTYAGGREG_SWID_LOW			), &QNOC_SFTY_AGG_1_0,    0},
        {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_ASIL_B_OR_TIMEOUT_SFTYAGGREG_SWID_LOW                 ), &QNOC_SFTY_AGG_1_0,    0},
       */
      },
    },
  },
  [2]={
    .name            = "ASIL_D_ISOLATION_NOC",
    .erl_hw          = 0U, /*Error logger reg set is no present for this Isolation noc*/
    .erl_base_addr   = 0U,
    .intr_vector     = {70U, 74U, 77U}, /* sail_asil_d_isolation noc_Fault */
    .num_sbms        = 2U,
    .sb_hw           = (NOC_sideband_hw_type *[]){ &QNOC_SB_4_0_L, &QNOC_SB_4_0_IOS_L},
    .sb_base_addrs   = (void *[]){ (void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_ASILD_ISOLATION_OR_TIMEOUT_SBM_SWID_LOW),
    	                           (void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_ASILD_ISOLATION_NOC_SBM_SBM_SWID_LOW)},
    .num_tos         = 3U,
    .to_addrs        = (void *[]){ (void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL0_LOW),
    	                           (void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL1_LOW),
    	                           (void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_MAINCTL_LOW),
    },
    .syndrome        = { .sbms = (NOCERR_sbm_syndrome_type []){ {0U, 0U} },
                         .sfty_ctl = (NOCERR_sfty_ctl_syndrome_type []){ {0U, 0U, 0U, 0U, 0U} },
                         .sfty_agg = (NOCERR_sfty_agg_syndrome_type []){ [11] = {0U, 0U, 0U} }, },
     .num_sfty_ctl    = 1U,
     .sfty_ctl_hw     = (NOC_sfty_ctl_hw_type *[]){ &QNOC_SFTY_CTL_1_0_L },
     .sfty_ctl_addrs  = (void *[]){(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SFTYCTL_SWID_LOW)},
     .num_sfty_aggs   = (uint32_t []){11},
     .sfty_aggs =       (NOC_sfty_agg_type *[]){
                           [0] = (NOC_sfty_agg_type []){
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_ASILD_ISOLATION_OR_TIMEOUT_SFTYAGGREG_SWID_LOW	   ), &QNOC_SFTY_AGG_1_0_XC, 0U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_ASILD_ISOLATION_NOC_SBM_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 1U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_QNM_IN_I_SFTYAGGREG_SWID_LOW	                       ), &QNOC_SFTY_AGG_1_0_XC, 2U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_QNM_ISOLATION_NOC_CFG_I_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 3U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_QNS_SAILSS_MD_0_T_SFTYAGGREG_SWID_LOW	           ), &QNOC_SFTY_AGG_1_0_XC, 4U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_MD0_REFGEN_SFTYAGGREG_SWID_LOW	   ), &QNOC_SFTY_AGG_1_0,    5U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_REFGEN_0_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 6U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_REFGEN_1_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 7U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_SFTYAGGREG_SWID_LOW   ), &QNOC_SFTY_AGG_1_0_XC, 8U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SERVICE_ISOLATION_SAIL_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 9U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_D_ISOLATIONNOC_SERVICE_ISOLATION_SAIL_T_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0,   10U},
                           },
                           },
      },
  [3]={
    .name            = "ASIL_B_ISOLATION_NOC",
    .erl_hw              = &QNOC_4_0,/*Error logger reg set is no present in ISOlation noc*/
    .erl_base_addr       = (uint32_t *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_ERL_SWID_LOW),

    .intr_vector     = {52U,59U,60U}, /* sail_asil_b_isolation noc_Fault */
    .num_sbms        = 2U,
    .sb_hw           = (NOC_sideband_hw_type *[]){ &QNOC_SB_4_0_IOS_L, &QNOC_SB_4_0_L },
    .sb_base_addrs   = (void *[]){ (void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_ASIL_B_ISOLATION_NOC_SBM_SBM_SWID_LOW),
    	                           (void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_ASIL_B_OR_TIMEOUT_SBM_SWID_LOW)},
    .num_tos         = 4U,
    .to_addrs        = (void *[]){ (void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL0_LOW),
    	                           (void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL1_LOW),
    	                           (void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL2_LOW),
    	                           (void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_MAINCTL_LOW),
    },
    .syndrome        = { .sbms = (NOCERR_sbm_syndrome_type []){ {0U, 0U} },
                         .sfty_ctl = (NOCERR_sfty_ctl_syndrome_type []){ {0U, 0U, 0U, 0U, 0U} },
                         .sfty_agg = (NOCERR_sfty_agg_syndrome_type []){ [12] = {0U, 0U, 0U} }, },
     .num_sfty_ctl    = 1U,
     .sfty_ctl_hw     = (NOC_sfty_ctl_hw_type *[]){ &QNOC_SFTY_CTL_1_0_L },
     .sfty_ctl_addrs  = (void *[]){(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SFTYCTL_SWID_LOW)},
     .num_sfty_aggs   = (uint32_t []){12U},
     .sfty_aggs =       (NOC_sfty_agg_type *[]){
                           [0] = (NOC_sfty_agg_type []){
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_ASIL_B_OR_TIMEOUT_SFTYAGGREG_SWID_LOW	                   ), &QNOC_SFTY_AGG_1_0_XC, 0U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_ASIL_B_ISOLATION_NOC_SBM_SFTYAGGREG_SWID_LOW	               ), &QNOC_SFTY_AGG_1_0_XC, 1U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_QHS_ASIL_B_NOC_MPU_CFG_T_SFTYAGGREG_SWID_LOW	               ), &QNOC_SFTY_AGG_1_0,    2U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_QNM_ASIL_B_ISOLATION_NOC_CFG_I_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 3U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_QNM_ASIL_B_NOC_IN_I_SFTYAGGREG_SWID_LOW	                   ), &QNOC_SFTY_AGG_1_0_XC, 4U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_QNS_SAILSS_MD1_T_SFTYAGGREG_SWID_LOW                        ), &QNOC_SFTY_AGG_1_0,    5U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_MD1_REFGEN_SFTYAGGREG_SWID_LOW	           ), &QNOC_SFTY_AGG_1_0_XC, 6U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_REFGEN_0_SFTYAGGREG_SWID_LOW	               ), &QNOC_SFTY_AGG_1_0_XC, 7U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_REFGEN_1_SFTYAGGREG_SWID_LOW	               ), &QNOC_SFTY_AGG_1_0_XC, 8U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SAIL_ISOLATION_TIMEOUT_REFGEN_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 9U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SERVICE_ASIL_B_ISOLATION_SAIL_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0_XC, 10U},
                                 {(void *)HWIO_ADDR(SAILSS_ASIL_B_ISOLATION_ASIL_B_NOC_SERVICE_ASIL_B_ISOLATION_SAIL_T_SFTYAGGREG_SWID_LOW	       ), &QNOC_SFTY_AGG_1_0,    11U},
                           },
                           },
      }
};

static void *clock_reg_addrs[] =
{
  (uint32_t *)HWIO_ADDR(SAIL_TO_MD_GCC_NOC_BUS_TIMEOUT_EXTREF_CBCR),
  (uint32_t *)HWIO_ADDR(SAIL_TO_MD_GCC_NOC_BUS_TIMEOUT_EXTREF_DIV_CDIVR),
  (uint32_t *)HWIO_ADDR(SAIL_TO_MD_GCC_NOC_BUS_TIMEOUT_EXTREF_DIV512_CDIVR)
};

/* LemansAu family identification */
NOCERR_config_info_type NOCERR_propdata_R2 =
{
  .num_configs = 1,
  .configs = (NOCERR_propdata_type [])
    {
      /* Target info: Lemans  */
      [0] = 
        {
          .family          = CHIPINFO_FAMILY_LEMANSAU,
          .match           = false,
          .version         = CHIPINFO_VERSION(2U,0U),

          /* NoC info. */
          .len             = sizeof(NOCERR_cfgdata_R2)/sizeof(NOCERR_info_type),
          .NOCInfo         = NOCERR_cfgdata_R2,
          .num_clock_regs  = sizeof(clock_reg_addrs)/sizeof(clock_reg_addrs[0]),
          .clock_reg_addrs = clock_reg_addrs,
        },
    },
};


/* MonacoAu family identification */
NOCERR_config_info_type NOCERR_propdata_MONACOAU =
{
  .num_configs = 1,
  .configs = (NOCERR_propdata_type [])
    {
      /* Target info: Lemans  */
      [0] =
        {
          .family          = CHIPINFO_FAMILY_MONACOAU,
          .match           = false,
          .version         = CHIPINFO_VERSION(1U,0U),

          /* NoC info. */
          .len             = sizeof(NOCERR_cfgdata_R2)/sizeof(NOCERR_info_type),
          .NOCInfo         = NOCERR_cfgdata_R2,
          .num_clock_regs  = sizeof(clock_reg_addrs)/sizeof(clock_reg_addrs[0]),
          .clock_reg_addrs = clock_reg_addrs,
        },
    },
};

/*============================================================================
                                 FUNCTIONS
============================================================================*/
NOCERR_config_info_type*  NOC_Error_Platform_Get_Data(void)
{
	NOCERR_config_info_type *NOCERR_config_info = NULL;
  ChipInfoVersionType ICB_LeManSailVersion =0U;
  ChipInfoFamilyType ICB_SailFamily = CHIPINFO_FAMILY_LEMANSAU;

  ICB_LeManSailVersion = ChipInfo_GetSailChipVersion();
  ICB_SailFamily = ChipInfo_GetChipFamily();

	if (CHIPINFO_FAMILY_MONACOAU == ICB_SailFamily )
	{
		 //DEBUG_LOG(SAIL_INFO,"[ICB] : CHIPINFO_FAMILY_MONACOAU         \n\r" );
		NOCERR_config_info = &NOCERR_propdata_MONACOAU;
	}
	else
	{
		if(ICB_LeManSailVersion == ICB_LEMANS_SAIL_R1_VERSION )
	    {
	    	DEBUG_LOG(SAIL_ERROR,"[ICB] : LEMANS_SAIL_R1_VERSION is not supported.\n\r" );
	    }
	    else
	    {
	    	//DEBUG_LOG(SAIL_INFO,"[ICB] : R2 ICB_LeManSailVersion         \n\r" );
	    	NOCERR_config_info = &NOCERR_propdata_R2;
	    }
	}

	return NOCERR_config_info;
}

/**********************************************************************************************************
**                                  End of file                                                         **
**********************************************************************************************************/
