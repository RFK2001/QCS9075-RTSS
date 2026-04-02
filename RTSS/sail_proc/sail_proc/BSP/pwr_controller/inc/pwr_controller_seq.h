#ifndef __PWR_CONTROLLER_SEQ_H__
#define __PWR_CONTROLLER_SEQ_H__

/*
===========================================================================
*/
/**
    @file  pwr_controller_seq.h
    @brief This file provides Power Controller Sequence.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/inc/pwr_controller_seq.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"

/* Uncomment this using for RUMI testing or using any other sequence not official */
//#define PC_RUMI_TESTING

#ifdef PC_RUMI_TESTING
#define SAIL_PC_NO_MD 1
#define SAIL_PC_NO_CC 1
#define SAIL_PC_NO_APM 1
#define SAIL_PC_NO_PMIC 1
#endif /* PC_RUMI_TESTING */

#define PWR_CTRL_SEQ_MEM_BASE 0xF1004000

static uint32 pwr_ctl_seq_mem_cmds[] = {

#ifndef PC_RUMI_TESTING
  // Sequence Memory Commands
  0x7001501d,   // 0x000 : 0x501D       DOWN_SEQUENCE:      SET1        sleep_entry
                // 0x002 : 0x7001                           WAIT1       aggr_wfi
  0x50025000,   // 0x004 : 0x5000                           SET1        pch_low_pwr_entry_trg
                // 0x006 : 0x5002                           SET1        qch_low_pwr_entry_trg
  0x40007002,   // 0x008 : 0x7002                           WAIT1       aggr_pch_low_pwr_rdy
                // 0x00A : 0x4000                           SET0        pch_low_pwr_entry_trg
  0x40027003,   // 0x00C : 0x7003                           WAIT1       aggr_qch_low_pwr_rdy
                // 0x00E : 0x4002                           SET0        qch_low_pwr_entry_trg
  0x70055007,   // 0x010 : 0x5007                           SET1        func_clk_disable
                // 0x012 : 0x7005                           WAIT1       all_clk_off
  0x70065008,   // 0x014 : 0x5008                           SET1        mem_pwr_down
                // 0x016 : 0x7006                           WAIT1       mem_pwr_down_done
  0x380c5025,   // 0x018 : 0x5025                           SET1        cxo_pad_disable
                // 0x01A : 0x380C                                       BEQR        low_power_mode=1        RET_ENABLE
  0x1c001c01,   // 0x01C : 0x1C01                           CALL        INTER_ISO_ASSERT
                // 0x01E : 0x1C00                           CALL        MD_SLEEP_EN_HSK
  0x38443802,   // 0x020 : 0x3802                                       BEQR        low_power_mode=1        APM_SWITCH_DOWN
                // 0x022 : 0x3844                                       BEQR        sail_pmic_wakeup=1      SAIL_PMIC_WKUP
  0x38c63885,   // 0x024 : 0x3885                                       BEQR        sail_wake_up=1          SAIL_WKUP
                // 0x026 : 0x38C6                                       BEQR        md_wake_up=1            MD_WKUP
  0x0002501b,   // 0x028 : 0x501B       UP_SEQUENCE:        SET1        sail_to_md_wakeup_irq
                // 0x02A : 0x0002                           DELI        104ns
  0x5001401b,   // 0x02C : 0x401B                           SET0        sail_to_md_wakeup_irq
                // 0x02E : 0x5001                           SET1        pch_low_pwr_exit_trg
  0x38085003,   // 0x030 : 0x5003                           SET1        qch_low_pwr_exit_trg
                // 0x032 : 0x3808                                       BEQR        low_power_mode=1        APM_SWITCH_UP
  0x1c0b3009,   // 0x034 : 0x3009                                       BEQR        low_power_mode=0        STDBY_RST
                // 0x036 : 0x1C0B                           CALL        ISO_DEASSERT
  0x40251c0a,   // 0x038 : 0x1C0A                           CALL        MD_PWR_READY_HSK
                // 0x03A : 0x4025                           SET0        cxo_pad_disable
  0x60064008,   // 0x03C : 0x4008                           SET0        mem_pwr_down
                // 0x03E : 0x6006                           WAIT0       mem_pwr_down_done
  0x60054007,   // 0x040 : 0x4007                           SET0        func_clk_disable
                // 0x042 : 0x6005                           WAIT0       all_clk_off
  0x40016002,   // 0x044 : 0x6002                           WAIT0       aggr_pch_low_pwr_rdy
                // 0x046 : 0x4001                           SET0        pch_low_pwr_exit_trg
  0x40036003,   // 0x048 : 0x6003                           WAIT0       aggr_qch_low_pwr_rdy
                // 0x04A : 0x4003                           SET0        qch_low_pwr_exit_trg
  0x10004026,   // 0x04C : 0x4026                           SET0        sleep_exit
                // 0x04E : 0x1000                           RETURN
  0x500f501e,   // 0x050 : 0x501E       INTER_ISO_ASSERT:   SET1        iso_in_progress
                // 0x052 : 0x500F                           SET1        sail_cx_iso_input
  0x50105009,   // 0x054 : 0x5009                           SET1        sail_cx_clamp_mem
                // 0x056 : 0x5010                           SET1        sail_cx_iso_output
  0x500e500d,   // 0x058 : 0x500D                           SET1        freeze_io_early
                // 0x05A : 0x500E                           SET1        freeze_io
  0x1000401e,   // 0x05C : 0x401E                           SET0        iso_in_progress
                // 0x05E : 0x1000                           RETURN
  0x50117007,   // 0x060 : 0x7007       MD_SLEEP_EN_HSK:    WAIT1       md_to_sail_sleep_en_req
                // 0x062 : 0x5011                           SET1        sail_from_md_cx_iso_en
  0x50120004,   // 0x064 : 0x0004                           DELI        520ns
                // 0x066 : 0x5012                           SET1        md_to_sail_sleen_en_ack
  0x40126007,   // 0x068 : 0x6007                           WAIT0       md_to_sail_sleep_en_req
                // 0x06A : 0x4012                           SET0        md_to_sail_sleen_en_ack
  0x501f1000,   // 0x06C : 0x1000                           RETURN
                // 0x06E : 0x501F       APM_SWITCH_DOWN:    SET1        apm_dwn_in_progress
  0x50157008,   // 0x070 : 0x7008                           WAIT1       md_to_sail_apm_change_req
                // 0x072 : 0x5015                           SET1        apm_clk_enable
  0x50160002,   // 0x074 : 0x0002                           DELI        104ns
                // 0x076 : 0x5016                           SET1        out2apm_aon_use_aux_seq
  0x50184017,   // 0x078 : 0x4017                           SET0        out2apm_tile_act_br_seq_0
                // 0x07A : 0x5018                           SET1        out2apm_tile_act_br_seq_1
  0x401f1c03,   // 0x07C : 0x1C03                           CALL        APM_CHANGE
                // 0x07E : 0x401F                           SET0        apm_dwn_in_progress
  0x00031000,   // 0x080 : 0x1000                           RETURN
                // 0x082 : 0x0003       APM_CHANGE:         DELI        208ns
  0x40195019,   // 0x084 : 0x5019                           SET1        out2apm_start_apm_switch_seq
                // 0x086 : 0x4019                           SET0        out2apm_start_apm_switch_seq
  0x4015700c,   // 0x088 : 0x700C                           WAIT1       apm2out_tile_trans_done
                // 0x08A : 0x4015                           SET0        apm_clk_enable
  0x50130002,   // 0x08C : 0x0002                           DELI        104ns
                // 0x08E : 0x5013                           SET1        md_to_sail_apm_change_ack
  0x40136008,   // 0x090 : 0x6008                           WAIT0       md_to_sail_apm_change_req
                // 0x092 : 0x4013                           SET0        md_to_sail_apm_change_ack
  0x501a1000,   // 0x094 : 0x1000                           RETURN
                // 0x096 : 0x501A       SAIL_PMIC_WKUP:     SET1        sail_sleep_en
  0x401d600b,   // 0x098 : 0x600B                           WAIT0       sail_pwr_rdy
                // 0x09A : 0x401D                           SET0        sleep_entry
  0x700a501c,   // 0x09C : 0x501C                           SET1        seq_wdog_disable
                // 0x09E : 0x700A                           WAIT1       aggr_wake_irq
  0x5026401c,   // 0x0A0 : 0x401C                           SET0        seq_wdog_disable
                // 0x0A2 : 0x5026                           SET1        sleep_exit
  0x1000401a,   // 0x0A4 : 0x401A                           SET0        sail_sleep_en
                // 0x0A6 : 0x1000                           RETURN
  0x40117009,   // 0x0A8 : 0x7009       MD_PWR_READY_HSK:   WAIT1       md_to_sail_pwr_rdy_req
                // 0x0AA : 0x4011                           SET0        sail_from_md_cx_iso_en
  0x50140004,   // 0x0AC : 0x0004                           DELI        520ns
                // 0x0AE : 0x5014                           SET1        md_to_sail_pwr_rdy_ack
  0x40146009,   // 0x0B0 : 0x6009                           WAIT0       md_to_sail_pwr_rdy_req
                // 0x0B2 : 0x4014                           SET0        md_to_sail_pwr_rdy_ack
  0x501a1000,   // 0x0B4 : 0x1000                           RETURN
                // 0x0B6 : 0x501A       SAIL_WKUP:          SET1        sail_sleep_en
  0x401d600b,   // 0x0B8 : 0x600B                           WAIT0       sail_pwr_rdy
                // 0x0BA : 0x401D                           SET0        sleep_entry
  0x700a501c,   // 0x0BC : 0x501C                           SET1        seq_wdog_disable
                // 0x0BE : 0x700A                           WAIT1       aggr_wake_irq
  0x5026401c,   // 0x0C0 : 0x401C                           SET0        seq_wdog_disable
                // 0x0C2 : 0x5026                           SET1        sleep_exit
  0x700b401a,   // 0x0C4 : 0x401A                           SET0        sail_sleep_en
                // 0x0C6 : 0x700B                           WAIT1       sail_pwr_rdy
  0x50201000,   // 0x0C8 : 0x1000                           RETURN
                // 0x0CA : 0x5020       APM_SWITCH_UP:      SET1        apm_up_in_progress
  0x70085005,   // 0x0CC : 0x5005                           SET1        low_pwr_func_ares
                // 0x0CE : 0x7008                           WAIT1       md_to_sail_apm_change_req
  0x00025015,   // 0x0D0 : 0x5015                           SET1        apm_clk_enable
                // 0x0D2 : 0x0002                           DELI        104ns
  0x50174016,   // 0x0D4 : 0x4016                           SET0        out2apm_aon_use_aux_seq
                // 0x0D6 : 0x5017                           SET1        out2apm_tile_act_br_seq_0
  0x1c034018,   // 0x0D8 : 0x4018                           SET0        out2apm_tile_act_br_seq_1
                // 0x0DA : 0x1C03                           CALL        APM_CHANGE
  0x40050002,   // 0x0DC : 0x0002                           DELI        104ns
                // 0x0DE : 0x4005                           SET0        low_pwr_func_ares
  0x400a0004,   // 0x0E0 : 0x0004                           DELI        520ns
                // 0x0E2 : 0x400A                           SET0        retain_ff
  0x0002500c,   // 0x0E4 : 0x500C                           SET1        restore_ff
                // 0x0E6 : 0x0002                           DELI        104ns
  0x4020400c,   // 0x0E8 : 0x400C                           SET0        restore_ff
                // 0x0EA : 0x4020                           SET0        apm_up_in_progress
  0x50041000,   // 0x0EC : 0x1000                           RETURN
                // 0x0EE : 0x5004       STDBY_RST:          SET1        standby_core_ares
  0x40040004,   // 0x0F0 : 0x0004                           DELI        520ns
                // 0x0F2 : 0x4004                           SET0        standby_core_ares
  0x50211000,   // 0x0F4 : 0x1000                           RETURN
                // 0x0F6 : 0x5021       ISO_DEASSERT:       SET1        de_iso_in_progress
  0x400d4009,   // 0x0F8 : 0x4009                           SET0        sail_cx_clamp_mem
                // 0x0FA : 0x400D                           SET0        freeze_io_early
  0x400e4010,   // 0x0FC : 0x4010                           SET0        sail_cx_iso_output
                // 0x0FE : 0x400E                           SET0        freeze_io
  0x4021400f,   // 0x100 : 0x400F                           SET0        sail_cx_iso_input
                // 0x102 : 0x4021                           SET0        de_iso_in_progress
  0x401d1000,   // 0x104 : 0x1000                           RETURN
                // 0x106 : 0x401D       MD_WKUP:            SET0        sleep_entry
  0x700a501c,   // 0x108 : 0x501C                           SET1        seq_wdog_disable
                // 0x10A : 0x700A                           WAIT1       aggr_wake_irq
  0x5026401c,   // 0x10C : 0x401C                           SET0        seq_wdog_disable
                // 0x10E : 0x5026                           SET1        sleep_exit
  0x500a1000,   // 0x110 : 0x1000                           RETURN
                // 0x112 : 0x500A       RET_ENABLE:         SET1        retain_ff
  0x0002500b,   // 0x114 : 0x500B                           SET1        save_ff
                // 0x116 : 0x0002                           DELI        104ns
  0x1000400b,   // 0x118 : 0x400B                           SET0        save_ff
                // 0x11A : 0x1000                           RETURN
#else

  // Sequence Memory Commands

                     // 0x501D      DOWN_SEQUENCE:      SET1        sleep_entry
                     // 0x7001                          WAIT1       aggr_wfi
  0x7001501d,
                    // 0x5000                           SET1        pch_low_pwr_entry_trg
                    // 0x5002                           SET1        qch_low_pwr_entry_trg
  0x50025000,
                     // 0x7002                          WAIT1       aggr_pch_low_pwr_rdy
                     // 0x4000                          SET0        pch_low_pwr_entry_trg
  0x40007002,
                     // 0x7003                          WAIT1       aggr_qch_low_pwr_rdy
                     // 0x4002                          SET0        qch_low_pwr_entry_trg
  0x40027003,
                     // 0x5007                          SET1        func_clk_disable
                     // 0x7005                          WAIT1       all_clk_off
  SAIL_PC_NO_CC ? 0x00055007 : 0x70055007,
                     // 0x5008                          SET1        mem_pwr_down
                     // 0x7006                          WAIT1       mem_pwr_down_done
  0x70065008,
                     // 0x5025                          SET1        cxo_pad_disable
                     // 0x380C                                      BEQR        low_power_mode=1        RET_ENABLE
  0x380c5025,
                     // 0x1C01                          CALL        INTER_ISO_ASSERT
                     // 0x1C00                          CALL        MD_SLEEP_EN_HSK
  0x1c001c01,
                     // 0x3802                                      BEQR        low_power_mode=1        APM_SWITCH_DOWN
                     // 0x3844                                      BEQR        sail_pmic_wakeup=1      SAIL_PMIC_WKUP
  0x38443802,
                     // 0x3885                                      BEQR        sail_wake_up=1          SAIL_WKUP
                     // 0x38C6                                      BEQR        md_wake_up=1            MD_WKUP
  0x38c63885,
                     // 0x501B      UP_SEQUENCE:        SET1        sail_to_md_wakeup_irq
                     // 0x0002                          DELI        104ns
  0x0002501b,
                     // 0x401B                          SET0        sail_to_md_wakeup_irq
                     // 0x5001                          SET1        pch_low_pwr_exit_trg
  0x5001401b,
                     // 0x5003                          SET1        qch_low_pwr_exit_trg
                     // 0x3808                                      BEQR        low_power_mode=1        APM_SWITCH_UP
  0x38085003,
                     // 0x3009                                      BEQR        low_power_mode=0        STDBY_RST
                     // 0x1C0B                          CALL        ISO_DEASSERT
  0x1c0b3009,
                     // 0x1C0A                          CALL        MD_PWR_READY_HSK
                     // 0x4025                          SET0        cxo_pad_disable
  0x40251c0a,
                     // 0x4008                          SET0        mem_pwr_down
                     // 0x6006                          WAIT0       mem_pwr_down_done
  0x60064008,
                       // 0x4007                        SET0        func_clk_disable
                       // 0x6005                        WAIT0       all_clk_off
  SAIL_PC_NO_CC ? 0x00054007 : 0x60054007,
                     // 0x6002                          WAIT0       aggr_pch_low_pwr_rdy
                     // 0x4001                          SET0        pch_low_pwr_exit_trg
  0x40016002,
                     // 0x6003                          WAIT0       aggr_qch_low_pwr_rdy
                     // 0x4003                          SET0        qch_low_pwr_exit_trg
  0x40036003,
                     // 0x4026                          SET0        sleep_exit
                     // 0x1000                          RETURN
  0x10004026,
                     // 0x501E      INTER_ISO_ASSERT:   SET1        iso_in_progress
                     // 0x500F                          SET1        sail_cx_iso_input
  0x500f501e,
                     // 0x5009                          SET1        sail_cx_clamp_mem
                     // 0x5010                          SET1        sail_cx_iso_output
  0x50105009,
                     // 0x500D                          SET1        freeze_io_early
                     // 0x500E                          SET1        freeze_io
  0x500e500d,
                     // 0x401E                          SET0        iso_in_progress
                     // 0x1000                          RETURN
  0x1000401e,
                     // 0x7007      MD_SLEEP_EN_HSK:    WAIT1       md_to_sail_sleep_en_req
                     // 0x5011                          SET1        sail_from_md_cx_iso_en
  SAIL_PC_NO_MD ? 0x50110005 : 0x50117007,
                     // 0x0004                          DELI        520ns
                     // 0x5012                          SET1        md_to_sail_sleen_en_ack
  0x50120004,
                     // 0x6007                          WAIT0       md_to_sail_sleep_en_req
                     // 0x4012                          SET0        md_to_sail_sleen_en_ack
  SAIL_PC_NO_MD ? 0x40120005 : 0x40126007,
                     // 0x1000                          RETURN
                     // 0x501F      APM_SWITCH_DOWN:    SET1        apm_dwn_in_progress
  0x501f1000,
                     // 0x7008                          WAIT1       md_to_sail_apm_change_req
                     // 0x5015                          SET1        apm_clk_enable
  SAIL_PC_NO_MD ? 0x50150005 : 0x50157008,
                     // 0x0002                          DELI        104ns
                     // 0x5016                          SET1        out2apm_aon_use_aux_seq
  0x50160002,
                     // 0x4017                          SET0        out2apm_tile_act_br_seq_0
                     // 0x5018                          SET1        out2apm_tile_act_br_seq_1
  0x50184017,
                     // 0x1C03                          CALL        APM_CHANGE
                     // 0x401F                          SET0        apm_dwn_in_progress
  0x401f1c03,
                     // 0x1000                          RETURN
                     // 0x0003      APM_CHANGE:         DELI        208ns
  0x00031000,
                     // 0x5019                          SET1        out2apm_start_apm_switch_seq
                     // 0x4019                          SET0        out2apm_start_apm_switch_seq
  0x40195019,
                     // 0x700C                          WAIT1       apm2out_tile_trans_done
                     // 0x4015                          SET0        apm_clk_enable
  SAIL_PC_NO_APM ? 0x40150005 : 0x4015700c,
                     // 0x0002                          DELI        104ns
                     // 0x5013                          SET1        md_to_sail_apm_change_ack
  0x50130002,
                     // 0x6008                          WAIT0       md_to_sail_apm_change_req
                     // 0x4013                          SET0        md_to_sail_apm_change_ack
  SAIL_PC_NO_MD ? 0x40130005 : 0x40136008,
                    // 0x1000                           RETURN
                    // 0x501A       SAIL_PMIC_WKUP:     SET1        sail_sleep_en
  0x501a1000,
                    // 0x600B                           WAIT0       sail_pwr_rdy
                    // 0x401D                           SET0        sleep_entry
  SAIL_PC_NO_PMIC ? 0x401d0005 : 0x401d600b,
                    // 0x501C                           SET1        seq_wdog_disable
                    // 0x700A                           WAIT1       aggr_wake_irq
  0x700a501c,
                    // 0x401C                           SET0        seq_wdog_disable
                    // 0x5026                           SET1        sleep_exit
  0x5026401c,
                    // 0x401A                           SET0        sail_sleep_en
                    // 0x1000                           RETURN
  0x1000401a,
                    // 0x7009       MD_PWR_READY_HSK:   WAIT1       md_to_sail_pwr_rdy_req
                    // 0x4011                           SET0        sail_from_md_cx_iso_en
  SAIL_PC_NO_MD ? 0x40110005 : 0x40117009,
                    // 0x0004                           DELI        520ns
                    // 0x5014                           SET1        md_to_sail_pwr_rdy_ack
  0x50140004,
                    // 0x6009                           WAIT0       md_to_sail_pwr_rdy_req
                    // 0x4014                           SET0        md_to_sail_pwr_rdy_ack
  SAIL_PC_NO_MD ? 0x40140005 : 0x40146009,
                    // 0x1000                           RETURN
                    // 0x501A       SAIL_WKUP:          SET1        sail_sleep_en
  0x501a1000,
                    // 0x600B                           WAIT0       sail_pwr_rdy
                    // 0x401D                           SET0        sleep_entry
  SAIL_PC_NO_PMIC ? 0x401d0005 : 0x401d600b,
                    // 0x501C                           SET1        seq_wdog_disable
                    // 0x700A                           WAIT1       aggr_wake_irq
  0x700a501c,
                    // 0x401C                           SET0        seq_wdog_disable
                    // 0x5026                           SET1        sleep_exit
  0x5026401c,
                    // 0x401A                           SET0        sail_sleep_en
                    // 0x700B                           WAIT1       sail_pwr_rdy
  SAIL_PC_NO_PMIC ? 0x0005401a : 0x700b401a,
                    // 0x1000                           RETURN
                    // 0x5020       APM_SWITCH_UP:      SET1        apm_up_in_progress
  0x50201000,
                    // 0x5005                           SET1        low_pwr_func_ares
                    // 0x7008                           WAIT1       md_to_sail_apm_change_req
  SAIL_PC_NO_MD ? 0x00055005 : 0x70085005,
                    // 0x5015                           SET1        apm_clk_enable
                    // 0x0002                           DELI        104ns
  0x00025015,
                    // 0x4016                           SET0        out2apm_aon_use_aux_seq
                    // 0x5017                           SET1        out2apm_tile_act_br_seq_0
  0x50174016,
                    // 0x4018                           SET0        out2apm_tile_act_br_seq_1
                    // 0x1C03                           CALL        APM_CHANGE
  0x1c034018,
                    // 0x0002                           DELI        104ns
                    // 0x4005                           SET0        low_pwr_func_ares
  0x40050002,
                    // 0x0004                           DELI        520ns
                    // 0x400A                           SET0        retain_ff
  0x400a0004,
                    // 0x500C                           SET1        restore_ff
                    // 0x0002                           DELI        104ns
  0x0002500c,
                    // 0x400C                           SET0        restore_ff
                    // 0x4020                           SET0        apm_up_in_progress
  0x4020400c,
                    // 0x1000                           RETURN
                    // 0x5004       STDBY_RST:          SET1        standby_core_ares
  0x50041000,
                    // 0x0004                           DELI        520ns
                    // 0x4004                           SET0        standby_core_ares
  0x40040004,
                    // 0x1000                           RETURN
                    // 0x5021       ISO_DEASSERT:       SET1        de_iso_in_progress
  0x50211000,
                    // 0x4009                           SET0        sail_cx_clamp_mem
                    // 0x400D                           SET0        freeze_io_early
  0x400d4009,
                    // 0x4010                           SET0        sail_cx_iso_output
                    // 0x400E                           SET0        freeze_io
  0x400e4010,
                    // 0x400F                           SET0        sail_cx_iso_input
                    // 0x4021                           SET0        de_iso_in_progress
  0x4021400f,
                    // 0x1000                           RETURN
                    // 0x401D       MD_WKUP:            SET0        sleep_entry
  0x401d1000,
                    // 0x501C                           SET1        seq_wdog_disable
                    // 0x700A                           WAIT1       aggr_wake_irq
  0x700a501c,
                    // 0x401C                           SET0        seq_wdog_disable
                    // 0x5026                           SET1        sleep_exit
  0x5026401c,
                    // 0x1000                           RETURN
                    // 0x500A       RET_ENABLE:         SET1        retain_ff
  0x500a1000,
                    // 0x500B                           SET1        save_ff
                    // 0x0002                           DELI        104ns
  0x0002500b,
                    // 0x400B                           SET0        save_ff
                    // 0x1000                           RETURN
  0x1000400b,
#endif /* PC_RUMI_TESTING */
};

