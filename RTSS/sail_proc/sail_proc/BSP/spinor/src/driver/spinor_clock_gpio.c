/*
===========================================================================
*/
/**
    @file  spinor_clock_gpio.c
    @brief Implementation of spinor clock and gpio driver

*/
/*
    ===========================================================================

    Copyright (c) 2017,2019,2020-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_clock_gpio.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/
#include "gpio.h"
#include "Clock.h"
#include "spinor_clock_gpio.h"
#include "debug_log.h"
#include "libfdt.h"
#include "fdt_utils.h"
#include "chipinfo.h"
#include "chipinfodefs.h"
#include "platforminfodefs.h"
#include "spinor_init_config.h"

/*==================================================================================================
                                               MACROS
==================================================================================================*/


/*==================================================================================================
                                             CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                              TYPEDEFS
==================================================================================================*/
typedef enum
{
   QSPI_AHB_CLK = 0,
   QSPI_CORE_CLK = 1,
} OSPI_CLK_ID;

typedef struct
{
  OSPI_CLK_ID clk_id;
  const char* szName;
  uint32 freq_in_mHz;
  ClockIdType nClockId;
}OSPIClkParams;

/*==================================================================================================
                                          LOCAL VARIABLES
==================================================================================================*/

static OSPIClkParams xOSPICfgClocks[] =
{
    { QSPI_AHB_CLK, "sailss_cc_qspi_ahb_clk",  166, 0},    /* SRC PLL2 - 166Mhz Max Nom , cbc,  sailss_cc_asilb_qspi_qh_grp  */
    { QSPI_CORE_CLK, "sailss_cc_qspi_core_clk", 166, 0}, /* SRC PLL2 - 332Mhz Max Nom , cbc,  sailss_cc_qspi_core_grp  */
};

ClockHandle hClient = (ClockHandle) NULL;

