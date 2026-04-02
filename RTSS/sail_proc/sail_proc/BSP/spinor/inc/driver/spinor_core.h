#ifndef __SPINOR_CORE_H__
#define __SPINOR_CORE_H__
/*
===========================================================================
*/
/**
    @file  spinor_core.h
    @brief This file provides definitions for the spinor support functions

*/
/*
    ===========================================================================

    Copyright (c) 2017,2019,2020-2025 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_core.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_api.h"
#include "spinor_init_config.h"

/* SFDP's Dword 15th Bits[20:22]. QER Field.*/
#define  ENABLE_QUAD_MODE_0  0x0
#define  ENABLE_QUAD_MODE_1  0x1
#define  ENABLE_QUAD_MODE_2  0x2
#define  ENABLE_QUAD_MODE_3  0x3
#define  ENABLE_QUAD_MODE_4  0x4
#define  ENABLE_QUAD_MODE_5  0x5
#define  ENABLE_QUAD_MODE_6  0x6
#define  ENABLE_QUAD_MODE_7  0x7

/* SFDP's Dword 19th Bits[20:22]. Octal Enable Requirements Field.*/
#define  ENABLE_OCTAL_MODE_0  0x0      /* Device does not have an Octal Enable bit. */
#define  ENABLE_OCTAL_MODE_1  0x1      /* Octal Enable is bit 3 of status register 2. It is set via Write status register 2 instruction 31h with one data byte where bit 3 is one.
                                          It is cleared via Write status register 2 instruction 3Eh with one data byte where bit 3 is zero.
                                          The status register 2 is read using instruction 65h with address byte 02h and one dummy byte. */

/* Reserved bits per JESD216D Spec. Repurposing the reserved bits in SW to enable Octal Mode STR and DTR using bit 8:4 in 19th Dword of the Basic Parameter table */

/* 8s-8s-8s mode enable sequences
   This field describes the supported methods to enter 8-8-8 mode from 1-1-1 mode.
   x_xx1xb: x_xx1xb: Issue instruction 06h (WREN), then issue instruction E8h
   x_x1xxb: Issue instruction 06h (WREN), then issue instruction 72h (Write CFG Reg 2), Address = 00000000h, Data = 01h (8S-8S-8S) or 02h (8D-8D-8D) */

#define  ENABLE_OCTAL_MODE_2  0x2  /* Issue instruction 06h (WREN), then issue instruction E8h */
#define  ENABLE_OCTAL_MODE_3  0x3
#define  ENABLE_OCTAL_MODE_4  0x4  /* Issue instruction 06h (WREN), then issue instruction 72h (Write CFG Reg 2), Address = 00000000h, Data = 01h (8S-8S-8S) or 02h (8D-8D-8D) */
#define  ENABLE_OCTAL_MODE_5  0x5
#define  ENABLE_OCTAL_MODE_6  0x6
#define  ENABLE_OCTAL_MODE_7  0x7  /* for Micron WRITE VOLATILE CONFIGURATION REGISTER Instruction 81h with Address= 0 and data = E7h (Octal DDR) */

#define PROG_ERASE_WRITE_BUSY_BMSK   0x01
#define READ_STATUS_BUSY_MASK        0x01
#define STATUS_WR_EN_MASK            0x02 /* Write Enable Latch status */


#define RESET_ENABLE_CMD      0x66
#define RESET_CMD             0x99

#define READ_STATUS_CMD       0x05
#define READ_STATUS_2_CMD     0x3F
#define WRITE_STATUS_2_CMD    0x3E
#define WRITE_ENABLE_CMD      0x06
#define READ_ID_CMD           0x9F
#define READ_SFDP_CMD         0x5A
#define READ_CFG1_CMD         0x35        /* Micron/Spansion: Enable QE */
#define READ_FLAG_STATUS_CMD  0x70
#define READ_SECURITY_CMD     0x2B
#define WRITE_STATUS_CMD      0x01
#define ENTER_4B_ADDR_CMD     0xB7
#define READ_CFG_REG_CMD      0x15

#define READ_CFG_CMD          0x65
#define WRITE_CFG_CMD         0x71

#define ENTER_DPD             0xB9
#define EXIT_DPD              0xAB

