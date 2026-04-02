/*
===========================================================================
*/
/**
    @file  spinor_core.c
    @brief Implementation of spinor driver

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_core.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_api.h"
#include "spinor_clock_gpio.h"
#include "spinor_core.h"
#include "spinor_hal.h"
#include "spinor_learning.h"
#include "spinor_utils.h"
#include "spinor_osal.h"
#include "spinor_init_config.h"
#include "spinor_cmd.h"
#include "spinor_job.h"
#include "spinor_sfdp.h"
#include "spinor_sfdp_util.h"
#include "debug_log.h"
#include "boot_logger.h"
#include "spinor_diag.h"
#include "spinor_pvl_api.h"
#include "libfdt.h"
#include "fdt_utils.h"

spinor_config_data spinor_core_config_data_mm;
spinor_config_data spinor_core_config_data_crash_dbg;

#ifdef NORPVL_ENB
uint32_t spinor_thead_delay_us = 0;
uint32_t spinor_thread_chunk_size = 0;
#endif

static boolean is_crash_dbg;

/* Local functions */

/**********************************************************
 * Sets timeouts via Device tree.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 *********************************************************/
static boolean prvSPINORReadDTSTimeouts(void)
{
    void* pDTB = NULL;
    int32_t root_offset = 0;
    int retval = 0;

    /* Check which GPIO pins should be used based on device tree and chipinfo */
    pDTB = fdt_get_dtb();
    if (NULL != pDTB)
    {
        root_offset = fdt_path_offset(pDTB, "/spinor");
        if (root_offset > 0)
        {
            retval = fdt_getprop_u32(pDTB, root_offset, "read_timeout_us", &p_spinor_dev->read_timeout);
            if (0 != retval)
            {
                return false;
            }
            retval = fdt_getprop_u32(pDTB, root_offset, "write_timeout_us", &p_spinor_dev->write_timeout);
            if (0 != retval)
            {
                return false;
            }
            retval = fdt_getprop_u32(pDTB, root_offset, "erase_timeout_us", &p_spinor_dev->erase_timeout);
            if (0 != retval)
            {
                return false;
            }
            retval = fdt_getprop_u32(pDTB, root_offset, "read_reg_timeout_us", &p_spinor_dev->read_status_timeout);
            if (0 != retval)
            {
                return false;
            }
            retval = fdt_getprop_u32(pDTB, root_offset, "disable_timeouts", &p_spinor_dev->disable_timeouts);
            if (0 != retval)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

/**********************************************************
 * Initializes the spinor driver info structure.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 *********************************************************/
 SPINOR_STATUS spinor_drv_info_init (int type)
{
  boolean status = false;

  p_spinor_dev->nor_init_done = SPINOR_INIT_NOT_DONE;
  p_spinor_dev->config_data = (SPINOR_INIT_TYPE_DEFAULT == type) ? &spinor_core_config_data_mm : &spinor_core_config_data_crash_dbg;
  p_spinor_dev->cmd_eng_poll_timeout_us = (SPINOR_INIT_TYPE_DEFAULT == type) ? SPINOR_CMD_ENG_TIMEOUT_US : SPINOR_CMD_ENG_TIMEOUT_LOW_FRQ_US;
  p_spinor_dev->status_polling_usec = READ_STATUS_POLLING_USEC;
  p_spinor_dev->dma_enable = SPINOR_DMA_EN_CTRL;
  p_spinor_dev->enable_ecc = SPINOR_ECC_EN_CTRL;
  p_spinor_dev->ecc_enabled_status_local = FALSE;
  p_spinor_dev->sw_reset_done = FALSE;
  p_spinor_dev->perfmode_enabled = FALSE;
  p_spinor_dev->enable_crc = SPINOR_CRC_EN_CTRL;
  p_spinor_dev->four_byte_mode_enabled = FALSE;
  p_spinor_dev->octal_mode_enabled = FALSE;

  status = prvSPINORReadDTSTimeouts();
  if (status != true)
  {
      DEBUG_LOG(SAIL_ERROR, "%s: Set timeouts via device tree failed \r\n", __func__);
      return SPINOR_DEVICE_FAIL;
  }

  /* Zero the config structure to remove residue. Need to test:
   * 1. init
   * 2. perf operations
   * 3. deinit
   * 4. init
   * 5. perf operations
   * to confirm that we can cleanly deinit and then reinit the driver and card.
   */
  memset(p_spinor_dev->config_data, 0, sizeof(spinor_config_data));
    return SPINOR_DEVICE_DONE;
}

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
SPINOR_STATUS spinor_core_init(int type, void *spinor_config_table, spinor_hardcode_data_mode *hardcoded_data_mode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    bool qspi_init_status = FALSE;
    spinor_sfdp_header header;
    uint32 timeout = 0;
    uint32 status_polling_us = 0;
    uint32 dev_id = 0;
    uint32_t mem_density = 0;
    uint8 result = 0;
    uint32_t signature = 0U;
    boolean use_pbl = 0;
    is_crash_dbg = SPINOR_INIT_TYPE_RAM_DUMP == type;
    uint8_t manufacturer;
    boolean restore_reset_val = FALSE;
    boolean pattern_match = FALSE;
    spinor_gpio_data gpio_config_data = { 0U };

#ifdef SAIL_CC_SPINOR
    is_crash_dbg = FALSE;
#endif

    /* Core init sequence:
    * 1. Enable GPIO
    * 2. Set GPIO mux to SPINOR
    * 3. enable 1-1-1 STR PBL mode at 19.2MHz bus frequnece (core freq = 2 * 19.2MHz)
    * 4. Run SFDP based device discovery
    * 5. Set 4 byte instruction mode
    * 6. Verify that NOR flash memory's DLP pattern is correct. If not, overwrite to the correct pattern
    * 7. Enable performance mode / mission mode
    */
    if(TRUE == p_spinor_dev->sw_reset_done)
    {
        restore_reset_val = TRUE;
    }
    if(p_spinor_dev->nor_init_done < SPINOR_INIT_PARTIALLY_DONE)
    {
        memset(p_spinor_dev, 0, sizeof(spinor_drv_info));
        /* Initialize all the spinor_dev structure, except client's handles info  */
        spinor_drv_info_init(type);
    }

    /*restore the previous reset value */
    p_spinor_dev->sw_reset_done = restore_reset_val;

    if (p_spinor_dev->config_data == NULL)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x300);
        SPINOR_LOG_ERROR("%s: Error, p_spinor_dev config data is NULL \r\n", __func__);
        p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
        status = SPINOR_DEVICE_FAIL;
        goto spinor_init_end;
    }
    /* For mission mode, if nor_init_done and no sw_reset, do not init again */
    if ( (p_spinor_dev->config_data->magic_number == SPINOR_INIT_CFG_MAGIC_NUMBER) &&
      (p_spinor_dev->nor_init_done == SPINOR_INIT_DONE) && (p_spinor_dev->sw_reset_done == FALSE))
    {
        /* In FOM mode, spinor_init has been done at least once */
        status = SPINOR_DEVICE_DONE;
        SPINOR_LOG_INFO("%s: Info, In FOM mode, spinor_init has been done at least once \r\n", __func__);
        goto spinor_init_end;
    }
    
    memcpy(&gpio_config_data, &p_spinor_dev->config_data->gpio_info, sizeof(spinor_gpio_data));
    if (TRUE != spinor_configure_gpios(&gpio_config_data))
    {
        status = SPINOR_DEVICE_FAIL;
        p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x301);
        SPINOR_LOG_ERROR("%s: Error, Configure GPIOs failed \r\n", __func__);
        goto spinor_init_end;
    }
    else
    {
        memcpy(&p_spinor_dev->config_data->gpio_info, &gpio_config_data, sizeof(spinor_gpio_data));
    }

    if ( FALSE == is_crash_dbg && FALSE == spinor_configure_clocks( ) )
    {
        status = SPINOR_DEVICE_FAIL;
        p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x302);
        SPINOR_LOG_ERROR("%s: Error, Configure clocks failed \r\n", __func__);
        goto spinor_init_end;
    }

    if((p_spinor_dev->nor_init_done < SPINOR_INIT_PARTIALLY_DONE) || (p_spinor_dev->sw_reset_done == TRUE))
    {
        status = spinor_core_init_one_lane(is_crash_dbg);
        if ( SPINOR_DEVICE_DONE != status)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x303);
            SPINOR_LOG_ERROR("%s: Error, init_one_lane failed status = 0x%x\r\n", __func__, status);
            p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
            goto spinor_init_end;
        }

        /* 1-1-1 STR is up. Run card discovery rioutine, set 4B mode */
        //mzhu: make sfdp signature a for loop so that we only have one finction
        status = spinor_util_check_sfdp_signature( );
        if (status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x304);
            SPINOR_LOG_ERROR("%s: Error, checking SFDP signature @ 1-1-1 mode failed status = 0x%x\r\n", __func__, status);
            p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
            goto spinor_init_end;
        }

        status = spinor_core_device_lookup (is_crash_dbg, spinor_config_table, hardcoded_data_mode);
        if (status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x305);
            SPINOR_LOG_ERROR("%s: Error, device lookup failed status =0x%x \r\n", __func__, status);
            p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
            goto spinor_init_end;
        }

        p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE;

        mem_density = (p_spinor_dev->config_data->density_in_blocks * p_spinor_dev->config_data->block_size_in_bytes * 8)/(1024*1024);

        DEBUG_LOG(SAIL_WARNING,"[SPINOR] Device ID = 0x%x \n\r", p_spinor_dev->config_data->device_id);
        DEBUG_LOG(SAIL_WARNING,"[SPINOR] Device Memory density = %d   Mb \n\r", mem_density);

        /* Enable 4-byte address mode when density is more than 16MB and based on the 4-byte address mode defined in the config data table */
        if ((p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].addr_bytes == 4) &&
          ((p_spinor_dev->config_data->density_in_blocks * p_spinor_dev->config_data->block_size_in_bytes) > SPINOR_16MB_IN_BYTES))
        {
            status = spinor_core_device_set_4byte_address_mode();
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x306);
                p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As mission mode is up, we need 4byte mode
                SPINOR_LOG_ERROR("%s: Error, setting 4-byte address failed status = 0x%x\r\n", __func__, status);
                (void)spinor_pvl_sfdp_dump();
                goto spinor_init_end;
            }
            /* clear the SW reset done flag here after entering 4Byte mode so that next deinit shows the correct value to enter as default */
            p_spinor_dev->sw_reset_done = FALSE;

            p_spinor_dev->four_byte_mode_enabled = TRUE;

            manufacturer = spinor_sfdp_util_get_manufacturer(p_spinor_dev->config_data->device_id);
            p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].addr_bytes_reg_addr = (manufacturer == MANUFACTURER_ID_MICRON)? 0 : 4;

        }

        if (TRUE == is_crash_dbg)
        {
            /* for crash dbg, we only use one lane. Stop here */
            p_spinor_dev->nor_init_done = SPINOR_INIT_DONE;
            SPINOR_LOG_INFO("%s: for crash dbg, we only use one lane. Stop initialization here \r\n", __func__);
            goto spinor_init_end;
        }

        /* At this point 1-1-1 (default mode) is working.
         Read from the DLP partition to see if the data read back matches expected pattern.
         Else write the pattern here in 1-1-1 and read back before trying DLP training.
        */
        if (SPINOR_DEVICE_DONE == spinor_learning_check_nor_pattern(&pattern_match))
        {
            if (FALSE == pattern_match)
            {
                if (FALSE == spinor_learning_write_nor_pattern())
                {
                    spinor_log (&p_spinor_dev->debug_log, 0x307);
                    SPINOR_LOG_ERROR("%s: Error, data learning @ 1-1-1 mode failed \r\n", __func__);
                    status = SPINOR_DEVICE_FAIL;
                    p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As 111 mode is up, so we can do a sw reset
                    (void)spinor_pvl_sfdp_dump();
                    goto spinor_init_end;
                }
            }
        }
        else
        {
            spinor_log (&p_spinor_dev->debug_log, 0x31B);
            SPINOR_LOG_ERROR("%s: Error, data learning check @ 1-1-1 mode error \r\n", __func__);
            status = SPINOR_DEVICE_FAIL;
            p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As 111 mode is up, so we can do a sw reset
            (void)spinor_pvl_sfdp_dump();
            goto spinor_init_end;
        }

        #ifdef SAILJTAGPROGRAMMER
        if (status == SPINOR_DEVICE_DONE)
        {
            goto spinor_early_exit;
        }
        #endif
    }

    manufacturer = spinor_sfdp_util_get_manufacturer(p_spinor_dev->config_data->device_id);

    /* If it is first time init, mode_enabled will be set to SPI_DEFAULT_SDR and for the case when we go to sleep,
      we keep the mode_enabled flag set to the previous mode. Hence we dont need to reconfigure the device to perf mode. */
    if((p_spinor_dev->mode_enabled == SPI_DEFAULT_SDR) && (p_spinor_dev->nor_init_done <= SPINOR_INIT_PARTIALLY_DONE) )
    {
        if(manufacturer == MANUFACTURER_ID_INFINEON)
        {
            if ((SPI_OCTAL_IO == p_spinor_dev->config_data->spi_io_mode) && (SPI_TRANSFER_DTR == p_spinor_dev->config_data->device_transfer_rate))
            {
                /* do SW Reset in 111 mode; switch to 888 using cmd sequence */
                status = spinor_util_device_software_reset();
                if(status != SPINOR_DEVICE_DONE)
                {
                    spinor_log (&p_spinor_dev->debug_log, 0x308);
                    SPINOR_LOG_ERROR("%s: Error, device SW reset failed status =0x%x \r\n", __func__, status);
                    p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
                    (void)spinor_pvl_sfdp_dump();
                    goto spinor_init_end;
                }

                p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].addr_bytes_reg_addr = 3;
                p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].addr_bytes_reg = 3;

                status = spinor_core_run_octal_ddr_sequence();
                if(status != SPINOR_DEVICE_DONE)
                {
                    spinor_log (&p_spinor_dev->debug_log, 0x309);
                    SPINOR_LOG_ERROR("%s: Error, octal DDR sequence failed status =0x%x \r\n", __func__, status);
                    p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL;
                    (void)spinor_pvl_sfdp_dump();
                    goto spinor_init_end;
                }

                DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: DDR_8_8_8 \n\r");
                DEBUG_LOG(SAIL_WARNING,"[SPINOR] Frequency of operation = %d MHz\n\r", p_spinor_dev->config_data->freq_khz/1000);

                /* Set required flags */
                p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].wait_state = 20; //default dummy cycles
                SPINOR_LOG_WARNING("%s: Info, %d dummy cycles default \r\n", __func__, p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].wait_state);
                p_spinor_dev->octal_mode_enabled = TRUE;
                p_spinor_dev->mode_enabled = SPI_OCTAL_DDR;

                /* clear the SW reset done flag here after entering configuring perf mode mode so that next deinit shows the correct value to enter as default */
                p_spinor_dev->sw_reset_done = FALSE;
            }
            else
            {
                status = spinor_core_device_perf_config();
                if (status != SPINOR_DEVICE_DONE)
                {
                    spinor_log (&p_spinor_dev->debug_log, 0x30A);
                    p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As 111 mode is up, so we can do a sw reset
                    SPINOR_LOG_ERROR("%s: Error, setting Device perf mode config failed status = 0x%x\r\n", __func__, status);
                    (void)spinor_pvl_sfdp_dump();
                    goto spinor_init_end;
                }

                /* clear the SW reset done flag here after entering configuring perf mode so that next deinit shows the correct value to enter as default */
                p_spinor_dev->sw_reset_done = FALSE;
            }
        }
        else
        {
            status = spinor_core_device_perf_config();
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x30B);
                p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As 111 mode is up, so we can do a sw reset
                SPINOR_LOG_ERROR("%s: Error, setting Device perf mode config failed status = 0x%x\r\n", __func__, status);
                (void)spinor_pvl_sfdp_dump();
                goto spinor_init_end;
            }

            /* clear the SW reset done flag here after entering configuring perf mode so that next deinit shows the correct value to enter as default */
            p_spinor_dev->sw_reset_done = FALSE;
        }
    }

    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Frequency of operation = %d MHz\n\r", p_spinor_dev->config_data->freq_khz/1000);

    qspi_init_status = TRUE;
    use_pbl = (hardcoded_data_mode == NULL)?0:hardcoded_data_mode->use_pbl;
    status = spinor_core_init_perf(spinor_config_table, use_pbl);
    if (status != SPINOR_DEVICE_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x30C);
        p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL; //as perf mode is up, we need the perf initializations
        SPINOR_LOG_ERROR("%s: initializing controller in perf mode failed status = 0x%x\r\n", __func__, status);
        (void)spinor_pvl_sfdp_dump();
        goto spinor_init_end;
    }
    if((p_spinor_dev->nor_init_done == SPINOR_INIT_PARTIALLY_DONE) || (p_spinor_dev->nor_init_done == SPINOR_INIT_SLEEP_DONE) )
    {
        status = spinor_util_exit_deep_power_down();
        if (status != SPINOR_DEVICE_DONE)
        {
            spinor_log(&p_spinor_dev->debug_log, 0x30D);
            p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As perf mode is up, so we can do a sw reset
            SPINOR_LOG_ERROR("%s: Error, DPD Exit failed \r\n", __func__);
            (void)spinor_pvl_sfdp_dump();
            status = SPINOR_DEVICE_FAIL;
            goto spinor_init_end;
        }
    }

    /* Enable DDR DLP Training if applicable */
    if ((FALSE == p_spinor_dev->dll_config_en ) && (SPI_TRANSFER_DTR == p_spinor_dev->config_data->device_transfer_rate))
    {
        status = spinor_core_DDR_DLP_training();
        if (status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x30E);
            p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As perf mode is up, so we can do a sw reset
            SPINOR_LOG_ERROR("%s: Error, DDR data learning training @ perf mode failed status = 0x%x\r\n", __func__, status);
            (void)spinor_pvl_sfdp_dump();
            goto spinor_init_end;
        }
    }
    else if ((TRUE == p_spinor_dev->dll_config_en ) && (SPI_TRANSFER_STR == p_spinor_dev->config_data->device_transfer_rate))
    {
        status = spinor_learning_SDR_DLL_training();
        if (status != SPINOR_DEVICE_DONE)
        {
            spinor_log (&p_spinor_dev->debug_log, 0x30F);
            p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As perf mode is up, so we can do a sw reset
            SPINOR_LOG_ERROR("%s: Error, SDR data learning training @ perf mode failed status = 0x%x \r\n", __func__, status);
            (void)spinor_pvl_sfdp_dump();
            goto spinor_init_end;
        }
    }

    status = spinor_learning_check_nor_pattern(&pattern_match);
    if ((SPINOR_DEVICE_DONE != status) || (FALSE == pattern_match))
    {
        spinor_log (&p_spinor_dev->debug_log, 0x310);
        SPINOR_LOG_ERROR("%s:Error,data learning check @perf mode failed status=0x%x match=%d\r\n", __func__, status, pattern_match);
        status = SPINOR_DEVICE_FAIL;
        p_spinor_dev->nor_init_done = SPINOR_INIT_PARTIALLY_DONE; //As perf mode is up, so we can do a sw reset
        (void)spinor_pvl_sfdp_dump();
        goto spinor_init_end;
    }

    if(p_spinor_dev->mode_enabled != SPI_DEFAULT_SDR)
    {
        status = spinor_util_check_operation_status(&result);
        if (status != SPINOR_DEVICE_DONE)
        {
            p_spinor_dev->perfmode_enabled = FALSE;
            p_spinor_dev->debug_log.spinor_status = result;
            p_spinor_dev->nor_init_done = SPINOR_INIT_FAIL; //as perf mode is up, we need the perf initializations
            spinor_log (&p_spinor_dev->debug_log, 0x311);
            (void)spinor_pvl_sfdp_dump();
            SPINOR_LOG_ERROR("%s: Error, checking operation status failed status= 0x%x \r\n", __func__, status);
            goto spinor_init_end;
        }
    }

    status = spinor_core_ecc_crc_init();
    if(status != SPINOR_DEVICE_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x312);
        SPINOR_LOG_ERROR("%s: Error, ECC/CRC init failed status= 0x%x\r\n", __func__, status);
        p_spinor_dev->nor_init_done = SPINOR_INIT_DONE; //As perf mode is up, so we can do a sw reset
        (void)spinor_pvl_sfdp_dump();
        goto spinor_init_end;
    }

    spinor_early_exit:
    SPINOR_LOG_INFO("%s: Info, SPINOR core init completed \r\n", __func__);

    p_spinor_dev->nor_init_done = SPINOR_INIT_DONE;
    p_spinor_dev->ref_count = 0;
    status = SPINOR_DEVICE_DONE;

    spinor_init_end:
    return status;
}

