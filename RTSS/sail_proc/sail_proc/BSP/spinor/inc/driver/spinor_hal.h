#ifndef __SPINOR_HAL_H__
#define __SPINOR_HAL_H__
/*
===========================================================================
*/
/**
    @file  spinor_hal.h
    @brief ocatal SPI HW IO defines

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_hal.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/

#include "types.h"
#include "sail_ospi_hwio.h"
#include "spinor_cm_defs.h"
#include "spinor_osal.h"


/*==================================================================================================
                                               MACROS
==================================================================================================*/
typedef enum
{
  OSPI_DEFAULT_MODE = 0x0,
  OSPI_SDR_MODE     = 0x1,
  OSPI_DDR_MODE     = 0x2,
} OSPI_RAM_MODES;

#define DLL_DDR_RCLK_VAL 0x53
/*==================================================================================================
                                              TYPEDEFS
==================================================================================================*/

/**********************************************************
 * Configure controller HW to PBL mode.
 *
 * @param NA
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_hw_cfg_one_lane_pbl(void);

/**********************************************************
 * This function loads the CDR phase configuration from the input provided
 *
 * @param uint8 [IN]
 *   cdr_sel
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_hal_load_CDR_cfg(uint8 cdr_sel);

/**********************************************************
 * This function loads the sampling clock
 *
 * @param uint8_t [IN]
 *   cfg
 *
 * @return void
 *
 **********************************************************/
void spinor_hal_load_sampling_clk_cfg(uint8_t *cfg);

/**********************************************************
 * This function calculates the mclk value
 *
 * @param uint32_t [IN]
 *   clock_freq
 *
 * @return void
 *
 **********************************************************/
uint8 spinor_hal_dll_init_mclk_val(uint32_t clock_freq);

/**********************************************************
 * This function does some pre-requsite configuration for SDR DLL
 *
 * @param NA
 *
 * @return void
 *
 **********************************************************/
SPINOR_STATUS DLL_SDR_config_prerequsites(void);

/**********************************************************
 * This function does some pre-requsite configuration for DDR DLL
 *
 * @param NA
 *
 * @return void
 *
 **********************************************************/
SPINOR_STATUS DLL_DDR_config_prerequsites(void);

/**********************************************************
 * This function initializes the QSPI registers and puts the QSPI into a known state.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_hw_cfg_perf(boolean clk_polarity, boolean clk_phase, boolean DLL_en, uint32_t bus_clk_freq, uint8_t DLL_enable_mode, uint8_t chip_select, boolean dqs_sync_qspi_clk, boolean use_pbl);

/**********************************************************
 * This function initializes the QSPI registers and puts the QSPI into a known state for the legacy mode.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_legacy_cfg_perf(uint32_t bus_clk_freq, uint8_t DLL_enable_mode);

/**********************************************************
 * This function initializes the QSPI registers for the case where DQS sync is enabled.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_dqs_sync_en_cfg(void);

/**********************************************************
 * This function initializes the QSPI registers for the case where DQS sync is disabled.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_dqs_sync_disable_cfg(void);

/**********************************************************
 * This function enables/disables DMA mode via the MSTR_CONFIG register.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_configure_dma_mode(bool enable_dma);

/**********************************************************
 * This function transfers a chain of descriptors over the bus using DMA mode.
 *
 * @return void
 *
 **********************************************************/
void spinor_hal_dma_transfer_chain(uint32_t chain);

/**********************************************************
 * This function checks if the DMA transfer is complete.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_hal_is_dma_transfer_done(void);

/**********************************************************
 * This function performs a PIO read transfer using a single transaction.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_pio_read(uint8_t *buffer, uint32_t num_bytes, uint32_t pio_transfer_config);

/**********************************************************
 * This function performs a PIO write transfer using a single transaction.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_pio_write(uint8_t *buffer, uint32_t num_bytes, uint32_t pio_transfer_config);

/**********************************************************
 * This function checks if the PIO transfer is complete.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_hal_is_pio_transer_done(void);
/*==================================================================================================

FUNCTION: spinor_hal_is_dma_idle

DESCRIPTION:
   Checks if the OSPI DMA is idle.

==================================================================================================*/
boolean spinor_hal_is_dma_idle(void);

/**********************************************************
 * This function performs Controller Reset.
 *
 * @return void [OUT]
 *   Result of the operation.
 *
 **********************************************************/
void spinor_hal_controller_reset(void);

/**********************************************************
 * This function services the receive fifo.
 *
 * @param ptr [IN]
 *   Pointer to the data buffer
 *
 * @param num_bytes [IN]
 *   Length of the data
 *
 * @return void [OUT]
 *   Number of bytes completed.
 *
 **********************************************************/
uint32_t spinor_hal_service_rx_fifo(uint8_t *ptr, uint32_t num_bytes);

/**********************************************************
 * This function services the Send fifo.
 *
 * @param ptr [IN]
 *   Pointer to the data buffer
 *
 * @param num_bytes [IN]
 *   Length of the data
 *
 * @return void [OUT]
 *   Number of bytes completed.
 *
 **********************************************************/
uint32_t spinor_hal_service_tx_fifo(uint8_t *ptr, uint32_t num_bytes);


#endif  // __SPINOR_HAL_H__