#define ISSUE_INSTR_35_CMD    0x35
#define ISSUE_INSTR_38_CMD    0x38

#define READ_ENHANCED_VOL_CFG_CMD     0x65
#define WRITE_ENHANCED_VOL_CFG_CMD    0x61

#define READ_OCTAL_EN_STATUS_2_CMD     0x65
#define WRITE_OCTAL_EN_STATUS_2_CMD    0x31
#define CLEAR_OCTAL_EN_STATUS_2_CMD    0x3E

#define ENABLE_8S_8S_8S_MODE_SEQ_CMD   0xE8
#define CLEAR_ERR_REGS                 0xB6
#define CLEAR_FLAG_STATUS_REG          0x50

#define READ_CFG2_CMD                  0x71
#define WRITE_CFG2_CMD                 0x72
#define READ_VOLATILE_CFG_CMD          0x85        /* Micron and ISSI */
#define WRITE_VOLATILE_CFG_CMD         0x81

#define MAX_PAGE_PER_WRITE             1
#define READ_STATUS_POLLING_USEC       1

#define FLASH_INIT_TIMEOUT_USEC   1000000 /* usec unit - 1 second timeout based on the worst case reset recovery time incase of a reset during a 32KB operation */
#define FLASH_INIT_POLLING_USEC   1000    /* 1ms polling */

#define DEVICE_ID_LEN_IN_BYTES   3

#define BIT_0  0x1
#define BIT_1  0x2
#define BIT_2  0x4
#define BIT_3  0x8
#define BIT_4  0x10
#define BIT_5  0x20
#define BIT_6  0x40
#define BIT_7  0x80

/*Default 4KB Block, 256 bytes per page */
#define PAGES_PER_BLOCK  16
#define BLOCK_SIZE_IN_BYTES  4096

/* Check for integer overflows */
#define INT_OVERFLOW(x,y) (x + y < x)

#define SPINOR_16MB_IN_BYTES   0x1000000
#define SPINOR_16MB_IN_BLOCKS  0x1000
#define SPINOR_DEVICE_MEM_START_ADDR 0x000

/* Error Check operation types */
#define ERASE_OPERATION   1
#define WRITE_OPERATION   2

#define DEFAULT_QSPI_SDR_8MHZ   8000
#define SPINOR_QSPI_SDR_96MHZ    96000
#define SPINOR_QSPI_DDR_64MHZ    64000

#define SPINOR_ERR_LOG_SIZE  16

/* Control for Enabling DMA for SPINOR accesses. Set to false to disable DMA */
#define SPINOR_DMA_EN_CTRL TRUE
#define SPINOR_ECC_EN_CTRL FALSE
#define SPINOR_CRC_EN_CTRL FALSE

/* Flag for enabling SPINOR ECC/CRC functions */
//#define SPINOR_ECC_ENABLE
//#define SPINOR_CRC_ENABLE

/* Flash Error Log */
typedef struct
{
  uint8  spinor_err_index;
  uint16 spinor_err_codes[SPINOR_ERR_LOG_SIZE];
  uint32 read_unaligned_count;
  uint32 write_unaligned_count;
  uint32 spinor_status;
  uint32 vendor_status;
} spinor_logs;

typedef enum enter_4byte_addr_mode_t
{
  ADDR_4BYTE_NOT_SUPPORTED,
  ADDR_4BYTE_MODE_1,      /* issue instruction B7h (preceding write enable not required) */
  ADDR_4BYTE_MODE_2,      /* issue write enable instruction 06h, then issue instruction B7h */
  ADDR_4BYTE_MODE_3,      /* 8-bit volatile extended address register used to define
                             A[31:24] bits.  Read with instruction C8h.  ... */
  ADDR_4BYTE_MODE_4,      /* 8-bit volatile bank register used to define A[30:A24]
                             bits. MSB (bit[7]) is used to enable/disable 4-byte ... */
  ADDR_4BYTE_MODE_5,      /* A 16-bit nonvolatile configuration register controls ... */
  ADDR_4BYTE_MODE_6,      /* Supports dedicated 4-Byte address instruction set. */
  ADDR_4BYTE_MODE_7,      /* Always operates in 4-Byte address mode */
  ADDR_4BYTE_MODE_MAX,
}enter_4byte_addr_mode;

