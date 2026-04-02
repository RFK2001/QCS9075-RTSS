#ifndef __SPINOR_CLOCK_GPIO_H__
#define __SPINOR_CLOCK_GPIO_H__
/*
===========================================================================
*/
/**
    @file  spinor_clock_gpio.h
    @brief This file provides definitions for the spinor clock and gpio functions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_clock_gpio.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"

typedef struct
{
    uint32_t gpio_numbers[11];
    uint32_t gpio_func[11];
    uint32_t gpio_drive[11];
    uint32_t gpio_dir[11];
    uint32_t gpio_pull[11];
}spinor_gpio_data;

/**********************************************************
 * Configure SPINOR controller clocks
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_configure_clocks(void);

/**********************************************************
 * Disables clocks to QSPI
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_disable_clocks(void);

/**********************************************************
 * Set SPINOR controller core clock frequency
 *
 * @params uint32_t [IN]
 *   clock frequency in Hz
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_set_core_clk_freq(uint32_t nFreqHz);

/**********************************************************
 * Configure SPINOR GPIOs
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_configure_gpios(spinor_gpio_data* gpio_arrays);
/**********************************************************
 * Reconfigure SPINOR GPIO mux to SPINOR controller
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_reconfigure_mux(spinor_gpio_data* gpio_arrays);

/**********************************************************
 * Configure GPIOs for sleep case in QSPI cards
 *
 * @params gpio_arrays [IN/OUT]
 *   array with the GPIO information
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_configure_gpios_sleep(spinor_gpio_data* gpio_arrays);

#endif /* __SPINOR_CLOCK_GPIO_H__ */
