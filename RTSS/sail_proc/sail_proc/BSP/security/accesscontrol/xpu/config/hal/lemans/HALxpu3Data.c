/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
	===========================================================================*/

#include "HALxpu3Internal.h"
#include "HALhwio.h"
#include "HALSOCHWIOTarget.h"
#include "HALxpu3Hwio.h"
#include "HALhwioXpu3Generic.h"
#include "HALxpu3HWIOTarget.h"

#if !defined(XPU_IMAGE_SIZE_REDUCTION)
#define XPU_NAME(v)  (v)
#else
#define XPU_NAME(v)  
#endif

HAL_xpu3_Xpu3BaseAddressInfoType g_xpu_base_addr_array[]=
{
  {HAL_XPU_ASILD_NOC_DMA_MS_MPU,   XPU_ADDR_TYPE(SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0),   XPU_NAME("ASILD_NOC_DMA_MS_MPU_ASILD_NOC_DMA_MS_MPU")},
  {HAL_XPU_ASILD_ASILB_NOC_MS_MPU, XPU_ADDR_TYPE(SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0), XPU_NAME("ASILD_ASILB_NOC_MS_MPU_ASILD_ASILB_NOC_MS_MPU")},
  {HAL_XPU_CRYPTO0_BAM,            XPU_ADDR_TYPE(SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0),            XPU_NAME("CRYPTO0_CRYPTO_BAM_XPU3")},
  {HAL_XPU_ASILB_ASILB_NOC_MS_MPU, XPU_ADDR_TYPE(SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0),       XPU_NAME("ASIL_B_ASILB_NOC_MS_MPU_ASILB_NOC_MS_MPU")},
};

uint32 g_xpu_base_addr_array_count = sizeof(g_xpu_base_addr_array)/sizeof(g_xpu_base_addr_array[0]);