/* Defines the enum for the IO mode to select for device */
typedef enum spinor_io_type_t
{
  SPI_IO_DEFAULT,         /* Default 1 lane */
  SPI_DUAL_IO,            /* Dual lane IO */
  SPI_QUAD_IO,            /* Quad Lane IO */
  SPI_OCTAL_IO            /* Octal Lane IO */
}spinor_io_type;

/* Defines the enum for the mode to select for device */
typedef enum spinor_mode_t
{
    SPI_DEFAULT_SDR = 0,  /* Defaults to single SPI */
    SPI_DUAL_SDR,         /* Dual SPI SDR mode */
    SPI_QUAD_SDR,         /* Quad SPI SDR mode */
    SPI_OCTAL_SDR,        /* Octal SPI SDR mode */
    SPI_DEFAULT_DDR,      /* single SPI DDR mode*/
    SPI_DUAL_DDR,         /* Dual SPI DDR mode */
    SPI_QUAD_DDR,         /* Quad SPI DDR mode */
    SPI_OCTAL_DDR,        /* Octal SPI DDR mode */
}spinor_mode_type;

/* Defines for the enum for the Transfer rate for the device */
typedef enum spinor_transfer_type_t
{
  SPI_TRANSFER_STR,        /* Single Transfer Rate */
  SPI_TRANSFER_DTR,        /* Dual Transfer Rate */
  SPI_TRANSFER_MAX
}spinor_transfer_type;

/* Defines for the enum for the Init states of the device */
typedef enum spinor_init_type_t
{
  SPINOR_INIT_NOT_DONE,          /* Init not done = 0 */
  SPINOR_INIT_FAIL,              /* Init fail */
  SPINOR_INIT_PARTIALLY_DONE,    /* Init partitally done */
  SPINOR_INIT_SLEEP_DONE,        /* SPINOR init sleep done */
  SPINOR_INIT_DONE,              /* Init done */
}spinor_init_type;

/* Defines the structure for storing the address of the ECC failure event */
typedef struct
{
  uint8   chunk_number;             /* Which 512MB chunk has the ECC event */
  uint32  ECC_fail_event_address;   /* Address of the failure event */
  uint8   ECC_event_type;           /* Type of ECC event : 1 bit/2 bit error */
}ECC_address_details;

typedef struct
{
	uint64 spinor_core_read_time;
	uint64 spinor_core_write_time;
	uint64 spinor_core_erase_time;
}spinor_profiling_data;

typedef struct
{
  uint8 nor_init_done;                    /* Stages of driver Initialization:
                                             SPINOR_INIT_NOT_DONE         = 0 -> Init not done
                                             SPINOR_INIT_FAIL             = 1 -> Init fail 
                                             SPINOR_INIT_PARTIALLY_DONE   = 2 -> Init partitally done
                                             SPINOR_INIT_DONE             = 3 -> Init done  */
  uint32  cmd_eng_poll_timeout_us;        /* CMD Engine timeout for flush chain */
  uint32  erase_timeout;                  /* Erase transaction timeout */
  uint32  write_timeout;                  /* Write transaction timeout */
  uint32  read_timeout;                   /* Read transaction timeout */
  uint32  read_status_timeout;            /* Register/Other transaction timeout */
  uint16  status_polling_usec;            /* Status polling timeout */
  uint32 disable_timeouts;               /* If set, timeouts in SPINOR will be disabled */
  boolean dma_enable;
  boolean dll_config_en;
  uint8   ref_count;
  spinor_logs debug_log;
  spinor_config_data *config_data;        /* Device configuration data pointer */
  spinor_mode_type mode_enabled;          /* Current Mode enabled */
  ECC_address_details ECC_addresses[4];   /* Array of structs to store ECC fail event address details */
#ifdef SPINOR_PROFILE_ENABLED
  spinor_profiling_data profiling_time;   /* Struct to record read, write and erase profiling time */
#endif /* SPINOR_PROFILE_ENABLED */
  boolean enable_ecc;                     /* Global Flag to tell if ECC should be enabled*/
  boolean ecc_enabled_status_local;       /* Local Flag to keep track of whether ECC is enabled or not */
  boolean sw_reset_done;                  /* Flag to check if a SW device reset was done or not */
  boolean perfmode_enabled;               /* Flag to determine default mode or perf mode */
  boolean enable_crc;                     /* Global Flag to tell if CRC should be enabled*/
  boolean four_byte_mode_enabled;         /* Flag to check if 4-byte address mode has been enabled */
  boolean octal_mode_enabled;             /* Flag to check if octal mode has been enabled */
  boolean disable_data_dummy_cycle_recfg; /* If set, will not reconfigure the data read dummy cycle reconfiguration */
}spinor_drv_info;

