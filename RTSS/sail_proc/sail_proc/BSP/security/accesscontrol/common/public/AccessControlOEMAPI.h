/*===========================================================================
  Copyright (c) 2023 by Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/


#ifndef ACOEMAPI_H
#define ACOEMAPI_H

#include "types.h"
#include "ACTargetCfg.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#ifndef ARR_SIZE
  #define  ARR_SIZE(a)  (sizeof((a))/sizeof(*((a)+0)))
#endif

/* OEM xPU indexs */
#define OEM_MAP_NIU_INDEX     0U
#define OEM_MAP_EXT_NIU_INDEX 1U


/* VMID can't be more than 16bits because of lack of support in S2VMID conversion */

/*------------------------ SAIL LEMANS R2 AC VMID's--------------------------*/
/* Lemans R2 has stream and VMIDMT specific VMID instead of memory specific VMID's.*/
            /* HAL_VMIDMT_0_VMIDMT_SMR_NIU - EMAC */
#define SAILBSP_VMID_EMAC_CH_3           29U      /* VMID for EMAC Channel 3 */
#define SAILBSP_VMID_EMAC_CH_2           28U      /* VMID for EMAC Channel 2 */
#define SAILBSP_VMID_EMAC_CH_1           27U      /* VMID for EMAC Channel 1 */
#define SAILBSP_VMID_EMAC_CH_0           26U      /* VMID for EMAC Channel 0 */
#define SAILBSP_VMID_EMAC_CH_3_BIT       (1UL << SAILBSP_VMID_EMAC_CH_3)
#define SAILBSP_VMID_EMAC_CH_2_BIT       (1UL << SAILBSP_VMID_EMAC_CH_2)
#define SAILBSP_VMID_EMAC_CH_1_BIT       (1UL << SAILBSP_VMID_EMAC_CH_1)
#define SAILBSP_VMID_EMAC_CH_0_BIT       (1UL << SAILBSP_VMID_EMAC_CH_0)
           /* HAL_VMIDMT_0_VMIDMT_SMR_NIU - CAN */
#define SAILBSP_VMID_CAN_FD_7            25U      /* VMID for CAN FD Channel 7 */
#define SAILBSP_VMID_CAN_FD_6            24U      /* VMID for CAN FD Channel 6 */
#define SAILBSP_VMID_CAN_FD_5            23U      /* VMID for CAN FD Channel 5 */
#define SAILBSP_VMID_CAN_FD_4            22U      /* VMID for CAN FD Channel 4 */
#define SAILBSP_VMID_CAN_FD_3            21U      /* VMID for CAN FD Channel 3 */
#define SAILBSP_VMID_CAN_FD_2            20U      /* VMID for CAN FD Channel 2 */
#define SAILBSP_VMID_CAN_FD_1            19U      /* VMID for CAN FD Channel 1 */
#define SAILBSP_VMID_CAN_FD_0            18U      /* VMID for CAN FD Channel 0 */
#define SAILBSP_VMID_CAN_FD_7_BIT        (1UL << SAILBSP_VMID_CAN_FD_7)
#define SAILBSP_VMID_CAN_FD_6_BIT        (1UL << SAILBSP_VMID_CAN_FD_6)
#define SAILBSP_VMID_CAN_FD_5_BIT        (1UL << SAILBSP_VMID_CAN_FD_5)
#define SAILBSP_VMID_CAN_FD_4_BIT        (1UL << SAILBSP_VMID_CAN_FD_4)
#define SAILBSP_VMID_CAN_FD_3_BIT        (1UL << SAILBSP_VMID_CAN_FD_3)
#define SAILBSP_VMID_CAN_FD_2_BIT        (1UL << SAILBSP_VMID_CAN_FD_2)
#define SAILBSP_VMID_CAN_FD_1_BIT        (1UL << SAILBSP_VMID_CAN_FD_1)
#define SAILBSP_VMID_CAN_FD_0_BIT        (1UL << SAILBSP_VMID_CAN_FD_0)
           /* HAL_VMIDMT_0_VMIDMT_SMR_NIU - GPCE */
#define SAILBSP_VMID_GPCE_PIPESET_3      17U      /* VMID for GPCE Pipe set 3 (Secure) */
#define SAILBSP_VMID_GPCE_PIPESET_2      16U      /* VMID for GPCE Pipe set 2 (Secure) */
#define SAILBSP_VMID_GPCE_PIPESET_1      15U      /* VMID for GPCE Pipe set 1 (Non-Secure) */
#define SAILBSP_VMID_GPCE_PIPESET_0      14U      /* VMID for GPCE Pipe set 0 (Non-Secure) */
#define SAILBSP_VMID_GPCE_PIPESET_3_BIT  (1UL << SAILBSP_VMID_GPCE_PIPESET_3)
#define SAILBSP_VMID_GPCE_PIPESET_2_BIT  (1UL << SAILBSP_VMID_GPCE_PIPESET_2)
#define SAILBSP_VMID_GPCE_PIPESET_1_BIT  (1UL << SAILBSP_VMID_GPCE_PIPESET_1)
#define SAILBSP_VMID_GPCE_PIPESET_0_BIT  (1UL << SAILBSP_VMID_GPCE_PIPESET_0)
          /* HAL_VMIDMT_0_VMIDMT_SMR_NIU - OSPI */
#define SAILBSP_VMID_OSPI_DMA            13U      /* VMID for OSPI DMA Access*/
#define SAILBSP_VMID_OSPI_DMA_BIT        (1U << SAILBSP_VMID_OSPI_DMA)
          /* HAL_VMIDMT_0_VMIDMT_SMR_NIU */
