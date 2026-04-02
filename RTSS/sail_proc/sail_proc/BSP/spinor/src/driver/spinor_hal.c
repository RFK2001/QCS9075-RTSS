/*
===========================================================================
*/
/**
    @file  spinor_hal.c
    @brief Implementation of spinor driver hal

*/
/*
    ===========================================================================

    Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_hal.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_hal.h"
#include "spinor_clock_gpio.h"
#include "debug_log.h"
#include "boot_logger.h"
#include "HALclkHWIO.h"
#include "HALhwio.h"
#include "sail_ospi_hwio.h"

/* DLL Configuration values */
#define DLL_CLK_OUTPUT_PHASE_VAL 0
#define QSPI_MASTER_CONFIG_DELAY_LINE_VAL 0xC
#define DLL_LOCK_TIMEOUT_US 15

#define REG_IN(reg, value_ptr) \
   do { \
      *(value_ptr) = *(volatile uint32_t *)(QSPI_REG_BASE + reg); \
   } while (0)

#define REG_OUT(reg, value) \
   do { \
      *(volatile uint32_t *)(QSPI_REG_BASE + reg) = (value); \
   } while (0)

#define INT_TO_PTR(x) (void *)(uintptr_t)(x)

#ifdef SPINOR_PRE_SIL
#include "chipinfo.h"
typedef enum
{
  OSPI_PLATFORM_UNKNOWN,
  OSPI_PLATFORM_RUMI,
  OSPI_PLATFORM_VIRTIO,
  OSPI_PLATFORM_SILICON,
  OSPI_PLATFORM_MAX,
} OSPI_Platform_TYPE;
/*==================================================================================================

FUNCTION: Get the platforminfo type in the runtime

DESCRIPTION:
   This function uses the platforminfo lib to obtain the runtime platform type.

==================================================================================================*/
static OSPI_Platform_TYPE get_platform_type(void)
{
  static OSPI_Platform_TYPE ospi_platform = OSPI_PLATFORM_UNKNOWN;
  PlatformInfoPlatformType platform;

  if (ospi_platform == OSPI_PLATFORM_UNKNOWN)
  {
    platform = PlatformInfo_Platform();

    switch(platform)
    {
      case PLATFORMINFO_TYPE_RUMI:
      {
        ospi_platform = OSPI_PLATFORM_RUMI;
      }
      break;

      case PLATFORMINFO_TYPE_VIRTIO:
      {
        ospi_platform = OSPI_PLATFORM_VIRTIO;
      }
      break;

      default:
        ospi_platform = OSPI_PLATFORM_SILICON;
    }
  }

  return ospi_platform;
}
#endif

/**********************************************************
 * Configure controller HW to PBL mode.
 *
 * @param NA
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_hal_hw_cfg_one_lane_pbl(void)
{
  uint32_t ulVal;
  uint32_t ulTmp;
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  do
  {
    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &ulVal);
    /* enable FB_CLK_EN = 1 */
    ulVal |= HWIO_QSPI_MSTR_CONFIG_FB_CLK_EN_BMSK;

    /* Enable full cycle mode. SPI_MODE must be 0 */
    ulVal |= HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK;
    ulVal &= ~HWIO_QSPI_MSTR_CONFIG_SPI_MODE_BMSK;

    /* Disable DMA */
    ulVal &= ~HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK;

    /* Disable SBL */
    ulVal &= ~HWIO_QSPI_MSTR_CONFIG_SBL_EN_BMSK;

    /* PIN_WPN = 0 */
    ulVal &= ~HWIO_QSPI_MSTR_CONFIG_PIN_WPN_BMSK;

    /* PIN_HOLDN = 1 */
    ulVal |= HWIO_QSPI_MSTR_CONFIG_PIN_HOLDN_BMSK;

    REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, ulVal);
    /* Read after write and compare the result */
    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &ulTmp);
    if (ulTmp != ulVal)
    {
        break;
    }

    /* Disable QSPI_<STR_INT_ENABLE */
    ulVal = 0;
    REG_OUT(HWIO_QSPI_MSTR_INT_ENABLE_OFFS, ulVal);
    REG_IN(HWIO_QSPI_MSTR_INT_ENABLE_OFFS, &ulTmp);
    if(ulVal != ulTmp)
    {
      break;
    }
    status = SPINOR_DEVICE_DONE;
  } while (0);

  return status;
}


/*==================================================================================================

FUNCTION: DLL_SDR_config_init

DESCRIPTION:
   This function initializes the QSPI DLL for SDR configuration.

==================================================================================================*/
static SPINOR_STATUS DLL_SDR_config_init(void)
{
  uint32_t dll_config,dll_status, read_val;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  status = DLL_SDR_config_prerequsites();
  if(status != SPINOR_DEVICE_DONE)
  {
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: DLL SDR init config pre-requisites failed \r\n", __func__);
      goto DLL_SDR_config_init_end;
  }

   /* a.Wait until CK_OUT_EN bit of HC_REG_DLL_CONFIG register is 0. */
   REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_status);
   if (dll_status & HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK)
   {
       status = SPINOR_DEVICE_FAIL;
   }

   SPINOR_DSB;

   /* b.Write the selected DLL clock output phase (0 – 15) to CDR_SELEXT bit field of HC_REG_DLL_CONFIG register in gray code */
   REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);
   dll_config = (dll_config & ~(HWIO_HC_REG_DLL_CONFIG_CDR_SELEXT_BMSK)) |(DLL_CLK_OUTPUT_PHASE_VAL << HWIO_HC_REG_DLL_CONFIG_CDR_SELEXT_SHFT);
   REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
   REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
   if(read_val != dll_config)
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 5 failed \r\n", __func__);
       goto DLL_SDR_config_init_end;
   }
   SPINOR_DSB;

   /* c.Set CK_OUT_EN bit of HC_REG_DLL_CONFIG register to 1. */
   dll_config |= HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK;
   REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
   REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
   if(read_val != dll_config)
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 6 failed \r\n", __func__);
       goto DLL_SDR_config_init_end;
   }
   SPINOR_DSB;

   /* d.Wait until CK_OUT_EN bit of HC_REG_DLL_CONFIG register is 1 */
   REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_status);
   if (!(dll_status & HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK))
   {
       status = SPINOR_DEVICE_FAIL;
   }

   SPINOR_DSB;

   /* e.For SDR mode DLL_CLOCK_DISABLE in HC_REG_DLL_CONFIG_2 register should be cleared because DLL requires qspi_sampling_clk_phase0 toggling for SDR mode (for DLL_LOCK). */
   REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS,&dll_config);
   dll_config &= ~HWIO_HC_REG_DLL_CONFIG_2_DLL_CLOCK_DISABLE_BMSK;
   REG_OUT(HWIO_HC_REG_DLL_CONFIG_2_OFFS,dll_config);
   REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS, &read_val);
   if(read_val != dll_config)
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 7 failed \r\n", __func__);
       goto DLL_SDR_config_init_end;
   }
   SPINOR_DSB;