/*==================================================================================================
                                     LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================

FUNCTION: prvSPINORReadDeviceTreeSettings

DESCRIPTION:
   Configure Device tree settings for GPIOs

==================================================================================================*/
static boolean prvSPINORReadDeviceTreeSettings(const char* func, int size, spinor_gpio_data *gpio_arrays)
{
    void* pDTB = NULL;
    int root_offset = 0, offset = 0;
    const char* path;
    int valSize = size;
    char ospi_monaco[6] = { 'o', 's', 'p', 'i','0','\0' };
    char ospi_lemans[6] = { 'o', 's', 'p', 'i','1','\0' };

    GPIOConfigType xSpinorPinCfg = { 0x0u };
    uint8 ucGpioNumbers = 0x0u;

    ChipInfoFamilyType xIsMonacoChip = CHIPINFO_FAMILY_32BITS;
    xIsMonacoChip = ChipInfo_GetChipFamily();

    /* Check which GPIO pins should be used based on device tree and chipinfo */
    if (gpio_arrays->gpio_numbers[0] == 0)
    {
        pDTB = fdt_get_dtb();
        if (NULL != pDTB)
        {
            root_offset = fdt_path_offset(pDTB, "/aliases");
            if (root_offset > 0)
            {
                if (CHIPINFO_FAMILY_MONACOAU == xIsMonacoChip)
                {
                    path = (const char*)fdt_getprop(pDTB, root_offset, ospi_monaco, NULL);
                }
                else
                {
                    path = (const char*)fdt_getprop(pDTB, root_offset, ospi_lemans, NULL);
                }
                if (NULL != path)
                {
                    offset = fdt_path_offset(pDTB, path);
                    (void)fdt_getprop_u32_array(pDTB, offset, "pins", gpio_arrays->gpio_numbers, &valSize);
                    (void)fdt_getprop_u32_array(pDTB, offset, "drive-strength", gpio_arrays->gpio_drive, &valSize);
                    (void)fdt_getprop_u32_array(pDTB, offset, "dir", gpio_arrays->gpio_dir, &valSize);

                    /* Choose function select value based on the usecase */
                    if((strcmp(func, "sleep")) == 0)
                    {
                        (void)fdt_getprop_u32_array(pDTB, offset, "sleep_func", gpio_arrays->gpio_func, &valSize);
                    }
                    else if((strcmp(func, "reconfig")) == 0)
                    {
                        (void)fdt_getprop_u32_array(pDTB, offset, "mux_func", gpio_arrays->gpio_func, &valSize);
                    }
                    else
                    {
                        (void)fdt_getprop_u32_array(pDTB, offset, "func", gpio_arrays->gpio_func, &valSize);
                    }

                    /* Choose bias (pull) value based on the usecase */
                    if((strcmp(func, "sleep")) == 0)
                    {
                        (void)fdt_getprop_u32_array(pDTB, offset, "sleep_bias", gpio_arrays->gpio_pull, &valSize);
                    }
                    else
                    {
                        (void)fdt_getprop_u32_array(pDTB, offset, "bias", gpio_arrays->gpio_pull, &valSize);
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
        }
        else
        {
            return false;
        }
    }

    for (int i = 0; i < valSize; i++)
    {
        ucGpioNumbers = (uint8)gpio_arrays->gpio_numbers[i];
        xSpinorPinCfg.func = gpio_arrays->gpio_func[i];
        xSpinorPinCfg.drive = gpio_arrays->gpio_drive[i];
        xSpinorPinCfg.dir = gpio_arrays->gpio_dir[i];
        xSpinorPinCfg.pull = gpio_arrays->gpio_pull[i];
        sail_gpio_config_pin(ucGpioNumbers, xSpinorPinCfg);
    }

    return true;
}

/*==================================================================================================

FUNCTION: configure_clocks

DESCRIPTION:
   Turn on the clocks to QSPI.

==================================================================================================*/
boolean spinor_configure_clocks(void)
{
  ClockResult eResult = CLOCK_SUCCESS;
  uint32_t nFreqHz;
  bool status = TRUE;

  // PNOC clock need not be explicitly set.  Configure the QSPI reference clock as
  // needed to get the requested bus frequency (in DLL mode, we will not use SBL_EN=1
  // so reference frequency will be twice of requested bus frequency). The reference
  // clock is specified in kHz and the bus clock is specified in Hz.

  /* Turn on qspi_ahb_clk with frequency of 166MHz and sailss_cc_qspi_core_clk with frequency of 332MHz */

  Clock_GetHandle(&hClient);
  for(uint8_t i=0; i<SIZEOF_ARRAY(xOSPICfgClocks); i++)
  {
      eResult = Clock_GetClockId( hClient, xOSPICfgClocks[i].szName, &xOSPICfgClocks[i].nClockId);
      if (eResult != CLOCK_SUCCESS)
      {
          DEBUG_LOG(SAIL_ERROR,"Failed to find clockId for %d \r\n",xOSPICfgClocks[i].clk_id);
          status = FALSE;
          break;
      }
      eResult = Clock_SetClockFrequency (hClient, xOSPICfgClocks[i].nClockId, xOSPICfgClocks[i].freq_in_mHz, CLOCK_FREQUENCY_MHZ_EXACT,&nFreqHz);
      if (eResult != CLOCK_SUCCESS)
      {
          DEBUG_LOG(SAIL_ERROR,"Failed to set frequency of %dMHz for %d \r\n",xOSPICfgClocks[i].freq_in_mHz, xOSPICfgClocks[i].clk_id);
          status = FALSE;
          break;
      }
      eResult = Clock_EnableClock(hClient, xOSPICfgClocks[i].nClockId);
      if (eResult != CLOCK_SUCCESS)
      {
          DEBUG_LOG(SAIL_ERROR,"Failed to enable %d \r\n",xOSPICfgClocks[i].clk_id);
          status = FALSE;
          break;
      }
      DEBUG_LOG(SAIL_INFO,"%s: Set frequency of %dMHz for %d, %s \r\n",
	            __func__, xOSPICfgClocks[i].freq_in_mHz, xOSPICfgClocks[i].clk_id, xOSPICfgClocks[i].szName);
  }
  return status;
}


/*==================================================================================================

FUNCTION: disable_clocks

DESCRIPTION:
   Disables clocks to QSPI.

==================================================================================================*/
boolean spinor_disable_clocks(void)
{
  ClockResult eResult = CLOCK_SUCCESS;
  uint32_t nFreqHz;
  bool status = TRUE;

  Clock_GetHandle(&hClient);
  if ((ClockHandle)NULL != hClient)
  {
      for (uint8_t i = 0; i < SIZEOF_ARRAY(xOSPICfgClocks); i++)
      {
          eResult = Clock_GetClockId( hClient, xOSPICfgClocks[i].szName, &xOSPICfgClocks[i].nClockId);
          if (eResult != CLOCK_SUCCESS)
          {
              DEBUG_LOG(SAIL_ERROR,"Failed to find clockId for %d \r\n",xOSPICfgClocks[i].clk_id);
              status = FALSE;
              break;
          }

          eResult = Clock_DisableClock(hClient, xOSPICfgClocks[i].nClockId);
          if (eResult != CLOCK_SUCCESS)
          {
              DEBUG_LOG(SAIL_ERROR,"Failed to disable %d \r\n",xOSPICfgClocks[i].clk_id);
              status = FALSE;
              break;
          }
          DEBUG_LOG(SAIL_INFO,"%s: Disabled clock %d, %s \r\n",
                    __func__, xOSPICfgClocks[i].clk_id, xOSPICfgClocks[i].szName);
      }
  }
  return status;
}

boolean spinor_set_core_clk_freq(uint32_t nFreqHz)
{
    ClockResult eResult;
    uint32_t nResultFreqHz = 0;

    /* Set core clock frequency */
    eResult = Clock_SetClockFrequency (hClient, xOSPICfgClocks[QSPI_CORE_CLK].nClockId, nFreqHz, CLOCK_FREQUENCY_HZ_AT_LEAST,&nResultFreqHz);

	DEBUG_LOG(SAIL_INFO,"%s: Set frequency of %dkHz for %d, QSPI_CORE_CLK \r\n",
	            __func__, nFreqHz/1000, xOSPICfgClocks[QSPI_CORE_CLK].nClockId);

    return eResult == CLOCK_SUCCESS;
}
/*==================================================================================================

FUNCTION: configure_gpios

DESCRIPTION:
   Configure TLMM so that QSPI signals are routed to the GPIO pads.

==================================================================================================*/
boolean spinor_configure_gpios(spinor_gpio_data* gpio_arrays)
{
    boolean status;
    const char* val = "active";

    status = prvSPINORReadDeviceTreeSettings(val, 11, gpio_arrays);
    if (status != true)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: GPIO config failed \r\n", __func__);
    }
    return status;
}
/*==================================================================================================

FUNCTION: spinor_reconfigure_mux_md

DESCRIPTION:
   Configure TLMM so that QSPI signals are routed to the GPIO pads.

==================================================================================================*/
boolean spinor_reconfigure_mux(spinor_gpio_data* gpio_arrays)
{
    boolean status;
    const char* val = "reconfig";

    status = prvSPINORReadDeviceTreeSettings(val, 4, gpio_arrays);
    if (status != true)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: Reconfigure MD mux failed \r\n", __func__);
    }
    return status;
}

/*==================================================================================================

FUNCTION: spinor_configure_gpios_sleep

DESCRIPTION:
   Configure GPIOs for sleep case in QSPI cards.

==================================================================================================*/
boolean spinor_configure_gpios_sleep(spinor_gpio_data* gpio_arrays)
{
    boolean status;
    const char* val = "sleep";

    status = prvSPINORReadDeviceTreeSettings(val, 11, gpio_arrays);
    if (status != true)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: GPIO config for QSPI in sleep case failed \r\n", __func__);
    }
    return status;
}