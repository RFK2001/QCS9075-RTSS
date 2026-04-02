/**
 * @file log_code.h
 * @brief
 * Header file for debug macros of safety manager
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "err_fatal.h"
#include <stdlib.h>
#include "debug_log.h"
#include "HALhwio.h"
#include "common_functions.h"


#ifndef SAIL_PROC_BSP_COMMON_INC_LOG_CODE_H_
#define SAIL_PROC_BSP_COMMON_INC_LOG_CODE_H_


/* Shared memory partitiions *//* 450 bytes of SM in use */
#define LOGCODE_LIB_MEM                             LOGCODE_STARTADDR
#define LOGCODE_SAIL_BOOT_SIZE                      (0x14U)// 20 bytes 

#define LOGIC_MD_BOOT_STATUS_ADDR                   (LOGCODE_LIB_MEM + LOGCODE_SAIL_BOOT_SIZE)
#define LOGCODE_MD_BOOT_SIZE                        (0x14U)// 20 bytes 

#define LOGCODE_UPDATE_MEM                          (LOGIC_MD_BOOT_STATUS_ADDR + LOGCODE_MD_BOOT_SIZE)
#define LOGCODE_UPDATE_MEM_SIZE                     (0x14U)// 20 bytes

#define LOGCODE_TIMESTAMP_ADDR                      (LOGCODE_UPDATE_MEM + LOGCODE_UPDATE_MEM_SIZE)
#define LOGCODE_TIMESTAMP_MEM_SIZE                  (0x12CU)//300bytes

#define LOGCODE_TIMESTAMP_CORE_ADDR                 (LOGCODE_TIMESTAMP_ADDR + LOGCODE_TIMESTAMP_MEM_SIZE)
#define LOGCODE_TIMESTAMP_CORE_SIZE                 (0x32U)//50bytes

#define LOGCODE_UART_VIP_BOOT_STATUS                (LOGCODE_TIMESTAMP_CORE_ADDR + LOGCODE_TIMESTAMP_CORE_SIZE)
#define LOGCODE_UART_VIP_BOOT_STATUS_MEM_SIZE       (0x1EU)//30bytes

#define LOGCODE_TEMP_SENSOR                         (LOGCODE_UART_VIP_BOOT_STATUS + LOGCODE_UART_VIP_BOOT_STATUS_MEM_SIZE)
#define LOGCODE_TEMP_SENSOR_MEM_SIZE                (0x5U)//5bytes

#define LOGCODE_ERR_FATAL_READ_DTB_ADDR             (LOGCODE_TEMP_SENSOR + LOGCODE_TEMP_SENSOR_MEM_SIZE)
#define LOGCODE_ERR_FATAL_READ_DTB_MEM_SIZE         (0x5U)//5bytes

enum Module_Id_e{SAIL_BOOT_MILESTONES ,
 CPU_LOAD ,
 RGMI_LINK_UP_TEST ,
 OSPI_READ_RESULTS ,
 SM_ERR_DIAGNOSTICS ,
 TEMP_SENSOR ,
 MD_BOOT_MILESTONES,
 DV_TEST 
 };

typedef enum{CORE1_RELEASE = 1 ,
CORE2_RELEASE = 2 ,
CORE3_RELEASE = 3 ,
CORE1_START = 5 ,
CORE2_START = 6 ,
CORE3_START = 7 ,
CORE0_EL1_LOAD = 8 ,
CORE1_EL1_LOAD = 9 ,
CORE2_EL1_LOAD = 10 ,
CORE3_EL1_LOAD = 11 ,
CORE0_EL1_START = 12 ,
CORE1_EL1_START = 13 ,
CORE2_EL1_START = 14 ,
CORE3_EL1_START = 15 ,
SAIL_BIST_STATUS = 16 ,
MD_BIST_STATUS = 17 ,
R52_DIAGNOSTICS = 18 ,
ASILD_PMIC = 19 ,
CPR_INIT = 20 ,
CRASH_DBG = 21 ,
SKIP_SAIL_BIST = 22,
SKIP_MD_BIST = 23,
EXT_MAILBOX = 24 ,
INT_MAILBOX = 25 ,
WDOG_INIT = 26 ,
ULS = 27 ,
VIP_UART = 28 ,
DBG_UART = 29 ,
I2C = 30 ,
SPI = 31 ,
SAFETY_MONITOR = 32 ,
CMU = 33 ,
TSENS_INIT = 34 ,
VSENS = 35 ,
TRUSENS = 36 ,
FUSA_STATUS = 37 
}SAIL_BOOT_STATUS_e;

