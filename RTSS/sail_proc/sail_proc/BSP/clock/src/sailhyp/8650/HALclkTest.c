/*
==============================================================================

FILE:         HALclkTest.c

DESCRIPTION:
  Auto-generated file containing custom debug mux control functions.

==============================================================================

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/src/sailhyp/8650/HALclkTest.c#1 $

==============================================================================
            Copyright (c) 2022 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "HALclkInternal.h"
#include "HALclkHWIO.h"
#include "HALhwio.h"

/*=========================================================================
      Definitions
==========================================================================*/

#define HAL_CLK_FRQ_MEASURE_CNT_SHORT     0x0100
#define HAL_CLK_FRQ_MEASURE_CNT_LONG      0x8000
#define HAL_CLK_FRQ_MEASURE_CNT_LOW_FREQ  0xFFFFF


/*=========================================================================
      CAM_CC Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxCAMCC
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR, CLK_DIV, 3);
  HWIO_OUTF(SAIL_TO_MD_CAM_CC_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlCAMCC_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxCAMCC,
};


/*=========================================================================
      DISP_CC_0 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxDISPCC0
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_MDSS_0_DISP_CC_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_MDSS_0_DISP_CC_DEBUG_DIV_CDIVR, CLK_DIV, 3);
  HWIO_OUTF(SAIL_TO_MD_MDSS_0_DISP_CC_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlDISPCC0_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxDISPCC0,
};


/*=========================================================================
      DISP_CC_1 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxDISPCC1
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR, CLK_DIV, 3);
  HWIO_OUTF(SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlDISPCC1_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxDISPCC1,
};


/*=========================================================================
      GCC Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxGCC
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_GCC_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_GCC_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_GCC_DEBUG_CBCR, CLK_ENABLE, 1);
}

static uint32_t HAL_clk_RunFreqCounterGCC
(
  uint32_t nTermCount
)
{
  uint64_t nNumerator;
  uint32_t nDenominator;
  uint32_t nCount;

  /*
   * Enable the reference clock and disable the counter.
   */
  HWIO_OUTF(SAIL_TO_MD_GCC_FRQ_MEASURE_REF_CBCR, CLK_ENABLE, 1);
  HWIO_OUTF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_CTL, CNT_EN, 0);

  /*
   * Clear the previous count.
   */
  HWIO_OUTF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_CTL, CLR_CNT, 1);
  while (HWIO_INF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_STATUS, MEASURE_CNT) != 0);
  HWIO_OUTF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_CTL, CLR_CNT, 0);

  /*
   * Run the counter.
   */
  HWIO_OUTF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_CTL, XO_DIV4_TERM_CNT, nTermCount);
  HWIO_OUTF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_CTL, CNT_EN, 1);
  HAL_clk_BusyWait(5);
  while (HWIO_INF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_STATUS, XO_DIV4_CNT_DONE) == 0);
  HWIO_OUTF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_CTL, CNT_EN, 0);
  nCount = HWIO_INF(SAIL_TO_MD_GCC_CLOCK_FRQ_MEASURE_STATUS, MEASURE_CNT);

  /*
   * Calculate the frequency.  Function is provided by
   * Power Control 42.8.1.2 Measurement technique
   * f ring = f tcxo/4 * (Nring + 1.5) / (TCtcxo + 3.5)
   *
   * The formula below is the equivalent one converted
   * to integer arithmetic.
   *
   * We add half of the denominator value to the dividend
   * to guard against rounding errors inherent to
   * integer arithmetic.
   */
  nNumerator = 9600000 * (uint64_t)nCount + 14400000;
  nDenominator = nTermCount * 2 + 7;
  return (uint32_t)((nNumerator + (nDenominator / 2)) / nDenominator);
}

static void HAL_clk_CalcDebugMuxFreqGCC
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                  *pnFreqHz
)
{
  uint32_t nFreq;

  nFreq = HAL_clk_RunFreqCounterGCC(HAL_CLK_FRQ_MEASURE_CNT_LONG);
  if (nFreq < 9600000)
  {
    nFreq = HAL_clk_RunFreqCounterGCC(HAL_CLK_FRQ_MEASURE_CNT_LOW_FREQ);
  }

  *pnFreqHz = nFreq;
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlGCC_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxGCC,
  .CalcFreq   = HAL_clk_CalcDebugMuxFreqGCC,
};


/*=========================================================================
      GPU_CC Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxGPUCC
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlGPUCC_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxGPUCC,
};


/*=========================================================================
      SAILSS_CC Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxSAILSSCC
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlSAILSSCC_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxSAILSSCC,
};


/*=========================================================================
      TURING_CC_0 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGCC0
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_0_TURING_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_0_TURING_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_0_TURING_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGCC0_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGCC0,
};


/*=========================================================================
      TURING_CC_1 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGCC1
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_1_TURING_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_1_TURING_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_1_TURING_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGCC1_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGCC1,
};


/*=========================================================================
      TURING_GDSP_CC_0 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGGDSPCC0
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGGDSPCC0_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGGDSPCC0,
};


/*=========================================================================
      TURING_GDSP_Q6_CC_0 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGGDSPQ6CC0
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGGDSPQ6CC0_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGGDSPQ6CC0,
};


/*=========================================================================
      TURING_GDSP_CC_1 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGGDSPCC1
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_1_TURING_QDSP6SS_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_1_TURING_QDSP6SS_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_1_TURING_QDSP6SS_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGGDSPCC1_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGGDSPCC1,
};


/*=========================================================================
      TURING_GDSP_Q6_CC_1 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGGDSPQ6CC1
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_1_TURING_QDSP6SS_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_1_TURING_QDSP6SS_DEBUG_DIV_CDIVR, CLK_DIV, 1);
  HWIO_OUTF(SAIL_TO_MD_TURINGGDSP_1_TURING_QDSP6SS_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGGDSPQ6CC1_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGGDSPQ6CC1,
};


/*=========================================================================
      TURING_Q6_CC_0 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGQ6CC0
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_DEBUG_DIV_CDIVR, CLK_DIV, 2);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGQ6CC0_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGQ6CC0,
};


/*=========================================================================
      TURING_Q6_CC_1 Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxTURINGQ6CC1
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_DEBUG_DIV_CDIVR, CLK_DIV, 2);
  HWIO_OUTF(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlTURINGQ6CC1_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxTURINGQ6CC1,
};


/*=========================================================================
      VIDEO_CC Debug Mux Control Functions
==========================================================================*/

static void HAL_clk_ConfigDebugMuxVIDEOCC
(
  HAL_clk_DebugMuxDescType  *pmDebugMux,
  uint32_t                   nMuxSel
)
{
  HWIO_OUTF(SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR, MUX_SEL, nMuxSel);
  HWIO_OUTF(SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR, CLK_DIV, 2);
  HWIO_OUTF(SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR, CLK_ENABLE, 1);
}

HAL_clk_DebugMuxControlType HAL_clk_DebugMuxControlVIDEOCC_lemansau =
{
  .ConfigMux  = HAL_clk_ConfigDebugMuxVIDEOCC,
};

