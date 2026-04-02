#ifndef __SPINOR_SFDP_H__
#define __SPINOR_SFDP_H__
/*
===========================================================================
*/
/**
    @file  spinor_sfdp.h
    @brief Serial Flash Discoverable Parameters

*/
/*
    ===========================================================================

    Copyright (c) 2020-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_sfdp.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_api.h"
#include "spinor_init_config.h"

//#define SPINOR_SFDP_UNUSED_FUNCTIONS

#define SFDP_HEADER_SIGNATURE         0x50444653
#define SFDP_HEADER_MAJOR_REV         1
#define SFDP_HEADER_MINOR_REV_D       8         /* JESD216D = 8*/

#define SFDP_BASIC_PARAM_MAJOR_REV    1
#define SFDP_BASIC_PARAM_MINOR_REV    7         /* JESD216A = 5, JESD216B = 6, JESD216C = 7*/

#define MAX_3BYTE_ADDRESS             0x00FFFFFF
#define READ_SDR_4B_111_INST          0x13
#define READ_SDR_4B_111_INST_F        0x0C
#define READ_SDR_4B_112_INST_F        0x3C
#define READ_SDR_4B_122_INST_F        0xBC
#define READ_SDR_4B_114_INST_F        0x6C
#define READ_SDR_4B_144_INST          0xEC
#define READ_SDR_4B_118_INST_F        0x7C
#define READ_SDR_4B_188_INST_F        0xCC
#define PROG_SDR_4B_111_INST          0x12
#define PROG_SDR_4B_114_INST          0x34
#define PROG_SDR_4B_144_INST          0x3E
#define PROG_SDR_4B_118_INST          0x84
#define PROG_SDR_4B_188_INST          0x8E
#define READ_DTR_4B_111_INST          0x0E
#define READ_DTR_4B_122_INST          0xBE
#define READ_DTR_4B_144_INST          0xEE
#define READ_DTR_4B_188_INST          0xFD
#define SFDP_BASIC_PARAM_LSB          0x00
#define SFDP_BASIC_PARAM_MSB          0xFF
#define SFDP_4BYTE_INST_LSB           0x84
#define SFDP_4BYTE_INST_MSB           0xFF
#define SFDP_SCCR_MAP_INST_LSB        0x87
#define SFDP_SCCR_MAP_INST_MSB        0xFF
#define SFDP_XSPI_P1_INST_LSB         0x05
#define SFDP_XSPI_P1_INST_MSB         0xFF
#define SFDP_OCTAL_DDR_CMD_SEQ_LSB    0x0A
#define SFDP_OCTAL_DDR_CMD_SEQ_MSB    0xFF
#define SFDP_SECTOR_MAP_LSB           0x81
#define SFDP_SECTOR_MAP_MSB           0xFF
#define MANUFACTURER_ID_MACRONIX      0xC2
#define MANUFACTURER_ID_MICRON        0x20
#define MANUFACTURER_ID_SPANSION      0x01
#define MANUFACTURER_ID_WINBOND       0xEF
#define MANUFACTURER_ID_MICRON_OSPI   0x2C
#define MANUFACTURER_ID_ISSI          0x9D
#define MANUFACTURER_ID_GD            0xC8
#define MANUFACTURER_ID_INFINEON      0x34

#define INFI_CONFIG_DETECT_DWORDS     3
#define INFI_MAX_NUM_CONFIGS          4

typedef enum {
  SFDP_BUS_QSPI,
  SFDP_BUS_OSPI,
  SFDP_BUS_MAX
} spinor_sfdp_bus_t;

typedef struct spinor_sfdp_header_t
{
  uint32 signature;                             /* SFDP or 0x50444653 */
  uint8  minor_rev;
  uint8  major_rev;
  uint8  num_param_headers;
  uint8  access_protocol;
} __attribute__((__packed__)) spinor_sfdp_header;

/* SFDP Parameter Header */
typedef struct spinor_sfdp_param_header_t
{
  uint8  param_id_lsb;
  uint8  minor_rev;
  uint8  major_rev;
  uint8  table_length;
  uint32 table_pointer:24;
  uint32 param_id_msb:8;
}__attribute__((__packed__)) spinor_sfdp_param_header;

