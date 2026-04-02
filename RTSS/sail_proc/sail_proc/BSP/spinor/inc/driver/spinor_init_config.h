#ifndef __SPINOR_INIT_CONFIG_H__
#define __SPINOR_INIT_CONFIG_H__
/*
===========================================================================
*/
/**
    @file  spinor_init_config.h
    @brief This file provides definitions for the spinor init config implementations

*/
/*
    ===========================================================================

    Copyright (c) 2017,2020-2024 Qualcomm Technologies, Inc.
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

#include "spinor_api.h"
#include "spinor_clock_gpio.h"

#define SPINOR_INIT_TABLE_MAGIC_NUMBER 0x46474643

#define SPINOR_INIT_TABLE_VERSION_NUMBER 0x2

#define SPINOR_INIT_CFG_MAGIC_NUMBER 0xFACEECAF

#define SPINOR_INIT_POWER_ON_DELAY_IN_100US    0x8U
typedef enum
{
    DEFAULT_ACCESS_PARAM=0,
    PERF_MODE_ACCESS_PARAM,
    MAX_ACCESS_PARAM
}access_param_mode_type;

typedef struct
{
  uint8 read_mode;                      /* Read Mode: Command-Address-Data */
  uint8 write_mode;                     /* Write Mode: Command-Address-Data */
  uint8 addr_bytes;                     /* 3 or 4 Bytes Addressing Mode for memory access read/write/erase*/
  uint8 addr_bytes_reg;                 /* Number of addr bytes for Register read/write command */
  uint8 addr_bytes_reg_addr;            /* Number of addr bytes fo Register read/write with address command */
  uint8 reg_read_dummy_cycles;          /* Dummy cycles needed for read status/control register for volatile registers */
  uint8 reg_read_addr_dummy_cycles;     /* Dummy cycles needed for read status/control register for volatile registers with addr specified */
  uint8 addr_bytes_sfdp;                /* SFDP Command in 8D-8D-8D mode – Address Bytes */
  uint8 sfdp_read_dummy_cycles;         /* SFDP Command in 8D-8D-8D mode – Dummy Cycles */
  uint8 read_id_opcode;                 /* Opcode for the multiple IO read ID operation
                                           If there is multiple I/O read ID opcode in the data sheet use that opcode
                                           If not use the default READ_ID_CMD 0x9F or set this to 0 to use the default */
  uint8 read_opcode;                    /* Opcode for the read Operation and mode as per data sheet */
  uint8 wait_state;                     /* Total of dummy cycles to wait states for the operation and mode as per data sheet */
  uint8 write_opcode;                   /* Opcode for the write Operation and mode as per data sheet */
  uint8 erase_4kb_opcode;               /* Opcode for the 4KB Block erase Operation and mode as per data sheet  */
  uint8 erase_256kb_opcode;             /* Opcode for the 256KB Block erase Operation and mode as per data sheet  */
}spinor_access_param_type;

typedef struct
{
  boolean ecc_default_enabled;            /* Bit to tell if the ECC is initialized by default */
  boolean ecc_supported;                  /* Bit to tell if the vendor supports ECC */
  uint8   ecc_number_of_chunks;           /* Bit to tell us the number of ECC chunks supported */
  uint8   ecc_enable_bmsk;                /* Status BIT(s) indicating if ECC Check is enabled (only when ecc_supported is TRUE) */
  uint32  ecc_init_reg_addr;              /* Register ddress to initialize ECC */
  uint8   ecc_err_bmsk;                   /* Status BIT(s) indicating if ECC Event has occured */
  uint8   ecc_correction_count_bmsk;      /* Status BIT(s) indicating the number of 1-bit ECC correction events that occured */
  uint8   ecc_double_prog_bmsk;           /* Status BIT(s) indicating if double programming has occured */
  uint32  ecc_status_reg_rd_opcode;       /* Command to read the register with ECC related bits */
  uint32  ecc_status_reg_wr_opcode;       /* Command to write to the register with ECC related bits */
  uint32  ecc_status_reg_addr[4];         /* Register address to check the ECC status of individual 512MB chunks */
  uint32  ecc_fail_chunk_addr[16];        /* Register address to check where the ECC event has occured */
}spinor_ecc_info_type;

typedef struct
{
  boolean crc_supported;                   /* Bit to tell if the vendor supports CRC */
  boolean crc_dtr_mode_needed;             /* Bit to tell if the vendor needs DTR mode to implement CRC */
  boolean crc_zero_to_enable;              /* TRUE if the vendor needs to write 0 the enable_bmsk to enable CRC */
  uint32  crc_init_reg_addr[2];            /* Register ddress to initialize ECC */
  uint32  crc_status_reg_rd_opcode;        /* Command to read the register with CRC related bits */
  uint32  crc_status_reg_wr_opcode;        /* Command to write to the register with CRC related bits */
  uint32  crc_status_reg_addr;             /* Register address to check the CRC status */
  uint8   crc_enable_bmsk[2];              /* Status BIT(s) indicating if CRC check is enabled */
  uint8   crc_err_bmsk;                    /* Status BIT(s) indicating if CRC error has occured */
}spinor_crc_info_type;