static uint32 pwr_ctl_br_addr[] = {
#ifndef PC_RUMI_TESTING
  // Branch Addresses
  // Branch addr: 0x0
  0x60 ,  // MD_SLEEP_EN_HSK = 96 + BRANCH_ADDR: 0x0  BRANCH_REG: 0
  0x50 ,  // INTER_ISO_ASSERT = 80 + BRANCH_ADDR: 0x0  BRANCH_REG: 1
  0x6e ,  // APM_SWITCH_DOWN = 110 + BRANCH_ADDR: 0x0  BRANCH_REG: 2
  0x82 ,  // APM_CHANGE = 130 + BRANCH_ADDR: 0x0  BRANCH_REG: 3
  0x96 ,  // SAIL_PMIC_WKUP = 150 + BRANCH_ADDR: 0x0  BRANCH_REG: 4
  0xb6 ,  // SAIL_WKUP = 182 + BRANCH_ADDR: 0x0  BRANCH_REG: 5
  0x106 , // MD_WKUP = 262 + BRANCH_ADDR: 0x0  BRANCH_REG: 6
  0x28 ,  // UP_SEQUENCE = 40 + BRANCH_ADDR: 0x0  BRANCH_REG: 7
  0xca ,  // APM_SWITCH_UP = 202 + BRANCH_ADDR: 0x0  BRANCH_REG: 8
  0xee ,  // STDBY_RST = 238 + BRANCH_ADDR: 0x0  BRANCH_REG: 9
  0xa8 ,  // MD_PWR_READY_HSK = 168 + BRANCH_ADDR: 0x0  BRANCH_REG: 10
  0xf6 ,  // ISO_DEASSERT = 246 + BRANCH_ADDR: 0x0  BRANCH_REG: 11
  0x112,  // RET_ENABLE = 274 + BRANCH_ADDR: 0x0  BRANCH_REG: 12
#else
  // Branch Addresses
  // Branch addr: 0x0
  0x60 ,  // MD_SLEEP_EN_HSK = 96 + BRANCH_ADDR: 0x0  BRANCH_REG: 0
  0x50 ,  // INTER_ISO_ASSERT = 80 + BRANCH_ADDR: 0x0  BRANCH_REG: 1
  0x6e ,  // APM_SWITCH_DOWN = 110 + BRANCH_ADDR: 0x0  BRANCH_REG: 2
  0x82 ,  // APM_CHANGE = 130 + BRANCH_ADDR: 0x0  BRANCH_REG: 3
  0x96 ,  // SAIL_PMIC_WKUP = 150 + BRANCH_ADDR: 0x0  BRANCH_REG: 4
  0xb6 ,  // SAIL_WKUP = 182 + BRANCH_ADDR: 0x0  BRANCH_REG: 5
  0x106 , // MD_WKUP = 262 + BRANCH_ADDR: 0x0  BRANCH_REG: 6
  0x28 ,  // UP_SEQUENCE = 40 + BRANCH_ADDR: 0x0  BRANCH_REG: 7
  0xca ,  // APM_SWITCH_UP = 202 + BRANCH_ADDR: 0x0  BRANCH_REG: 8
  0xee ,  // STDBY_RST = 238 + BRANCH_ADDR: 0x0  BRANCH_REG: 9
  0xa8 ,  // MD_PWR_READY_HSK = 168 + BRANCH_ADDR: 0x0  BRANCH_REG: 10
  0xf6 ,  // ISO_DEASSERT = 246 + BRANCH_ADDR: 0x0  BRANCH_REG: 11
  0x112,  // RET_ENABLE = 274 + BRANCH_ADDR: 0x0  BRANCH_REG: 12
#endif /* PC_RUMI_TESTING */
};

