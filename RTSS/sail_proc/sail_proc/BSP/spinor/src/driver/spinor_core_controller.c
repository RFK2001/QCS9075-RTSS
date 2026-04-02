/*
===========================================================================
*/
/**
    @file  spinor_core_controller.c
    @brief This file implements function to configure the controller

*/
/*
    ===========================================================================

    Copyright (c) 2022-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_core_controller.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/
#include "spinor_clock_gpio.h"
#include "debug_log.h"
#include "spinor_utils.h"
#include "spinor_init_config.h"
#include "spinor_core.h"
#include "spinor_sfdp.h"
#include "spinor_learning.h"
#include "spinor_hal.h"
#include "spinor_diag.h"

/*==================================================================================================
                                               MACROS
==================================================================================================*/
#define SPINOR_DLL_EN_CTRL TRUE
/*==================================================================================================
                                             CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                              TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                          LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                     LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/**********************************************************
 * Initializes the spinor driver in 1-1-1 SDR PBL mode.
 * Invokes spinor_core_init_one_lane() to initialize spinor sub modules
 *
 * @param spinor_config_table [IN]
 *   RAM table containing config data for supported spinor devices
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_init_one_lane(boolean is_crash_dbg)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint32_t ulCoreClkFreqHz = 19200000; //(is_crash_dbg) ? 19200000 : 40000000;

  /* No need to reconfigure the core clock frequence if in crash_dbg */
  if (FALSE == is_crash_dbg && TRUE != spinor_set_core_clk_freq(ulCoreClkFreqHz))
  {
    DEBUG_LOG(SAIL_ERROR,"%s: Failed to set frequency of %dMHz for core clock \r\n", __func__, ulCoreClkFreqHz);
    return FALSE;
  }
  status = spinor_hal_hw_cfg_one_lane_pbl();
  if(status == SPINOR_DEVICE_FAIL)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x400);
    DEBUG_LOG(SAIL_ERROR,"%s: spinor_hal_hw_cfg_one_lane_pbl failed \r\n", __func__);
    return SPINOR_DEVICE_FAIL;
  }
  return status;
}

static SPINOR_STATUS spinor_core_init_perf_hw(boolean use_pbl)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  //OSPI_MASTER_CONFIG ospi_cfg;
  //bool octalspi_status;
  uint8_t  chip_select;          // chip select to assert during transaction (0 or 1)
  boolean  clk_polarity;         // clock polarity
  boolean  clk_phase;            // clock phase
  uint32_t clk_freq;             // bus clock frequency (4.8 MHz, 60 MHz, 66.625 MHz, or 75 MHz)
  boolean  DLL_en;
  uint8_t  DLL_enable_mode;      // preferred mode to choose from the configuration Default/SDR/DDR for the DLL configuration
  boolean  dqs_sync_qspi_clk;    // DQS Sync with QSPI CLK

  /* Zero inialize memory. */
  //memset(&ospi_cfg, 0, sizeof(OSPI_MASTER_CONFIG));

  /* Only 1 Chip Select */
  chip_select  = 0;
  /* This setting is for SPI mode */
  clk_polarity = FALSE;
  clk_phase    = FALSE;


  clk_freq = p_spinor_dev->config_data->freq_khz * 1000;
  /* For the init after the device look up enable DLL and use the mode depending on the frequency */
  if (p_spinor_dev->config_data->freq_khz >= 90000)
  {
    DLL_en       = SPINOR_DLL_EN_CTRL;
  }
  else
  {
    DLL_en       = FALSE;
  }

  /* DLL enable mode should be the one from the device transfer rate from config data.
     Add 1 to the value from the config data so that the value matches the enum value
     checked inside octalspi_init which uses OSPI_RAM_MODES
   */
  DLL_enable_mode = (uint8_t)p_spinor_dev->config_data->device_transfer_rate+1; //mzhu: Need to check with Dilip and Prerana


  p_spinor_dev->dll_config_en = DLL_en;
  dqs_sync_qspi_clk = p_spinor_dev->config_data->dqs_sync_qspi_clk;

  status = spinor_hal_hw_cfg_perf(clk_polarity, clk_phase, DLL_en, clk_freq, DLL_enable_mode, chip_select, dqs_sync_qspi_clk, use_pbl);
#if 0
  if(status == SPINOR_DEVICE_DONE)
  {
    ddr_dll_en_cfg = ((TRUE == DLL_en) && (OSPI_DDR_MODE == DLL_enable_mode)) ? 1 : 0;
  }
#endif
  return status;
}

/**********************************************************
 * Initializes the spinor driver to performance mode.
 *
 * @param spinor_config_table [IN]
 *   RAM table containing config data for supported spinor devices
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_init_perf(void *spinor_config_table, boolean use_pbl)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  SPINOR_STATUS nor_status = SPINOR_DEVICE_FAIL;
  uint8 result = 0;

  /* Core init sequence:
   * 1. Enable GPIO
   * 2. Set GPIO mux to SPINOR
   * 3. enable 1-1-1 STR PBL mode at 19.2MHz bus frequnece (core freq = 2 * 19.2MHz) and run SFDP based device discovery
   * 4. Verify that NOR flash memory's DLP pattern is correct. If not, overwrite to teh correct pattern
   * 5. Enable performance mode / mission mode
   */

  //mzhu qspi_init_status = TRUE;
  status = spinor_core_init_perf_hw (use_pbl);
  if ( status != SPINOR_DEVICE_DONE )
  {
      spinor_log (&p_spinor_dev->debug_log, 0x401);
      SPINOR_LOG_ERROR("%s: Error, perf mode hw initialization fail \r\n", __func__);
      goto perf_init_end;
  }

  p_spinor_dev->perfmode_enabled = TRUE;

  status = SPINOR_DEVICE_DONE;

perf_init_end:
  return status;
}
