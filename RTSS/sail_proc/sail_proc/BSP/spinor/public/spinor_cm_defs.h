#ifndef __SPINOR_CM_DEFS_H__
#define __SPINOR_CM_DEFS_H__

/*
===========================================================================
*/
/**
    @file  spinor_cm_defs.h
    @brief Public interface's common data structures and macros for the Spinor Drivers.
           This file describes the spinor external interface's common data structures and macros.

*/
/*
    ===========================================================================

    Copyright (c) 2021-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/public/spinor_cm_defs.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/**  \mainpage spinor Functional Overview
 *
 * The spinor driver provides a high-level interface for clients, such
 * as bootloaders, file systems, and tools to interact with the spinor devices. It
 * handles the spinor device specifics and abstracts with the client from the device-
 * specific algorithms, interfaces, and OS adaptations.
 *
 * \n
 *
 */

#include "types.h"

#define SPINOR_BYTES_ALIGNMENT             16

/** Spinor API operation status */
#define SPINOR_DEVICE_OK_NOT_DONE          1    /**< Operation flow passed but not completed yet */
#define SPINOR_DEVICE_DONE                 0    /**< Operation passed */
#define SPINOR_DEVICE_FAIL                (-1)  /**< Operation failed */
#define SPINOR_DEVICE_NOT_SUPPORTED       (-2)  /**< Device/operation not supported */
#define SPINOR_DEVICE_INVALID_PARAMETER   (-3)  /**< API parameters invalid */
#define SPINOR_DEVICE_IMAGE_NOT_FOUND     (-4)  /**< FW Image ID not found */
#define SPINOR_DEVICE_NOT_FOUND           (-5)  /**< Device not found on supported device list */
#define SPINOR_ACCESS_DENIED              (-6)  /**< Access to the given region is denied by software */
#define SPINOR_ACCESS_ECC_ERROR           (-7)  /**< ECC not recoverable error */
#define SPINOR_ACCESS_ECC_WARN            (-8)  /**< ECC one bit recoverable warning */
#define SPINOR_ACCESS_CRC_ERROR           (-9)  /**< CRC not recoverable error */
#define SPINOR_ACCESS_NO_BUS             (-10)  /**< SPI bus is not available */
#define SPINOR_NO_FD                     (-11)  /**< Run out of fd */
#define SPINOR_ALIGNMENT                 (-12)  /**< alignment error */
#define SPINOR_DEVICE_MISSING_REQUIRED_SFDP_TABLE    (-13)  /**< one or more required tables missing. Recoverable if static configuration is available */
#define SPINOR_DEVICE_NULL_POINTER                   (-14)  /**< NULL pointer, SW bug or data corruption */
#define SPINOR_DEVICE_INCONSISTENT       (-15)  /**< Data inconsistent */
#define SPINOR_OPERATION_TIMEOUT         (-16)  /**< Operation timed out */
#define SPINOR_ERASE_BLOCK_INVALID       (-17)  /**< Invalid Erase block range passed */

typedef int SPINOR_STATUS;                     /**< Error status values used in SPINOR driver */
typedef void *spinor_handle_t;

typedef enum {
    SPINOR_INIT_TYPE_DEFAULT,                  /**< default initialization type, used in boot time init */
    SPINOR_INIT_TYPE_RAM_DUMP,                 /**< RAM dump initialization type, used in SDI module to re-init
                                                *   the SPI NOR driver for RAM dump */
    SPINOR_INIT_TYPE_MAX_NUM
} spinor_init_type_t;

typedef enum {
    SPINOR_USER_TYPE_EL1,
    SPINOR_USER_TYPE_EL1_SUPER,
    SPINOR_USER_TYPE_EL2,
    SPINOR_USER_TYPE_BOOT_LOADER,
    SPINOR_USER_TYPE_CRASH_DBG,
    SPINOR_USER_TYPE_OTA,
    SPINOR_USER_TYPE_MAX
} eSpinorUserType;

typedef enum {
    SPINOR_PROTECT_NONE = 0,                   /**< default Protection type, No Read/Write/Erase protection */
    SPINOR_PROTECT_WR,                         /**< Only Read access. Write/Erase protection */
    SPINOR_PROTECT_RD,                         /**< Only Write/Erase access. Read protection */
    SPINOR_PROTECT_RDWR,                       /**< Read/Write/Erase protection */
    SPINOR_PROTECT_MAX                         /**< Max value for Protection */
} eSpinorProtectType;