/* SFDP Basic Parameters */
typedef struct spinor_sfdp_basic_param_t
{
  /* DWORD 1 */
  uint32 blk_erase_size:2;               /* Block/Sector Erase Sizes */
  uint32 write_granularity:1;
  uint32 volatile_block_protect:1;       /* Volatile Status Register Block Protect bits */
  uint32 write_enable_instruction:1;     /* Write Enable Instruction Select for Writing to Volatile Status Register */
  uint32 reserved1_1:3;
  uint32 erase_instr_4k:8;               /* 4 Kilobyte Erase Instruction */
  uint32 read_112_support:1;             /* Supports (1-1-2) Fast Read */
  uint32 address_bytes_sup:2;            /*Address bytes mode, 3 byte or 4 byte */
  uint32 dtr_support:1;
  uint32 read_122_support:1;             /* Supports (1-2-2) Fast Read */
  uint32 read_144_support:1;             /* Supports (1-4-4) Fast Read */
  uint32 read_114_support:1;             /* Supports (1-1-4) Fast Read */
  uint32 reserved1_2:9;

  /* DWORD 2 */
  uint32 density;                        /* Density in bits. */

  /* DWORD 3 */
  uint32 read_144_dummy_cycles:5;
  uint32 read_144_mode_clocks:3;
  uint32 read_144_instruction:8;
  uint32 read_114_dummy_cycles:5;
  uint32 read_114_mode_clocks:3;
  uint32 read_114_instruction:8;

  /* DWORD 4 */
  uint32 read_112_dummy_cycles:5;
  uint32 read_112_mode_clocks:3;
  uint32 read_112_instruction:8;
  uint32 read_122_dummy_cycles:5;
  uint32 read_122_mode_clocks:3;
  uint32 read_122_instruction:8;

  /* DWORD 5 */
  uint32 read_222_support:1;
  uint32 reserved5_1:3;
  uint32 read_444_support:1;
  uint32 reserved5_2:27;

  /* DWORD 6 */
  uint32 reserved6_1:16;
  uint32 read_222_dummy_cycles:5;
  uint32 read_222_mode_clocks:3;
  uint32 read_222_instruction:8;

  /* DWORD 7 */
  uint32 reserved7_1:16;
  uint32 read_444_dummy_cycles:5;
  uint32 read_444_mode_clocks:3;
  uint32 read_444_instruction:8;

  /* DWORD 8 */
  uint32 erase_type1_size:8;             /* Size in bytes, this field specifies N for size as 2^N */
  uint32 erase_type1_inst:8;
  uint32 erase_type2_size:8;
  uint32 erase_type2_inst:8;

  /* DWORD 9 */
  uint32 erase_type3_size:8;
  uint32 erase_type3_inst:8;
  uint32 erase_type4_size:8;
  uint32 erase_type4_inst:8;

  /* DWORD 10 */
  uint32 erase_time_multiplier:4;
  uint32 erase_type1_time:7;
  uint32 erase_type2_time:7;
  uint32 erase_type3_time:7;
  uint32 erase_type4_time:7;

  /* DWORD 11 */
  uint32 program_multiplier:4;           /* Multiplier from typical time to max time for Page or byte program */
  uint32 page_size:4;
  uint32 page_prog_time:6;               /* Page Program Typical time */
  uint32 byte_prog_time_first:5;         /* Byte Program Typical time, first byte */
  uint32 byte_prog_time_additional:5;    /* Byte Program Typical time, additional byte */
  uint32 erase_time:7;                   /* Chip Erase, Typical time */
  uint32 reserved11_1:1;

  /* DWORD 12 */
  uint32 prohibit_op_prog:4;             /* Prohibited Operations During Program Suspend */
  uint32 prohibit_op_erase:4;            /* Prohibited Operations During Erase Suspend */
  uint32 reserved12_1:1;
  uint32 prog_resume_suspend_interval:4; /* Program Resume to Suspend Interval */
  uint32 suspend_prog_lat_count:5;       /* Suspend in-progress program max latency count */
  uint32 suspend_prog_lat_units:2;       /* Suspend in-progress program max latency unit */
  uint32 erase_res2susp_interval:4;      /* Erase Resume to Suspend Interval */
  uint32 suspend_erase_lat_count:5;      /* Suspend in-progress erase max latency count */
  uint32 suspend_erase_lat_units:2;      /* Suspend in-progress erase max latency count */
  uint32 susp_res_suppport:1;            /* Suspend / Resume supported */

  /* DWORD 13 */
  uint32 prog_resume_inst:8;             /* Program Resume Instruction */
  uint32 prog_suspend_inst:8;            /* Program Suspend Instruction */
  uint32 resume_inst:8;                  /* Resume Instruction */
  uint32 suspend_inst:8;                 /* Suspend Instruction */

  /* DWORD 14 */
  uint32 reserved14_1:2;
  uint32 status_polling:6;               /* Status Register Polling Device Busy */
  uint32 exit_pwr_delay_count:5;         /* Exit Deep Powerdown to next operation delay count */
  uint32 exit_pwr_delay_units:2;         /* Exit Deep Powerdown to next operation delay unit */
  uint32 exit_pwr_inst:8;                /* Exit Deep Powerdown Instruction */
  uint32 enter_pwr_inst:8;               /* Enter Deep Powerdown Instruction */
  uint32 deep_pwr_support:1;             /* Deep Powerdown Supported */

  /* DWORD 15 */
  uint32 disable_444_seq:4;              /* 4-4-4 mode disable sequences */
  uint32 enable_444_seq:5;               /* 4-4-4 mode enable sequences */
  uint32 support_044:1;                  /* 0-4-4 mode supported */
  uint32 exit_044_method:6;              /* 0-4-4 Mode Exit Method */
  uint32 entry_044_method:4;             /* 0-4-4 Mode Entry Method */
  uint32 quad_en_r:3;                    /* Quad Enable Requirements (QER) */
  uint32 reset_disable:1;                /* HOLD or RESET Disable */
  uint32 reserved15_1:8;

  /* DWORD 16 */
  uint32 volatile_register_1:7;          /* Volatile or Non-Volatile Register and Write Enable Instruction for Status Register 1 */
  uint32 reserved16_1:1;
  uint32 srr_seq_sup:6;                  /* Soft Reset and Rescue Sequence Support */
  uint32 exit_4b_addr:10;                /* Exit 4-Byte Addressing */
  uint32 enter_4b_addr:8;                /* Enter 4-Byte Addressing */

  /* DWORD 17 */
  uint32 read_188_dummy_cycles:5;        /* (1-8-8) Fast Read Number of Wait states (dummy clocks) needed before valid output */
  uint32 read_188_mode_clocks:3;         /* (1-8-8) Fast Read Number of Mode Clocks */
  uint32 read_188_instruction:8;         /* (1-8-8) Fast Read Instruction */
  uint32 read_118_dummy_cycles:5;        /* (1-1-8) Fast Read Number of Wait states (dummy clocks) needed before valid output */
  uint32 read_118_mode_clocks:3;         /* (1-1-8) Fast Read Number of Mode Clocks */
  uint32 read_118_instruction:8;         /* (1-1-8) Fast Read Instruction */

  /* DWORD 18 */
  uint32 reserved18_1:18;
  uint32 var_output_strength:5;          /* Variable Output Driver Strength */
  uint32 spi_reset:1;                    /* JEDEC SPI Protocol Reset(In-Band Reset) */
  uint32 dsw_str_mode:2;                 /* Data StrobeWaveforms in STR Mode */
  uint32 ds_sup_str_mode:1;              /* Data Strobe support for QPI STR mode (4S-4S-4S) */
  uint32 ds_sup_dtr_mode:1;              /* Data Strobe support for QPI DTR mode (4S-4D-4D) */
  uint32 reserved18_2:1;
  uint32 octal_dtr_ext:2;                /* Octal DTR (8D-8D-8D) Command and Command Extension */
  uint32 byte_order_888_mode:1;          /* Byte Orderin 8D-8D-8Dmode */

  /* DWORD 19 */
  uint32 dis_888_seq:4;                  /* 8s-8s-8smode disable sequences */
  uint32 en_888_seq:5;                   /* 8s-8s-8smode enable sequences */
  uint32 sup_088:1;                      /* 0-8-8 mode supported */
  uint32 exit_088_method:6;              /* 0-8-8Mode Exit Method */
  uint32 entry_088_method:4;             /* 0-8-8Mode Entry Method */
  uint32 octal_en_req:3;                 /* OctalEnable Requirements */
  uint32 reserved19_1:9;

  /* DWORD 20 */
  uint32 mhz_444s_ndt:4;                 /* Maximum operation speed of device in 4S-4S-4S mode when not utilizing Data Strobe */
  uint32 mhz_444s_dt:4;                  /* Maximum operation speed of device in 4S-4S-4S mode when utilizing Data Strobe */
  uint32 mhz_444d_ndt:4;                 /* Maximum operation speed of device in 4S-4D-4D mode when not utilizing Data Strobe */
  uint32 mhz_444d_dt:4;                  /* Maximum operation speed of device in 4S-4D-4D mode when utilizing Data Strobe */
  uint32 mhz_888s_ndt:4;                 /* Maximum operation speed of device in 8S-8S-8S mode when not utilizing Data Strobe */
  uint32 mhz_888s_dt:4;                  /* Maximum operation speed of device in 8S-8S-8S mode when utilizing Data Strobe */
  uint32 mhz_888d_ndt:4;                 /* Maximum operation speed of device in 8S-8D-8D mode when not utilizing Data Strobe */
  uint32 mhz_888d_dt:4;                  /* Maximum operation speed of device in 8S-8D-8D mode when utilizing Data Strobe */
}__attribute__((__packed__)) spinor_sfdp_basic_param;