/**********************************************************
 * De-initializes the spinor driver.
 * Free up resources used by the spinor driver
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_deinit (void)
{
  /*uint32 i = 0; */
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if ((p_spinor_dev->config_data->magic_number == SPINOR_INIT_CFG_MAGIC_NUMBER) &&
      (p_spinor_dev->nor_init_done == SPINOR_INIT_FAIL || p_spinor_dev->nor_init_done == SPINOR_INIT_NOT_DONE))
  {
    memset(p_spinor_dev->config_data, 0, sizeof(spinor_config_data));
    memset(p_spinor_dev, 0, sizeof(spinor_drv_info));
    return SPINOR_DEVICE_DONE;
  }

  if ((p_spinor_dev->ref_count) != 0)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x313);
    SPINOR_LOG_ERROR("%s: Error, reference count %d is not zero \r\n", __func__, p_spinor_dev->ref_count);
    status = SPINOR_DEVICE_FAIL;
    goto spinor_deinit_end;
  }

  /* We are clearing the context variables and setting the state machine to idle state so that incase of any errors within spinor,
     the statemachine is cleared before sending the reset command to the device
  */
  spinor_cmd_clear_bin_cmd_params();
  extern void spinorCMDEngineSetState(SPINOR_CMDEngineStatusType status);
  spinorCMDEngineSetState(SPINOR_CMD_ENGINE_IDLE);

  extern spinor_JobOperationCtxType spinor_jobOperationCtx;
  spinor_jobOperationCtx = (spinor_JobOperationCtxType){0};

  status = spinor_core_deinit();
  if(status != SPINOR_DEVICE_DONE)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x314);
      SPINOR_LOG_ERROR("%s: Error, SPINOR core deinit failed status = 0x%x\r\n", __func__, status);
      goto spinor_deinit_end;
  }

  memset(p_spinor_dev->config_data, 0, sizeof(spinor_config_data));

  /* Incase of SW reset done, we need to be in 3byte mode by default.
     during mission mode entry from PBL, 4byte mode is enabled by default.
     during reinit, p_spinor_dev->sw_reset_done value is needed to know if we should be in 3byte or 4byte mode
     */
  if (TRUE == p_spinor_dev->sw_reset_done)
  {
      memset(p_spinor_dev, 0, sizeof(spinor_drv_info));
      p_spinor_dev->sw_reset_done = TRUE;
  }
  else
  {
      memset(p_spinor_dev, 0, sizeof(spinor_drv_info));
  }

  spinor_cmd_clear_bin_cmd_params();
  extern void spinorCMDEngineSetState(SPINOR_CMDEngineStatusType status);
  spinorCMDEngineSetState(SPINOR_CMD_ENGINE_IDLE);

  extern spinor_JobOperationCtxType spinor_jobOperationCtx;
  spinor_jobOperationCtx = (spinor_JobOperationCtxType){0};

  status = SPINOR_DEVICE_DONE;

