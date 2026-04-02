/**************************************************************************************************
    Copyright (c) 2023-2025 Qualcomm Technologies, Inc.
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : sail_mem_map.h
    Component Name     : sail memory map
    Description        : Header file for sail memory map
    $Header: 
    $DateTime: 
    $Author: 
==================================================================================================*/
/* Include header file guard */
#ifndef SAIL_MEM_MAP_H
#define SAIL_MEM_MAP_H

#include <types.h>
#include <stdbool.h>

/*==================================================================================================
**                                      Macros                                                    **
==================================================================================================*/
#define SAILBSP_MEMORY_SIZE             0x000FA000UL  /* SAIL HYP Memory Size - 900KB (100KB reserved for PBL) */
#define SAILBSP_MEMORY_ADDR             0x08000000UL  /* Start of SAIL memory region. */
#define SAILBSP_ENTRY_BASE              0x0801D400UL  /* SAIL Entry point. */
#define SAILBSP_EL2_SRAM_START          SAILBSP_ENTRY_BASE  /* SAIL EL2 SRAM Start Address */
// Changing SAILBSP_EL2_SRAM_END address for Autosar Sailhyp image (using sailhyp's LR5 region for autosarsailsw1 image)
//	no change for SafeRTOS sailhyp
#ifdef SAIL_CASAR
#define SAILBSP_EL2_SRAM_END            0x080D3800UL  /* SAIL EL2 SRAM End Address */
#else
#define SAILBSP_EL2_SRAM_END            0x080FA000UL  /* SAIL EL2 SRAM End Address */
#endif

#define SAILBSP_EL1_SRAM_1_START        SAILBSP_MEMORY_ADDR /* Because EL1 now reuses PBL region */
#define SAILBSP_EL1_SRAM_1_END          0x08019000UL
#define SAILBSP_EL1_SRAM_1_RO_SIZE      0xC800
#define SAILBSP_EL1_SRAM_2_START        SAILBSP_EL2_SRAM_END
#define SAILBSP_EL1_SRAM_2_END          0x08300000UL

#define SAILBSP_DDR_MEMORY_START        0x30000000UL
#define SAILBSP_DDR_MEMORY_END          0xC0000000UL
/* DDR Early Access Memory which is available to use when MD sends S1 map ready to SAIL */
#define SAILBSP_DDR_1_EA_MEMORY_START   0x20000000UL
#define SAILBSP_SRV1_EA_MEMORY_START    0x2D000000UL
#define SAILBSP_DDR_2_EA_MEMORY_START   0x30C00000UL
#define SAILBSP_DDR_EA_MEMORY_END       0x30000000UL
/* Offset between MD DDR map and SAIL mapped MD DDR map, MD DDR addresses are mapped to lower addresses for SAIL usage */
#define SAILBSP_DDR_EA_OFFSET           0x60000000UL

/* Freertos init macros */
#define FreeRTOS_0_GIC_FLAG_MEM_ADD       0x082FBF80U
#define FreeRTOS_1_GIC_FLAG_MEM_ADD       0x082FBFc0U

