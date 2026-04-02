/*
===========================================================================
*/
/**
    @file  spinor_cmd.c
    @brief This file implements function to interface spinor driver with spi buses driver

*/
/*
    ===========================================================================

    Copyright (c) 2017-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_cmd.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_utils.h"
#include "spinor_init_config.h"
#include "spinor_osal.h"
#include "busywait.h"
#include "spinor_dma_pio.h"
#include "spinor_core.h"
#include "spinor_cmd.h"
#include "spinor_diag.h"
#include "timetick.h"
#include "common_functions.h"
#include "spinor_hal.h"
#include "spinor_sfdp.h"

/* SPINOR Command Engine Context */
typedef struct
{
    SPINOR_CMDEngineStatusType status;          /* Status of the Command Engine */
    SPINOR_CMDEngineParamType CMDEngineParams;  /* Command Engine Parameters */
    timetick_type_64 starttime;                 /* Start time for the command flush */
}
spinorCMDEngineCtxType;

spinorCMDEngineCtxType spinorCMDEngineCtx = {0};

typedef struct
{
    uint8_t dummycycles;
    uint32_t len;
    uint8_t num_addr_bytes;
    boolean is_write_operation;
    boolean use_dma;
}spinor_bincmd_param_type;

spinor_bincmd_param_type spinor_bincmd_param = {0};

static SPINOR_STATUS config_cmd_spi(OSPI_CMD *qspi_config_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode);
static SPINOR_STATUS config_cmd_spi_read(OSPI_CMD *qspi_config_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);
static SPINOR_STATUS config_cmd_spi_write(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);
static SPINOR_STATUS config_cmd_spi_erase(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);
static SPINOR_STATUS config_cmd_spi_device_op(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);
static SPINOR_STATUS config_cmd_spi_reg_write(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);
static SPINOR_STATUS config_cmd_spi_reg_read(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);
static SPINOR_STATUS config_cmd_spi_sfdp_read(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);
static SPINOR_STATUS config_cmd_spi_bin_cmd(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode);

/**********************************************************
 * Gets the current status of the SPINOR Command Engine.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the SPINOR Command Engine.
 *
 **********************************************************/
SPINOR_CMDEngineStatusType spinorCMDEngineGetState(void)
{
    return spinorCMDEngineCtx.status;
}

/**********************************************************
 * Sets the current status of the SPINOR Command Engine.
 *
 * @param status [IN]
 *   Status to be set.
 *
 * @return int [OUT]
 *   Status of the SPINOR Command Engine.
 *
 **********************************************************/
