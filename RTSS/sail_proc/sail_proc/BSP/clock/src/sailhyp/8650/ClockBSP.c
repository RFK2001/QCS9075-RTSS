/*
==============================================================================

FILE:         ClockBSP.c

DESCRIPTION:
  This file contains the clock driver BSP data.

  Auto-generated from the following IPCat controller releases:

    SA8775Pv1 (lemansau_1.0):
      PLL_HSR   : 4.0
      CAM_CC          : lemansau_cam_cc_z_cam_cc_LeMans_1.0_p3q2r55_fp6 [lemansau_cam_cc.r2]
      DISP_CC_0       : lemansau_disp_cc_z_disp_cc_LeMans_1.0_p3q2r36.5632_fp6 [lemansau_disp_cc_0.r6]
      DISP_CC_1       : lemansau_disp_cc_z_disp_cc_LeMans_1.0_p3q2r36.5632_fp6 [lemansau_disp_cc_0.r6]
      GCC             : lemansau_gcc_z_lemansau_clk_ctl_p3q2r66_fp21 [lemansau_gcc.r21]
      GPU_CC          : lemansau_gpu_cc_z_gpu_cc_LeMans_1.0_p3q2r38_fp10 [lemansau_gpu_cc.r6]
      SAILSS_CC       : lemansau_sailss_cc_z_sailss_cc_1.0_p3q3r101_fp25 [lemansau_sailss_cc.r8]
      TURING_CC_0     : lemansau_turing_cc_z_turing_10.0.0_010522_p3q3r8.3_fp12 [lemansau_turing_cc.r5]
      TURING_CC_1     : lemansau_turing_cc_z_turing_10.0.0_010522_p3q3r8.3_fp12 [lemansau_turing_cc.r5]
      TURING_GDSP_CC_0: lemansau_turing_gdsp_cc_turing_gdsp_11.0.0_100821_p3q3r9.6_fp8 [lemansau_turing_gdsp_cc.r4]
      TURING_GDSP_CC_1: lemansau_turing_gdsp_cc_turing_gdsp_11.0.0_100821_p3q3r9.6_fp8 [lemansau_turing_gdsp_cc.r4]
      TURING_Q6_CC_0  : lemansau_turing_q6_cc_qdsp6_nsp_lemansau_p3q3r1.4_fp8 [lemansau_turing_q6_cc.r6]
      TURING_Q6_CC_1  : lemansau_turing_q6_cc_qdsp6_nsp_lemansau_p3q3r1.4_fp8 [lemansau_turing_q6_cc.r6]
      VIDEO_CC        : lemansau_video_cc_z_video_cc_LeMans_1.0_p3q2r19_fp3 [lemansau_video_cc.r1]


  Generated using the following clockdrivergen settings:

CLOCKDRIVERGEN_CONFIG = \
{'filter_warning': 'sw',
 'generators': [{'options': {'env': ['SMSS'],
                             'explicit_ownership': True,
                             'include_all_freqs': ['sailss_cc_.*'],
                             'include_only_fmax': {'.*': ['nominal']}},
                 'output_dir': '../src/sailhyp',
                 'type': 'dalclock'}],
 'memmap_name': 'SAILSS_ADDRESS_FILE_SW',
 'target': ['lemans']}

==============================================================================

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/src/sailhyp/8650/ClockBSP.c#1 $

==============================================================================
            Copyright (c) 2023, 2025 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "ClockBSP.h"
#include "HALclkHWIO.h"
#include "HALhwio.h"


/*=========================================================================
      Externs
==========================================================================*/

extern HAL_clk_ClockControlType           HAL_clk_GenericClockControl;
extern HAL_clk_ClockDomainControlType     HAL_clk_GenericDomainControl;
extern HAL_clk_ClockDomainControlType     HAL_clk_GenericDomainMuxControl;
extern HAL_clk_PowerDomainControlType     HAL_clk_GenericPowerDomainControl;
extern HAL_clk_SourceControlType          HAL_clk_LucidevoPLLControl;
extern HAL_clk_SourceControlType          HAL_clk_PongoevoPLLControl;
extern HAL_clk_SourceControlType          HAL_clk_RivianevoPLLControl;
extern HAL_clk_SourceControlType          HAL_clk_ZondaevoPLLControl;

/*
 * Debug mux control structures.
 */
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlCAMCC_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlDISPCC0_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlDISPCC1_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlGCC_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlGPUCC_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlSAILSSCC_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGCC0_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGCC1_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGGDSPCC0_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGGDSPCC1_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGGDSPQ6CC0_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGGDSPQ6CC1_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGQ6CC0_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlTURINGQ6CC1_lemansau;
extern HAL_clk_DebugMuxControlType        HAL_clk_DebugMuxControlVIDEOCC_lemansau;


/*=========================================================================
      Data Declarations
==========================================================================*/


/*=========================================================================
      Voltage Rails
==========================================================================*/

enum
{
  RAIL_IDX_VDD_CX,
  RAIL_IDX_VDD_GX,
  RAIL_IDX_VDD_MM,
  RAIL_IDX_VDD_MX,
  RAIL_IDX_VDD_MXA,
  RAIL_IDX_VDD_MXC,
  RAIL_IDX_VDD_NSP_CX,
  RAIL_IDX_VDD_SAIL_CX,
  RAIL_IDX_VDD_SAIL_MX,
};

#define RAIL_VDD_CX          (1 << RAIL_IDX_VDD_CX)
#define RAIL_VDD_GX          (1 << RAIL_IDX_VDD_GX)
#define RAIL_VDD_MM          (1 << RAIL_IDX_VDD_MM)
#define RAIL_VDD_MX          (1 << RAIL_IDX_VDD_MX)
#define RAIL_VDD_MXA         (1 << RAIL_IDX_VDD_MXA)
#define RAIL_VDD_MXC         (1 << RAIL_IDX_VDD_MXC)
#define RAIL_VDD_NSP_CX      (1 << RAIL_IDX_VDD_NSP_CX)
#define RAIL_VDD_SAIL_CX     (1 << RAIL_IDX_VDD_SAIL_CX)
#define RAIL_VDD_SAIL_MX     (1 << RAIL_IDX_VDD_SAIL_MX)

static ClockRailType ClockRail_VDDCX =
{
  .szName = "/vcs/vdd_cx",
};

static ClockRailType ClockRail_VDDGX =
{
  .szName = "/vcs/vdd_gx",
};

static ClockRailType ClockRail_VDDMM =
{
  .szName = "/vcs/vdd_mm",
};

static ClockRailType ClockRail_VDDMX =
{
  .szName = "/vcs/vdd_mx",
};

static ClockRailType ClockRail_VDDMXA =
{
  .szName = "/vcs/vdd_mxa",
};

static ClockRailType ClockRail_VDDMXC =
{
  .szName = "/vcs/vdd_mxc",
};

static ClockRailType ClockRail_VDDNSPCX =
{
  .szName = "/vcs/vdd_nsp_cx",
};

static ClockRailType ClockRail_VDDSAILCX =
{
  .szName = "/vcs/vdd_sail_cx",
};

static ClockRailType ClockRail_VDDSAILMX =
{
  .szName = "/vcs/vdd_sail_mx",
};

static ClockRailType *aRails[] =
{
  [RAIL_IDX_VDD_CX]       = &ClockRail_VDDCX,
  [RAIL_IDX_VDD_GX]       = &ClockRail_VDDGX,
  [RAIL_IDX_VDD_MM]       = &ClockRail_VDDMM,
  [RAIL_IDX_VDD_MX]       = &ClockRail_VDDMX,
  [RAIL_IDX_VDD_MXA]      = &ClockRail_VDDMXA,
  [RAIL_IDX_VDD_MXC]      = &ClockRail_VDDMXC,
  [RAIL_IDX_VDD_NSP_CX]   = &ClockRail_VDDNSPCX,
  [RAIL_IDX_VDD_SAIL_CX]  = &ClockRail_VDDSAILCX,
  [RAIL_IDX_VDD_SAIL_MX]  = &ClockRail_VDDSAILMX,
};

/*=========================================================================
      Debug Muxes
==========================================================================*/