DLL_SDR_config_init_end:
    return status;
}

/*==================================================================================================

FUNCTION: DLL_SDR_config_prerequsites

DESCRIPTION:
   This function does some pre-requsite configuration for SDR DLL

==================================================================================================*/
SPINOR_STATUS DLL_SDR_config_prerequsites(void)
{
    uint32_t dll_config, read_val;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);
    SPINOR_DSB;

    dll_config &= ~HWIO_HC_REG_DLL_CONFIG_CDR_EN_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
      goto DLL_SDR_config_prerequsites_end;
    }
    SPINOR_DSB;

    dll_config |= HWIO_HC_REG_DLL_CONFIG_CDR_EXT_EN_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 2 failed \r\n", __func__);
      goto DLL_SDR_config_prerequsites_end;
    }
    SPINOR_DSB;

    dll_config &= ~HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 3 failed \r\n", __func__);
       goto DLL_SDR_config_prerequsites_end;
    }
    SPINOR_DSB;

    dll_config |= HWIO_HC_REG_DLL_CONFIG_DLL_EN_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 4 failed \r\n", __func__);
       goto DLL_SDR_config_prerequsites_end;
    }
    SPINOR_DSB;

DLL_SDR_config_prerequsites_end:
    return status;
}

/*==================================================================================================

FUNCTION: DLL_DDR_config_init

DESCRIPTION:
   This function initializes the QSPI DLL for DDR configuration.

==================================================================================================*/
static SPINOR_STATUS DLL_DDR_config_init(void)
{
  uint32_t dll_config = 0;
  uint32_t ddr_config,dll_status = 0;
  uint32_t read_val = 0;

  uint8 timeout = DLL_LOCK_TIMEOUT_US;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  status = DLL_DDR_config_prerequsites();
  if(status != SPINOR_DEVICE_DONE)
  {
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: DLL SDR init config pre-requisites failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

  REG_OUT(HWIO_HC_REG_DLL_CONFIG_3_OFFS,0x1);
  REG_OUT(HWIO_HC_REG_DLL_USER_CTL_OFFS,0x2C010800);
  REG_OUT(HWIO_HC_REG_DLL_TEST_CTL_OFFS,0xC1400000);

  REG_IN(HWIO_HC_REG_DDR_CONFIG_OFFS,&ddr_config);

  SPINOR_DSB;

  ddr_config = (ddr_config & ~(HWIO_HC_REG_DDR_CONFIG_PRG_RCLK_DLY_BMSK)) |(DLL_DDR_RCLK_VAL << HWIO_HC_REG_DDR_CONFIG_PRG_RCLK_DLY_SHFT);
  REG_OUT(HWIO_HC_REG_DDR_CONFIG_OFFS,ddr_config);
  REG_IN(HWIO_HC_REG_DDR_CONFIG_OFFS, &read_val);
  if(read_val != ddr_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 6 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

  ddr_config |= HWIO_HC_REG_DDR_CONFIG_PRG_DLY_EN_BMSK;
  REG_OUT(HWIO_HC_REG_DDR_CONFIG_OFFS,ddr_config);
  REG_IN(HWIO_HC_REG_DDR_CONFIG_OFFS, &read_val);
  if(read_val != ddr_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 7 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);
  dll_config = ((dll_config & ~(HWIO_HC_REG_DLL_CONFIG_MCLK_FREQ_BMSK)) |(5 << HWIO_HC_REG_DLL_CONFIG_MCLK_FREQ_SHFT));
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 8 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

   REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS,&dll_config);
   SPINOR_DSB;
   dll_config = ((dll_config & ~(HWIO_HC_REG_DLL_CONFIG_2_MCLK_FREQ_CALC_BMSK)) |(0x23 << HWIO_HC_REG_DLL_CONFIG_2_MCLK_FREQ_CALC_SHFT));
   REG_OUT(HWIO_HC_REG_DLL_CONFIG_2_OFFS,dll_config);
   REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS, &read_val);
   if(read_val != dll_config)
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 9 failed \r\n", __func__);
       goto DLL_DDR_config_init_end;
   }

  SPINOR_DSB;

  REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS,&dll_config);
  dll_config |= HWIO_HC_REG_DLL_CONFIG_2_DDR_CAL_EN_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_2_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 10 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }
  SPINOR_DSB;

  REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS,&dll_config);
  dll_config &= ~HWIO_HC_REG_DLL_CONFIG_2_DLL_CLOCK_DISABLE_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_2_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS, &read_val);
  if(read_val != dll_config)
  {
    //not written right
    status = SPINOR_DEVICE_FAIL;
    DEBUG_LOG(SAIL_ERROR,"%s: readback 11 failed \r\n", __func__);
    goto DLL_DDR_config_init_end;
  }

  SPINOR_DSB;

  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &dll_config);

  SPINOR_DSB;

  dll_config |= HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK;
  dll_config |= HWIO_HC_REG_DLL_CONFIG_DLL_EN_BMSK;
  dll_config |= HWIO_HC_REG_DLL_CONFIG_RCLK_IN_TEST_EN_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 11 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

  spinor_udelay(100);

  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &dll_config);
  SPINOR_DSB;

  dll_config &= ~HWIO_HC_REG_DLL_CONFIG_DLL_RST_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 12 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

  SPINOR_DSB;

  dll_config &= ~HWIO_HC_REG_DLL_CONFIG_PDN_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 13 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

  SPINOR_DSB;

  dll_config |= HWIO_HC_REG_DLL_CONFIG_DLL_RST_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 14 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

  SPINOR_DSB;

  dll_config &= ~HWIO_HC_REG_DLL_CONFIG_DLL_RST_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 15 failed \r\n", __func__);
      goto DLL_DDR_config_init_end;
  }

  SPINOR_DSB;

  spinor_udelay(100);

  while (timeout > 0)
  {
    /* delay between each poll */
    spinor_udelay(1);
    timeout -= 1;

    REG_IN(HWIO_HC_REG_DLL_STATUS_OFFS,&dll_status);
    if (dll_status & HWIO_HC_REG_DLL_STATUS_DDR_DLL_LOCK_BMSK)
    {
        break;
    }
  }

  SPINOR_DSB;