extern spinor_drv_info *p_spinor_dev;

#ifndef TRUE
#define TRUE   1   /* Boolean true value. */
#endif

#ifndef FALSE
#define FALSE  0   /* Boolean false value. */
#endif

#ifndef NULL
#define NULL  0
#endif

/**********************************************************
 * Sets 4-byte address mode
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_device_set_4byte_address_mode(void);

/**********************************************************
 * Switch the mux control from SAIL to MD.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_reconfig_mux(void);

/**********************************************************
 * De-initializes the spinor nor driver
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_deinit (void);

/**********************************************************
 * Initializes the spinor driver info structure.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 *********************************************************/
SPINOR_STATUS spinor_drv_info_init (int type);

/**********************************************************
 * Initializes the spinor controller HW
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_controller_init (boolean is_crash_dbg);

/**********************************************************
 * Initializes the spinor driver.
 * Invokes spinor_core_init() to initialize spinor sub modules
 *
 * @param spinor_config_table [IN]
 *   RAM table containing config data for supported spinor devices
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_init(int type, void *spinor_config_table, spinor_hardcode_data_mode *hardcoded_data_mode);

/**********************************************************
 * Initializes the ECC and CRC parameters
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_ecc_crc_init(void);

/**********************************************************
 * De-initializes the spinor driver.
 * Free up resources used by the spinor driver
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_deinit (void);

/**********************************************************
 * Enable ECC Checks for operations.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_core_enable_ecc_check(void);

/**********************************************************
 * Disable ECC Checks for operations.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_core_disable_ecc_check(void);

/**********************************************************
 * Read SFDP Signature.
 *
 * @signature [OUT]
 *   Stores the sfdp signature read.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_core_read_sfdp_signature(uint32* signature);

/**********************************************************
 * clears ECC regs
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_core_clear_ECC_regs (void);

/**********************************************************
 * checks ECC status
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_core_check_ECC_Status (void);

/**********************************************************
 * Performs a complete shutdown of the core
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_core_shutdown(boolean is_crash_dbg_flag);

/**********************************************************
 * Enables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_enable_crc_check(void);

/**********************************************************
 * Disables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_disable_crc_check(void);

/**********************************************************
 * Checks the CRC status
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_check_CRC_Status (void);

/**********************************************************
 * Clears the CRC registers
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_clear_CRC_regs (void);

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_is_device_alive(void);

/**********************************************************
 * Performs SDR DLL training
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_SDR_DLL_training(void);

/**********************************************************
 * Performs DDR DLP training
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_DDR_DLP_training(void);

/**********************************************************
 * Enable spinor one lane in PBL mode configuration at 19.2MHz bus frequence
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_init_one_lane(boolean is_crash_dbg);

/**********************************************************
 * Enable spinor one lane in PBL mode configuration at 19.2MHz bus frequence
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_init_perf(void *spinor_config_table, boolean use_pbl);

/**********************************************************
 * Look up table to find the spinor config info.
 *
 * @param spinor_config_tbl [IN]
 *   Table containing config data for supported spinor devices
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_device_lookup (boolean is_crash_dbg, void *spinor_config_tbl, spinor_hardcode_data_mode *hardcoded_data_mode);

/**********************************************************
 * Runs the 8D-8D-8D sequence
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_run_octal_ddr_sequence(void);

SPINOR_STATUS spinor_core_device_perf_config(void);
#ifdef NORPVL_ENB
SPINOR_STATUS spinor_core_change_params(uint32 thread_delay_us, uint32_t max_tranfr_pg_size);
#endif
#endif /* __SPINOR_CORE_H__ */