static uint32 crash_wkup_seq_mem_cmds[] = {

#ifndef PC_RUMI_TESTING
  // Sequence Memory Commands
  0x501c2007,   //0x000: 0x2007      CRASH_WAKEUP_SEQ: BEQ         pwr_seq_busy=0          CRASH_SEQ_COMPLETE
                //0x002: 0x501C                        SET1        seq_wdog_disable
  0x5027501d,   //0x004: 0x501D                        SET1        sleep_entry_disable
                //0x006: 0x5027                        SET1        sleep_exit 
  0x28482906,   //0x008: 0x2906                        BEQ         de_iso_in_progress=1    ISO_DEASSERT
                //0x00A: 0x2848                        BEQ         iso_in_progress=1       ISO_IN_PROGRESS
  0x288328c3,   //0x00c: 0x28C3                        BEQ         apm_up_in_progress=1    APM_SWITCH_UP
                //0x00E: 0x2883                        BEQ         apm_dwn_in_progress=1   APM_SWITCH_UP
  0x29c12980,   //0x010: 0x2980                        BEQ         sail_pmic_wakeup=1      SAIL_PMIC_WKUP
                //0x012: 0x29C1                        BEQ         sail_wake_up=1          SAIL_WKUP
  0x10002a02,   //0x014: 0x2A02                        BEQ         md_wake_up=1            MD_WKUP
                //0x016: 0x1000                        RETURN
  0x21452944,   //0x018: 0x2944      ISO_IN_PROGRESS:  BEQ         low_power_mode=1        RET_DISABLE
                //0x01A: 0x2145                        BEQ         low_power_mode=0        STDBY_RST
  0x501a700b,   //0x01c: 0x700B      SAIL_PMIC_WKUP:   WAIT1       sail_pwr_rdy
                //0x01E: 0x501A                        SET1        sail_sleep_en_disable
  0x21452943,   //0x020: 0x2943                        BEQ         low_power_mode=1        APM_SWITCH_UP
                //0x022: 0x2145                        BEQ         low_power_mode=0        STDBY_RST
  0x700b501a,   //0x024: 0x501A      SAIL_WKUP:        SET1        sail_sleep_en_disable
                //0x026: 0x700B                        WAIT1       sail_pwr_rdy
  0x21452943,   //0x028: 0x2943                        BEQ         low_power_mode=1        APM_SWITCH_UP
                //0x02A: 0x2145                        BEQ         low_power_mode=0        STDBY_RST
  0x21452943,   //0x02C: 0x2943      MD_WKUP:          BEQ         low_power_mode=1        APM_SWITCH_UP
                //0x02E: 0x2145                        BEQ         low_power_mode=0        STDBY_RST
  0x5001500b,   //0x030: 0x500B      APM_SWITCH_UP:    SET1        save_ff_disable
                //0x032: 0x5001                        SET1        pch_low_pwr_exit_trg
  0x20c95003,   //0x034: 0x5003                        SET1        qch_low_pwr_exit_trg
                //0x036: 0x20C9                        BEQ         apm_up_in_progress=0    LABEL1
  0x208b180a,   //0x038: 0x180A                        JMP                                 LABEL2
                //0x03A: 0x208B      LABEL1:           BEQ         apm_dwn_in_progress=0   LABEL3
  0x50155005,   //0x03c: 0x5005      LABEL2:           SET1        low_pwr_func_ares
                //0x03E: 0x5015      LABEL3:           SET1        apm_clk_enable
  0x50160002,   //0x040: 0x0002                        DELI        104ns
                //0x042: 0x5016                        SET1        out2apm_aon_use_aux_seq_disable
  0x40185017,   //0x044: 0x5017                        SET1        out2apm_tile_act_br_seq_0
                //0x046: 0x4018                        SET0        out2apm_tile_act_br_seq_1
  0x0003502d,   //0x048: 0x502D                        SET1        out2apm_tile_act_br_seq_switch
                //0x04A: 0x0003                        DELI        208ns
  0x40195019,   //0x04c: 0x5019                        SET1        out2apm_start_apm_switch_seq
                //0x04E: 0x4019                        SET0        out2apm_start_apm_switch_seq
  0x4015700c,   //0x050: 0x700C                        WAIT1       apm2out_tile_trans_done
                //0x052: 0x4015                        SET0        apm_clk_enable
  0x00020002,   //0x054: 0x0002                        DELI        104ns
                //0x056: 0x0002                        DELI        104ns
  0x00044005,   //0x058: 0x4005                        SET0        low_pwr_func_ares
                //0x05A: 0x0004                        DELI        520ns
  0x500c500a,   //0x05c: 0x500A      RET_DISABLE:      SET1        retain_ff_disable
                //0x05E: 0x500C                        SET1        restore_ff
  0x400c0002,   //0x060: 0x0002                        DELI        104ns
                //0x062: 0x400C                        SET0        restore_ff
  0x50041806,   //0x064: 0x1806                        JMP         ISO_DEASSERT
                //0x066: 0x5004      STDBY_RST:        SET1        standby_core_ares
  0x40040004,   //0x068: 0x0004                        DELI        520ns
                //0x06A: 0x4004                        SET0        standby_core_ares
  0x500d5009,   //0x06c: 0x5009      ISO_DEASSERT:     SET1        sail_cx_clamp_mem_disable
                //0x06E: 0x500D                        SET1        freeze_io_early_disable
  0x500e5010,   //0x070: 0x5010                        SET1        sail_cx_iso_output_disable
                //0x072: 0x500E                        SET1        freeze_io_disable
  0x5011500f,   //0x074: 0x500F                        SET1        sail_cx_iso_input_disable
                //0x076: 0x5011                        SET1        sail_from_md_cx_iso_en_disable
  0x50260004,   //0x078: 0x0004                        DELI        520ns
                //0x07A: 0x5026                        SET1        cxo_pad_enable
  0x60065008,   //0x07c: 0x5008                        SET1        mem_pwr_down_disable
                //0x07E: 0x6006                        WAIT0       mem_pwr_down_done
  0x60055007,   //0x080: 0x5007                        SET1        func_clk_enable
                //0x082: 0x6005                        WAIT0       all_clk_off
  0x40016002,   //0x084: 0x6002                        WAIT0       aggr_pch_low_pwr_rdy
                //0x086: 0x4001                        SET0        pch_low_pwr_exit_trg
  0x40036003,   //0x088: 0x6003                        WAIT0       aggr_qch_low_pwr_rdy
                //0x08A: 0x4003                        SET0        qch_low_pwr_exit_trg
  0x50254027,   //0x08c: 0x4027                        SET0        sleep_exit
                //0x08E: 0x5025    CRASH_SEQ_COMPLETE: SET1        seq_wakeup_done
  0x00001000,   //0x090: 0x1000                        RETURN
#else
  // Sequence Memory Commands
  0x501c2007,   // 0x2007       CRASH_WAKEUP_SEQ:   BEQ         pwr_seq_busy=0          CRASH_SEQ_COMPLETE
                // 0x501C                           SET1        seq_wdog_disable
  0x5027501d,   // 0x501D                           SET1        sleep_entry_disable
                // 0x5027                           SET1        sleep_exit
  0x28482906,   // 0x2906                           BEQ         de_iso_in_progress=1    ISO_DEASSERT
                // 0x2848                           BEQ         iso_in_progress=1       ISO_IN_PROGRESS
  0x288328c3,   // 0x28C3                           BEQ         apm_up_in_progress=1    APM_SWITCH_UP
                // 0x2883                           BEQ         apm_dwn_in_progress=1   APM_SWITCH_UP
  0x29c12980,   // 0x2980                           BEQ         sail_pmic_wakeup=1      SAIL_PMIC_WKUP
                // 0x29C1                           BEQ         sail_wake_up=1          SAIL_WKUP
  0x10002a02,   // 0x2A02                           BEQ         md_wake_up=1            MD_WKUP
                // 0x1000                           RETURN
  0x21452944,   // 0x2944       ISO_IN_PROGRESS:    BEQ         low_power_mode=1        RET_DISABLE
                // 0x2145                           BEQ         low_power_mode=0        STDBY_RST
  0x501a700b,   // 0x700B       SAIL_PMIC_WKUP:     WAIT1       sail_pwr_rdy
                // 0x501A                           SET1        sail_sleep_en_disable
  0x21452943,   // 0x2943                                       BEQ         low_power_mode=1        APM_SWITCH_UP
                // 0x2145                                       BEQ         low_power_mode=0        STDBY_RST
  0x700b501a,   // 0x501A       SAIL_WKUP:          SET1        sail_sleep_en_disable
                // 0x700B                           WAIT1       sail_pwr_rdy
  0x21452943,   // 0x2943                                       BEQ         low_power_mode=1        APM_SWITCH_UP
                // 0x2145                                       BEQ         low_power_mode=0        STDBY_RST
  0x21452943,   // 0x2943       MD_WKUP:                        BEQ         low_power_mode=1        APM_SWITCH_UP
                // 0x2145                                       BEQ         low_power_mode=0        STDBY_RST
  0x5001500b,   // 0x500B       APM_SWITCH_UP:      SET1        save_ff_disable
                // 0x5001                           SET1        pch_low_pwr_exit_trg
  0x50055003,   // 0x5003                           SET1        qch_low_pwr_exit_trg
                // 0x5005                           SET1        low_pwr_func_ares
  0x00025015,   // 0x5015                           SET1        apm_clk_enable
                // 0x0002                           DELI        104ns
  0x50175016,   // 0x5016                           SET1        out2apm_aon_use_aux_seq_disable
                // 0x5017                           SET1        out2apm_tile_act_br_seq_0
  0x502d4018,   // 0x4018                           SET0        out2apm_tile_act_br_seq_1
                // 0x502D                           SET1        out2apm_tile_act_br_seq_switch
  0x50190003,   // 0x0003                           DELI        208ns
                // 0x5019                           SET1        out2apm_start_apm_switch_seq
  0x700c4019,   // 0x4019                           SET0        out2apm_start_apm_switch_seq
                // 0x700C                           WAIT1       apm2out_tile_trans_done
  0x00024015,   // 0x4015                           SET0        apm_clk_enable
                // 0x0002                           DELI        104ns
  0x40050002,   // 0x0002                           DELI        104ns
                // 0x4005                           SET0        low_pwr_func_ares
  0x500a0004,   // 0x0004                           DELI        520ns
                // 0x500A     RET_DISABLE:          SET1        retain_ff_disable
  0x0002500c,   // 0x500C                           SET1        restore_ff
                // 0x0002                           DELI        104ns
  0x1806400c,   // 0x400C                           SET0        restore_ff
                // 0x1806                           JMP         ISO_DEASSERT
  0x00045004,   // 0x5004       STDBY_RST:          SET1        standby_core_ares
                // 0x0004                           DELI        520ns
  0x50094004,   // 0x4004                           SET0        standby_core_ares
                // 0x5009                           SET1        sail_cx_clamp_mem_disable
  0x5010500d,   // 0x500D                           SET1        freeze_io_early_disable
                // 0x5010                           SET1        sail_cx_iso_output_disable
  0x500f500e,   // 0x500e                           SET1        freeze_io_disable
                // 0x500F                           SET1        sail_cx_iso_input_disable
  0x00045011,   // 0x5011                           SET1        sail_from_md_cx_iso_en_disable
                // 0x0004                           DELI        520ns
  0x50085026,   // 0x5026                           SET1        cxo_pad_enable
                // 0x5008                           SET1        mem_pwr_down_disable
  0x50076006,   // 0x6006                           WAIT0       mem_pwr_down_done
                // 0x5007                           SET1        func_clk_enable
  0x60026005,   // 0x6005                           WAIT0       all_clk_off
                // 0x6002                           WAIT0       aggr_pch_low_pwr_rdy
  0x60034001,   // 0x4001                           SET0        pch_low_pwr_exit_trg
                // 0x6003                           WAIT0       aggr_qch_low_pwr_rdy
  0x40274003,   // 0x4003                           SET0        qch_low_pwr_exit_trg
                // 0x4027                           SET0        sleep_exit
  0x10005025,   // 0x5025       CRASH_SEQ_COMPLETE: SET1        seq_wakeup_done
                // 0x1000                           RETURN

#endif /* PC_RUMI_TESTING */
};