DLL_DDR_config_init_end:
  return status;
}

/*==================================================================================================

FUNCTION: DLL_DDR_config_prerequsites

DESCRIPTION:
   This function does some pre-requsite configuration for DDR DLL

==================================================================================================*/
SPINOR_STATUS DLL_DDR_config_prerequsites(void)
{
    uint32_t dll_config, read_val;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);
    SPINOR_DSB;

    dll_config &= ~HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
       goto DLL_DDR_config_prerequsites_end;
    }
    SPINOR_DSB;


    dll_config |= HWIO_HC_REG_DLL_CONFIG_DLL_EN_BMSK;
    dll_config |= HWIO_HC_REG_DLL_CONFIG_CDR_EXT_EN_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 2 failed \r\n", __func__);
       goto DLL_DDR_config_prerequsites_end;
    }
    SPINOR_DSB;


    REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS,&dll_config);
    dll_config |= HWIO_HC_REG_DLL_CONFIG_2_DLL_CLOCK_DISABLE_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_2_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS, &read_val);
    if(read_val != dll_config)
    {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 3 failed \r\n", __func__);
      goto DLL_DDR_config_prerequsites_end;
    }

    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);

    SPINOR_DSB;

    dll_config |= HWIO_HC_REG_DLL_CONFIG_DLL_RST_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 4 failed \r\n", __func__);
      goto DLL_DDR_config_prerequsites_end;
    }

    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);

    SPINOR_DSB;

    dll_config |= HWIO_HC_REG_DLL_CONFIG_PDN_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
    if(read_val != dll_config)
    {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 5 failed \r\n", __func__);
      goto DLL_DDR_config_prerequsites_end;
    }

DLL_DDR_config_prerequsites_end:
  return status;
}

/*==================================================================================================

FUNCTION: spinor_hal_load_sampling_clk_cfg

DESCRIPTION:
   This function loads the sampling clock configuration from the input provided.

==================================================================================================*/
void spinor_hal_load_sampling_clk_cfg(uint8_t *cfg)
{
    uint32_t read_val;

    if (cfg)
    {

        /* Disable the load before changing the sampling config */
        REG_IN(HWIO_QSPI_SAMPLING_CLK_CONFIG_OFFS, &read_val);
        read_val = read_val & ~ HWIO_QSPI_SAMPLING_CLK_CONFIG_EN_LOAD_CLK_CNTR_BMSK;
        REG_OUT(HWIO_QSPI_SAMPLING_CLK_CONFIG_OFFS, read_val);

        SPINOR_DSB;


        read_val = 0;

        /* set all lane config to shift level i */
        /* Enable the clock after loading sampling config */
        read_val = (cfg[7] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE7_CLK_CNTR_INIT_VAL_SHFT) |
                   (cfg[6] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE6_CLK_CNTR_INIT_VAL_SHFT) |
                   (cfg[5] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE5_CLK_CNTR_INIT_VAL_SHFT) |
                   (cfg[4] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE4_CLK_CNTR_INIT_VAL_SHFT) |
                   (cfg[3] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE3_CLK_CNTR_INIT_VAL_SHFT) |
                   (cfg[2] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE2_CLK_CNTR_INIT_VAL_SHFT) |
                   (cfg[1] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE1_CLK_CNTR_INIT_VAL_SHFT) |
                   (cfg[0] << HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE0_CLK_CNTR_INIT_VAL_SHFT) |
                   (1 << HWIO_QSPI_SAMPLING_CLK_CONFIG_EN_LOAD_CLK_CNTR_SHFT);

        SPINOR_DSB;

        REG_OUT(HWIO_QSPI_SAMPLING_CLK_CONFIG_OFFS, read_val);

        SPINOR_DSB;

    }
    return;
}

