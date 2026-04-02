/*
===========================================================================
*/
/**
    @file  spinor_sfdp.c
    @brief Serial Flash Discoverable Parameters

*/
/*
    ===========================================================================

    Copyright (c) 2020-2025 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_sfdp.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include <string.h>
#include "spinor_core.h"
#include "spinor_utils.h"
#include "spinor_init_config.h"
#include "spinor_job.h"
#include "spinor_sfdp.h"
#include "spinor_sfdp_util.h"
#include "spinor_cmd.h"
#include "spinor_diag.h"
#include "libfdt.h"
#include "fdt_utils.h"

/**********************************************************
 * Read the Parameters using SFDP
 *
 * @param device_id [IN/OUT]
 *   spinor Device ID
 *
 * @param device_id_len [IN]
 *   Number of bytes to read
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/


spinor_sfdp_t g_sfdp_data;

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
SPINOR_STATUS spinor_sfdp_read_signature(uint32* signature)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinor_sfdp_header *header;
    spinor_sfdp_header header_data;
    header = &header_data;
    spinor_OperationParamType xMemParams = {.addr = 0, .buffer = (uint8*)header, .len = sizeof(spinor_sfdp_header), .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    /* read sfdp signature */
    memset(header, 0, sizeof(spinor_sfdp_header));

    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x800);
        SPINOR_LOG_ERROR("%s: Error, command transfer for sfdp signature read failure, status = 0x%x \r\n", __func__, status);
        goto read_sfdp_end;
    }

    *signature = header->signature;

read_sfdp_end:
return status;
}

SPINOR_STATUS spinor_sfdp_read_config_infineon(void)
{
    uint32 config_reg3 = 0, config_reg1 = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    /* Read configuration register 3 */
    status = spinor_util_read_reg_addr (READ_CFG_CMD, g_sfdp_data.config_info[0].map_config_detect_cmd_addr, 1,(uint8*)&config_reg3,sizeof(config_reg3));
    if (status != SPINOR_DEVICE_DONE)
    {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x83E);
        goto spinor_sfdp_read_config_infineon_end;
    }

    /* Read configuration register 1 */
    status = spinor_util_read_reg_addr (READ_CFG_CMD,g_sfdp_data.config_info[1].map_config_detect_cmd_addr, 1,(uint8*)&config_reg1,sizeof(config_reg1));
    if (status != SPINOR_DEVICE_DONE)
    {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x83F);
        goto spinor_sfdp_read_config_infineon_end;
    }

    /* Check if the required sector map is configured and enabled: CFR3V[3] = 0, CFR1V[6] = 1 and CFR1V[2] = 0 */
    if((config_reg3 & 0x8) != 0 || (config_reg1 & 0x44) != 0x40)
    {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x840);
        goto spinor_sfdp_read_config_infineon_end;
    }

    /* Configuration is correct */

spinor_sfdp_read_config_infineon_end:
    return status;
}

/**********************************************************
 * Decoding the 8D-8D-8D sequence
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
void spinor_sfdp_decode_octal_ddr_seq(void)
{
    int rows = sizeof(p_spinor_dev->config_data->octal_ddr_cmd_seq) / sizeof(p_spinor_dev->config_data->octal_ddr_cmd_seq[0]);

    /* Decoding command sequences */
    for(int i = 0; i < rows; i++)
    {
        /* Decoding Length */
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][0] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_len;

        /* Decoding Opcode */
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][1] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_1;

        /* Decoding 3 bytes of address */
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][2] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_2;
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][3] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_3;
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][4] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_4;

        /* Decoding remaining data bytes */
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][5] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_5;
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][6] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_6;
        p_spinor_dev->config_data->octal_ddr_cmd_seq[i][7] = g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq[i].cmd_seq_byte_7;
    }

    return;
}