typedef struct
{
  uint32  dummy_cycle_config_addr;               /* Register ddress to configure dummy cycles */
  uint32  dummy_cycle_reg_rd_opcode;             /* Command to read the register to configure dummy cycles */
  uint32  dummy_cycle_reg_wr_opcode;             /* Command to write to the register to configure dummy cycles */
  uint8   dummy_cycle_config_bmsk;               /* BIT(s) used to configure dummy cycles in the required register */
  uint8   dummy_config_shift;                    /* Bitwise shift to be done to configure dummy cycles */
  uint32  dummy_clocks_freq_vs_number[8][10];    /* Frequency vs dummy cycles */
  uint32  dummy_clocks_number_vs_regval[10][2];   /* dummy cycles vs register value */
}spinor_dummy_cycle_info_type;

typedef struct __attribute__((__packed__))
{
  uint32  magic_number;                   /* Magic number used to indicate the structure is valid */
  uint8   enter_4byte_mode;               /* Enter 4-byte address mode for SPI */
  uint8   octal_dtr_ext;                  /* Octal DTR (8D-8D-8D) Command and Command Extension */
                                          /* 00b: The Command Extension is the same as the Command.
                                             (The Command / Command Extension has the same value for the whole clock period.)
                                             01b: Command Extension is the inverse of the Command.
                                             The Command Extension acts as a confirmation of the Command
                                             10b: Reserved
                                             11b: Command and Command Extension forms a 16 bit command word. */

  spinor_access_param_type access_param[MAX_ACCESS_PARAM];  /* Flash access operation parameters  */

  uint8   quad_enable_mode;               /* Quad Enable Requirements (QER) as defined in the JEDEC Standard No. 216A Document */
  uint8   enable_444_seq;                 /* 4-4-4 mode Enable Sequence */
  uint8   octal_enable_r;                 /* Octal Enable Requirment and way to enable 8-8-8 from 1-1-1 */
  uint8   spi_io_mode;                    /* SPI IO Mode to enable - User configurable to
                                             select different options based on needs and what is supported by the vendor
                                             Default xSPI/Dual/Quad/Octal
                                             0 - SPI_IO_DEFAULT,
                                             1 - SPI_DUAL_IO,
                                             2 - SPI_QUAD_IO,
                                             3 - SPI_OCTAL_IO */

  uint8  device_transfer_rate;            /* Transfer rate type to be used for
                                             the device based on needs and what is supported by the vendor
                                             0 - SPI_TRANSFER_STR,     --> Single Transfer Rate
                                             1 - SPI_TRANSFER_DTR      --> Dual Transfer Rate */
  uint8  octal_sdr_num_bytes;             /* Number of bytes for octal SDR */

  uint8   erase_err_bmsk;                 /* Status BIT(s) in the erase_err_status_reg Register indicating if there's erase error condition */
  uint8   erase_err_status_reg;           /* register address used for polling the erase status */
  uint8   write_err_bmsk;                 /* Status BIT(s) in the write_err_status_reg Register indicating if there's write error condition */
  uint8   write_err_status_reg;           /* register address used for polling the write status */
  uint32  freq_khz;                       /* Max supported Frequency */
  uint32  read_max_transfer_in_pages;     /* This field indicates the maximum Read transfer size in unit of page (256 bytes per page) */
  uint32  density_in_blocks;              /* Device density in unit of Blocks */
  uint32  block_size_in_bytes;            /* Block density in bytes */
  uint32  pages_per_block;                /* No of pages per block */
  uint32  page_size_in_bytes;             /* No of bytes per page */
  uint32  device_id;                      /* Device ID when query with Device Read ID command 0x9F */
  uint8   power_on_delay_in_100us;        /* Power On Reset delay in 100us unit */
  boolean dqs_sync_qspi_clk;              /* TRUE - DQS in sync with qspi_clk;
                                             FALSE - DQS half cycle shifted with qspi_clk (inverted/delayed DQS) */
  spinor_ecc_info_type ecc_info;                   /* Vendor specific ECC parameters */
  spinor_crc_info_type crc_info;                   /* Vendor specific CRC parameters */
  spinor_dummy_cycle_info_type dummy_cycle_info;   /* Dummy cycle configuration parameters */
  spinor_gpio_data gpio_info;                      /* Stores the GPIO pin info */
  spinor_secmaptype secmapdata[5];        /* Sector Map Data */
  uint32_t secMapAlignmentAddr;           /* Alignment address based on the hybrid sector map */
  uint32 octal_ddr_cmd_seq[4][8];         /* Array to store the length (1byte), opcode (1byte), address (3bytes) and data(3bytes) for the 4 octal DDR command sequences */
  uint8  device_type;                     /* Specifies the device type: 
                                             0 -> SFDP_BUS_QSPI -> Quad device
                                             1 -> SFDP_BUS_OSPI -> Octal device */
} spinor_config_data;


typedef struct __attribute__((__packed__))
{
  uint32 magic_no;
  uint32 total_entries;
  uint32 version_no;
} spinor_init_config_table_type;

void* spinor_get_config_table_struct(void);
#endif /* __SPINOR_INIT_CONFIG_H__ */