/** Spinor client device data */
struct spinor_info
{
  char  device_name[32];              /**< Device name string */
  uint32 maker_id;                     /**< Manufacturer Identification */
  uint32 device_id;                    /**< Device Identification */
  uint32 version_id;                   /**< Device Version ID, if any */
  uint32 block_count;                  /**< Number of total blocks in device */
  uint32 pages_per_block;              /**< Number of pages in a block */
  uint32 page_size_bytes;              /**< Page size in bytes */
};

typedef struct spinor_info spinorMemInfoType;

typedef struct
{
    uint32_t hardcode_dqs;          /* such as BUS_AUTO_DQS, BUS_USE_DQS, BUS_NO_DQS */
    uint32_t hardcode_read_mode;    /* such as BUS_MODE_AUTO or DDR_8_8_8_MODE, etc. */
    uint32_t hardcode_write_mode;   /* such as BUS_MODE_AUTO or DDR_8_8_8_MODE, etc. */
    uint32_t hardcode_bus_clk_khz;  /* Driver finds best match using this as floor   */
    uint32_t hardcode_no_data_read_dummy_cycle_recfg;   /* 1 =disable, 0 = enable */
	boolean use_pbl; /* 0= disable, 1 = enable */
} spinor_hardcode_data_mode;

/* Spinor sector map address range datatype */
typedef struct
{
    uint32_t start_range;
    uint32_t end_range;
    uint32_t er_size_KB;
}spinor_secmaptype;

/* Spinor sector map info type */
typedef struct
{
    spinor_secmaptype sectorMapInfo[5]; /* Sector Map Info */
}spinorSectorMapInfoType;

/* Struct to get the 4k block info */
typedef struct
{
    uint32_t block_num;
    int idx;
}spinor_getnum4kblockType;

#define SDR_1_1_READ_CODE_13H_MAX_FREQ_KHZ    54000U
#define SPINOR_DEFAULT_BUS_FREQ_MHZ_OSPI           90U
#define SPINOR_DEFAULT_BUS_FREQ_MHZ_QSPI           83U
#define DLL_LOW_FREQ_KHZ          90000U
#define SPI_BUS_MAX_SUPPORTED_FREQ_KHZ_OSPI 166000U

#ifdef NORPVL_ENB
#define SPI_BUS_MAX_SUPPORTED_FREQ_KHZ_QSPI 85500U
#else
#define SPI_BUS_MAX_SUPPORTED_FREQ_KHZ_QSPI 83000U
#endif

#define SPI_BUS_DEFAULT_FREQ_KHZ_QSPI       83000U
#define BUS_MODE_AUTO        0      /* Let driver/SFDP to find the best match which is DDR888 or SDR444 */
#define SDR_1_1_1_MODE       1      /* 1S-1S-1S */
#define SDR_1_1_4_MODE       2
#define SDR_1_4_4_MODE       3
#define SDR_4_4_4_MODE       4      /* 4S-4S-4S. DQS is disabled in the driver currently. The best QSPI perf mode for now */
#define DDR_1_1_4_MODE       5      /* 1S-1S-4D. Not support in the driver yet */
#define DDR_1_4_4_MODE       6      /* 1S-4D-4D. Not support in the driver yet */
#define DDR_4_4_4_MODE       7      /* 4S-4D-4D. Not support in the driver yet. TBD to enable DDR444 when DQS is available */
#define SDR_1_1_8_MODE       8
#define SDR_1_8_8_MODE       9
#define SDR_8_8_8_MODE       10
#define DDR_1_1_8_MODE       11
#define DDR_1_8_8_MODE       12
#define DDR_8_8_8_MODE       13
#define BUS_AUTO_DQS         0      /* Let driver to choose if DQS should be used. This is for productio driver. */
#define BUS_USE_DQS          1      /* Driver must use DQS. If driver has conflict, return failure */
#define BUS_NO_DQS           2      /* Driver must not use DQS. If driver has conflict, return failure */

#endif /* __SPINOR_CM_DEFS_H__ */
