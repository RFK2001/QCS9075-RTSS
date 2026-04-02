#ifndef AC_TARGET_CFG_H
#define AC_TARGET_CFG_H
/*==============================================================================
@file ACTargetCfg.h
Public interface for Access Control SMMU specific functionality

                 Copyright (c) Qualcomm Technologies Incorporated.
                            All rights reserved.
                    Qualcomm Technologies Inc. Confidential and Proprietary
==============================================================================*/

/*==============================================================================

                            EDIT HISTORY FOR FILE



when       who      what, where, why
--------   ---      ------------------------------------
10/10/2021  ip       Created
30/12/2021  ip       Added Secure interrupt Vector
27/01/2022  ip       Definition of different memory start and end address added, Introduction of AC Static config enable an disable
==============================================================================*/
/*-------------------------------------------------------------------------
* Include Files
* ----------------------------------------------------------------------*/
#include "interrupts.h"
#include "target.h"
#include "target_linker_map.h"
/*-------------------------------------------------------------------------
* Preprocessor Definitions and Constants
* ----------------------------------------------------------------------*/
#define SAILBSP_INT_VMIDMT_ERR_CLT_SEC                  325U  
#define SAILBSP_INT_VMIDMT_ERR_CFG_SEC                  322U
#define SAILBSP_INT_VMIDMT_ERR_CLT_NONSEC               323U  
#define SAILBSP_INT_VMIDMT_ERR_CFG_NONSEC               324U
#define SAILBSP_INT_XPU_SEC                             326U
#define SAILBSP_INT_XPU_NON_SEC                         327U
#define SAILBSP_INT_MSA_XPU_ERR                         36U

#define SAILBSPAC_EL2_SRAM_BASE	                        SAILBSP_EL2_SRAM_START
#define SAILBSPAC_EL2_SRAM_END                          SAILBSP_EL2_SRAM_END
 
#define SAILBSPAC_EL1_1_SRAM_BASE	                    SAILBSP_EL1_SRAM_1_START
#define SAILBSPAC_EL1_1_SRAM_END                        SAILBSP_EL1_SRAM_1_END
#define SAILBSPAC_EL1_2_SRAM_BASE	                    SAILBSP_EL1_SRAM_2_START
#define SAILBSPAC_EL1_2_SRAM_END                        SAILBSP_EL1_SRAM_2_END

#define SAILBSPAC_DDR_MEMORY_START                      SAILBSP_DDR_MEMORY_START
#define SAILBSPAC_DDR_MEMORY_END                        SAILBSP_DDR_MEMORY_END

#define SAILBSP_MD_MAP_UPPER_ADDRESS                    0x00000010UL

#define SAILBSPAC_CAN_EA_START                          (SAILBSP_CAN_DDREA_START + SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_CAN_EA_END                            (SAILBSP_CAN_DDREA_END   + SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_OSPI_EA_START                         (SAILBSP_OSPI_DDREA_START+ SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_OSPI_EA_END                           (SAILBSP_OSPI_DDREA_END  + SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_EMAC_EA_START                         (SAILBSP_EMAC_DDREA_START+ SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_EMAC_EA_END                           (SAILBSP_EMAC_DDREA_END  + SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_OSPI_DDR_START                        (SAILBSP_OSPI_DDR_START  + SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_OSPI_DDR_END                          (SAILBSP_OSPI_DDR_END    + SAILBSP_DDR_EA_OFFSET)

#ifdef AC_ENABLE_EMAC_DDR_CARVEOUT
#define SAILBSPAC_EMAC_DDR_START                        (SAILBSP_EMAC_DDR_START + SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_EMAC_DDR_END                          (SAILBSP_EMAC_DDR_END   + SAILBSP_DDR_EA_OFFSET)
#endif

#ifdef AC_ENABLE_GPCE_DDR_CARVEOUT
#define SAILBSPAC_GPCE_DDR_START                        (SAILBSP_GPCE_DDR_START + SAILBSP_DDR_EA_OFFSET)
#define SAILBSPAC_GPCE_DDR_END                          (SAILBSP_GPCE_DDR_END   + SAILBSP_DDR_EA_OFFSET)
#endif

#define SAILBSPAC_CORE0_ATCM_START                      SAILBSP_CORE0_ATCM_START
#define SAILBSPAC_CORE3_CTCM_END                        SAILBSP_CORE3_CTCM_END

#ifdef AC_ENABLE_DMA_CRC	
#define SAILBSPAC_EL1_SRAM_DMA_MEMORY_START             SAILBSP_EL1_SRAM_1_START
#define SAILBSPAC_EL1_SRAM_DMA_MEMORY_END               SAILBSP_EL1_SRAM_1_END
#define SAILBSPAC_EA_DRAM_DMA_START                     SAILBSP_DDR_EA_MEMORY_START
#define SAILBSPAC_EA_DRAM_DMA_END                       SAILBSP_DDR_EA_MEMORY_END
#endif

#ifdef AC_ENABLE_OSPI_CARVEOUT
#define SAILBSPAC_OSPI_SRAM_START                       SAILBSP_OSPI_EL1_SRAM_START
#define SAILBSPAC_OSPI_SRAM_END                         SAILBSP_OSPI_EL1_SRAM_END
#endif

#ifdef AC_ENABLE_CAN_CARVEOUT
#define SAILBSPAC_CAN_SRAM_START                        SAILBSP_CAN_EL1_SRAM_START
#define SAILBSPAC_CAN_SRAM_END                          SAILBSP_CAN_EL1_SRAM_END
#endif

#ifdef AC_ENABLE_EMAC_CARVEOUT
#define SAILBSPAC_EMAC_SRAM_START                       SAILBSP_EMAC_EL1_SRAM_START
#define SAILBSPAC_EMAC_SRAM_END                         SAILBSP_EMAC_EL1_SRAM_END
#endif

#ifdef AC_ENABLE_GPCE_CARVEOUT
#define SAILBSPAC_GPCE_SRAM_START                       SAILBSP_GPCE_EL1_SRAM_START
#define SAILBSPAC_GPCE_SRAM_END                         SAILBSP_GPCE_EL1_SRAM_END
#endif

#define SAIL_R1_MAJ_VERSION                             0x00010000UL /* 16bit Major - 16bit Minor version */
#define SAIL_R2_MAJ_VERSION                             0x00020000UL /* 16bit Major - 16bit Minor version */
#define SAIL_MAJ_VERSION_MASK                           0xFFFF0000UL /* Bit Mask for major version */

#define LLC_BROADCAST_LLCC_MPU_XPU3_ADDR                0xC9A30000UL /* XPU Address of MD XPU - LLC_BROADCAST_LLCC_MPU_XPU3 */
#define TOTAL_XPUS_WITH_MSA_RG                          1U           /* This is total number of MD XPU's where MSA RG's are monitored */
#define TOTAL_MSA_RGS_PER_XPU                           1U           /* Number of MSA RG's per XPU */

/* Uncomment it to disable AC Static Config*/
//#define AC_STATIC_CONFIG_DISABLE

/* Enable this only for bring up, till SafeRTOS/EL1 drivers are ready */
#define EL1_BU_CONFIGURATION
/*-------------------------------------------------------------------------
* Type Declarations
* ----------------------------------------------------------------------*/
/*-------------------------------------------------------------------------
* Function Declarations and Documentation
* ----------------------------------------------------------------------*/
 

#endif /* #ifndef AC_TARGET_CFG_H */