/*==================================================================================================

FUNCTION: DLL_init

DESCRIPTION:
   This function initializes the QSPI DLL.

==================================================================================================*/
static SPINOR_STATUS DLL_init(uint32_t clock_freq)
{
  uint32_t dll_config,dll_status, read_val;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint8 timeout = DLL_LOCK_TIMEOUT_US, dll_init_mclk_freq_loc = 0;

  dll_init_mclk_freq_loc = spinor_hal_dll_init_mclk_val(clock_freq);

  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);

  SPINOR_DSB;

  dll_config |= HWIO_HC_REG_DLL_CONFIG_DLL_RST_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
      goto DLL_init_end;
  }


  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);

  SPINOR_DSB;

  dll_config |= HWIO_HC_REG_DLL_CONFIG_PDN_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 2 failed \r\n", __func__);
      goto DLL_init_end;
  }

  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);

  SPINOR_DSB;

  dll_config = ((dll_config & ~(HWIO_HC_REG_DLL_CONFIG_MCLK_FREQ_BMSK)) |(dll_init_mclk_freq_loc << HWIO_HC_REG_DLL_CONFIG_MCLK_FREQ_SHFT));
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 3 failed \r\n", __func__);
      goto DLL_init_end;
  }

  SPINOR_DSB;

  dll_config &= ~HWIO_HC_REG_DLL_CONFIG_DLL_RST_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 4 failed \r\n", __func__);
      goto DLL_init_end;
  }

  SPINOR_DSB;

  dll_config &= ~HWIO_HC_REG_DLL_CONFIG_PDN_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 5 failed \r\n", __func__);
      goto DLL_init_end;
  }

  SPINOR_DSB;

  dll_config |= HWIO_HC_REG_DLL_CONFIG_DLL_EN_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 6 failed \r\n", __func__);
      goto DLL_init_end;
  }

  SPINOR_DSB;

  dll_config |= HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK;
  REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
  REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
  if(read_val != dll_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 6 failed \r\n", __func__);
      goto DLL_init_end;
  }

   /* Wait until DLL_LOCK bit of HC_REG_DLL_STATUS register is 1. */
   while (timeout > 0)
   {
     /* delay between each poll */
     spinor_udelay(1);
     timeout -= 1;

     REG_IN(HWIO_HC_REG_DLL_STATUS_OFFS,&dll_status);
     if (dll_status & HWIO_HC_REG_DLL_STATUS_DLL_LOCK_BMSK)
     {
         break;
     }
   }

   if(0==(dll_status & HWIO_HC_REG_DLL_STATUS_DLL_LOCK_BMSK))
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 7 failed \r\n", __func__);
       goto DLL_init_end;
   }

DLL_init_end:
  return status;
}

/*==================================================================================================

FUNCTION: spinor_hal_dll_init_mclk_val

DESCRIPTION:
   This function calculates the mclk value

==================================================================================================*/
uint8 spinor_hal_dll_init_mclk_val(uint32_t clock_freq)
{
    uint8 dll_init_mclk_freq = 0;

    switch(clock_freq)
    {
        case 100 ... 112:
          dll_init_mclk_freq = 0;
          break;

        case 113 ... 125:
          dll_init_mclk_freq = 1;
          break;

        case 126 ... 137:
          dll_init_mclk_freq = 2;
          break;

        case 138 ... 150:
          dll_init_mclk_freq = 3;
          break;

        case 151 ... 162:
          dll_init_mclk_freq = 4;
          break;

        case 163 ... 175:
          dll_init_mclk_freq = 5;
          break;

        case 176 ... 187:
          dll_init_mclk_freq = 6;
          break;

        case 188 ... 200:
          dll_init_mclk_freq = 7;
          break;

        default:
          dll_init_mclk_freq = 0;
          break;
    }

    return dll_init_mclk_freq;
}

