/*
===========================================================================
*/
/**
    @file  spinor_pvl_api.c
    @brief PVL api

*/
/*
    ===========================================================================

    Copyright (c) 2022 - 2025 Qualcomm Technologies, Inc.
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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include <string.h>
#include "spinor_core.h"
#include "spinor_utils.h"
#include "spinor_init_config.h"
#include "spinor_sfdp.h"
#include "spinor_sfdp_util.h"
#include "spinor_diag.h"

extern spinor_sfdp_t g_sfdp_data;

SPINOR_STATUS spinor_pvl_enter_powder_down(void)
{
  return spinor_util_enter_deep_power_down();
}
SPINOR_STATUS spinor_pvl_exit_powder_down(void)
{
  return spinor_util_exit_deep_power_down();
}
SPINOR_STATUS spinor_pvl_get_bus_type(boolean *bOSPI)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  do
  {
    if (bOSPI == NULL)
    {
      SPINOR_LOG_ERROR("%s: error, bOSPI is NULL\r\n");
      break;
    }
    if (g_sfdp_data.inst_4byte_size == 0U)
    {
      SPINOR_LOG_ERROR("%s: error, No 4-bytes inst table\r\n");
      break;
    }

    if (g_sfdp_data.inst4b_data.read_114_support || g_sfdp_data.inst4b_data.read_144_support)
    {
      *bOSPI = FALSE;
    }
    else if (g_sfdp_data.inst4b_data.read_118_support)
    {
      *bOSPI = TRUE;
    }
    else
    {
      break;
    }
    status = SPINOR_DEVICE_DONE;
  } while (FALSE);
  return status;
}

boolean spinor_pvl_check_dtr(void)
{
  //return g_sfdp_data.bparam_data.ds_sup_dtr_mode == 1U; mhz_888d_dt
  return (g_sfdp_data.bparam_data.mhz_888d_dt != 0U || g_sfdp_data.bparam_data.mhz_888d_ndt != 0U);
}
boolean spinor_pvl_check_read_114S(void)
{
    return (g_sfdp_data.inst4b_data.read_114_support == 1U && g_sfdp_data.inst4b_data.prog_114_support == 1U);
}
boolean spinor_pvl_check_read_144S(void)
{
  return (g_sfdp_data.inst4b_data.read_144_support == 1U && g_sfdp_data.inst4b_data.prog_144_support == 1U);
}
boolean spinor_pvl_check_read_118S(void)
{
  return (g_sfdp_data.inst4b_data.read_118_support == 1U);
}
boolean spinor_pvl_check_read_188S(void)
{
  return (g_sfdp_data.inst4b_data.read_188_support == 1U);
}
boolean spinor_pvl_check_888S(void)
{
  boolean bRet = FALSE;
  if ((g_sfdp_data.bparam_data.mhz_888s_dt  != 0U  && g_sfdp_data.bparam_data.mhz_888s_dt != 0b1111 && g_sfdp_data.bparam_data.mhz_888s_dt  != 0b1110) ||
      (g_sfdp_data.bparam_data.mhz_888s_ndt != 0U && g_sfdp_data.bparam_data.mhz_888s_ndt != 0b1111 && g_sfdp_data.bparam_data.mhz_888s_ndt != 0b1110))
  {
    bRet = TRUE;
  }
  return bRet;
}

uint32_t spinor_pvl_get_444_str_max_freq(void)
{
  uint32_t max_clk_khz = spinor_sfdp_util_get_maxfreq(g_sfdp_data.bparam_data.mhz_444s_ndt);

  return max_clk_khz;
}

/*uint32_t spinor_pvl_get_444_dtr_max_freq(void)
{
  uint32_t mhz;
  uint32_t max_clk_khz;

  if (g_sfdp_data.bparam_data.mhz_444d_dt != 0)
  {
    mhz = g_sfdp_data.bparam_data.mhz_444d_dt;
  }
  else
  {
    mhz = g_sfdp_data.bparam_data.mhz_444d_ndt;
  }
  max_clk_khz = spinor_sfdp_util_get_maxfreq(mhz);

  return max_clk_khz;
}*/

/*uint32_t spinor_pvl_get_888_str_max_freq(void)
{
  uint32_t max_clk_khz = spinor_sfdp_util_get_maxfreq(g_sfdp_data.bparam_data.mhz_888s_ndt);

  return max_clk_khz;
}*/

uint32_t spinor_pvl_get_888_dtr_max_freq(void)
{
  uint32_t mhz;
  uint32_t max_clk_khz;

  mhz = g_sfdp_data.bparam_data.mhz_888d_dt;

  max_clk_khz = spinor_sfdp_util_get_maxfreq(mhz);
  return max_clk_khz;
}

