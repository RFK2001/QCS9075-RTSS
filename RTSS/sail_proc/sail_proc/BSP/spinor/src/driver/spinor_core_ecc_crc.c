/*
===========================================================================
*/
/**
    @file  spinor_core_ecc_crc.c
    @brief This file implements function for ECC and CRC

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_core_ecc_crc.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_api.h"
#include "spinor_core.h"
#include "spinor_dma_pio.h"
#include "spinor_utils.h"
#include "spinor_osal.h"
#include "spinor_init_config.h"
#include "spinor_job.h"
#include "spinor_cmd.h"
#include "spinor_sfdp.h"
#include "debug_log.h"
#include "boot_logger.h"
#include "spinor_diag.h"

static SPINOR_STATUS store_ecc_err_addr(int sector);

/**********************************************************
 * Initializes the ECC and CRC parameters
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_ecc_crc_init(void)
{
  SPINOR_STATUS nor_status = SPINOR_DEVICE_DONE;

#ifdef SPINOR_ECC_ENABLE
  if ((p_spinor_dev->config_data->ecc_info.ecc_supported == TRUE) && (p_spinor_dev->enable_ecc == TRUE))
  {
      nor_status = spinor_core_clear_ECC_regs();
      if (nor_status != SPINOR_DEVICE_DONE)
      {
        spinor_log (&p_spinor_dev->debug_log, 0x600);
        SPINOR_LOG_ERROR("%s: Error, Clear ECC regs failed \r\n", __func__);
        goto spinor_ecc_crc_init_end;
      }

      nor_status = spinor_core_enable_ecc_check();
      if (nor_status != SPINOR_DEVICE_DONE)
      {
        spinor_log (&p_spinor_dev->debug_log, 0x601);
        SPINOR_LOG_ERROR("%s: Error, enable ECC check failed \r\n", __func__);
        goto spinor_ecc_crc_init_end;
      }
  }
#endif

#ifdef SPINOR_CRC_ENABLE
  if ((p_spinor_dev->config_data->crc_info.crc_supported == TRUE) && (p_spinor_dev->enable_crc == TRUE))
  {
      if ((p_spinor_dev->config_data->crc_info.crc_dtr_mode_needed == TRUE) && (p_spinor_dev->mode_enabled == SPI_OCTAL_DDR))
      {
        nor_status = spinor_core_clear_CRC_regs();
        if (nor_status != SPINOR_DEVICE_DONE)
        {
          spinor_log (&p_spinor_dev->debug_log, 0x602);
          SPINOR_LOG_ERROR("%s: Error, clear CRC regs failed \r\n", __func__);
          goto spinor_ecc_crc_init_end;
        }

        nor_status = spinor_core_enable_crc_check();
        if (nor_status != SPINOR_DEVICE_DONE)
        {
          spinor_log (&p_spinor_dev->debug_log, 0x603);
          SPINOR_LOG_ERROR("%s: Error, enable CRC check failed \r\n", __func__);
          goto spinor_ecc_crc_init_end;
        }
      }
  }
#endif

spinor_ecc_crc_init_end:
  return nor_status;
}

#ifdef SPINOR_ECC_ENABLE
/**********************************************************
 * Checks the ECC status bits for occurance of 2-bit ECC error event and finds the address of the error in case of an ECC error.
 * (Also checks for double programming events and calculates the number of 1-bit ECC correction events)
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_check_ECC_Status (void)
{
    uint8 status_mask = 0;
    uint32 ecc_status = 0;
    uint8 stat_bit =0;
    uint32 err_register_cmd = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    err_register_cmd = p_spinor_dev->config_data->ecc_info.ecc_status_reg_rd_opcode;
    status_mask = p_spinor_dev->config_data->ecc_info.ecc_err_bmsk;
    int m = p_spinor_dev->config_data->ecc_info.ecc_number_of_chunks, i;
    int len;

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    for (i = 0; i < m ; i++)
    {
        ecc_status = 0;
        /* Reads the status bit to check for 2-bit ECC error event occurance */
        status = spinor_util_read_reg_addr (err_register_cmd,p_spinor_dev->config_data->ecc_info.ecc_status_reg_addr[i], len, (uint8 *)&ecc_status,sizeof(ecc_status));
        if(status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x604);
            SPINOR_LOG_ERROR("%s: Error, register read failed \r\n", __func__);
            goto ecc_status_check_end;
        }
        stat_bit = ((uint8)ecc_status & status_mask);
        if(stat_bit != 0x00)
        {
            switch(stat_bit)
            {
                /* Macronix double programming, 2 bit error, 1 bit error = 0xA0, 0x10, 0x40 */
                /* ISSI double programming, 2 bit error, 1 bit error = 0x80, 0x04 */
                case 0xA0:
                case 0x10:
                case 0x40:
                case 0x80:
                case 0x04:
                    status = store_ecc_err_addr(i);
                    SPINOR_LOG_INFO("%s: Info, ECC Error occured %d \r\n", __func__, stat_bit);
                    status = SPINOR_ACCESS_ECC_ERROR; /* To indicate occurance of ECC event */
                    break;

                default:
                    /* Undefined ECC event */
                    SPINOR_LOG_ERROR("%s: Error, Undefined ECC Event occured %d \r\n", __func__, stat_bit);
                    status = SPINOR_DEVICE_FAIL;
                    break;
            }
            break;
        }
    }
