/*
 * Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Export of this technology or software is regulated by the U.S. Government.
 * Diversion contrary to U.S. law prohibited.
 *
 * All ideas, data and information contained in or disclosed by
 * this document are confidential and proprietary information of
 * Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
 * By accepting this material the recipient agrees that this material
 * and the information contained therein are held in confidence and in
 * trust and will not be used, copied, reproduced in whole or in part,
 * nor its contents revealed in any manner to others without the express
 * written permission of Qualcomm Technologies, Inc.
 */

#ifndef SAIL_BIST_H_
#define SAIL_BIST_H_

#include <stdint.h>
#include "boot.h"
#include "syscall.h"
#include "syscall_pub.h"

#define MD_BIST_FUNC  __attribute__ ( ( section ("md_bist_func" ) ) )
#define MD_BIST_DATA  __attribute__ ( ( section ("md_bist_data" ) ) )

#define BIST_PHASE_TEST     (0x0U)
#define BIST_MD_PHASE1      (0x1U)
#define BIST_MD_PHASE2      (0x2U)
#define BIST_MD_POFF        (0x3U)
#define BIST_PHASE_ERROR    (0xfeU)
#define BIST_PHASE_NULL     (0xffU)

#define BIST_SOC_VERSION_2                            0x20000U

#define FORCE_SKIP_MD_BIST_EXECUTION        (1UL)

#define BIST_E_SUCCESS (uint32_t)E_SUCCESS
#define BIST_E_NO_MEMORY (uint32_t)E_NO_MEMORY
#define BIST_E_INVALID_ARG (uint32_t)E_INVALID_ARG
#define BIST_E_NO_DEV (uint32_t)E_NO_DEV
#define BIST_E_DEV_FAILURE (uint32_t)E_DEV_FAILURE
#define BIST_E_TIMER_EXP (uint32_t)E_TIMER_EXP

MD_BIST_FUNC void vCaptureDisableHBCU(void);

MD_BIST_FUNC uint32_t slRunMDBIST(void);
MD_BIST_FUNC void pre_BIST_init(void);
MD_BIST_FUNC void bootcfg_el2_setMDBIST_core(boot_mode_type* bootmode);
MD_BIST_FUNC bool getSkipMDBISTConfig(void);
uint8_t bootcfg_el2_getMDBIST_core(void);


#endif  //SAIL_BIST_H_