#define EL_SHARED_CACHELINE_SIZE            128U                /* safe value, same as mutex */
#define HYP_DEBUGLOG_MEM_INDEX_ADDR         (EL_SHARED_AREA_STARTADDRESS)
#define OS_DEBUGLOG_MEM_INDEX_ADDR          (HYP_DEBUGLOG_MEM_INDEX_ADDR + EL_SHARED_CACHELINE_SIZE)
#define DEBUGLOG_UART_WRINDEX_ADDR          (OS_DEBUGLOG_MEM_INDEX_ADDR + EL_SHARED_CACHELINE_SIZE)
#define DEBUGLOG_UART_RDINDEX_ADDR          (DEBUGLOG_UART_WRINDEX_ADDR + EL_SHARED_CACHELINE_SIZE)
#define DEBUGLOG_UART_READYSTATE_ADDR       (DEBUGLOG_UART_RDINDEX_ADDR + EL_SHARED_CACHELINE_SIZE)
#define OSPI_EL1_MUTEX_ADDR                 (DEBUGLOG_UART_READYSTATE_ADDR + EL_SHARED_CACHELINE_SIZE)
#define DMA_CRC_EL1_SHARED_ADDR             (OSPI_EL1_MUTEX_ADDR + EL_SHARED_CACHELINE_SIZE)
#define DMA_CRC_EL1_MUTEX_ADDR              (DMA_CRC_EL1_SHARED_ADDR + EL_SHARED_CACHELINE_SIZE)
#define VSENS_RAM_LOG_ADDR                  (DMA_CRC_EL1_MUTEX_ADDR + EL_SHARED_CACHELINE_SIZE)
#define XBL_EL1_MUTEX_ADDR                  (VSENS_RAM_LOG_ADDR + EL_SHARED_CACHELINE_SIZE)
#define WARM_BOOT_STATUS                    (XBL_EL1_MUTEX_ADDR + EL_SHARED_CACHELINE_SIZE)
#define SLEEP_CORE_STATUS                   (XBL_EL1_MUTEX_ADDR + 4u)
#define TGB_BOOT_STATUS                     (SLEEP_CORE_STATUS + 4u)
#define PSAIL_ERROR_STATUS                  (TGB_BOOT_STATUS + 4u)


/*Once the test framework is available the below macro can be removed.*/
#define Dhrystone_temporary_location         (WARM_BOOT_STATUS + EL_SHARED_CACHELINE_SIZE)
#define CPU0_STATUS_CHECK_LOCATION           (Dhrystone_temporary_location+ EL_SHARED_CACHELINE_SIZE)
#define CPU1_STATUS_CHECK_LOCATION           (Dhrystone_temporary_location+ 4U)
#define CPU2_STATUS_CHECK_LOCATION           (Dhrystone_temporary_location+ 4U)
#define UART_DEBUG_CONNECTION_STATUS         (CPU2_STATUS_CHECK_LOCATION + 4U)
#define UART_CONNECTION_TEST                 (UART_DEBUG_CONNECTION_STATUS + 4U)
#define SAILAC_INIT_STATUS                   (UART_CONNECTION_TEST + 4U)
#define MD_BOOT_CHECK                        (SAILAC_INIT_STATUS + 4U)
#define BID_INFORMATION_FROM_VIP             (MD_BOOT_CHECK+4u)
#define BID_INFORMATION_END                  (BID_INFORMATION_FROM_VIP+EL_SHARED_CACHELINE_SIZE)
#define FreeRTOS_0_SPIN_LOCK_MEM_ADD         (CPU0_STATUS_CHECK_LOCATION+EL_SHARED_CACHELINE_SIZE+EL_SHARED_CACHELINE_SIZE)
#define FreeRTOS_1_SPIN_LOCK_MEM_ADD         (FreeRTOS_0_SPIN_LOCK_MEM_ADD+EL_SHARED_CACHELINE_SIZE)
#define SHR_DEEP_SLEEP                       (FreeRTOS_1_SPIN_LOCK_MEM_ADD+EL_SHARED_CACHELINE_SIZE)
#define FREERTOS_TASK_LOCK_MEM_ADD           (SHR_DEEP_SLEEP+EL_SHARED_CACHELINE_SIZE)
#define FREERTOS_ISR_LOCK_MEM_ADD            (FREERTOS_TASK_LOCK_MEM_ADD+EL_SHARED_CACHELINE_SIZE)
/** 
 * TCM Memory range
 *
 */
#define SAILBSP_CORE0_ATCM_START        0x02000000UL
#define SAILBSP_CORE3_CTCM_END          0x03680000UL

