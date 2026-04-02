#ifndef __SPINOR_TRANSACTION_H__
#define __SPINOR_TRANSACTION_H__
/*
===========================================================================
*/
/**
    @file  spinor_transaction.h
    @brief This file provides definitions for the spinor transactions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_transaction.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_api.h"

/* Erase Operation States */
typedef enum
{
    ERASE_OP_DONE = 0,
    ERASE_PENDING,
    ERASE_SND_WR_EN_CMD,
    ERASE_RD_WR_EN_LATCH,
    ERASE_SND_ERASE_CMD,
    ERASE_RD_PE_WR_BUSY_STATUS,
    ERASE_RD_VENDOR_ERR_STATUS,
    ERASE_RD_ECC_ERR_STATUS,
    ERASE_RD_ECC_ERR_ADDR,
    ERASE_RD_CRC_ERR_STATUS,
    ERASE_OP_ERROR,
    ERASE_OP_ECC_ERROR,
    ERASE_OP_CRC_ERROR,
    ERASE_TIMEOUT_ERROR
}spinor_EraseOperationStateType;

/* Write Operation States */
typedef enum
{
    WRITE_OP_DONE = 0,
    WRITE_PENDING,
    WRITE_SND_WR_EN_CMD,
    WRITE_RD_WR_EN_LATCH,
    WRITE_SND_WRITE_CMD,
    WRITE_RD_PE_WR_BUSY_STATUS,
    WRITE_RD_VENDOR_ERR_STATUS,
    WRITE_RD_ECC_ERR_STATUS,
    WRITE_RD_ECC_ERR_ADDR,
    WRITE_RD_CRC_ERR_STATUS,
    WRITE_OP_ERROR,
    WRITE_OP_ECC_ERROR,
    WRITE_OP_CRC_ERROR,
    WRITE_TIMEOUT_ERROR
}spinor_WriteOperationStateType;

/* Read Operation States */
typedef enum
{
    READ_OP_DONE = 0,
    READ_PENDING,
    READ_SND_READ_CMD,
    READ_RD_ECC_ERR_STATUS,
    READ_RD_ECC_ERR_ADDR,
    READ_RD_CRC_ERR_STATUS,
    READ_SEND_SPLITREAD_CMD,
    READ_RD_ECC_ERR_STATUS1,
    READ_RD_ECC_ERR_ADDR1,
    READ_RD_CRC_ERR_STATUS1,
    READ_COPY_SPLIT_CONTENTS,
    READ_OP_ERROR,
    READ_OP_ECC_ERROR,
    READ_OP_CRC_ERROR,
    READ_TIMEOUT_ERROR
}spinor_ReadOperationStateType;

/* SPI command Operation States */
typedef enum
{
    SPI_CMD_OP_DONE = 0,
    SPI_CMD_PENDING,
    SPI_SND_SPI_CMD,
    SPI_CMD_OP_ERROR,
    SPI_CMD_TIMEOUT_ERROR
}spinor_SPICMDOperationStateType;

/**********************************************************
 * Main function loop for Erase Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_erase_async(void *Ctx);

/**********************************************************
 * Main function loop for Read Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_read_async(void *Ctx);

/**********************************************************
 * Main function loop for Write Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_write_async(void *Ctx);

/**********************************************************
 * Main function loop for SPI CMD Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_spicmd_async(void *Ctx);

#endif /* __SPINOR_TRANSACTION_H__ */