void spinorCMDEngineSetState(SPINOR_CMDEngineStatusType status)
{
    spinorCMDEngineCtx.status = status;
}

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
SPINOR_STATUS spinorCMDEngineStart(SPINOR_CMDEngineParamType* CMDEngineParams)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    SPINOR_CMDEngineParamType *params;

    if (SPINOR_CMD_ENGINE_IDLE != spinorCMDEngineGetState())
    {
        spinor_log (&p_spinor_dev->debug_log, 0x200);
        SPINOR_LOG_ERROR("%s: Error, Command Engine not Idle \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* Set the state of the Command Engine to busy soon after it is known to be Idle */
    spinorCMDEngineSetState(SPINOR_CMD_ENGINE_BUSY);

    /* Copy the Command Engine parameters to the Engine's context to keep track of the current item being processed by the Engine */
    sailbsp_memscpy((void *)&spinorCMDEngineCtx.CMDEngineParams, sizeof(SPINOR_CMDEngineParamType), ( const void *)CMDEngineParams, sizeof(SPINOR_CMDEngineParamType));

    params = &spinorCMDEngineCtx.CMDEngineParams;

    /* Queue the item to the transfer and flush the descriptor chain in the controller to initiate the command */
    status = spinor_cmd_transfer(params->cmd_mode, params->addr, params->reg_value, params->len, params->opcode);

    if (SPINOR_DEVICE_DONE != status)
    {
        //todo: Dilip should the status go back to Idle or leave in error state?
        // if we leave it in error state, next transaction cannot be called.
        // need to do a reset of the command engine to get the next transaction
        //spinorCMDEngineSetState(SPINOR_CMD_ENGINE_IDLE);
        spinorCMDEngineSetState(SPINOR_CMD_ENGINE_ERROR);
        spinor_log (&p_spinor_dev->debug_log, 0x201);
        SPINOR_LOG_ERROR("%s: Error, Command Engine Start failed, status = 0x%x \r\n", __func__, status);
        return SPINOR_DEVICE_FAIL;
    }

    /* Set the state of the Command Engine to Queue Flush chain */
    spinorCMDEngineSetState(SPINOR_CMD_ENGINE_QUEUE_FLUSH_CHAIN);

    /* Get the current timer to track of the flush timeout */
    if(p_spinor_dev->disable_timeouts == 0)
    {
        spinorCMDEngineCtx.starttime = timetick_get64();
    }

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Main function loop to run the SPINOR Command Engine.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinorCMDEngineRun(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    SPINOR_CMDEngineParamType *params;

    params = &spinorCMDEngineCtx.CMDEngineParams;

    /* Queue the item to the transfer and flush the descriptor chain in the controller to initiate the command */
    status = spinor_cmd_transfer(params->cmd_mode, params->addr, params->reg_value, params->len, params->opcode);

    if (SPINOR_DEVICE_DONE != status)
    {
        spinorCMDEngineSetState(SPINOR_CMD_ENGINE_ERROR);
        spinor_log (&p_spinor_dev->debug_log, 0x202);
        SPINOR_LOG_ERROR("%s: Error, Command Engine Run failed, status = 0x%x \r\n", __func__, status);
        return;
    }

    return;
}

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
SPINOR_STATUS spinor_cmd_transfer(SPI_COMMAND_TYPE cmd_mode, uint32_t addr, uint8 *reg_value, uint32 len,uint8_t opcode )
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  boolean transfer_mode = FALSE;
  uint32 transfer_size = 0;
  OSPI_CMD ospi_cmd;
  boolean dma_done = FALSE;
  spinor_getnum4kblockType blockinfo = {0};
#ifdef SPINOR_CRC_ENABLE
  boolean crc_flag = GetCRCFlag();
#endif

  if((TRUE == p_spinor_dev->dll_config_en ) && (SPI_TRANSFER_DTR == p_spinor_dev->config_data->device_transfer_rate)
     && (cmd_mode == OSPI_READ_MODE || cmd_mode == OSPI_REGISTER_READ_ADDR ||cmd_mode == OSPI_REGISTER_READ || cmd_mode == OSPI_READ_SFDP_MODE || ((cmd_mode == OSPI_BIN_CMD_MODE) && (FALSE == spinor_bincmd_param.is_write_operation) && (0 != spinor_bincmd_param.len) ) )
    )
  {
      if(TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk)
          transfer_size = len;
      else
          transfer_size =  len+1;
  }
  else
      transfer_size = len;

  if (cmd_mode == OSPI_READ_MODE || cmd_mode == OSPI_WRITE_MODE || cmd_mode == OSPI_ERASE_MODE || cmd_mode == OSPI_ERASE_BULK_MODE || cmd_mode == OSPI_DEVICE_OP_MODE || ((cmd_mode == OSPI_BIN_CMD_MODE) && (TRUE == spinor_bincmd_param.use_dma)))
  {
    transfer_mode = p_spinor_dev->dma_enable; //QSPI_DMA_INT_MODE : QSPI_DMA_POLL_MODE;
  }

#ifdef SPINOR_CRC_ENABLE
  if(crc_flag == TRUE)
  {
      switch(cmd_mode)
      {
          case OSPI_REGISTER_WRITE_ADDR:
          case OSPI_REGISTER_WRITE:
              if(p_spinor_dev->config_data->ecc_info.ecc_status_reg_wr_opcode == WRITE_CFG2_CMD) /* Only for macronix */
                  SetOSPICmdFlag(REG_WRITE_OP);
              else
                  SetOSPICmdFlag(NO_APPEND_NEEDED);
              break;

          case OSPI_REGISTER_READ_ADDR:
          case OSPI_REGISTER_READ:
              if(p_spinor_dev->config_data->ecc_info.ecc_status_reg_wr_opcode == WRITE_CFG2_CMD) /* Only for macronix */
                  SetOSPICmdFlag(REG_READ_OP);
              else
                  SetOSPICmdFlag(NO_APPEND_NEEDED);
              break;

          case OSPI_READ_SFDP_MODE:
              if(p_spinor_dev->config_data->ecc_info.ecc_status_reg_wr_opcode == WRITE_CFG2_CMD) /* Only for macronix */
                  SetOSPICmdFlag(OSPI_SFDP_OP);
              else
                  SetOSPICmdFlag(NO_APPEND_NEEDED);

          case OSPI_READ_MODE:
              SetOSPICmdFlag(OSPI_READ_OP);
              break;

          case OSPI_WRITE_MODE:
              SetOSPICmdFlag(OSPI_WRITE_OP);
              break;

          default:
              SetOSPICmdFlag(NO_APPEND_NEEDED);
              break;
        }
  }
#endif

  if (SPINOR_CMD_ENGINE_BUSY == spinorCMDEngineGetState())
  {
      memset (&ospi_cmd, 0, sizeof(OSPI_CMD));

      if (OSPI_ERASE_MODE == cmd_mode)
      {
          access_param_mode_type mode;

          if (TRUE == p_spinor_dev->perfmode_enabled)
          {
              mode = PERF_MODE_ACCESS_PARAM;
          }
          else
          {
              mode = DEFAULT_ACCESS_PARAM;
          }
          
          status = spinor_util_getnum4kblock(addr, &blockinfo);
          if(status != SPINOR_DEVICE_DONE)
          {
              status = SPINOR_DEVICE_FAIL;
              spinor_log (&p_spinor_dev->debug_log, 0x203);
              SPINOR_LOG_ERROR("%s: Error, spinor_util_getnum4kblock failed \r\n", __func__);
              goto done;
          }
          
          if(blockinfo.block_num > 1)
          {
              opcode = p_spinor_dev->config_data->access_param[mode].erase_256kb_opcode;
              addr =  addr &~(p_spinor_dev->config_data->secMapAlignmentAddr - 1);
          }
          else
              opcode = p_spinor_dev->config_data->access_param[mode].erase_4kb_opcode;
      }

      if (status != config_cmd_spi(&ospi_cmd, cmd_mode, opcode))
      {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x204);
        SPINOR_LOG_ERROR("%s: Error, command configuration failed \r\n", __func__);
        goto done;
      }

      if (p_spinor_dev->dma_enable == TRUE &&
          (cmd_mode == OSPI_WRITE_MODE ||
          cmd_mode == OSPI_REGISTER_WRITE_ADDR ||
           cmd_mode == OSPI_REGISTER_WRITE || ((cmd_mode == OSPI_BIN_CMD_MODE) && (TRUE == spinor_bincmd_param.is_write_operation) ))
          )
      {
        spinor_cache_flush(reg_value, transfer_size);
      }

      if (!spinor_dma_pio_transfer(&ospi_cmd, addr, reg_value, transfer_size, transfer_mode, p_spinor_dev->config_data->octal_sdr_num_bytes))
      {
        spinorCMDEngineSetState(SPINOR_CMD_ENGINE_FLUSH_ERROR);
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x205);
        SPINOR_LOG_ERROR("%s: Error, SPINOR DMA/PIO transfer failed \r\n", __func__);
      }
      return status;
  }

   if ((SPINOR_CMD_ENGINE_QUEUE_FLUSH_CHAIN == spinorCMDEngineGetState()) || (SPINOR_CMD_ENGINE_FLUSH_POLL ==spinorCMDEngineGetState()) )
   {
       if (transfer_mode)
       {
           dma_done = spinor_hal_is_dma_transfer_done();
       }
       else
       {
           dma_done = spinor_hal_is_pio_transer_done();
       }

       if (TRUE == dma_done)
       {

           spinorCMDEngineSetState(SPINOR_CMD_ENGINE_FLUSH_POLL);
           status = dma_pio_copy_bounce_data(transfer_mode);
           if (SPINOR_DEVICE_DONE != status)
           {
               spinorCMDEngineSetState(SPINOR_CMD_ENGINE_ERROR);
               status = SPINOR_DEVICE_FAIL;
               spinor_log (&p_spinor_dev->debug_log, 0x206);
               SPINOR_LOG_ERROR("%s: Error, SPINOR DMA/PIO copy bounce data failed, status = 0x%x \r\n", __func__, status);
               return status;
           }
           spinorCMDEngineSetState(SPINOR_CMD_ENGINE_COPY_BOUNCE_DATA);
           return status;
       }
       else
       {
           spinorCMDEngineSetState(SPINOR_CMD_ENGINE_FLUSH_POLL);
           /* Check if the timeout happened */
           if(p_spinor_dev->disable_timeouts == 0)
           {
               timetick_type_64 t2 = timetick_get64();
               
               if (transfer_mode)
               {
                   dma_done = spinor_hal_is_dma_transfer_done();
               }
               else
               {
                   dma_done = spinor_hal_is_pio_transer_done();
               }
               
               if (TRUE == dma_done)
               {
               
                   spinorCMDEngineSetState(SPINOR_CMD_ENGINE_FLUSH_POLL);
                   status = dma_pio_copy_bounce_data(transfer_mode);
                   if (SPINOR_DEVICE_DONE != status)
                   {
                       spinorCMDEngineSetState(SPINOR_CMD_ENGINE_ERROR);
                       status = SPINOR_DEVICE_FAIL;
                       spinor_log (&p_spinor_dev->debug_log, 0x207);
                       SPINOR_LOG_ERROR("%s: Error, SPINOR DMA/PIO copy bounce data failed \r\n", __func__);
                       return status;
                   }
                   spinorCMDEngineSetState(SPINOR_CMD_ENGINE_COPY_BOUNCE_DATA);
                   return status;
               }
           
               if (p_spinor_dev->cmd_eng_poll_timeout_us <= elapsedtime_us(t2, spinorCMDEngineCtx.starttime))
               {
                   spinor_log (&p_spinor_dev->debug_log, 0x208);
                   SPINOR_LOG_ERROR("%s: Error, SPINOR CMD engine flush timeout occured \r\n", __func__);
                   spinorCMDEngineSetState(SPINOR_CMD_ENGINE_FLUSH_TIMEOUT);
               }
           }
           return status;
       }
   }

   if(SPINOR_CMD_ENGINE_COPY_BOUNCE_DATA == spinorCMDEngineGetState())
   {
#ifdef SPINOR_CRC_ENABLE
       /* Unpacking the data if CRC is enabled */
       if(GetCRCFlag() == TRUE && ((cmd_mode == OSPI_REGISTER_READ) || (cmd_mode == OSPI_REGISTER_READ_ADDR) || (cmd_mode == OSPI_READ_MODE) || (cmd_mode == OSPI_READ_SFDP_MODE) ||
                                   ((cmd_mode == OSPI_BIN_CMD_MODE) && (FALSE == spinor_bincmd_param.is_write_operation) ) )
          ) //for only read operation
       {
           /* need to unpack the CRC if needed */
           if(FALSE == dma_pio_unpack_crc_data(reg_value,transfer_size))
           {
               spinorCMDEngineSetState(SPINOR_CMD_ENGINE_ERROR);
               status = SPINOR_DEVICE_FAIL;
               spinor_log (&p_spinor_dev->debug_log, 0x209);
               SPINOR_LOG_ERROR("%s: Error, SPINOR DMA/PIO unpacking CRC failed \r\n", __func__);
               return status;
           }
           spinorCMDEngineSetState(SPINOR_CMD_ENGINE_UNPACK_CRC_DATA);
       }
#endif

       if (p_spinor_dev->dma_enable == TRUE &&
           (cmd_mode == OSPI_READ_MODE ||
            cmd_mode == OSPI_REGISTER_READ ||
            cmd_mode == OSPI_REGISTER_READ_ADDR ||
            cmd_mode == OSPI_READ_SFDP_MODE || ((cmd_mode == OSPI_BIN_CMD_MODE) && (FALSE == spinor_bincmd_param.is_write_operation) ))
           )
       {
         spinor_cache_inval(reg_value, transfer_size);
       }

       spinorCMDEngineSetState(SPINOR_CMD_ENGINE_IDLE);

   }