#define SAILBSP_VMID_NS_DEBUG             2U      /* VMID to access non secure memory regions(EL1).*/
#define SAILBSP_VMID_SECURE_DEBUG         1U      /* VMID to access secure memory regions(EL2).*/
#define SAILBSP_VMID_NS_DEBUG_BIT        (1UL << SAILBSP_VMID_NS_DEBUG)
#define SAILBSP_VMID_SECURE_DEBUG_BIT    (1UL << SAILBSP_VMID_SECURE_DEBUG)

				  /* HAL_VMIDMT_2_VMIDMT_SMR_DMA */
#define SAILBSP_VMID_R52_WRITE_CH3       15U      /* VMID/MID for R52 DMA Write Channel 3 (0x0F) */
#define SAILBSP_VMID_R52_WRITE_CH2       14U      /* VMID/MID for R52 DMA Write Channel 2 (0x0E) */
#define SAILBSP_VMID_R52_WRITE_CH1       13U      /* VMID/MID for R52 DMA Write Channel 1 (0x0D) */
#define SAILBSP_VMID_R52_WRITE_CH0       12U      /* VMID/MID for R52 DMA Write Channel 0 (0x0C) */
#define SAILBSP_VMID_R52_WRITE_CH3_BIT   (1UL << SAILBSP_VMID_R52_WRITE_CH3)
#define SAILBSP_VMID_R52_WRITE_CH2_BIT   (1UL << SAILBSP_VMID_R52_WRITE_CH2)
#define SAILBSP_VMID_R52_WRITE_CH1_BIT   (1UL << SAILBSP_VMID_R52_WRITE_CH1)
#define SAILBSP_VMID_R52_WRITE_CH0_BIT   (1UL << SAILBSP_VMID_R52_WRITE_CH0)

         /* HAL_VMIDMT_1_VMIDMT_SMR_DMA */
#define SAILBSP_VMID_R52_READ_CH3        11U      /* VMID/MID for R52 DMA Read Channel 3 (0x0B) */
#define SAILBSP_VMID_R52_READ_CH2        10U      /* VMID/MID for R52 DMA Read Channel 2 (0x0A) */
#define SAILBSP_VMID_R52_READ_CH1         9U      /* VMID/MID for R52 DMA Read Channel 1 (0x09) */
#define SAILBSP_VMID_R52_READ_CH0         8U      /* VMID/MID for R52 DMA Read Channel 0 (0x08) */
#define SAILBSP_VMID_R52_READ_CH3_BIT    (1UL << SAILBSP_VMID_R52_READ_CH3)
#define SAILBSP_VMID_R52_READ_CH2_BIT    (1UL << SAILBSP_VMID_R52_READ_CH2)
#define SAILBSP_VMID_R52_READ_CH1_BIT    (1UL << SAILBSP_VMID_R52_READ_CH1)
#define SAILBSP_VMID_R52_READ_CH0_BIT    (1UL << SAILBSP_VMID_R52_READ_CH0)

/*##############--------------SAIL LEMANS R1 AC VMID's-----------####################*/
#define SAILBSP_VMID_EL1_FULL             5U     /* VMID to access non secure memory regions(Crypto, EL1 Config and memory).*/
#define SAILBSP_VMID_EL2_FULL             4U     /* VMID to access secure memory regions(Crypto, EL2 Config and memory).*/
#define SAILBSP_VMID_EL1_MEMORY           2U     /* VMID to access non secure memory regions(EL1 memory).*/
#define SAILBSP_VMID_EL2_MEMORY           1U     /* VMID to access secure memory regions(EL2 memory).*/
#define SAILBSP_VMID_EL1_MEMORY_BIT      (1UL << SAILBSP_VMID_EL1_MEMORY)
#define SAILBSP_VMID_EL2_MEMORY_BIT      (1UL << SAILBSP_VMID_EL2_MEMORY)
#define SAILBSP_VMID_EL1_FULL_BIT        (1UL << SAILBSP_VMID_EL1_FULL)
#define SAILBSP_VMID_EL2_FULL_BIT        (1UL << SAILBSP_VMID_EL2_FULL)

#define SAILBSP_VMID_NOACCESS             0x0U     /* Bypass VMID or No Access VMID*/
#define SAILBSP_VMID_BYPASS_VMID          SAILBSP_VMID_NOACCESS

#ifdef EL1_BU_CONFIGURATION
#define SAILBSP_VMID_TEMP_EL2_MEMORY      0x03U    /* Temporary VMID to provide EL2 access to DMA domains */ 
#define SAILBSP_VMID_TEMP_EL2_MEMORY_BIT  (1UL << SAILBSP_VMID_TEMP_EL2_MEMORY)
#endif


/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/
typedef struct OEM_xpu_rg_s
{
  uint32 read_vmid;  /* read permissions */
  uint32 write_vmid; /* write permissions */
  uintptr_t start;  /* Start of the address range */
  uintptr_t end;    /* End of the address range, not included in the range */
} OEM_xpu_rg_t;

typedef struct OEM_xpu_map_s
{
  uint16 oem_uid;
  const OEM_xpu_rg_t *xpu_rg_map;
  uint8 rgn;
} OEM_xpu_map_t;

extern const OEM_xpu_rg_t oem_cfg_NIU[];
extern const OEM_xpu_rg_t oem_cfg_EXT_NIU[];
extern const OEM_xpu_map_t oem_xpu_map[];
extern const uint32 oem_xpu_map_count;

#endif /* ACOEMAPI_H */