typedef enum{
CORE0_EL2_START = 0,
PMIC_START = 1,
PMIC_END = 2,
SPI_NOR_START = 3,
SPI_NOR_END = 4,
BIST_PH1_START = 5,
BIST_PH1_END = 6,
BIST_PH2_START =7,
BIST_PH2_END = 8,
SBL_START = 9,
CORE1_EL2_START = 10,
CORE2_EL2_START = 11,
CORE3_EL2_START = 12,
CORE1_EL1_LOAD_START = 13,
CORE2_EL1_LOAD_START = 14,
CORE3_EL1_LOAD_START = 15,
CORE1_EL1_LOAD_END = 16,
CORE2_EL1_LOAD_END = 17,
CORE3_EL1_LOAD_END = 18,
CORE1_EL2_END = 19,
CORE2_EL2_END = 20,
CORE3_EL2_END = 21,
CORE1_EL1_STARTS = 22,
CORE2_EL1_STARTS = 23,
CORE3_EL1_STARTS = 24,
CORE0_EL1_LOAD_START = 25,
CORE0_EL1_LOAD_END = 26,
SBL_END = 27,
CORE0_EL2_END = 28,
CORE0_EL1_STARTS = 29,
CORE1_HLOS_KERNEL_START = 30,
CORE2_HLOS_KERNEL_START = 31,
CORE3_HLOS_KERNEL_START = 32,
CORE0_HLOS_KERNEL_START = 33,
SAIL_CAN_READY = 34,
SAIL_DDR_READY = 35,
SAIL_TZ_READY = 36,
SAIL_S1_READY = 37,
DEFAULT_BOOT_STATUS =38,
eSAIL_BSTAGE_MAX,
}BOOT_STAGE_e;


typedef enum 
{
    LC_MD_DDR_READY     = 0U,
    LC_MD_XBLSEC_BOOT   = 1U,
    LC_MD_XBLLDR_BOOT   = 2U,
    LC_MD_TZ_BOOT       = 3U,
    LC_MD_QCPE_BOOT     = 4U,
    LC_MD_QHEE_BOOT     = 5U,
    LC_MD_UEFI_BOOT     = 6U,
    LC_MD_ABL_BOOT      = 7U,
    LC_MD_ADSP_BOOT     = 8U,
    LC_MD_PSAIL_FAULT   = 9U,
    LC_MD_HLOS_RDY      = 10U

}MD_BOOT_STAGE_VALUE_e;

typedef enum
{
    VIP_BID_INIT_STATUS = 0u,
    MCU_BOARD_ID,            
    MAIN_BOARD_ID,           
    S1_SOC_BOARD_ID,         
    S1_SIP_BOARD_ID0,        
    S1_SIP_BOARD_ID1,        
    S2_SOC_BOARD_ID,         
    S2_SIP_BOARD_ID0,        
    S2_SIP_BOARD_ID1,        
    S3_BOARD_ID,             
    S4_BOARD_ID,             
    CAN_BOARD_ID,            
    ENET_BOARD_ID,           
    FPGA_BOARD_ID,           
    DISPLAY_BOARD_ID,        
    S2_DISPLAY_BOARD_ID,     
    CAMERA_BOARD_ID,         
    WLAN_BOARD_ID,           
    PCIE_BOARD_ID,           
    AUDIO_BOARD_ID,          
    SAIL_ENET_BOARD_ID,      
    MCU_ENET_BOARD_ID,       
    SENSOR_BOARD_ID,         
    MAX_BID_LIMIT
}BID_INFORMATON_e;

enum LOG_LEVEL_e{FAIL ,PASS};


//Macros for Common Sizes

#define CONST_2				(1 << 1)
#define CONST_4				(1 << 2)
#define CONST_8				(1 << 3)
#define CONST_1             (1 << 0)
#define CONST_16			(1 << 4)
#define CONST_5			    5
#define CONST_6			    6
#define CONST_9			    9
#define CONST_10			10
#define CONST_11		    11
#define CONST_32			(1 << 5)
#define CONST_255			((1 << 8) - 1) 
#define CONST_256			(1 << 8)
#define CONST_127			((1 << 7) - 1)
#define CONST_1000			1000
#define CONST_20000			20000
#define CONST_50000			50000
#define CONST_31			((1 << 5) - 1)
#define CONST_127			((1 << 7) - 1)
#define CONST_3			    ((1 << 2) - 1)
#define CONST_24			24
#define CONST_23			23
#define CONST_40			40
#define CONST_63			((1 << 6) - 1) 

#define socBOOT_PACKET_LENGTH					0x12
#define BID_INFO_MAGIC_NUM                      0xababcdcdu
#define BID_INFO_INIT_DONE						0x1u
#define START_INDEX_BID_INFO                    0x5u
#define END_INDEX_MAGIC_NUM                     0xDu

#define COMMON_MAJOR_VERSION_BID         1
#define COMMON_MINOR_VERSION_BID         2
#define COMMON_SUB_MINOR_VERSION_BID     8

#define THESHOLD_VIP_FIRMWARE_VERSION_BID_INFO (COMMON_MAJOR_VERSION_BID*100u+COMMON_MINOR_VERSION_BID*10u+COMMON_SUB_MINOR_VERSION_BID)

/* Log Code API'S*/
int vLcWriteLogCode (enum Module_Id_e mid ,enum LOG_LEVEL_e status ,uint32_t *pudata ,uint8_t uclength);
uint8_t* LcReadLogCode (enum Module_Id_e mid);
void ErrFatal_Readdtb( void );
/*Timestamp API */
void vLCWriteTimeStamp(BOOT_STAGE_e bid ,uint64_t ultime_stamp);

/*API to capture varoius errors*/
void vLCWriteErrorCode(MODULE_ID mod_id ,uint8_t core_id , uint32_t error_id) ;

#endif /* SAIL_PROC_BSP_COMMON_INC_LOG_CODE_H_ */