SPINOR_STATUS spinor_sfdp_read_tables(uint32 device_id, spinor_sfdp_t **pSfdpTable)
{
  spinor_sfdp_param_header paramh = {0};
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  uint32_t offset;
  uint32_t count;
  int retval=0;
  uint32_t spinor_prop_val=0;
  void *pDTB = NULL;
  int32_t root_offset = 0;
  boolean spinor_x10Table_wa_en = FALSE;
  spinor_OperationParamType xMemParams = {0};
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);
  config_map_desc_header sector_map_header = {0};

  if (pSfdpTable == NULL)
  {
    DEBUG_LOG(SAIL_ERROR,"%s: Error - pSfdpTable is NULL\r\n", __func__);
    goto end;
  }

  *pSfdpTable = NULL;

  memset(&g_sfdp_data, 0, sizeof(g_sfdp_data));
  /* Sanity check the structures. if compiler sizes are wrong the Compiler will
   * only keep the code inside this IF, and remove the rest. */
  if(sizeof(spinor_sfdp_header) != 8 ||
     sizeof(spinor_sfdp_param_header) != 8 ||
     sizeof(spinor_sfdp_basic_param) != (20*4) ||
     sizeof(spinor_sfdp_4byte_inst) != (2*4) ||
     sizeof(spinor_sfdp_xspi_profile_1_0) != (5*4))
  {
    spinor_log (&p_spinor_dev->debug_log, 0x801);
    DEBUG_LOG(SAIL_ERROR,"%s: Error - SFDP table size mis-match \r\n", __func__);
    goto end;
  }

  if(manufacturer == MANUFACTURER_ID_INFINEON)
  {
      if(sizeof(config_detect_cmd_desc) != (2*4) ||
         sizeof(config_map_desc_header) != (1*4) ||
         sizeof(config_map_desc_region) != (1*4))
      {
        spinor_log (&p_spinor_dev->debug_log, 0x802);
        DEBUG_LOG(SAIL_ERROR,"%s: Error - SFDP table size mis-match \r\n", __func__);
        goto end;
      }
  }

  /* Read the SFDP header and validate it */
  /* Command | data addr | data buffer | length | opcode */
  xMemParams = (spinor_OperationParamType){.addr = 0, .buffer = (uint8*)&g_sfdp_data.header_data, .len = sizeof(spinor_sfdp_header), .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x803);
    SPINOR_LOG_ERROR("%s: Error, command transfer for SFDP header failure, status = 0x%x \r\n", __func__, status);
    goto end;
  }

  /* Header was read, validate it. */
  if (g_sfdp_data.header_data.signature != SFDP_HEADER_SIGNATURE ||
      (g_sfdp_data.header_data.major_rev < SFDP_HEADER_MAJOR_REV &&
       g_sfdp_data.header_data.minor_rev < SFDP_HEADER_MINOR_REV_D))
  {
    status = SPINOR_DEVICE_NOT_SUPPORTED;
    spinor_log (&p_spinor_dev->debug_log, 0x804);
    SPINOR_LOG_ERROR("%s: Error - SFDP header verification failed. signature = 0x%x, major_ver = 0x%x, minor_rev = 0x%x \r\n",
              __func__, g_sfdp_data.header_data.signature, g_sfdp_data.header_data.major_rev, g_sfdp_data.header_data.minor_rev);
    goto end;
  }

  /* Loop through each parameter header struct to find out basic param table,
   * 4 bytes instruction table and xSPI profile1.0 table information and offset. */
  for (count = 0; count <= g_sfdp_data.header_data.num_param_headers; count++)
  {
    offset = sizeof(spinor_sfdp_header) + count * sizeof(spinor_sfdp_param_header);
    xMemParams = (spinor_OperationParamType){.addr = offset, .buffer = (uint8*)&paramh, .len = sizeof(spinor_sfdp_param_header), .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x805);
      SPINOR_LOG_ERROR("%s: Error, command transfer for profile1.0 read failure, status = 0x%x \r\n", __func__, status);
      goto end;
    }

    /* This is incorrect. We need to enforce 216D. The revision is 8. */
    if (paramh.major_rev != SFDP_BASIC_PARAM_MAJOR_REV &&
        paramh.minor_rev < SFDP_BASIC_PARAM_MINOR_REV)
    {
      continue;
    }

    /* Look for the Basic parameter Table offset. */
    if (paramh.param_id_lsb == SFDP_BASIC_PARAM_LSB &&
        paramh.param_id_msb == SFDP_BASIC_PARAM_MSB)
    {
      memcpy(&g_sfdp_data.bparam_paramh, &paramh, sizeof(paramh));
      g_sfdp_data.basic_param_offset = paramh.table_pointer;
      g_sfdp_data.basic_param_size = paramh.table_length * sizeof(uint32);
    }

    /* Look for 4-byte Address Instruction Parameter Header. */
    if (paramh.param_id_lsb == SFDP_4BYTE_INST_LSB &&
        paramh.param_id_msb == SFDP_4BYTE_INST_MSB)
    {
      memcpy(&g_sfdp_data.inst4b_paramh, &paramh, sizeof(paramh));
      g_sfdp_data.inst_4byte_offset = paramh.table_pointer;
      g_sfdp_data.inst_4byte_size = paramh.table_length * sizeof(uint32);
    }

    /* Look for xSPI profile 1.0 table */
    if (paramh.param_id_lsb == SFDP_XSPI_P1_INST_LSB &&
        paramh.param_id_msb == SFDP_XSPI_P1_INST_MSB)
    {
      memcpy(&g_sfdp_data.profile10_paramh, &paramh, sizeof(paramh));
      g_sfdp_data.profile10_offset = paramh.table_pointer;
      g_sfdp_data.profile10_size = paramh.table_length * sizeof(uint32);
    }

    if (g_sfdp_data.basic_param_size > 0UL &&
      g_sfdp_data.inst_4byte_size > 0UL && g_sfdp_data.profile10_size > 0UL)
    {
        if(manufacturer == MANUFACTURER_ID_INFINEON)
        {
            /* Look for Command Sequences to change to Octal DDR(8D-8D-8D) mode table */
            if (paramh.param_id_lsb == SFDP_OCTAL_DDR_CMD_SEQ_LSB &&
                paramh.param_id_msb == SFDP_OCTAL_DDR_CMD_SEQ_MSB)
            {
              memcpy(&g_sfdp_data.octal_ddr_paramh, &paramh, sizeof(paramh));
              g_sfdp_data.octal_ddr_offset = paramh.table_pointer;
              g_sfdp_data.octal_ddr_size = paramh.table_length * sizeof(uint32);
            }

            /* Look for JEDEC Sector Map table */
            if (paramh.param_id_lsb == SFDP_SECTOR_MAP_LSB &&
                paramh.param_id_msb == SFDP_SECTOR_MAP_MSB)
            {
              memcpy(&g_sfdp_data.sector_map_paramh, &paramh, sizeof(paramh));
              g_sfdp_data.sector_map_offset = paramh.table_pointer;
              g_sfdp_data.sector_map_size = paramh.table_length * sizeof(uint32);
            }

            if (g_sfdp_data.basic_param_size > 0UL &&
              g_sfdp_data.inst_4byte_size > 0UL && g_sfdp_data.profile10_size > 0UL &&
              g_sfdp_data.octal_ddr_size > 0UL && g_sfdp_data.sector_map_size > 0UL)
            {
              /* Got all required sfdp tables. exit the for loop */
              break;
            }
        }
        else
        {
            /* Got all required sfdp tables. exit the for loop */
            break;
        }
    }
  }
  /* After the for loop, check if all three manadatory tables are presented. If not return error. */
  if (g_sfdp_data.basic_param_size == 0UL || g_sfdp_data.inst_4byte_size == 0UL)
  {
    status = SPINOR_DEVICE_NOT_SUPPORTED;
    spinor_log (&p_spinor_dev->debug_log, 0x806);
    SPINOR_LOG_ERROR("%s: Error - mandatory table, basic tbl size = %d, 4 byte inst tbl size = %d, major ver = %d, rev = %d\r\n",
              __func__, g_sfdp_data.basic_param_size, g_sfdp_data.inst_4byte_size,
              g_sfdp_data.header_data.major_rev, g_sfdp_data.header_data.minor_rev);
    goto end;
  }

  if(manufacturer == MANUFACTURER_ID_INFINEON)
  {
      if(g_sfdp_data.sector_map_size == 0UL || g_sfdp_data.octal_ddr_size == 0UL)
      {
          status = SPINOR_DEVICE_NOT_SUPPORTED;
          spinor_log (&p_spinor_dev->debug_log, 0x807);
          DEBUG_LOG(SAIL_ERROR,"%s: Error - mandatory table sector map tbl size = %d, Octal DDR tbl size = %d, major ver = %d, rev = %d\r\n",
              __func__, g_sfdp_data.sector_map_size, g_sfdp_data.octal_ddr_size, g_sfdp_data.header_data.major_rev, g_sfdp_data.header_data.minor_rev);
          goto end;
      }
  }

  /* Compute the number of bytes of read for the basic parameter table */
  if (g_sfdp_data.basic_param_size > sizeof(spinor_sfdp_basic_param))
  {
    g_sfdp_data.basic_param_size = sizeof(spinor_sfdp_basic_param);
  }
  /* Read the basic parameter table. */
  xMemParams = (spinor_OperationParamType){.addr =  g_sfdp_data.basic_param_offset, .buffer = (uint8*)&g_sfdp_data.bparam_data, .len = g_sfdp_data.basic_param_size, .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x808);
    SPINOR_LOG_ERROR("%s: Error, command transfer basic parameter table read failure, status = 0x%x \r\n", __func__, status);
    goto end;
  }

  /* Compute the number of bytes of read for the 4 bytes instruction table */
  if (g_sfdp_data.inst_4byte_size > sizeof(spinor_sfdp_4byte_inst))
  {
    g_sfdp_data.inst_4byte_size = sizeof(spinor_sfdp_4byte_inst);
  }
  /* Read the 4-byte address instruction table. */
  xMemParams = (spinor_OperationParamType){.addr =  g_sfdp_data.inst_4byte_offset, .buffer = (uint8*)&g_sfdp_data.inst4b_data, .len = g_sfdp_data.inst_4byte_size, .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x809);
    SPINOR_LOG_ERROR("%s: Error, command transfer 4-byte instruction table read failure, status = 0x%x \r\n", __func__, status);
    goto end;
  }

  *pSfdpTable = &g_sfdp_data;

  if (g_sfdp_data.inst4b_data.read_114_support || g_sfdp_data.inst4b_data.read_144_support)
  {
      //device is QSPI
      status = SPINOR_DEVICE_DONE;
      goto end;
  }

  /* Make profile 1.0 still optional. For this card, only fail it if the static lookup table does not contain this card */
  if (g_sfdp_data.profile10_size > 0)
  {
    /* Compute the number of bytes of read for the xSPI profile 1.0 table */
    if (g_sfdp_data.profile10_size > sizeof(spinor_sfdp_xspi_profile_1_0))
    {
      g_sfdp_data.profile10_size = sizeof(spinor_sfdp_xspi_profile_1_0);
    }
    /* Read the xSPI profile 1.0 table. */
    xMemParams = (spinor_OperationParamType){.addr =  g_sfdp_data.profile10_offset, .buffer = (uint8*)&g_sfdp_data.profile10_data, .len = g_sfdp_data.profile10_size, .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x80A);
      SPINOR_LOG_ERROR("%s: Error in xSPI profile 1.0 table read command, status = 0x%x \r\n",__func__, status);
      goto end;
    }

    status = SPINOR_DEVICE_DONE;
  }
  else
  {
    status = SPINOR_DEVICE_MISSING_REQUIRED_SFDP_TABLE;
    spinor_log (&p_spinor_dev->debug_log, 0x80B);
    SPINOR_LOG_ERROR("%s: Error! Missing required xSPI profile 1.0 in SFDP, major ver = %d, rev = %d\r\n",
              __func__, g_sfdp_data.header_data.major_rev, g_sfdp_data.header_data.minor_rev);
    goto end;
  }

  if(manufacturer == MANUFACTURER_ID_INFINEON)
  {
      /* Read the sector map table comprising of:
         3 Config detect DWORDS
         1 Config 0 header DWORD
         3 Config 0 region DWORDS
         1 Config 3 header DWORD
         3 Config 3 region DWORDS
         1 Config 1 header DWORD
         5 Config 1 region DWORDS
         1 Config 4 header DWORD
         1 Config 4 region DWORDS
      */
      /* Read the configuration DWORDS (6) */
      int config_det_id = 0, region_id = 0, header_id = 0;
      uint32 offset_addr = 0, region_addr = 0;
      do
      {
          offset_addr = g_sfdp_data.sector_map_offset + config_det_id*(sizeof(config_detect_cmd_desc));
          xMemParams = (spinor_OperationParamType){.addr =  offset_addr, .buffer = (uint8*)&g_sfdp_data.config_info[config_det_id], .len = sizeof(config_detect_cmd_desc), .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
          status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
          if (SPINOR_DEVICE_DONE != status)
          {
            spinor_log (&p_spinor_dev->debug_log, 0x80C);
            SPINOR_LOG_ERROR("%s: Error, Sector map config detect DWORD %d read failure, status = 0x%x \r\n", __func__, config_det_id, status);
            goto end;
          }
          config_det_id++;
      }while(g_sfdp_data.config_info[config_det_id-1].desc_end_indicator == 0 && config_det_id < INFI_CONFIG_DETECT_DWORDS);

      if(config_det_id == INFI_CONFIG_DETECT_DWORDS && g_sfdp_data.config_info[config_det_id-1].desc_end_indicator == 0)
      {
          /* Infineon has only 3 configuration DWORDS */
          status = SPINOR_DEVICE_FAIL;
          SPINOR_LOG_ERROR("%s: Error, Infineon has only 3 configuration DWORDS, Invalid config \r\n", __func__);
          goto end;
      }

      /* Reading DWORDS for Config 1 -> Required to be used; config_ID = 0x2 */
      int reg_count = 0;
      for(header_id = 0; header_id < INFI_MAX_NUM_CONFIGS; header_id++)
      {
          offset_addr = g_sfdp_data.sector_map_offset + (INFI_CONFIG_DETECT_DWORDS*(sizeof(config_detect_cmd_desc))) + (header_id*sizeof(config_map_desc_header)) + (reg_count*sizeof(config_map_desc_region));
          xMemParams = (spinor_OperationParamType){.addr =  offset_addr, .buffer = (uint8*)&sector_map_header, .len = sizeof(config_map_desc_header), .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
          status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
          if (SPINOR_DEVICE_DONE != status)
          {
            spinor_log (&p_spinor_dev->debug_log, 0x80D);
            SPINOR_LOG_ERROR("%s: Error, Config Header %d read failure, status = 0x%x \r\n", __func__, header_id, status);
            goto end;
          }

          reg_count += sector_map_header.region_count + 1;

          if(sector_map_header.config_ID == 0x2)
          {
              memcpy(&g_sfdp_data.config_header_data, &sector_map_header, sizeof(sector_map_header));
              for(region_id = 0; region_id <= g_sfdp_data.config_header_data.region_count; region_id++)
              {
                  region_addr = offset_addr + sizeof(config_map_desc_header) + region_id*sizeof(config_map_desc_region);
                  xMemParams = (spinor_OperationParamType){.addr =  region_addr, .buffer = (uint8*)&g_sfdp_data.config_region_data[region_id], .len = sizeof(config_map_desc_region), .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
                  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
                  if (SPINOR_DEVICE_DONE != status)
                  {
                    spinor_log (&p_spinor_dev->debug_log, 0x80E);
                    SPINOR_LOG_ERROR("%s: Error, Config region %d read failure, status = 0x%x \r\n", __func__, region_id, status);
                    goto end;
                  }
              }
              status = SPINOR_DEVICE_DONE;
              break;
          }
      }
      if(header_id == INFI_MAX_NUM_CONFIGS)
      {
          /* Did not find config_ID = 0x2 */
          spinor_log (&p_spinor_dev->debug_log, 0x80F);
          SPINOR_LOG_ERROR("%s: Error, Config region 0x2 not found \r\n", __func__);
          status = SPINOR_DEVICE_FAIL;
          goto end;
      }

	  /* Compute the number of bytes of read for the 8D-8D-8D Command sequence table */
      if (g_sfdp_data.octal_ddr_size > sizeof(spinor_octal_ddr_cmd_seq))
      {
        g_sfdp_data.octal_ddr_size = sizeof(spinor_octal_ddr_cmd_seq);
      }

      /* Read the 8D-8D-8D Command sequence table */
      xMemParams = (spinor_OperationParamType){.addr =  g_sfdp_data.octal_ddr_offset, .buffer = (uint8*)&g_sfdp_data.octal_ddr_sequence.spinor_ddr_cmd_seq, .len = g_sfdp_data.octal_ddr_size, .opcode=READ_SFDP_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
      status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_SFDP, &xMemParams);
      if (SPINOR_DEVICE_DONE != status)
      {
        spinor_log (&p_spinor_dev->debug_log, 0x810);
        SPINOR_LOG_ERROR("%s: Error, command transfer 8D-8D-8D Command sequence table read failure, status = 0x%x \r\n", __func__, status);
        goto end;
      }
  }

end:
  return status;
}

#ifdef SPINOR_SFDP_UNUSED_FUNCTIONS
SPINOR_STATUS spinor_parse_sfdp(spinor_config_data *config, uint32_t device_id, spinor_sfdp_t *sfdp_data_read)
{
  spinor_drv_info *spinord = p_spinor_dev;
  spinor_sfdp_basic_param *bparam;
  spinor_sfdp_4byte_inst *inst4b;
  uint32 offset, count;
  uint32 page_size;
  SPINOR_STATUS status;
  SPINOR_STATUS ret_status = SPINOR_DEVICE_FAIL;
  spinor_config_data *config_data;
  uint32 basic_param_offset = 0, basic_param_size;
  uint32 inst_4byte_offset = 0, inst_4byte_size;
  uint64 density_in_bytes;
  uint8 addr_bytes;

  /* Sanity check the structures. if compiler sizes are wrong the Compiler will
   * only keep the code inside this IF, and remove the rest. */
  if(sizeof(spinor_sfdp_header) != 8 ||
     sizeof(spinor_sfdp_param_header) != 8 ||
     sizeof(spinor_sfdp_basic_param) != (20*4) ||
     sizeof(spinor_sfdp_4byte_inst) != (2*4))
  {
    spinor_log (&p_spinor_dev->debug_log, 0x811);
    return ret_status;
  }

  bparam = &sfdp_data_read->bparam_data;
  inst4b = &sfdp_data_read->inst4b_data;

  /* Basic device config to read SFDP. */
  config_data = p_spinor_dev->config_data;
  memset(config_data, 0, sizeof(spinor_config_data));
  config_data->magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER;
  config_data->access_param[0].addr_bytes = 3;
  config_data->access_param[0].read_mode = SDR_1_1_1_MODE;
  config_data->access_param[0].write_mode = SDR_1_1_1_MODE;
  config_data->access_param[1].addr_bytes = 3;
  config_data->access_param[1].read_mode = SDR_1_1_1_MODE;
  config_data->access_param[1].write_mode = SDR_1_1_1_MODE;
  config_data->freq_khz = 50000; /* SFDP compliant parts must support reading
                                    at 50MHz*/


  if ((bparam->density & 0x80000000))
    density_in_bytes = (1 << bparam->density & 0x7FFFFFFF) / 8;
  else
    density_in_bytes = (bparam->density / 8) + 1;

   /* possible values are
      0b00 3 byte addressing only
      0b01 3 byte or 4 byte addressing
      0b10 4 byte addressing only
      0b11 Reserved.*/
  if (bparam->address_bytes_sup == 0 ||
      (bparam->address_bytes_sup == 0b01 && density_in_bytes <= MAX_3BYTE_ADDRESS))
    addr_bytes = 3;
  else if (bparam->address_bytes_sup == 0b01 || bparam->address_bytes_sup == 0b10)
    addr_bytes = 4;
  else
  {
    spinor_log (&p_spinor_dev->debug_log, 0x812);
    SPINOR_LOG_ERROR("%s: Error, invalid addressing mode \r\n", __func__);
    goto spinor_core_sfdp_end;
  }

  /* 4 byte address mode enabled, read the 4 byte SFDP table. */
  if (addr_bytes == 4 && sfdp_data_read->inst_4byte_size > 0)
  {
    uint8 read_mode, read_inst, read_dummy_c;
    uint8 prog_mode, prog_inst;
    uint8 erase_4k_index = 0xFF;
    uint8 erase_inst[4];
    uint8 erase_shift_size[4];
    int i;

    /* Setup the Read Mode and instruction for 1-1-1 mode*/
    if (inst4b->read_111_support == 1)
    {
      read_mode = SDR_1_1_1_MODE;
      read_inst = READ_SDR_4B_111_INST;
      read_dummy_c = 0;
    }
    else
    {
      spinor_log (&p_spinor_dev->debug_log, 0x813);
      SPINOR_LOG_ERROR("%s: Error, read 111 not supported \r\n", __func__);
      goto spinor_core_sfdp_end;
    }

    /* Setup the Program/Write Mode and instruction for 1-1-1 mode */

    if (inst4b->prog_111_support == 1)
    {
      prog_mode = SDR_1_1_1_MODE;
      prog_inst = PROG_SDR_4B_111_INST;
    }
    else
    {
      spinor_log (&p_spinor_dev->debug_log, 0x814);
      SPINOR_LOG_ERROR("%s: Error, Program 111 not supported \r\n", __func__);
      goto spinor_core_sfdp_end;
    }

    memset (erase_shift_size, 0, sizeof(erase_shift_size));
    memset (erase_inst, 0, sizeof(erase_inst));
    if (inst4b->erase_1_support == 1)
    {
      erase_inst[0] = inst4b->erase_1_inst;
      erase_shift_size[0] = bparam->erase_type1_size;
    }
    if (inst4b->erase_2_support == 1)
    {
      erase_inst[1] = inst4b->erase_2_inst;
      erase_shift_size[1] = bparam->erase_type2_size;
    }
    if (inst4b->erase_3_support == 1)
    {
      erase_inst[2] = inst4b->erase_3_inst;
      erase_shift_size[2] = bparam->erase_type3_size;
    }
    if (inst4b->erase_4_support == 1)
    {
      erase_inst[3] = inst4b->erase_4_inst;
      erase_shift_size[3] = bparam->erase_type4_size;
    }
    /* Search for the 4k erase operations. */
    for (i = 0; i < 4; i++)
    {
      if (erase_shift_size[i] == 0x0C) /* 1 << 0x0C = 4096 */
        erase_4k_index = i;
    }

    config->access_param[0].read_mode = read_mode;
    config->access_param[0].write_mode = prog_mode;
    config->access_param[0].read_opcode = read_inst;
    config->access_param[0].wait_state = read_dummy_c;
    config->access_param[0].write_opcode = prog_inst;

    config->access_param[1].read_mode = read_mode;
    config->access_param[1].write_mode = prog_mode;
    config->access_param[1].read_opcode = read_inst;
    config->access_param[1].wait_state = read_dummy_c;
    config->access_param[1].write_opcode = prog_inst;

    if (erase_4k_index >= 4)
    {
      /* We didn't find a valid 4K erase command, required by software. */
      spinor_log (&p_spinor_dev->debug_log, 0x815);
      SPINOR_LOG_ERROR("%s: Error, didn't find a valid 4K erase command \r\n", __func__);
      goto spinor_core_sfdp_end;
    }
    config->access_param[0].erase_4kb_opcode = erase_inst[erase_4k_index];
    config->access_param[1].erase_4kb_opcode = erase_inst[erase_4k_index];

    /* Sort this statements to give priority to a different switch mode */
    if (bparam->enter_4b_addr & 0b01000000) /* Always in 4 byte mode */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_7;
    else if (bparam->enter_4b_addr & 0b00000001) /* Issue B7 instruction */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_1;
    else if (bparam->enter_4b_addr & 0b00100000) /* Dedicated 4Byte ADDR Instructions. */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_6;
    else if (bparam->enter_4b_addr & 0b00000010) /* instruction 06 then B7 */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_2;
    else if (bparam->enter_4b_addr & 0b00000100) /* */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_3;
    else if (bparam->enter_4b_addr & 0b00001000)
      config->enter_4byte_mode = ADDR_4BYTE_MODE_4;
    else if (bparam->enter_4b_addr & 0b00010000)
      config->enter_4byte_mode = ADDR_4BYTE_MODE_5;
    else
      config->enter_4byte_mode = ADDR_4BYTE_MODE_MAX; /* 4 byte address not supported? odd*/
  }
  else /* 3 byte address mode */
  {
    config->enter_4byte_mode = ADDR_4BYTE_NOT_SUPPORTED;

    /* We don't fully support or have tested 3 byte addressing,
     * Return error since we don't support this part. */
    spinor_log (&p_spinor_dev->debug_log, 0x816);
    SPINOR_LOG_ERROR("%s: Error, We don't fully support or have tested 3 byte addressing, Return error since we don't support this part \r\n", __func__);
    goto spinor_core_sfdp_end;
  }

  if (bparam->page_size > 0x0C) /* Code assumes page size is less than 4k */
  {
    spinor_log (&p_spinor_dev->debug_log, 0x817);
    SPINOR_LOG_ERROR("%s: Error, invalid page size \r\n", __func__);
    goto spinor_core_sfdp_end;
  }

  page_size = 1 << bparam->page_size;

  config->octal_dtr_ext = bparam->octal_dtr_ext;
  config->access_param[0].addr_bytes = addr_bytes;
  config->access_param[1].addr_bytes = addr_bytes;
  config->quad_enable_mode = 0;
  config->enable_444_seq = 0;
  config->device_transfer_rate = 0;
  config->spi_io_mode = 0;
  config->access_param[0].read_id_opcode = 0;
  config->access_param[1].read_id_opcode = 0;
  config->octal_enable_r = 0;
  config->spi_io_mode = 0;
  config->device_transfer_rate = 0;
  config->read_max_transfer_in_pages = density_in_bytes / page_size;
  config->density_in_blocks = density_in_bytes / 4096;
  config->block_size_in_bytes = 4096;
  config->pages_per_block = 4096 / page_size;
  config->page_size_in_bytes = page_size;
  config->power_on_delay_in_100us = 8;

  /* The error bitmask for erase and program could be retrieved from the
   * device by getting the SCCR table in SFDP. SCCR is defined in JESD216C
   * or later. */
  ret_status = spinor_sfdp_util_get_erase_and_write_reg_mask(config, device_id, sfdp_data_read);
  if(ret_status != SPINOR_DEVICE_DONE)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x841);
      SPINOR_LOG_ERROR("%s: Error, get erase and write reg mask failed \r\n", __func__);
      goto spinor_core_sfdp_end;
  }

spinor_core_sfdp_end:
  return ret_status;
}
#endif