spinor_deinit_end:
  return status;
}

/**********************************************************
 * Prepares the spinor core for shutdown.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_shutdown(boolean is_crash_dbg_flag)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    bool stat = TRUE;
    timetick_type_64 t1,t2;
    uint64 timeout = 10000; //us

    /* Wait till the DMA is IDLE before resetting the QSPI controller */
    while(timeout > 0)
    {
        t1 = timetick_get64();
        stat = spinor_hal_is_dma_idle();
        if(stat == TRUE)
        {
            break;
        }
        t2 = timetick_get64();
        timeout -= elapsedtime_us(t2, t1);
    }

    /* Performs a SW reset of the device */
    status = spinor_util_device_software_reset();
    if(status != SPINOR_DEVICE_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x315);
        SPINOR_LOG_ERROR("%s: Error, spinor_util_device_software_reset fail status 0x%x \r\n", __func__, status);
        goto spinor_core_shutdown_end;
    }

    /* Performs a QSPI controller reset */
    spinor_hal_controller_reset();

    p_spinor_dev->mode_enabled = SPI_DEFAULT_SDR;
    p_spinor_dev->ecc_enabled_status_local = FALSE;
    p_spinor_dev->sw_reset_done = TRUE;
    p_spinor_dev->perfmode_enabled = FALSE;

    if (FALSE == is_crash_dbg_flag)
    {
        stat = spinor_disable_clocks();
        if(stat != TRUE)
        {
            status = SPINOR_DEVICE_FAIL;
            spinor_log (&p_spinor_dev->debug_log, 0x316);
            SPINOR_LOG_ERROR("%s: Error, spinor_disable_clocks fail \r\n", __func__);
            goto spinor_core_shutdown_end;
        }
    }

    //todo: Partial reinitialization to be called

    SPINOR_LOG_INFO("%s: Info, SPINOR core shutdown completed \r\n", __func__);