ecc_status_check_end:
    return status;
}

/**********************************************************
 * Stores the ECC fail address
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS store_ecc_err_addr(int sector)
{
    uint8 type = 2;
    uint32 ecc_status = 0;
    uint32 err_register_cmd = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    err_register_cmd = p_spinor_dev->config_data->ecc_info.ecc_status_reg_rd_opcode;
    int i = sector, j, count1 = 0;
    int len;

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    for(j = i*4 ; j < (i+1)*4 ; j++)
    {
        /* ECC event occured in jth 512MB chunk, stores the error details in a structure */
        ecc_status = 0;
        status = spinor_util_read_reg_addr (err_register_cmd,p_spinor_dev->config_data->ecc_info.ecc_fail_chunk_addr[j], len, (uint8 *)&ecc_status,sizeof(ecc_status));
        if(status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x605);
            SPINOR_LOG_ERROR("%s: Error, register read failure \r\n", __func__);
            goto store_err_addr_end;
        }
        p_spinor_dev->ECC_addresses[count1].chunk_number = j;
        p_spinor_dev->ECC_addresses[count1].ECC_fail_event_address = (uint8)ecc_status;
        p_spinor_dev->ECC_addresses[count1].ECC_event_type = type;
        count1++;

        SPINOR_LOG_INFO("%s: Info, ECC error event occured at %d address \r\n", __func__, ecc_status);
    }

store_err_addr_end:
    return status;
}

/**********************************************************
 * Clears the ECC related bits and registers
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_clear_ECC_regs (void)
{
    uint32 ecc_status = 0;
    uint8 result = 0, temp = 0;
    uint32 ecc_cmd_write = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    ecc_cmd_write = p_spinor_dev->config_data->ecc_info.ecc_status_reg_wr_opcode;
    int len;
    spinor_OperationParamType xMemParams = {.addr = 0, .buffer = &temp, .len = 0, .opcode=CLEAR_ERR_REGS, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    switch(ecc_cmd_write)
    {
        case WRITE_VOLATILE_CFG_CMD:
            /* This command has no data phase. Only write the command */
            status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x606);
                SPINOR_LOG_ERROR("%s: Error, Spinor command transfer failure \r\n", __func__);
                goto clear_ecc_regs_end;
            }
            break;

        case WRITE_CFG2_CMD:
            ecc_status = 0x00;
            /* Clear ECC registers */
            status = spinor_util_write_reg_addr (ecc_cmd_write,p_spinor_dev->config_data->ecc_info.ecc_status_reg_addr[0], len, (uint8 *)&ecc_status, sizeof(ecc_status));
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x607);
                SPINOR_LOG_ERROR("%s: Error, register write failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto clear_ecc_regs_end;
            }
            break;

        default:
            status = SPINOR_DEVICE_FAIL;
    }
clear_ecc_regs_end:
  return status;
}