/* Source address and size SAIL R52 TCM memories */
#define SAIL_CORE0_ATCM_START             (0x02000000U)
#define SAIL_CORE0_BTCM_START             (0x02100000U)
#define SAIL_CORE0_CTCM_START             (0x02200000U)
#define SAIL_CORE1_ATCM_START             (0x02400000U)
#define SAIL_CORE1_BTCM_START             (0x02500000U)
#define SAIL_CORE1_CTCM_START             (0x02600000U)
#define SAIL_CORE2_ATCM_START             (0x03000000U)
#define SAIL_CORE2_BTCM_START             (0x03100000U)
#define SAIL_CORE2_CTCM_START             (0x03200000U)
#define SAIL_ATCM_SIZE                    (0x10000) /* 64KB */
#define SAIL_BTCM_SIZE                    (0x8000)  /* 32KB */
#define SAIL_CTCM_SIZE                    (0x8000)  /* 32KB */

/** 
 * R52 DMA memory regions.
 *
 */
#define SAILBSP_EL2_DMA_MEMORY_START    0x02000000UL
#define SAILBSP_EL2_DMA_MEMORY_END      0x03000000UL
#define SAILBSP_EL1_DMA_MEMORY_START    0x03000000UL
#define SAILBSP_EL1_DMA_MEMORY_END      0x04000000UL

#ifdef SAIL_CASAR
	/* AUTOSAR build toggle AC config address */
	/* 	EMAC 256K: 0x828E400 + 40000U
		CAN 32K: 0x82CE400 + 8000U */
  #define AC_ENABLE_EMAC_CARVEOUT           0x1U
  #define SAILBSP_EMAC_EL1_SRAM_START       0x082A4000UL //0x0828E400UL
  #define SAILBSP_EMAC_EL1_SRAM_END         SAILBSP_EMAC_EL1_SRAM_START+0x33000UL//SAILBSP_EMAC_EL1_SRAM_START+0x40000UL 
  #define AC_ENABLE_CAN_CARVEOUT            0x1U
  #define SAILBSP_CAN_EL1_SRAM_START        0x0829C000UL //0x082CE400UL 
  #define SAILBSP_CAN_EL1_SRAM_END          SAILBSP_CAN_EL1_SRAM_START+0x8000UL
#endif

/** 
 * DDR Early Availability carveout memory regions for DMA domains.
 * 
 */
#define SAILBSP_CAN_DDREA_START         0x2F000000UL
#define SAILBSP_CAN_DDREA_END           0x2F800000UL
#define SAILBSP_OSPI_DDREA_START        0x20000000UL
#define SAILBSP_OSPI_DDREA_END          0x2D800000UL //SAIL Tests + OEM App Data
#define SAILBSP_EMAC_DDREA_START        0x2E000000UL
#define SAILBSP_EMAC_DDREA_END          0x2E800000UL

/** 
 * DDR carveout memory regions for DMA domains.
 *
 */
#define SAILBSP_OSPI_DDR_START          0x30E00000UL
#define SAILBSP_OSPI_DDR_END            0x31400000UL //START -- End of MD OSPI NOR mini-dump log area


#define SAILBSP_QUP_MEM_START      0x01F00000
#define SAILBSP_QUP_MEM_SIZE       0x6000

/* QUM RAM Reservation*/
/*Debug Logs*/
#define HYP_DEBUGLOG_STARTADDRESS           0x01F00000U
#define HYP_DEBUGLOG_SIZE                   0x1300U             /* 4.75KB */
#define HYP_DEBUGLOG_EXTRA_SIZE             0x0100U             /* .25KB */

#define OS_DEBUGLOG_STARTADDRESS            0x01F01400U
#define OS_DEBUGLOG_SIZE                    0x3800U             /* 14.0KB */
#define OS_DEBUGLOG_EXTRA_SIZE              0x0400U             /* 1.0KB */

#define EL_SHARED_AREA_STARTADDRESS         0x082FB000U         /* defined in sailhyp.lds */
#define EL_SHARED_AREA_SIZE                 0x1000U             /* 4KB */