done:

  return status;
}

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
void spinor_cmd_set_bin_cmd_params(uint8_t dummy_cycles, uint32_t len, uint8_t num_addr_bytes, boolean is_write_operation, boolean use_dma)
{
    spinor_bincmd_param.dummycycles = dummy_cycles;
    spinor_bincmd_param.len = len;
    spinor_bincmd_param.num_addr_bytes = num_addr_bytes;
    spinor_bincmd_param.is_write_operation = is_write_operation;
    spinor_bincmd_param.use_dma = use_dma;
}

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
void spinor_cmd_clear_bin_cmd_params(void)
{
    spinor_bincmd_param.dummycycles = 0;
    spinor_bincmd_param.len = 0;
    spinor_bincmd_param.num_addr_bytes = 0;
    spinor_bincmd_param.is_write_operation = FALSE;
    spinor_bincmd_param.use_dma = FALSE;
}

static SPINOR_STATUS config_cmd_spi(OSPI_CMD *qspi_config_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode)
{
  OSPI_CMD *qspi_cmd;
  qspi_cmd = qspi_config_cmd;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint8_t op_code;
  access_param_mode_type mode;

  if (TRUE == p_spinor_dev->perfmode_enabled)
  {
      mode = PERF_MODE_ACCESS_PARAM;
  }
  else
  {
      mode = DEFAULT_ACCESS_PARAM;
  }

  if (cmd_mode == OSPI_READ_MODE)
  {
    status = config_cmd_spi_read(qspi_cmd, cmd_mode, opcode, mode);
  }
  else if (cmd_mode == OSPI_WRITE_MODE)
  {
    status = config_cmd_spi_write(qspi_cmd, cmd_mode, opcode, mode);
  }
  else if (cmd_mode == OSPI_ERASE_MODE)
  {
    status = config_cmd_spi_erase(qspi_cmd, cmd_mode, opcode, mode);
  }
  else if (cmd_mode == OSPI_DEVICE_OP_MODE)
  {
    status = config_cmd_spi_device_op(qspi_cmd, cmd_mode, opcode, mode);
  }
  else if ((cmd_mode == OSPI_REGISTER_WRITE)||(cmd_mode == OSPI_REGISTER_WRITE_ADDR))
  {
      status = config_cmd_spi_reg_write(qspi_cmd, cmd_mode, opcode, mode);
  }
  else if ((cmd_mode == OSPI_REGISTER_READ) || (cmd_mode == OSPI_REGISTER_READ_ADDR))
  {
      status = config_cmd_spi_reg_read(qspi_cmd, cmd_mode, opcode, mode);
  }
  else if (cmd_mode == OSPI_READ_SFDP_MODE)
  {
      status = config_cmd_spi_sfdp_read(qspi_cmd, cmd_mode, opcode, mode);
  }
  else if (cmd_mode == OSPI_BIN_CMD_MODE)
  {
      status = config_cmd_spi_bin_cmd(qspi_cmd, cmd_mode, opcode, mode);
  }
  else
  {
      // Invalid cmd_mode
      status = SPINOR_DEVICE_FAIL;
  }

config_cmd_spi:
  return status;
}