static ClockDebugMuxType ClockDebugMux_GCC =
{
  .szName       = "gcc",
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlGCC_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_CAMCC =
{
  .szName       = "cam_cc",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 140,
  .nDivider     = 4,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlCAMCC_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_DISPCC0 =
{
  .szName       = "disp_cc_0",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 146,
  .nDivider     = 4,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlDISPCC0_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_DISPCC1 =
{
  .szName       = "disp_cc_1",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 152,
  .nDivider     = 4,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlDISPCC1_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_GPUCC =
{
  .szName       = "gpu_cc",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 502,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlGPUCC_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_SAILSSCC =
{
  .szName       = "sailss_cc",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 287,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlSAILSSCC_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGCC0 =
{
  .szName       = "turing_cc_0",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 345,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGCC0_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGCC1 =
{
  .szName       = "turing_cc_1",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 353,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGCC1_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGGDSPCC0 =
{
  .szName       = "turing_gdsp_cc_0",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 153,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGGDSPCC0_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGGDSPCC1 =
{
  .szName       = "turing_gdsp_cc_1",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 154,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGGDSPCC1_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_VIDEOCC =
{
  .szName       = "video_cc",
  .pParent      = &ClockDebugMux_GCC,
  .nParentSel   = 162,
  .nDivider     = 3,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlVIDEOCC_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGGDSPQ6CC0 =
{
  .szName       = "turing_gdsp_q6_cc_0",
  .pParent      = &ClockDebugMux_TURINGGDSPCC0,
  .nParentSel   = 13,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGGDSPQ6CC0_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGGDSPQ6CC1 =
{
  .szName       = "turing_gdsp_q6_cc_1",
  .pParent      = &ClockDebugMux_TURINGGDSPCC1,
  .nParentSel   = 13,
  .nDivider     = 2,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGGDSPQ6CC1_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGQ6CC0 =
{
  .szName       = "turing_q6_cc_0",
  .pParent      = &ClockDebugMux_TURINGCC0,
  .nParentSel   = 12,
  .nDivider     = 3,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGQ6CC0_lemansau,
  },
};

static ClockDebugMuxType ClockDebugMux_TURINGQ6CC1 =
{
  .szName       = "turing_q6_cc_1",
  .pParent      = &ClockDebugMux_TURINGCC1,
  .nParentSel   = 12,
  .nDivider     = 3,
  .HALDebugMux  = {
    .pmControl  = &HAL_clk_DebugMuxControlTURINGQ6CC1_lemansau,
  },
};

static ClockDebugMuxType *aDebugMuxes[] =
{
  &ClockDebugMux_CAMCC,
  &ClockDebugMux_DISPCC0,
  &ClockDebugMux_DISPCC1,
  &ClockDebugMux_GCC,
  &ClockDebugMux_GPUCC,
  &ClockDebugMux_SAILSSCC,
  &ClockDebugMux_TURINGCC0,
  &ClockDebugMux_TURINGCC1,
  &ClockDebugMux_TURINGGDSPCC0,
  &ClockDebugMux_TURINGGDSPCC1,
  &ClockDebugMux_TURINGGDSPQ6CC0,
  &ClockDebugMux_TURINGGDSPQ6CC1,
  &ClockDebugMux_TURINGQ6CC0,
  &ClockDebugMux_TURINGQ6CC1,
  &ClockDebugMux_VIDEOCC,
};


/*=========================================================================
      Primary Sources
==========================================================================*/

static ClockSourceNodeType ClockSource_XO =
{
  .szName    = "/pmic/client/xo",
  .nFlags    = 0x0,
};


/*=========================================================================
      Source Register Settings
==========================================================================*/

static const ClockSourceRegSettingsType ClockSourceRegSettings_CAMCC_CAMCCPLL0[] =
{
  {
    .HALSettings = {
      .nConfigCtl   = 0x20485699,
      .nConfigCtl1  = 0x00182261,
      .nConfigCtl2  = 0x32AA299C,
      .nTestCtl     = 0x00000000,
      .nTestCtl1    = 0x00000000,
      .nTestCtl2    = 0x00000000,
      .nUserCtl     = 0x00000000,
      .nUserCtl1    = 0x00400805,
    },
  },
};

static const ClockSourceRegSettingsType ClockSourceRegSettings_CAMCC_CAMCCPLL2[] =
{
  {
    .HALSettings = {
      .nConfigCtl   = 0x90008820,
      .nConfigCtl1  = 0x00890263,
      .nConfigCtl2  = 0x00000247,
      .nTestCtl     = 0x00000000,
      .nTestCtl1    = 0x00000000,
      .nUserCtl     = 0x00000000,
      .nUserCtl1    = 0x00400000,
    },
  },
};

static const ClockSourceRegSettingsType ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL1[] =
{
  {
    .HALSettings = {
      .nConfigCtl   = 0x08200800,
      .nConfigCtl1  = 0x05028001,
      .nConfigCtl2  = 0x00000000,
      .nTestCtl     = 0x00000000,
      .nTestCtl1    = 0x00000000,
      .nTestCtl2    = 0x00000000,
      .nUserCtl     = 0x00000000,
      .nUserCtl1    = 0x00000000,
    },
  },
};

static const ClockSourceRegSettingsType ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL5[] =
{
  {
    .HALSettings = {
      .nConfigCtl   = 0x60004F61,
      .nConfigCtl1  = 0x0001C808,
      .nConfigCtl2  = 0x00000000,
      .nConfigCtl3  = 0x040001AC,
      .nTestCtl     = 0x00000000,
      .nTestCtl1    = 0x0081C6DE,
      .nTestCtl2    = 0x40100000,
      .nTestCtl3    = 0x440001B2,
      .nTestCtl4    = 0x000003D8,
      .nUserCtl     = 0x00000000,
      .nUserCtl1    = 0x00250002,
    },
  },
};


/*=========================================================================
      Source BSP
==========================================================================*/

/*
 * ClockSourceBSP_CAMCC_CAMCCPLL0
 *
 * Used by:
 *   ClockSource_CAMCC_CAMCCPLL0
 */
static const ClockSourceFreqConfigType ClockSourceBSP_CAMCC_CAMCCPLL0[] =
{
  { 1200000000, &ClockSource_XO, { 0, 0, 1, 62,  0x00008000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucidevo.nEven = 2, .Lucidevo.nOdd = 3} }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
};
static const ClockSourceFreqConfigType ClockSourceBSPCal_CAMCC_CAMCCPLL0[] =
{
  { 1305600000, &ClockSource_XO, { 0, 0, 1, 68,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
};

/*
 * ClockSourceBSP_CAMCC_CAMCCPLL2
 *
 * Used by:
 *   ClockSource_CAMCC_CAMCCPLL2
 */
static const ClockSourceFreqConfigType ClockSourceBSP_CAMCC_CAMCCPLL2[] =
{
  {  960000000, &ClockSource_XO, { 0, 0, 1, 50,  0x00000000, HAL_CLK_PLL_FRAC_MODE_UNKNOWN, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_CAMCC_CAMCCPLL3
 *
 * Used by:
 *   ClockSource_CAMCC_CAMCCPLL3
 *   ClockSource_CAMCC_CAMCCPLL4
 *   ClockSource_CAMCC_CAMCCPLL5
 */
static const ClockSourceFreqConfigType ClockSourceBSP_CAMCC_CAMCCPLL3[] =
{
  {  960000000, &ClockSource_XO, { 0, 0, 1, 50,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucidevo.nEven = 2}        }, RAIL_VOLTAGE_LEVEL_SVS,       },
  { 1200000000, &ClockSource_XO, { 0, 0, 1, 62,  0x00008000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucidevo.nEven = 2}        }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
};

/*
 * ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0
 *
 * Used by:
 *   ClockSource_DISPCC0_MDSS0DISPCCPLL0
 *   ClockSource_DISPCC1_MDSS1DISPCCPLL0
 */
static const ClockSourceFreqConfigType ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0[] =
{
  { 1125000000, &ClockSource_XO, { 0, 0, 1, 58,  0x00009800, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1500000000, &ClockSource_XO, { 0, 0, 1, 78,  0x00002000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1725000000, &ClockSource_XO, { 0, 0, 1, 89,  0x0000D800, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
  { 1950000000, &ClockSource_XO, { 0, 0, 1, 101, 0x00009000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_TUR,       },
};
#if 0
/*
 * ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL1
 *
 * Used by:
 *   ClockSource_DISPCC0_MDSS0DISPCCPLL1
 *   ClockSource_DISPCC1_MDSS1DISPCCPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL1[] =
{
  {  600000000, &ClockSource_XO, { 0, 0, 1, 31,  0x00004000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_LOW_SVS,   },
};
#endif
/*
 * ClockSourceBSP_GCC_GCCGPLL0
 *
 * Used by:
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GCCGPLL0[] =
{
  {  600000000, &ClockSource_XO, { 0, 0, 1, 31,  0x00004000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucidevo.nEven = 2}        }, RAIL_VOLTAGE_LEVEL_LOW_SVS,   },
};

/*
 * ClockSourceBSP_GCC_GCCGPLL1
 *
 * Used by:
 *   ClockSource_GCC_GCCGPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GCCGPLL1[] =
{
  { 1066000000, &ClockSource_XO, { 0, 0, 1, 55,  0x00008555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GCCGPLL10
 *
 * Used by:
 *   ClockSource_GCC_GCCGPLL10
 *   ClockSource_GCC_GCCGPLL7
 *   ClockSource_GPUCC_GPUCCPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GCCGPLL10[] =
{
  { 1000000000, &ClockSource_XO, { 0, 0, 1, 52,  0x00001555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GCCGPLL4
 *
 * Used by:
 *   ClockSource_GCC_GCCGPLL4
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GCCGPLL4[] =
{
  {  806400000, &ClockSource_XO, { 0, 0, 1, 42,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GCCGPLL5
 *
 * Used by:
 *   ClockSource_GCC_GCCGPLL5
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GCCGPLL5[] =
{
  {  933000000, &ClockSource_XO, { 0, 0, 1, 48,  0x00009800, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GPUCC_GPUCCPLL0
 *
 * Used by:
 *   ClockSource_GPUCC_GPUCCPLL0
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GPUCC_GPUCCPLL0[] =
{
  {  810000000, &ClockSource_XO, { 0, 0, 1, 42,  0x00003000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
  { 1060000000, &ClockSource_XO, { 0, 0, 1, 55,  0x00003555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
  { 1352000000, &ClockSource_XO, { 0, 0, 1, 70,  0x00006AAA, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1556000000, &ClockSource_XO, { 0, 0, 1, 81,  0x00000AAA, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
  { 1680000000, &ClockSource_XO, { 0, 0, 1, 87,  0x00008000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
};

/*
 * ClockSourceBSP_SAILSSCC_SAILSSCCPLL0
 *
 * Used by:
 *   ClockSource_SAILSSCC_SAILSSCCPLL0
 */
static const ClockSourceFreqConfigType ClockSourceBSP_SAILSSCC_SAILSSCCPLL0[] =
{
  {  600000000, &ClockSource_XO, { 0, 0, 1, 31,  0x00004000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucidevo.nEven = 2}        }, RAIL_VOLTAGE_LEVEL_LOW_SVS,   },
};

/*
 * ClockSourceBSP_SAILSSCC_SAILSSCCPLL1
 *
 * Used by:
 *   ClockSource_SAILSSCC_SAILSSCCPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_SAILSSCC_SAILSSCCPLL1[] =
{
  { 1209600000, &ClockSource_XO, { 0, 0, 1, 63,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_LOW_SVS,   },
  { 1593600000, &ClockSource_XO, { 0, 0, 1, 83,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
  { 1843200000, &ClockSource_XO, { 0, 0, 1, 96,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};
static const ClockSourceFreqConfigType ClockSourceBSPCal_SAILSSCC_SAILSSCCPLL1[] =
{
  { 1516800000, &ClockSource_XO, { 0, 0, 1, 79,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_SAILSSCC_SAILSSCCPLL2
 *
 * Used by:
 *   ClockSource_SAILSSCC_SAILSSCCPLL2
 */
static const ClockSourceFreqConfigType ClockSourceBSP_SAILSSCC_SAILSSCCPLL2[] =
{
  {  664000000, &ClockSource_XO, { 0, 0, 1, 34,  0x00009555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_SAILSSCC_SAILSSCCPLL3
 *
 * Used by:
 *   ClockSource_SAILSSCC_SAILSSCCPLL3
 */
static const ClockSourceFreqConfigType ClockSourceBSP_SAILSSCC_SAILSSCCPLL3[] =
{
  {  960000000, &ClockSource_XO, { 0, 0, 1, 50,  0x00000000, HAL_CLK_PLL_FRAC_MODE_UNKNOWN, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_SAILSSCC_SAILSSCCPLL4
 *
 * Used by:
 *   ClockSource_SAILSSCC_SAILSSCCPLL4
 */
static const ClockSourceFreqConfigType ClockSourceBSP_SAILSSCC_SAILSSCCPLL4[] =
{
  {  500000000, &ClockSource_XO, { 0, 0, 1, 26,  0x00000AAA, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_LOW_SVS_D1,},
};

/*
 * ClockSourceBSP_SAILSSCC_SAILSSCCPLL5
 *
 * Used by:
 *   ClockSource_SAILSSCC_SAILSSCCPLL5
 */
static const ClockSourceFreqConfigType ClockSourceBSP_SAILSSCC_SAILSSCCPLL5[] =
{
  {   38400000, &ClockSource_XO, { 0, 0, 1, 2,   0x00000000, HAL_CLK_PLL_FRAC_MODE_UNKNOWN, {.Pongoevo.nEven = 2}        }, RAIL_VOLTAGE_LEVEL_LOW_SVS_D1,},
};

/*
 * ClockSourceBSP_SAILSSCC_SAILSSCCPLL6
 *
 * Used by:
 *   ClockSource_SAILSSCC_SAILSSCCPLL6
 */
static const ClockSourceFreqConfigType ClockSourceBSP_SAILSSCC_SAILSSCCPLL6[] =
{
  {   38400000, &ClockSource_XO, { 0, 0, 1, 2,   0x00000000, HAL_CLK_PLL_FRAC_MODE_UNKNOWN, {.Pongoevo.nEven = 2}        }, RAIL_VOLTAGE_LEVEL_LOW_SVS_D1,},
};

/*
 * ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL
 *
 * Used by:
 *   ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL
 *   ClockSource_TURINGCC0_TURING0TURINGCCCORE2PLL
 *   ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL
 *   ClockSource_TURINGCC1_TURING1TURINGCCCORE2PLL
 */
static const ClockSourceFreqConfigType ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL[] =
{
  { 1050000000, &ClockSource_XO, { 0, 0, 1, 54,  0x0000B000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucidevo.nEven = 2}        }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE1PLL
 *
 * Used by:
 *   ClockSource_TURINGCC0_TURING0TURINGCCCORE1PLL
 *   ClockSource_TURINGCC1_TURING1TURINGCCCORE1PLL
 */
static const ClockSourceFreqConfigType ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE1PLL[] =
{
  {  944000000, &ClockSource_XO, { 0, 0, 1, 49,  0x00002AAA, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL
 *
 * Used by:
 *   ClockSource_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL
 *   ClockSource_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCPLL
 */
static const ClockSourceFreqConfigType ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL[] =
{
  { 1113600000, &ClockSource_XO, { 0, 0, 1, 58,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1344000000, &ClockSource_XO, { 0, 0, 1, 70,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1497600000, &ClockSource_XO, { 0, 0, 1, 78,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1708800000, &ClockSource_XO, { 0, 0, 1, 89,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
};

/*
 * ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL
 *
 * Used by:
 *   ClockSource_TURINGQ6CC0_TURING0TURINGQ6CCPLL
 *   ClockSource_TURINGQ6CC1_TURING1TURINGQ6CCPLL
 */
static const ClockSourceFreqConfigType ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL[] =
{
  {  556800000, &ClockSource_XO, { 0, 0, 1, 29,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_LOW_SVS,   },
  {  768000000, &ClockSource_XO, { 0, 0, 1, 40,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
  {  960000000, &ClockSource_XO, { 0, 0, 1, 50,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
  { 1171200000, &ClockSource_XO, { 0, 0, 1, 61,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1401600000, &ClockSource_XO, { 0, 0, 1, 73,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1497600000, &ClockSource_XO, { 0, 0, 1, 78,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
};

/*
 * ClockSourceBSP_VIDEOCC_VIDEOPLL0
 *
 * Used by:
 *   ClockSource_VIDEOCC_VIDEOPLL0
 */
static const ClockSourceFreqConfigType ClockSourceBSP_VIDEOCC_VIDEOPLL0[] =
{
  { 1098000000, &ClockSource_XO, { 0, 0, 1, 57,  0x00003000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1332000000, &ClockSource_XO, { 0, 0, 1, 69,  0x00006000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1599000000, &ClockSource_XO, { 0, 0, 1, 83,  0x00004800, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
  { 1680000000, &ClockSource_XO, { 0, 0, 1, 87,  0x00008000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
};

/*
 * ClockSourceBSP_VIDEOCC_VIDEOPLL1
 *
 * Used by:
 *   ClockSource_VIDEOCC_VIDEOPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_VIDEOCC_VIDEOPLL1[] =
{
  { 1098000000, &ClockSource_XO, { 0, 0, 1, 57,  0x00003000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1332000000, &ClockSource_XO, { 0, 0, 1, 69,  0x00006000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
  { 1600000000, &ClockSource_XO, { 0, 0, 1, 83,  0x00005555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
  { 1800000000, &ClockSource_XO, { 0, 0, 1, 93,  0x0000C000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_NOM,       },
};


/*=========================================================================
      Sources
==========================================================================*/

static ClockSourceNodeType ClockSource_CAMCC_CAMCCPLL0 =
{
  .szName       = "cam_cc_pll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_CAMCC_CAMCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_CAMCC_CAMCCPLL0),
  .nRailMask    = RAIL_VDD_MXC,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE |
                  CLOCK_CONFIG_PLL_ODD_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_CAM_CC_PLL0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};
#if 0
static ClockSourceNodeType ClockSource_CAMCC_CAMCCPLL2 =
{
  .szName       = "cam_cc_pll2",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_CAMCC_CAMCCPLL2,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_CAMCC_CAMCCPLL2),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_CAM_CC_PLL2_PLL_MODE),
    .pmControl      = &HAL_clk_RivianevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSP_CAMCC_CAMCCPLL2,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSP_CAMCC_CAMCCPLL2),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL2,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL2),
};
#endif
static ClockSourceNodeType ClockSource_CAMCC_CAMCCPLL3 =
{
  .szName       = "cam_cc_pll3",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_CAMCC_CAMCCPLL3,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_CAMCC_CAMCCPLL3),
  .nRailMask    = RAIL_VDD_MXC,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_CAM_CC_PLL3_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_CAMCC_CAMCCPLL4 =
{
  .szName       = "cam_cc_pll4",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_CAMCC_CAMCCPLL3,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_CAMCC_CAMCCPLL3),
  .nRailMask    = RAIL_VDD_MXC,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_CAM_CC_PLL4_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_CAMCC_CAMCCPLL5 =
{
  .szName       = "cam_cc_pll5",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_CAMCC_CAMCCPLL3,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_CAMCC_CAMCCPLL3),
  .nRailMask    = RAIL_VDD_MXC,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_CAM_CC_PLL5_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_DISPCC0_MDSS0DISPCCPLL0 =
{
  .szName       = "mdss_0_disp_cc_pll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0),
  .nRailMask    = RAIL_VDD_MM,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_PLL0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};
#if 0
static ClockSourceNodeType ClockSource_DISPCC0_MDSS0DISPCCPLL1 =
{
  .szName       = "mdss_0_disp_cc_pll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL1),
  .nRailMask    = RAIL_VDD_MM,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_PLL1_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};
#endif
static ClockSourceNodeType ClockSource_DISPCC1_MDSS1DISPCCPLL0 =
{
  .szName       = "mdss_1_disp_cc_pll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0),
  .nRailMask    = RAIL_VDD_MM,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_PLL0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};
#if 0
static ClockSourceNodeType ClockSource_DISPCC1_MDSS1DISPCCPLL1 =
{
  .szName       = "mdss_1_disp_cc_pll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL1),
  .nRailMask    = RAIL_VDD_MM,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_PLL1_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};
#endif
static ClockSourceNodeType ClockSource_GCC_GCCGPLL0 =
{
  .szName       = "gcc_gpll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL |
                  CLOCK_FLAG_READ_ONLY,
  .aBSP         = ClockSourceBSP_GCC_GCCGPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GCCGPLL0),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE |
                  CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GCC_GPLL0_PLL_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x1},
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_GCC_GCCGPLL1 =
{
  .szName       = "gcc_gpll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GCCGPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GCCGPLL1),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GCC_GPLL1_PLL_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x2},
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_GCC_GCCGPLL10 =
{
  .szName       = "gcc_gpll10",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GCCGPLL10,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GCCGPLL10),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GCC_GPLL10_PLL_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x400},
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_GCC_GCCGPLL4 =
{
  .szName       = "gcc_gpll4",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GCCGPLL4,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GCCGPLL4),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GCC_GPLL4_PLL_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x10},
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_GCC_GCCGPLL5 =
{
  .szName       = "gcc_gpll5",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GCCGPLL5,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GCCGPLL5),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GCC_GPLL5_PLL_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x20},
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_GCC_GCCGPLL7 =
{
  .szName       = "gcc_gpll7",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GCCGPLL10,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GCCGPLL10),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GCC_GPLL7_PLL_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x80},
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_GPUCC_GPUCCPLL0 =
{
  .szName       = "gpu_cc_pll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GPUCC_GPUCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GPUCC_GPUCCPLL0),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_PLL0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_GPUCC_GPUCCPLL1 =
{
  .szName       = "gpu_cc_pll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GCCGPLL10,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GCCGPLL10),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_PLL1_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_SAILSSCC_SAILSSCCPLL0 =
{
  .szName       = "sailss_cc_pll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_SAILSSCC_SAILSSCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL0),
  .nRailMask    = RAIL_VDD_SAIL_CX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_SAILSSCC_SAILSSCCPLL1 =
{
  .szName       = "sailss_cc_pll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_SAILSSCC_SAILSSCCPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL1),
  .nRailMask    = RAIL_VDD_SAIL_CX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL1_PLL_MODE),
    .pmControl      = &HAL_clk_ZondaevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_SAILSSCC_SAILSSCCPLL1,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_SAILSSCC_SAILSSCCPLL1),
  .pRegSettings               = ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL1,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL1),
};

static ClockSourceNodeType ClockSource_SAILSSCC_SAILSSCCPLL2 =
{
  .szName       = "sailss_cc_pll2",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_SAILSSCC_SAILSSCCPLL2,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL2),
  .nRailMask    = RAIL_VDD_SAIL_CX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL2_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_SAILSSCC_SAILSSCCPLL3 =
{
  .szName       = "sailss_cc_pll3",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_SAILSSCC_SAILSSCCPLL3,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL3),
  .nRailMask    = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL3_PLL_MODE),
    .pmControl      = &HAL_clk_RivianevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSP_CAMCC_CAMCCPLL2,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSP_CAMCC_CAMCCPLL2),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL2,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL2),
};

static ClockSourceNodeType ClockSource_SAILSSCC_SAILSSCCPLL4 =
{
  .szName       = "sailss_cc_pll4",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_SAILSSCC_SAILSSCCPLL4,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL4),
  .nRailMask    = RAIL_VDD_SAIL_CX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL4_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_SAILSSCC_SAILSSCCPLL5 =
{
  .szName       = "sailss_cc_pll5",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_SAILSSCC_SAILSSCCPLL5,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL5),
  .nRailMask    = RAIL_VDD_SAIL_MX,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL5_PLL_MODE),
    .pmControl      = &HAL_clk_PongoevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSP_SAILSSCC_SAILSSCCPLL5,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL5),
  .pRegSettings               = ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL5,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL5),
};

static ClockSourceNodeType ClockSource_SAILSSCC_SAILSSCCPLL6 =
{
  .szName       = "sailss_cc_pll6",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_SAILSSCC_SAILSSCCPLL6,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL6),
  .nRailMask    = RAIL_VDD_SAIL_CX,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL6_PLL_MODE),
    .pmControl      = &HAL_clk_PongoevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSP_SAILSSCC_SAILSSCCPLL6,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSP_SAILSSCC_SAILSSCCPLL6),
  .pRegSettings               = ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL5,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_SAILSSCC_SAILSSCCPLL5),
};

static ClockSourceNodeType ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL =
{
  .szName       = "turing_0_turing_cc_core0_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_CORE0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGCC0_TURING0TURINGCCCORE1PLL =
{
  .szName       = "turing_0_turing_cc_core1_pll",
  .nFlags       = 0x0,
  .aBSP         = ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE1PLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE1PLL),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_CORE1_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGCC0_TURING0TURINGCCCORE2PLL =
{
  .szName       = "turing_0_turing_cc_core2_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_CORE2_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL =
{
  .szName       = "turing_1_turing_cc_core0_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_CORE0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGCC1_TURING1TURINGCCCORE1PLL =
{
  .szName       = "turing_1_turing_cc_core1_pll",
  .nFlags       = 0x0,
  .aBSP         = ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE1PLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE1PLL),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_CORE1_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGCC1_TURING1TURINGCCCORE2PLL =
{
  .szName       = "turing_1_turing_cc_core2_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGCC0_TURING0TURINGCCCORE0PLL),
  .nRailMask    = RAIL_VDD_MXA,
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_CORE2_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL =
{
  .szName       = "turing_ss_gdsp_0_qdsp6ss_core_cc_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_QDSP6SS_PLL_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCPLL =
{
  .szName       = "turing_ss_gdsp_1_qdsp6ss_core_cc_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL),
  .nRailMask    = RAIL_VDD_CX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_QDSP6SS_PLL_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGQ6CC0_TURING0TURINGQ6CCPLL =
{
  .szName       = "turing_0_turing_q6_cc_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL),
  .nRailMask    = RAIL_VDD_MX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_PLL_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_TURINGQ6CC1_TURING1TURINGQ6CCPLL =
{
  .szName       = "turing_1_turing_q6_cc_pll",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL),
  .nRailMask    = RAIL_VDD_MX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_PLL_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_VIDEOCC_VIDEOPLL0 =
{
  .szName       = "video_pll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_VIDEOCC_VIDEOPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_VIDEOCC_VIDEOPLL0),
  .nRailMask    = RAIL_VDD_MX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};

static ClockSourceNodeType ClockSource_VIDEOCC_VIDEOPLL1 =
{
  .szName       = "video_pll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_VIDEOCC_VIDEOPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_VIDEOCC_VIDEOPLL1),
  .nRailMask    = RAIL_VDD_MX,
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_MODE),
    .pmControl      = &HAL_clk_LucidevoPLLControl,
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_CAMCC_CAMCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_CAMCC_CAMCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_CAMCC_CAMCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_CAMCC_CAMCCPLL0),
};


static ClockSourceNodeType *aSources[] =
{
  &ClockSource_CAMCC_CAMCCPLL0,
#if 0
  &ClockSource_CAMCC_CAMCCPLL2,
#endif
  &ClockSource_CAMCC_CAMCCPLL3,
#if 0
  &ClockSource_CAMCC_CAMCCPLL4,
  &ClockSource_CAMCC_CAMCCPLL5,
#endif
  &ClockSource_DISPCC0_MDSS0DISPCCPLL0,
#if 0
  &ClockSource_DISPCC0_MDSS0DISPCCPLL1,
#endif
  &ClockSource_DISPCC1_MDSS1DISPCCPLL0,
#if 0
  &ClockSource_DISPCC1_MDSS1DISPCCPLL1,
#endif
  &ClockSource_GCC_GCCGPLL0,
  &ClockSource_GCC_GCCGPLL1,
  &ClockSource_GCC_GCCGPLL10,
  &ClockSource_GCC_GCCGPLL4,
  &ClockSource_GCC_GCCGPLL5,
  &ClockSource_GCC_GCCGPLL7,
  &ClockSource_GPUCC_GPUCCPLL0,
  &ClockSource_GPUCC_GPUCCPLL1,
  &ClockSource_SAILSSCC_SAILSSCCPLL0,
  &ClockSource_SAILSSCC_SAILSSCCPLL1,
  &ClockSource_SAILSSCC_SAILSSCCPLL2,
  &ClockSource_SAILSSCC_SAILSSCCPLL3,
  &ClockSource_SAILSSCC_SAILSSCCPLL4,
  &ClockSource_SAILSSCC_SAILSSCCPLL5,
  &ClockSource_SAILSSCC_SAILSSCCPLL6,
  &ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL,
#if 0
  &ClockSource_TURINGCC0_TURING0TURINGCCCORE1PLL,
#endif
  &ClockSource_TURINGCC0_TURING0TURINGCCCORE2PLL,
  &ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL,
#if 0
  &ClockSource_TURINGCC1_TURING1TURINGCCCORE1PLL,
#endif
  &ClockSource_TURINGCC1_TURING1TURINGCCCORE2PLL,
#if 0
  &ClockSource_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL,
  &ClockSource_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCPLL,
#endif
  &ClockSource_TURINGQ6CC0_TURING0TURINGQ6CCPLL,
  &ClockSource_TURINGQ6CC1_TURING1TURINGQ6CCPLL,
  &ClockSource_VIDEOCC_VIDEOPLL0,
  &ClockSource_VIDEOCC_VIDEOPLL1,
  &ClockSource_XO,
};


/*=========================================================================
      Domain BSP
==========================================================================*/

/*
 * ClockDomainBSP_CAMCC_CAMCCCAMNOCAXI
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCCAMNOCAXI
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCCAMNOCAXI[] =
{
  {  400000000, &ClockSource_CAMCC_CAMCCPLL0,             { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = CAM_CC_PLL0_OUT_MAIN */
};
#if 0
/*
 * ClockDomainBSP_CAMCC_CAMCCCCI0
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCCCI0
 *   ClockDomain_CAMCC_CAMCCCCI1
 *   ClockDomain_CAMCC_CAMCCCCI2
 *   ClockDomain_CAMCC_CAMCCCCI3
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCCCI0[] =
{
  {   37500000, &ClockSource_CAMCC_CAMCCPLL0,             { 1,     32,    1,     2,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = CAM_CC_PLL0_OUT_MAIN */
};
#endif
/*
 * ClockDomainBSP_CAMCC_CAMCCCPHYRX
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCCPHYRX
 *   ClockDomain_CAMCC_CAMCCCSI0PHYTIMER
 *   ClockDomain_CAMCC_CAMCCCSI1PHYTIMER
 *   ClockDomain_CAMCC_CAMCCCSI2PHYTIMER
 *   ClockDomain_CAMCC_CAMCCCSI3PHYTIMER
 *   ClockDomain_CAMCC_CAMCCCSID
 *   ClockDomain_CAMCC_CAMCCIFELITECSID
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCCPHYRX[] =
{
  {  400000000, &ClockSource_CAMCC_CAMCCPLL0,             { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[3] = CAM_CC_PLL0_OUT_ODD */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCFASTAHB
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCFASTAHB
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCFASTAHB[] =
{
  {  400000000, &ClockSource_CAMCC_CAMCCPLL0,             { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = CAM_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCICP
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCICP
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCICP[] =
{
  {  600000000, &ClockSource_CAMCC_CAMCCPLL0,             { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = CAM_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCIFE0
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCIFE0
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCIFE0[] =
{
  {  600000000, &ClockSource_CAMCC_CAMCCPLL4,             { 6,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_CAMCC_CAMCCPLL3[ 1] /* 600.0  */ },    /* Mux[6] = CAM_CC_PLL4_OUT_EVEN */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCIFE1
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCIFE1
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCIFE1[] =
{
  {  600000000, &ClockSource_CAMCC_CAMCCPLL5,             { 6,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_CAMCC_CAMCCPLL3[ 1] /* 600.0  */ },    /* Mux[6] = CAM_CC_PLL5_OUT_EVEN */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCIFELITE
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCIFELITE
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCIFELITE[] =
{
  {  480000000, &ClockSource_CAMCC_CAMCCPLL0,             { 1,     5,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = CAM_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCIPE
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCIPE
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCIPE[] =
{
  {  600000000, &ClockSource_CAMCC_CAMCCPLL3,             { 6,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_CAMCC_CAMCCPLL3[ 1] /* 600.0  */ },    /* Mux[6] = CAM_CC_PLL3_OUT_EVEN */
};
#if 0
/*
 * ClockDomainBSP_CAMCC_CAMCCMCLK0
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCMCLK0
 *   ClockDomain_CAMCC_CAMCCMCLK1
 *   ClockDomain_CAMCC_CAMCCMCLK2
 *   ClockDomain_CAMCC_CAMCCMCLK3
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCMCLK0[] =
{
  {   64000000, &ClockSource_CAMCC_CAMCCPLL2,             { 5,     30,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[5] = CAM_CC_PLL2_OUT_MAIN */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCQDSSDEBUG
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCQDSSDEBUG
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCQDSSDEBUG[] =
{
  {  300000000, &ClockSource_CAMCC_CAMCCPLL0,             { 2,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[2] = CAM_CC_PLL0_OUT_EVEN */
};
#endif
/*
 * ClockDomainBSP_CAMCC_CAMCCSLEEP
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCSLEEP
 *   ClockDomain_DISPCC0_MDSS0DISPCCSLEEP
 *   ClockDomain_DISPCC1_MDSS1DISPCCSLEEP
 *   ClockDomain_VIDEOCC_VIDEOCCSLEEP
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCSLEEP[] =
{
  {      32000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[0] = CHIP_SLEEP_CLK */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCSLOWAHB
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCSLOWAHB
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCSLOWAHB[] =
{
  {   80000000, &ClockSource_CAMCC_CAMCCPLL0,             { 2,     15,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[2] = CAM_CC_PLL0_OUT_EVEN */
};

/*
 * ClockDomainBSP_CAMCC_CAMCCXO
 *
 * Used by:
 *   ClockDomain_CAMCC_CAMCCXO
 *   ClockDomain_GCC_GCCEMAC0PHYAUX
 *   ClockDomain_GCC_GCCEMAC1PHYAUX
 *   ClockDomain_GCC_GCCPCIE0AUX
 *   ClockDomain_GCC_GCCPCIE1AUX
 *   ClockDomain_GPUCC_GPUCCRBCPR
 *   ClockDomain_GPUCC_GPUCCXO
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE0
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE1
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0AUX
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0CRYPTO
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0LINK
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL0
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL1
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL2
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL3
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1AUX
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1CRYPTO
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1LINK
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL0
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL1
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC0
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC1
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK0
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK1
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSVSYNC
 *   ClockDomain_DISPCC0_MDSS0DISPCCXO
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE0
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE1
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0AUX
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0CRYPTO
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0LINK
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL0
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL1
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL2
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL3
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1AUX
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1CRYPTO
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1LINK
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL0
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL1
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC0
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC1
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK0
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK1
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSVSYNC
 *   ClockDomain_DISPCC1_MDSS1DISPCCXO
 *   ClockDomain_VIDEOCC_VIDEOCCAHB
 *   ClockDomain_VIDEOCC_VIDEOCCXO
 */
static ClockMuxConfigType ClockDomainBSP_CAMCC_CAMCCXO[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[0] = BI_TCXO */
};
#if 0
/*
 * ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSAHB
 *
 * Used by:
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSAHB[] =
{
  {   75000000, &ClockSource_DISPCC0_MDSS0DISPCCPLL1,     { 4,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
};
#endif
/*
 * ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSMDP
 *
 * Used by:
 *   ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSMDP[] =
{
  {  500000000, &ClockSource_DISPCC0_MDSS0DISPCCPLL0,     { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0[ 1] /* 1500.0 */ },  /* Mux[1] = DISP_CC_PLL0_OUT_MAIN */
};
#if 0
/*
 * ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSAHB
 *
 * Used by:
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSAHB[] =
{
  {   75000000, &ClockSource_DISPCC1_MDSS1DISPCCPLL1,     { 4,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
};
#endif
/*
 * ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSMDP
 *
 * Used by:
 *   ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSMDP[] =
{
  {  500000000, &ClockSource_DISPCC1_MDSS1DISPCCPLL0,     { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_DISPCC0_MDSS0DISPCCPLL0[ 1] /* 1500.0 */ },  /* Mux[1] = DISP_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCAGGRENOC
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCAGGRENOC
 *   ClockDomain_GCC_GCCSYSNOC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCAGGRENOC[] =
{
  {  200000000, &ClockSource_GCC_GCCGPLL0,                { 1,     6,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP73_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCAGGRENOCPCIESF
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCAGGRENOCPCIESF
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCAGGRENOCPCIESF[] =
{
  {  466500000, &ClockSource_GCC_GCCGPLL5,                { 3,     4,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[3] = GCC_GPLL5_OUT_MAIN_PWRGRP9_CLKGEN_ACGC_CLK */
};
#if 0
/*
 * ClockDomainBSP_GCC_GCCCNOCPERIPH
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCCNOCPERIPH
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCNOCPERIPH[] =
{
  {  100000000, &ClockSource_GCC_GCCGPLL0,                { 1,     12,    0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};
#endif
/*
 * ClockDomainBSP_GCC_GCCCONFIGNOC
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCCONFIGNOC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCONFIGNOC[] =
{
  {   75000000, &ClockSource_GCC_GCCGPLL0,                { 1,     16,    0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP73_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCCONFIGNOCPCIESF
 *   ClockDomain_GCC_GCCMMUTCU
 *   ClockDomain_GCC_GCCSYSNOCSFAXI
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF[] =
{
  {  403200000, &ClockSource_GCC_GCCGPLL4,                { 5,     4,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[5] = GCC_GPLL4_OUT_MAIN_PWRGRP11_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCEMAC0PTP
 *
 * Used by:
 *   ClockDomain_GCC_GCCEMAC0PTP
 *   ClockDomain_GCC_GCCEMAC1PTP
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCEMAC0PTP[] =
{
  {  230400000, &ClockSource_GCC_GCCGPLL4,                { 5,     7,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[5] = GCC_GPLL4_OUT_MAIN_PWRGRP18_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCEMAC0RGMII
 *
 * Used by:
 *   ClockDomain_GCC_GCCEMAC0RGMII
 *   ClockDomain_GCC_GCCEMAC1RGMII
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCEMAC0RGMII[] =
{
  {  250000000, &ClockSource_GCC_GCCGPLL7,                { 2,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[2] = GCC_GPLL7_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCGPDSP0Q6AXI
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCGPDSP0Q6AXI
 *   ClockDomain_GCC_GCCGPDSP1Q6AXI
 *   ClockDomain_GCC_GCCGPUMEMNOCGFX
 *   ClockDomain_GCC_GCCMMNOCHFQX
 *   ClockDomain_GCC_GCCMMNOCSFQX
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCGPDSP0Q6AXI[] =
{
  {  533000000, &ClockSource_GCC_GCCGPLL1,                { 4,     4,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = GCC_GPLL1_OUT_MAIN_PWRGRP7_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCLBIST
 *
 * Used by:
 *   ClockDomain_GCC_GCCLBIST
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCLBIST[] =
{
  {  125000000, &ClockSource_GCC_GCCGPLL10,               { 2,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[2] = GCC_GPLL10_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCMEMNOC
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCMEMNOC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCMEMNOC[] =
{
  {  806400000, &ClockSource_GCC_GCCGPLL4,                { 5,     2,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[5] = GCC_GPLL4_OUT_MAIN_PWRGRP3_CLKGEN_ACGC_CLK */
};
#if 0
/*
 * ClockDomainBSP_GCC_GCCPCIE0PHYRCHNG
 *
 * Used by:
 *   ClockDomain_GCC_GCCPCIE0PHYRCHNG
 *   ClockDomain_GCC_GCCPCIE1PHYRCHNG
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCPCIE0PHYRCHNG[] =
{
  {  100000000, &ClockSource_GCC_GCCGPLL0,                { 1,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};
#endif
/*
 * ClockDomainBSP_GCC_GCCSAILSHSAPB
 *
 * Used by:
 *   ClockDomain_GCC_GCCSAILSHSAPB
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCSAILSHSAPB[] =
{
  {   50000000, &ClockSource_GCC_GCCGPLL0,                { 1,     24,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP7_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCSHRM
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCSHRM
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCSHRM[] =
{
  {  403200000, &ClockSource_GCC_GCCGPLL4,                { 5,     4,     0,     0,     0x01 }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[5] = GCC_GPLL4_OUT_MAIN_PWRGRP4_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCTURING0Q6AXI
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCTURING0Q6AXI
 *   ClockDomain_GCC_GCCTURING1Q6AXI
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCTURING0Q6AXI[] =
{
  {  600000000, &ClockSource_GCC_GCCGPLL0,                { 1,     2,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP5_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GPUCC_GPUCCFF
 *
 * Used by:
 *   ClockDomain_GPUCC_GPUCCFF
 */
static ClockMuxConfigType ClockDomainBSP_GPUCC_GPUCCFF[] =
{
  {  200000000, NULL,                                     { 5,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[5] = GPLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GPUCC_GPUCCGMU
 *
 * Used by:
 *   ClockDomain_GPUCC_GPUCCGMU
 */
static ClockMuxConfigType ClockDomainBSP_GPUCC_GPUCCGMU[] =
{
  {  500000000, &ClockSource_GPUCC_GPUCCPLL1,             { 3,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[3] = GPU_CC_PLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_GPUCC_GPUCCGXGFX3D
 *
 * Used by:
 *   ClockDomain_GPUCC_GPUCCGXGFX3D
 */
static ClockMuxConfigType ClockDomainBSP_GPUCC_GPUCCGXGFX3D[] =
{
  {  676000000, &ClockSource_GPUCC_GPUCCPLL0,             { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_GPUCC_GPUCCPLL0[ 2] /* 1352.0 */ },    /* Mux[1] = GPU_CC_PLL0_OUT_EVEN */
};
#if 0
/*
 * ClockDomainBSP_GPUCC_GPUCCHUB
 *
 * Used by:
 *   ClockDomain_GPUCC_GPUCCHUB
 */
static ClockMuxConfigType ClockDomainBSP_GPUCC_GPUCCHUB[] =
{
  {  240000000, NULL,                                     { 5,     5,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[5] = GPLL0_OUT_MAIN */
};
#endif
/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCACC
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCACC
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCACC[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   75000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCACMU0CORE
 *   ClockDomain_SAILSSCC_SAILSSCCACMU1CORE
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR
 *   ClockDomain_SAILSSCC_SAILSSCCRBCPRCX
 *   ClockDomain_SAILSSCC_SAILSSCCTSENSE
 *   ClockDomain_SAILSSCC_SAILSSCCVSCTRLPRIM
 *   ClockDomain_SAILSSCC_SAILSSCCVSCTRLSEC
 *   ClockDomain_SAILSSCC_SAILSSCCWDT
 *   ClockDomain_SAILSSCC_SAILSSCCXO
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCACMU0RO
 *   ClockDomain_SAILSSCC_SAILSSCCPWRCTRLXO
 *   ClockDomain_SAILSSCC_SAILSSCCSWAOTS
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO[] =
{
  {   19200000, &ClockSource_SAILSSCC_SAILSSCCPLL5,       { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[3] = SAILSS_CC_PLL5_OUT_EVEN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCACMU1RO
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCACMU1RO
 *   ClockDomain_SAILSSCC_SAILSSCCERROR
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCACMU1RO[] =
{
  {   19200000, &ClockSource_SAILSSCC_SAILSSCCPLL6,       { 4,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[4] = SAILSS_CC_PLL6_OUT_EVEN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCASILBNOCQX
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCASILBNOCQX[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  240000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     5,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_TUR,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCASILBQSPIQH
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCASILBQSPIQH
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCASILBQSPIQH[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   83000000, &ClockSource_SAILSSCC_SAILSSCCPLL2,       { 4,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[4] = SAILSS_CC_PLL2_OUT_MAIN */
  {  166000000, &ClockSource_SAILSSCC_SAILSSCCPLL2,       { 4,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = SAILSS_CC_PLL2_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCDMA
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCDMA[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  400000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     3,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  500000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_TUR,        },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCQUP
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCQUP[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  100000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCBMTXNOCQH
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCBMTXNOCQH[] =
{
  {   19200000, &ClockSource_SAILSSCC_SAILSSCCPLL5,       { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[3] = SAILSS_CC_PLL5_OUT_EVEN */
  {   50000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     24,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  100000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCCAN0CORE
 *   ClockDomain_SAILSSCC_SAILSSCCCAN1CORE
 *   ClockDomain_SAILSSCC_SAILSSCCCAN2CORE
 *   ClockDomain_SAILSSCC_SAILSSCCCAN3CORE
 *   ClockDomain_SAILSSCC_SAILSSCCCAN4CORE
 *   ClockDomain_SAILSSCC_SAILSSCCCAN5CORE
 *   ClockDomain_SAILSSCC_SAILSSCCCAN6CORE
 *   ClockDomain_SAILSSCC_SAILSSCCCAN7CORE
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   80000000, &ClockSource_SAILSSCC_SAILSSCCPLL3,       { 5,     24,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[5] = SAILSS_CC_PLL3_OUT_EVEN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCCE1
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCCE1
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCCE1[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   85714286, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     14,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCCPUCORE
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCCPUCORE
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCCPUCORE[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  { 1209600000, &ClockSource_SAILSSCC_SAILSSCCPLL1,       { 2,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     {{0}}, &ClockSourceBSP_SAILSSCC_SAILSSCCPLL1[ 0] /* 1209.0 */ },  /* Mux[2] = SAILSS_CC_PLL1_OUT_MAIN */
  { 1593600000, &ClockSource_SAILSSCC_SAILSSCCPLL1,       { 2,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_SAILSSCC_SAILSSCCPLL1[ 1] /* 1593.0 */ },  /* Mux[2] = SAILSS_CC_PLL1_OUT_MAIN */
  { 1843200000, &ClockSource_SAILSSCC_SAILSSCCPLL1,       { 2,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_TUR,        {{0}}, &ClockSourceBSP_SAILSSCC_SAILSSCCPLL1[ 2] /* 1843.0 */ },  /* Mux[2] = SAILSS_CC_PLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0PTP
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCEMAC0PTP
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0PTP[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  125000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0RGMII
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCEMAC0RGMII
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0RGMII[] =
{
  {    2500000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     20,    1,     20,    0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS_D1, },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
  {    5000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     20,    1,     10,    0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS_D1, },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   25000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     20,    1,     2,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
  {   50000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     20,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
  {  125000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
  {  250000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCGP1
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCGP1
 *   ClockDomain_SAILSSCC_SAILSSCCGP2
 *   ClockDomain_SAILSSCC_SAILSSCCGP3
 *   ClockDomain_SAILSSCC_SAILSSCCGP4
 *   ClockDomain_SAILSSCC_SAILSSCCGP5
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCGP1[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCHWKMKM
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCHWKMKM
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCHWKMKM[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   37500000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     32,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {   75000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCLBIST
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCLBIST
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCLBIST[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  120000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     10,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCPKACORE
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCPKACORE
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCPKACORE[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  250000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
  {  500000000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
  {  600000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_TUR,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCQDSSATBA
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSATBA
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSATBB
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCQDSSATBA[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  240000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     5,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  300000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_TUR,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRACECLKIN
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSTRACECLKIN
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRACECLKIN[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  150000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  300000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRIG
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSTRIG
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRIG[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   75000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  150000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCQSPICORE
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCQSPICORE
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCQSPICORE[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  166000000, &ClockSource_SAILSSCC_SAILSSCCPLL2,       { 4,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[4] = SAILSS_CC_PLL2_OUT_MAIN */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  332000000, &ClockSource_SAILSSCC_SAILSSCCPLL2,       { 4,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = SAILSS_CC_PLL2_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  150000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  200000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S0
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S1
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S2
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S3
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S4
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0[] =
{
  {    7372800, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     2,     192,   15625, 0xFF }, RAIL_VOLTAGE_LEVEL_RET,        {{0x02, 0x00}, {0xFF, 0xFF}, CHIPINFO_FAMILY_LEMANSAU}, },    /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {    7372800, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     2,     192,   15625, 0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS_D1, {{0x01, 0x00}, {0x02, 0x00}, CHIPINFO_FAMILY_LEMANSAU}, },    /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {   14745600, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     2,     384,   15625, 0xFF }, RAIL_VOLTAGE_LEVEL_RET,        {{0x02, 0x00}, {0xFF, 0xFF}, CHIPINFO_FAMILY_LEMANSAU}, },    /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {   14745600, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     2,     384,   15625, 0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS_D1, {{0x01, 0x00}, {0x02, 0x00}, CHIPINFO_FAMILY_LEMANSAU}, },    /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0x00 }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  100000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     12,    0,     0,     0x01 }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCSAILNOCCENTERQH
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCSAILNOCCENTERQH[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   85714286, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     14,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
  {  100000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCSECCTRL
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCSECCTRL
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCSECCTRL[] =
{
  {    4800000, &ClockSource_XO,                          { 0,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCSWAO
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCSWAO
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCSWAO[] =
{
  {   19200000, &ClockSource_SAILSSCC_SAILSSCCPLL5,       { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[3] = SAILSS_CC_PLL5_OUT_EVEN */
  {  300000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS0CNTR
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCTSCSS0CNTR
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS0CNTR[] =
{
  {    9600000, &ClockSource_XO,                          { 0,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {   15625000, &ClockSource_SAILSSCC_SAILSSCCPLL4,       { 6,     32,    1,     2,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[6] = SAILSS_CC_PLL4_OUT_MAIN */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS1CNTR
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCTSCSS1CNTR
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS1CNTR[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO_MX */
};

/*
 * ClockDomainBSP_SAILSSCC_SAILSSCCVSENSORPRIM
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCVSENSORPRIM
 *   ClockDomain_SAILSSCC_SAILSSCCVSENSORSEC
 */
static ClockMuxConfigType ClockDomainBSP_SAILSSCC_SAILSSCCVSENSORPRIM[] =
{
  {   19200000, &ClockSource_XO,                          { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[0] = SAILSS_SAFE_TCXO */
  {  300000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,       { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = SAILSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_TURINGCC0_TURING0TURINGCCAON
 *
 * Used by:
 *   ClockDomain_TURINGCC0_TURING0TURINGCCAON
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC0_TURING0TURINGCCAON[] =
{
  {  175000000, &ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL, { 4,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};
#if 0
/*
 * ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSISENSE
 *
 * Used by:
 *   ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSISENSE
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSISENSE[] =
{
  {  210000000, &ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL, { 4,     5,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};
#endif
/*
 * ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSLMH
 *
 * Used by:
 *   ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSLMH
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSLMH[] =
{
  {  262500000, &ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL, { 4,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};

/*
 * ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSBUS
 *
 * Used by:
 *   ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSBUS
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSBUS[] =
{
  {  525000000, &ClockSource_TURINGCC0_TURING0TURINGCCCORE2PLL, { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[3] = TURING_CC_CORE2_PLL_OUT_EVEN */
};

/*
 * ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA
 *
 * Used by:
 *   ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSDMA
 *   ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSFINT
 *   ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSHCP
 *   ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTBUF2
 *   ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTCMS
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA[] =
{
  {  525000000, &ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL, { 4,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};

/*
 * ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSVMA
 *
 * Used by:
 *   ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSVMA
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSVMA[] =
{
  {  350000000, &ClockSource_TURINGCC0_TURING0TURINGCCCORE0PLL, { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = TURING_CC_CORE0_PLL_OUT_MAIN */
};

/*
 * ClockDomainBSP_TURINGCC1_TURING1TURINGCCAON
 *
 * Used by:
 *   ClockDomain_TURINGCC1_TURING1TURINGCCAON
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC1_TURING1TURINGCCAON[] =
{
  {  175000000, &ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL, { 4,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};
#if 0
/*
 * ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSISENSE
 *
 * Used by:
 *   ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSISENSE
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSISENSE[] =
{
  {  210000000, &ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL, { 4,     5,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};
#endif
/*
 * ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSLMH
 *
 * Used by:
 *   ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSLMH
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSLMH[] =
{
  {  262500000, &ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL, { 4,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};

/*
 * ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSBUS
 *
 * Used by:
 *   ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSBUS
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSBUS[] =
{
  {  525000000, &ClockSource_TURINGCC1_TURING1TURINGCCCORE2PLL, { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[3] = TURING_CC_CORE2_PLL_OUT_EVEN */
};

/*
 * ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA
 *
 * Used by:
 *   ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSDMA
 *   ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSFINT
 *   ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSHCP
 *   ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTBUF2
 *   ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTCMS
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA[] =
{
  {  525000000, &ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL, { 4,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = TURING_CC_CORE0_PLL_OUT_EVEN */
};

/*
 * ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSVMA
 *
 * Used by:
 *   ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSVMA
 */
static ClockMuxConfigType ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSVMA[] =
{
  {  350000000, &ClockSource_TURINGCC1_TURING1TURINGCCCORE0PLL, { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = TURING_CC_CORE0_PLL_OUT_MAIN */
};
#if 0
/*
 * ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE
 *
 * Used by:
 *   ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE
 */
static ClockMuxConfigType ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE[] =
{
  { 1344000000, &ClockSource_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL, { 2,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL[ 1] /* 1344.0 */ },  /* Mux[2] = QDSP6SS_CORE_CC_PLL_OUT_MAIN */
};

/*
 * ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON
 *
 * Used by:
 *   ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON
 *   ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON
 */
static ClockMuxConfigType ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON[] =
{
  {  200000000, NULL,                                     { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = TURING_CC_GPLL0_CLK */
};

/*
 * ClockDomainBSP_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE
 *
 * Used by:
 *   ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE
 */
static ClockMuxConfigType ClockDomainBSP_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE[] =
{
  { 1344000000, &ClockSource_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCPLL, { 2,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCPLL[ 1] /* 1344.0 */ },  /* Mux[2] = QDSP6SS_CORE_CC_PLL_OUT_MAIN */
};
#endif
/*
 * ClockDomainBSP_TURINGQ6CC0_TURING0TURINGQ6CCCORE
 *
 * Used by:
 *   ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE
 */
static ClockMuxConfigType ClockDomainBSP_TURINGQ6CC0_TURING0TURINGQ6CCCORE[] =
{
  { 1171200000, &ClockSource_TURINGQ6CC0_TURING0TURINGQ6CCPLL, { 2,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL[ 3] /* 1171.0 */ },  /* Mux[2] = TURING_Q6_CC_PLL_OUT_MAIN */
};

/*
 * ClockDomainBSP_TURINGQ6CC1_TURING1TURINGQ6CCCORE
 *
 * Used by:
 *   ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE
 */
static ClockMuxConfigType ClockDomainBSP_TURINGQ6CC1_TURING1TURINGQ6CCCORE[] =
{
  { 1171200000, &ClockSource_TURINGQ6CC1_TURING1TURINGQ6CCPLL, { 2,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_TURINGQ6CC0_TURING0TURINGQ6CCPLL[ 3] /* 1171.0 */ },  /* Mux[2] = TURING_Q6_CC_PLL_OUT_MAIN */
};

/*
 * ClockDomainBSP_VIDEOCC_VIDEOCCMVS0
 *
 * Used by:
 *   ClockDomain_VIDEOCC_VIDEOCCMVS0
 */
static ClockMuxConfigType ClockDomainBSP_VIDEOCC_VIDEOCCMVS0[] =
{
  { 1332000000, &ClockSource_VIDEOCC_VIDEOPLL0,           { 1,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_VIDEOCC_VIDEOPLL0[ 1] /* 1332.0 */ },  /* Mux[1] = VIDEO_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_VIDEOCC_VIDEOCCMVS1
 *
 * Used by:
 *   ClockDomain_VIDEOCC_VIDEOCCMVS1
 */
static ClockMuxConfigType ClockDomainBSP_VIDEOCC_VIDEOCCMVS1[] =
{
  { 1332000000, &ClockSource_VIDEOCC_VIDEOPLL1,           { 1,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        {{0}}, &ClockSourceBSP_VIDEOCC_VIDEOPLL1[ 1] /* 1332.0 */ },  /* Mux[1] = VIDEO_PLL1_OUT_MAIN */
};


/*=========================================================================
      Domain Source Maps
==========================================================================*/

/*
 * ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCACC
 *   ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX
 *   ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP
 *   ClockDomain_SAILSSCC_SAILSSCCCE1
 *   ClockDomain_SAILSSCC_SAILSSCCGP1
 *   ClockDomain_SAILSSCC_SAILSSCCGP2
 *   ClockDomain_SAILSSCC_SAILSSCCGP3
 *   ClockDomain_SAILSSCC_SAILSSCCGP4
 *   ClockDomain_SAILSSCC_SAILSSCCGP5
 *   ClockDomain_SAILSSCC_SAILSSCCHWKMKM
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSATBA
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSATBB
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSTRACECLKIN
 *   ClockDomain_SAILSSCC_SAILSSCCQDSSTRIG
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S0
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S1
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S2
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S3
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S4
 *   ClockDomain_SAILSSCC_SAILSSCCRBCPRCX
 *   ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH
 *   ClockDomain_SAILSSCC_SAILSSCCVSENSORPRIM
 *   ClockDomain_SAILSSCC_SAILSSCCVSENSORSEC
 */
static const ClockSourceMapType ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0[] =
{
  { 0,   19200000, &ClockSource_XO,                         },
  { 1,  600000000, &ClockSource_SAILSSCC_SAILSSCCPLL0,      },
  { 7,  400000000, NULL,                                    },
  { CLOCK_SOURCE_MAP_END }
};


/*=========================================================================
      Domain FMAX
==========================================================================*/

/*
 * ClockDomainFMax_SAILSSCC_SAILSSCCQUPV3WRAP0S0
 *
 * Used by:
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S0
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S1
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S2
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S3
 *   ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S4
 */
static const ClockFMaxType ClockDomainFMax_SAILSSCC_SAILSSCCQUPV3WRAP0S0[] =
{
  {   19200000, RAIL_VOLTAGE_LEVEL_RET,        },
  {  100000000, RAIL_VOLTAGE_LEVEL_SVS_L1,     },
  {  0  }
};


/*=========================================================================
      Domains
==========================================================================*/

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCAMNOCAXI =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCAMNOCAXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCAMNOCAXI),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCCI0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCCI0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCCI0),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCCI1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCCI0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCCI0),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCCI2 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCCI0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCCI0),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCCI3 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCCI0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCCI0),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_3_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCPHYRX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCPHYRX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCPHYRX),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCSI0PHYTIMER =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCPHYRX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCPHYRX),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCSI1PHYTIMER =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCPHYRX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCPHYRX),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCSI2PHYTIMER =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCPHYRX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCPHYRX),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCSI3PHYTIMER =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCPHYRX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCPHYRX),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI3PHYTIMER_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCCSID =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCPHYRX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCPHYRX),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCFASTAHB =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCFASTAHB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCFASTAHB),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCICP =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCICP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCICP),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCIFE0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCIFE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCIFE0),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCIFE1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCIFE1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCIFE1),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCIFELITE =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCIFELITE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCIFELITE),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCIFELITECSID =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCCPHYRX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCCPHYRX),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCIPE =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCIPE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCIPE),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCMCLK0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCMCLK0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCMCLK0),
  .nRailMask = RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCMCLK1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCMCLK0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCMCLK0),
  .nRailMask = RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCMCLK2 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCMCLK0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCMCLK0),
  .nRailMask = RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCMCLK3 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCMCLK0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCMCLK0),
  .nRailMask = RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK3_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCPLLTESTSTAGE007MUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCQDSSDEBUG =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCQDSSDEBUG,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCQDSSDEBUG),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCSLEEP =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCSLEEP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCSLEEP),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCSLOWAHB =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCSLOWAHB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCSLOWAHB),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_CAMCC_CAMCCSMDEBUGCLKMONITORMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_CAMCC_CAMCCXO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CAM_CC_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB =
{
  .aBSP      = ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSAHB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSAHB),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_AHB_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_BYTE0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_BYTE1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0AUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0CRYPTO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0LINK =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL2 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL3 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1AUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1CRYPTO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1LINK =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_ESC0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_ESC1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP =
{
  .aBSP      = ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSMDP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC0_MDSS0DISPCCMDSSMDP),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_MDP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_PCLK0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_PCLK1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCMDSSVSYNC =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_VSYNC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_PLL_TEST_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCSLEEP =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCSLEEP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCSLEEP),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_SLEEP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCSMMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC0_MDSS0DISPCCXO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB =
{
  .aBSP      = ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSAHB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSAHB),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0AUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0CRYPTO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0LINK =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL2 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL3 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1AUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1CRYPTO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1LINK =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP =
{
  .aBSP      = ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSMDP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC1_MDSS1DISPCCMDSSMDP),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK0 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK1 =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCMDSSVSYNC =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCSLEEP =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCSLEEP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCSLEEP),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCSMMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC1_MDSS1DISPCCXO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_CLOCKDRIVERGENXO =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = 0x0,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = 0x0,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOC),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCPCIESF =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCPCIESF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCPCIESF),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_PCIE_SF_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCCNOCCENTERQX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_CNOC_CENTER_QX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCCNOCPERIPH =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCNOCPERIPH,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCNOCPERIPH),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_CNOC_PERIPH_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCCONFIGNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCONFIGNOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCONFIGNOC),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_CONFIG_NOC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCCONFIGNOCDDRSSSF =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_CONFIG_NOC_DDRSS_SF_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCCONFIGNOCPCIESF =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_CONFIG_NOC_PCIE_SF_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCEMAC0PHYAUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_PHY_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCEMAC0PTP =
{
  .aBSP      = ClockDomainBSP_GCC_GCCEMAC0PTP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCEMAC0PTP),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_PTP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCEMAC0RGMII =
{
  .aBSP      = ClockDomainBSP_GCC_GCCEMAC0RGMII,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCEMAC0RGMII),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_RGMII_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCEMAC1PHYAUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_PHY_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCEMAC1PTP =
{
  .aBSP      = ClockDomainBSP_GCC_GCCEMAC0PTP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCEMAC0PTP),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_PTP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCEMAC1RGMII =
{
  .aBSP      = ClockDomainBSP_GCC_GCCEMAC0RGMII,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCEMAC0RGMII),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_RGMII_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCGPDSP0Q6AXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCGPDSP0Q6AXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCGPDSP0Q6AXI),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_0_Q6_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCGPDSP1Q6AXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCGPDSP0Q6AXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCGPDSP0Q6AXI),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_1_Q6_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCGPUMEMNOCGFX =
{
  .aBSP      = ClockDomainBSP_GCC_GCCGPDSP0Q6AXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCGPDSP0Q6AXI),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_GPU_MEMNOC_GFX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCLBIST =
{
  .aBSP      = ClockDomainBSP_GCC_GCCLBIST,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCLBIST),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_LBIST_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCMEMNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCMEMNOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCMEMNOC),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_MEMNOC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCMMNOCHFQX =
{
  .aBSP      = ClockDomainBSP_GCC_GCCGPDSP0Q6AXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCGPDSP0Q6AXI),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_HF_QX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCMMNOCSFQX =
{
  .aBSP      = ClockDomainBSP_GCC_GCCGPDSP0Q6AXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCGPDSP0Q6AXI),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_SF_QX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCMMUTCU =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_MMU_TCU_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCPCIE0AUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCPCIE0PHYAUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_DOMAIN_FORCE_SETTINGS,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_AUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCPCIE0PHYRCHNG =
{
  .aBSP      = ClockDomainBSP_GCC_GCCPCIE0PHYRCHNG,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCPCIE0PHYRCHNG),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_PHY_RCHNG_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCPCIE0PIPE =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_DOMAIN_FORCE_SETTINGS,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_PIPE_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCPCIE1AUX =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_AUX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCPCIE1PHYAUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_DOMAIN_FORCE_SETTINGS,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_AUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCPCIE1PHYRCHNG =
{
  .aBSP      = ClockDomainBSP_GCC_GCCPCIE0PHYRCHNG,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCPCIE0PHYRCHNG),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_PHY_RCHNG_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCPCIE1PIPE =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_DOMAIN_FORCE_SETTINGS,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_PIPE_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCQDSSAPBTSCTR =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_QDSS_APB_TSCTR_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCQDSSATBB =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_QDSS_ATB_B_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCQDSSTRIG =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_QDSS_TRIG_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCSAILAXI =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_SAIL_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCSAILSHSAPB =
{
  .aBSP      = ClockDomainBSP_GCC_GCCSAILSHSAPB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCSAILSHSAPB),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_SAIL_SHS_APB_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCSHRM =
{
  .aBSP      = ClockDomainBSP_GCC_GCCSHRM,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCSHRM),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_SHRM_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCSLEEP =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_SLEEP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCSYSNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOC),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_SYS_NOC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GCC_GCCSYSNOCGCAXI =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_SYS_NOC_GC_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCSYSNOCSFAXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCONFIGNOCPCIESF),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_SYS_NOC_SF_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GCC_GCCTURING0Q6AXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCTURING0Q6AXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCTURING0Q6AXI),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_TURING_0_Q6_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCTURING1Q6AXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCTURING0Q6AXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCTURING0Q6AXI),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_TURING_1_Q6_AXI_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCXO =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GCC_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GPUCC_GPUCCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_GPUCC_GPUCCFF =
{
  .aBSP      = ClockDomainBSP_GPUCC_GPUCCFF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GPUCC_GPUCCFF),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GPUCC_GPUCCGMU =
{
  .aBSP      = ClockDomainBSP_GPUCC_GPUCCGMU,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GPUCC_GPUCCGMU),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_GPUCC_GPUCCGXGFX3D =
{
  .aBSP      = ClockDomainBSP_GPUCC_GPUCCGXGFX3D,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GPUCC_GPUCCGXGFX3D),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_GX | RAIL_VDD_MXA | RAIL_VDD_MXC,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GPUCC_GPUCCHUB =
{
  .aBSP      = ClockDomainBSP_GPUCC_GPUCCHUB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GPUCC_GPUCCHUB),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GPUCC_GPUCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_GPUCC_GPUCCRBCPR =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_GPUCC_GPUCCSMMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_GPUCC_GPUCCXO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCACC =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACC),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCACMU0CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCACMU0RO =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_RO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCACMU1CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCACMU1RO =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU1RO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU1RO),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_RO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCASILBNOCQX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCASILBNOCQX),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_QX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCASILBQSPIQH =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCASILBQSPIQH,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCASILBQSPIQH),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_QSPI_QH_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCDMA),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_DMA_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCQUP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCASILDNOCQUP),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_QUP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCBMTXNOCQH,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCBMTXNOCQH),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_BMTX_NOC_QH_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN0CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN0_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN1CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN1_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN2CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN2_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN3CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN3_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN4CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN4_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN5CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN5_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN6CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN6_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCAN7CORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCAN0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN7_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCE1 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCE1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCE1),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CE1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCCPUCORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCCPUCORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCCPUCORE),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCEMAC0PTP =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0PTP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0PTP),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_PTP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCEMAC0RGMII =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0RGMII,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCEMAC0RGMII),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_RGMII_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCERROR =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU1RO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU1RO),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ERROR_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCGP1 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCGP1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCGP1),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCGP2 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCGP1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCGP1),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCGP3 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCGP1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCGP1),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP3_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCGP4 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCGP1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCGP1),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP4_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCGP5 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCGP1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCGP1),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP5_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCHWKMKM =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCHWKMKM,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCHWKMKM),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCLBIST =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCLBIST,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCLBIST),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCPKACORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCPKACORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCPKACORE),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL_TEST_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCPWRCTRLXO =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO),
  .nRailMask = RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_APB_TSCTR_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQDSSATBA =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQDSSATBA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQDSSATBA),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_ATB_A_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQDSSATBB =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQDSSATBA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQDSSATBA),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_ATB_B_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQDSSTRACECLKIN =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRACECLKIN,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRACECLKIN),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_TRACECLKIN_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQDSSTRIG =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRIG,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQDSSTRIG),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_TRIG_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQSPICORE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQSPICORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQSPICORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_CORE_2X_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S0 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aFMax     = ClockDomainFMax_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S1 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aFMax     = ClockDomainFMax_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S2 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aFMax     = ClockDomainFMax_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S3 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aFMax     = ClockDomainFMax_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S3_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S4 =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCQUPV3WRAP0S0),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aFMax     = ClockDomainFMax_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S4_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCRBCPRCX =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_RBCPR_CX_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCSAILNOCCENTERQH),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SAIL_NOC_CENTER_QH_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCSECCTRL =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCSECCTRL,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCSECCTRL),
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCSWAO =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCSWAO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCSWAO),
  .nRailMask = RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCSWAOTS =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0RO),
  .nRailMask = RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCTSCSS0CNTR =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS0CNTR,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS0CNTR),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSCSS_0_CNTR_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCTSCSS1CNTR =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS1CNTR,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCTSCSS1CNTR),
  .nRailMask = RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCTSENSE =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSENSE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCVSCTRLPRIM =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_CTRL_PRIM_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCVSCTRLSEC =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_CTRL_SEC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCVSENSORPRIM =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCVSENSORPRIM,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCVSENSORPRIM),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCVSENSORSEC =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCVSENSORPRIM,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCVSENSORPRIM),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .aSourceMap = ClockSourceMap_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCWDT =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCXO =
{
  .aBSP      = ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_SAILSSCC_SAILSSCCACMU0CORE),
  .nRailMask = RAIL_VDD_SAIL_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_SAILSSCC_SAILSSCCXOROGFMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_SAIL_CX | RAIL_VDD_SAIL_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_XO_RO_GFMUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCAON =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCAON,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCAON),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_AON_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_DEBUG_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_PLL_TEST_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSISENSE =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSISENSE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSISENSE),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_ISENSE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSLMH =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSLMH,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCQ6SSLMH),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_LMH_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCSMDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSBUS =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSBUS,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSBUS),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_BUS_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSDMA =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_DMA_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSFINT =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_FINT_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSHCP =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_HCP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTBUF2 =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_TBUF2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTCMS =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_TCMS_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSVMA =
{
  .aBSP      = ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSVMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC0_TURING0TURINGCCVAPSSVMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_VMA_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCAON =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCAON,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCAON),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_AON_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_DEBUG_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_PLL_TEST_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSISENSE =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSISENSE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSISENSE),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_ISENSE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSLMH =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSLMH,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCQ6SSLMH),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_LMH_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCSMDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSBUS =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSBUS,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSBUS),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_BUS_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSDMA =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_DMA_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSFINT =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_FINT_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSHCP =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_HCP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTBUF2 =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_TBUF2_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTCMS =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSDMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_TCMS_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSVMA =
{
  .aBSP      = ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSVMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGCC1_TURING1TURINGCCVAPSSVMA),
  .nRailMask = RAIL_VDD_CX | RAIL_VDD_MXA,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_VMA_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE =
{
  .aBSP      = ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON =
{
  .aBSP      = ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_AON_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE =
{
  .aBSP      = ClockDomainBSP_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON =
{
  .aBSP      = ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON),
  .nRailMask = RAIL_VDD_CX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_AON_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_DEBUG_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE =
{
  .aBSP      = ClockDomainBSP_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGQ6CC0_TURING0TURINGQ6CCCORE),
  .nRailMask = RAIL_VDD_MXC | RAIL_VDD_NSP_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_NSP_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCSMMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_NSP_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE =
{
  .aBSP      = ClockDomainBSP_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_TURINGQ6CC1_TURING1TURINGQ6CCCORE),
  .nRailMask = RAIL_VDD_MXC | RAIL_VDD_NSP_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_CORE_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCDEBUGMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_NSP_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCSMMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_NSP_CX,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_VIDEOCC_VIDEOCCAHB =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_VIDEOCC_VIDEOCCMVS0 =
{
  .aBSP      = ClockDomainBSP_VIDEOCC_VIDEOCCMVS0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_VIDEOCC_VIDEOCCMVS0),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_VIDEOCC_VIDEOCCMVS1 =
{
  .aBSP      = ClockDomainBSP_VIDEOCC_VIDEOCCMVS1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_VIDEOCC_VIDEOCCMVS1),
  .nRailMask = RAIL_VDD_MM | RAIL_VDD_MX,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};
#if 0
static ClockDomainNodeType ClockDomain_VIDEOCC_VIDEOCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR),
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};

static ClockDomainNodeType ClockDomain_VIDEOCC_VIDEOCCSLEEP =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCSLEEP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCSLEEP),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_VIDEOCC_VIDEOCCSMMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nRailMask = RAIL_VDD_MM,
  .pSource   = NULL,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainMuxControl,
  },
};
#endif
static ClockDomainNodeType ClockDomain_VIDEOCC_VIDEOCCXO =
{
  .aBSP      = ClockDomainBSP_CAMCC_CAMCCXO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_CAMCC_CAMCCXO),
  .nRailMask = RAIL_VDD_MM,
  .pSource   = &ClockSource_XO,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR),
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};


static ClockDomainNodeType *aDomains[] =
{
  &ClockDomain_CAMCC_CAMCCCAMNOCAXI,
#if 0
  &ClockDomain_CAMCC_CAMCCCCI0,
  &ClockDomain_CAMCC_CAMCCCCI1,
  &ClockDomain_CAMCC_CAMCCCCI2,
  &ClockDomain_CAMCC_CAMCCCCI3,
  &ClockDomain_CAMCC_CAMCCCPHYRX,
  &ClockDomain_CAMCC_CAMCCCSI0PHYTIMER,
  &ClockDomain_CAMCC_CAMCCCSI1PHYTIMER,
  &ClockDomain_CAMCC_CAMCCCSI2PHYTIMER,
  &ClockDomain_CAMCC_CAMCCCSI3PHYTIMER,
#endif
  &ClockDomain_CAMCC_CAMCCCSID,
#if 0
  &ClockDomain_CAMCC_CAMCCDEBUGMUX,
#endif
  &ClockDomain_CAMCC_CAMCCFASTAHB,
#if 0
  &ClockDomain_CAMCC_CAMCCICP,
#endif
  &ClockDomain_CAMCC_CAMCCIFE0,
  &ClockDomain_CAMCC_CAMCCIFE1,
#if 0
  &ClockDomain_CAMCC_CAMCCIFELITE,
#endif
  &ClockDomain_CAMCC_CAMCCIFELITECSID,
  &ClockDomain_CAMCC_CAMCCIPE,
#if 0
  &ClockDomain_CAMCC_CAMCCMCLK0,
  &ClockDomain_CAMCC_CAMCCMCLK1,
  &ClockDomain_CAMCC_CAMCCMCLK2,
  &ClockDomain_CAMCC_CAMCCMCLK3,
  &ClockDomain_CAMCC_CAMCCPLLTESTSTAGE007MUX,
  &ClockDomain_CAMCC_CAMCCQDSSDEBUG,
  &ClockDomain_CAMCC_CAMCCSLEEP,
#endif
  &ClockDomain_CAMCC_CAMCCSLOWAHB,
  #if 0
  &ClockDomain_CAMCC_CAMCCSMDEBUGCLKMONITORMUX,
  &ClockDomain_CAMCC_CAMCCXO,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE0,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE1,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0AUX,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0CRYPTO,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0LINK,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL0,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL1,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL2,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL3,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1AUX,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1CRYPTO,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1LINK,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL0,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL1,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC0,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC1,
  #endif
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP,
  #if 0
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK0,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK1,
  &ClockDomain_DISPCC0_MDSS0DISPCCMDSSVSYNC,
  &ClockDomain_DISPCC0_MDSS0DISPCCPLLTESTMUX,
  &ClockDomain_DISPCC0_MDSS0DISPCCSLEEP,
  &ClockDomain_DISPCC0_MDSS0DISPCCSMMUX,
  &ClockDomain_DISPCC0_MDSS0DISPCCXO,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE0,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE1,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0AUX,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0CRYPTO,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0LINK,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL0,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL1,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL2,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL3,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1AUX,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1CRYPTO,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1LINK,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL0,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL1,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC0,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC1,
  #endif
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP,
  #if 0
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK0,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK1,
  &ClockDomain_DISPCC1_MDSS1DISPCCMDSSVSYNC,
  &ClockDomain_DISPCC1_MDSS1DISPCCPLLTESTMUX,
  &ClockDomain_DISPCC1_MDSS1DISPCCSLEEP,
  &ClockDomain_DISPCC1_MDSS1DISPCCSMMUX,
  &ClockDomain_DISPCC1_MDSS1DISPCCXO,
  #endif
  &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
  &ClockDomain_GCC_CLOCKDRIVERGENXO,
  &ClockDomain_GCC_GCCAGGRENOC,
  &ClockDomain_GCC_GCCAGGRENOCPCIESF,
#if 0
  &ClockDomain_GCC_GCCCNOCCENTERQX,
  &ClockDomain_GCC_GCCCNOCPERIPH,
#endif
  &ClockDomain_GCC_GCCCONFIGNOC,
  &ClockDomain_GCC_GCCCONFIGNOCDDRSSSF,
  &ClockDomain_GCC_GCCCONFIGNOCPCIESF,
  &ClockDomain_GCC_GCCEMAC0PHYAUX,
  &ClockDomain_GCC_GCCEMAC0PTP,
  &ClockDomain_GCC_GCCEMAC0RGMII,
#if 0
  &ClockDomain_GCC_GCCEMAC1PHYAUX,
#endif
  &ClockDomain_GCC_GCCEMAC1PTP,
#if 0
  &ClockDomain_GCC_GCCEMAC1RGMII,
#endif
  &ClockDomain_GCC_GCCGPDSP0Q6AXI,
  &ClockDomain_GCC_GCCGPDSP1Q6AXI,
  &ClockDomain_GCC_GCCGPUMEMNOCGFX,
  &ClockDomain_GCC_GCCLBIST,
  &ClockDomain_GCC_GCCMEMNOC,
  &ClockDomain_GCC_GCCMMNOCHFQX,
  &ClockDomain_GCC_GCCMMNOCSFQX,
  &ClockDomain_GCC_GCCMMUTCU,
  &ClockDomain_GCC_GCCPCIE0AUX,
#if 0
  &ClockDomain_GCC_GCCPCIE0PHYAUX,
  &ClockDomain_GCC_GCCPCIE0PHYRCHNG,
#endif
  &ClockDomain_GCC_GCCPCIE0PIPE,
  &ClockDomain_GCC_GCCPCIE1AUX,
#if 0
  &ClockDomain_GCC_GCCPCIE1PHYAUX,
  &ClockDomain_GCC_GCCPCIE1PHYRCHNG,
#endif
  &ClockDomain_GCC_GCCPCIE1PIPE,
  #if 0
  &ClockDomain_GCC_GCCQDSSAPBTSCTR,
  &ClockDomain_GCC_GCCQDSSATBB,
  &ClockDomain_GCC_GCCQDSSTRIG,
  #endif
  &ClockDomain_GCC_GCCSAILAXI,
  &ClockDomain_GCC_GCCSAILSHSAPB,
  &ClockDomain_GCC_GCCSHRM,
#if 0
  &ClockDomain_GCC_GCCSLEEP,
#endif
  &ClockDomain_GCC_GCCSYSNOC,
#if 0
  &ClockDomain_GCC_GCCSYSNOCGCAXI,
  &ClockDomain_GCC_GCCSYSNOCSFAXI,
#endif
  &ClockDomain_GCC_GCCTURING0Q6AXI,
  &ClockDomain_GCC_GCCTURING1Q6AXI,
  &ClockDomain_GCC_GCCXO,
#if 0
  &ClockDomain_GPUCC_GPUCCDEBUGMUX,
  &ClockDomain_GPUCC_GPUCCFF,
#endif
  &ClockDomain_GPUCC_GPUCCGMU,
  &ClockDomain_GPUCC_GPUCCGXGFX3D,
#if 0
  &ClockDomain_GPUCC_GPUCCHUB,
  &ClockDomain_GPUCC_GPUCCPLLTESTMUX,
#endif
  &ClockDomain_GPUCC_GPUCCRBCPR,
#if 0
  &ClockDomain_GPUCC_GPUCCSMMUX,
#endif
  &ClockDomain_GPUCC_GPUCCXO,
  &ClockDomain_SAILSSCC_SAILSSCCACC,
  &ClockDomain_SAILSSCC_SAILSSCCACMU0CORE,
  &ClockDomain_SAILSSCC_SAILSSCCACMU0RO,
  &ClockDomain_SAILSSCC_SAILSSCCACMU1CORE,
  &ClockDomain_SAILSSCC_SAILSSCCACMU1RO,
  &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
  &ClockDomain_SAILSSCC_SAILSSCCASILBQSPIQH,
  &ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA,
  &ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP,
  &ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH,
  &ClockDomain_SAILSSCC_SAILSSCCCAN0CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCAN1CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCAN2CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCAN3CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCAN4CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCAN5CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCAN6CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCAN7CORE,
  &ClockDomain_SAILSSCC_SAILSSCCCE1,
  &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
  &ClockDomain_SAILSSCC_SAILSSCCEMAC0PTP,
  &ClockDomain_SAILSSCC_SAILSSCCEMAC0RGMII,
  &ClockDomain_SAILSSCC_SAILSSCCERROR,
  &ClockDomain_SAILSSCC_SAILSSCCGP1,
  &ClockDomain_SAILSSCC_SAILSSCCGP2,
  &ClockDomain_SAILSSCC_SAILSSCCGP3,
  &ClockDomain_SAILSSCC_SAILSSCCGP4,
  &ClockDomain_SAILSSCC_SAILSSCCGP5,
  &ClockDomain_SAILSSCC_SAILSSCCHWKMKM,
  &ClockDomain_SAILSSCC_SAILSSCCLBIST,
  &ClockDomain_SAILSSCC_SAILSSCCPKACORE,
  &ClockDomain_SAILSSCC_SAILSSCCPLLTESTMUX,
  &ClockDomain_SAILSSCC_SAILSSCCPWRCTRLXO,
  &ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR,
  &ClockDomain_SAILSSCC_SAILSSCCQDSSATBA,
  &ClockDomain_SAILSSCC_SAILSSCCQDSSATBB,
  &ClockDomain_SAILSSCC_SAILSSCCQDSSTRACECLKIN,
  &ClockDomain_SAILSSCC_SAILSSCCQDSSTRIG,
  &ClockDomain_SAILSSCC_SAILSSCCQSPICORE,
  &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X,
  &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
  &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S1,
  &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S2,
  &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S3,
  &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S4,
  &ClockDomain_SAILSSCC_SAILSSCCRBCPRCX,
  &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
  &ClockDomain_SAILSSCC_SAILSSCCSECCTRL,
  &ClockDomain_SAILSSCC_SAILSSCCSWAO,
  &ClockDomain_SAILSSCC_SAILSSCCSWAOTS,
  &ClockDomain_SAILSSCC_SAILSSCCTSCSS0CNTR,
  &ClockDomain_SAILSSCC_SAILSSCCTSCSS1CNTR,
  &ClockDomain_SAILSSCC_SAILSSCCTSENSE,
  &ClockDomain_SAILSSCC_SAILSSCCVSCTRLPRIM,
  &ClockDomain_SAILSSCC_SAILSSCCVSCTRLSEC,
  &ClockDomain_SAILSSCC_SAILSSCCVSENSORPRIM,
  &ClockDomain_SAILSSCC_SAILSSCCVSENSORSEC,
  &ClockDomain_SAILSSCC_SAILSSCCWDT,
  &ClockDomain_SAILSSCC_SAILSSCCXO,
  &ClockDomain_SAILSSCC_SAILSSCCXOROGFMUX,
  &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
  #if 0
  &ClockDomain_TURINGCC0_TURING0TURINGCCDEBUGMUX,
  &ClockDomain_TURINGCC0_TURING0TURINGCCPLLTESTMUX,
  &ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSISENSE,
  #endif
  &ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSLMH,
  &ClockDomain_TURINGCC0_TURING0TURINGCCSMDEBUGMUX,
  &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSBUS,
  &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSDMA,
  &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSFINT,
  &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSHCP,
  &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTBUF2,
  &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTCMS,
  &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSVMA,
  &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
  #if 0
  &ClockDomain_TURINGCC1_TURING1TURINGCCDEBUGMUX,
  &ClockDomain_TURINGCC1_TURING1TURINGCCPLLTESTMUX,
  &ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSISENSE,
  #endif
  &ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSLMH,
  &ClockDomain_TURINGCC1_TURING1TURINGCCSMDEBUGMUX,
  &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSBUS,
  &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSDMA,
  &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSFINT,
  &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSHCP,
  &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTBUF2,
  &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTCMS,
  &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSVMA,
  #if 0
  &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE,
  &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCDEBUGMUX,
  &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
  &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCDEBUGMUX,
  &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE,
  &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCDEBUGMUX,
  &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
  &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCDEBUGMUX,
  #endif
  &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
#if 0
  &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCDEBUGMUX,
  &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCSMMUX,
#endif
  &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
#if 0
  &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCDEBUGMUX,
  &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCSMMUX,
#endif
  &ClockDomain_VIDEOCC_VIDEOCCAHB,
  &ClockDomain_VIDEOCC_VIDEOCCMVS0,
  &ClockDomain_VIDEOCC_VIDEOCCMVS1,
  #if 0
  &ClockDomain_VIDEOCC_VIDEOCCPLLTESTMUX,
  &ClockDomain_VIDEOCC_VIDEOCCSLEEP,
  &ClockDomain_VIDEOCC_VIDEOCCSMMUX,
  #endif
  &ClockDomain_VIDEOCC_VIDEOCCXO,
};


/*=========================================================================
      Clocks
==========================================================================*/

static ClockNodeType aClocks[] =
{
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCAMNOCAXI                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_camnoc_axi_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCAMNOCAXI,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x8AA30E80,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 53,
    },
  },
#if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCCI0                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cci_0_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCCI0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x2F0FA585,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_0_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 48,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCCI1                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cci_1_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCCI1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x0072D990,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_1_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 49,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCCI2                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cci_2_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCCI2,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x68C6ABCF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_2_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 5,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCCI3                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cci_3_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCCI3,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x07E4E704,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CCI_3_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 6,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCPHYRX                                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_csid_csiphy_rx_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCPHYRX,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x2FBDAC2F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
  {
    .szName    = "cam_cc_csiphy0_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCPHYRX,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x5BD9C966,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 10,
    },
  },
  {
    .szName    = "cam_cc_csiphy1_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCPHYRX,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xD1C62B7E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 13,
    },
  },
  {
    .szName    = "cam_cc_csiphy2_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCPHYRX,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xFB341D3F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 15,
    },
  },
  {
    .szName    = "cam_cc_csiphy3_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCPHYRX,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x29439ED4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSIPHY3_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "cam_cc_ife_lite_cphy_rx_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCPHYRX,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x51577E4F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 36,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCSI0PHYTIMER                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_csi0phytimer_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCSI0PHYTIMER,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xDF3E55F8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 9,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCSI1PHYTIMER                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_csi1phytimer_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCSI1PHYTIMER,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xBD91807B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 12,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCSI2PHYTIMER                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_csi2phytimer_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCSI2PHYTIMER,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x411BC4E9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCSI3PHYTIMER                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_csi3phytimer_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCSI3PHYTIMER,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xD8F7C361,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSI3PHYTIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 16,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCCSID                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_csid_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCCSID,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x81ECCAD5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CSID_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },
#if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCDEBUGMUX                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_debug_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x8E6D4CE1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCFASTAHB                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cpas_fast_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCFASTAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xC8B7CE22,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },
  #endif
  {
    .szName    = "cam_cc_ife_0_fast_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCFASTAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x5422ADFD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 27,
    },
  },
  {
    .szName    = "cam_cc_ife_1_fast_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCFASTAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x24DD2629,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 32,
    },
  },
  {
    .szName    = "cam_cc_ipe_fast_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCFASTAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x1494FF97,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 22,
    },
  },
  {
    .szName    = "cam_cc_sfe_lite_0_fast_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCFASTAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xFD405085,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 41,
    },
  },
  {
    .szName    = "cam_cc_sfe_lite_1_fast_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCFASTAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xED8E43BE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 45,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCICP                                            */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_icp_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCICP,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xFDC6BEB1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_ICP_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_ICP_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 46,
    },
  },
#if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCIFE0                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cpas_ife_0_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x690E94A4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },
  {
    .szName    = "cam_cc_cpas_sfe_lite_0_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xD73D272A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 39,
    },
  },
  #endif
  {
    .szName    = "cam_cc_ife_0_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x93CC2ED3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 23,
    },
  },
  #if 0
  {
    .szName    = "cam_cc_ife_0_spdm_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x4C5D526B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 26,
    },
  },
  {
    .szName    = "cam_cc_sfe_lite_0_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x1E1E523B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 38,
    },
  },
  {
    .szName    = "cam_cc_sfe_lite_0_spdm_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x9C8C087E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 40,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCIFE1                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cpas_ife_1_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x615F16E2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 29,
    },
  },
  {
    .szName    = "cam_cc_cpas_sfe_lite_1_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x8968C1D2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 43,
    },
  },
#endif
  {
    .szName    = "cam_cc_ife_1_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x20EDB204,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 28,
    },
  },
  {
    .szName    = "cam_cc_ife_1_spdm_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x3E07A91F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 31,
    },
  },
  {
    .szName    = "cam_cc_sfe_lite_1_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x668F8D1C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 42,
    },
  },
#if 0
  {
    .szName    = "cam_cc_sfe_lite_1_spdm_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFE1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x9F8F29D0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 44,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCIFELITE                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cpas_ife_lite_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFELITE,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xAA3AA381,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 34,
    },
  },
  {
    .szName    = "cam_cc_ife_lite_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFELITE,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xD0972606,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 33,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCIFELITECSID                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_ife_lite_csid_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIFELITECSID,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xC6E06EE3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 35,
    },
  },
#if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCIPE                                            */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_cpas_ipe_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIPE,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x9E0C3271,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },
  #endif
  {
    .szName    = "cam_cc_ipe_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIPE,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x847B9887,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  #if 0
  {
    .szName    = "cam_cc_ipe_spdm_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCIPE,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x90F0B8E2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCMCLK0                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_mclk0_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCMCLK0,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xAFDBB67A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK0_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 1,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCMCLK1                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_mclk1_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCMCLK1,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x57396D81,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK1_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 2,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCMCLK2                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_mclk2_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCMCLK2,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x70806571,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK2_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 3,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCMCLK3                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_mclk3_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCMCLK3,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x35F364E9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_MCLK3_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 4,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCPLLTESTSTAGE007MUX                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_pll_test_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCPLLTESTSTAGE007MUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x519E3D27,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCQDSSDEBUG                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_qdss_debug_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCQDSSDEBUG,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x1843A6D1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 56,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCSLEEP                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_sleep_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCSLEEP,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xCFDF030C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SLEEP_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 60,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCSLOWAHB                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_core_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCSLOWAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xA974C223,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 58,
    },
  },
  {
    .szName    = "cam_cc_cpas_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCSLOWAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x7E6C7824,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },
  {
    .szName    = "cam_cc_icp_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCSLOWAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x32CA8C6A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_ICP_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 47,
    },
  },
  {
    .szName    = "cam_cc_ife_lite_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCSLOWAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x27E3565D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 37,
    },
  },
  {
    .szName    = "cam_cc_ipe_ahb_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCSLOWAHB,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xC1192084,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_IPE_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 21,
    },
  },