/**********************************************************
 * Read the SFDP Data and populate the spinor configuration structure.
 *
 * @param config [IN/OUT]
 *   SPI-NOR device configuration structure.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_parse_sfdp_1_1_1_str(spinor_config_data *config, uint32 device_id, spinor_sfdp_t *sfdp_data_read)
{
  spinor_drv_info *spinord = p_spinor_dev;
  spinor_sfdp_basic_param *bparam;
  spinor_sfdp_4byte_inst *inst4b;
  uint32 offset, count;
  uint32 page_size;
  SPINOR_STATUS status;
  SPINOR_STATUS ret_status = SPINOR_DEVICE_FAIL;
  spinor_config_data *config_data;
  uint32 basic_param_offset = 0, basic_param_size;
  uint32 inst_4byte_offset = 0, inst_4byte_size;
  uint64 density_in_bytes;
  uint8 addr_bytes;

  /* Sanity check the structures. if compiler sizes are wrong the Compiler will
   * only keep the code inside this IF, and remove the rest. */
  if(sizeof(spinor_sfdp_header) != 8 ||
     sizeof(spinor_sfdp_param_header) != 8 ||
     sizeof(spinor_sfdp_basic_param) != (20*4) ||
     sizeof(spinor_sfdp_4byte_inst) != (2*4))
  {
    spinor_log (&p_spinor_dev->debug_log, 0x818);
    SPINOR_LOG_ERROR("%s: Error, SFDP header or table size incorrect, device_id = 0x%x \r\n", __func__, device_id);
    goto end;
  }

  bparam = &sfdp_data_read->bparam_data;
  inst4b = &sfdp_data_read->inst4b_data;

  /* Basic device config to read SFDP. */
  config_data = p_spinor_dev->config_data;
  memset(config_data, 0, sizeof(spinor_config_data));
  config_data->magic_number = SPINOR_INIT_CFG_MAGIC_NUMBER;
  config_data->access_param[0].addr_bytes = 3;
  config_data->access_param[0].read_mode = SDR_1_1_1_MODE;
  config_data->access_param[0].write_mode = SDR_1_1_1_MODE;
  config_data->access_param[1].addr_bytes = 3;
  config_data->access_param[1].read_mode = SDR_1_1_1_MODE;
  config_data->access_param[1].write_mode = SDR_1_1_1_MODE;
  config_data->freq_khz = 50000; /* SFDP compliant parts must support reading at 50MHz*/

  if ((bparam->density & 0x80000000))
    density_in_bytes = (1 << bparam->density & 0x7FFFFFFF) / 8;
  else
    density_in_bytes = (bparam->density / 8) + 1;

   /* possible values are
      0b00 3 byte addressing only
      0b01 3 byte or 4 byte addressing
      0b10 4 byte addressing only
      0b11 Reserved.*/
  if (bparam->address_bytes_sup == 0b01 || bparam->address_bytes_sup == 0b10)
    addr_bytes = 4;
  else
  {
    spinor_log (&p_spinor_dev->debug_log, 0x819);
    SPINOR_LOG_ERROR("%s: Error, does not support 4-byte address, device_id = 0x%x \r\n", __func__, device_id);
    goto end;
  }

  /* 4 byte address mode enabled, read the 4 byte SFDP table. */
  if (addr_bytes == 4 && sfdp_data_read->inst_4byte_size > 0)
  {
    uint8 read_mode, read_inst, read_dummy_c;
    uint8 prog_mode, prog_inst;
    uint8 erase_4k_index = 0xFF;
    uint8 erase_256k_index = 0xFF;
    uint8 erase_inst[4];
    uint8 erase_shift_size[4];
    int i;

    /* Setup the Read Mode and instruction for 1-1-1 mode*/
    if (inst4b->read_111_support == 1)
    {
      read_mode = SDR_1_1_1_MODE;
      read_inst = READ_SDR_4B_111_INST;
      read_dummy_c = 0;
    }
    else
    {
      spinor_log (&p_spinor_dev->debug_log, 0x81A);
      SPINOR_LOG_ERROR("%s: Error, read_111_support = 0 \r\n", __func__);
      goto end;
    }

    /* Setup the Program/Write Mode and instruction for 1-1-1 mode */

    if (inst4b->prog_111_support == 1)
    {
      prog_mode = SDR_1_1_1_MODE;
      prog_inst = PROG_SDR_4B_111_INST;
    }
    else
    {
      spinor_log (&p_spinor_dev->debug_log, 0x81B);
      SPINOR_LOG_ERROR("%s: Error, prog_111_support = 0, device_id = 0x%x \r\n", __func__, device_id);
      goto end;
    }

    memset (erase_shift_size, 0, sizeof(erase_shift_size));
    memset (erase_inst, 0, sizeof(erase_inst));
    if (inst4b->erase_1_support == 1)
    {
      erase_inst[0] = inst4b->erase_1_inst;
      erase_shift_size[0] = bparam->erase_type1_size;
    }
    if (inst4b->erase_2_support == 1)
    {
      erase_inst[1] = inst4b->erase_2_inst;
      erase_shift_size[1] = bparam->erase_type2_size;
    }
    if (inst4b->erase_3_support == 1)
    {
      erase_inst[2] = inst4b->erase_3_inst;
      erase_shift_size[2] = bparam->erase_type3_size;
    }
    if (inst4b->erase_4_support == 1)
    {
      erase_inst[3] = inst4b->erase_4_inst;
      erase_shift_size[3] = bparam->erase_type4_size;
    }
    /* Search for the 4k erase operations. */
    for (i = 0; i < 4; i++)
    {
      if (erase_shift_size[i] == 0x0C) /* 1 << 0x0C = 4096 */
        erase_4k_index = i;
    }

    if ((0x195A34 == device_id) || (0x195B34 == device_id))
    {
        /* Search for the 256k erase operations. */
        for (i = 0; i < 4; i++)
        {
          if (erase_shift_size[i] == 0x12) /* 1 << 0x12 = 262144 (256K) */
            erase_256k_index = i;
        }
    }

    config->access_param[0].read_mode = read_mode;
    config->access_param[0].write_mode = prog_mode;
    config->access_param[0].read_opcode = read_inst;
    config->access_param[0].wait_state = read_dummy_c;
    config->access_param[0].write_opcode = prog_inst;

    config->access_param[1].read_mode = read_mode;
    config->access_param[1].write_mode = prog_mode;
    config->access_param[1].read_opcode = read_inst;
    config->access_param[1].wait_state = read_dummy_c;
    config->access_param[1].write_opcode = prog_inst;

    if (erase_4k_index >= 4)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x81C);
      SPINOR_LOG_ERROR("%s: Error, erase_4k_index = %d, device_id = 0x%x \r\n", __func__, erase_4k_index, device_id);
      goto end;
    }

    if ((0x195A34 == device_id) || (0x195B34 == device_id))
    {
        if (erase_256k_index >= 4)
        {
          spinor_log (&p_spinor_dev->debug_log, 0x81D);
          SPINOR_LOG_ERROR("%s: Error, erase_256k_index = %d, device_id = 0x%x \r\n", __func__, erase_256k_index, device_id);
          goto end;
        }
        config->access_param[0].erase_256kb_opcode = erase_inst[erase_256k_index];
        config->access_param[1].erase_256kb_opcode = erase_inst[erase_256k_index];
    }

    config->access_param[0].erase_4kb_opcode = erase_inst[erase_4k_index];
    config->access_param[1].erase_4kb_opcode = erase_inst[erase_4k_index];

    if (bparam->enter_4b_addr & 0b01000000) /* Always in 4 byte mode */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_7;
    else if (bparam->enter_4b_addr & 0b00000001) /* Issue B7 instruction */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_1;
    else if (bparam->enter_4b_addr & 0b00100000) /* Dedicated 4Byte ADDR Instructions. */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_6;
    else if (bparam->enter_4b_addr & 0b00000010) /* instruction 06 then B7 */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_2;
    else if (bparam->enter_4b_addr & 0b00000100) /* */
      config->enter_4byte_mode = ADDR_4BYTE_MODE_3;
    else if (bparam->enter_4b_addr & 0b00001000)
      config->enter_4byte_mode = ADDR_4BYTE_MODE_4;
    else if (bparam->enter_4b_addr & 0b00010000)
      config->enter_4byte_mode = ADDR_4BYTE_MODE_5;
    else
      config->enter_4byte_mode = ADDR_4BYTE_MODE_MAX; /* 4 byte address not supported? odd*/
  }
  else /* 3 byte address mode */
  {
    config->enter_4byte_mode = ADDR_4BYTE_NOT_SUPPORTED;

    /* We don't fully support or have tested 3 byte addressing,
     * Return error since we don't support this part. */
    spinor_log (&p_spinor_dev->debug_log, 0x81E);
    SPINOR_LOG_ERROR("%s: Error, 4 byte mode not supported, device_id = 0x%x \r\n", __func__, device_id);
    goto end;
  }

  if (bparam->page_size > 0x0C) /* Code assumes page size is less than 4k */
  {
    spinor_log (&p_spinor_dev->debug_log, 0x81F);
    SPINOR_LOG_ERROR("%s: Error, incorrect page size = 0x%x, device_id = 0x%x \r\n", __func__, bparam->page_size, device_id);
    goto end;
  }

  ret_status = spinor_sfdp_util_get_default_reg_read_and_reg_read_addr_dummy_cycles(sfdp_data_read, device_id, config);
  if (ret_status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x820);
    SPINOR_LOG_ERROR("%s: Error, failure in obtaining reg read dummy cycles \r\n", __func__);
    goto end;
  }

  page_size = 1 << bparam->page_size;

  config->octal_dtr_ext = bparam->octal_dtr_ext;
  config->access_param[0].addr_bytes = addr_bytes;
  config->access_param[1].addr_bytes = addr_bytes;
  config->quad_enable_mode = 0;
  config->enable_444_seq = 0;
  config->device_transfer_rate = 0;
  config->spi_io_mode = 0;
  config->access_param[0].read_id_opcode = 0;
  config->access_param[1].read_id_opcode = 0;
  config->octal_enable_r = 0;
  config->spi_io_mode = 0;
  config->device_transfer_rate = 0;
  config->read_max_transfer_in_pages = density_in_bytes / page_size;
  config->density_in_blocks = density_in_bytes / 4096;
  config->block_size_in_bytes = 4096;
  config->pages_per_block = 4096 / page_size;
  config->page_size_in_bytes = page_size;
  config->power_on_delay_in_100us = 8;

  ret_status = SPINOR_DEVICE_DONE;