static SPINOR_STATUS config_cmd_spi_read(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;


    op_code                = p_spinor_dev->config_data->access_param[mode].read_opcode;
    qspi_cmd->addr_bytes   = p_spinor_dev->config_data->access_param[mode].addr_bytes;
    qspi_cmd->dummy_clocks = p_spinor_dev->config_data->access_param[mode].wait_state;
    qspi_cmd->cmd_mode     = SDR_1BIT;
    qspi_cmd->addr_mode    = SDR_1BIT;
    qspi_cmd->data_mode    = SDR_1BIT;
    qspi_cmd->write        = false;

    switch (p_spinor_dev->config_data->access_param[mode].read_mode)
    {
        case SDR_1_1_1_MODE:
          break;                                   /* default settings */

        case SDR_4_4_4_MODE:
          qspi_cmd->cmd_mode  = SDR_4BIT;
          qspi_cmd->addr_mode = SDR_4BIT;
          qspi_cmd->data_mode = SDR_4BIT;
          break;

        case SDR_1_1_4_MODE:
          qspi_cmd->data_mode = SDR_4BIT;
          break;

        case SDR_1_4_4_MODE:
          qspi_cmd->addr_mode = SDR_4BIT;
          qspi_cmd->data_mode = SDR_4BIT;
          break;

        case DDR_4_4_4_MODE:
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en)?((qspi_cmd->dummy_clocks*2)+1):qspi_cmd->dummy_clocks;
          qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          break;

        case SDR_8_8_8_MODE:
          qspi_cmd->cmd_mode  = SDR_8BIT;
          qspi_cmd->addr_mode = SDR_8BIT;
          qspi_cmd->data_mode = SDR_8BIT;
          break;

        case DDR_8_8_8_MODE:
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en)?((qspi_cmd->dummy_clocks*2)+1):(qspi_cmd->dummy_clocks*2);
          qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          break;

        case SDR_1_1_8_MODE:
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SDR_1_8_8_MODE:
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x20A);
          SPINOR_LOG_ERROR("%s: Error, Invalid read mode choice for configuring command type READ \r\n", __func__);
          goto config_cmd_spi_reads;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
      qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)op_code<<8)|((uint8_t)op_code)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)op_code)<<8)| ((uint8_t)(op_code)):op_code;
    }
    else
    {
      qspi_cmd->opcode = op_code;
    }

