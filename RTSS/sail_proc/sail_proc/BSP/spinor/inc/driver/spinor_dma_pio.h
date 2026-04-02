#ifndef __SPINOR_DMA_PIO_H__
#define __SPINOR_DMA_PIO_H__
/*
===========================================================================
*/
/**
    @file  spinor_dma_pio.h
    @brief Bus DMA and PIO functionality

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_dma_pio.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/

#include <stdbool.h>   // bool, etc.
#include <stdint.h>    // uint32_t, etc.
#include "spinor_cm_defs.h"

#define PAGE_SIZE_IN_BYTES   256
#define OSPI_DMA_DESCRIPTOR_ALIGNMENT 1024

// descriptor offset  0 = data address[ 7: 0]
// descriptor offset  1 = data address[15: 8]
// descriptor offset  2 = data address[23:16]
// descriptor offset  3 = data address[31:24]
// descriptor offset  4 = next descriptor[ 7: 0]
// descriptor offset  5 = next descriptor[15: 8]
// descriptor offset  6 = next descriptor[23:16]
// descriptor offset  7 = next descriptor[31:24]
// descriptor offset  8 = mode/dir
// descriptor offset  9 = fragment
// descriptor offset 10 = transfer length[ 7:0]
// descriptor offset 11 = transfer length[15:8]

typedef struct
{
   uint32_t  data_address;
   uint32_t  next_descriptor;
   uint32_t  direction:1;
   uint32_t  multi_io_mode:3;
   uint32_t  reserved1:4;
   uint32_t  fragment:1;
   uint32_t  reserved2:7;
   uint32_t  length:16;
   //------------------------//
   uint32_t  bounce_src;
   uint32_t  bounce_dst;
   uint32_t  bounce_length;
   uint64_t  padding[5];
} DESCRIPTOR;

#define DMA_MAX_DESCRIPTORS ((OSPI_DMA_DESCRIPTOR_ALIGNMENT/sizeof(DESCRIPTOR))-1)

// Maximum transfer size is 0xFFFF bytes but 0xFFC0 is the largest size that
// maintains 32-byte alignment between chunks.
#define DMA_MAX_TRSFR_LEN_PER_DESCRIPTOR 0xFFC0
/*==================================================================================================
                                               MACROS
==================================================================================================*/

// The following macros are used to statically allocate DMA buffers.  DMA buffers must be
// located in memory that is accessible to the OSPI HW.  They should also be in uncached memory
// (the octalspi driver will not flush/invalidate client buffers).  For best performance DMA
// buffers should be 32-byte aligned.  For example:
//

/*==================================================================================================
                                              TYPEDEFS
==================================================================================================*/

/* OSPI_MODE for the  includes the [3] DDR Mode field and [2:1] Multi IO Mode field of the CMD descriptor.

    Multi IO Mode – define the SPI mode
¨	01 – Single SPI
¨	10– Dual SPI
¨	11– Quad SPI
¨	00– Octal SPI
	DDR Mode  – selects between SDR/DDR modes
¨	0 – SDR
¨	1 – DDR

Hence the ordering of the enum matters here. */
typedef enum
{
   SDR_8BIT = 0,
   SDR_1BIT = 1,
   SDR_2BIT = 2,
   SDR_4BIT = 3,
   DDR_8BIT = 4,
   DDR_1BIT = 5,
   DDR_2BIT = 6,
   DDR_4BIT = 7,
} OSPI_MODE;

typedef struct
{
   uint16_t   opcode;        // 2 bytes are needed to support OSPI opcodes compared to 1 byte for Quad and single SPI
   uint8_t    addr_bytes;    // Number of bytes for Address
   uint8_t    dummy_clocks;  // Number of dummy cycles needed for the operation
   OSPI_MODE  cmd_mode;      // Mode for the command bytes
   OSPI_MODE  addr_mode;     // Mode for the Address bytes
   OSPI_MODE  data_mode;     // Mode for the Data bytes
   bool       write;         // Transfer direction (0 – Read 1 – Write)
} OSPI_CMD;

typedef enum               // Structure to know the type of operation in order to perform correct CRC related operations on the necessary data
{
   NO_APPEND_NEEDED = 0,   // Any other kind of operation which does not need any CRC related operations to be performed on the data
   REG_READ_OP = 1,        // Indicates a Register read operation
   REG_WRITE_OP = 2,       // Indicates a Register write operation
   OSPI_READ_OP = 3,       // Indicates a Memory read operation
   OSPI_WRITE_OP = 4,      // Indicates a Memory write operation
   OSPI_SFDP_OP = 5,       // Indicates an SFDP read
} OSPI_OP_ID;

/*==================================================================================================
                                        FUNCTION PROTOTYPES
==================================================================================================*/

extern bool spinor_dma_pio_transfer(OSPI_CMD *cmd, uint32_t addr, uint8_t *data, uint32_t data_bytes,
                        bool enable_dma, uint8 sdr_opcode_bytes);

/**********************************************************
 * Copy the data from bounce buffers
 *
 * @param dma_mode [IN]
 *   DMA mode
 *
 * @return int [OUT]
 *   Result of the operation. 0 for success, non zero for error
 *
 **********************************************************/
SPINOR_STATUS dma_pio_copy_bounce_data(bool dma_mode);

/**********************************************************
 * Unpack the CRC data
 *
 * @param data [IN/OUT]
 *   Data buffer to unpack the data
 *
 * @param data_bytes [IN]
 *   Number of bytes in the orginal data
 *
 * @return boolean [OUT]
 *   Result of the operation. 0 for success, non zero for error
 *
 **********************************************************/
boolean dma_pio_unpack_crc_data(uint8_t *data,uint32 data_bytes);

/**********************************************************
 * Set the CRC flag.
 *
 * @return value [IN]
 *   value to set.
 *
 **********************************************************/
void SetCRCFlag(bool value);

/**********************************************************
 * Get the CRC flag.
 *
 * @return bool [OUT]
 *   value to CRC flag.
 *
 **********************************************************/
bool GetCRCFlag(void);

/**********************************************************
 * Set the OSPI command flag for the operation ID.
 *
 * @return operation_id [IN]
 *   Operation ID.
 *
 **********************************************************/
void SetOSPICmdFlag(OSPI_OP_ID operation_id);

/**********************************************************
 * Get the OSPI command flag.
 *
 * @return int [OUT]
 *   Operation ID.
 *
 **********************************************************/
OSPI_OP_ID GetOSPICmdFlag(void);

#endif  // __OCTALSPI_H__