spinor_core_shutdown_end:
    return status;
}

/**********************************************************
 * De-initializes the controller
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_controller_deinit(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    boolean stat = TRUE;
    spinor_gpio_data qspi_sleep_gpio_data;
    timetick_type_64 t1,t2;
    uint64 timeout = 10000; //us

    /* Wait till the DMA is IDLE before resetting the QSPI controller */
    while(timeout > 0)
    {
        t1 = timetick_get64();
        stat = spinor_hal_is_dma_idle();
        if(stat == TRUE)
        {
            break;
        }
        t2 = timetick_get64();
        timeout -= elapsedtime_us(t2, t1);
    }

    /* Performs a QSPI controller reset */
    spinor_hal_controller_reset();

    stat = spinor_disable_clocks();
    if (stat != TRUE)
    {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x317);
        SPINOR_LOG_ERROR("%s: Error, spinor_disable_clocks fail \r\n", __func__);
        goto spinor_controller_deinit_end;
    }

    /* We are setting these GPIO settings only for QSPI devices */
    if(p_spinor_dev->config_data->device_type == SFDP_BUS_QSPI)
    {
        memset(&qspi_sleep_gpio_data, 0, sizeof(spinor_gpio_data));

        //Configure the QSPI GPIOs for sleep entry case
        stat = spinor_configure_gpios_sleep(&qspi_sleep_gpio_data);
        if(stat != TRUE)
        {
            status = SPINOR_DEVICE_FAIL;
            spinor_log (&p_spinor_dev->debug_log, 0x318);
            SPINOR_LOG_ERROR("%s: Error, spinor_configure_gpios_sleep fail \r\n", __func__);
            goto spinor_controller_deinit_end;
        }
    }

    p_spinor_dev->nor_init_done = SPINOR_INIT_SLEEP_DONE;
    p_spinor_dev->perfmode_enabled = FALSE;