config_cmd_spi_reads:
  return status;
}

static SPINOR_STATUS config_cmd_spi_write(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;

    op_code = p_spinor_dev->config_data->access_param[mode].write_opcode;
    qspi_cmd->addr_bytes = p_spinor_dev->config_data->access_param[mode].addr_bytes;
    qspi_cmd->dummy_clocks = 0;
    qspi_cmd->cmd_mode = SDR_1BIT;
    qspi_cmd->addr_mode = SDR_1BIT;
    qspi_cmd->data_mode = SDR_1BIT;
    qspi_cmd->write = true;

    switch (p_spinor_dev->config_data->access_param[mode].write_mode)
    {
        case SDR_1_1_1_MODE:
          break;                                   /* default settings */

        case SDR_4_4_4_MODE:
          qspi_cmd->cmd_mode   = SDR_4BIT;
          qspi_cmd->addr_mode  = SDR_4BIT;
          qspi_cmd->data_mode  = SDR_4BIT;
          break;

        case SDR_1_1_4_MODE:
          qspi_cmd->data_mode = SDR_4BIT;
          break;

        case SDR_1_4_4_MODE:
          qspi_cmd->addr_mode = SDR_4BIT;
          qspi_cmd->data_mode = SDR_4BIT;
          break;

        case DDR_4_4_4_MODE:
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          break;

        case SDR_8_8_8_MODE:
          qspi_cmd->cmd_mode     = SDR_8BIT;
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case DDR_8_8_8_MODE:
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          break;

        case SDR_1_1_8_MODE:
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SDR_1_8_8_MODE:
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x20B);
          SPINOR_LOG_ERROR("%s: Error, Invalid write mode choice for configuring command type WRITE \r\n", __func__);
          goto config_cmd_spi_writes;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
      qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)op_code<<8)|((uint8_t)op_code)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)op_code)<<8)| ((uint8_t)(op_code)):op_code;
    }
    else
    {
      qspi_cmd->opcode = op_code;
    }

config_cmd_spi_writes:
  return status;
}