/*==================================================================================================

FUNCTION: spinor_hal_hw_cfg_perf

DESCRIPTION:
   This function initializes the QSPI registers and puts the QSPI into a known state.

==================================================================================================*/
SPINOR_STATUS spinor_hal_hw_cfg_perf(boolean clk_polarity, boolean clk_phase, boolean DLL_en, uint32_t bus_clk_freq, uint8_t DLL_enable_mode, uint8_t chip_select, boolean dqs_sync_qspi_clk, boolean use_pbl)
{
  uint32_t spi_mode            = 0U;
  uint32_t tx_data_oe_delay    = 0U;
  uint32_t pin_wpn             = 0U;
  uint32_t tx_data_delay       = 0U;
  uint32_t mstr_config         = 0U;
  uint32_t master_config       = 0U;
  uint32_t read_val,dll_config = 0U;
  uint32_t sbl_en              = 0U;
  uint32_t core_clk_freq       = 0U;
  //uint32_t nFreqHz           = 0U;
  SPINOR_STATUS status         = SPINOR_DEVICE_DONE;

#ifdef SPINOR_PRE_SIL
  if (get_platform_type() == OSPI_PLATFORM_RUMI)
  {
     sbl_en = 0;
     mstr_config = 0x5C;
  }
#endif

  sbl_en = (use_pbl == FALSE)?HWIO_QSPI_MSTR_CONFIG_SBL_EN_BMSK:0;
  core_clk_freq = bus_clk_freq;

  spi_mode = (clk_polarity == FALSE && clk_phase == FALSE) ? 0 :
             (clk_polarity == FALSE && clk_phase == TRUE) ? 1 :
             (clk_polarity == TRUE  && clk_phase == FALSE) ? 2 :
             (clk_polarity == TRUE  && clk_phase == TRUE) ? 3 : 0;

  // The TX DATA delay is needed for writes in DDR mode using the Micron
  // SPI NOR flash. Note that a half cycle of the reference clock is 1/8
  // cycle of the SPI clock when SBL_EN=1 and 1/4 cycle of the SPI clock
  // when SBL_EN=0.

  tx_data_oe_delay = 0; // delay half cycle of reference clock
  tx_data_delay = 1;    // delay half cycle of reference clock

  mstr_config = (tx_data_oe_delay << HWIO_QSPI_MSTR_CONFIG_TX_DATA_OE_DELAY_SHFT) |
          (tx_data_delay << HWIO_QSPI_MSTR_CONFIG_TX_DATA_DELAY_SHFT) |
                  (sbl_en) |
          (chip_select ? HWIO_QSPI_MSTR_CONFIG_CHIP_SELECT_NUM_BMSK : 0) |
          (spi_mode << HWIO_QSPI_MSTR_CONFIG_SPI_MODE_SHFT) |
                  (HWIO_QSPI_MSTR_CONFIG_PIN_HOLDN_BMSK) |
                  (HWIO_QSPI_MSTR_CONFIG_FB_CLK_EN_BMSK) |
          (pin_wpn << HWIO_QSPI_MSTR_CONFIG_PIN_WPN_SHFT) |
                  (HWIO_QSPI_MSTR_CONFIG_CS_ADVANCED_BMSK) |
                  (HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK);

  // Do not set the CONTINUOUS_MODE bit in RD_FIFO_CONFIG.  If CONTINUOUS_MODE is
  // used transfers will hang when we are slow to service the RD_FIFO.  When the
  // RD_FIFO is full the QSPI master continues clocking in data over the bus (and
  // decrementing REQUEST_COUNT in PIO_TRANSFER_CONTROL) but just drops the data
  // with no indication to SW.  This causes the transfer to end before SW has read
  // the expected number of bytes from the RD_FIFO.

  REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, mstr_config);
  REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
  if(read_val != mstr_config)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
      goto reg_init_end;
  }

  REG_OUT(HWIO_QSPI_AHB_MASTER_CFG_OFFS,  0xA42); // this is the reset state
  REG_IN(HWIO_QSPI_AHB_MASTER_CFG_OFFS, &read_val);
  if(read_val != 0xA42)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 2 failed \r\n", __func__);
      goto reg_init_end;
  }

  REG_OUT(HWIO_QSPI_MSTR_INT_ENABLE_OFFS, 0x00000000);
  REG_IN(HWIO_QSPI_MSTR_INT_ENABLE_OFFS, &read_val);
  if(read_val != 0x00000000)
  {
      //not written right
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: readback 3 failed \r\n", __func__);
      goto reg_init_end;
  }

  REG_OUT(HWIO_QSPI_MSTR_INT_STATUS_OFFS, 0xFFFFFFFF);   // clear latched status bits

  REG_OUT(HWIO_QSPI_RD_FIFO_CONFIG_OFFS,  0x00000000);
  REG_OUT(HWIO_QSPI_RD_FIFO_RESET_OFFS,   HWIO_QSPI_RD_FIFO_RESET_RESET_FIFO_BMSK);

  if (DLL_en)
  {
    /* If DLL mode is enabled, Core CLK will be 2 times bus frequency */
    core_clk_freq = 2U * bus_clk_freq;

    /* Set core clock frequency */
    if (TRUE != spinor_set_core_clk_freq(core_clk_freq))
    {
      DEBUG_LOG(SAIL_ERROR,"Failed to set frequency of %dMHz for core clock \r\n",core_clk_freq);
      status = SPINOR_DEVICE_FAIL;
      goto reg_init_end;
    }

    /* Clear DLL_CLOCK_DISABLE in HC_REG_DLL_CONFIG_2 register for DLL_LOCK after the core clock is supplied at the desired frequency */
    REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS,&dll_config);
    dll_config &= ~HWIO_HC_REG_DLL_CONFIG_2_DLL_CLOCK_DISABLE_BMSK;
    REG_OUT(HWIO_HC_REG_DLL_CONFIG_2_OFFS,dll_config);
    REG_IN(HWIO_HC_REG_DLL_CONFIG_2_OFFS, &read_val);
    if(read_val != dll_config)
    {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 4 failed \r\n", __func__);
       goto reg_init_end;
    }

    SPINOR_DSB;

    /* Before starting the DLL configuration, Clear the FB_CLK_EN and SBL_EN bits in QPSI_MSTR_CONFIG to 0 */
    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);
    mstr_config = mstr_config & ~HWIO_QSPI_MSTR_CONFIG_FB_CLK_EN_BMSK;
    mstr_config = mstr_config & ~HWIO_QSPI_MSTR_CONFIG_SBL_EN_BMSK;
    REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, mstr_config);
    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
    if(read_val != mstr_config)
    {
        //not written right
        status = SPINOR_DEVICE_FAIL;
        DEBUG_LOG(SAIL_ERROR,"%s: readback 5 failed \r\n", __func__);
        goto reg_init_end;
    }

    status = DLL_init(bus_clk_freq/1000000);

    if (OSPI_SDR_MODE == DLL_enable_mode)
    {
      status = DLL_SDR_config_init();
    }
    else if (OSPI_DDR_MODE == DLL_enable_mode)
    {
      /* Configuration for QSPI MSTR for DLL DDR mode based on DQS sync with QSPI CLK */
      if(TRUE == dqs_sync_qspi_clk)
      {
          status = spinor_hal_dqs_sync_en_cfg();
      }
      else
      {
          status = spinor_hal_dqs_sync_disable_cfg();
      }

      if(status != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"Failed to set DQS sync settings \r\n");
          status = SPINOR_DEVICE_FAIL;
          goto reg_init_end;
      }

      status = DLL_DDR_config_init();
    }
  }
  else
  {
      status = spinor_legacy_cfg_perf(bus_clk_freq, DLL_enable_mode);
  }

reg_init_end:
  return status;
}

/*==================================================================================================

FUNCTION: spinor_legacy_cfg_perf

DESCRIPTION:
   This function initializes the QSPI registers and puts the QSPI into a known state for the legacy mode.

==================================================================================================*/
SPINOR_STATUS spinor_legacy_cfg_perf(uint32_t bus_clk_freq, uint8_t DLL_enable_mode)
{
  uint32_t mstr_config         = 0U;
  uint32_t read_val = 0U;
  uint32_t sbl_en              = 0U;
  uint32_t core_clk_freq       = 0U;
  SPINOR_STATUS status         = SPINOR_DEVICE_DONE;

  REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
  sbl_en = (read_val & HWIO_QSPI_MSTR_CONFIG_SBL_EN_BMSK);

  /* If DLL mode is not enabled, Core CLK will be 2 times bus frequency if SBL mode is not set
         if SBL mode is set, Core CLK will be 4 times the bus frequency */
  if(sbl_en == 0)
  {
      //No SBL_en
      core_clk_freq = bus_clk_freq * 2;
  }
  else //sbl_en == 1
  {
      //SBL_en is TRUE
      core_clk_freq = bus_clk_freq * 4;
  }

  /* Set core clock frequency */
  if (TRUE != spinor_set_core_clk_freq(core_clk_freq))
  {
      DEBUG_LOG(SAIL_ERROR,"Failed to set frequency of %dMHz for core clock \r\n",core_clk_freq);
      status = SPINOR_DEVICE_FAIL;
      goto reg_init_end;
  }

  /* For Legacy mode without DLL, enable the Full cycle mode bit for SDR and disable for DDR mode */
  REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);

  if (OSPI_SDR_MODE == DLL_enable_mode)
  {
      mstr_config = mstr_config | HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK;
  }
  else
  {
      mstr_config = mstr_config & ~HWIO_QSPI_MSTR_CONFIG_FB_CLK_EN_BMSK;
      mstr_config &= ~(HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK);
  }

   REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, mstr_config);
   REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
   if(read_val != mstr_config)
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 10 failed \r\n", __func__);
       goto reg_init_end;
   }