/* 4-byte Address Instruction Table */
typedef struct spinor_sfdp_4byte_inst_t
{
  /* DWORD 1 */
  uint32 read_111_support:1;             /* Support for (1-1-1) READ Command, Instruction=13h */
  uint32 fread_111_support:1;            /* Support for (1-1-1) FAST_READ Command, Instruction=0Ch */
  uint32 read_112_support:1;             /* Support for (1-1-2) FAST_READ Command, Instruction=3Ch */
  uint32 read_122_support:1;             /* Support for (1-2-2) FAST_READ Command, Instruction=BCh */
  uint32 read_114_support:1;             /* Support for (1-1-4) FAST_READ Command, Instruction=6Ch */
  uint32 read_144_support:1;             /* Support for (1-4-4) FAST_READ Command, Instruction=ECh */
  uint32 prog_111_support:1;             /* Support for (1-1-1) Page Program Command, Instruction=12h */
  uint32 prog_114_support:1;             /* Support for (1-1-4) Page Program Command, Instruction=34h */
  uint32 prog_144_support:1;             /* Support for (1-4-4) Page Program Command, Instruction=3Eh */
  uint32 erase_1_support:1;              /* Support for Erase Command –Type 1 size, Instruction lookup in next Dword */
  uint32 erase_2_support:1;              /* Support for Erase Command –Type 2 size, Instruction lookup in next Dword */
  uint32 erase_3_support:1;              /* Support for Erase Command –Type 3 size, Instruction lookup in next Dword */
  uint32 erase_4_support:1;              /* Support for Erase Command –Type 4 size, Instruction lookup in next Dword */
  uint32 read_dtr_111_support:1;         /* Support for (1-1-1) DTR_Read Command, Instruction=0Eh */
  uint32 read_dtr_122_support:1;         /* Support for (1-2-2) DTR_Read Command, Instruction=BEh */
  uint32 read_dtr_144_support:1;         /* Support for (1-4-4) DTR_Read Command, Instruction=EEh */
  uint32 vol_read_lock_support:1;        /* Support for volatile individual sector lock Read command, Instruction=E0h */
  uint32 vol_write_lock_support:1;       /* Support for volatile individual sector lock Write command, Instruction=E1h */
  uint32 nvol_read_lock_support:1;       /* Support for non-volatile individual sector lock read command, Instruction=E2h*/
  uint32 nvol_write_lock_support:1;      /* Support for non-volatile individual sector lock write command, Instruction=E3h */
  uint32 read_118_support:1;             /* Support for (1-1-8) FAST_READ Command, Instruction=7Ch */
  uint32 read_188_support:1;             /* Support for (1-8-8) FAST_READ Command, Instruction=CCh */
  uint32 read_dtr_188_support:1;         /* Support for (1-8-8) DTR_READ Command, Instruction=FDh */
  uint32 prog_118_support:1;             /* Support for (1-1-8) Page Program Command, Instruction=84h */
  uint32 prog_188_support:1;             /* Support for (1-8-8) Page Program Command, Instruction=8Eh */
  uint32 reserved1:7;

  /* DWORD 2, erase command, same as basic flash parameter table DWORD 8 and 9 */
  uint32 erase_1_inst:8;                 /* Instruction for Erase Type 1 , typical 0x21 */
  uint32 erase_2_inst:8;                 /* Instruction for Erase Type 2 , typical 0x5C */
  uint32 erase_3_inst:8;                 /* Instruction for Erase Type 3 , typical 0xDC */
  uint32 erase_4_inst:8;                 /* Instruction for Erase Type 4 , typical 0xDC */
} __attribute__((__packed__)) spinor_sfdp_4byte_inst;