static SPINOR_STATUS config_cmd_spi_erase(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;

    op_code = opcode;
    qspi_cmd->addr_bytes = p_spinor_dev->config_data->access_param[mode].addr_bytes;
    qspi_cmd->dummy_clocks = 0;
    qspi_cmd->cmd_mode = SDR_1BIT;
    qspi_cmd->addr_mode = SDR_1BIT;
    qspi_cmd->data_mode = SDR_1BIT;
    qspi_cmd->write = false;

    switch (p_spinor_dev->config_data->access_param[mode].write_mode)
    {
        case SDR_1_1_1_MODE:
          break;                                   /* default settings */

        case SDR_4_4_4_MODE:
          qspi_cmd->cmd_mode   = SDR_4BIT;
          qspi_cmd->addr_mode  = SDR_4BIT;
          qspi_cmd->data_mode  = SDR_4BIT;
          break;

        case SDR_1_1_4_MODE:
          qspi_cmd->data_mode = SDR_4BIT;
          break;

        case SDR_1_4_4_MODE:
          qspi_cmd->data_mode = SDR_4BIT;
          break;

        case DDR_4_4_4_MODE:
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          break;

        case SDR_8_8_8_MODE:
          qspi_cmd->cmd_mode     = SDR_8BIT;
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case DDR_8_8_8_MODE:
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          break;

        case SDR_1_1_8_MODE:
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SDR_1_8_8_MODE:
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x20C);
          SPINOR_LOG_ERROR("%s: Error, Invalid write mode choice for configuring command type ERASE \r\n", __func__);
          goto config_cmd_spi_erase;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
      qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)op_code<<8)|((uint8_t)op_code)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)op_code)<<8)| ((uint8_t)(op_code)):op_code;
    }
    else
    {
      qspi_cmd->opcode = op_code;
    }

config_cmd_spi_erase:
  return status;
}

static SPINOR_STATUS config_cmd_spi_device_op(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;

    op_code = opcode;
    qspi_cmd->addr_bytes = 0;
    qspi_cmd->dummy_clocks = 0;
    qspi_cmd->cmd_mode  = SDR_1BIT;
    qspi_cmd->addr_mode = SDR_1BIT;
    qspi_cmd->data_mode = SDR_1BIT;
    qspi_cmd->write = false;

    switch (p_spinor_dev->mode_enabled)
    {
        case SPI_DEFAULT_SDR:
          break;                                   /* default settings */

        case SPI_QUAD_SDR:
          qspi_cmd->cmd_mode   = SDR_4BIT;
          qspi_cmd->addr_mode  = SDR_4BIT;
          qspi_cmd->data_mode  = SDR_4BIT;
          break;

        case SPI_QUAD_DDR:
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          break;

        case SPI_OCTAL_SDR:
          qspi_cmd->cmd_mode     = SDR_8BIT;
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SPI_OCTAL_DDR:
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x20D);
          SPINOR_LOG_ERROR("%s: Error, Invalid mode enabled choice for configuring command type DEVICE OP \r\n", __func__);
          goto config_cmd_spi_device_op;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
      qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)op_code<<8)|((uint8_t)op_code)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)op_code)<<8)| ((uint8_t)(op_code)):op_code;
    }
    else
    {
      qspi_cmd->opcode = op_code;
    }

config_cmd_spi_device_op:
  return status;
}

static SPINOR_STATUS config_cmd_spi_reg_write(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;

    qspi_cmd->opcode = opcode;
    qspi_cmd->addr_bytes = (cmd_mode == OSPI_REGISTER_WRITE_ADDR)?p_spinor_dev->config_data->access_param[mode].addr_bytes_reg_addr:p_spinor_dev->config_data->access_param[mode].addr_bytes_reg;
    qspi_cmd->dummy_clocks = 0;
    qspi_cmd->cmd_mode  = SDR_1BIT;
    qspi_cmd->addr_mode = SDR_1BIT;
    qspi_cmd->data_mode = SDR_1BIT;
    qspi_cmd->write = true;

    switch (p_spinor_dev->mode_enabled)
    {
        case SPI_DEFAULT_SDR:
          break;                                   /* default settings */

        case SPI_QUAD_SDR:
          qspi_cmd->cmd_mode   = SDR_4BIT;
          qspi_cmd->addr_mode  = SDR_4BIT;
          qspi_cmd->data_mode  = SDR_4BIT;
          break;

        case SPI_QUAD_DDR:
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          break;

        case SPI_OCTAL_SDR:
          qspi_cmd->cmd_mode     = SDR_8BIT;
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SPI_OCTAL_DDR:
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x20E);
          SPINOR_LOG_ERROR("%s: Error, Invalid mode enabled choice for configuring command type REGISTER WRITE \r\n", __func__);
          goto config_cmd_spi_reg_write;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
        qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)opcode<<8)|((uint8_t)opcode)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)opcode)<<8)| ((uint8_t)(opcode)):opcode;
    }
    else
    {
        qspi_cmd->opcode = opcode;
    }

config_cmd_spi_reg_write:
  return status;
}

