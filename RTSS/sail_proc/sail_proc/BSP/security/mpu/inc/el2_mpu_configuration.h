/*
* el2_mpu_configuration.h
*
* Copyright (c) Qualcomm Technologies, Inc.
* All Rights Reserved.
* Qualcomm Technologies Inc. Proprietary and Confidential.
*
*  Created on: Jul 6, 2022
*  Author: shaygold
                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

   when        who         what, where, why
   --------    -----       -----------------------------------------------------
   06/07/21    shaygold    Initial version
 */

#ifndef EL2_MPU_CONFIGURATION_H_
#define EL2_MPU_CONFIGURATION_H_

#include "el2_mpu.h"

el2_mpu_configuration* get_default_configuration(void);
el2_mpu_configuration* get_sw1_configuration(void);
el2_mpu_configuration* get_sw2_configuration(void);
el2_mpu_configuration* get_sw3_configuration(void);
el2_mpu_configuration* get_sw4_configuration(void);
el2_mpu_configuration* get_sec_elf_configuration(void);
el2_mpu_configuration* get_dbg_policy_configuration(void);
boolean sailhyp_xbl_dts_mpu_update(void);
boolean sailhyp_xbl_dts_node_exists(void);
region_configuration sailhyp_xbl_dts_get_node(void);
void sailhyp_xbl_dts_next_node(void);
uint32_t sailhyp_xbl_dts_is_el2_node(void);
uint32_t sailhyp_xbl_dts_is_el1_node(void);
uint32_t sailhyp_xbl_dts_con_srv_board(void);

#endif /* EL2_MPU_DEF_H_ */