/**********************************************************
 * Dump SFDP table to UART console.
 *
 * @param NA
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_pvl_sfdp_dump(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
#if (defined(NORPVL_ENB) || defined(SPINOR_SFDP_DUMP_ENABLED))
  spinor_sfdp_basic_param *bparam;
  spinor_sfdp_4byte_inst *inst4b;
  spinor_sfdp_xspi_profile_1_0 *profile10;

  bparam    = &g_sfdp_data.bparam_data;
  inst4b    = &g_sfdp_data.inst4b_data;
  profile10 = &g_sfdp_data.profile10_data;

  do
  {
    if (g_sfdp_data.basic_param_size == 0U || g_sfdp_data.inst_4byte_size == 0U)
    {
      status = SPINOR_DEVICE_FAIL;
      break;
    }

    if (!(g_sfdp_data.inst4b_data.read_114_support || g_sfdp_data.inst4b_data.read_144_support))
    {
        if (g_sfdp_data.inst4b_data.prog_118_support && g_sfdp_data.profile10_size == 0U)
        {
          status = SPINOR_DEVICE_NOT_SUPPORTED;
          break;
        }
    }

    SPINOR_LOG_WARNING("SFDP Basic paramters header\r\n");
    SPINOR_LOG_WARNING("SFDP Basic paramters header param_id_lsb = 0x%x\r\n", g_sfdp_data.bparam_paramh.param_id_lsb);
    SPINOR_LOG_WARNING("SFDP Basic paramters header minor_rev = 0x%x\r\n", g_sfdp_data.bparam_paramh.minor_rev);
    SPINOR_LOG_WARNING("SFDP Basic paramters header major_rev = 0x%x\r\n", g_sfdp_data.bparam_paramh.major_rev);
    SPINOR_LOG_WARNING("SFDP Basic paramters header table_length = 0x%x\r\n", g_sfdp_data.bparam_paramh.table_length);
    SPINOR_LOG_WARNING("SFDP Basic paramters header table_pointer = 0x%x\r\n", g_sfdp_data.bparam_paramh.table_pointer);
    SPINOR_LOG_WARNING("SFDP Basic paramters header param_id_msb = 0x%x\r\n", g_sfdp_data.bparam_paramh.param_id_msb);
    SPINOR_LOG_WARNING("SFDP Basic paramters header end\r\n");

    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 1\r\n");
    /* DWORD 1 */
    SPINOR_LOG_WARNING("blk_erase_size 0x%x\r\n", bparam->blk_erase_size);
    SPINOR_LOG_WARNING("write_granularity 0x%x\r\n", bparam->write_granularity);
    SPINOR_LOG_WARNING("volatile_block_protect 0x%x\r\n", bparam->volatile_block_protect);
    SPINOR_LOG_WARNING("write_enable_instruction 0x%x\r\n", bparam->write_enable_instruction);
    SPINOR_LOG_WARNING("reserved1_1 0x%x\r\n", bparam->reserved1_1);
    SPINOR_LOG_WARNING("erase_instr_4k 0x%x\r\n", bparam->erase_instr_4k);
    SPINOR_LOG_WARNING("read_112_support 0x%x\r\n", bparam->read_112_support);
    SPINOR_LOG_WARNING("address_bytes_sup 0x%x\r\n", bparam->address_bytes_sup);
    SPINOR_LOG_WARNING("dtr_support 0x%x\r\n", bparam->dtr_support);
    SPINOR_LOG_WARNING("read_122_support 0x%x\r\n", bparam->read_122_support);
    SPINOR_LOG_WARNING("read_144_support 0x%x\r\n", bparam->read_144_support);
    SPINOR_LOG_WARNING("read_114_support 0x%x\r\n", bparam->read_114_support);
    SPINOR_LOG_WARNING("reserved1_2 0x%x\r\n", bparam->reserved1_2);
    /* DWORD 2 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 2\r\n");
    SPINOR_LOG_WARNING("density 0x%x\r\n", bparam->density);
    /* DWORD 3 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 3\r\n");
    SPINOR_LOG_WARNING("read_144_dummy_cycles 0x%x\r\n", bparam->read_144_dummy_cycles);
    SPINOR_LOG_WARNING("read_144_mode_clocks 0x%x\r\n", bparam->read_144_mode_clocks);
    SPINOR_LOG_WARNING("read_144_instruction 0x%x\r\n", bparam->read_144_instruction);
    SPINOR_LOG_WARNING("read_114_dummy_cycles 0x%x\r\n", bparam->read_114_dummy_cycles);
    SPINOR_LOG_WARNING("read_114_mode_clocks 0x%x\r\n", bparam->read_114_mode_clocks);
    SPINOR_LOG_WARNING("read_114_instruction 0x%x\r\n", bparam->read_114_instruction);
    /* DWORD 4 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 4\r\n");
    SPINOR_LOG_WARNING("read_112_dummy_cycles 0x%x\r\n", bparam->read_112_dummy_cycles);
    SPINOR_LOG_WARNING("read_112_mode_clocks 0x%x\r\n", bparam->read_112_mode_clocks);
    SPINOR_LOG_WARNING("read_112_instruction 0x%x\r\n", bparam->read_112_instruction);
    SPINOR_LOG_WARNING("read_122_dummy_cycles 0x%x\r\n", bparam->read_122_dummy_cycles);
    SPINOR_LOG_WARNING("read_122_mode_clocks 0x%x\r\n", bparam->read_122_mode_clocks);
    SPINOR_LOG_WARNING("read_122_instruction 0x%x\r\n", bparam->read_122_instruction);
    /* DWORD 5 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 5\r\n");
    SPINOR_LOG_WARNING("read_222_support 0x%x\r\n", bparam->read_222_support);
    SPINOR_LOG_WARNING("reserved5_1 0x%x\r\n", bparam->reserved5_1);
    SPINOR_LOG_WARNING("read_444_support 0x%x\r\n", bparam->read_444_support);
    SPINOR_LOG_WARNING("reserved5_2 0x%x\r\n", bparam->reserved5_2);
    /* DWORD 6 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 6\r\n");
    SPINOR_LOG_WARNING("reserved6_1 0x%x\r\n", bparam->reserved6_1);
    SPINOR_LOG_WARNING("read_222_dummy_cycles 0x%x\r\n", bparam->read_222_dummy_cycles);
    SPINOR_LOG_WARNING("read_222_mode_clocks 0x%x\r\n", bparam->read_222_mode_clocks);
    SPINOR_LOG_WARNING("read_222_instruction 0x%x\r\n", bparam->read_222_instruction);
    /* DWORD 7 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 7\r\n");
    SPINOR_LOG_WARNING("reserved7_1 0x%x\r\n", bparam->reserved7_1);
    SPINOR_LOG_WARNING("read_444_dummy_cycles 0x%x\r\n", bparam->read_444_dummy_cycles);
    SPINOR_LOG_WARNING("read_444_mode_clocks 0x%x\r\n", bparam->read_444_mode_clocks);
    SPINOR_LOG_WARNING("read_444_instruction 0x%x\r\n", bparam->read_444_instruction);
    /* DWORD 8 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 8\r\n");
    SPINOR_LOG_WARNING("erase_type1_size 0x%x\r\n", bparam->erase_type1_size);
    SPINOR_LOG_WARNING("erase_type1_inst 0x%x\r\n", bparam->erase_type1_inst);
    SPINOR_LOG_WARNING("erase_type2_size 0x%x\r\n", bparam->erase_type2_size);
    SPINOR_LOG_WARNING("erase_type2_inst 0x%x\r\n", bparam->erase_type2_inst);
    /* DWORD 9 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 9\r\n");
    SPINOR_LOG_WARNING("erase_type3_size 0x%x\r\n", bparam->erase_type3_size);
    SPINOR_LOG_WARNING("erase_type3_inst 0x%x\r\n", bparam->erase_type3_inst);
    SPINOR_LOG_WARNING("erase_type4_size 0x%x\r\n", bparam->erase_type4_size);
    SPINOR_LOG_WARNING("erase_type4_inst 0x%x\r\n", bparam->erase_type4_inst);
    /* DWORD 10 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 10\r\n");
    SPINOR_LOG_WARNING("erase_time_multiplier 0x%x\r\n", bparam->erase_time_multiplier);
    SPINOR_LOG_WARNING("erase_type1_time 0x%x\r\n", bparam->erase_type1_time);
    SPINOR_LOG_WARNING("erase_type2_time 0x%x\r\n", bparam->erase_type2_time);
    SPINOR_LOG_WARNING("erase_type3_time 0x%x\r\n", bparam->erase_type3_time);
    SPINOR_LOG_WARNING("erase_type4_time 0x%x\r\n", bparam->erase_type4_time);
    /* DWORD 11 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 11\r\n");
    SPINOR_LOG_WARNING("program_multiplier 0x%x\r\n", bparam->program_multiplier);
    SPINOR_LOG_WARNING("page_size 0x%x\r\n", bparam->page_size);
    SPINOR_LOG_WARNING("page_prog_time 0x%x\r\n", bparam->page_prog_time);
    SPINOR_LOG_WARNING("byte_prog_time_first 0x%x\r\n", bparam->byte_prog_time_first);
    SPINOR_LOG_WARNING("byte_prog_time_additional 0x%x\r\n", bparam->byte_prog_time_additional);
    SPINOR_LOG_WARNING("erase_time 0x%x\r\n", bparam->erase_time);
    SPINOR_LOG_WARNING("reserved11_1 0x%x\r\n", bparam->reserved11_1);
    /* DWORD 12 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 12\r\n");
    SPINOR_LOG_WARNING("prohibit_op_prog 0x%x\r\n", bparam->prohibit_op_prog);
    SPINOR_LOG_WARNING("prohibit_op_erase 0x%x\r\n", bparam->prohibit_op_erase);
    SPINOR_LOG_WARNING("reserved12_1 0x%x\r\n", bparam->reserved12_1);
    SPINOR_LOG_WARNING("prog_resume_suspend_interval 0x%x\r\n", bparam->prog_resume_suspend_interval);
    SPINOR_LOG_WARNING("suspend_prog_lat_count 0x%x\r\n", bparam->suspend_prog_lat_count);
    SPINOR_LOG_WARNING("suspend_prog_lat_units 0x%x\r\n", bparam->suspend_prog_lat_units);
    SPINOR_LOG_WARNING("erase_res2susp_interval 0x%x\r\n", bparam->erase_res2susp_interval);
    SPINOR_LOG_WARNING("suspend_erase_lat_count 0x%x\r\n", bparam->suspend_erase_lat_count);
    SPINOR_LOG_WARNING("suspend_erase_lat_units 0x%x\r\n", bparam->suspend_erase_lat_units);
    SPINOR_LOG_WARNING("susp_res_suppport 0x%x\r\n", bparam->susp_res_suppport);
    /* DWORD 13 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 13\r\n");
    SPINOR_LOG_WARNING("prog_resume_inst 0x%x\r\n", bparam->prog_resume_inst);
    SPINOR_LOG_WARNING("prog_suspend_inst 0x%x\r\n", bparam->prog_suspend_inst);
    SPINOR_LOG_WARNING("resume_inst 0x%x\r\n", bparam->resume_inst);
    SPINOR_LOG_WARNING("suspend_inst 0x%x\r\n", bparam->suspend_inst);
    /* DWORD 14 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 14\r\n");
    SPINOR_LOG_WARNING("reserved14_1 0x%x\r\n", bparam->reserved14_1);
    SPINOR_LOG_WARNING("status_polling 0x%x\r\n", bparam->status_polling);
    SPINOR_LOG_WARNING("exit_pwr_delay_count 0x%x\r\n", bparam->exit_pwr_delay_count);
    SPINOR_LOG_WARNING("exit_pwr_delay_units 0x%x\r\n", bparam->exit_pwr_delay_units);
    SPINOR_LOG_WARNING("exit_pwr_inst 0x%x\r\n", bparam->exit_pwr_inst);
    SPINOR_LOG_WARNING("enter_pwr_inst 0x%x\r\n", bparam->enter_pwr_inst);
    SPINOR_LOG_WARNING("deep_pwr_support 0x%x\r\n", bparam->deep_pwr_support);
    /* DWORD 15 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 15\r\n");
    SPINOR_LOG_WARNING("disable_444_seq 0x%x\r\n", bparam->disable_444_seq);
    SPINOR_LOG_WARNING("enable_444_seq 0x%x\r\n", bparam->enable_444_seq);
    SPINOR_LOG_WARNING("support_044 0x%x\r\n", bparam->support_044);
    SPINOR_LOG_WARNING("exit_044_method 0x%x\r\n", bparam->exit_044_method);
    SPINOR_LOG_WARNING("entry_044_method 0x%x\r\n", bparam->entry_044_method);
    SPINOR_LOG_WARNING("quad_en_r 0x%x\r\n", bparam->quad_en_r);
    SPINOR_LOG_WARNING("reset_disable 0x%x\r\n", bparam->reset_disable);
    SPINOR_LOG_WARNING("reserved15_1 0x%x\r\n", bparam->reserved15_1);
    /* DWORD 16 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 16\r\n");
    SPINOR_LOG_WARNING("volatile_register_1 0x%x\r\n", bparam->volatile_register_1);
    SPINOR_LOG_WARNING("reserved16_1 0x%x\r\n", bparam->reserved16_1);
    SPINOR_LOG_WARNING("srr_seq_sup 0x%x\r\n", bparam->srr_seq_sup);
    SPINOR_LOG_WARNING("exit_4b_addr 0x%x\r\n", bparam->exit_4b_addr);
    SPINOR_LOG_WARNING("enter_4b_addr 0x%x\r\n", bparam->enter_4b_addr);
    /* DWORD 17 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 17\r\n");
    SPINOR_LOG_WARNING("read_188_dummy_cycles 0x%x\r\n", bparam->read_188_dummy_cycles);
    SPINOR_LOG_WARNING("read_188_mode_clocks 0x%x\r\n", bparam->read_188_mode_clocks);
    SPINOR_LOG_WARNING("read_188_instruction 0x%x\r\n", bparam->read_188_instruction);
    SPINOR_LOG_WARNING("read_118_dummy_cycles 0x%x\r\n", bparam->read_118_dummy_cycles);
    SPINOR_LOG_WARNING("read_118_mode_clocks 0x%x\r\n", bparam->read_118_mode_clocks);
    SPINOR_LOG_WARNING("read_118_instruction 0x%x\r\n", bparam->read_118_instruction);
    /* DWORD 18 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 18\r\n");
    SPINOR_LOG_WARNING("reserved18_1 0x%x\r\n", bparam->reserved18_1);
    SPINOR_LOG_WARNING("var_output_strength 0x%x\r\n", bparam->var_output_strength);
    SPINOR_LOG_WARNING("spi_reset 0x%x\r\n", bparam->spi_reset);
    SPINOR_LOG_WARNING("dsw_str_mode 0x%x\r\n", bparam->dsw_str_mode);
    SPINOR_LOG_WARNING("ds_sup_str_mode 0x%x\r\n", bparam->ds_sup_str_mode);
    SPINOR_LOG_WARNING("ds_sup_dtr_mode 0x%x\r\n", bparam->ds_sup_dtr_mode);
    SPINOR_LOG_WARNING("reserved18_2 0x%x\r\n", bparam->reserved18_2);
    SPINOR_LOG_WARNING("octal_dtr_ext 0x%x\r\n", bparam->octal_dtr_ext);
    SPINOR_LOG_WARNING("byte_order_888_mode 0x%x\r\n", bparam->byte_order_888_mode);
    /* DWORD 19 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 19\r\n");
    SPINOR_LOG_WARNING("dis_888_seq 0x%x\r\n", bparam->dis_888_seq);
    SPINOR_LOG_WARNING("en_888_seq 0x%x\r\n", bparam->en_888_seq);
    SPINOR_LOG_WARNING("sup_088 0x%x\r\n", bparam->sup_088);
    SPINOR_LOG_WARNING("exit_088_method 0x%x\r\n", bparam->exit_088_method);
    SPINOR_LOG_WARNING("entry_088_method 0x%x\r\n", bparam->entry_088_method);
    SPINOR_LOG_WARNING("octal_en_req 0x%x\r\n", bparam->octal_en_req);
    SPINOR_LOG_WARNING("reserved19_1 0x%x\r\n", bparam->reserved19_1);
    /* DWORD 20 */
    SPINOR_LOG_WARNING("SFDP Basic paramters DWORD 20\r\n");
    SPINOR_LOG_WARNING("mhz_444s_ndt 0x%x\r\n", bparam->mhz_444s_ndt);
    SPINOR_LOG_WARNING("mhz_444s_dt 0x%x\r\n", bparam->mhz_444s_dt);
    SPINOR_LOG_WARNING("mhz_444d_ndt 0x%x\r\n", bparam->mhz_444d_ndt);
    SPINOR_LOG_WARNING("mhz_444d_dt 0x%x\r\n", bparam->mhz_444d_dt);
    SPINOR_LOG_WARNING("mhz_888s_ndt 0x%x\r\n", bparam->mhz_888s_ndt);
    SPINOR_LOG_WARNING("mhz_888s_dt 0x%x\r\n", bparam->mhz_888s_dt);
    SPINOR_LOG_WARNING("mhz_888d_ndt 0x%x\r\n", bparam->mhz_888d_ndt);
    SPINOR_LOG_WARNING("mhz_888d_dt 0x%x\r\n", bparam->mhz_888d_dt);

    /* 4-byte Address Instruction Table */
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header\r\n");
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header param_id_lsb = 0x%x\r\n", g_sfdp_data.inst4b_paramh.param_id_lsb);
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header minor_rev = 0x%x\r\n", g_sfdp_data.inst4b_paramh.minor_rev);
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header major_rev = 0x%x\r\n", g_sfdp_data.inst4b_paramh.major_rev);
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header table_length = 0x%x\r\n", g_sfdp_data.inst4b_paramh.table_length);
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header table_pointer = 0x%x\r\n", g_sfdp_data.inst4b_paramh.table_pointer);
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header param_id_msb = 0x%x\r\n", g_sfdp_data.inst4b_paramh.param_id_msb);
    SPINOR_LOG_WARNING("SFDP 4-byte instruction header end\r\n");

    /* DWORD 1 */
    SPINOR_LOG_WARNING("SFDP 4-byte instruction DWORD 1\r\n");
    SPINOR_LOG_WARNING("read_111_support 0x%x\r\n", inst4b->read_111_support);
    SPINOR_LOG_WARNING("fread_111_support 0x%x\r\n", inst4b->fread_111_support);
    SPINOR_LOG_WARNING("read_112_support 0x%x\r\n", inst4b->read_112_support);
    SPINOR_LOG_WARNING("read_122_support 0x%x\r\n", inst4b->read_122_support);
    SPINOR_LOG_WARNING("read_114_support 0x%x\r\n", inst4b->read_114_support);
    SPINOR_LOG_WARNING("read_144_support 0x%x\r\n", inst4b->read_144_support);
    SPINOR_LOG_WARNING("prog_111_support 0x%x\r\n", inst4b->prog_111_support);
    SPINOR_LOG_WARNING("prog_114_support 0x%x\r\n", inst4b->prog_114_support);
    SPINOR_LOG_WARNING("prog_144_support 0x%x\r\n", inst4b->prog_144_support);
    SPINOR_LOG_WARNING("erase_1_support 0x%x\r\n", inst4b->erase_1_support);
    SPINOR_LOG_WARNING("erase_2_support 0x%x\r\n", inst4b->erase_2_support);
    SPINOR_LOG_WARNING("erase_3_support 0x%x\r\n", inst4b->erase_3_support);
    SPINOR_LOG_WARNING("erase_4_support 0x%x\r\n", inst4b->erase_4_support);
    SPINOR_LOG_WARNING("read_dtr_111_support 0x%x\r\n", inst4b->read_dtr_111_support);
    SPINOR_LOG_WARNING("read_dtr_122_support 0x%x\r\n", inst4b->read_dtr_122_support);
    SPINOR_LOG_WARNING("read_dtr_144_support 0x%x\r\n", inst4b->read_dtr_144_support);
    SPINOR_LOG_WARNING("vol_read_lock_support 0x%x\r\n", inst4b->vol_read_lock_support);
    SPINOR_LOG_WARNING("vol_write_lock_support 0x%x\r\n", inst4b->vol_write_lock_support);
    SPINOR_LOG_WARNING("nvol_read_lock_support 0x%x\r\n", inst4b->nvol_read_lock_support);
    SPINOR_LOG_WARNING("nvol_write_lock_support 0x%x\r\n", inst4b->nvol_write_lock_support);
    SPINOR_LOG_WARNING("read_118_support 0x%x\r\n", inst4b->read_118_support);
    SPINOR_LOG_WARNING("read_188_support 0x%x\r\n", inst4b->read_188_support);
    SPINOR_LOG_WARNING("read_dtr_188_support 0x%x\r\n", inst4b->read_dtr_188_support);
    SPINOR_LOG_WARNING("prog_118_support 0x%x\r\n", inst4b->prog_118_support);
    SPINOR_LOG_WARNING("prog_188_support 0x%x\r\n", inst4b->prog_188_support);
    SPINOR_LOG_WARNING("reserved1 0x%x\r\n", inst4b->reserved1);
    /* DWORD 2, erase command, same as basic flash parameter table DWORD 8 and 9 */
    SPINOR_LOG_WARNING("SFDP 4-byte instruction DWORD 2\r\n");
    SPINOR_LOG_WARNING("erase_1_inst 0x%x\r\n", inst4b->erase_1_inst);
    SPINOR_LOG_WARNING("erase_2_inst 0x%x\r\n", inst4b->erase_2_inst);
    SPINOR_LOG_WARNING("erase_3_inst 0x%x\r\n", inst4b->erase_3_inst);
    SPINOR_LOG_WARNING("erase_4_inst 0x%x\r\n", inst4b->erase_4_inst);

    if(g_sfdp_data.profile10_size != 0)
    {
        /* xSPI profile1.0 Table */
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header\r\n");
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header param_id_lsb = 0x%x\r\n", g_sfdp_data.profile10_paramh.param_id_lsb);
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header minor_rev = 0x%x\r\n", g_sfdp_data.profile10_paramh.minor_rev);
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header major_rev = 0x%x\r\n", g_sfdp_data.profile10_paramh.major_rev);
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header table_length = 0x%x\r\n", g_sfdp_data.profile10_paramh.table_length);
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header table_pointer = 0x%x\r\n", g_sfdp_data.profile10_paramh.table_pointer);
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header param_id_msb = 0x%x\r\n", g_sfdp_data.profile10_paramh.param_id_msb);
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 header end\r\n");

        /* DWORD 1 */
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 DWORD 1\r\n");
        SPINOR_LOG_WARNING("read_fast_wrapped_cmd 0x%x\r\n", profile10->read_fast_wrapped_cmd);
        SPINOR_LOG_WARNING("read_fast_cmd 0x%x\r\n", profile10->read_fast_cmd);
        SPINOR_LOG_WARNING("reversed1 0x%x\r\n", profile10->reversed1);
        SPINOR_LOG_WARNING("num_data_bytes_used_for_write_reg_cmd 0x%x\r\n", profile10->num_data_bytes_used_for_write_reg_cmd);
        SPINOR_LOG_WARNING("num_additional_modifier_bytes_used_for_write_reg_cmd 0x%x\r\n", profile10->num_additional_modifier_bytes_used_for_write_reg_cmd);
        SPINOR_LOG_WARNING("num_additional_modifier_bytes_used_for_write_status_cfg_reg_cmd 0x%x\r\n", profile10->num_additional_modifier_bytes_used_for_write_status_cfg_reg_cmd);
        SPINOR_LOG_WARNING("initial_latency_for_read_non_volatile_reg_cmd 0x%x\r\n", profile10->initial_latency_for_read_non_volatile_reg_cmd);
        SPINOR_LOG_WARNING("initial_latency_for_read_volatile_reg_cmd 0x%x\r\n", profile10->initial_latency_for_read_volatile_reg_cmd);
        SPINOR_LOG_WARNING("num_additional_modifier_bytes_used_for_read_reg_cmd 0x%x\r\n", profile10->num_additional_modifier_bytes_used_for_read_reg_cmd);
        SPINOR_LOG_WARNING("initial_latency_for_read_status_reg_cmd 0x%x\r\n", profile10->initial_latency_for_read_status_reg_cmd);
        SPINOR_LOG_WARNING("num_additional_modifier_bytes_used_for_read_status_reg_cmd 0x%x\r\n", profile10->num_additional_modifier_bytes_used_for_read_status_reg_cmd);
        SPINOR_LOG_WARNING("sfdp_cmd_in_8d_8d_8d_mode_dummy_cycles 0x%x\r\n", profile10->sfdp_cmd_in_8d_8d_8d_mode_dummy_cycles);
        SPINOR_LOG_WARNING("sfdp_cmd_in_8d_8d_8d_mode_addr_bytes 0x%x\r\n", profile10->sfdp_cmd_in_8d_8d_8d_mode_addr_bytes);
        /* DWORD 2 */
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 DWORD 2\r\n");
        SPINOR_LOG_WARNING("write_nv_reg_cmd 0x%x\r\n", profile10->write_nv_reg_cmd);
        SPINOR_LOG_WARNING("write_volatile_reg_cmd 0x%x\r\n", profile10->write_volatile_reg_cmd);
        SPINOR_LOG_WARNING("read_nv_reg_cmd 0x%x\r\n", profile10->read_nv_reg_cmd);
        SPINOR_LOG_WARNING("read_volatile_reg_cmd 0x%x\r\n", profile10->read_volatile_reg_cmd);
        /* DWORD 3 */
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 DWORD 3\r\n");
        SPINOR_LOG_WARNING("reserved3 0x%x\r\n", profile10->reserved3);
        SPINOR_LOG_WARNING("enter_default_protocol_mode 0x%x\r\n", profile10->enter_default_protocol_mode);
        SPINOR_LOG_WARNING("soft_reset_and_enter_default_protocol_mode 0x%x\r\n", profile10->soft_reset_and_enter_default_protocol_mode);
        SPINOR_LOG_WARNING("reset_enable 0x%x\r\n", profile10->reset_enable);
        SPINOR_LOG_WARNING("soft_reset 0x%x\r\n", profile10->soft_reset);
        SPINOR_LOG_WARNING("exit_deep_power_down 0x%x\r\n", profile10->exit_deep_power_down);
        SPINOR_LOG_WARNING("enter_deep_sleep_power_down 0x%x\r\n", profile10->enter_deep_sleep_power_down);
        SPINOR_LOG_WARNING("write_nv_reg 0x%x\r\n", profile10->write_nv_reg);
        SPINOR_LOG_WARNING("write_volatile_reg 0x%x\r\n", profile10->write_volatile_reg);
        SPINOR_LOG_WARNING("write_reg 0x%x\r\n", profile10->write_reg);
        SPINOR_LOG_WARNING("clear_flag_status_reg 0x%x\r\n", profile10->clear_flag_status_reg);
        SPINOR_LOG_WARNING("write_status_cfg_reg 0x%x\r\n", profile10->write_status_cfg_reg);
        SPINOR_LOG_WARNING("read_nv_reg 0x%x\r\n", profile10->read_nv_reg);
        SPINOR_LOG_WARNING("read_volatile_reg 0x%x\r\n", profile10->read_volatile_reg);
        SPINOR_LOG_WARNING("read_reg 0x%x\r\n", profile10->read_reg);
        SPINOR_LOG_WARNING("read_flag_status_reg 0x%x\r\n", profile10->read_flag_status_reg);
        SPINOR_LOG_WARNING("read_cfg_reg 0x%x\r\n", profile10->read_cfg_reg);
        SPINOR_LOG_WARNING("erase_chip 0x%x\r\n", profile10->erase_chip);
        SPINOR_LOG_WARNING("erase_32k_bytes 0x%x\r\n", profile10->erase_32k_bytes);
        SPINOR_LOG_WARNING("erase_4k_bytes 0x%x\r\n", profile10->erase_4k_bytes);
        SPINOR_LOG_WARNING("setup_read_wrap 0x%x\r\n", profile10->setup_read_wrap);
        SPINOR_LOG_WARNING("read_fast_wrapped 0x%x\r\n", profile10->read_fast_wrapped);
        SPINOR_LOG_WARNING("read_sfdp_8d_8d_8d 0x%x\r\n", profile10->read_sfdp_8d_8d_8d);
        /* DWORD 4 */
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 DWORD 4\r\n");
        SPINOR_LOG_WARNING("reserved4 0x%x\r\n", profile10->reserved4);
        SPINOR_LOG_WARNING("cfg_bit_pattern_to_set_this_num_of_dummy_cycles_200mhz_operation 0x%x\r\n", profile10->cfg_bit_pattern_to_set_this_num_of_dummy_cycles_200mhz_operation);
        SPINOR_LOG_WARNING("num_dummy_cycles_required_200mhz_operation 0x%x\r\n", profile10->num_dummy_cycles_required_200mhz_operation);
        SPINOR_LOG_WARNING("reserved 0x%x\r\n", profile10->reserved);
        /* DWORD 5 */
        SPINOR_LOG_WARNING("SFDP xSPI profile1.0 DWORD 5\r\n");
        SPINOR_LOG_WARNING("reserved5 0x%x\r\n", profile10->reserved5);
        SPINOR_LOG_WARNING("cfg_bit_pattern_to_set_this_num_of_dummy_cycles_100mhz_operation 0x%x\r\n", profile10->cfg_bit_pattern_to_set_this_num_of_dummy_cycles_100mhz_operation);
        SPINOR_LOG_WARNING("num_dummy_cycles_required_100mhz_operation 0x%x\r\n", profile10->num_dummy_cycles_required_100mhz_operation);
        SPINOR_LOG_WARNING("cfg_bit_pattern_to_set_this_num_of_dummy_cycles_133mhz_operation 0x%x\r\n", profile10->cfg_bit_pattern_to_set_this_num_of_dummy_cycles_133mhz_operation);
        SPINOR_LOG_WARNING("num_dummy_cycles_required_133mhz_operation 0x%x\r\n", profile10->num_dummy_cycles_required_133mhz_operation);
        SPINOR_LOG_WARNING("cfg_bit_pattern_to_set_this_num_of_dummy_cycles_166mhz_operation 0x%x\r\n", profile10->cfg_bit_pattern_to_set_this_num_of_dummy_cycles_166mhz_operation);
        SPINOR_LOG_WARNING("num_dummy_cycles_required_166mhz_operation 0x%x\r\n", profile10->num_dummy_cycles_required_166mhz_operation);
    }

    if (0 != g_sfdp_data.octal_ddr_size)
    {
        /* Octal DDR table */
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header\r\n");
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header param_id_lsb = 0x%x\r\n", g_sfdp_data.octal_ddr_paramh.param_id_lsb);
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header minor_rev = 0x%x\r\n", g_sfdp_data.octal_ddr_paramh.minor_rev);
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header major_rev = 0x%x\r\n", g_sfdp_data.octal_ddr_paramh.major_rev);
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header table_length = 0x%x\r\n", g_sfdp_data.octal_ddr_paramh.table_length);
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header table_pointer = 0x%x\r\n", g_sfdp_data.octal_ddr_paramh.table_pointer);
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header param_id_msb = 0x%x\r\n", g_sfdp_data.octal_ddr_paramh.param_id_msb);
        SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D sequence Table header end\r\n");

        /* Octal DDR Command Sequences */
        for(int i = 0; i < (sizeof(g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq)/sizeof(g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[0])); i++)
        {
            SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D command sequence DWORD %d\r\n",i*2+1);
            SPINOR_LOG_WARNING("Byte 3 of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_3);
            SPINOR_LOG_WARNING("Byte 2 of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_2);
            SPINOR_LOG_WARNING("Byte 1 of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_1);
            SPINOR_LOG_WARNING("Length of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_len);
            SPINOR_LOG_WARNING("SFDP Octal DDR 8D-8D-8D command sequence DWORD %d\r\n",i*2+2);
            SPINOR_LOG_WARNING("Byte 7 of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_7);
            SPINOR_LOG_WARNING("Byte 6 of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_6);
            SPINOR_LOG_WARNING("Byte 5 of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_5);
            SPINOR_LOG_WARNING("Byte 4 of command sequence %d = 0x%x\r\n",i+1, g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_4);
        }


    }

    if (0 != g_sfdp_data.sector_map_size)
    {
        /* Sector Map table */
        SPINOR_LOG_WARNING("SFDP Sector Map Table header\r\n");
        SPINOR_LOG_WARNING("SFDP Sector Map Table header param_id_lsb = 0x%x\r\n", g_sfdp_data.sector_map_paramh.param_id_lsb);
        SPINOR_LOG_WARNING("SFDP Sector Map Table header minor_rev = 0x%x\r\n", g_sfdp_data.sector_map_paramh.minor_rev);
        SPINOR_LOG_WARNING("SFDP Sector Map Table header major_rev = 0x%x\r\n", g_sfdp_data.sector_map_paramh.major_rev);
        SPINOR_LOG_WARNING("SFDP Sector Map Table header table_length = 0x%x\r\n", g_sfdp_data.sector_map_paramh.table_length);
        SPINOR_LOG_WARNING("SFDP Sector Map Table header table_pointer = 0x%x\r\n", g_sfdp_data.sector_map_paramh.table_pointer);
        SPINOR_LOG_WARNING("SFDP Sector Map Table header param_id_msb = 0x%x\r\n", g_sfdp_data.sector_map_paramh.param_id_msb);
        SPINOR_LOG_WARNING("SFDP Sector Map Table header end\r\n");


        /* Sector Map Config Detect Sequences */
        for(int i = 0; i < (sizeof(g_sfdp_data.config_info)/sizeof(g_sfdp_data.config_info[0])); i++)
        {
            SPINOR_LOG_WARNING("JEDEC Sector Map Parameter Config. Detect-%d\r\n", i+1);
            SPINOR_LOG_WARNING("JEDEC Sector Map Parameter Config. Detect DWORD %d\r\n",i*2+1);
            SPINOR_LOG_WARNING("desc_end_indicator = 0x%x\r\n", g_sfdp_data.config_info[i].desc_end_indicator);
            SPINOR_LOG_WARNING("desc_type = 0x%x\r\n", g_sfdp_data.config_info[i].desc_type);
            SPINOR_LOG_WARNING("reserved1 = 0x%x\r\n", g_sfdp_data.config_info[i].reserved1);
            SPINOR_LOG_WARNING("detection_cmd_inst = 0x%x\r\n", g_sfdp_data.config_info[i].detection_cmd_inst);
            SPINOR_LOG_WARNING("config_detect_cmd_rd_latency = 0x%x\r\n", g_sfdp_data.config_info[i].config_detect_cmd_rd_latency);
            SPINOR_LOG_WARNING("reserved = 0x%x\r\n", g_sfdp_data.config_info[i].reserved);
            SPINOR_LOG_WARNING("config_detect_cmd_addr_len = 0x%x\r\n", g_sfdp_data.config_info[i].config_detect_cmd_addr_len);
            SPINOR_LOG_WARNING("read_data_mask = 0x%x\r\n", g_sfdp_data.config_info[i].read_data_mask);

            SPINOR_LOG_WARNING("JEDEC Sector Map Parameter Config. Detect DWORD %d\r\n",i*2+2);
            SPINOR_LOG_WARNING("map_config_detect_cmd_addr = 0x%x\r\n", g_sfdp_data.config_info[i].map_config_detect_cmd_addr);
        }


        /* Sector Map Config Header and region */
        SPINOR_LOG_WARNING("Only dumping the the valid config for configID 2 for split 4KB regions or the last read SFDP Sector Map Config Header\r\n");

        /* Sector Map Config Header DWORDS */
        SPINOR_LOG_WARNING("SFDP Sector Map Parameter Config Header\r\n");
        SPINOR_LOG_WARNING("JEDEC Sector Map Parameter Config Header DWORD 1\r\n");
        SPINOR_LOG_WARNING("desc_end_indicator = 0x%x\r\n", g_sfdp_data.config_header_data.desc_end_indicator);
        SPINOR_LOG_WARNING("desc_type = 0x%x\r\n", g_sfdp_data.config_header_data.desc_type);
        SPINOR_LOG_WARNING("reserved1 = 0x%x\r\n", g_sfdp_data.config_header_data.reserved1);
        SPINOR_LOG_WARNING("config_ID = 0x%x\r\n", g_sfdp_data.config_header_data.config_ID);
        SPINOR_LOG_WARNING("region_count = 0x%x\r\n", g_sfdp_data.config_header_data.region_count);
        SPINOR_LOG_WARNING("reserved = 0x%x\r\n", g_sfdp_data.config_header_data.reserved);


        /* Sector Map Config Region DWORDS */
        for(int i = 0; i < (sizeof(g_sfdp_data.config_region_data)/sizeof(g_sfdp_data.config_region_data[0])); i++)
        {
            SPINOR_LOG_WARNING("JEDEC Sector Map Parameter Config.Region-%d\r\n", i);
            SPINOR_LOG_WARNING("erase_1_support = 0x%x\r\n", g_sfdp_data.config_region_data[i].erase_1_support);
            SPINOR_LOG_WARNING("erase_2_support = 0x%x\r\n", g_sfdp_data.config_region_data[i].erase_2_support);
            SPINOR_LOG_WARNING("erase_3_support = 0x%x\r\n", g_sfdp_data.config_region_data[i].erase_3_support);
            SPINOR_LOG_WARNING("erase_4_support = 0x%x\r\n", g_sfdp_data.config_region_data[i].erase_4_support);
            SPINOR_LOG_WARNING("reserved = 0x%x\r\n", g_sfdp_data.config_region_data[i].reserved);
            SPINOR_LOG_WARNING("region_size = 0x%x\r\n", g_sfdp_data.config_region_data[i].region_size);
        }
    }

  } while (FALSE);
#endif /*(defined(NORPVL_ENB) || defined(SPINOR_SFDP_DUMP_ENABLED))*/
  return status;
}

uint32_t spinor_pvl_get_device_id(void)
{
	return (p_spinor_dev) ? p_spinor_dev->config_data->device_id : 0;
}