static SPINOR_STATUS config_cmd_spi_reg_read(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;

    qspi_cmd->opcode = opcode;
    qspi_cmd->addr_bytes = (cmd_mode == OSPI_REGISTER_READ_ADDR)?p_spinor_dev->config_data->access_param[mode].addr_bytes_reg_addr:p_spinor_dev->config_data->access_param[mode].addr_bytes_reg;
    qspi_cmd->dummy_clocks = (cmd_mode == OSPI_REGISTER_READ_ADDR)?p_spinor_dev->config_data->access_param[mode].reg_read_addr_dummy_cycles:p_spinor_dev->config_data->access_param[mode].reg_read_dummy_cycles;
    qspi_cmd->cmd_mode  = SDR_1BIT;
    qspi_cmd->addr_mode = SDR_1BIT;
    qspi_cmd->data_mode = SDR_1BIT;
    qspi_cmd->write = false;

    switch (p_spinor_dev->mode_enabled)
    {
        case SPI_DEFAULT_SDR:
          break;                                   /* default settings */

        case SPI_QUAD_SDR:
          qspi_cmd->cmd_mode   = SDR_4BIT;
          qspi_cmd->addr_mode  = SDR_4BIT;
          qspi_cmd->data_mode  = SDR_4BIT;
          break;

        case SPI_QUAD_DDR:
          qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en)?((qspi_cmd->dummy_clocks*2)+1):qspi_cmd->dummy_clocks;
          qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          break;

        case SPI_OCTAL_SDR:
          qspi_cmd->cmd_mode     = SDR_8BIT;
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SPI_OCTAL_DDR:
          qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en)?((qspi_cmd->dummy_clocks*2)+1):(qspi_cmd->dummy_clocks*2);
          qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x20F);
          SPINOR_LOG_ERROR("%s: Error, Invalid mode enabled choice for configuring command type REGISTER READ \r\n", __func__);
          goto config_cmd_spi_reg_read;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
        qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)opcode<<8)|((uint8_t)opcode)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)opcode)<<8)| ((uint8_t)(opcode)):opcode;
    }
    else
    {
        qspi_cmd->opcode = opcode;
    }

config_cmd_spi_reg_read:
  return status;
}

static SPINOR_STATUS config_cmd_spi_sfdp_read(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;

    qspi_cmd->opcode = opcode;
    qspi_cmd->addr_bytes = 3;
    qspi_cmd->dummy_clocks = 8;
    qspi_cmd->cmd_mode  = SDR_1BIT;
    qspi_cmd->addr_mode = SDR_1BIT;
    qspi_cmd->data_mode = SDR_1BIT;
    qspi_cmd->write = false;

    switch (p_spinor_dev->mode_enabled)
    {
        case SPI_DEFAULT_SDR:
          break;                                   /* default settings */

        case SPI_QUAD_SDR:
          qspi_cmd->addr_bytes = p_spinor_dev->config_data->access_param[mode].addr_bytes_sfdp;
          qspi_cmd->dummy_clocks = p_spinor_dev->config_data->access_param[mode].sfdp_read_dummy_cycles;
          qspi_cmd->cmd_mode   = SDR_4BIT;
          qspi_cmd->addr_mode  = SDR_4BIT;
          qspi_cmd->data_mode  = SDR_4BIT;
          break;

        case SPI_QUAD_DDR:
          qspi_cmd->addr_bytes = p_spinor_dev->config_data->access_param[mode].addr_bytes_sfdp;
          qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en)?((p_spinor_dev->config_data->access_param[mode].sfdp_read_dummy_cycles*2)+1):p_spinor_dev->config_data->access_param[mode].sfdp_read_dummy_cycles;
          qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          break;

        case SPI_OCTAL_SDR:
          qspi_cmd->addr_bytes = p_spinor_dev->config_data->access_param[mode].addr_bytes_sfdp;
          qspi_cmd->dummy_clocks = p_spinor_dev->config_data->access_param[mode].sfdp_read_dummy_cycles;
          qspi_cmd->cmd_mode     = SDR_8BIT;
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SPI_OCTAL_DDR:
          qspi_cmd->addr_bytes = p_spinor_dev->config_data->access_param[mode].addr_bytes_sfdp;
          qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en)?((p_spinor_dev->config_data->access_param[mode].sfdp_read_dummy_cycles*2)+1):(p_spinor_dev->config_data->access_param[mode].sfdp_read_dummy_cycles*2);
          qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x210);
          SPINOR_LOG_ERROR("%s: Error, Invalid mode enabled choice for configuring command type READ SFDP \r\n", __func__);
          goto config_cmd_spi_sfdp_read;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
        qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)opcode<<8)|((uint8_t)opcode)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)opcode)<<8)| ((uint8_t)(opcode)):opcode;
    }
    else
    {
        qspi_cmd->opcode = opcode;
    }

config_cmd_spi_sfdp_read:
  return status;
}