end:
  return ret_status;

}

static SPINOR_STATUS config_qspi_ospi(uint32_t device_id, spinor_sfdp_bus_t bus, spinor_sfdp_t *sfdp_data, spinor_config_data *config,
                                           boolean dqs, uint32_t read_mode, uint32_t write_mode, uint32_t bus_clk_khz)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  /* Magic number used to indicate the structure is valid */
  config->magic_number = SPINOR_INIT_TABLE_MAGIC_NUMBER;

  /* Enter 4-byte address mode for SPI */
  status = spinor_sfdp_util_get_enter_4byte_mode(sfdp_data, device_id, bus, &config->enter_4byte_mode);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x821);
    SPINOR_LOG_ERROR("%s: Error, get enter_4byte_mode fail \r\n", __func__);
    goto end;
  }

  /* Octal DTR (8D-8D-8D) Command and Command Extension
   * 00b: The Command Extension is the same as the Command.
   * (The Command / Command Extension has the same value for the whole clock period.)
   * 01b: Command Extension is the inverse of the Command.
   * The Command Extension acts as a confirmation of the Command
   * 10b: Reserved
   * 11b: Command and Command Extension forms a 16 bit command word.
   */
  status = spinor_sfdp_util_get_octal_dtr_ext(sfdp_data, device_id, bus, &config->octal_dtr_ext);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x822);
    SPINOR_LOG_ERROR("%s: Error, get octal_dtr_ext fail \r\n", __func__);
    goto end;
  }
  /* Flash access operation parameters  */
  status = spinor_sfdp_util_get_access_param_perf(sfdp_data, device_id, bus, bus_clk_khz, read_mode, write_mode, dqs, config);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x823);
    SPINOR_LOG_ERROR("%s: Error, get access param perf fail \r\n", __func__);
    goto end;
  }

  /* Quad Enable Requirements (QER) as defined in the JEDEC Standard No. 216A Document */
  status = spinor_sfdp_util_get_quad_enable_mode(sfdp_data, device_id, bus, &config->quad_enable_mode);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x824);
    SPINOR_LOG_ERROR("%s: Error, get get_quad_enable_mode fail \r\n", __func__);
    goto end;
  }

  /* 4-4-4 mode Enable Sequence */
  status = spinor_sfdp_util_get_enable_444_seq(sfdp_data, device_id, bus, &config->enable_444_seq);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x825);
    SPINOR_LOG_ERROR("%s: Error, get enable_444_seq fail \r\n", __func__);
    goto end;
  }

  /* Octal Enable Requirment and way to enable 8-8-8 from 1-1-1 */
  status = spinor_sfdp_util_get_octal_enable_r(sfdp_data, device_id, bus, &config->octal_enable_r, &config->octal_sdr_num_bytes);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x826);
    SPINOR_LOG_ERROR("%s: Error, get octal_enable_r fail \r\n", __func__);
    goto end;
  }
  /* SPI IO Mode to enable - User configurable to
   * select different options based on needs and what is supported by the vendor
   * Default xSPI/Dual/Quad/Octal
   * 0 - SPI_IO_DEFAULT,
   * 1 - SPI_DUAL_IO,
   * 2 - SPI_QUAD_IO,
   * 3 - SPI_OCTAL_IO
   */
  status = spinor_sfdp_util_get_spi_io_mode(sfdp_data, device_id, bus, &config->spi_io_mode, read_mode);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x827);
    SPINOR_LOG_ERROR("%s: Error, get spi_io_mode fail \r\n", __func__);
    goto end;
  }
  /* Transfer rate type to be used for
   * the device based on needs and what is supported by the vendor
   * 0 - SPI_TRANSFER_STR,     --> Single Transfer Rate
   * 1 - SPI_TRANSFER_DTR      --> Dual Transfer Rate
   */
  status = spinor_sfdp_util_get_device_transfer_rate(sfdp_data, device_id, bus, read_mode, &config->device_transfer_rate);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x828);
    SPINOR_LOG_ERROR("%s: Error, get device_transfer_rate fail \r\n", __func__);
    goto end;
  }
  /* erase_err_bmsk:       Status BIT(s) in the erase_err_status_reg Register indicating if there's erase error condition
   * erase_err_status_reg: register address used for polling the erase status
   * write_err_bmsk:       Status BIT(s) in the write_err_status_reg Register indicating if there's write error condition
   * write_err_status_reg: register address used for polling the write status */
  status = spinor_sfdp_util_get_erase_and_write_reg_mask(config, device_id, sfdp_data);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x829);
    SPINOR_LOG_ERROR("%s: Error, get erase and write reg mask fail \r\n", __func__);
    goto end;
  }
  /* Max supported Frequency */
  config->freq_khz = bus_clk_khz;

  /* Device ID when query with Device Read ID command 0x9F */
  config->device_id = (0x00FFFFFF & device_id);

  /* Power On Reset delay in 100us unit */
  status = spinor_sfdp_util_get_power_on_delay_in_100us(sfdp_data, device_id, bus, &config->power_on_delay_in_100us);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x82A);
    SPINOR_LOG_ERROR("%s: Error, get power on delay fail \r\n", __func__);
    goto end;
  }
  /* TRUE - DQS in sync with qspi_clk;
   *FALSE - DQS half cycle shifted with qspi_clk (inverted/delayed DQS) */
  status = spinor_sfdp_util_get_dqs_sync_qspi_clk(sfdp_data, device_id, bus, &config->dqs_sync_qspi_clk);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x82B);
    SPINOR_LOG_ERROR("%s: Error, get dqs_sync_qspi_clk fail \r\n", __func__);
    goto end;
  }
  /* Vendor specific ECC parameters */
  status = spinor_sfdp_util_get_ecc_info(sfdp_data, device_id, bus, config);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x82C);
    SPINOR_LOG_ERROR("%s: Error, get ECC info fail \r\n", __func__);
    goto end;
  }
  /* Vendor specific CRC parameters :  */
  status = spinor_sfdp_util_get_crc_info(sfdp_data, device_id, bus, config);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x82D);
    SPINOR_LOG_ERROR("%s: Error, get CRC info fail \r\n", __func__);
    goto end;
  }
  /* Dummy cycle configuration parameters -  */
  status = spinor_sfdp_util_get_dummy_cycle_info(sfdp_data, device_id, bus, bus_clk_khz, read_mode, config);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x82E);
    SPINOR_LOG_ERROR("%s: Error, get dummy cycle info fail \r\n", __func__);
    goto end;
  }