#if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCSMDEBUGCLKMONITORMUX                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_sm_obs_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCSMDEBUGCLKMONITORMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x1945482C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_SM_OBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_CAMCC_CAMCCXO                                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "cam_cc_camnoc_dcd_xo_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCXO,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xD2B89C42,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 54,
    },
  },
  {
    .szName    = "cam_cc_camnoc_xo_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCXO,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0x6D33216F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 55,
    },
  },
  {
    .szName    = "cam_cc_gdsc_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCXO,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xC9FEBE6E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_GDSC_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 59,
    },
  },
  {
    .szName    = "cam_cc_qdss_debug_xo_clk",
    .pDomain   = &ClockDomain_CAMCC_CAMCCXO,
    .pDebugMux = &ClockDebugMux_CAMCC,
    .nUniqueId = 0xFC7EF9CE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 57,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_ahb1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x25AD2909,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_AHB1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 39,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xBBF85513,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 38,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_non_gdsc_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xADDA45B8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_NON_GDSC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_RSCC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 42,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_rscc_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xEEF47C14,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_RSCC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_RSCC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 44,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE0                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_byte0_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xEB9AAD48,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_BYTE0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_byte0_intf_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xE82DFC5D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_BYTE0_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE1                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_byte1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xDACA132B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_BYTE1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_byte1_intf_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSBYTE1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x953F3523,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_BYTE1_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 21,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0AUX                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_aux_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0AUX,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x9E40F88E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 28,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0CRYPTO                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_crypto_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0CRYPTO,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xF3CAF5AA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 27,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_spdm_dp_crypto_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0CRYPTO,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x5FEC9CAE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 49,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0LINK                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_link_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0LINK,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x4E46E157,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_LINK_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0LINK,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x0BB705F5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 25,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_usb_router_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0LINK,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x3FB6E594,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 26,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL0                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_pixel0_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x399636AB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 29,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_spdm_dp_pixel_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x96059D02,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL1                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x2281ACAA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 30,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_spdm_dp_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x2FB132B7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL2                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_pixel2_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL2,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x90ADA722,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 40,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL3                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx0_pixel3_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX0PIXEL3,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x3CDE453F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 41,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1AUX                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx1_aux_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1AUX,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x6D9872D3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 37,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1CRYPTO                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx1_crypto_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1CRYPTO,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xED91D84E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 36,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1LINK                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx1_link_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1LINK,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xE606F341,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_LINK_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 33,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx1_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1LINK,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x21C6F43C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 34,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx1_usb_router_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1LINK,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x6BEEA021,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 35,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL0                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx1_pixel0_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xAA4B6A8F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 31,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL1                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_dptx1_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSDPTX1PIXEL1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x09170121,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 32,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC0                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_esc0_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x4002BDEB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_ESC0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 22,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC1                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_esc1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSESC1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xF074533F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_ESC1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 23,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_mdp1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x9587765D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_MDP1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 13,
    },
  },