typedef struct spinor_sfdp_xspi_profile_1_0_t
{
  /* DWORD 1 */
  uint32 read_fast_wrapped_cmd                                            : 8;    /* 00h means not supported                       */
  uint32 read_fast_cmd                                                    : 8;    /* command code                                  */
  uint32 reversed1                                                        : 6;    /* reserved                                      */
  uint32 num_data_bytes_used_for_write_reg_cmd                            : 1;    /* 0: 1 bytes, 1: 2 bytes                        */
  uint32 num_additional_modifier_bytes_used_for_write_reg_cmd             : 1;    /* 0: 1 bytes, 1: 4 bytes                        */
  uint32 num_additional_modifier_bytes_used_for_write_status_cfg_reg_cmd  : 1;    /* 0: 0 bytes, 1: 4 bytes                        */
  uint32 initial_latency_for_read_non_volatile_reg_cmd                    : 1;    /* 0: 4 clocks, 1: 8 clocks                      */
  uint32 initial_latency_for_read_volatile_reg_cmd                        : 1;    /* 0: 4 clocks, 1: 8 clocks                      */
  uint32 num_additional_modifier_bytes_used_for_read_reg_cmd              : 1;    /* 0: 1 bytes, 1: 4 bytes                        */
  uint32 initial_latency_for_read_status_reg_cmd                          : 1;    /* 0: 4 clock cycles, 1: 8 clock cycles          */
  uint32 num_additional_modifier_bytes_used_for_read_status_reg_cmd       : 1;    /* 0: 0 bytes, 1: 4 bytes                        */
  uint32 sfdp_cmd_in_8d_8d_8d_mode_dummy_cycles                           : 1;    /* 0: b, 1: 20                                   */
  uint32 sfdp_cmd_in_8d_8d_8d_mode_addr_bytes                             : 1;    /* o: 32 bites, 1: 24 bytes                      */

  /* DWORD 2 */
  uint32 write_nv_reg_cmd                                                 : 8;    /* command op code                               */
  uint32 write_volatile_reg_cmd                                           : 8;    /* command op code                               */
  uint32 read_nv_reg_cmd                                                  : 8;    /* command op code                               */
  uint32 read_volatile_reg_cmd                                            : 8;    /* command op code                               */

  /* DWORD 3 */
  uint32 reserved3                                                        : 10;   /* Reserved                                      */
  uint32 enter_default_protocol_mode                                      : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 soft_reset_and_enter_default_protocol_mode                       : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 reset_enable                                                     : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 soft_reset                                                       : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 exit_deep_power_down                                             : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 enter_deep_sleep_power_down                                      : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 write_nv_reg                                                     : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 write_volatile_reg                                               : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 write_reg                                                        : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 clear_flag_status_reg                                            : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 write_status_cfg_reg                                             : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 read_nv_reg                                                      : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 read_volatile_reg                                                : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 read_reg                                                         : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 read_flag_status_reg                                             : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 read_cfg_reg                                                     : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 erase_chip                                                       : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 erase_32k_bytes                                                  : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 erase_4k_bytes                                                   : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 setup_read_wrap                                                  : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 read_fast_wrapped                                                : 1;    /* 0: command not supported, 1: cpmand supported */
  uint32 read_sfdp_8d_8d_8d                                               : 1;    /* 0: command not supported, 1: cpmand supported */

  /* DWORD 4 */
  uint32 reserved4                                                        : 2;    /* Reserved                                      */
  uint32 cfg_bit_pattern_to_set_this_num_of_dummy_cycles_200mhz_operation : 5;    /* No comment                                    */
  uint32 num_dummy_cycles_required_200mhz_operation                       : 5;    /* 0: this 200MHz frequency is not supported     */
  uint32 reserved                                                         : 20;   /* Reserved                                      */

  /* DWORD 5 */
  uint32 reserved5                                                        : 2;    /* Reserved                                      */
  uint32 cfg_bit_pattern_to_set_this_num_of_dummy_cycles_100mhz_operation : 5;    /* No comment                                    */
  uint32 num_dummy_cycles_required_100mhz_operation                       : 5;    /* 0: this 100MHz frequency is not supported     */
  uint32 cfg_bit_pattern_to_set_this_num_of_dummy_cycles_133mhz_operation : 5;    /* No comment                                    */
  uint32 num_dummy_cycles_required_133mhz_operation                       : 5;    /* 0: this 133MHz frequency is not supported     */
  uint32 cfg_bit_pattern_to_set_this_num_of_dummy_cycles_166mhz_operation : 5;    /* No comment                                    */
  uint32 num_dummy_cycles_required_166mhz_operation                       : 5;    /* 0: this 166MHz frequency is not supported     */
} spinor_sfdp_xspi_profile_1_0;