end:
  return status;
}



static uint32_t get_bus_freq_by_mode
(
  spinor_sfdp_t *sfdp_data_read,
  uint32_t freq_khz_at_least,
  boolean dqs,
  uint32_t data_mode,
  spinor_sfdp_bus_t bus_type,
  uint32_t device_id
)
{
  uint32_t freq_khz = 0U;
  spinor_sfdp_basic_param *bparam = &sfdp_data_read->bparam_data;
  uint32_t mhz = 0U;
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);

  switch (data_mode)
  {
      case SDR_1_1_1_MODE:      /* 1S-1S-1S */
        if(bus_type == SFDP_BUS_QSPI)
            mhz = bparam->mhz_444s_ndt;
        else
            mhz = bparam->mhz_888d_dt;
        break;

      case SDR_1_1_4_MODE:
      case SDR_1_4_4_MODE:
      case SDR_4_4_4_MODE:
        mhz = bparam->mhz_444s_ndt;
        break;

      case DDR_4_4_4_MODE:      /* 4D-4D-4D */
        mhz = (dqs == TRUE) ? bparam->mhz_444d_dt : bparam->mhz_444d_ndt;
        break;

      case SDR_1_1_8_MODE: //micron ospi: takes mhz 15, fails
      case SDR_1_8_8_MODE:
        mhz = bparam->mhz_888d_dt;
        break;

      case SDR_8_8_8_MODE:
        if(manufacturer == MANUFACTURER_ID_MICRON_OSPI)
        {
            mhz = bparam->mhz_888d_dt;
        }
        else
        {
        mhz = (dqs == TRUE) ? bparam->mhz_888s_dt : bparam->mhz_888s_ndt;
        }
        break;

      case DDR_8_8_8_MODE:
        if(manufacturer == MANUFACTURER_ID_MICRON_OSPI)
        {
            mhz = bparam->mhz_888d_dt;
        }
        else
        {
        mhz = (dqs == TRUE) ? bparam->mhz_888d_dt : bparam->mhz_888d_ndt;
        }
        break;

      case DDR_1_1_4_MODE:      /* 1S-1S-4D */
      case DDR_1_4_4_MODE:      /* 1S-4D-4D */
      case DDR_1_1_8_MODE:      /* 1S-1S-8D */
      case DDR_1_8_8_MODE:      /* 1S-8D-8D */
      default:
        mhz =0;
        break;
  }

  freq_khz = spinor_sfdp_util_get_maxfreq(mhz);

  if (freq_khz > 0U && freq_khz > freq_khz_at_least)
  {
      freq_khz = freq_khz_at_least;
  }

  return freq_khz;
}