#endif
  {
    .szName    = "mdss_0_disp_cc_mdss_mdp_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xCB3B5650,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_MDP_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 12,
    },
  },
#if 0
  {
    .szName    = "mdss_0_disp_cc_mdss_mdp_lut1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x7561776A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_MDP_LUT1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 15,
    },
  },
  #endif
  {
    .szName    = "mdss_0_disp_cc_mdss_mdp_lut_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x188BA153,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_MDP_LUT_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },
  #if 0
  {
    .szName    = "mdss_0_disp_cc_mdss_spdm_mdp_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x167E9944,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_MDP_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 48,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK0                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_pclk0_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xC68AE77C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_PCLK0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 10,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_spdm_pclk0_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK0,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x5A09BA4A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_PCLK0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 46,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK1                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_pclk1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x878FE07F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_PCLK1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_spdm_pclk1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSPCLK1,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x3429AD4A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_PCLK1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 47,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCMDSSVSYNC                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_rscc_vsync_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSVSYNC,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x7652E2E1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_RSCC_VSYNC_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_RSCC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 43,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_vsync1_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSVSYNC,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x04C414C4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_VSYNC1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_vsync_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCMDSSVSYNC,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0x68BFFED3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_VSYNC_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 16,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCPLLTESTMUX                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_pll_test_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCPLLTESTMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x951A1801,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCSLEEP                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_sleep_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCSLEEP,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xAF20C512,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_SLEEP_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 53,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCSMMUX                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_sm_obs_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCSMMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x4DFF0450,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_SM_OBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC0_MDSS0DISPCCXO                                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_0_disp_cc_mdss_pll_lock_monitor_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCXO,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xE4F77597,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 45,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_xo_clk",
    .pDomain   = &ClockDomain_DISPCC0_MDSS0DISPCCXO,
    .pDebugMux = &ClockDebugMux_DISPCC0,
    .nUniqueId = 0xFCD2ED0D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_ahb1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xF09D2D00,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 39,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x99B086B8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 38,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_non_gdsc_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xCD5973E5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 42,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_rscc_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSAHB,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x63ED9BA2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 44,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE0                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_byte0_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x501A95CC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_byte0_intf_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xFA9644F6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE1                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_byte1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xD626BB83,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_byte1_intf_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSBYTE1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xDE304951,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 21,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0AUX                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_aux_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0AUX,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x78CE1F4F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 28,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0CRYPTO                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_crypto_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0CRYPTO,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x4E9B204B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 27,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_spdm_dp_crypto_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0CRYPTO,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x55DF2407,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 49,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0LINK                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_link_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0LINK,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x373B294C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0LINK,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xAA8CC5C4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 25,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_usb_router_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0LINK,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x4B16379C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 26,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL0                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_pixel0_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xA9ADEE43,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 29,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_spdm_dp_pixel_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xAAACFD7D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL1                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x2263AF3A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 30,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_spdm_dp_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x4C94E794,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL2                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_pixel2_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL2,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xA615CB9F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 40,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL3                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx0_pixel3_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX0PIXEL3,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xB9DC9E0D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 41,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1AUX                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx1_aux_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1AUX,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x34C4FCCD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 37,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1CRYPTO                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx1_crypto_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1CRYPTO,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x07CEE874,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 36,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1LINK                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx1_link_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1LINK,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x1C7CC924,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 33,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx1_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1LINK,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x1285CB5D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 34,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx1_usb_router_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1LINK,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x178E706E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 35,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL0                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx1_pixel0_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x3083DC1C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 31,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL1                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_dptx1_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSDPTX1PIXEL1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x8BB993C0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 32,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC0                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_esc0_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x4511159E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 22,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC1                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_esc1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSESC1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xEAC55681,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 23,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_mdp1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x3691674A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 13,
    },
  },
  #endif
  {
    .szName    = "mdss_1_disp_cc_mdss_mdp_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x058AFF61,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 12,
    },
  },
  #if 0
  {
    .szName    = "mdss_1_disp_cc_mdss_mdp_lut1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x8C8D7C49,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 15,
    },
  },
  #endif
  {
    .szName    = "mdss_1_disp_cc_mdss_mdp_lut_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x1E4E00BE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },
  #if 0
  {
    .szName    = "mdss_1_disp_cc_mdss_spdm_mdp_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSMDP,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x928C07CC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 48,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK0                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_pclk0_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0xA932963B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 10,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_spdm_pclk0_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK0,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x3020C678,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 46,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK1                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_pclk1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x5192911C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_spdm_pclk1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSPCLK1,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x26E2FC61,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 47,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCMDSSVSYNC                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_rscc_vsync_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSVSYNC,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x3DECE23B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 43,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_vsync1_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSVSYNC,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x2799DF7B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_vsync_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCMDSSVSYNC,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x357FD0BA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 16,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCPLLTESTMUX                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_pll_test_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCPLLTESTMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x5FEF5BDB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCSLEEP                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_sleep_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCSLEEP,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x9CD79ACE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 53,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCSMMUX                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_sm_obs_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCSMMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x5FC9A0F4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC1_MDSS1DISPCCXO                                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "mdss_1_disp_cc_mdss_pll_lock_monitor_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCXO,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x6BE08713,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 45,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_xo_clk",
    .pDomain   = &ClockDomain_DISPCC1_MDSS1DISPCCXO,
    .pDebugMux = &ClockDebugMux_DISPCC1,
    .nUniqueId = 0x5A25BE58,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_CLOCKDRIVERGENXO                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_gpdsp_0_gpll0_main_clk_src",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xD9C18B63,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 360,
    },
  },
  {
    .szName    = "gcc_gpdsp_1_gpll0_main_clk_src",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x99CC7280,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 367,
    },
  },
  {
    .szName    = "gpu_cc_cb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x721C91D0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 46,
    },
  },
  {
    .szName    = "gpu_cc_cx_qdss_tsctr_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x403CC85F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 25,
    },
  },
  {
    .szName    = "gpu_cc_gx_qdss_tsctr_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x39A96FAC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 16,
    },
  },
  {
    .szName    = "turing_0_turing_cc_epcb_rx_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x74A4FA96,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 68,
    },
  },
  {
    .szName    = "turing_0_turing_cc_nspaux_accu_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x28C81678,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_ACCU_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  {
    .szName    = "turing_0_turing_cc_nspaux_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xD3A6B6C3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "turing_0_turing_cc_nspnoc_apb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xFEA6BF8D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPNOC_APB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 47,
    },
  },
  {
    .szName    = "turing_0_turing_cc_q6ss_llm_temp_ssc_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x2D5CF4D9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_LLM_TEMP_SSC_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 65,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_accu_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x65325C9A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_ACCU_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_apb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x0CD91156,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_APB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 40,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xB69512DA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },
  {
    .szName    = "turing_0_turing_cc_xo_cdiv_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x4FD5D546,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_XO_CDIV_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 22,
    },
  },
  #endif
  {
    .szName    = "turing_0_turing_cc_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x47D180C8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 21,
    },
  },
  #if 0
  {
    .szName    = "turing_0_turing_q6_cc_acd_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x367D03BE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_ACD_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 8,
    },
  },
  {
    .szName    = "turing_1_turing_cc_epcb_rx_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x2AFAB8AF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 68,
    },
  },
  {
    .szName    = "turing_1_turing_cc_nspaux_accu_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xBD70B056,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_ACCU_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  {
    .szName    = "turing_1_turing_cc_nspaux_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x143A2FF9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "turing_1_turing_cc_nspnoc_apb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xDCDAF5D9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPNOC_APB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 47,
    },
  },
  {
    .szName    = "turing_1_turing_cc_q6ss_llm_temp_ssc_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x3B6A55CD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_LLM_TEMP_SSC_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 65,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_accu_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xB8E96E9F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_ACCU_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_apb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xD9AAF700,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_APB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 40,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x9913955D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },
  {
    .szName    = "turing_1_turing_cc_xo_cdiv_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x93ED1778,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_XO_CDIV_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 22,
    },
  },
  #endif
  {
    .szName    = "turing_1_turing_cc_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xC45948F0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 21,
    },
  },
  #if 0
  {
    .szName    = "turing_1_turing_q6_cc_acd_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0x35D01C10,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_ACD_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 8,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0x91F94799,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_xo_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENXO,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0x2A4871DD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_gx_vsense_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x2DA8421F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 15,
    },
  },
  {
    .szName    = "gpu_cc_memnoc_gfx_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xEAA2A911,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 34,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0xDFB1C70F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "mdss_0_disp_cc_mdss_spdm_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0xE09C3C93,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_DEBUG_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0x9ACD202F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "mdss_1_disp_cc_mdss_spdm_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0xAFDFBF6C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR), HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  #endif
  {
    .szName    = "sail_to_md_gpucc_gpu_cc_ff_bcr",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0x6529CC76,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sail_to_md_gpucc_gpu_cc_gmu_bcr",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0x96EFF4D6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_acmu_mux0_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0x00B5D4E4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU_MUX0_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_acmu_mux1_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0x2FE5E254,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU_MUX1_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0x91C8B327,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_spdm_debug_cy_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0xB451B664,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_DEBUG_CY_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "turing_0_turing_cc_ceng_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xE6AD5D1E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_CENG_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 43,
    },
  },
  #if 0
  {
    .szName    = "turing_0_turing_cc_nspnoc_atb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x17DC37E8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPNOC_ATB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 46,
    },
  },
  {
    .szName    = "turing_0_turing_cc_nspnoc_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x20C8B4A3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPNOC_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 44,
    },
  },
  {
    .szName    = "turing_0_turing_cc_q6ss_llm_curr_ssc_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x9249AED5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_LLM_CURR_SSC_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 66,
    },
  },
  #endif
  {
    .szName    = "turing_0_turing_cc_q6ss_q6_axim_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x34B122D8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_Q6_AXIM_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 56,
    },
  },
  #if 0
  {
    .szName    = "turing_0_turing_cc_vapss_atb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x186EC7D7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_ATB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 39,
    },
  },
  {
    .szName    = "turing_0_turing_q6_cc_acd_ahbs_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0xE2DB9D04,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_ACD_AHBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 10,
    },
  },
  {
    .szName    = "turing_0_turing_q6_cc_pll_ahbs_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x7DD0C950,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_PLL_AHBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 9,
    },
  },
  #endif
  {
    .szName    = "turing_1_turing_cc_ceng_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x5292680D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_CENG_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 43,
    },
  },
  #if 0
  {
    .szName    = "turing_1_turing_cc_nspnoc_atb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x5DB52266,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPNOC_ATB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 46,
    },
  },
  {
    .szName    = "turing_1_turing_cc_nspnoc_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x800805F6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPNOC_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 44,
    },
  },
  {
    .szName    = "turing_1_turing_cc_q6ss_llm_curr_ssc_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xBD50BDC3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_LLM_CURR_SSC_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 66,
    },
  },
  #endif
  {
    .szName    = "turing_1_turing_cc_q6ss_q6_axim_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x68EB6C88,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_Q6_AXIM_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 56,
    },
  },
  #if 0
  {
    .szName    = "turing_1_turing_cc_vapss_atb_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xB6E1F557,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_ATB_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 39,
    },
  },
  {
    .szName    = "turing_1_turing_q6_cc_acd_ahbs_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0x14B4F1DE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_ACD_AHBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 10,
    },
  },
  {
    .szName    = "turing_1_turing_q6_cc_pll_ahbs_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0x2E8D2E74,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_PLL_AHBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 9,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_q6ss_q6_axim_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0x54A4D290,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_Q6_AXIM_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 1,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_q6ss_q6_axim_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0x5B2A232C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_Q6_AXIM_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 1,
    },
  },
  {
    .szName    = "video_cc_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .pDebugMux = NULL,
    .nUniqueId = 0x9AD7014D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCAGGRENOC                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac0_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCD60335C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 516,
    },
  },
  {
    .szName    = "gcc_emac1_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x41C516DF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 525,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCAGGRENOCPCIESF                                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_aggre_noc_pcie_tbu_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x523BCBA7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_PCIE_TBU_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMU3_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_4), 0x8} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 88,
    },
  },
  {
    .szName    = "gcc_aggre_noc_pcie_tcu_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x4CC30072,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_PCIE_TCU_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMU3_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_4), 0x800} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 89,
    },
  },
  #if 0
  {
    .szName    = "gcc_ddrss_pcie_sf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x1EE37723,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_PCIE_SF_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE), 0x80000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 320,
    },
  },
  #endif
  {
    .szName    = "gcc_pcie_0_mstr_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x6ECCBB13,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_MSTR_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_2), 0x800} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 405,
    },
  },
  {
    .szName    = "gcc_pcie_1_mstr_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xD8A72CC2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_MSTR_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_1), 0x2} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 392,
    },
  },
  {
    .szName    = "gcc_pcie_tbu_bwmon_clk",
    .pDomain   = &ClockDomain_GCC_GCCAGGRENOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x11CA1EB4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_TBU_BWMON_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMU3_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_4), 0x2000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 90,
    },
  },