typedef struct spinor_octal_ddr_dword_t
{
  /* DWORD 1 */
  uint8 cmd_seq_byte_3:8;           /* Byte 3 of the command sequence */
  uint8 cmd_seq_byte_2:8;           /* Byte 2 of the command sequence */
  uint8 cmd_seq_byte_1:8;           /* Byte 1 of the command sequence */
  uint8 cmd_seq_len:8;              /* Length of the command sequence */
  
  uint8 cmd_seq_byte_7:8;           /* Byte 7 of the command sequence */
  uint8 cmd_seq_byte_6:8;           /* Byte 6 of the command sequence */
  uint8 cmd_seq_byte_5:8;           /* Byte 5 of the command sequence */
  uint8 cmd_seq_byte_4:8;           /* Byte 4 of the command sequence */
}__attribute__((__packed__)) spinor_octal_ddr_dword;

/* Command Sequences to change to Octal DDR */
typedef struct spinor_octal_ddr_cmd_seq_t
{
  /* spinor_ddr_cmd_seq[0] - cmd 1
     spinor_ddr_cmd_seq[1] - cmd 2
     spinor_ddr_cmd_seq[2] - cmd 3
     spinor_ddr_cmd_seq[3] - cmd 4 */
  spinor_octal_ddr_dword spinor_ddr_cmd_seq[4];    /* 4 command sequences for the Octal DDR enablement table */
} __attribute__((__packed__)) spinor_octal_ddr_cmd_seq;