/**********************************************************
 * Enables the ECC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_enable_ecc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32 err_cmd_read = 0, ecc_cmd_write = 0, err_init_register_addr = 0;
    uint8 stat_bit = 0;
    uint32 ecc_status = 0;
    err_init_register_addr = p_spinor_dev->config_data->ecc_info.ecc_init_reg_addr;
    err_cmd_read = p_spinor_dev->config_data->ecc_info.ecc_status_reg_rd_opcode;
    ecc_cmd_write = p_spinor_dev->config_data->ecc_info.ecc_status_reg_wr_opcode;
    int len;

    if((p_spinor_dev->enable_ecc == TRUE) && (p_spinor_dev->ecc_enabled_status_local == FALSE))
    {
        if(p_spinor_dev->perfmode_enabled == FALSE)
            len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
        else
            len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

        status = spinor_util_read_reg_addr (err_cmd_read, err_init_register_addr, len, (uint8 *)&ecc_status,sizeof(ecc_status));
        if(status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x608);
            SPINOR_LOG_ERROR("%s: Error, register read failure \r\n", __func__);
            status = SPINOR_DEVICE_FAIL;
            goto ecc_enable_end;
        }

        stat_bit = ((uint8)ecc_status & p_spinor_dev->config_data->ecc_info.ecc_enable_bmsk);
        if (stat_bit != 0x00)
        {
            ecc_status &= !(p_spinor_dev->config_data->ecc_info.ecc_enable_bmsk);  /* Clear ECC bits to enable it */
            status = spinor_util_write_reg_addr (ecc_cmd_write, err_init_register_addr, len, (uint8 *)&ecc_status, sizeof(ecc_status));
            if(status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x609);
                SPINOR_LOG_ERROR("%s: Error, register write failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto ecc_enable_end;
            }
        }

        status = spinor_core_check_ECC_Status();
        if(status != SPINOR_DEVICE_DONE)
        {
            /* Fatal error should be triggered */
            spinor_log (&p_spinor_dev->debug_log, 0x60A);
            SPINOR_LOG_ERROR("%s: Error, ECC Error occured \r\n", __func__);
            status = SPINOR_DEVICE_FAIL;
            goto ecc_enable_end;

        }
        p_spinor_dev->ecc_enabled_status_local = TRUE;
        goto ecc_enable_end;
    }
    else if((p_spinor_dev->enable_ecc == TRUE) && (p_spinor_dev->ecc_enabled_status_local == TRUE))
    {
        /* ECC already enabled */
        goto ecc_enable_end;
    }
    else
    {
        /* If p_spinor_dev->enable_ecc == FALSE (global flag disabled) */
        p_spinor_dev->ecc_enabled_status_local = FALSE;
        goto ecc_enable_end;
    }

ecc_enable_end:
return status;
}

/**********************************************************
 * Disables the ECC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_disable_ecc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32 ecc_status = 0;
    uint8 stat_bit = 0;
    uint32 err_cmd_read = 0, ecc_cmd_write = 0, err_init_register_addr = 0;
    err_init_register_addr = p_spinor_dev->config_data->ecc_info.ecc_init_reg_addr;
    err_cmd_read = p_spinor_dev->config_data->ecc_info.ecc_status_reg_rd_opcode;
    ecc_cmd_write = p_spinor_dev->config_data->ecc_info.ecc_status_reg_wr_opcode;
    int len;

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    if((p_spinor_dev->enable_ecc == TRUE) && (p_spinor_dev->ecc_enabled_status_local == TRUE))
    {
        status = spinor_util_read_reg_addr (err_cmd_read, err_init_register_addr, len, (uint8 *)&ecc_status, sizeof(ecc_status));
        if(status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x60B);
            SPINOR_LOG_ERROR("%s: Error, register read failure \r\n", __func__);
            status = SPINOR_DEVICE_FAIL;
            goto ecc_disable_end;
        }

        stat_bit = ((uint8)ecc_status & p_spinor_dev->config_data->ecc_info.ecc_enable_bmsk);
        if (stat_bit != p_spinor_dev->config_data->ecc_info.ecc_enable_bmsk)
        {
            ecc_status |= p_spinor_dev->config_data->ecc_info.ecc_enable_bmsk;  /* Set ECC Bits to disable it */
            status = spinor_util_write_reg_addr (ecc_cmd_write, err_init_register_addr, len, (uint8 *)&ecc_status, sizeof(ecc_status));
            if(status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x60C);
                SPINOR_LOG_ERROR("%s: Error, Register write failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto ecc_disable_end;
            }
        }
        p_spinor_dev->ecc_enabled_status_local = FALSE;
        goto ecc_disable_end;
    }
    else if((p_spinor_dev->enable_ecc == TRUE) && (p_spinor_dev->ecc_enabled_status_local == FALSE))
    {
        /* ECC already disabled */
        goto ecc_disable_end;
    }
    else
    {
        /* If p_spinor_dev->enable_ecc == FALSE (global flag disabled) */
        p_spinor_dev->ecc_enabled_status_local = FALSE;
        goto ecc_disable_end;
    }

ecc_disable_end:
return status;
}
#endif /* SPINOR_ECC_ENABLE */