reg_init_end:
  return status;
}

/*==================================================================================================

FUNCTION: spinor_hal_dqs_sync_en_cfg

DESCRIPTION:
   This function initializes the QSPI registers for the case where DQS sync is enabled.

==================================================================================================*/
SPINOR_STATUS spinor_hal_dqs_sync_en_cfg(void)
{
    uint32_t mstr_config         = 0U;
    uint32_t master_config       = 0U;
    uint32_t read_val = 0U;
    SPINOR_STATUS status         = SPINOR_DEVICE_DONE;

    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);
    REG_IN(HWIO_QSPI_MASTER_CONFIG_OFFS, &master_config);

    /* Clear the full cycle mode bit in QSPI MSTR CONFIG */
    mstr_config = mstr_config & ~HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK;
    REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS,mstr_config);
    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
    if(read_val != mstr_config)
    {
        //not written right
        status = SPINOR_DEVICE_FAIL;
        DEBUG_LOG(SAIL_ERROR,"%s: readback 6 failed \r\n", __func__);
        goto reg_init_end;
    }

    /* Disable the delay line */
    master_config = master_config & ~HWIO_QSPI_MASTER_CONFIG_DELAY_LINE_EN_BMSK;
    REG_OUT(HWIO_QSPI_MASTER_CONFIG_OFFS, master_config);
    REG_IN(HWIO_QSPI_MASTER_CONFIG_OFFS, &read_val);
    if(read_val != master_config)
    {
        //not written right
        status = SPINOR_DEVICE_FAIL;
        DEBUG_LOG(SAIL_ERROR,"%s: readback 7 failed \r\n", __func__);
        goto reg_init_end;
    }

reg_init_end:
  return status;
}

/*==================================================================================================

FUNCTION: spinor_hal_dqs_sync_disable_cfg

DESCRIPTION:
   This function initializes the QSPI registers for the case where DQS sync is disabled.

==================================================================================================*/
SPINOR_STATUS spinor_hal_dqs_sync_disable_cfg(void)
{
    uint32_t mstr_config         = 0U;
    uint32_t master_config       = 0U;
    uint32_t read_val = 0U;
    SPINOR_STATUS status         = SPINOR_DEVICE_DONE;

    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);
    REG_IN(HWIO_QSPI_MASTER_CONFIG_OFFS, &master_config);

    /* Set the full cycle mode bit in QSPI MSTR CONFIG */
    mstr_config = mstr_config | HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK;
    REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, mstr_config);
    REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
    if(read_val != mstr_config)
    {
        //not written right
        status = SPINOR_DEVICE_FAIL;
        DEBUG_LOG(SAIL_ERROR,"%s: readback 8 failed \r\n", __func__);
        goto reg_init_end;
    }

    /* Configure the delay line */
    master_config = master_config & ~HWIO_QSPI_MASTER_CONFIG_DELAY_LINE_BMSK;
    master_config = master_config | (QSPI_MASTER_CONFIG_DELAY_LINE_VAL << HWIO_QSPI_MASTER_CONFIG_DELAY_LINE_SHFT);
    REG_OUT(HWIO_QSPI_MASTER_CONFIG_OFFS, master_config);
    REG_IN(HWIO_QSPI_MASTER_CONFIG_OFFS, &read_val);
    if(read_val != master_config)
    {
        //not written right
        status = SPINOR_DEVICE_FAIL;
        DEBUG_LOG(SAIL_ERROR,"%s: readback 9 failed \r\n", __func__);
        goto reg_init_end;
    }

reg_init_end:
  return status;
}

/*==================================================================================================

FUNCTION: octal_spi_load_CDR_cfg

DESCRIPTION:
   This function loads the CDR phase configuration from the input provided.

==================================================================================================*/
boolean spinor_hal_load_CDR_cfg(uint8 cdr_sel)
{
    uint32_t dll_config;
    uint32_t mstr_config;
    uint32_t read_val;

   /* b.Write the selected DLL clock output phase (0 – 15) to CDR_SELEXT bit field of HC_REG_DLL_CONFIG register in gray code */
   REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS,&dll_config);
   dll_config = (dll_config & ~(HWIO_HC_REG_DLL_CONFIG_CDR_SELEXT_BMSK)) | (cdr_sel << HWIO_HC_REG_DLL_CONFIG_CDR_SELEXT_SHFT);
   REG_OUT(HWIO_HC_REG_DLL_CONFIG_OFFS,dll_config);
   REG_IN(HWIO_HC_REG_DLL_CONFIG_OFFS, &read_val);
   if(read_val != dll_config)
   {
       //not written right
       DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
       return FALSE;
   }
   SPINOR_DSB;

   /* Configuration for QSPI MSTR for DLL SDR mode */

   /* In DLL SDR mode, with CDR config value between 0-9, data will be sampled properly without full cycle mode enabled
      but for CDR value(HC_REG_DLL_CONFIG__CDR_SELEXT) higher than 9, full cycle mode needs to be enabled for proper sampling of incoming data.*/
   REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);
   if (cdr_sel > 9)
   {
       mstr_config |= (HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK);
   }
   else
   {

       mstr_config &= ~(HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK);
   }
   REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, mstr_config);
   REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
   if(read_val != mstr_config)
   {
       //not written right
       DEBUG_LOG(SAIL_ERROR,"%s: readback 2 failed \r\n", __func__);
       return FALSE;
   }

   return TRUE;

}