/* Configuration Detection Command Descriptor */
typedef struct spinor_config_detect_cmd_desc_t
{
  /* DWORD 1 */
  uint32 desc_end_indicator:1;           /* Descriptor Sequence End Indicator */
  uint32 desc_type:1;                    /* Descriptor Type */
  uint32 reserved1:6;
  uint32 detection_cmd_inst:8;           /* Eight bit instruction for the sector map configuration detection command */
  uint32 config_detect_cmd_rd_latency:4; /* Four bit field indicating the number of cycles between the end of address and the beginning of returning read data */
  uint32 reserved:2;
  uint32 config_detect_cmd_addr_len:2;   /* Two bit field that defines the length of the address used in the configuration detection command. */
  uint32 read_data_mask:8;               /* This bit field is used as a mask to select one bit from the data byte that is read */

  /* DWORD 2 */
  uint32 map_config_detect_cmd_addr:32;   /* Sector map configuration detection command address */
} __attribute__((__packed__)) config_detect_cmd_desc;


/* Configuration Map Descriptor Header */
typedef struct spinor_config_map_desc_header_t
{
  /* DWORD 1 */
  uint32 desc_end_indicator:1; /* Descriptor Sequence End Indicator */
  uint32 desc_type:1;          /* Descriptor Type */
  uint32 reserved1:6;
  uint32 config_ID:8;          /* Configuration ID */
  uint32 region_count:8;       /* The number of following region DWORDs minus 1 */
  uint32 reserved:8;
} __attribute__((__packed__)) config_map_desc_header;