#ifdef SPINOR_CRC_ENABLE
/**********************************************************
 * Enables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_enable_crc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32 crc_cmd_read = 0, crc_cmd_write = 0;
    uint32 crc_reg_status = 0;
    crc_cmd_read = p_spinor_dev->config_data->crc_info.crc_status_reg_rd_opcode;
    crc_cmd_write = p_spinor_dev->config_data->crc_info.crc_status_reg_wr_opcode;
    int i = 0, len;
    size_t n = sizeof(p_spinor_dev->config_data->crc_info.crc_init_reg_addr) / sizeof(uint32);

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    bool crc_status = FALSE;
    crc_status = GetCRCFlag();

    if((p_spinor_dev->enable_crc == TRUE) && (crc_status == FALSE))
    {
        while((i < n) && (p_spinor_dev->config_data->crc_info.crc_init_reg_addr[i] != 0xFF))
        {
            status = spinor_util_read_reg_addr (crc_cmd_read, p_spinor_dev->config_data->crc_info.crc_init_reg_addr[i], len, (uint8 *)&crc_reg_status,sizeof(crc_reg_status));
            if(status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x60D);
                SPINOR_LOG_ERROR("%s: Error, Register read failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto crc_enable_end;
            }

            if(p_spinor_dev->config_data->crc_info.crc_zero_to_enable == FALSE) /* Macronix vendor */
            {
                crc_reg_status |= p_spinor_dev->config_data->crc_info.crc_enable_bmsk[i];
            }
            else /* ISSI vendor */
            {
                crc_reg_status &= ~(p_spinor_dev->config_data->crc_info.crc_enable_bmsk[i]);
            }

            status = spinor_util_write_reg_addr (crc_cmd_write, p_spinor_dev->config_data->crc_info.crc_init_reg_addr[i], len, (uint8 *)&crc_reg_status, sizeof(crc_reg_status));
            if(status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x60E);
                SPINOR_LOG_ERROR("%s: Error, Register write failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto crc_enable_end;
            }

            i++;
        }
        SetCRCFlag(TRUE);
        SPINOR_LOG_INFO("%s: Info, CRC enabled \r\n", __func__);
        goto crc_enable_end;
    }
    else if((p_spinor_dev->enable_crc == TRUE) && (crc_status == TRUE))
    {
        /* CRC already enabled */
        SPINOR_LOG_INFO("%s: Info, CRC enabled \r\n", __func__);
        goto crc_enable_end;
    }
    else
    {
        /* If p_spinor_dev->enable_crc == FALSE (global flag disabled) */
        SetCRCFlag(FALSE);
        goto crc_enable_end;
    }

crc_enable_end:
return status;
}

/**********************************************************
 * Disables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_disable_crc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32 crc_cmd_read = 0, crc_cmd_write = 0;
    uint32 crc_reg_status = 0;
    crc_cmd_read = p_spinor_dev->config_data->crc_info.crc_status_reg_rd_opcode;
    crc_cmd_write = p_spinor_dev->config_data->crc_info.crc_status_reg_wr_opcode;
    int i = 0, len;
    size_t n = sizeof(p_spinor_dev->config_data->crc_info.crc_init_reg_addr) / sizeof(uint32);

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    bool crc_status = FALSE;
    crc_status = GetCRCFlag();

    if((p_spinor_dev->enable_crc == TRUE) && (crc_status == TRUE))
    {
        while((i < n) && (p_spinor_dev->config_data->crc_info.crc_init_reg_addr[i] != 0xFF))
        {
            status = spinor_util_read_reg_addr (crc_cmd_read, p_spinor_dev->config_data->crc_info.crc_init_reg_addr[i], len, (uint8 *)&crc_reg_status,sizeof(crc_reg_status));
            if(status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x60F);
                SPINOR_LOG_ERROR("%s: Error, Register read failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto crc_disable_end;
            }

            if(p_spinor_dev->config_data->crc_info.crc_zero_to_enable == TRUE) /* ISSI vendor */
            {
                crc_reg_status |= p_spinor_dev->config_data->crc_info.crc_enable_bmsk[i];
            }
            else /* Macronix vendor */
            {
                crc_reg_status &= ~(p_spinor_dev->config_data->crc_info.crc_enable_bmsk[i]);
            }

            status = spinor_util_write_reg_addr (crc_cmd_write, p_spinor_dev->config_data->crc_info.crc_init_reg_addr[i], len, (uint8 *)&crc_reg_status, sizeof(crc_reg_status));
            if(status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x610);
                SPINOR_LOG_ERROR("%s: Error, Register write failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto crc_disable_end;
            }

            i++;
        }
        SetCRCFlag(FALSE);
        SPINOR_LOG_INFO("%s: Info, CRC disabled \r\n", __func__);
        goto crc_disable_end;
    }
    else if((p_spinor_dev->enable_crc == TRUE) && (crc_status == FALSE))
    {
        /* CRC already locally disabled */
        SPINOR_LOG_INFO("%s: Info, CRC disabled \r\n", __func__);
        goto crc_disable_end;
    }
    else
    {
        /* If p_spinor_dev->enable_crc == FALSE (global flag disabled), already disabled */
        SetCRCFlag(FALSE);
        goto crc_disable_end;
    }