static SPINOR_STATUS config_cmd_spi_bin_cmd(OSPI_CMD *qspi_cmd, SPI_COMMAND_TYPE cmd_mode, uint8_t opcode, access_param_mode_type mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8_t op_code;

    op_code                = opcode;
    qspi_cmd->addr_bytes   = spinor_bincmd_param.num_addr_bytes;
    qspi_cmd->dummy_clocks = spinor_bincmd_param.dummycycles;
    qspi_cmd->cmd_mode     = SDR_1BIT;
    qspi_cmd->addr_mode    = SDR_1BIT;
    qspi_cmd->data_mode    = SDR_1BIT;
    qspi_cmd->write        = spinor_bincmd_param.is_write_operation;

    switch (p_spinor_dev->mode_enabled)
    {
        case SPI_DEFAULT_SDR:
           if((opcode == PROG_SDR_4B_114_INST && p_spinor_dev->config_data->access_param[mode].write_mode == SDR_1_1_4_MODE) || (opcode == READ_SDR_4B_114_INST_F && p_spinor_dev->config_data->access_param[mode].read_mode == SDR_1_1_4_MODE))
           {
               qspi_cmd->data_mode = SDR_4BIT;
           }
           else if((opcode == PROG_SDR_4B_144_INST && p_spinor_dev->config_data->access_param[mode].write_mode == SDR_1_4_4_MODE) || (opcode == READ_SDR_4B_144_INST && p_spinor_dev->config_data->access_param[mode].read_mode == SDR_1_4_4_MODE))
           {
               qspi_cmd->addr_mode = SDR_4BIT;
               qspi_cmd->data_mode = SDR_4BIT;
           }
           else
           {
               qspi_cmd->cmd_mode     = SDR_1BIT;
               qspi_cmd->addr_mode    = SDR_1BIT;
               qspi_cmd->data_mode    = SDR_1BIT;
           }
           break;                                   /* default settings */

        case SPI_QUAD_SDR:
          qspi_cmd->cmd_mode   = SDR_4BIT;
          qspi_cmd->addr_mode  = SDR_4BIT;
          qspi_cmd->data_mode  = SDR_4BIT;
          break;

        case SPI_QUAD_DDR:
          if (TRUE == spinor_bincmd_param.is_write_operation)
          {
              qspi_cmd->dummy_clocks = 0;
          }
          else if (0 == spinor_bincmd_param.len)
          {
              qspi_cmd->dummy_clocks = 0;
          }
          else
          {
            qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en)?((qspi_cmd->dummy_clocks*2)+1):qspi_cmd->dummy_clocks;
            qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          }
          qspi_cmd->cmd_mode     = DDR_4BIT;
          qspi_cmd->addr_mode    = DDR_4BIT;
          qspi_cmd->data_mode    = DDR_4BIT;
          break;

        case SPI_OCTAL_SDR:
          qspi_cmd->cmd_mode     = SDR_8BIT;
          qspi_cmd->addr_mode    = SDR_8BIT;
          qspi_cmd->data_mode    = SDR_8BIT;
          break;

        case SPI_OCTAL_DDR:
          if (TRUE == spinor_bincmd_param.is_write_operation)
          {
              qspi_cmd->dummy_clocks = 0;
          }
          else if (0 == spinor_bincmd_param.len)
          {
              qspi_cmd->dummy_clocks = 0;
          }
          else
          {
              qspi_cmd->dummy_clocks = (TRUE == p_spinor_dev->dll_config_en) ? ((qspi_cmd->dummy_clocks * 2) + 1) : (qspi_cmd->dummy_clocks * 2);
              qspi_cmd->dummy_clocks = ((TRUE == p_spinor_dev->dll_config_en) && (TRUE == p_spinor_dev->config_data->dqs_sync_qspi_clk))?(qspi_cmd->dummy_clocks+1):qspi_cmd->dummy_clocks;
          }
          qspi_cmd->cmd_mode     = DDR_8BIT;
          qspi_cmd->addr_mode    = DDR_8BIT;
          qspi_cmd->data_mode    = DDR_8BIT;
          break;

        default:
          status = SPINOR_DEVICE_FAIL;
          spinor_log (&p_spinor_dev->debug_log, 0x211);
          SPINOR_LOG_ERROR("%s: Error, Invalid mode enabled choice for configuring command type BINARY CMD \r\n", __func__);
          goto config_cmd_spi_bincmd;
    }

    if ((SPI_OCTAL_SDR == p_spinor_dev->mode_enabled) || (SPI_OCTAL_DDR == p_spinor_dev->mode_enabled))
    {
      qspi_cmd->opcode = ((p_spinor_dev->config_data->octal_dtr_ext)==0x00)?(((uint16_t)op_code<<8)|((uint8_t)op_code)):((p_spinor_dev->config_data->octal_dtr_ext)==0x01)?((~(uint16_t)op_code)<<8)| ((uint8_t)(op_code)):op_code;
    }
    else
    {
      qspi_cmd->opcode = op_code;
    }

config_cmd_spi_bincmd:
  return status;
}