#if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCCNOCCENTERQX                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_tcu3_cfg_qx_clk",
    .pDomain   = &ClockDomain_GCC_GCCCNOCCENTERQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x406247FD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TCU3_CFG_QX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMU3_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 87,
    },
  },
  {
    .szName    = "gcc_tcu_cfg_qx_clk",
    .pDomain   = &ClockDomain_GCC_GCCCNOCCENTERQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x634A069D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TCU_CFG_QX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 84,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCCNOCPERIPH                                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac0_slv_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCNOCPERIPH,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xFB1E933B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_SLV_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 517,
    },
  },
  {
    .szName    = "gcc_emac1_slv_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCNOCPERIPH,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x769082CD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_SLV_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 526,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCCONFIGNOC                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_aggre_noc_throttle_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xE785F64B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_THROTTLE_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_ANOC_TBU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 96,
    },
  },
  #endif
  {
    .szName    = "gcc_camera_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCB81AAEC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 131,
    },
  },
  #if 0
  {
    .szName    = "gcc_ddrss_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x061D8289,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_CFG_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 324,
    },
  },
  #endif
  {
    .szName    = "gcc_disp1_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x544434D3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DISP1_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 147,
    },
  },
  {
    .szName    = "gcc_disp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCC324D48,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DISP_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 141,
    },
  },
  #if 0
  {
    .szName    = "gcc_gpdsp_0_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xB835D7DF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_0_CFG_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 356,
    },
  },
  {
    .szName    = "gcc_gpdsp_0_throttle_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xAACB506E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_0_THROTTLE_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 357,
    },
  },
  {
    .szName    = "gcc_gpdsp_1_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xFA8EFB0F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_1_CFG_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 363,
    },
  },
  {
    .szName    = "gcc_gpdsp_1_throttle_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x8577FDFE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_1_THROTTLE_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 364,
    },
  },
