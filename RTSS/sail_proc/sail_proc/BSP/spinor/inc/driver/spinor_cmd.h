#ifndef __SPINOR_CMD_H__
#define __SPINOR_CMD_H__
/*
===========================================================================
*/
/**
    @file  spinor_cmd.h
    @brief This file provides an interface to spi buses driver

*/
/*
    ===========================================================================

    Copyright (c) 2017,2019,2020-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_cmd.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"

/* SPI command Types */
typedef enum
{
   OSPI_READ_MODE  = 1,
   OSPI_WRITE_MODE = 2,
   OSPI_ERASE_MODE = 3,
   OSPI_ERASE_BULK_MODE = 5,
   OSPI_DEVICE_OP_MODE = 6,
   OSPI_REGISTER_READ = 7,
   OSPI_REGISTER_WRITE = 8,
   OSPI_READ_SFDP_MODE = 9,
   OSPI_REGISTER_READ_ADDR = 0xA,
   OSPI_REGISTER_WRITE_ADDR = 0xB,
   OSPI_BIN_CMD_MODE = 0xC,
} SPI_COMMAND_TYPE;

/* States for the SPINOR Command Engine */
typedef enum
{
    SPINOR_CMD_ENGINE_IDLE = 0,           /* Engine Idle */
    SPINOR_CMD_ENGINE_BUSY,               /* Engine Busy */
    SPINOR_CMD_ENGINE_QUEUE_FLUSH_CHAIN,  /* Engine started to flush the command chain */
    SPINOR_CMD_ENGINE_FLUSH_POLL,         /* Engine waiting for completion of transfer */
    SPINOR_CMD_ENGINE_FLUSH_TIMEOUT,      /* Engine timedout waiting for completion of transfer */
    SPINOR_CMD_ENGINE_COPY_BOUNCE_DATA,   /* Engine copying bounce buffer data */
    SPINOR_CMD_ENGINE_UNPACK_CRC_DATA,    /* Engine unpacking CRC data */
    SPINOR_CMD_ENGINE_ERROR,              /* Engine error */
    SPINOR_CMD_ENGINE_FLUSH_ERROR,        /* Engine Flush Error */
}SPINOR_CMDEngineStatusType;

/* Parameters for the SPINOR Command Engine */
typedef struct
{
    SPI_COMMAND_TYPE cmd_mode;            /* SPI Command mode */
    uint32_t addr;                        /* Address of the memory */
    uint8 *reg_value;                     /* Data buffer for reads/writes */
    uint32_t len;                         /* Length of the data buffer */
    uint8_t opcode;                       /* Opcode for the SPI command */
}SPINOR_CMDEngineParamType;

#ifdef SAILJTAGPROGRAMMER
#define SPINOR_CMD_ENG_TIMEOUT_US 1000000 /* 1s */
#define SPINOR_CMD_ENG_TIMEOUT_LOW_FRQ_US 1000000 /* 1s time out while running at low frequencies */
#else
#ifndef NORPVL_ENB
#define SPINOR_CMD_ENG_TIMEOUT_US 200000 /* 200ms */
#define SPINOR_CMD_ENG_TIMEOUT_LOW_FRQ_US 1000000 /* 1s time out while running at low frequencies */
#else
#define SPINOR_CMD_ENG_TIMEOUT_US 1000000 /* 1s */
#define SPINOR_CMD_ENG_TIMEOUT_LOW_FRQ_US 1000000 /* 1s */
#endif
#endif



/*==================================================================================================
                                        FUNCTION PROTOTYPES
==================================================================================================*/
/**********************************************************
 * Gets the current status of the SPINOR Command Engine.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the SPINOR Command Engine.
 *
 **********************************************************/
SPINOR_CMDEngineStatusType spinorCMDEngineGetState(void);

/**********************************************************
 * Trigger the start of the SPINOR Command Engine.
 *
 * @param CMDEngineParams [IN]
 *   Command Engine Parameters
 *
 * @return int [OUT]
 *   Status of the Operation.
 *
 **********************************************************/
SPINOR_STATUS spinorCMDEngineStart(SPINOR_CMDEngineParamType* CMDEngineParams);

/**********************************************************
 * Main function loop to run the SPINOR Command Engine.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinorCMDEngineRun(void);

/**********************************************************
 * Transfers the SPINOR command.
 *
 * @param cmd_mode [IN]
 *   SPI Command mode
 *
 * @param addr [IN]
 *   Address of the memory
 *
 * @param reg_value [IN/OUT]
 *   Pointer to the data buffer
 *
 * @param len [IN]
 *   Length of the data buffer
 *
 * @param opcode [IN]
 *   Opcode for the SPI command
 *
 * @return int [OUT]
 *   Status of the Operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_cmd_transfer(SPI_COMMAND_TYPE cmd_mode, uint32_t addr, uint8 *reg_value, uint32 len, uint8_t opcode );

/**********************************************************
 * Sets the parameters for SPI binary command.
 *
 * @param dummy_cycles [IN]
 *   Number of dummy cycles
 *
 * @param len [IN]
 *   Number of data bytes
 *
 * @param num_addr_bytes [IN]
 *   Number of address bytes
 *
 * @param is_write_operation [IN/OUT]
 *   Write operation or not
 *
 * @param use_dma [IN]
 *   Uses DMA or not
 *
 * @return void [OUT]
 *   void.
 *
 **********************************************************/
void spinor_cmd_set_bin_cmd_params(uint8_t dummy_cycles, uint32_t len, uint8_t num_addr_bytes, boolean is_write_operation, boolean use_dma);

/**********************************************************
 * Clears the parameters for SPI binary command.
 *
 * @param void [IN]
 *   void
 *
 * @return void [OUT]
 *   void.
 *
 **********************************************************/
void spinor_cmd_clear_bin_cmd_params(void);

#endif /* __SPINOR_SPIAL_H__ */