/* Configuration Map Descriptor Region */
typedef struct spinor_config_map_desc_region_t
{
  /* DWORD 1 */
  uint32 erase_1_support:1;   /* Support for Erase Type 1 */
  uint32 erase_2_support:1;   /* Support for Erase Type 2 */
  uint32 erase_3_support:1;   /* Support for Erase Type 3 */
  uint32 erase_4_support:1;   /* Support for Erase Type 4 */
  uint32 reserved:4;
  uint32 region_size:24;      /* Region size as a multiple (count) of 256 Byte units */
} __attribute__((__packed__)) config_map_desc_region;

typedef struct
{
  uint32_t basic_param_offset;
  uint32_t basic_param_size;
  uint32_t inst_4byte_offset;
  uint32_t inst_4byte_size;
  uint32_t profile10_offset;
  uint32_t profile10_size;
  uint32_t octal_ddr_offset;
  uint32_t octal_ddr_size;
  uint32_t sector_map_offset;
  uint32_t sector_map_size;
  spinor_sfdp_header header_data;
  spinor_sfdp_param_header bparam_paramh;
  spinor_sfdp_param_header inst4b_paramh;
  spinor_sfdp_param_header profile10_paramh;
  spinor_sfdp_param_header octal_ddr_paramh;
  spinor_sfdp_param_header sector_map_paramh;
  spinor_sfdp_basic_param bparam_data;
  spinor_sfdp_4byte_inst inst4b_data;
  spinor_sfdp_xspi_profile_1_0 profile10_data;
  spinor_octal_ddr_cmd_seq octal_ddr_sequence;
  config_detect_cmd_desc config_info[3];
  config_map_desc_header config_header_data;
  config_map_desc_region config_region_data[5]; /* Required for our usage */
} spinor_sfdp_t;

/**********************************************************
 * Reads the SFDP Signature
 *
 * @signature [OUT]
 *   Stores the sfdp signature read.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_sfdp_read_signature(uint32* signature);

/**********************************************************
 * Read SFDP tables from flash memory
 *
 * @param device_id [IN]
 *   Device ID
 *
 * @param pSfdpTable [OUT]
 *   SFDP table pointer
 *
 * @return status [OUT]
 *   status
 *
 **********************************************************/
SPINOR_STATUS spinor_sfdp_read_tables(uint32 device_id,spinor_sfdp_t **pSfdpTable);

/**********************************************************
 * Read the SFDP Data and populate the spinor configuration structure.
 *
 * @param config [IN/OUT]
 *   SPI-NOR device configuration structure.
 *
 * @param manufacturer [IN]
 *   Manufacturer ID, least significant byte of spinor_util_read_device_id()
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_parse_sfdp(spinor_config_data *config, uint32 device_id, spinor_sfdp_t *sfdp_data_read);
SPINOR_STATUS spinor_parse_sfdp_1_1_1_str(spinor_config_data *config, uint32 device_id, spinor_sfdp_t *sfdp_data_read);
SPINOR_STATUS spinor_parse_sfdp2(boolean is_crash_dbg, uint32 device_id, spinor_hardcode_data_mode *hardcode_mode,
                                 spinor_config_data *config, spinor_sfdp_t *sfdp_data_read);

#endif /* __SPINOR_SFDP_H__ */