/*==================================================================================================

FUNCTION: spinor_hal_configure_dma_mode

DESCRIPTION:
   This function enables/disables DMA mode via the MSTR_CONFIG register.

==================================================================================================*/
static boolean dma_enabled = FALSE;
SPINOR_STATUS spinor_hal_configure_dma_mode(bool enable_dma)
{
   uint32_t mstr_config, read_val, dma_status_now, temp1;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &dma_status_now);
   temp1 = dma_status_now & HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK;
   if(temp1 == HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK)
       dma_enabled = TRUE;
   else
       dma_enabled = FALSE;

   if (enable_dma && !dma_enabled)
   {
      REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);
      mstr_config |= HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK;
      REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, mstr_config);
      dma_enabled = true;

      REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
      if(!(HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK & read_val))
      {
          //not written right
          status = SPINOR_DEVICE_FAIL;
          DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
          goto configure_dma_mode_end;
      }
   }
   else if (!enable_dma && dma_enabled)
   {
      REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);
      mstr_config &= ~HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK;
      REG_OUT(HWIO_QSPI_MSTR_CONFIG_OFFS, mstr_config);
      dma_enabled = false;

      REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &read_val);
      if(HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK & read_val)
      {
          //not written right
          status = SPINOR_DEVICE_FAIL;
          DEBUG_LOG(SAIL_ERROR,"%s: readback 2 failed \r\n", __func__);
          goto configure_dma_mode_end;
      }
   }

configure_dma_mode_end:
   return status;
}


/*==================================================================================================

FUNCTION: spinor_hal_dma_transfer_chain

DESCRIPTION:
   This function transfers a chain of descriptors over the bus using DMA mode.

==================================================================================================*/
void spinor_hal_dma_transfer_chain(uint32_t chain)
{
   uint32_t mstr_int_status;

   SPINOR_DSB;

   REG_OUT(HWIO_QSPI_MSTR_INT_STATUS_OFFS, 0xFFFFFFFF);  // clear latched status bits

   REG_OUT(HWIO_QSPI_NEXT_DMA_DESC_ADDR_OFFS, (uint32_t)chain);
}

/**********************************************************
 * This function checks if the DMA transfer is complete.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_hal_is_dma_transfer_done(void)
{
    uint32_t mstr_int_status;

    REG_IN(HWIO_QSPI_MSTR_INT_STATUS_OFFS, &mstr_int_status);
    if (mstr_int_status & HWIO_QSPI_MSTR_INT_STATUS_DMA_CHAIN_DONE_BMSK)
    {
        return TRUE;
    }
    return FALSE;
}

/*==================================================================================================

FUNCTION: spinor_hal_pio_read

DESCRIPTION:
   This function performs a PIO read transfer using a single transaction.

==================================================================================================*/
SPINOR_STATUS spinor_hal_pio_read(uint8_t *buffer, uint32_t num_bytes, uint32_t pio_transfer_config)
{
   uint8_t *ptr = buffer;
   uint32_t bytes_left = num_bytes;
   uint32_t bytes_read, read_val;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   REG_OUT(HWIO_QSPI_PIO_TRANSFER_CONFIG_OFFS, pio_transfer_config);
   REG_IN(HWIO_QSPI_PIO_TRANSFER_CONFIG_OFFS, &read_val);
   if(read_val != pio_transfer_config)
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
       goto pio_read_end;
   }

   REG_OUT(HWIO_QSPI_PIO_TRANSFER_CONTROL_OFFS, num_bytes);

   while (bytes_left)  // poll until all data has been read from the RX FIFO
   {
      bytes_read = spinor_hal_service_rx_fifo(ptr, bytes_left);
      bytes_left -= bytes_read;
      ptr += bytes_read;
   }

pio_read_end:
    return status;
}

/*==================================================================================================

FUNCTION: spinor_hal_pio_write

DESCRIPTION:
   This function performs a PIO write transfer using a single transaction.

==================================================================================================*/
SPINOR_STATUS spinor_hal_pio_write(uint8_t *buffer, uint32_t num_bytes, uint32_t pio_transfer_config)
{
   uint8_t *ptr = buffer;
   uint32_t bytes_left = num_bytes;
   uint32_t bytes_written, read_val;
   uint32_t mstr_int_status;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   REG_OUT(HWIO_QSPI_MSTR_INT_STATUS_OFFS, 0xFFFFFFFF);  // clear latched status bits

   REG_OUT(HWIO_QSPI_PIO_TRANSFER_CONFIG_OFFS, pio_transfer_config);
   REG_IN(HWIO_QSPI_PIO_TRANSFER_CONFIG_OFFS, &read_val);
   if(read_val != pio_transfer_config)
   {
       //not written right
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: readback 1 failed \r\n", __func__);
       goto pio_write_end;
   }

   REG_OUT(HWIO_QSPI_PIO_TRANSFER_CONTROL_OFFS, num_bytes);

   while (bytes_left)  // poll until all data has been written to the TX FIFO
   {
      bytes_written = spinor_hal_service_tx_fifo(ptr, bytes_left);
      bytes_left -= bytes_written;
      ptr += bytes_written;
   }

   //5us delay for the write to flush for the descriptors.
   spinor_udelay(5);

pio_write_end:
    return status;
}