#endif
  {
    .szName    = "gcc_gpu_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xBDC5D904,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPU_CFG_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 499,
    },
  },
  {
    .szName    = "gcc_mmnoc_hf_ahb_cfg_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xE1A6F11E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_HF_AHB_CFG_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 103,
    },
  },
  {
    .szName    = "gcc_mmnoc_sf_ahb_cfg_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x56FB62D9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_SF_AHB_CFG_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 104,
    },
  },
  {
    .szName    = "gcc_pcie_0_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xAB33D8F8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_CFG_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_2), 0x1000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 406,
    },
  },
  {
    .szName    = "gcc_pcie_1_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xB6E6F09E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_CFG_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_1), 0x4} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 393,
    },
  },
  #if 0
  {
    .szName    = "gcc_pcie_tcu_throttle_cfg_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x01597D66,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_TCU_THROTTLE_CFG_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMU3_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_4), 0x4000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 91,
    },
  },
  {
    .szName    = "gcc_qmip_camera_nrt_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x5508D425,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_CAMERA_NRT_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 132,
    },
  },
  {
    .szName    = "gcc_qmip_camera_rt_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x15F7C6F4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_CAMERA_RT_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 133,
    },
  },
  {
    .szName    = "gcc_qmip_disp1_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xB5FBD1D3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_DISP1_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 148,
    },
  },
  {
    .szName    = "gcc_qmip_disp1_rot_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xC5C89A97,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_DISP1_ROT_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 149,
    },
  },
  {
    .szName    = "gcc_qmip_disp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x2FE1361E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_DISP_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 142,
    },
  },
  {
    .szName    = "gcc_qmip_disp_rot_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x26BFD970,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_DISP_ROT_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 143,
    },
  },
  #endif
  {
    .szName    = "gcc_qmip_video_cvp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x5577C832,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_VIDEO_CVP_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 156,
    },
  },
    #if 0
  {
    .szName    = "gcc_qmip_video_vcodec_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xED09B49D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_VIDEO_VCODEC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 157,
    },
  },
  {
    .szName    = "gcc_qmip_video_vcpu_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xF73DA3D4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_QMIP_VIDEO_VCPU_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 158,
    },
  },
  #endif
  {
    .szName    = "gcc_turing_0_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x5182D289,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_0_CFG_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 341,
    },
  },
    #if 0
  {
    .szName    = "gcc_turing_0_throttle_nsp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x4CACA254,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_0_THROTTLE_NSP_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 342,
    },
  },
  #endif
  {
    .szName    = "gcc_turing_1_cfg_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x52F35756,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_1_CFG_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 349,
    },
  },
    #if 0
  {
    .szName    = "gcc_turing_1_throttle_nsp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xA2381CF6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_1_THROTTLE_NSP_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 350,
    },
  },
  #endif
  {
    .szName    = "gcc_video_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x3DC15104,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 155,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCCONFIGNOCDDRSSSF                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_ddrss_config_noc_sf_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOCDDRSSSF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x898AADD0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_CONFIG_NOC_SF_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 323,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCCONFIGNOCPCIESF                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_0_slv_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x9331B3EF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_SLV_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_2), 0x400} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 404,
    },
  },
    #if 0
  {
    .szName    = "gcc_pcie_0_slv_q2a_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x5B161349,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_SLV_Q2A_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_3), 0x1000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 403,
    },
  },
  #endif
  {
    .szName    = "gcc_pcie_1_slv_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xAA65C59A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_SLV_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_1), 0x1} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 391,
    },
  },
    #if 0
  {
    .szName    = "gcc_pcie_1_slv_q2a_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOCPCIESF,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x5F52BA5E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_SLV_Q2A_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_1), 0x20} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 390,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCEMAC0PHYAUX                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac0_phy_aux_clk",
    .pDomain   = &ClockDomain_GCC_GCCEMAC0PHYAUX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x85203CAB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_PHY_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 518,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCEMAC0PTP                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac0_ptp_clk",
    .pDomain   = &ClockDomain_GCC_GCCEMAC0PTP,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x806A4C5B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_PTP_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 519,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCEMAC0RGMII                                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac0_rgmii_clk",
    .pDomain   = &ClockDomain_GCC_GCCEMAC0RGMII,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x81EAC006,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_RGMII_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 520,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCEMAC1PHYAUX                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac1_phy_aux_clk",
    .pDomain   = &ClockDomain_GCC_GCCEMAC1PHYAUX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x0E517E28,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_PHY_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 527,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCEMAC1PTP                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac1_ptp_clk",
    .pDomain   = &ClockDomain_GCC_GCCEMAC1PTP,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xFC3592EC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_PTP_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 528,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCEMAC1RGMII                                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_emac1_rgmii_clk",
    .pDomain   = &ClockDomain_GCC_GCCEMAC1RGMII,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x11953840,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_RGMII_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 529,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCGPDSP0Q6AXI                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_aggre_noc_gpdsp_0_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCGPDSP0Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xB354E2EB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_GPDSP_0_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 355,
    },
  },
  {
    .szName    = "gcc_gpdsp_0_q6_axi_acgc_clk_src",
    .pDomain   = &ClockDomain_GCC_GCCGPDSP0Q6AXI,
    .pDebugMux = NULL,
    .nUniqueId = 0xA9F4B335,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "gcc_gpdsp_0_q6_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCGPDSP0Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x265FA206,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_0_Q6_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 354,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCGPDSP1Q6AXI                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_aggre_noc_gpdsp_1_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCGPDSP1Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xE9DA16F3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_GPDSP_1_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 362,
    },
  },
  {
    .szName    = "gcc_gpdsp_1_q6_axi_acgc_clk_src",
    .pDomain   = &ClockDomain_GCC_GCCGPDSP1Q6AXI,
    .pDebugMux = NULL,
    .nUniqueId = 0x64ACD995,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "gcc_gpdsp_1_q6_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCGPDSP1Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x98EF631A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPDSP_1_Q6_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 361,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCGPUMEMNOCGFX                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_gpu_memnoc_gfx_clk",
    .pDomain   = &ClockDomain_GCC_GCCGPUMEMNOCGFX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x114959A4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_GPU_MEMNOC_GFX_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 503,
    },
  },
    #if 0
  {
    .szName    = "gpu_cc_cx_snoc_dvm_clk",
    .pDomain   = &ClockDomain_GCC_GCCGPUMEMNOCGFX,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xB73879BC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 27,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCLBIST                                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_lbist_clk",
    .pDomain   = &ClockDomain_GCC_GCCLBIST,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x567C9315,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_LBIST_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_LBIST_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 563,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCMEMNOC                                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_memnoc_clk",
    .pDomain   = &ClockDomain_GCC_GCCMEMNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xA2D3B0E7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MEMNOC_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 325,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCMMNOCHFQX                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_camera_hf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x62191536,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_HF_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 134,
    },
  },
    #if 0
  {
    .szName    = "gcc_ddrss_mmnoc_hf_qx_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x59DCABC0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_MMNOC_HF_QX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 314,
    },
  },
  #endif
  {
    .szName    = "gcc_disp1_hf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xE81D031D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DISP1_HF_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 150,
    },
  },
  {
    .szName    = "gcc_disp_hf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xBF311160,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DISP_HF_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 144,
    },
  },
  {
    .szName    = "gcc_mmnoc_hf_qx_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xE67A5480,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_HF_QX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 111,
    },
  },

  {
    .szName    = "gcc_mmnoc_ip_hf_qx_acgc_clk_src",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = NULL,
    .nUniqueId = 0x61A1B546,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "gcc_mmnoc_ip_hf_qx_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x813215C2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_IP_HF_QX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 110,
    },
  },

  {
    .szName    = "gcc_mmnoc_tbu_camera_hf4_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x0B98DFB8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_TBU_CAMERA_HF4_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 118,
    },
  },
  {
    .szName    = "gcc_mmnoc_tbu_disp1_hf2_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xD10F2CB0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_TBU_DISP1_HF2_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 116,
    },
  },
  {
    .szName    = "gcc_mmnoc_tbu_disp1_hf3_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x6183971C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_TBU_DISP1_HF3_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 117,
    },
  },
  {
    .szName    = "gcc_mmnoc_tbu_hf0_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x4EC02329,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_TBU_HF0_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 99,
    },
  },
  {
    .szName    = "gcc_mmnoc_tbu_hf1_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x8D7ECE57,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_TBU_HF1_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 100,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCMMNOCSFQX                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_camera_sf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x033685A3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_SF_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 136,
    },
  },
    #if 0
  {
    .szName    = "gcc_ddrss_mmnoc_sf_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCD208810,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_MMNOC_SF_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 313,
    },
  },
  #endif
  {
    .szName    = "gcc_mmnoc_sf_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x528C2F1D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_SF_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 112,
    },
  },
    #if 0
  {
    .szName    = "gcc_mmnoc_sf_qx_acgc_clk_src",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = NULL,
    .nUniqueId = 0x810B0B0C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  #endif
  {
    .szName    = "gcc_mmnoc_tbu_sf0_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x92FB3EA0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_TBU_SF0_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 114,
    },
  },
  {
    .szName    = "gcc_mmnoc_tbu_sf1_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xB0C9D820,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_TBU_SF1_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 115,
    },
  },
  {
    .szName    = "gcc_video_axi0_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x527C9897,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_AXI0_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 159,
    },
  },
  {
    .szName    = "gcc_video_axi1_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x4F8C5CD6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_AXI1_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 160,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCMMUTCU                                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_ddrss_tcu_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMUTCU,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x7D45F907,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_TCU_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 315,
    },
  },
  {
    .szName    = "gcc_mmu_tcu_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMUTCU,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xFAB09BDC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMU_TCU_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 85,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE0AUX                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_0_aux_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE0AUX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xDE4195A6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_2), 0x10000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 408,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE0PHYAUX                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_0_phy_aux_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE0PHYAUX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xF12E95DE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_PHY_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_2), 0x2000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 407,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE0PHYRCHNG                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_0_phy_rchng_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE0PHYRCHNG,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x4F8DB026,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_PHY_RCHNG_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_2), 0x8000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 411,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE0PIPE                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_0_pipe_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE0PIPE,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xDCB72BF8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_PIPE_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_2), 0x4000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 409,
    },
  },
    #if 0
  {
    .szName    = "gcc_pcie_0_pipediv2_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE0PIPE,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x558C2260,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_PIPEDIV2_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_3), 0x400000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 410,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE1AUX                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_1_aux_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE1AUX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xBC6B4728,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE), 0x80000000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 395,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE1PHYAUX                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_1_phy_aux_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE1PHYAUX,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xF23222AB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_PHY_AUX_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_1), 0x8} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 394,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE1PHYRCHNG                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_1_phy_rchng_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE1PHYRCHNG,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCA529D26,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_PHY_RCHNG_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE), 0x400000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 398,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCPCIE1PIPE                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_pcie_1_pipe_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE1PIPE,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xB60CB671,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_PIPE_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_1), 0x10} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 396,
    },
  },
    #if 0
  {
    .szName    = "gcc_pcie_1_pipediv2_clk",
    .pDomain   = &ClockDomain_GCC_GCCPCIE1PIPE,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xC1D235F6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_PIPEDIV2_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_3), 0x10000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 397,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCQDSSAPBTSCTR                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_mmnoc_hf_tsctr_clk",
    .pDomain   = &ClockDomain_GCC_GCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xC594B62D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_HF_TSCTR_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 108,
    },
  },
  {
    .szName    = "gcc_mmnoc_sf_tsctr_clk",
    .pDomain   = &ClockDomain_GCC_GCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xB9282DD5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_SF_TSCTR_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 109,
    },
  },
  {
    .szName    = "gpu_cc_cx_apb_clk",
    .pDomain   = &ClockDomain_GCC_GCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x6E5557EC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 26,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCQDSSATBB                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_cx_qdss_at_clk",
    .pDomain   = &ClockDomain_GCC_GCCQDSSATBB,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x3A64CC97,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCQDSSTRIG                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_cx_qdss_trig_clk",
    .pDomain   = &ClockDomain_GCC_GCCQDSSTRIG,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x046DFEBA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 29,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCSAILAXI                                            */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_aggre_noc_sail_tbu_clk",
    .pDomain   = &ClockDomain_GCC_GCCSAILAXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x74B8A032,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_SAIL_TBU_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_SAIL_TBU_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE_4), 0x10000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 98,
    },
  },
  #endif
  {
    .szName    = "gcc_memnoc_sailss_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCSAILAXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xA9E01FEB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MEMNOC_SAILSS_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {HWIO_ADDR(GCC_PROC_CLK_BRANCH_ENA_VOTE), 0x40000} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 319,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCSAILSHSAPB                                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_sail_shs_sys_apb_clk",
    .pDomain   = &ClockDomain_GCC_GCCSAILSHSAPB,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x2EC63491,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_SAIL_SHS_SYS_APB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_SHS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 401,
    },
  },
  {
    .szName    = "gcc_shs_apb_clk",
    .pDomain   = &ClockDomain_GCC_GCCSAILSHSAPB,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x0C7221C5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_SHS_APB_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_SHS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 402,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCSHRM                                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_shrm_clk",
    .pDomain   = &ClockDomain_GCC_GCCSHRM,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xEF2E9801,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_SHRM_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 327,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCSLEEP                                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_sleep_clk",
    .pDomain   = &ClockDomain_GCC_GCCSLEEP,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xC2E1C465,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 28,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCSYSNOC                                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_aggre_noc_tbu1_clk",
    .pDomain   = &ClockDomain_GCC_GCCSYSNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCBBA4548,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_TBU1_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_ANOC_TBU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 94,
    },
  },
  {
    .szName    = "gcc_aggre_noc_tbu2_clk",
    .pDomain   = &ClockDomain_GCC_GCCSYSNOC,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x4E307B0E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_TBU2_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_ANOC_TBU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 95,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCSYSNOCGCAXI                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_ddrss_sys_noc_gc_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCSYSNOCGCAXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x0ABE8689,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_SYS_NOC_GC_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 321,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCSYSNOCSFAXI                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_aggre_noc_audio_tbu_clk",
    .pDomain   = &ClockDomain_GCC_GCCSYSNOCSFAXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCA0F2BFC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_AGGRE_NOC_AUDIO_TBU_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_LPASS_TBU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 97,
    },
  },
  {
    .szName    = "gcc_ddrss_sys_noc_sf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCSYSNOCSFAXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xCBACEECA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_SYS_NOC_SF_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 322,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCTURING0Q6AXI                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_ddrss_turing_0_q6_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING0Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x18F48C18,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_TURING_0_Q6_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 316,
    },
  },
  #endif
  {
    .szName    = "gcc_turing_0_q6_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING0Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xF5A093DC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_0_Q6_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 340,
    },
  },
  {
    .szName    = "gcc_turing_0_q6_tbu0_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING0Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x03E6ED9F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_0_Q6_TBU0_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 338,
    },
  },
  {
    .szName    = "gcc_turing_0_q6_tbu1_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING0Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x39D79120,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_0_Q6_TBU1_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 339,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCTURING1Q6AXI                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_ddrss_turing_1_q6_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING1Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xDCBDEE06,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_TURING_1_Q6_AXI_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DDRSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 317,
    },
  },
  #endif
  {
    .szName    = "gcc_turing_1_q6_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING1Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x91B0C55F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_1_Q6_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 348,
    },
  },
  {
    .szName    = "gcc_turing_1_q6_tbu2_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING1Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xA629AB7D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_1_Q6_TBU2_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 346,
    },
  },
  {
    .szName    = "gcc_turing_1_q6_tbu3_clk",
    .pDomain   = &ClockDomain_GCC_GCCTURING1Q6AXI,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x664F9EC1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_TURING_1_Q6_TBU3_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 347,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCXO                                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_camera_throttle_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x9B4ACBCF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_THROTTLE_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 139,
    },
  },
  {
    .szName    = "gcc_camera_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xEF993118,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_CAMERA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 138,
    },
  },
  {
    .szName    = "gcc_disp1_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xC20C8DE5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DISP1_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 151,
    },
  },
  {
    .szName    = "gcc_disp_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x9A471C5C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_DISP_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_DISPLAY_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 145,
    },
  },
  {
    .szName    = "gcc_mmnoc_qosgen_extref_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x296C7BD3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_QOSGEN_EXTREF_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 113,
    },
  },
  {
    .szName    = "gcc_noc_mmnoc_dcd_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0xBCD5903A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_NOC_MMNOC_DCD_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 105,
    },
  },
  {
    .szName    = "gcc_noc_mmnoc_hf_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x993A43F0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_NOC_MMNOC_HF_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 107,
    },
  },
  {
    .szName    = "gcc_noc_mmnoc_sf_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x6F1DE6E7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_NOC_MMNOC_SF_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 106,
    },
  },
  {
    .szName    = "gcc_video_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .pDebugMux = &ClockDebugMux_GCC,
    .nUniqueId = 0x79581D18,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_XO_CBCR), HWIO_ADDR(SAIL_TO_MD_GCC_VIDEO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 161,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCDEBUGMUX                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_debug_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x2D49728D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "gpu_cc_debug_measure_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x61D27566,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCFF                                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_cx_ff_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCFF,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x276A4142,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 33,
    },
  },
  {
    .szName    = "gpu_cc_gx_ff_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCFF,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xD12CF765,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCGMU                                            */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_cx_gmu_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGMU,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x85040864,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 30,
    },
  },
    #if 0
  {
    .szName    = "gpu_cc_gx_gmu_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGMU,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xFD46B6AB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCGXGFX3D                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_cx_gfx3d_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGXGFX3D,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x2B627FA6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 37,
    },
  },
  {
    .szName    = "gpu_cc_cx_gfx3d_slv_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGXGFX3D,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xD96DA83B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 38,
    },
  },
  #endif
  {
    .szName    = "gpu_cc_gx_gfx3d_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGXGFX3D,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x40E4E782,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },
    #if 0
  {
    .szName    = "gpu_cc_gx_gfx3d_rdvm_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGXGFX3D,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x14588D9F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 21,
    },
  },
  {
    .szName    = "gpu_cc_mnd1x_1_gfx3d_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGXGFX3D,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x999671BB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 42,
    },
  },
  {
    .szName    = "gpu_cc_spdm_gx_gfx3d_div_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCGXGFX3D,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xFB0C5507,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 43,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCHUB                                            */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_acd_ahb_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCHUB,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xD8CEEBD9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 45,
    },
  },
  {
    .szName    = "gpu_cc_ahb_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCHUB,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x763BA1C4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 22,
    },
  },
  {
    .szName    = "gpu_cc_crc_ahb_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCHUB,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xACF3D523,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 23,
    },
  },
  {
    .szName    = "gpu_cc_hub_aon_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCHUB,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x063271D7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 47,
    },
  },
  {
    .szName    = "gpu_cc_hub_cx_int_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCHUB,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xC00F7891,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 32,
    },
  },
  {
    .szName    = "gpu_cc_rbcpr_ahb_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCHUB,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x08747E3D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 40,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCPLLTESTMUX                                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_pll_test_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCPLLTESTMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x8F8278F9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCRBCPR                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_rbcpr_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCRBCPR,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x60C9F321,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 39,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCSMMUX                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_sm_cmu_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCSMMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x3E08204D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GPUCC_GPUCCXO                                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gpu_cc_acd_cxo_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xFB4F06FB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 44,
    },
  },
  {
    .szName    = "gpu_cc_cxo_aon_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xA006B60F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
  {
    .szName    = "gpu_cc_cxo_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x8DFA73CF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 31,
    },
  },
  {
    .szName    = "gpu_cc_demet_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x2217FC16,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 13,
    },
  },
  {
    .szName    = "gpu_cc_freq_measure_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0xC306597F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 12,
    },
  },
  {
    .szName    = "gpu_cc_gx_cxo_clk",
    .pDomain   = &ClockDomain_GPUCC_GPUCCXO,
    .pDebugMux = &ClockDebugMux_GPUCC,
    .nUniqueId = 0x28DEB84B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR), HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCACC                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_sec_ctrl_acc_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCACC,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x94C9F132,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_ACC_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 86,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCACMU0CORE                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_acmu0_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCACMU0CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x51E5BE70,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 154,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCACMU0RO                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_acmu0_ro_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCACMU0RO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x549ED216,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_RO_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 153,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCACMU1CORE                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_acmu1_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCACMU1CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x8F5F7B76,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 157,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCACMU1RO                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_acmu1_ro_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCACMU1RO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x19B9E399,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_RO_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 156,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asilb_noc_partial_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x2DC5CE57,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 12,
    },
  },
  {
    .szName    = "sailss_cc_asilb_noc_qx_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x97560846,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_QX_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 10,
    },
  },
  {
    .szName    = "sailss_cc_asild_data_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x1D526C0D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_DATA_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },
  {
    .szName    = "sailss_cc_ce1_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC3443B34,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CE1_AXI_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CE1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 97,
    },
  },
  {
    .szName    = "sailss_cc_emac0_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x67A7BAB9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_AXI_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 141,
    },
  },
  {
    .szName    = "sailss_cc_emac0_axi_pipe_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE2D6232D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_AXI_PIPE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 145,
    },
  },
  {
    .szName    = "sailss_cc_md2sail_tic_bdg_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x4CECF921,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_MD2SAIL_TIC_BDG_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },
  {
    .szName    = "sailss_cc_qdss_etr_ddr_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x5696C38D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_ETR_DDR_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 35,
    },
  },
  {
    .szName    = "sailss_cc_spdm_asilb_noc_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x69319F89,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_ASILB_NOC_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 93,
    },
  },
  {
    .szName    = "sailss_cc_tic_cfg_qx_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBNOCQX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x842B5B85,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TIC_CFG_QX_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 28,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCASILBQSPIQH                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asilb_noc_qspi_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBQSPIQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x50DE37D7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_QSPI_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
  {
    .szName    = "sailss_cc_qspi_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILBQSPIQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x19EF08ED,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QSPI_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 139,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asild_noc_dma_apb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xAEF48DD5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_DMA_APB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 26,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_dma_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x5B25FFE7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_DMA_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 23,
    },
  },
  {
    .szName    = "sailss_cc_dma_apb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x44F304FF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DMA_APB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DMA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 183,
    },
  },
  {
    .szName    = "sailss_cc_dma_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCDMA,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xF3F0BF55,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DMA_AXI_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DMA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 182,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asild_noc_qup_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x251AAC72,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_QUP_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },
  {
    .szName    = "sailss_cc_lpm_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x4BE39C72,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LPM_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PRAM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 30,
    },
  },
  {
    .szName    = "sailss_cc_lpm_pram_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x2CFF3468,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PRAM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 29,
    },
  },
  {
    .szName    = "sailss_cc_qupv3_wrap0_m_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x6096D90E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_M_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 45,
    },
  },
  {
    .szName    = "sailss_cc_qupv3_wrap0_s_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCASILDNOCQUP,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD9B96273,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 46,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD782E90B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 103,
    },
  },
  {
    .szName    = "sailss_cc_aodap_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x796DA852,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_AODAP_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 188,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_bmtx_qh_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xF1085DD5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_BMTX_QH_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 27,
    },
  },
  {
    .szName    = "sailss_cc_bmtx_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC7B17499,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_BMTX_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 102,
    },
  },
  {
    .szName    = "sailss_cc_cx_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE83EB7F1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CX_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 101,
    },
  },
  {
    .szName    = "sailss_cc_pwr_ctrl_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCBMTXNOCQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xAC4CDBF8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 82,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN0CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can0_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN0CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x3DDE6242,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN0_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 55,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN1CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can1_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN1CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xADB698B4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN1_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 57,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN2CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can2_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN2CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x7A9B8EDA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN2_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 59,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN3CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can3_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN3CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x76966011,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN3_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 61,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN4CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can4_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN4CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x2A86A3F0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN4_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 63,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN5CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can5_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN5CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0E0C8A43,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN5_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 65,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN6CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can6_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN6CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0952EA20,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN6_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 67,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCAN7CORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_can7_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCAN7CORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xFB64D93B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN7_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 69,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCE1                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_ce1_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCE1,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x67C32BD2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CE1_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CE1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 96,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCCPUCORE                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asild_noc_cpu_qx_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x5FB06119,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_CPU_QX_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_partial_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x22C7E57D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 21,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_apb_cbc_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC915333B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_APB_CBC_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 116,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_apb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0xE355D209,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_atbd_cbc_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xDAADAB53,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_ATBD_CBC_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 114,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_atbd_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0x502D6AE9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_atbi_cbc_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE19BE97E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_ATBI_CBC_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 115,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_atbi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0x88BFB7A2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0xC376034C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x6794755B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 108,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_cnt_cbc_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xF0AFC648,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CNT_CBC_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 113,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_cnt_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0x61E07B6D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster0_ph2_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xFCFFB2AC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_PH2_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 118,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster1_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE6EFDEBA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 109,
    },
  },
  {
    .szName    = "sailss_cc_cpu_cluster1_ph2_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xCD00C408,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_PH2_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 119,
    },
  },
  {
    .szName    = "sailss_cc_spdm_cpu_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD3483752,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_CPU_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 95,
    },
  },
  {
    .szName    = "sailss_cc_sram0_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x779EB37E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SRAM0_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 159,
    },
  },
  {
    .szName    = "sailss_cc_sram1_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x65D5286B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SRAM1_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 160,
    },
  },
  {
    .szName    = "sailss_cc_sram2_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0D9F9830,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SRAM2_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 161,
    },
  },
  {
    .szName    = "sailss_cc_sram3_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0AD5F8FC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SRAM3_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 162,
    },
  },
  {
    .szName    = "sailss_cc_sram4_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x96A18479,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SRAM4_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 163,
    },
  },
  {
    .szName    = "sailss_cc_sram5_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCCPUCORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x33DD358D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SRAM5_AXI_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 164,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCEMAC0PTP                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_emac0_ptp_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCEMAC0PTP,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x1FCA7C40,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_PTP_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 143,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCEMAC0RGMII                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_emac0_rgmii_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCEMAC0RGMII,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x2CC8BBAF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_RGMII_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 144,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCERROR                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_error_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCERROR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x12195398,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ERROR_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 181,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCGP1                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_gp1_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCGP1,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE1FC2CB0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP1_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 123,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCGP2                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_gp2_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCGP2,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xAE86A1C8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP2_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 124,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCGP3                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_gp3_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCGP3,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x47EB0C67,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP3_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 125,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCGP4                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_gp4_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCGP4,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xACBEC6E0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP4_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 126,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCGP5                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_gp5_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCGP5,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x8DA89ACC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_GP5_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 127,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCHWKMKM                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_hwkm_km_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCHWKMKM,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC09B1FC9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HWKM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 73,
    },
  },
  {
    .szName    = "sailss_cc_hwkm_km_keytable_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCHWKMKM,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x70548D89,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_KEYTABLE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HWKM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 74,
    },
  },
  {
    .szName    = "sailss_cc_sec_ctrl_hwkm_km_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCHWKMKM,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x78DF8254,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_HWKM_KM_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 91,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCLBIST                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_hbcu_wrck_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCLBIST,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xA46F7A6A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HBCU_WRCK_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 146,
    },
  },
  {
    .szName    = "sailss_cc_lbist0_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCLBIST,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0F0F23FD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST0_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 147,
    },
  },
  {
    .szName    = "sailss_cc_lbist1_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCLBIST,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC9892A9B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST1_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 148,
    },
  },
  {
    .szName    = "sailss_cc_lbist2_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCLBIST,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x4D576945,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST2_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 149,
    },
  },
  {
    .szName    = "sailss_cc_lbist3_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCLBIST,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE9587810,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST3_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_LBIST_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 150,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCPKACORE                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_pka_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCPKACORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0BE69118,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PKA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 71,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCPLLTESTMUX                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_pll_test_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCPLLTESTMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x93EB531A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCPWRCTRLXO                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_demet_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCPWRCTRLXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xB4268676,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 84,
    },
  },
  {
    .szName    = "sailss_cc_pwr_ctrl_xo_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCPWRCTRLXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x616AE08E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 83,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_apb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x22E91D41,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_APB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 41,
    },
  },
  {
    .szName    = "sailss_cc_asilb_noc_apb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD643468C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 7,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_tsctr_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xCCC3A412,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_TSCTR_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  {
    .szName    = "sailss_cc_qdss_dap_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x333C10C8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 40,
    },
  },
  {
    .szName    = "sailss_cc_qdss_tsctr_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x16422D39,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_TSCTR_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 38,
    },
  },
  {
    .szName    = "sailss_cc_swao_apb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSAPBTSCTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC000276F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 42,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQDSSATBA                                 */
  /*-----------------------------------------------------------------------*/

  /*
   * Fake clock added with domain name since there are no actual branches
   * on the domain. Used to control frequency.
   */
  {
    .szName    = "sailss_cc_qdss_atb_a_clk_src",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSATBA,
    .pDebugMux = NULL,
    .nUniqueId = 0xFC8AB673,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = NULL,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQDSSATBB                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asilb_noc_atb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSATBB,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x447CD797,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_ATB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 6,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_atb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSATBB,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xB0B56D17,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_ATB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "sailss_cc_at_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSATBB,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC0B736CD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_AT_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 100,
    },
  },
  {
    .szName    = "sailss_cc_qdss_at_bdg_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSATBB,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x53231E73,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_AT_BDG_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 44,
    },
  },
  {
    .szName    = "sailss_cc_qdss_center_at_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSATBB,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x13DE216B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_CENTER_AT_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 33,
    },
  },
  {
    .szName    = "sailss_cc_swao_at_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSATBB,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x4D70DFEF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_AT_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 34,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQDSSTRACECLKIN                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qdss_traceclkin_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSTRACECLKIN,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x7788DF59,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_TRACECLKIN_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 37,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQDSSTRIG                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qdss_trig_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQDSSTRIG,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x7A7C40DC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_TRIG_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 39,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQSPICORE                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qspi_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQSPICORE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0D20E757,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QSPI_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 140,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qupv3_wrap0_core_2x_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x4FBB0196,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_CORE_2X_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 48,
    },
  },
  {
    .szName    = "sailss_cc_qupv3_wrap0_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0CORE2X,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xB4E0F2EF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 47,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S0                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qupv3_wrap0_s0_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S0,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x9FFC5FED,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S0_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 49,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S1                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qupv3_wrap0_s1_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S1,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x022E236C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S1_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S2                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qupv3_wrap0_s2_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S2,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x33FEDB0A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S2_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S3                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qupv3_wrap0_s3_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S3,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x32DED14E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S3_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S4                             */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_qupv3_wrap0_s4_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCQUPV3WRAP0S4,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x6F65DF58,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAP0_S4_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QUPV3_WRAPPER_0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 53,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCRBCPRCX                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_rbcpr_cx_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCRBCPRCX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x21E7575F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_RBCPR_CX_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_RBCPR_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 120,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_acmu0_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xAE8A05A0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 155,
    },
  },
  {
    .szName    = "sailss_cc_acmu1_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x9B660CCB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ACMU1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 158,
    },
  },
  {
    .szName    = "sailss_cc_asilb_noc_qh_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xEB63F7B8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_QH_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 8,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_qh_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x595423B5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_QH_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 15,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_wdt_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xCAD75CDD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_WDT_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 22,
    },
  },
  {
    .szName    = "sailss_cc_boot_rom_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x24E2FCA5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_BOOT_ROM_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 81,
    },
  },
  {
    .szName    = "sailss_cc_can0_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x23DEBC67,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN0_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 54,
    },
  },
  {
    .szName    = "sailss_cc_can1_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x8325AC5B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN1_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 56,
    },
  },
  {
    .szName    = "sailss_cc_can2_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xF539B19A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN2_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 58,
    },
  },
  {
    .szName    = "sailss_cc_can3_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x3BEB17E6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN3_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 60,
    },
  },
  {
    .szName    = "sailss_cc_can4_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x6F796E43,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN4_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 62,
    },
  },
  {
    .szName    = "sailss_cc_can5_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x4046AF47,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN5_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 64,
    },
  },
  {
    .szName    = "sailss_cc_can6_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xBFE9BD99,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN6_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 66,
    },
  },
  {
    .szName    = "sailss_cc_can7_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0AAE79AA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CAN7_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 68,
    },
  },
  {
    .szName    = "sailss_cc_ce1_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x32E7C34E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CE1_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CE1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 98,
    },
  },
  {
    .szName    = "sailss_cc_cpu_csr_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD67DDDED,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_CSR_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 110,
    },
  },
  {
    .szName    = "sailss_cc_dcc_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0BC410C7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 136,
    },
  },
  {
    .szName    = "sailss_cc_dma_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x633A01B4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DMA_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_DMA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 184,
    },
  },
  {
    .szName    = "sailss_cc_emac0_slv_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xAC969DEB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_SLV_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_EMAC0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 142,
    },
  },
  {
    .szName    = "sailss_cc_hbcu_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xF96C81EA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HBCU_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HBCU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 137,
    },
  },
  {
    .szName    = "sailss_cc_hbcu_shs_apb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x9A824A6B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HBCU_SHS_APB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HBCU_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 138,
    },
  },
  {
    .szName    = "sailss_cc_hwkm_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x1F952DA0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HWKM_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_HWKM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 72,
    },
  },
  {
    .szName    = "sailss_cc_ipcc_core_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xB1FA0B58,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_IPCC_CORE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_IPCC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 99,
    },
  },
  {
    .szName    = "sailss_cc_pka_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xAFA6546A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PKA_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PKA_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 70,
    },
  },
  {
    .szName    = "sailss_cc_qdss_cfg_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x33549649,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 32,
    },
  },
  {
    .szName    = "sailss_cc_qdss_dap_axi_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE737C97D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_AXI_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 31,
    },
  },
  {
    .szName    = "sailss_cc_qdss_stm_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC8059D96,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_STM_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 36,
    },
  },
  {
    .szName    = "sailss_cc_qtmr_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xEF02F967,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QTMR_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QTMR_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 180,
    },
  },
  {
    .szName    = "sailss_cc_rbcpr_cx_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x66A11791,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_RBCPR_CX_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_RBCPR_CX_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 121,
    },
  },
  {
    .szName    = "sailss_cc_safe_apb_bdg_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x773C47A9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SAFE_APB_BDG_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 13,
    },
  },
  {
    .szName    = "sailss_cc_sec_ctrl_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x6F82408C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 87,
    },
  },
  {
    .szName    = "sailss_cc_sec_ctrl_boot_rom_patch_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x96E05C2B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_BOOT_ROM_PATCH_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 90,
    },
  },
  {
    .szName    = "sailss_cc_spdm_sail_noc_qh_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xBABE7082,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_SAIL_NOC_QH_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 94,
    },
  },
  {
    .szName    = "sailss_cc_tcsr_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC98A9E3B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TCSR_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TCSR_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 79,
    },
  },
  {
    .szName    = "sailss_cc_tlmm_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x68368B3E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TLMM_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TLMM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 85,
    },
  },
  {
    .szName    = "sailss_cc_tscss_0_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xF506560D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSCSS_0_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 75,
    },
  },
  {
    .szName    = "sailss_cc_tscss_1_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x72B099A9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 77,
    },
  },
  {
    .szName    = "sailss_cc_vs_prim_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xB87435B2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_PRIM_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_PRIM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 174,
    },
  },
  {
    .szName    = "sailss_cc_vs_sec_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x43CACF4D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_SEC_AHB_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_SEC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 178,
    },
  },
  {
    .szName    = "sailss_cc_wdt0_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE9010A58,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT0_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 128,
    },
  },
  {
    .szName    = "sailss_cc_wdt1_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x6B98D30B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT1_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 129,
    },
  },
  {
    .szName    = "sailss_cc_wdt2_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x999AB173,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT2_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 130,
    },
  },
  {
    .szName    = "sailss_cc_wdt3_ahb_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSAILNOCCENTERQH,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x29DB65EF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT3_AHB_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 131,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCSECCTRL                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_sec_ctrl_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSECCTRL,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x17C3CD61,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 88,
    },
  },
  {
    .szName    = "sailss_cc_sec_ctrl_sense_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSECCTRL,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xED0D8E04,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_SENSE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SEC_CTRL_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 89,
    },
  },
  {
    .szName    = "sailss_cc_tcsr_acc_serial_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSECCTRL,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x0E2E214A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TCSR_ACC_SERIAL_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TCSR_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 80,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCSWAO                                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_swao_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSWAO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xDAAE6F3E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 185,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCSWAOTS                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_swao_dap_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSWAOTS,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x75045237,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_DAP_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 187,
    },
  },
  {
    .szName    = "sailss_cc_swao_ts_bdg_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSWAOTS,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x27537341,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_BDG_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 189,
    },
  },
  {
    .szName    = "sailss_cc_swao_ts_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCSWAOTS,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xDBD08FD2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SWAO_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 186,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCTSCSS0CNTR                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_tscss_0_global_cntr_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCTSCSS0CNTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xB68F66CF,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSCSS_0_GLOBAL_CNTR_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 76,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCTSCSS1CNTR                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_tscss_1_global_cntr_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCTSCSS1CNTR,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xF87E7B5F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_GLOBAL_CNTR_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 78,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCTSENSE                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asild_noc_tsense_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCTSENSE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE43F4F2C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_TSENSE_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 25,
    },
  },
  {
    .szName    = "sailss_cc_tsense0_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCTSENSE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xE9CD5E6F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSENSE0_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSENSE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 151,
    },
  },
  {
    .szName    = "sailss_cc_tsense1_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCTSENSE,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x95B8141B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSENSE1_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_TSENSE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 152,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCVSCTRLPRIM                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_vs_ctrl_prim_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCVSCTRLPRIM,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x9BE8DF26,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_CTRL_PRIM_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_PRIM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 173,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCVSCTRLSEC                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_vs_ctrl_sec_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCVSCTRLSEC,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x5F207323,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_CTRL_SEC_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_SEC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 177,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCVSENSORPRIM                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_vdd_sailcx_vs_prim_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCVSENSORPRIM,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xCDCFF19B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VDD_SAILCX_VS_PRIM_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_PRIM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 171,
    },
  },
  {
    .szName    = "sailss_cc_vdd_sailmx_vs_prim_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCVSENSORPRIM,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xEB074719,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VDD_SAILMX_VS_PRIM_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_PRIM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 172,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCVSENSORSEC                               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_vdd_sailcx_vs_sec_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCVSENSORSEC,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xBB5FC71C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VDD_SAILCX_VS_SEC_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_SEC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 175,
    },
  },
  {
    .szName    = "sailss_cc_vdd_sailmx_vs_sec_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCVSENSORSEC,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xDE9F68E9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VDD_SAILMX_VS_SEC_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_VS_SEC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 176,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCWDT                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_wdt0_timer_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCWDT,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xA084600D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT0_TIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 132,
    },
  },
  {
    .szName    = "sailss_cc_wdt1_timer_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCWDT,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xA6A734A0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT1_TIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 133,
    },
  },
  {
    .szName    = "sailss_cc_wdt2_timer_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCWDT,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD232A413,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT2_TIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 134,
    },
  },
  {
    .szName    = "sailss_cc_wdt3_timer_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCWDT,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD71C706D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_WDT3_TIMER_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 135,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCXO                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_asilb_noc_qosgen_extref_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x04320D94,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_QOSGEN_EXTREF_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 9,
    },
  },
  {
    .szName    = "sailss_cc_asilb_noc_xo_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x42215E7F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_XO_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_B_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 5,
    },
  },
  {
    .szName    = "sailss_cc_asild_noc_xo_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x723E1BF9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_XO_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_ASIL_D_NOC_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 16,
    },
  },
  {
    .szName    = "sailss_cc_cpu_xo_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x52F02D7F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_CPU_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 117,
    },
  },
  {
    .szName    = "sailss_cc_frq_measure_ref_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x8F68FACD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_FRQ_MEASURE_REF_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 122,
    },
  },
  {
    .szName    = "sailss_cc_qdss_xo_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xA6583293,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QDSS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 43,
    },
  },
  {
    .szName    = "sailss_cc_qtmr_xo_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD360EE71,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QTMR_XO_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_QTMR_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 179,
    },
  },
  {
    .szName    = "sailss_cc_spdm_ff_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xC0F70627,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_FF_CBCR), HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SPDM_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 92,
    },
  },
  {
    .szName    = "sailss_cc_xo_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xA5A819CB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 104,
    },
  },
  {
    .szName    = "sailss_cc_xo_div4_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXO,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xD1A25D46,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_XO_DIV4_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 105,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_SAILSSCC_SAILSSCCXOROGFMUX                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "sailss_cc_int_sleep_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXOROGFMUX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0x261F6275,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_INT_SLEEP_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 106,
    },
  },
  {
    .szName    = "sailss_cc_sleep_clk",
    .pDomain   = &ClockDomain_SAILSSCC_SAILSSCCXOROGFMUX,
    .pDebugMux = &ClockDebugMux_SAILSSCC,
    .nUniqueId = 0xDB34CB1A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_SLEEP_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 107,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCAON                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_ceng_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x1368AD6D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_CENG_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 41,
    },
  },
    #if 0
  {
    .szName    = "turing_0_turing_cc_nspnoc_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xB07DF1C8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPNOC_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 42,
    },
  },
  #endif
  {
    .szName    = "turing_0_turing_cc_q6ss_ahbm_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x2A41E4B6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_AHBM_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 59,
    },
  },
  {
    .szName    = "turing_0_turing_cc_q6ss_ahbs_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xE16AD5C8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_AHBS_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 60,
    },
  },
  {
    .szName    = "turing_0_turing_cc_q6ss_alt_reset_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x6786E7C7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_ALT_RESET_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 61,
    },
  },
    #if 0
  {
    .szName    = "turing_0_turing_cc_turing_wrapper_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x6EEC30A0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_TURING_WRAPPER_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 13,
    },
  },
  {
    .szName    = "turing_0_turing_cc_turing_wrapper_bus_timeout_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x0ED02458,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_TURING_WRAPPER_BUS_TIMEOUT_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 15,
    },
  },
  {
    .szName    = "turing_0_turing_cc_turing_wrapper_cnoc_sway_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x5C6D5504,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_TURING_WRAPPER_CNOC_SWAY_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },
  {
    .szName    = "turing_0_turing_cc_turing_wrapper_rscc_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xAF20B98C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_TURING_WRAPPER_RSCC_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 16,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_ahbs_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xF98EB073,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_AHBS_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 37,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_ahbs_timeout_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x8FF89FFE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_AHBS_TIMEOUT_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 33,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_dma_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x8C03CF21,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_DMA_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 34,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_hcp_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x32825D03,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_HCP_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 36,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_tbuf2_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x92997D11,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_TBUF2_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_vma_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x39BF13E9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_VMA_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 35,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCDEBUGMUX                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x8FD4E1BC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCPLLTESTMUX                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_pll_test_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCPLLTESTMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0xA6D21FF5,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSISENSE                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_q6ss_isense_core_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSISENSE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xEB1BCC76,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_ISENSE_CORE_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 64,
    },
  },
  {
    .szName    = "turing_0_turing_cc_q6ss_isense_ctrl_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSISENSE,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x0EEC5785,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_ISENSE_CTRL_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 63,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSLMH                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_q6ss_lmh_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCQ6SSLMH,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x3955E218,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_LMH_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 62,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCSMDEBUGMUX                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_sm_debug_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCSMDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x3177B111,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_SM_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSBUS                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_nspnoc_vapss_bus_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSBUS,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x8845369B,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPNOC_VAPSS_BUS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 45,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_bus_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSBUS,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xA02E342E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_BUS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 29,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSDMA                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_vapss_dma_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSDMA,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xC4AED0E8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_DMA_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 23,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSFINT                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_vapss_fint_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSFINT,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x2909CC99,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_FINT_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 30,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_fint_prog_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSFINT,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x7151B7D2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_FINT_PROG_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 32,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSHCP                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_vapss_hcp0_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSHCP,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x8F70BE98,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_HCP0_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 28,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_hcp_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSHCP,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xE88DE586,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_HCP_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 26,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTBUF2                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_nspnoc_tbuf2_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTBUF2,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0xE6096855,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPNOC_TBUF2_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_tbuf2_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTBUF2,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x10BE7820,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_TBUF2_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTCMS                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_q6ss_axis2_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTCMS,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x9DD6D2F8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_AXIS2_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 58,
    },
  },
  {
    .szName    = "turing_0_turing_cc_vapss_tcms_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSTCMS,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x9A331B48,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_TCMS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 25,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSVMA                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_cc_vapss_vma_clk",
    .pDomain   = &ClockDomain_TURINGCC0_TURING0TURINGCCVAPSSVMA,
    .pDebugMux = &ClockDebugMux_TURINGCC0,
    .nUniqueId = 0x763F648A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_VMA_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCAON                              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_ceng_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x2C3291FB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_CENG_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 41,
    },
  },
  {
    .szName    = "turing_1_turing_cc_nspnoc_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xA98BAC86,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPNOC_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 42,
    },
  },
  {
    .szName    = "turing_1_turing_cc_q6ss_ahbm_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xE4703619,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_AHBM_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 59,
    },
  },
  {
    .szName    = "turing_1_turing_cc_q6ss_ahbs_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x4239ADCE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_AHBS_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 60,
    },
  },
  {
    .szName    = "turing_1_turing_cc_q6ss_alt_reset_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xB551B72E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_ALT_RESET_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 61,
    },
  },
    #if 0
  {
    .szName    = "turing_1_turing_cc_turing_wrapper_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xDC9545FC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_TURING_WRAPPER_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 13,
    },
  },
  {
    .szName    = "turing_1_turing_cc_turing_wrapper_bus_timeout_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x7CE2D661,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_TURING_WRAPPER_BUS_TIMEOUT_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 15,
    },
  },
  {
    .szName    = "turing_1_turing_cc_turing_wrapper_cnoc_sway_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x95A83714,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_TURING_WRAPPER_CNOC_SWAY_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },
  {
    .szName    = "turing_1_turing_cc_turing_wrapper_rscc_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x983C3F05,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_TURING_WRAPPER_RSCC_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 16,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_ahbs_aon_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x08CAEC01,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_AHBS_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 37,
    },
  },
  #endif
  {
    .szName    = "turing_1_turing_cc_vapss_ahbs_timeout_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x0D4B025F,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_AHBS_TIMEOUT_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 33,
    },
  },
    #if 0
  {
    .szName    = "turing_1_turing_cc_vapss_dma_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x7CAD4D8C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_DMA_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 34,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_hcp_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x556FD708,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_HCP_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 36,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_tbuf2_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xF31D4794,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_TBUF2_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_vma_ahbs_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xC1C82E9A,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_VMA_AHBS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 35,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCDEBUGMUX                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x913DA6A0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCPLLTESTMUX                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_pll_test_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCPLLTESTMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x89E604AC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSISENSE                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_q6ss_isense_core_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSISENSE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x3DEBADC8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_ISENSE_CORE_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 64,
    },
  },
  {
    .szName    = "turing_1_turing_cc_q6ss_isense_ctrl_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSISENSE,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xAC8A5DBE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_ISENSE_CTRL_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 63,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSLMH                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_q6ss_lmh_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCQ6SSLMH,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x16220295,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_LMH_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 62,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCSMDEBUGMUX                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_sm_debug_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCSMDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x01646C20,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_SM_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSBUS                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_nspnoc_vapss_bus_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSBUS,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xD6EC35B1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPNOC_VAPSS_BUS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 45,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_bus_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSBUS,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x28D7FDA7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_BUS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 29,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSDMA                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_vapss_dma_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSDMA,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x2D28AEED,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_DMA_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 23,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSFINT                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_vapss_fint_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSFINT,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x9554D677,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_FINT_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 30,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_fint_prog_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSFINT,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x6A635434,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_FINT_PROG_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 32,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSHCP                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_vapss_hcp0_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSHCP,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xDF8C1AE2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_HCP0_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 28,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_hcp_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSHCP,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x14B36E87,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_HCP_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 26,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTBUF2                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_nspnoc_tbuf2_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTBUF2,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x7A3C623D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPNOC_TBUF2_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_tbuf2_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTBUF2,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x6B76AB4D,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_TBUF2_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTCMS                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_q6ss_axis2_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTCMS,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x1D3786AD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_AXIS2_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 58,
    },
  },
  {
    .szName    = "turing_1_turing_cc_vapss_tcms_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSTCMS,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0xF983C6B8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_TCMS_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 25,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSVMA                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_cc_vapss_vma_clk",
    .pDomain   = &ClockDomain_TURINGCC1_TURING1TURINGCCVAPSSVMA,
    .pDebugMux = &ClockDebugMux_TURINGCC1,
    .nUniqueId = 0x3C83D1E6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_VMA_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_CORE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 24,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_0_qdsp6ss_core_cc_core_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0x5A083FDA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_qdsp6ss_core_cc_mon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0x5C8153A6,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCDEBUGMUX          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_0_qdsp6ss_core_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0QDSP6SSCORECCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x6BD007E1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_q6ss_ahbm_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0xBE4A9A05,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_AHBM_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_q6ss_ahbs_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0xC3CA5DF9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_AHBS_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_q6ss_alt_reset_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0xBF87D8F8,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_ALT_RESET_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_turing_wrapper_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0x441D54F9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_TURING_WRAPPER_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_turing_wrapper_bus_timeout_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0x2C4DD4C9,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_TURING_WRAPPER_BUS_TIMEOUT_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_turing_wrapper_cnoc_sway_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0xBC3F1262,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_TURING_WRAPPER_CNOC_SWAY_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_turing_wrapper_rscc_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC0,
    .nUniqueId = 0x8DD7C738,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_TURING_WRAPPER_RSCC_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCDEBUGMUX               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_0_turing_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC0_TURINGSSGDSP0TURINGCCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0xA2E4CA39,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_0_TURING_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE              */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_1_qdsp6ss_core_cc_core_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0xFEC20496,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_qdsp6ss_core_cc_mon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCCORE,
    .pDebugMux = NULL,
    .nUniqueId = 0xEA2F129C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCDEBUGMUX          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_1_qdsp6ss_core_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1QDSP6SSCORECCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x69E6D9A7,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_q6ss_ahbm_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0xA1D479E0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_AHBM_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 50,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_q6ss_ahbs_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0x2CA29FFE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_AHBS_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 51,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_q6ss_alt_reset_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0x3325CF83,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_ALT_RESET_AON_CBCR), HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_Q6SS_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 52,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_turing_wrapper_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0xD22FB008,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_TURING_WRAPPER_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 17,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_turing_wrapper_bus_timeout_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0x5692C227,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_TURING_WRAPPER_BUS_TIMEOUT_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 19,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_turing_wrapper_cnoc_sway_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0xA78E280E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_TURING_WRAPPER_CNOC_SWAY_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 18,
    },
  },
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_turing_wrapper_rscc_aon_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCAON,
    .pDebugMux = &ClockDebugMux_TURINGGDSPCC1,
    .nUniqueId = 0x95897655,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_TURING_WRAPPER_RSCC_AON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 20,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCDEBUGMUX               */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_ss_gdsp_1_turing_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGGDSPCC1_TURINGSSGDSP1TURINGCCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x5CA2FE46,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGGDSP_1_TURING_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_q6_cc_acd_scan_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x9F094030,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_ACD_SCAN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
  #endif
  {
    .szName    = "turing_0_turing_q6_cc_core_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0xD7F4F3C4,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 1,
    },
  },
    #if 0
  {
    .szName    = "turing_0_turing_q6_cc_l2itcm_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x5C9FB526,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_L2ITCM_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 5,
    },
  },
  {
    .szName    = "turing_0_turing_q6_cc_l2mem_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x93401C81,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_L2MEM_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 4,
    },
  },
  {
    .szName    = "turing_0_turing_q6_cc_l2vtcm_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x5EF81B31,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_L2VTCM_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 6,
    },
  },
  {
    .szName    = "turing_0_turing_q6_cc_mon_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x68F9B2CB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_MON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 3,
    },
  },
  {
    .szName    = "turing_0_turing_q6_cc_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC0,
    .nUniqueId = 0x42281094,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 2,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCDEBUGMUX                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_q6_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x767BAB32,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCSMMUX                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_0_turing_q6_cc_sm_obs_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC0_TURING0TURINGQ6CCSMMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0xB002A718,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_QDSP6SS_SM_OBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_q6_cc_acd_scan_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0x583AFE9C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_ACD_SCAN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
  #endif
  {
    .szName    = "turing_1_turing_q6_cc_core_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0xBC9706DA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_CORE_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 1,
    },
  },
    #if 0
  {
    .szName    = "turing_1_turing_q6_cc_l2itcm_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0xCB91BFC3,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_L2ITCM_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 5,
    },
  },
  {
    .szName    = "turing_1_turing_q6_cc_l2mem_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0xE5CC11F2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_L2MEM_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 4,
    },
  },
  {
    .szName    = "turing_1_turing_q6_cc_l2vtcm_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0xBCCAF1EA,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_L2VTCM_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 6,
    },
  },
  {
    .szName    = "turing_1_turing_q6_cc_mon_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0xA9AF0537,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_MON_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 3,
    },
  },
  {
    .szName    = "turing_1_turing_q6_cc_slpgen_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCCORE,
    .pDebugMux = &ClockDebugMux_TURINGQ6CC1,
    .nUniqueId = 0xCA1DA302,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_SLPGEN_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 2,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCDEBUGMUX                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_q6_cc_debug_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCDEBUGMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0x2C829148,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_DEBUG_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCSMMUX                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "turing_1_turing_q6_cc_sm_obs_clk",
    .pDomain   = &ClockDomain_TURINGQ6CC1_TURING1TURINGQ6CCSMMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0xDFC63D1C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_QDSP6SS_SM_OBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_VIDEOCC_VIDEOCCAHB                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "video_cc_ahb_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCAHB,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0x12DABE26,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR), HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 7,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_VIDEOCC_VIDEOCCMVS0                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "video_cc_mvs0_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCMVS0,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0x69F9979C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR), HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 3,
    },
  },
  {
    .szName    = "video_cc_mvs0c_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCMVS0,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0xCC22911E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR), HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 1,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_VIDEOCC_VIDEOCCMVS1                                       */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "video_cc_mvs1_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCMVS1,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0x770FB487,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR), HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 5,
    },
  },
  {
    .szName    = "video_cc_mvs1c_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCMVS1,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0xD3F30B66,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR), HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR), {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 9,
    },
  },
  #if 0
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_VIDEOCC_VIDEOCCPLLTESTMUX                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "video_cc_pll_test_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCPLLTESTMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0xF56D61DD,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_VIDEOCC_VIDEOCCSLEEP                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "video_cc_sleep_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCSLEEP,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0x2CE12181,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 12,
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_VIDEOCC_VIDEOCCSMMUX                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "video_cc_sm_obs_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCSMMUX,
    .pDebugMux = NULL,
    .nUniqueId = 0xAF5FFE2C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