spinor_controller_deinit_end:
    return status;
}


/**********************************************************
 * Switch the mux control from SAIL to MD.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_reconfig_mux(void)
{
    spinor_gpio_data mux_reconfig_gpio_data;
    memset(&mux_reconfig_gpio_data, 0, sizeof(spinor_gpio_data));

   //apply SAIL mux configuration to switch flash device control to MD and notify
   boolean bStatus = spinor_reconfigure_mux(&mux_reconfig_gpio_data);

   return (TRUE == bStatus) ? SPINOR_DEVICE_DONE : SPINOR_DEVICE_FAIL;
}

/**********************************************************
 * De-initializes the spinor Core.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_deinit(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    #ifdef NORPVL_ENB
      spinor_thead_delay_us = 0;
      spinor_thread_chunk_size = 0;
    #endif

    status = spinor_core_shutdown(is_crash_dbg);

    return status;
}

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
SPINOR_STATUS spinor_core_read_sfdp_signature(uint32* signature)
{
  SPINOR_STATUS status = spinor_sfdp_read_signature(signature);
  SPINOR_LOG_INFO("%s: Info, Signature read is 0x%x \r\n", __func__, signature);
  return status;
}
SPINOR_STATUS spinor_core_is_device_alive(void)
{
    boolean bRet = FALSE;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    status = spinor_learning_check_nor_pattern(&bRet);
    if ((status != SPINOR_DEVICE_DONE) || (FALSE == bRet) )
    {
        return SPINOR_DEVICE_FAIL;
    }
    else
    {
        return SPINOR_DEVICE_DONE;
    }
}

/**********************************************************
 * Runs the 8D-8D-8D sequence
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_run_octal_ddr_sequence(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    int8 length = 0, address_bytes = 0, data_bytes = 0;
    uint32 address = 0;
    uint8 data[3] = {0};

    for(int i = 0; i < (sizeof(p_spinor_dev->config_data->octal_ddr_cmd_seq) / sizeof(p_spinor_dev->config_data->octal_ddr_cmd_seq[0])); i++)
    {
        length = 0;
        address_bytes = 0;
        data_bytes = 0;
        address = 0;

        /* check if length > 0 */
        if(p_spinor_dev->config_data->octal_ddr_cmd_seq[i][0] > 0)
        {
            /* Store length in variable */
            length = p_spinor_dev->config_data->octal_ddr_cmd_seq[i][0];

            /* Subtract 1 for 1 byte of opcode and check for address bytes */
            length -= 1;
            if(length > 0)
            {
                /* subtract 3 bytes for 3 bytes of address */
                address_bytes = 3;
                length -= address_bytes;
            }

            /* Compute address */
            if(address_bytes > 0)
            {
                address = ((p_spinor_dev->config_data->octal_ddr_cmd_seq[i][2] << 16) |
                           (p_spinor_dev->config_data->octal_ddr_cmd_seq[i][3] << 8) |
                           (p_spinor_dev->config_data->octal_ddr_cmd_seq[i][4]));
            }
            else
            {
                address = 0;
            }

            /* Check data bytes size */
            if(length > 0)
            {
                /* Assign remaining bytes as data bytes */
                data_bytes = length;
            }

            /* Compute data */
            if(data_bytes == 0)
            {
                data[0] = 0;
                data[1] = 0;
                data[2] = 0;
            }
            else if(data_bytes == 1)
            {
                data[0] = p_spinor_dev->config_data->octal_ddr_cmd_seq[i][5];
                data[1] = 0;
                data[2] = 0;
            }
            else if(data_bytes == 2)
            {
                data[0] = p_spinor_dev->config_data->octal_ddr_cmd_seq[i][5];
                data[1] = p_spinor_dev->config_data->octal_ddr_cmd_seq[i][6];
                data[2] = 0;
            }
            else if(data_bytes == 3)
            {
                data[0] = p_spinor_dev->config_data->octal_ddr_cmd_seq[i][5];
                data[1] = p_spinor_dev->config_data->octal_ddr_cmd_seq[i][6];
                data[2] = p_spinor_dev->config_data->octal_ddr_cmd_seq[i][7];
            }
            else
            {
                /* Data bytes > 3, error out */
                status = SPINOR_DEVICE_FAIL;
                spinor_log (&p_spinor_dev->debug_log, 0x319);
                SPINOR_LOG_ERROR("%s: Error, Data bytes exceeds the max length \r\n", __func__);
                goto octal_ddr_sequence_end;
            }

            /* Run command sequence */
            spinor_OperationParamType xMemParams = {.addr = address, .buffer = (uint8 *)&data, .len = data_bytes, .opcode=p_spinor_dev->config_data->octal_ddr_cmd_seq[i][1], .dummy_cycle = 0, .num_addr_bytes = address_bytes, .is_write_operation = TRUE, .use_dma = FALSE};
            status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_BINARY_CMD, &xMemParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_log (&p_spinor_dev->debug_log, 0x31A);
                SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer 1 fail \r\n", __func__);
                goto octal_ddr_sequence_end;
            }
        }
        else
        {
            break;
        }
    }

octal_ddr_sequence_end:
    return status;
}

#ifdef NORPVL_ENB
SPINOR_STATUS spinor_core_change_params(uint32 thread_delay_us, uint32_t max_tranfr_pg_size)
{
    if(p_spinor_dev)
    {
       spinor_thead_delay_us = thread_delay_us;
       spinor_thread_chunk_size = max_tranfr_pg_size;
    }
    return SPINOR_DEVICE_DONE;
}
#endif
/* EOF */