/**********************************************************
 * This function checks if the PIO transfer is complete.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_hal_is_pio_transer_done(void)
{
    uint32_t mstr_int_status;
    REG_IN(HWIO_QSPI_MSTR_INT_STATUS_OFFS, &mstr_int_status);
    if (mstr_int_status & HWIO_QSPI_MSTR_INT_STATUS_TRANSACTION_DONE_BMSK)
    {
        return TRUE;
    }
    return FALSE;
}
/*==================================================================================================

FUNCTION: spinor_hal_is_dma_idle

DESCRIPTION:
   Checks if the OSPI DMA is idle.

==================================================================================================*/
boolean spinor_hal_is_dma_idle(void)
{
   uint32_t mstr_config,test_bus_val=0;

   REG_IN(HWIO_QSPI_MSTR_CONFIG_OFFS, &mstr_config);
   if(mstr_config&HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK)
   {
      /* 1. Configure QSPI_TEST_BUS_SEL to 0x4. */
      REG_OUT(HWIO_QSPI_TEST_BUS_SEL_OFFS , 4); //prepare test bus
      /* 2.Read QSPI_TEST_BUS_REG bits [4:0] corresponding to DMA state machine (SW need to read QSPI_TEST_BUS_REG and mask it with 0x1F). */
      REG_IN(HWIO_QSPI_TEST_BUS_REG_OFFS,&test_bus_val);
      /* 3.When DMA is idle the value in those bits will be zero and then it is safe to reset the QSPI core */
      if (test_bus_val & 0x1F)
      {
         return FALSE;
      }
      else
      {
         return TRUE;
      }
   }
   return TRUE;
}


/**********************************************************
 * Resets the QSPI Controller
 *
 *
 **********************************************************/
void spinor_hal_controller_reset(void)
{
    uint32_t mstr_config, read_val;

    /* 1.Disable qspi_refclk by writing 1�b0 to register SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR[CLK_ENABLE] [Bit 0] */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR, CLK_ENABLE, 0);

    /* 2. Assert �qspi_hclk_ares and qspi_refclk_ares� reset by writing 1�b1 to register SAILSS_CLKCTL_SAILSS_CC_QSPI_BCR[BLK_ARES] [Bit 0] */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QSPI_BCR, BLK_ARES, 1);

    /* 3. Wait for some time(1msec) */
    spinor_udelay(1000);

    /* 4. De-assert �qspi_hclk_ares and qspi_refclk_ares� by writing 1�b0 to register SAILSS_CLKCTL_SAILSS_CC_QSPI_BCR[BLK_ARES] [Bit 0] */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QSPI_BCR, BLK_ARES, 0);

    /* 5. Enable qspi_refclk by writing 1�b1 to register SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR[CLK_ENABLE] [Bit 0] */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR, CLK_ENABLE, 1);

    /* 6. Reinitialize both QSPI and XIP configuration registers. This is because both XIP and QSPI AHB domain is reset through SAILSS_CLKCTL_SAILSS_CC_QSPI_BCR */

    return;
}

/*==================================================================================================

FUNCTION: spinor_hal_service_rx_fifo

DESCRIPTION:
   This function reads data from the RX FIFO.

==================================================================================================*/
uint32_t spinor_hal_service_rx_fifo(uint8_t *ptr, uint32_t num_bytes)
{
   uint32_t full_words = num_bytes >> 2;
   uint32_t partial_bytes = num_bytes & 0x03;
   uint32_t rd_fifo_status;
   uint8_t  bytes_in_fifo;
   uint8_t  words_in_fifo;
   uint32_t words_to_read;
   uint32_t bytes_to_read;
   uint32_t word_value;
   uint32_t i;

   REG_IN(HWIO_QSPI_RD_FIFO_STATUS_OFFS, &rd_fifo_status);
   bytes_in_fifo = (rd_fifo_status & HWIO_QSPI_RD_FIFO_STATUS_WR_CNTS_BMSK) >> HWIO_QSPI_RD_FIFO_STATUS_WR_CNTS_SHFT;
   words_in_fifo = bytes_in_fifo >> 2;

   words_to_read = (words_in_fifo < full_words) ? (words_in_fifo) : (full_words);
   bytes_to_read = (bytes_in_fifo < num_bytes)  ?             (0) : (partial_bytes);

   for (i = 0; i < words_to_read; i++)
   {
      REG_IN(HWIO_QSPI_RD_FIFOn_OFFS(0), &word_value);
      *(uint32_t *)ptr = word_value;  // ptr is word aligned
      ptr += 4;
   }

   if (bytes_to_read)
   {
      REG_IN(HWIO_QSPI_RD_FIFOn_OFFS(0), &word_value);
      for (i = 0; i < bytes_to_read; i++) { ptr[i] = (uint8_t)(word_value >> i * 8); }
   }

   return(words_to_read * 4 + bytes_to_read);
}

/*==================================================================================================

FUNCTION: spinor_hal_service_tx_fifo

DESCRIPTION:
   This function writes data to the TX FIFO.

==================================================================================================*/
uint32_t spinor_hal_service_tx_fifo(uint8_t *ptr, uint32_t num_bytes)
{
   uint32_t full_words = num_bytes >> 2;
   uint32_t partial_bytes = num_bytes & 0x03;
   uint32_t pio_transfer_status;
   uint32_t room_in_bytes;
   uint32_t room_in_words;
   uint32_t words_to_send;
   uint32_t bytes_to_send;
   uint32_t word_value;
   uint32_t i;

   REG_IN(HWIO_QSPI_PIO_TRANSFER_STATUS_OFFS, &pio_transfer_status);
   room_in_bytes = (pio_transfer_status & HWIO_QSPI_PIO_TRANSFER_STATUS_WR_FIFO_BYTES_BMSK) >> HWIO_QSPI_PIO_TRANSFER_STATUS_WR_FIFO_BYTES_SHFT;
   room_in_words = room_in_bytes >> 2;

   words_to_send = (full_words > room_in_words) ? (room_in_words) : (full_words);
   bytes_to_send = (num_bytes  > room_in_bytes) ?             (0) : (partial_bytes);

   for (i = 0; i < words_to_send; i++)
   {
      word_value = *(uint32_t *)ptr;  // ptr is word aligned
      REG_OUT(HWIO_QSPI_PIO_DATAOUT_4BYTE_OFFS, word_value);
      ptr += 4;
   }

   for (i = 0; i < bytes_to_send; i++)
   {
      REG_OUT(HWIO_QSPI_PIO_DATAOUT_1BYTE_OFFS, *ptr);
      ptr++;
   }

   return(words_to_send * 4 + bytes_to_send);
}