#endif
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_VIDEOCC_VIDEOCCXO                                         */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "video_cc_pll_lock_monitor_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCXO,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0x670DE57E,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 14,
    },
  },
  {
    .szName    = "video_cc_xo_clk",
    .pDomain   = &ClockDomain_VIDEOCC_VIDEOCCXO,
    .pDebugMux = &ClockDebugMux_VIDEOCC,
    .nUniqueId = 0x3777936C,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR), 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = 11,
    },
  },
};


/*=========================================================================
      Power Domains
==========================================================================*/

static ClockPowerDomainNodeType aPowerDomains[] =
{
  {
    .szName         = "cam_cc_titan_top_gdsc",
    .nRailMask      = RAIL_VDD_MM | RAIL_VDD_MXC,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "mdss_0_disp_cc_mdss_core_gdsc",
    .nRailMask      = RAIL_VDD_MM,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "mdss_0_disp_cc_mdss_core_int2_gdsc",
    .nRailMask      = RAIL_VDD_MM,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_MDSS_0_DISP_CC_MDSS_CORE_INT2_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "mdss_1_disp_cc_mdss_core_gdsc",
    .nRailMask      = RAIL_VDD_MM,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "mdss_1_disp_cc_mdss_core_int2_gdsc",
    .nRailMask      = RAIL_VDD_MM,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_emac0_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC0_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_emac1_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_EMAC1_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_lpass_tbu_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_LPASS_TBU_GDSCR),
      .nGDSHWCtrlAddr = HWIO_ADDR(SAIL_TO_MD_GCC_LPASS_TBU_GDS_HW_CTRL),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_mmnoc_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_GDSCR),
      .nGDSHWCtrlAddr = HWIO_ADDR(SAIL_TO_MD_GCC_MMNOC_GDS_HW_CTRL),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_mmu3_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_MMU3_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_pcie_0_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_0_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_pcie_1_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_PCIE_1_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_sail_tbu_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_SAIL_TBU_GDSCR),
      .nGDSHWCtrlAddr = HWIO_ADDR(SAIL_TO_MD_GCC_SAIL_TBU_GDS_HW_CTRL),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_turing_0_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_TURING_0_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gcc_turing_1_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GCC_TURING_1_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gpu_cc_cx_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR),
      .nGDSHWCtrlAddr = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "gpu_cc_gx_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_GX | RAIL_VDD_MXC,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "turing_0_turing_cc_nspaux_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_NSPAUX_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "turing_0_turing_cc_vapss_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_GDSCR),
      .nGDSHWCtrlAddr = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_0_TURING_VAPSS_GDS_HW_CTRL),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "turing_1_turing_cc_nspaux_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_NSPAUX_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "turing_1_turing_cc_vapss_gdsc",
    .nRailMask      = RAIL_VDD_CX | RAIL_VDD_MXA,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_GDSCR),
      .nGDSHWCtrlAddr = HWIO_ADDR(SAIL_TO_MD_TURINGNSP_1_TURING_VAPSS_GDS_HW_CTRL),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "video_cc_mvs0_gdsc",
    .nRailMask      = RAIL_VDD_MM | RAIL_VDD_MX,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "video_cc_mvs0c_gdsc",
    .nRailMask      = RAIL_VDD_MM | RAIL_VDD_MX,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "video_cc_mvs1_gdsc",
    .nRailMask      = RAIL_VDD_MM | RAIL_VDD_MX,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
  {
    .szName         = "video_cc_mvs1c_gdsc",
    .nRailMask      = RAIL_VDD_MM | RAIL_VDD_MX,
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr     = HWIO_ADDR(SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR),
      .pmControl      = &HAL_clk_GenericPowerDomainControl,
    },
  },
};


/*=========================================================================
      Main BSP
==========================================================================*/

ClockBSPType ClockBSP =
{
  .aRails            = aRails,
  .nNumRails         = SIZEOF_ARRAY(aRails),
  .aClocks           = aClocks,
  .nNumClocks        = SIZEOF_ARRAY(aClocks),
  .aDomains          = aDomains,
  .nNumDomains       = SIZEOF_ARRAY(aDomains),
  .aSources          = aSources,
  .nNumSources       = SIZEOF_ARRAY(aSources),
  .aPowerDomains     = aPowerDomains,
  .nNumPowerDomains  = SIZEOF_ARRAY(aPowerDomains),
  .aDebugMuxes       = aDebugMuxes,
  .nNumDebugMuxes    = SIZEOF_ARRAY(aDebugMuxes),
  .SafeMuxConfig     = { 0, 2, 0, 0 },
};