static boolean verify_config_mode_params_ospi(spinor_sfdp_t *sfdp_data_read, uint32_t device_id,            uint32_t dqs_mode,
                                                                 uint32_t bus_clk_khz, uint32_t read_mode, uint32_t write_mode)
{
  boolean bStatus = FALSE;
  spinor_sfdp_4byte_inst *inst4b  = &sfdp_data_read->inst4b_data;
  spinor_sfdp_basic_param *bparam = &sfdp_data_read->bparam_data;
  uint32_t tmp_freq;

  /* Get the max freq supported by the dev that matches our read mode and bus freq .
     This will internally ensure that DDR or SDR 888 is already supported.
  */
  tmp_freq = get_bus_freq_by_mode(sfdp_data_read, bus_clk_khz, dqs_mode == BUS_USE_DQS, read_mode, SFDP_BUS_OSPI, device_id);
  if (bus_clk_khz != tmp_freq)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x82F);
      SPINOR_LOG_ERROR("%s: Error, get_bus_freq_by_mode fail \r\n", __func__);
      goto end;
  }

  /* We have already sanitized DDR/SDR 888 mode is supported and the frequency matches our desired frequency.
     So only sanitize if the read mode and write modes are correctly passed.
     For 1-lane mode and xSPI modes check if they are supported by the device.
  */
  if (read_mode == DDR_8_8_8_MODE && write_mode == DDR_8_8_8_MODE)
  {
      bStatus = TRUE;
      goto end;
  }
  else if (read_mode == SDR_8_8_8_MODE && write_mode == SDR_8_8_8_MODE )
  {
      bStatus = TRUE;
      goto end;
  }
  /* This is xSPI or 1-lane mode for Octal Device */
  else if (read_mode == SDR_1_1_8_MODE && inst4b->read_118_support)
  {
      if (write_mode == SDR_1_1_8_MODE && inst4b->prog_118_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_8_8_MODE && inst4b->prog_188_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_1_1_MODE && inst4b->prog_111_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else
      {
          bStatus = FALSE;
          goto end;
      }
  }
  else if (read_mode == SDR_1_8_8_MODE && inst4b->read_188_support)
  {
      if (write_mode == SDR_1_1_8_MODE && inst4b->prog_118_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_8_8_MODE && inst4b->prog_188_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_1_1_MODE && inst4b->prog_111_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else
      {
          bStatus = FALSE;
          goto end;
      }
  }
  else if (read_mode == SDR_1_1_1_MODE && inst4b->read_111_support)
  {
      if (write_mode == SDR_1_1_8_MODE && inst4b->prog_118_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_8_8_MODE && inst4b->prog_188_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_1_1_MODE && inst4b->prog_111_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else
      {
          bStatus = FALSE;
          goto end;
      }
  }
  else
  {
    // Incorrect Configuration
    spinor_log (&p_spinor_dev->debug_log, 0x830);
    SPINOR_LOG_ERROR("%s: Error, Incorrect configuration \r\n", __func__);
    goto end;
  }
end:
  return bStatus;
}
static boolean verify_config_mode_params_qspi(spinor_sfdp_t *sfdp_data_read, uint32_t device_id,            uint32_t dqs_mode,
                                                                 uint32_t bus_clk_khz, uint32_t read_mode, uint32_t write_mode)
{
  boolean bStatus = FALSE;
  spinor_sfdp_4byte_inst *inst4b = &sfdp_data_read->inst4b_data;
  spinor_sfdp_basic_param *bparam = &sfdp_data_read->bparam_data;

  /* For QSPI devices, do not perform any frequency check. Alwasys grant the requested frequency.
     Frequency of operation is hardcoded to the max SPI_BUS_DEFAULT_FREQ_KHZ_QSPI. Since PBL works, this is a safe frequency */
#if 0
  uint32_t tmp_freq;

  /* Get the max freq supported by the dev that matches our read mode and bus freq .
     This will internally ensure that DDR or SDR 888 is already supported.
  */
  tmp_freq = get_bus_freq_by_mode(sfdp_data_read, bus_clk_khz, dqs_mode == BUS_USE_DQS, read_mode, SFDP_BUS_QSPI, device_id);
  if (bus_clk_khz != tmp_freq)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x831);
      SPINOR_LOG_ERROR("%s: Error, get bus_freq_by_mode fail \r\n", __func__);
      goto end;
  }
#endif

  /* We have already sanitized DDR/SDR 888 mode is supported and the frequency matches our desired frequency.
     So only sanitize if the read mode and write modes are correctly passed.
     For 1-lane mode and xSPI modes check if they are supported by the device.
  */
  if (read_mode == DDR_4_4_4_MODE && write_mode == DDR_4_4_4_MODE)
  {
      bStatus = TRUE;
      goto end;
  }
  else if (read_mode == SDR_4_4_4_MODE && write_mode == SDR_4_4_4_MODE )
  {
      bStatus = TRUE;
      goto end;
  }
  /* This is xSPI or 1-lane mode for Quad Device */
  else if (read_mode == SDR_1_1_4_MODE && inst4b->read_114_support)
  {
      if (write_mode == SDR_1_1_4_MODE && inst4b->prog_114_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_4_4_MODE && inst4b->prog_144_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_1_1_MODE && inst4b->prog_111_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else
      {
          bStatus = FALSE;
          goto end;
      }
  }
  else if (read_mode == SDR_1_4_4_MODE && inst4b->read_144_support)
  {
      if (write_mode == SDR_1_1_4_MODE && inst4b->prog_114_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_4_4_MODE && inst4b->prog_144_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_1_1_MODE && inst4b->prog_111_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else
      {
          bStatus = FALSE;
          goto end;
      }
  }
  else if (read_mode == SDR_1_1_1_MODE && inst4b->read_111_support)
  {
      if (write_mode == SDR_1_1_4_MODE && inst4b->prog_114_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_4_4_MODE && inst4b->prog_144_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else if(write_mode == SDR_1_1_1_MODE && inst4b->prog_111_support)
      {
          bStatus = TRUE;
          goto end;
      }
      else
      {
          bStatus = FALSE;
          goto end;
      }
  }
  else
  {
    // Incorrect Configuration
    spinor_log (&p_spinor_dev->debug_log, 0x832);
    SPINOR_LOG_ERROR("%s: Error, Incorrect configuration \r\n", __func__);
    goto end;
  }
end:
  return bStatus;
}

static boolean verify_config_mode_params(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus,
                                         uint32_t dqs_mode, uint32_t bus_clk_khz, uint32_t read_mode, uint32_t write_mode)
{
  boolean bStatus = FALSE;
  spinor_sfdp_4byte_inst *inst4b = &sfdp_data_read->inst4b_data;
  spinor_sfdp_basic_param *bparam = &sfdp_data_read->bparam_data;
  if (bus == SFDP_BUS_OSPI)
  {
    bStatus = verify_config_mode_params_ospi(sfdp_data_read, device_id, dqs_mode, bus_clk_khz, read_mode, write_mode);
  }
  else if (bus == SFDP_BUS_QSPI)
  {
    bStatus = verify_config_mode_params_qspi(sfdp_data_read, device_id, dqs_mode, bus_clk_khz, read_mode, write_mode);
  }
  else
  {
    spinor_log (&p_spinor_dev->debug_log, 0x833);
    SPINOR_LOG_ERROR("%s: Error, Invalid bus type \r\n", __func__);
    bStatus = FALSE;
  }
  return bStatus;
}
static SPINOR_STATUS parse_config_qspi_ospi
(
  uint32_t device_id,
  spinor_sfdp_bus_t bus,
  spinor_sfdp_t *sfdp_data_read,
  uint32_t freq_khz_at_least,
  spinor_config_data *config_data,
  spinor_hardcode_data_mode *hardcode_mode
)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  uint32_t read_mode   = BUS_MODE_AUTO;
  uint32_t write_mode  = BUS_MODE_AUTO;
  uint32_t bus_clk_khz = 0U;
  uint32_t dqs_mode    = BUS_AUTO_DQS;
  boolean is_ospi      = (bus == SFDP_BUS_OSPI);

  if (hardcode_mode)
  {
    dqs_mode    = hardcode_mode->hardcode_dqs;
    read_mode   = hardcode_mode->hardcode_read_mode;
    write_mode  = hardcode_mode->hardcode_write_mode;
    bus_clk_khz = hardcode_mode->hardcode_bus_clk_khz;
  }
  /* If no pre-determined mode is provided, the rules are:
   * OSPI: DQS = TRUE, read_mode = DDR_8_8_8_MODE, write_mode = DDR_8_8_8_mode, bus frequency is at least 166MHz
   * QSPI: DQS = FALSE, read_mode = SDR_1_1_4_MODE, write_mode = SDR_1_1_4_mode, bus frequency is at least 83MHz
   * If (freq_mhz_at_least == 0), hard code to 166MHz
   */
  if (dqs_mode == BUS_AUTO_DQS && bus_clk_khz == 0U && read_mode == BUS_MODE_AUTO && write_mode == BUS_MODE_AUTO)
  {
    if (is_ospi)
    {
      dqs_mode = BUS_USE_DQS;
      bus_clk_khz = spinor_sfdp_util_get_dtr_bus_freq(sfdp_data_read, freq_khz_at_least, dqs_mode == BUS_USE_DQS, is_ospi);
      read_mode   = DDR_8_8_8_MODE;
      write_mode  = DDR_8_8_8_MODE;
    }
    else
    {
      /* Hard code to QSPI STR without DQS */
      dqs_mode = BUS_NO_DQS;
      // Hardcode the bus clk  frequeuncy to 83MHz max. This is the max frequeuncy allowed for QSPI
      bus_clk_khz = (freq_khz_at_least>= SPI_BUS_DEFAULT_FREQ_KHZ_QSPI)? SPI_BUS_DEFAULT_FREQ_KHZ_QSPI:freq_khz_at_least; //spinor_sfdp_util_get_str_bus_freq(sfdp_data_read, freq_khz_at_least, dqs_mode == BUS_USE_DQS, is_ospi);
      read_mode   = SDR_1_1_4_MODE;
      write_mode  = SDR_1_1_4_MODE;
    }
  }
  /* Verify that SFDP supports dqs_mode, read_mode, write_mode and bus_clk_khz are supported by SFDP and the driver rules also */
  status = verify_config_mode_params(sfdp_data_read, device_id, bus, dqs_mode, bus_clk_khz, read_mode, write_mode);
  if (status == FALSE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x834);
    SPINOR_LOG_ERROR("%s: Error, verify config mode params fail \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    goto end;
  }

  /* Fill in each fgield of spinor_config_data structure */
  status = config_qspi_ospi(device_id, bus, sfdp_data_read, config_data, (dqs_mode == BUS_USE_DQS), read_mode, write_mode, bus_clk_khz);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x835);
    SPINOR_LOG_ERROR("%s: Error, config QSPI/OSPI fail \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    goto end;
  }

end:
  return status;
}


SPINOR_STATUS spinor_parse_sfdp2
(
  boolean is_crash_dbg,
  uint32 device_id,
  spinor_hardcode_data_mode *hardcode_mode,
  spinor_config_data *config,
  spinor_sfdp_t *sfdp_data_read
)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  spinor_sfdp_bus_t bus = SFDP_BUS_MAX;
  uint32_t mhz_dtr, sw_reset, max_er_size = 0;
  spinor_sfdp_basic_param *basic_params = &sfdp_data_read->bparam_data;
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);
  uint32_t freq_khz_at_least;

  if (device_id == 0x0019BB20)
  {
     /* This is a hack to bring-up Micron QSPI with older basic param table */
    basic_params->mhz_444s_ndt = 0b0111;
    basic_params->mhz_444s_dt  = 0b0111;
    basic_params->mhz_444d_ndt = 0b0100;
    basic_params->mhz_444d_dt  = 0b0100;

    sfdp_data_read->inst4b_data.read_118_support = 0;
    sfdp_data_read->inst4b_data.read_188_support = 0;
    sfdp_data_read->inst4b_data.read_dtr_188_support = 0;
    sfdp_data_read->inst4b_data.prog_118_support = 0;
    sfdp_data_read->inst4b_data.prog_188_support = 0;

  }
  if(device_id == 0x001C5B2C)
  {
      sfdp_data_read->profile10_data.read_fast_cmd = 0xc;
      sfdp_data_read->profile10_data.sfdp_cmd_in_8d_8d_8d_mode_addr_bytes = 0;
  }

  if(manufacturer == MANUFACTURER_ID_ISSI)
  {
      /* Hack for ISSI to use MODE 1 for enter_4b_addr */
      basic_params->enter_4b_addr = 0b00000001;
  }

  if(manufacturer == MANUFACTURER_ID_WINBOND)
  {
      basic_params->dsw_str_mode = 0b01;
  }

  if (MANUFACTURER_ID_INFINEON != manufacturer)
  {
      if (FALSE == spinor_sfdp_util_get_4KB_uniform_sector(sfdp_data_read))
      {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x836);
        SPINOR_LOG_ERROR("%s: Error, uniform 4KB sector not supported\r\n", __func__);
        goto end;
      }
  }

  bus = spinor_sfdp_util_get_bus_mode(sfdp_data_read);

  if(SFDP_BUS_OSPI == bus)
  {
    mhz_dtr = basic_params->mhz_888d_dt & 0xF;
    if (!(mhz_dtr != 0b1111 && mhz_dtr != 0b1110 && mhz_dtr != 0))
    {
      status = SPINOR_DEVICE_FAIL;
      spinor_log (&p_spinor_dev->debug_log, 0x837);
      SPINOR_LOG_ERROR("%s: Error, Octal device requires DQS support \r\n", __func__);
      goto end;
    }
  }
  else if (SFDP_BUS_QSPI == bus)
  {
  }
  else
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x838);
    SPINOR_LOG_ERROR("%s: Error, Incorrect bus mode \r\n", __func__);
    goto end;
  }

  /* Check if SW reset is enabled on the device */
  sw_reset = basic_params->srr_seq_sup & 0x10;
  if (sw_reset != 0x10)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x839);
    SPINOR_LOG_ERROR("%s: Error, Device does not support the SW reset command \r\n", __func__);
    goto end;
  }

  /* Set the frequency of operation */
  if(hardcode_mode && hardcode_mode->hardcode_bus_clk_khz)
  {
	  freq_khz_at_least = hardcode_mode->hardcode_bus_clk_khz;
  }
  else if(bus == SFDP_BUS_OSPI)
  {
	  /* OSPI Card */
	  freq_khz_at_least = SPI_BUS_MAX_SUPPORTED_FREQ_KHZ_OSPI;
  }
  else
  {
	  /* QSPI Card */
	  freq_khz_at_least = SPI_BUS_DEFAULT_FREQ_KHZ_QSPI;
  }

  if ((freq_khz_at_least == 0U) || (bus == SFDP_BUS_OSPI && freq_khz_at_least > SPI_BUS_MAX_SUPPORTED_FREQ_KHZ_OSPI) || (bus == SFDP_BUS_QSPI && freq_khz_at_least > SPI_BUS_MAX_SUPPORTED_FREQ_KHZ_QSPI))
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x83A);
    SPINOR_LOG_ERROR("%s: Error, freq_khz_at_least = 0 or frequency is greater than max supported \r\n", __func__);
    goto end;
  }

  /* fill in 1-1-1 STR card's parameters first */
  status = spinor_parse_sfdp_1_1_1_str(config, device_id, sfdp_data_read);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x83B);
    SPINOR_LOG_ERROR("%s: Error, parse 1-1-1 STR fail \r\n", __func__);
    goto end;
  }

  /* Set bus type */
  config->device_type = bus;

  if ((0x195A34 == device_id) || (0x195B34 == device_id))
  {
      /* Check if Infineon configuration is correct */
      status = spinor_sfdp_read_config_infineon();
      if(status != SPINOR_DEVICE_DONE)
      {
          status = SPINOR_DEVICE_FAIL;
          goto end;
      }

      /* Populate the address ranges for each region */
      /* 4K blocks */
      config->secmapdata[0].start_range = 0;
      config->secmapdata[0].end_range = config->secmapdata[0].start_range + ((g_sfdp_data.config_region_data[0].region_size + 1) * 256) -1;
      config->secmapdata[0].er_size_KB = 4;

      /* 192K blocks */
      config->secmapdata[1].start_range = config->secmapdata[0].end_range + 1;
      config->secmapdata[1].end_range = config->secmapdata[1].start_range + ((g_sfdp_data.config_region_data[1].region_size + 1) * 256) -1;
      config->secmapdata[1].er_size_KB = 192;

      /* 256K blocks */
      config->secmapdata[2].start_range = config->secmapdata[1].end_range + 1;
      config->secmapdata[2].end_range = config->secmapdata[2].start_range + ((g_sfdp_data.config_region_data[2].region_size + 1) * 256) -1;
      config->secmapdata[2].er_size_KB = 256;

      /* 192K blocks */
      config->secmapdata[3].start_range = config->secmapdata[2].end_range + 1;
      config->secmapdata[3].end_range = config->secmapdata[3].start_range + ((g_sfdp_data.config_region_data[3].region_size + 1) * 256) -1;
      config->secmapdata[3].er_size_KB = 192;

      /* 4K blocks */
      config->secmapdata[4].start_range = config->secmapdata[3].end_range + 1;
      config->secmapdata[4].end_range = config->secmapdata[4].start_range + ((g_sfdp_data.config_region_data[4].region_size + 1) * 256) -1;
      config->secmapdata[4].er_size_KB = 4;

      /* Calculate the value to which addresses should be aligned */
      for (int idx = 0; idx < sizeof(config->secmapdata) / sizeof(config->secmapdata[0]); idx++)
      {
          if(config->secmapdata[idx].er_size_KB > max_er_size)
          {
              max_er_size = config->secmapdata[idx].er_size_KB;
          }
      }

    config->secMapAlignmentAddr = max_er_size * 1024;

      /* Decode the 8D-8D-8D sequence */
      spinor_sfdp_decode_octal_ddr_seq();
  }
  else
  {
      for (int idx=0;idx < sizeof(config->secmapdata)/sizeof(config->secmapdata[0]);idx++)
      {
          config->secmapdata[idx].start_range = 0;
          config->secmapdata[idx].end_range = (p_spinor_dev->config_data->density_in_blocks*4096)-1;
          config->secmapdata[idx].er_size_KB = 4;
      }
  }

  if (bus == SFDP_BUS_QSPI || bus == SFDP_BUS_OSPI)
  {
    status = parse_config_qspi_ospi(device_id, bus, sfdp_data_read, freq_khz_at_least, config, hardcode_mode);
    if (status != SPINOR_DEVICE_DONE)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x83C);
      SPINOR_LOG_ERROR("%s: Error, parse config QSPI/OSPI fail \r\n", __func__);
      goto end;
    }
  }
  else
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x83D);
    SPINOR_LOG_ERROR("%s: Error, invalid bus type = %d\r\n", __func__, bus);
    goto end;

  }
end:
  return status;
}