static uint32 crash_wkup_br_addr[] = {
// Branch Addresses
// Branch addr: 0x0
#ifndef PC_RUMI_TESTING
  0x1c,   // SAIL_PMIC_WKUP = 28 + BRANCH_ADDR: 0x0  BRANCH_REG: 0
  0x24,   // SAIL_WKUP = 36 + BRANCH_ADDR: 0x0  BRANCH_REG: 1
  0x2c,   // MD_WKUP = 44 + BRANCH_ADDR: 0x0  BRANCH_REG: 2
  0x30,   // APM_SWITCH_UP = 48 + BRANCH_ADDR: 0x0  BRANCH_REG: 3
  0x5c,   // RET_DISABLE = 92 + BRANCH_ADDR: 0x0  BRANCH_REG: 4
  0x66,   // STDBY_RST = 102 + BRANCH_ADDR: 0x0  BRANCH_REG: 5
  0x6c,   // ISO_DEASSERT = 108 + BRANCH_ADDR: 0x0  BRANCH_REG: 6
  0x8e,   // CRASH_SEQ_COMPLETE = 142 + BRANCH_ADDR: 0x0  BRANCH_REG: 7
  0x18,   // ISO_IN_PROGRESS = 24 + BRANCH_ADDR: 0x0  BRANCH_REG: 8
  0x3a,   // LABEL1 = 58 + BRANCH_ADDR: 0x0  BRANCH_REG: 9
  0x3c,   // LABEL2 = 60 + BRANCH_ADDR: 0x0  BRANCH_REG: 10
  0x3e,   // LABEL3 = 62 + BRANCH_ADDR: 0x0  BRANCH_REG: 11
#else
  0x1c,   // SAIL_PMIC_WKUP = 28 + BRANCH_ADDR: 0x0  BRANCH_REG: 0
  0x24,   // SAIL_WKUP = 36 + BRANCH_ADDR: 0x0  BRANCH_REG: 1
  0x2c,   // MD_WKUP = 44 + BRANCH_ADDR: 0x0  BRANCH_REG: 2
  0x30,   // APM_SWITCH_UP = 48 + BRANCH_ADDR: 0x0  BRANCH_REG: 3
  0x56,   // RET_DISABLE = 86 + BRANCH_ADDR: 0x0  BRANCH_REG: 4
  0x60,   // STDBY_RST = 96 + BRANCH_ADDR: 0x0  BRANCH_REG: 5
  0x66,   // ISO_DEASSERT = 102 + BRANCH_ADDR: 0x0  BRANCH_REG: 6
  0x88,   // CRASH_SEQ_COMPLETE = 136 + BRANCH_ADDR: 0x0  BRANCH_REG: 7
  0x18,   // ISO_IN_PROGRESS = 24 + BRANCH_ADDR: 0x0  BRANCH_REG: 8
#endif /* PC_RUMI_TESTING */
};

#endif /* __PWR_CONTROLLER_SEQ_H__ */
