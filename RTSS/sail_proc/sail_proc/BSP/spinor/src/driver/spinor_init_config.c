/*
===========================================================================
*/
/**
    @file  spinor_init_config.c
    @brief Implementation of passing RAM data table from other boot environments to spinor driver

*/
/*
    ===========================================================================

    Copyright (c) 2017-2018,2020-2024 Qualcomm Technologies, Inc.
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

#include "spinor_init_config.h"
#include "spinor_core.h"
#include <string.h>




static spinor_init_config_table_type spinor_cfg_table =
{
  .magic_no = SPINOR_INIT_TABLE_MAGIC_NUMBER,
  .total_entries = 8,
  .version_no =SPINOR_INIT_TABLE_VERSION_NUMBER,

};

#if 0
static spinor_config_data spinor_nor_entries[];

static spinor_config_data spinor_nor_entries[] =
{
  { /* Macronix MX66UW2G345G */
    .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    .enter_4byte_mode = ADDR_4BYTE_MODE_6,
    .octal_dtr_ext = 1,

    .access_param = {
                        {
                            /* Parameters to be used in Default 1-1-1 mode and STR */
                            .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = SDR_1_1_1_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 0,
                            .reg_read_addr_dummy_cycles = 0,
                            .addr_bytes_sfdp = 3,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0,
                            .read_opcode = 0x13,
                            .wait_state = 0,
                            .write_opcode = 0x12,
                            .erase_4kb_opcode = 0x21,
                        },
                        {
                            /* Parameters to be used in Perf mode which can be chosen based on the configuration required */
                            .read_mode = DDR_8_8_8_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = DDR_8_8_8_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 4,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 4,
                            .reg_read_addr_dummy_cycles = 4,
                            .addr_bytes_sfdp = 4,
                            .sfdp_read_dummy_cycles = 20,
                            .read_id_opcode = 0,
                            .read_opcode = 0xEE,
                            .wait_state = 6,
                            .write_opcode = 0x12,
                            .erase_4kb_opcode = 0x21,
                        }
                    },

    // .mode = 9,  /* SDR_8_8_8_MODE */  // .read_opcode = 0xEC, // .wait_state = 6,
    // .mode = 0,  /* SDR_1_1_1_MODE */  // .read_opcode = 0x13, // .wait_state = 0,
    // .mode = 7,  /* SDR_1_1_8_MODE */  // .read_opcode = 0x7C, // .wait_state = 6,
    // .mode = 12, /* DDR_8_8_8_MODE */  // .read_opcode = 0xEE, // .wait_state = 6,

    .quad_enable_mode = 0,
    .enable_444_seq = 0,
    .octal_enable_r = 4,
    .spi_io_mode = SPI_OCTAL_IO,
    .device_transfer_rate = SPI_TRANSFER_DTR,
	.octal_sdr_num_bytes = 2,
    .erase_err_bmsk = 0x40,
    .erase_err_status_reg = 0x2B,
    .write_err_bmsk = 0x20,
    .write_err_status_reg = 0x2B,
    .freq_khz = 166000, /* Spec supports max 50k */
    .read_max_transfer_in_pages = 0x100000, /* Change to part size */
    .density_in_blocks = 65536, /* PART SIZE, should change for new part */
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x003C84C2, /* This changes with each new part, command 9F*/
    .power_on_delay_in_100us = 8,
    .dqs_sync_qspi_clk = TRUE,
    .ecc_info = {
                    .ecc_default_enabled = TRUE,
                    .ecc_supported = TRUE,
                    .ecc_number_of_chunks = 4,
                    .ecc_enable_bmsk = 0x04, /* Bit 2 control the enablement of ECC
                                                Bit 0 and Bit 1 in 0x0400 address default set to 0, detects 2bit Error/Double programming */
                    .ecc_init_reg_addr = 0x0400,
                    .ecc_err_bmsk = 0xF0,
                    .ecc_correction_count_bmsk = 0x0F,
                    .ecc_double_prog_bmsk = 0x40,
                    .ecc_status_reg_rd_opcode = READ_CFG2_CMD,
                    .ecc_status_reg_wr_opcode = WRITE_CFG2_CMD,
                    .ecc_status_reg_addr = {0x00000800, 0x04000800, 0x08000800, 0x0C000800},  /*  Macronix : In each chunk, 1st address is to check status for that 512MB chunk and the subsequent addresses are the ECC failure event addresses
                                                                                                    Chunk 1 : 0x00000800, 0x00000C00, 0x00000D00, 0x00000E00, 0x00000F00
                                                                                                    Chunk 2 : 0x04000800, 0x04000C00, 0x04000D00, 0x04000E00, 0x04000F00
                                                                                                    Chunk 3 : 0x08000800, 0x08000C00, 0x08000D00, 0x08000E00, 0x08000F00
                                                                                                    Chunk 4 : 0x0C000800, 0x0C000C00, 0x0C000D00, 0x0C000E00, 0x0C000F00     */
                    .ecc_fail_chunk_addr = {0x00000C00, 0x00000D00, 0x00000E00, 0x00000F00,
                                            0x04000C00, 0x04000D00, 0x04000E00, 0x04000F00,
                                            0x08000C00, 0x08000D00, 0x08000E00, 0x08000F00,
                                            0x0C000C00, 0x0C000D00, 0x0C000E00, 0x0C000F00 },

                },
    .crc_info = {
                    .crc_supported = TRUE,
                    .crc_dtr_mode_needed = TRUE,
                    .crc_zero_to_enable = FALSE,
                    .crc_init_reg_addr = {0x0000, 0x0500},
                    .crc_status_reg_rd_opcode = READ_CFG2_CMD,
                    .crc_status_reg_wr_opcode = WRITE_CFG2_CMD,
                    .crc_status_reg_addr = 0x80000000,
                    .crc_enable_bmsk = {0x08, 0x90},
                    .crc_err_bmsk = 0x10,
                },
    .dummy_cycle_info = {
                            .dummy_cycle_config_addr = 0x300,
                            .dummy_cycle_reg_rd_opcode = READ_CFG2_CMD,
                            .dummy_cycle_reg_wr_opcode = WRITE_CFG2_CMD,
                            .dummy_cycle_config_bmsk = 0x07,
                            .dummy_config_shift = 0,
                                                            /* {freq,   1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR}
                                                                0 DUMMY CYCLES : INVALID
                                                            */
                            .dummy_clocks_freq_vs_number = {
                                                               {66,         0,       0,         0,          0,        0,         6,         0,         6,         6      },
                                                               {84,         0,       0,         0,          0,        0,         8,         0,         8,         8      },
                                                               {104,        0,       0,         0,          0,        0,         10,        0,         10,        10     },
                                                               {133,        0,       0,         0,          0,        0,         12,        0,         12,        12     },
                                                               {155,        0,       0,         0,          0,        0,         14,        0,         14,        14     },
                                                               {166,        0,       0,         0,          0,        0,         20,        0,         20,        20     },
                                                               {0xFFFFFFFF, 0xFF,    0xFF,      0xFF,       0xFF,     0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           },
                            .dummy_clocks_number_vs_regval = {
                                                                 {6, 0x7},
                                                                 {8, 0x6},
                                                                 {10, 0x5},
                                                                 {12, 0x4},
                                                                 {14, 0x3},
                                                                 {20, 0x0},
                                                                 {0xFF, 0xFF},
                                                             },
                        },
  },
  { /* Macronix Low density - 256Mb */
    .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    .enter_4byte_mode = ADDR_4BYTE_MODE_6,
    .octal_dtr_ext = 1,

    .access_param = {
                        {
                            /* Parameters to be used in Default 1-1-1 mode and STR */
                            .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = SDR_1_1_1_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 0,
                            .reg_read_addr_dummy_cycles = 0,
                            .addr_bytes_sfdp = 3,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0,
                            .read_opcode = 0x13,
                            .wait_state = 0,
                            .write_opcode = 0x12,
                            .erase_4kb_opcode = 0x21,
                        },
                        {
                            /* Parameters to be used in Perf mode which can be chosen based on the configuration required */
                            .read_mode = DDR_8_8_8_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = DDR_8_8_8_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 4,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 4,
                            .reg_read_addr_dummy_cycles = 4,
                            .addr_bytes_sfdp = 4,
                            .sfdp_read_dummy_cycles = 20,
                            .read_id_opcode = 0,
                            .read_opcode = 0xEE,
                            .wait_state = 6,
                            .write_opcode = 0x12,
                            .erase_4kb_opcode = 0x21,
                        }
                    },

    // .mode = 9,  /* SDR_8_8_8_MODE */  // .read_opcode = 0xEC, // .wait_state = 6,
    // .mode = 0,  /* SDR_1_1_1_MODE */  // .read_opcode = 0x13, // .wait_state = 0,
    // .mode = 7,  /* SDR_1_1_8_MODE */  // .read_opcode = 0x7C, // .wait_state = 6,
    // .mode = 12, /* DDR_8_8_8_MODE */  // .read_opcode = 0xEE, // .wait_state = 6,

    .quad_enable_mode = 0,
    .enable_444_seq = 0,
    .octal_enable_r = 4,
    .spi_io_mode = SPI_OCTAL_IO,
    .device_transfer_rate = SPI_TRANSFER_DTR,
	.octal_sdr_num_bytes = 2,
    .erase_err_bmsk = 0x40,
    .erase_err_status_reg = 0x2B,
    .write_err_bmsk = 0x20,
    .write_err_status_reg = 0x2B,
    .freq_khz = 166000, /* Spec supports max 50k */
    .read_max_transfer_in_pages = 0x20000, /* Change to part size */
    .density_in_blocks = 8192, /* PART SIZE, should change for new part */
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x003984C2, /* This changes with each new part, command 9F*/
    .power_on_delay_in_100us = 8,
    .dqs_sync_qspi_clk = TRUE,
    .ecc_info = {
                    .ecc_default_enabled = TRUE,
                    .ecc_supported = TRUE,
                    .ecc_number_of_chunks = 4,
                    .ecc_enable_bmsk = 0x04, /* Bit 2 control the enablement of ECC
                                                Bit 0 and Bit 1 in 0x0400 address default set to 0, detects 2bit Error/Double programming */
                    .ecc_init_reg_addr = 0x0400,
                    .ecc_err_bmsk = 0xF0,
                    .ecc_correction_count_bmsk = 0x0F,
                    .ecc_double_prog_bmsk = 0x40,
                    .ecc_status_reg_rd_opcode = READ_CFG2_CMD,
                    .ecc_status_reg_wr_opcode = WRITE_CFG2_CMD,
                    .ecc_status_reg_addr = {0x00000800, 0x04000800, 0x08000800, 0x0C000800},  /*  Macronix : In each chunk, 1st address is to check status for that 512MB chunk and the subsequent addresses are the ECC failure event addresses
                                                                                                    Chunk 1 : 0x00000800, 0x00000C00, 0x00000D00, 0x00000E00, 0x00000F00
                                                                                                    Chunk 2 : 0x04000800, 0x04000C00, 0x04000D00, 0x04000E00, 0x04000F00
                                                                                                    Chunk 3 : 0x08000800, 0x08000C00, 0x08000D00, 0x08000E00, 0x08000F00
                                                                                                    Chunk 4 : 0x0C000800, 0x0C000C00, 0x0C000D00, 0x0C000E00, 0x0C000F00     */
                    .ecc_fail_chunk_addr = {0x00000C00, 0x00000D00, 0x00000E00, 0x00000F00,
                                            0x04000C00, 0x04000D00, 0x04000E00, 0x04000F00,
                                            0x08000C00, 0x08000D00, 0x08000E00, 0x08000F00,
                                            0x0C000C00, 0x0C000D00, 0x0C000E00, 0x0C000F00 },

                },
    .crc_info = {
                    .crc_supported = TRUE,
                    .crc_dtr_mode_needed = TRUE,
                    .crc_zero_to_enable = FALSE,
                    .crc_init_reg_addr = {0x0000, 0x0500},
                    .crc_status_reg_rd_opcode = READ_CFG2_CMD,
                    .crc_status_reg_wr_opcode = WRITE_CFG2_CMD,
                    .crc_status_reg_addr = 0x80000000,
                    .crc_enable_bmsk = {0x08, 0x90},
                    .crc_err_bmsk = 0x10,
                },
    .dummy_cycle_info = {
                            .dummy_cycle_config_addr = 0x300,
                            .dummy_cycle_reg_rd_opcode = READ_CFG2_CMD,
                            .dummy_cycle_reg_wr_opcode = WRITE_CFG2_CMD,
                            .dummy_cycle_config_bmsk = 0x07,
                            .dummy_config_shift = 0,
                                                            /* {freq,   1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR}
                                                                0 DUMMY CYCLES : INVALID
                                                            */
                            .dummy_clocks_freq_vs_number = {
                                                               {66,         0,       0,         0,          0,        0,         6,         0,         6,         6      },
                                                               {84,         8,       0,         0,          0,        0,         8,         0,         8,         8      },
                                                               {104,        0,       0,         0,          0,        0,         10,        0,         10,        10     },
                                                               {133,        0,       0,         0,          0,        0,         12,        0,         12,        12     },
                                                               {155,        0,       0,         0,          0,        0,         14,        0,         14,        14     },
                                                               {166,        0,       0,         0,          0,        0,         20,        0,         20,        20     },
                                                               {0xFFFFFFFF, 0xFF,    0xFF,      0xFF,       0xFF,     0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           },
                            .dummy_clocks_number_vs_regval = {
                                                                 {6, 0x7},
                                                                 {8, 0x6},
                                                                 {10, 0x5},
                                                                 {12, 0x4},
                                                                 {14, 0x3},
                                                                 {20, 0x0},
                                                                 {0xFF, 0xFF},
                                                             },
                        },
  },

  { /* Micron MT25QU256ABA8E12-0AUT. 256MB - Quad SPI */
    .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    .enter_4byte_mode = ADDR_4BYTE_MODE_6,
    .octal_dtr_ext = 0,

    .access_param = {
                        {
                            .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = SDR_1_1_1_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 0,
                            .reg_read_dummy_cycles = 0,
                            .reg_read_addr_dummy_cycles = 0,
                            .addr_bytes_sfdp = 3,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0,
                            .read_opcode = 0x13,
                            .wait_state = 0,
                            .write_opcode = 0x12,
                            .erase_4kb_opcode = 0x21,
                        },
                        {
                            .read_mode = SDR_4_4_4_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = SDR_4_4_4_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 0,
                            .reg_read_dummy_cycles = 0,
                            .reg_read_addr_dummy_cycles = 0,
                            .addr_bytes_sfdp = 3,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0xAF,
                            .read_opcode = 0xEC,
                            .wait_state = 10,
                            .write_opcode = 0x34,
                            .erase_4kb_opcode = 0x21,
                        }
                    },

    // .mode = 3,  /* SDR_4_4_4_MODE */  // .read_opcode = 0xEC, //.write_opcode = 0x34,  // .wait_state = 10, //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_QUAD_IO,    //.device_transfer_rate = SPI_TRANSFER_STR,
    // .mode = 6,  /* DDR_4_4_4_MODE */  // .read_opcode = 0xEC, //.write_opcode = 0x34,  // .wait_state = 10, //.reg_read_dummy_cycles = 1, //.reg_read_addr_dummy_cycles = 1, //.spi_io_mode = SPI_QUAD_IO,    //.device_transfer_rate = SPI_TRANSFER_DTR,
    // .mode = 0,  /* SDR_1_1_1_MODE */  // .read_opcode = 0x13, //.write_opcode = 0x12,  // .wait_state = 0,  //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_IO_DEFAULT, //.device_transfer_rate = SPI_TRANSFER_STR,
    // .mode = 1,  /* SDR_1_1_4_MODE */  // .read_opcode = 0x6C, //.write_opcode = 0x34,  // .wait_state = 0,  //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_IO_DEFAULT, //.device_transfer_rate = SPI_TRANSFER_STR,
    // .mode = 2,  /* SDR_1_4_4_MODE */  // .read_opcode = 0xEC, //.write_opcode = 0x3E,  // .wait_state = 0,  //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_IO_DEFAULT, //.device_transfer_rate = SPI_TRANSFER_STR,

    .quad_enable_mode = ENABLE_QUAD_MODE_0,
    .enable_444_seq = 0x14,
    .octal_enable_r = 0,
    .spi_io_mode = SPI_QUAD_IO,
    .device_transfer_rate = SPI_TRANSFER_STR,
	.octal_sdr_num_bytes = 1,
    .erase_err_bmsk = 0x20,
    .erase_err_status_reg = 0x70,
    .write_err_bmsk = 0x10,
    .write_err_status_reg = 0x70,
    .freq_khz = 166000, /* Spec supports max 50k */
    .read_max_transfer_in_pages = 0x20000, /* Change to part size */
    .density_in_blocks = 8192, /* PART SIZE, should change for new part */
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x0019BB20, /* This changes with each new part, command 9F*/
    .power_on_delay_in_100us = 8,
    .dqs_sync_qspi_clk = FALSE,
    .ecc_info = {
                    .ecc_default_enabled = FALSE,
                    .ecc_supported = FALSE,
                    .ecc_number_of_chunks = 0,
                    .ecc_enable_bmsk = 0,
                    .ecc_init_reg_addr = 0,
                    .ecc_err_bmsk = 0,
                    .ecc_correction_count_bmsk = 0,
                    .ecc_double_prog_bmsk = 0,
                    .ecc_status_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                    .ecc_status_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                    .ecc_status_reg_addr = {},
                    .ecc_fail_chunk_addr = {},

                },
    .crc_info = {
                    .crc_supported = TRUE,
                    .crc_dtr_mode_needed = FALSE,
                    .crc_zero_to_enable = FALSE,
                    .crc_init_reg_addr = {0xFF, 0xFF},
                    .crc_status_reg_rd_opcode = 0,
                    .crc_status_reg_wr_opcode = 0,
                    .crc_status_reg_addr = 0xFF,
                    .crc_enable_bmsk = {0, 0},
                    .crc_err_bmsk = 0,
                },
    .dummy_cycle_info = {
                            .dummy_cycle_config_addr = 0x00,
                            .dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                            .dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                            .dummy_cycle_config_bmsk = 0xF0,
                            .dummy_config_shift = 4,
                                                           /*  {freq,     1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR}
                                                              0 DUMMY CYCLES : INVALID
                                                           */
                            .dummy_clocks_freq_vs_number = {
                                                               {40,         0,         1,         10,        10,        4,         0,         0,         0,         0      },
                                                               {58,         0,         0,         3,         3,         5,         0,         0,         0,         0      },
                                                               {69,         0,         0,         4,         4,         0,         0,         0,         0,         0      },
                                                               {80,         0,         4,         10,        10,        8,         0,         0,         0,         0      },
                                                               {90,         0,         0,         0,         0,         14,        0,         0,         0,         0      },
                                                               {166,        14,        0,         14,        14,        0,         0,         0,         0,         0      },
                                                               {0xFFFFFFFF, 0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           },
                            .dummy_clocks_number_vs_regval = {
                                                                 {1, 0x01},
                                                                 {3, 0x03},
                                                                 {4, 0x04},
                                                                 {5, 0x05},
																 {6, 0x06},
                                                                 {7, 0x07},
                                                                 {8, 0x08},
                                                                 {10, 0x0A},
                                                                 {14, 0x0E},
                                                                 {0xFF, 0xFF},
                                                             },
                        },
  },

  { /* Micron MT35XU02GCBA1G12-0AUT. 2GB - Octal SPI */
    .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    .enter_4byte_mode = ADDR_4BYTE_MODE_1,
    .octal_dtr_ext = 0,

    .access_param = {
                        {
                            .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = SDR_1_1_1_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 0,
                            .reg_read_addr_dummy_cycles = 8,
                            .addr_bytes_sfdp = 3,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0,
                            .read_opcode = 0x13,
                            .wait_state = 0,
                            .write_opcode = 0x12,
                            .erase_4kb_opcode = 0x21,
                        },
                        {
                            .read_mode = DDR_8_8_8_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = DDR_8_8_8_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 8,
                            .reg_read_addr_dummy_cycles = 8,
                            .addr_bytes_sfdp = 4,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0,
                            .read_opcode = 0xFD,
                            .wait_state = 5,
                            .write_opcode = 0x84,
                            .erase_4kb_opcode = 0x21,
                        }
                    },

    // .mode = 0,   /* SDR_1_1_1_MODE */  // .read_opcode = 0x13, // .wait_state = 0,  // .write_opcode = 0x12
    // .mode = 7,   /* SDR_1_1_8_MODE */  // .read_opcode = 0x7C, // .wait_state = 8,  // .write_opcode = 0x84
    // .mode = 12,  /* DDR_8_8_8_MODE */  // .read_opcode = 0x0C, // .wait_state = 8,  // .write_opcode = 0x12
    // .mode = 8,   /* SDR_1_8_8_MODE */  // .read_opcode = 0xCC, // .wait_state = 8,  // .write_opcode = 0x8E,

    .quad_enable_mode = ENABLE_QUAD_MODE_0,
    .enable_444_seq = 0,
    .octal_enable_r = ENABLE_OCTAL_MODE_7,
    .spi_io_mode = SPI_OCTAL_IO,
    .device_transfer_rate = SPI_TRANSFER_DTR,
	.octal_sdr_num_bytes = 1,
    .erase_err_bmsk = 0x20,
    .erase_err_status_reg = 0x70,
    .write_err_bmsk = 0x10,
    .write_err_status_reg = 0x70,
    .freq_khz = 166000, /* Spec supports max 50k */
    .read_max_transfer_in_pages = 0x100000, /* Change to part size */
    .density_in_blocks = 65536, /* PART SIZE, should change for new part */
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x001C5B2C, /* This changes with each new part, command 9F*/
    .power_on_delay_in_100us = 8,
    .dqs_sync_qspi_clk = FALSE,
    .ecc_info = {
                    .ecc_default_enabled = FALSE,
                    .ecc_supported = FALSE,
                    .ecc_number_of_chunks = 0,
                    .ecc_enable_bmsk = 0,
                    .ecc_init_reg_addr = 0,
                    .ecc_err_bmsk = 0,
                    .ecc_correction_count_bmsk = 0,
                    .ecc_double_prog_bmsk = 0,
                    .ecc_status_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                    .ecc_status_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                    .ecc_status_reg_addr = {},
                    .ecc_fail_chunk_addr = {},

                },
    .crc_info = {
                    .crc_supported = TRUE,
                    .crc_dtr_mode_needed = FALSE,
                    .crc_zero_to_enable = FALSE,
                    .crc_init_reg_addr = {0xFF, 0xFF},
                    .crc_status_reg_rd_opcode = 0,
                    .crc_status_reg_wr_opcode = 0,
                    .crc_status_reg_addr = 0xFF,
                    .crc_enable_bmsk = {0, 0},
                    .crc_err_bmsk = 0,
                },
    .dummy_cycle_info = {
                            .dummy_cycle_config_addr = 0x01,
                            .dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                            .dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                            .dummy_cycle_config_bmsk = 0xFF,
                            .dummy_config_shift = 0,
                                                            /* {freq,      1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR}
                                                               0 DUMMY CYCLES : INVALID
                                                            */
                            .dummy_clocks_freq_vs_number = {
                                                               {16,          0,         0,         0,         0,         0,         1,         3,         0,         3      },
                                                               {50,          0,         0,         0,         0,         0,         3,         5,         0,         6      },
                                                               {66,          0,         0,         0,         0,         0,         4,         6,         0,         6      },
                                                               {86,          0,         0,         0,         0,         0,         5,         8,         0,         8      },
                                                               {133,         3,         0,         0,         0,         0,         8,         13,        0,         13     },
                                                               {166,         20,        0,         0,         0,         0,         20,        20,        0,         17     },
                                                               {200,         0,         0,         0,         0,         0,         0,         0,         0,         20     },
                                                               {0xFFFFFFFF,  0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           },
                            .dummy_clocks_number_vs_regval = {
                                                                 {1, 0x01},
                                                                 {3, 0x03},
                                                                 {4, 0x04},
                                                                 {5, 0x05},
                                                                 {6, 0x06},
                                                                 {7, 0x07},
                                                                 {8, 0x08},
                                                                 {17, 0x11},
                                                                 {20, 0x14},
                                                                 {0xFF, 0xFF},
                                                             },
                        },
  },

  { // ISSI OSPI
    .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    .enter_4byte_mode = ADDR_4BYTE_MODE_1,
    .octal_dtr_ext = 0,


    .access_param = {
                          {
                              .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                      DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                      SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                      DDR_8_8_8_MODE = 12 */
                              .write_mode = SDR_1_1_1_MODE,
                              .addr_bytes = 4,
                              .addr_bytes_reg = 0,
                              .addr_bytes_reg_addr = 4,
                              .reg_read_dummy_cycles = 8,
                              .reg_read_addr_dummy_cycles = 8,
                              .addr_bytes_sfdp = 3,
                              .sfdp_read_dummy_cycles = 8,
                              .read_id_opcode = 0,
                              .read_opcode = 0x13,
                              .wait_state = 0,
                              .write_opcode = 0x12,
                              .erase_4kb_opcode = 0x21,
                          },
                          {
                              .read_mode = DDR_8_8_8_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                      DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                      SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                      DDR_8_8_8_MODE = 12 */
                              .write_mode = DDR_8_8_8_MODE,
                              .addr_bytes = 4,
                              .addr_bytes_reg = 0,
                              .addr_bytes_reg_addr = 4,
                              .reg_read_dummy_cycles = 8,
                              .reg_read_addr_dummy_cycles = 8,
                              .addr_bytes_sfdp = 4,
                              .sfdp_read_dummy_cycles = 8,
                              .read_id_opcode = 0x9E,
                              .read_opcode = 0xFD,
                              .wait_state = 16,
                              .write_opcode = 0x12,
                              .erase_4kb_opcode = 0x21,
                          }
                         },

    // .mode = 0,  /* SDR_1_1_1_MODE */  // .read_opcode = 0x13, // .wait_state = 0,  // .write_opcode = 0x12
    // .mode = 7,  /* SDR_1_1_8_MODE */  // .read_opcode = 0x7C, // .wait_state = 8,  // .write_opcode = 0x84
    // .mode = 8,  /* SDR_1_8_8_MODE */  // .read_opcode = 0xCC, // .wait_state = 16, // .write_opcode = 0x8E

    .quad_enable_mode = ENABLE_QUAD_MODE_0,
    .enable_444_seq = 0,
    .octal_enable_r = ENABLE_OCTAL_MODE_7,
    .spi_io_mode = SPI_OCTAL_IO,
    .device_transfer_rate = SPI_TRANSFER_DTR,
	.octal_sdr_num_bytes = 1,
    .erase_err_bmsk = 0x20,
    .erase_err_status_reg = 0x70,
    .write_err_bmsk = 0x10,
    .write_err_status_reg = 0x70,
    .freq_khz = 166000,
    .read_max_transfer_in_pages = 0x40000,
    .density_in_blocks = 16384,
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x001A5B9D,
    .power_on_delay_in_100us = 8,
    .dqs_sync_qspi_clk = FALSE,
    .ecc_info = {
                    .ecc_default_enabled = FALSE,
                    .ecc_supported = FALSE,
                    .ecc_number_of_chunks = 1,
                    .ecc_enable_bmsk = 0x03, /* Bits 0 and 1 control the enablement of ECC
                                                Bit 2 in 0x0B address set to 0, change based on ECC event that should be detected */
                    .ecc_init_reg_addr = 0x0B,
                    .ecc_err_bmsk = 0x84,
                    .ecc_correction_count_bmsk = 0x78,
                    .ecc_double_prog_bmsk = 0x80,
                    .ecc_status_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                    .ecc_status_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                    .ecc_status_reg_addr = {0x0C},   /* ISSI : 1st address is to check status the subsequent addresses are the ECC failure event addresses for each 512MB chunk
                                                                0x0C, 0x10, 0x0F, 0x0E, 0x0D */
                    .ecc_fail_chunk_addr = {0x10, 0x0F, 0x0E, 0x0D},

                },
    .crc_info = {
                    .crc_supported = FALSE,
                    .crc_dtr_mode_needed = TRUE,
                    .crc_zero_to_enable = TRUE,
                    .crc_init_reg_addr = {0x0B, 0xFF}, /* 0xFF is undefined address */
                    .crc_status_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                    .crc_status_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                    .crc_status_reg_addr = 0x0C,
                    .crc_enable_bmsk = {0x88, 0},
                    .crc_err_bmsk = 0x03,
                },
    .dummy_cycle_info = {
                            .dummy_cycle_config_addr = 0x01,
                            .dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                            .dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                            .dummy_cycle_config_bmsk = 0xFF,
                            .dummy_config_shift = 0,
                                                           /* {freq,      1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR }
                                                              0 DUMMY CYCLES : INVALID
                                                           */
                            .dummy_clocks_freq_vs_number = {
                                                               {16,          0,         0,         0,         0,         0,         1,         3,         0,         3      },
                                                               {50,          0,         0,         0,         0,         0,         3,         5,         0,         6      },
                                                               {66,          0,         0,         0,         0,         0,         4,         6,         0,         6      },
                                                               {86,          8,         0,         0,         0,         0,         5,         8,         0,         8      },
                                                               {133,         3,         0,         0,         0,         0,         8,         13,        0,         13     },
                                                               {166,         20,        0,         0,         0,         0,         20,        20,        0,         17     },
                                                               {200,         0,         0,         0,         0,         0,         0,         0,         0,         20     },
                                                               {0xFFFFFFFF,  0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           },
                            .dummy_clocks_number_vs_regval = {
                                                                 {1, 0x01},
                                                                 {3, 0x03},
                                                                 {4, 0x04},
                                                                 {5, 0x05},
                                                                 {6, 0x06},
                                                                 {7, 0x07},
                                                                 {8, 0x08},
                                                                 {17, 0x11},
                                                                 {20, 0x14},
                                                                 {0xFF, 0xFF},
                                                             },
                        },
  },
  
  { /* Giga Device - Octal SPI */
    .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    .enter_4byte_mode = ADDR_4BYTE_MODE_1,
    .octal_dtr_ext = 0,

    .access_param = {
                        {
                            .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = SDR_1_1_1_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 0,
                            .reg_read_addr_dummy_cycles = 8,
                            .addr_bytes_sfdp = 3,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0,
                            .read_opcode = 0x13,
                            .wait_state = 0,
                            .write_opcode = 0x12,
                            .erase_4kb_opcode = 0x21,
                        },
                        {
                            .read_mode = DDR_8_8_8_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    DDR_8_8_8_MODE = 12 */
                            .write_mode = DDR_8_8_8_MODE,
                            .addr_bytes = 4,
                            .addr_bytes_reg = 0,
                            .addr_bytes_reg_addr = 4,
                            .reg_read_dummy_cycles = 8,
                            .reg_read_addr_dummy_cycles = 8,
                            .addr_bytes_sfdp = 4,
                            .sfdp_read_dummy_cycles = 8,
                            .read_id_opcode = 0,
                            .read_opcode = 0xFD,
                            .wait_state = 5,
                            .write_opcode = 0x84,
                            .erase_4kb_opcode = 0x21,
                        }
                    },

    // .mode = 0,   /* SDR_1_1_1_MODE */  // .read_opcode = 0x0C, // .wait_state = 8,  // .write_opcode = 0x12  // .addr_bytes_sfdp = 3,
    // .mode = 7,   /* SDR_1_1_8_MODE */  // .read_opcode = 0x7C, // .wait_state = 8,  // .write_opcode = 0x84  // .addr_bytes_sfdp = 3,
	// .mode = 8,   /* SDR_1_8_8_MODE */  // .read_opcode = 0xCC, // .wait_state = 8,  // .write_opcode = 0x8E  // .addr_bytes_sfdp = 3,
    // .mode = 12,  /* DDR_8_8_8_MODE */  // .read_opcode = 0xFD, // .wait_state = 8,  // .write_opcode = 0x84  // .addr_bytes_sfdp = 4,
    // .mode = 9,   /* SDR_8_8_8_MODE */  // .read_opcode = 0x7C, // .wait_state = 16, // .write_opcode = 0x84, // .addr_bytes_sfdp = 3,

    .quad_enable_mode = ENABLE_QUAD_MODE_0,
    .enable_444_seq = 0,
    .octal_enable_r = ENABLE_OCTAL_MODE_7,
    .spi_io_mode = SPI_OCTAL_IO,
    .device_transfer_rate = SPI_TRANSFER_DTR,
	.octal_sdr_num_bytes = 1,
    .erase_err_bmsk = 0x20,
    .erase_err_status_reg = 0x70,
    .write_err_bmsk = 0x10,
    .write_err_status_reg = 0x70,
    .freq_khz = 166000,
    .read_max_transfer_in_pages = 0x40000, /* Change to part size */
    .density_in_blocks = 16384, /* PART SIZE, should change for new part */
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x001A68C8, /* This changes with each new part, command 9F*/
    .power_on_delay_in_100us = 8,
    .dqs_sync_qspi_clk = FALSE,
    .ecc_info = {
                    .ecc_default_enabled = FALSE,
                    .ecc_supported = FALSE,
                    .ecc_number_of_chunks = 0,
                    .ecc_enable_bmsk = 0,
                    .ecc_init_reg_addr = 0,
                    .ecc_err_bmsk = 0,
                    .ecc_correction_count_bmsk = 0,
                    .ecc_double_prog_bmsk = 0,
                    .ecc_status_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                    .ecc_status_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                    .ecc_status_reg_addr = {},
                    .ecc_fail_chunk_addr = {},

                },
    .crc_info = {
                    .crc_supported = TRUE,
                    .crc_dtr_mode_needed = FALSE,
                    .crc_zero_to_enable = FALSE,
                    .crc_init_reg_addr = {0xFF, 0xFF},
                    .crc_status_reg_rd_opcode = 0,
                    .crc_status_reg_wr_opcode = 0,
                    .crc_status_reg_addr = 0xFF,
                    .crc_enable_bmsk = {0, 0},
                    .crc_err_bmsk = 0,
                },
    .dummy_cycle_info = {
                            .dummy_cycle_config_addr = 0x01,
                            .dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                            .dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                            .dummy_cycle_config_bmsk = 0xFF,
                            .dummy_config_shift = 0,
                                                            /* {freq,      1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR}
                                                               0 DUMMY CYCLES : INVALID
                                                            */
                            .dummy_clocks_freq_vs_number = {
                                                               {16,          0,         0,         0,         0,         0,         1,         3,         0,         3      },
                                                               {50,          0,         0,         0,         0,         0,         3,         5,         4,         6      },
                                                               {66,          0,         0,         0,         0,         0,         4,         6,         0,         6      },
                                                               {86,          8,         0,         0,         0,         0,         8,         8,         16,        8      },
                                                               {133,         3,         0,         0,         0,         0,         8,         13,        0,         13     },
                                                               {166,         8,         0,         0,         0,         0,         8,         20,        16,        17     },
                                                               {200,         0,         0,         0,         0,         0,         0,         0,         0,         20     },
                                                               {0xFFFFFFFF,  0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           },
                            .dummy_clocks_number_vs_regval = {
                                                                 {1, 0x01},
                                                                 {3, 0x03},
                                                                 {4, 0x04},
                                                                 {5, 0x05},
                                                                 {6, 0x06},
                                                                 {8, 0x08},
																 {16, 0x10},
                                                                 {17, 0x11},
                                                                 {20, 0x14},
                                                                 {0xFF, 0xFF},
                                                             },
                        },
  },

  // { /* Giga Device - Quad SPI */
    // .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    // .enter_4byte_mode = ADDR_4BYTE_MODE_1,
    // .octal_dtr_ext = 0,

    // .access_param = {
                        // {
                            // .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    // DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    // SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    // DDR_8_8_8_MODE = 12 */
                            // .write_mode = SDR_1_1_1_MODE,
                            // .addr_bytes = 4,
                            // .addr_bytes_reg = 0,
                            // .addr_bytes_reg_addr = 4,
                            // .reg_read_dummy_cycles = 0,
                            // .reg_read_addr_dummy_cycles = 8,
                            // .addr_bytes_sfdp = 3,
                            // .sfdp_read_dummy_cycles = 8,
                            // .read_id_opcode = 0,
                            // .read_opcode = 0x13,
                            // .wait_state = 0,
                            // .write_opcode = 0x12,
                            // .erase_4kb_opcode = 0x21,
                        // },
                        // {
                            // .read_mode = SDR_4_4_4_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                    // DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                    // SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                    // DDR_8_8_8_MODE = 12 */
                            // .write_mode = SDR_4_4_4_MODE,
                            // .addr_bytes = 4,
                            // .addr_bytes_reg = 0,
                            // .addr_bytes_reg_addr = 4,
                            // .reg_read_dummy_cycles = 0,
                            // .reg_read_addr_dummy_cycles = 8,
                            // .addr_bytes_sfdp = 3,
                            // .sfdp_read_dummy_cycles = 8,
                            // .read_id_opcode = 0x0,
                            // .read_opcode = 0xEC,
                            // .wait_state = 10,
                            // .write_opcode = 0x34,
                            // .erase_4kb_opcode = 0x21,
                        // }
                    // },

    // // .mode = 3,  /* SDR_4_4_4_MODE */  // .read_opcode = 0xEC, //.write_opcode = 0x34,  // .wait_state = 10, //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_QUAD_IO,    //.device_transfer_rate = SPI_TRANSFER_STR,
    // // .mode = 6,  /* DDR_4_4_4_MODE */  // .read_opcode = 0xEC, //.write_opcode = 0x34,  // .wait_state = 10, //.reg_read_dummy_cycles = 1, //.reg_read_addr_dummy_cycles = 1, //.spi_io_mode = SPI_QUAD_IO,    //.device_transfer_rate = SPI_TRANSFER_DTR,
    // // .mode = 0,  /* SDR_1_1_1_MODE */  // .read_opcode = 0x13, //.write_opcode = 0x12,  // .wait_state = 0,  //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_IO_DEFAULT, //.device_transfer_rate = SPI_TRANSFER_STR,
    // // .mode = 1,  /* SDR_1_1_4_MODE */  // .read_opcode = 0x6C, //.write_opcode = 0x34,  // .wait_state = 0,  //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_IO_DEFAULT, //.device_transfer_rate = SPI_TRANSFER_STR,
    // // .mode = 2,  /* SDR_1_4_4_MODE */  // .read_opcode = 0xEC, //.write_opcode = 0x3E,  // .wait_state = 0,  //.reg_read_dummy_cycles = 0, //.reg_read_addr_dummy_cycles = 0, //.spi_io_mode = SPI_IO_DEFAULT, //.device_transfer_rate = SPI_TRANSFER_STR,

    // .quad_enable_mode = ENABLE_QUAD_MODE_0,
    // .enable_444_seq = 0x2,
    // .octal_enable_r = 0,
    // .spi_io_mode = SPI_QUAD_IO,
    // .device_transfer_rate = SPI_TRANSFER_STR,
	// .octal_sdr_num_bytes = 1,
    // .erase_err_bmsk = 0x20,
    // .erase_err_status_reg = 0x70,
    // .write_err_bmsk = 0x10,
    // .write_err_status_reg = 0x70,
    // .freq_khz = 166000, /* Spec supports max 50k */
    // .read_max_transfer_in_pages = 0x100000, /* Change to part size */
    // .density_in_blocks = 65536, /* PART SIZE, should change for new part */
    // .block_size_in_bytes = 4096,
    // .pages_per_block = 16,
    // .page_size_in_bytes = 256,
    // .device_id = 0x001C66C8, /* This changes with each new part, command 9F*/
    // .power_on_delay_in_100us = 8,
    // .dqs_sync_qspi_clk = FALSE,
    // .ecc_info = {
                    // .ecc_default_enabled = FALSE,
                    // .ecc_supported = FALSE,
                    // .ecc_number_of_chunks = 0,
                    // .ecc_enable_bmsk = 0,
                    // .ecc_init_reg_addr = 0,
                    // .ecc_err_bmsk = 0,
                    // .ecc_correction_count_bmsk = 0,
                    // .ecc_double_prog_bmsk = 0,
                    // .ecc_status_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                    // .ecc_status_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                    // .ecc_status_reg_addr = {},
                    // .ecc_fail_chunk_addr = {},

                // },
    // .crc_info = {
                    // .crc_supported = TRUE,
                    // .crc_dtr_mode_needed = FALSE,
                    // .crc_zero_to_enable = FALSE,
                    // .crc_init_reg_addr = {0xFF, 0xFF},
                    // .crc_status_reg_rd_opcode = 0,
                    // .crc_status_reg_wr_opcode = 0,
                    // .crc_status_reg_addr = 0xFF,
                    // .crc_enable_bmsk = {0, 0},
                    // .crc_err_bmsk = 0,
                // },
    // .dummy_cycle_info = {
                            // .dummy_cycle_config_addr = 0x01,
                            // .dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                            // .dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                            // .dummy_cycle_config_bmsk = 0xFF,
                            // .dummy_config_shift = 0,
                                                           // /*  {freq,     1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR}
                                                              // 0 DUMMY CYCLES : INVALID
                                                           // */
                            // .dummy_clocks_freq_vs_number = {
                                                               // {40,         0,         1,         10,        10,        4,         0,         0,         0,         0      },
                                                               // {58,         0,         0,         3,         3,         5,         0,         0,         0,         0      },
                                                               // {69,         0,         0,         4,         4,         0,         0,         0,         0,         0      },
                                                               // {80,         8,         8,         10,        10,        10,        0,         0,         0,         0      },
                                                               // {90,         0,         0,         0,         0,         10,        0,         0,         0,         0      },
                                                               // {166,        8,         8,         10,        10,        0,         0,         0,         0,         0      },
                                                               // {0xFFFFFFFF, 0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           // },
                            // .dummy_clocks_number_vs_regval = {
                                                                 // {1, 0x01},
                                                                 // {3, 0x03},
                                                                 // {4, 0x04},
                                                                 // {5, 0x05},
                                                                 // {7, 0x07},
                                                                 // {8, 0x08},
                                                                 // {10, 0x0A},
                                                                 // {14, 0x0E},
																 // {20, 0x14},
                                                                 // {0xFF, 0xFF},
                                                             // },
                        // },
  // },

  // { // Winbond W35T51NW. 512Mb 
    // .magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER,
    // .enter_4byte_mode = ADDR_4BYTE_MODE_1,
    // .octal_dtr_ext = 0,


    // .access_param = {
                          // {
                              // .read_mode = SDR_1_1_1_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                      // DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                      // SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                      // DDR_8_8_8_MODE = 12 */
                              // .write_mode = SDR_1_1_1_MODE,
                              // .addr_bytes = 4,
                              // .addr_bytes_reg = 0,
                              // .addr_bytes_reg_addr = 4,
                              // .reg_read_dummy_cycles = 0,
                              // .reg_read_addr_dummy_cycles = 8,
                              // .addr_bytes_sfdp = 3,
                              // .sfdp_read_dummy_cycles = 8,
                              // .read_id_opcode = 0,
                              // .read_opcode = 0x13,
                              // .wait_state = 0,
                              // .write_opcode = 0x12,
                              // .erase_4kb_opcode = 0x21,
                          // },
                          // {
                              // .read_mode = DDR_8_8_8_MODE,  /* SDR_1_1_1_MODE = 0, SDR_1_1_4_MODE = 1, SDR_1_4_4_MODE = 2, SDR_4_4_4_MODE = 3
                                                      // DDR_1_1_4_MODE = 4, DDR_1_4_4_MODE = 5, DDR_4_4_4_MODE = 6, SDR_1_1_8_MODE = 7,
                                                      // SDR_1_8_8_MODE = 8, SDR_8_8_8_MODE = 9, DDR_1_1_8_MODE = 10, DDR_1_8_8_MODE = 11,
                                                      // DDR_8_8_8_MODE = 12 */
                              // .write_mode = DDR_8_8_8_MODE,
                              // .addr_bytes = 4,
                              // .addr_bytes_reg = 0,
                              // .addr_bytes_reg_addr = 4,
                              // .reg_read_dummy_cycles = 8,
                              // .reg_read_addr_dummy_cycles = 8,
                              // .addr_bytes_sfdp = 4,
                              // .sfdp_read_dummy_cycles = 8,
                              // .read_id_opcode = 0,
                              // .read_opcode = 0xFD,
                              // .wait_state = 16,
                              // .write_opcode = 0x84,
                              // .erase_4kb_opcode = 0x21,
                          // }
                         // },

    // // .mode = 5,  /* DDR_1_4_4_MODE */  // .read_opcode = 0xED, // .wait_state = 8,

    // .quad_enable_mode = ENABLE_QUAD_MODE_0,
    // .enable_444_seq = 0,
    // .octal_enable_r = ENABLE_OCTAL_MODE_7,
    // .spi_io_mode = SPI_OCTAL_IO,
    // .device_transfer_rate = SPI_TRANSFER_DTR,
	// .octal_sdr_num_bytes = 1,
    // .erase_err_bmsk = 0x20,
    // .erase_err_status_reg = 0x70,
    // .write_err_bmsk = 0x10,
    // .write_err_status_reg = 0x70,
    // .freq_khz = 166000,
    // .read_max_transfer_in_pages = 0x40000,
    // .density_in_blocks = 16384,
    // .block_size_in_bytes = 4096,
    // .pages_per_block = 16,
    // .page_size_in_bytes = 256,
    // .device_id = 0x001A5BEF,
    // .power_on_delay_in_100us = 8,
    // .dqs_sync_qspi_clk = FALSE,
    // .ecc_info = {
                    // .ecc_default_enabled = FALSE,
                    // .ecc_supported = FALSE,
                    // .ecc_number_of_chunks = 0,
                    // .ecc_enable_bmsk = 0,
                    // .ecc_init_reg_addr = 0,
                    // .ecc_err_bmsk = 0,
                    // .ecc_correction_count_bmsk = 0,
                    // .ecc_double_prog_bmsk = 0,
                    // .ecc_status_reg_rd_opcode = 0,
                    // .ecc_status_reg_wr_opcode = 0,
                    // .ecc_status_reg_addr = {},
                    // .ecc_fail_chunk_addr = {},

                // },
    // .crc_info = {
                    // .crc_supported = FALSE,
                    // .crc_dtr_mode_needed = FALSE,
                    // .crc_zero_to_enable = FALSE,
                    // .crc_init_reg_addr = {0xFF, 0xFF},
                    // .crc_status_reg_rd_opcode = 0,
                    // .crc_status_reg_wr_opcode = 0,
                    // .crc_status_reg_addr = 0xFF,
                    // .crc_enable_bmsk = {0, 0},
                    // .crc_err_bmsk = 0,
                // },
    // .dummy_cycle_info = {
                            // .dummy_cycle_config_addr = 0x01,
                            // .dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD,
                            // .dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD,
                            // .dummy_cycle_config_bmsk = 0xFF,
                            // .dummy_config_shift = 0,
                                                           // /* {freq,      1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR }
                                                               // 0 DUMMY CYCLES : INVALID
                                                           // */
                            // .dummy_clocks_freq_vs_number = {
                                                               // {16,          0,         0,         0,         0,         0,         1,         3,         0,         3      },
                                                               // {50,          0,         0,         0,         0,         0,         3,         5,         0,         6      },
                                                               // {66,          0,         0,         0,         0,         0,         4,         6,         0,         6      },
                                                               // {86,          8,         0,         0,         0,         0,         5,         8,         0,         8      },
                                                               // {133,         3,         0,         0,         0,         0,         8,         13,        0,         13     },
                                                               // {166,         8,         0,         0,         0,         0,         20,        20,        0,         17     },
                                                               // {200,         0,         0,         0,         0,         0,         0,         0,         0,         20     },
                                                               // {0xFFFFFFFF,  0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF   },
                                                           // },
                            // .dummy_clocks_number_vs_regval = {
                                                                 // {1, 0x01},
                                                                 // {3, 0x03},
                                                                 // {4, 0x04},
                                                                 // {5, 0x05},
                                                                 // {6, 0x06},
                                                                 // {8, 0x08},
                                                                 // {17, 0x11},
															     // {20, 0x14},
                                                                 // {22, 0x16},
                                                                 // {0xFF, 0xFF},
                                                             // },
                        // },
  // },


/*
  { // Winbond W25Q256JW. 32MB
    .magic_number = 0xFACEECAF,
    .ddr_support = 0,
    .addr_bytes = 4,
    .read_mode = 2,
    .read_sdr_opcode = 0xEC,
    .read_ddr_opcode = 0,
    .read_sdr_wait_state = 6,
    .read_ddr_wait_state = 0,
    .write_mode = 1,
    .write_sdr_opcode = 0x34,
    .write_ddr_opcode = 0x00,
    .erase_4kb_opcode = 0x21,
    .bulk_erase_size_in_4KB = 16,
    .bulk_erase_opcode = 0xDC,
    .quad_enable_mode = 1,
    .erase_err_bmsk = 0,
    .erase_err_status_reg = 0,
    .erase_status_polling_ms = 5,
    .write_err_bmsk = 0,
    .write_err_status_reg = 0,
    .write_status_polling_usec = 100,
    .freq_khz = 100000,
    .read_max_transfer_in_pages = 0x20000,
    .density_in_blocks = 8192,
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x001960EF,
    .spinor_client_ref_count = 0,
    .power_on_delay_in_100us = 8,
    .dma_enable = TRUE,
  },
  { // Micron MT25QU256ABA8ESF. 32MB
    .magic_number = 0xFACEECAF,
    .ddr_support = 0,
    .addr_bytes = 4,
    .read_mode = 2,
    .read_sdr_opcode = 0xEB,
    .read_ddr_opcode = 0,
    .read_sdr_wait_state = 10,
    .read_ddr_wait_state = 0,
    .write_mode = 1,
    .write_sdr_opcode = 0x32,
    .write_ddr_opcode = 0x00,
    .erase_4kb_opcode = 0x20,
    .bulk_erase_size_in_4KB = 16,
    .bulk_erase_opcode = 0xD8,
    .quad_enable_mode = 0,
    .erase_err_bmsk = 0x7E,
    .erase_err_status_reg = 0x70,
    .erase_status_polling_ms = 5,
    .write_err_bmsk = 0x7E,
    .write_err_status_reg = 0x70,
    .write_status_polling_usec = 100,
    .freq_khz = 166000,
    .read_max_transfer_in_pages = 0x10000,
    .density_in_blocks = 8192,
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x0019BB20,
    .spinor_client_ref_count = 0,
    .power_on_delay_in_100us = 8,
    .dma_enable = TRUE,
  },
  { // Micron MT25QU256AB. 256MB
    .magic_number = 0xFACEECAF,
    .ddr_support = 0,
    .addr_bytes = 4,
    .read_mode = 2,
    .read_sdr_opcode = 0xEB,
    .read_ddr_opcode = 0,
    .read_sdr_wait_state = 10,
    .read_ddr_wait_state = 0,
    .write_mode = 1,
    .write_sdr_opcode = 0x32,
    .write_ddr_opcode = 0x00,
    .erase_4kb_opcode = 0x20,
    .bulk_erase_size_in_4KB = 16,
    .bulk_erase_opcode = 0xD8,
    .quad_enable_mode = 0,
    .erase_err_bmsk = 0x7E,
    .erase_err_status_reg = 0x70,
    .erase_status_polling_ms = 5,
    .write_err_bmsk = 0x7E,
    .write_err_status_reg = 0x70,
    .write_status_polling_usec = 100,
    .freq_khz = 166000,
    .read_max_transfer_in_pages = 0x10000,
    .density_in_blocks = 0xFFFE,
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x0020BB20,
    .spinor_client_ref_count = 0,
    .power_on_delay_in_100us = 8,
    .dma_enable = TRUE,
  },
  {  // Micron MT25QU512ABA. 512MB
    .magic_number = 0xFACEECAF,
    .ddr_support = 0,
    .addr_bytes = 4,
    .read_mode = 2,
    .read_sdr_opcode = 0xEB,
    .read_ddr_opcode = 0,
    .read_sdr_wait_state = 10,
    .read_ddr_wait_state = 0,
    .write_mode = 1,
    .write_sdr_opcode = 0x32,
    .write_ddr_opcode = 0x00,
    .erase_4kb_opcode = 0x20,
    .bulk_erase_size_in_4KB = 16,
    .bulk_erase_opcode = 0xD8,
    .quad_enable_mode = 0,
    .erase_err_bmsk = 0x7E,
    .erase_err_status_reg = 0x70,
    .erase_status_polling_ms = 5,
    .write_err_bmsk = 0x7E,
    .write_err_status_reg = 0x70,
    .write_status_polling_usec = 100,
    .freq_khz = 166000,
    .read_max_transfer_in_pages = 0x10000,
    .density_in_blocks = 0xFFFE,
    .block_size_in_bytes = 4096,
    .pages_per_block = 16,
    .page_size_in_bytes = 256,
    .device_id = 0x0020BA20,
    .spinor_client_ref_count = 0,
    .power_on_delay_in_100us = 8,
    .dma_enable = TRUE,
  },
  */
};

#endif

/**********************************************************
 * Get the pointer to the supported NOR devices and their parameters
 *
 * @return void* [OUT]
 *   Pointer to the table that contains the Flash's NOR config parameters
 *   needed for spinor operations
 *
 **********************************************************/
void* spinor_get_config_table_struct(void)
{
  return (void *)&spinor_cfg_table;
}