/* DTB memory reservation */
#define EL2_DTB_STARTADDRESS                0x08019000U   /* 32KB */
#define EL2_DTBO_STARTADDRESS               NULL          /* 8KB */

#define SW1_DTB_STARTADDRESS                0x082DC400U   /* 16KB */
#define SW1_DTBO_STARTADDRESS               NULL          /* 8KB */

#define SW2_DTB_STARTADDRESS                0x082D8400U   /* 16KB */
#define SW2_DTBO_STARTADDRESS               NULL          /* 8KB */

#define SW3_DTB_STARTADDRESS                0x082D6400U   /* 8KB */
#define SW3_DTBO_STARTADDRESS               NULL          /* 8KB */

/* Sec ELF and DBG Policy */
#define MANDATORY_SEC_ELF_LR1_START 0x082FF000U
#define MANDATORY_SEC_ELF_LR1_SIZE  0x1000U  // 4KB

#define MANDATORY_DBG_POLICY_LR1_START 0x082FC000U
#define MANDATORY_DBG_POLICY_LR1_SIZE  0x3000U  // 12KB

/* LogCode SM Reservation*/
#define LOGCODE_STARTADDR                      (0x082FAC00U)
#define LOGCODE_SIZE                           (0x400U)

#define UART_SHARED_AREA_STARTADDRESS     0x082F9C00U         /* UART Log info */
#define UART_SHARED_LOG_SIZE              0x1000U

/* UART driver*/
#define UART_TXBUFF_STARTADDR             0x01F05000U
#define UART_TXBUFF_SIZE				  0xFFU
#define UART_RXBUFF_STARTADDR             0x01F05100U
#define UART_RXBUFF_SIZE				  0xFFU

#define UART_VIP_TX_STARTADDR             0x01F05200U
#define UART_VIP_TX_SIZE				  0xFFU
#define UART_VIP_RX_STARTADDR             0x01F05300U
#define UART_VIP_RX_SIZE				  0xFFU

#define SPI_TX_DMA_ADDR					  0x01F05900
#define SPI_RX_DMA_ADDR 				  0x01F05a00

#define I2C_TX_DMA_ADDR                   0x01F05700
#define I2C_RX_DMA_ADDR                   0x01F05800

#if defined(__ARM_GNU__)
    /* BSP Global Data */
    extern uint32_t lnk_bsp_global_data_start_addr;
    extern uint32_t lnk_bsp_global_data_end_addr;
    #define SAILBSP_GLOBAL_DATA_ADDR_BASE   (uint32_t)(&lnk_bsp_global_data_start_addr)
    #define SAILBSP_GLOBAL_DATA_ADDR_SIZE   (uint32_t)((uint32_t)(&lnk_bsp_global_data_end_addr) - (uint32_t)(&lnk_bsp_global_data_start_addr))
#elif defined(__ARM_FUSA__)
    /* BSP Global Data */
    extern uint32_t Image$$lnkBSP_GLOBAL_DATAStartAddr$$ZI$$Base;
    extern uint32_t Image$$lnkBSP_GLOBAL_DATAEndAddr$$ZI$$Base;
    #define SAILBSP_GLOBAL_DATA_ADDR_BASE    (uint32_t)&Image$$lnkBSP_GLOBAL_DATAStartAddr$$ZI$$Base
    #define SAILBSP_GLOBAL_DATA_ADDR_SIZE    (uint32_t)( (uint32_t)&Image$$lnkBSP_GLOBAL_DATAEndAddr$$ZI$$Base -\
                                                                (uint32_t)&Image$$lnkBSP_GLOBAL_DATAStartAddr$$ZI$$Base )
#else
    #error "Unknown Linker Symbols Format"
#endif

#define BSP_GLOBAL_DATA __attribute__ ( ( section ( "bsp_global_data" ) ) )

#endif /* SAIL_MEM_MAP_H  */