crc_disable_end:
return status;
}

/**********************************************************
 * Checks the CRC status bits for occurance of a CRC error event and sends back an error status in case of a CRC error event.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_check_CRC_Status (void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32 crc_cmd_read = 0;
    uint32 crc_status = 0;
    uint8 stat_bit = 0, status_mask = 0, status_reg_addr = 0;
    crc_cmd_read = p_spinor_dev->config_data->crc_info.crc_status_reg_rd_opcode;
    status_mask = p_spinor_dev->config_data->crc_info.crc_err_bmsk;
    status_reg_addr = p_spinor_dev->config_data->crc_info.crc_status_reg_addr;
    int len;

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    crc_status = 0;
    /* Reads the status bit to check for CRC error event occurance */
    status = spinor_util_read_reg_addr (crc_cmd_read,status_reg_addr, len, (uint8 *)&crc_status, sizeof(crc_status));
    if(status != SPINOR_DEVICE_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x611);
        SPINOR_LOG_ERROR("%s: Error, Register read failure \r\n", __func__);
        goto crc_status_check_end;
    }
    stat_bit = ((uint8)crc_status & status_mask);
    if(stat_bit != 0x00)
    {
        switch(stat_bit)
        {
            /* Macronix CRC Err = 0x10 */
            /* ISSI CRC Err = 0x03, 0x02, 0x01 */
            case 0x30:
            case 0x20:
            case 0x10:
                SPINOR_LOG_INFO("%s: Info, CRC Error detected %d \r\n", __func__, stat_bit);
                status = SPINOR_ACCESS_CRC_ERROR; /* To indicate occurance of CRC Error = SPINOR_ACCESS_CRC_ERROR */
                break;

            default:
                /* Undefined CRC event */
                SPINOR_LOG_ERROR("%s: Error, Undefined CRC Event %d \r\n", __func__, stat_bit);
                status = SPINOR_DEVICE_FAIL;
                break;
        }
    }

crc_status_check_end:
    return status;
}

/**********************************************************
 * Clears the CRC related bits and registers
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_clear_CRC_regs (void)
{
    uint32 crc_status = 0;
    uint8 temp = 0;
    uint32 crc_cmd_write = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    crc_cmd_write = p_spinor_dev->config_data->crc_info.crc_status_reg_wr_opcode;
    int len;
    spinor_OperationParamType xMemParams = {.addr = 0, .buffer = &temp, .len = 0, .opcode=CLEAR_ERR_REGS, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    if(p_spinor_dev->perfmode_enabled == FALSE)
        len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
    else
        len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;


    switch(crc_cmd_write)
    {
        case WRITE_VOLATILE_CFG_CMD: /* ISSI Vendor */
            /* This command has no data phase. Only write the command */
            status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x612);
                SPINOR_LOG_ERROR("%s: Error, command transfer 1 failure \r\n", __func__);
                goto clear_crc_regs_end;
            }

            xMemParams = (spinor_OperationParamType){.addr = 0, .buffer = &temp, .len = 0, .opcode=CLEAR_FLAG_STATUS_REG, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
            status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x613);
                SPINOR_LOG_ERROR("%s: Error, command transfer 2 failure \r\n", __func__);
                goto clear_crc_regs_end;
            }
            break;

        case WRITE_CFG2_CMD: /* Macronix Vendor */
            crc_status = 0x00;
            /* Clear CRC registers */
            status = spinor_util_write_reg_addr (crc_cmd_write,p_spinor_dev->config_data->crc_info.crc_status_reg_addr, len, (uint8 *)&crc_status, sizeof(crc_status));
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x614);
                SPINOR_LOG_ERROR("%s: Error, Register write failure \r\n", __func__);
                status = SPINOR_DEVICE_FAIL;
                goto clear_crc_regs_end;
            }
            break;

        default:
            status = SPINOR_DEVICE_FAIL;
    }
clear_crc_regs_end:
  return status;
}
#endif /* SPINOR_CRC_ENABLE */