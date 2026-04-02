/**********************************************************************************************************
    Copyright (c) 2023 Qualcomm Technologies, Inc.
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
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : Compiler_Cfg.h
    Component Name     : STD
    Description        : The file Compiler_Cfg.h allows to configure these defines with the appropriate 
                         compiler specific keywords according to the modules description and memory 
                         set-up of the build scenario.
    $Header: $
    $DateTime: 2022/07/07 12:35:03 $
    $Author: pwbldsvc $
=========================================================================================================*/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H
/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/


/*=========================================================================================================
**                                         defines and macros                                            **
=========================================================================================================*/

/*------------------< Component Identification >------------------*/

#define AUTOSAR_COMPILER_CFG_VENDOR_ID                    0U
#define AUTOSAR_COMPILER_CFG_MODULE_ID                    198U
#define AUTOSAR_COMPILER_CFG_RELEASE_MAJOR_VERSION        22U
#define AUTOSAR_COMPILER_CFG_RELEASE_MINOR_VERSION        11U
#define AUTOSAR_COMPILER_CFG_RELEASE_REVISION_VERSION     0U
#define COMPILER_CFG_SW_MAJOR_VERSION                     1U
#define COMPILER_CFG_SW_MINOR_VERSION                     0U
#define COMPILER_CFG_SW_PATCH_VERSION                     0U

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/

/*------------------< SPI memory class and pointer class  >------------------*/
/*
* @brief        : SPI memory class (memclass) and pointer class (ptrclass) macro parameter
* @implements   : Each AUTOSAR software module and application software component shall 
                  support the distinction of at least the following different memory classes and pointer classes.
				  It is allowed to add module specific memory classes and pointer classes as they are 
                  mapped and thus are configurable within the Compiler_Cfg.h file.
* @Requirements : [SWS_COMPILER_00040]
*/

/*
* @brief        : To be used for code.
* @implements   : <PREFIX>_CODE[_<PERIOD>] --> [_<PERIOD>] is optional.
* @Requirements : 
*/
#define SPI_CODE

/*
* @brief        : To be used for callout code
* @implements   : <PREFIX>_<CN>_CODE
*                 <CN> is the callback name (including module reference) written in uppercase letters.                  
* @Requirements : 
*/
#define SPI_CALLOUT_CODE

/*
* @brief        : To be used for code that shall go into fast code memory segments.
                  The FAST sections should be used when the execution does not happen in a well defined 
				  period time but with the knowledge of high frequent access and /or high execution time, 
				  for example, a callback for a frequent notification. 
* @implements   : <PREFIX>_CODE_FAST
* @Requirements : 
*/
#define SPI_CODE_FAST

/*
* @brief        : To be used for code that shall go into slow code memory segments.
                  The SLOW sections should be used when the execution does not happen in a well defined 
				  period time but with the knowledge of low frequent access  
				  for example, a callback in case of seldom error 
* @implements   : <PREFIX>_CODE_SLOW
* @Requirements : 
*/
#define SPI_CODE_SLOW

/*
* @brief        : To be used for global or static constants
* @implements   : <PREFIX>_CONST.
* @Requirements : 
*/
#define SPI_CONST

/*
* @brief        : To be used for calibration constants.
* @implements   : <PREFIX>_CALIB.
* @Requirements : 
*/
#define SPI_CALIB

/*
* @brief        : To be used for module configuration constants.
* @implements   :  <PREFIX>_CONFIG_DATA
* @Requirements : 
*/
#define SPI_CONFIG_DATA

/*
* @brief        : To be used for ROM buffers of variables saved in non-volatile memory. X shall be 
                  replaced with the number of bytes (i.e. 8,16 or 32).
* @implements   :  <PREFIX>_CONST_SAVED_RECOVERY_ZONE<X>
* @Requirements : 
*/
#define SPI_CONST_SAVED_RECOVERY_ZONE8
#define SPI_CONST_SAVED_RECOVERY_ZONE16
#define SPI_CONST_SAVED_RECOVERY_ZONE32

/*
* @brief        : To be used for references on application data (expected to be in RAM or ROM) 
                  passed via API 
* @implements   : <PREFIX>_APPL_DATA
* @Requirements : 
*/
#define SPI_APPL_DATA

/*
* @brief        : To be used for references on application constants (expected to be certainly in 
                  ROM, for instance pointer of Init-function) passed via API. 
* @implements   : <PREFIX>_APPL_CONST
* @Requirements : 
*/
#define SPI_APPL_CONST

#define SPI_VAR

/*
* @brief        : INIT: Used for variables that are initialized with values after every reset.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define SPI_VAR_INIT

/*
* @brief        : NO_INIT: Used for variables that are never cleared and never initialized.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define SPI_VAR_NO_INIT

/*
* @brief        : POWER_ON_INIT: Used for variables that are initialized with values only after power on reset.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define SPI_VAR_POWER_ON_INIT

/*
* @brief        : CLEARED: Used for variables that are cleared to zero after every reset.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define SPI_VAR_CLEARED

/*
* @brief        : POWER_ON_CLEARED: Used for variables that are cleared to zero only after power on reset
                  To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define SPI_VAR_POWER_ON_CLEARED

/*
* @brief        : To be used for all global or static variables that have at least one of the Following properties:
                  - Accessed bitwise.
                  - Frequently used.
                  - High number of accesses in source code.
                  Some platforms allow the use of bit instructions for variables located in this 
                  specific RAM area as well as shorter addressing instructions. This saves code 
                  and runtime.
* @implements   :  <PREFIX>_VAR_FAST_<INIT_POLICY>
* @Requirements : 
*/
#define SPI_VAR_FAST
#define SPI_VAR_FAST_NO_INIT
#define SPI_VAR_FAST_CLEARED
#define SPI_VAR_FAST_POWER_ON_INIT
#define SPI_VAR_FAST_INIT
#define SPI_VAR_FAST_POWER_ON_CLEARED

/*
* @brief        : To be used for all infrequently accessed global or static variables.
* @implements   : <PREFIX>_VAR_SLOW_<INIT_POLICY>
* @Requirements : 
*/
#define SPI_VAR_SLOW
#define SPI_VAR_SLOW_NO_INIT
#define SPI_VAR_SLOW_CLEARED
#define SPI_VAR_SLOW_POWER_ON_INIT
#define SPI_VAR_SLOW_INIT
#define SPI_VAR_SLOW_POWER_ON_CLEARED

/*
* @brief        : To be used for global or static variables which are accessible from a calibration tool.
* @implements   : <PREFIX>_INTERNAL_VAR_<INIT_POLICY>
* @Requirements : 
*/
#define SPI_INTERNAL_VAR
#define SPI_INTERNAL_VAR_NO_INIT
#define SPI_INTERNAL_VAR_CLEARED
#define SPI_INTERNAL_VAR_POWER_ON_INIT
#define SPI_INTERNAL_VAR_INIT
#define SPI_INTERNAL_VAR_POWER_ON_CLEARED

/*
* @brief        : To be used for RAM buffers of variables saved in non-volatile memory. X shall be 
                  replaced with the number of bytes (i.e. 8,16 or 32).
* @implements   : <PREFIX>_VAR_SAVED_ZONE<X>
* @Requirements : 
*/
#define SPI_VAR_SAVED_ZONE8
#define SPI_VAR_SAVED_ZONE16
#define SPI_VAR_SAVED_ZONE32

/*
* @brief        : UART memory class (memclass) and pointer class (ptrclass) macro parameter
* @implements   : Each AUTOSAR software module and application software component shall 
                  support the distinction of at least the following different memory classes and pointer classes.
				  It is allowed to add module specific memory classes and pointer classes as they are 
                  mapped and thus are configurable within the Compiler_Cfg.h file.
* @Requirements : [SWS_COMPILER_00040]
*/

/*------------------< CDD UART memory class and pointer class  >------------------*/


/*
* @brief        : To be used for code.
* @implements   : <PREFIX>_CODE[_<PERIOD>] --> [_<PERIOD>] is optional.
* @Requirements : 
*/
#define CDD_UART_CODE

/*
* @brief        : To be used for callout code
* @implements   : <PREFIX>_<CN>_CODE
*                 <CN> is the callback name (including module reference) written in uppercase letters.                  
* @Requirements : 
*/
#define CDD_UART_CALLOUT_CODE

/*
* @brief        : To be used for code that shall go into fast code memory segments.
                  The FAST sections should be used when the execution does not happen in a well defined 
				  period time but with the knowledge of high frequent access and /or high execution time, 
				  for example, a callback for a frequent notification. 
* @implements   : <PREFIX>_CODE_FAST
* @Requirements : 
*/
#define CDD_UART_CODE_FAST

/*
* @brief        : To be used for code that shall go into slow code memory segments.
                  The SLOW sections should be used when the execution does not happen in a well defined 
				  period time but with the knowledge of low frequent access  
				  for example, a callback in case of seldom error 
* @implements   : <PREFIX>_CODE_SLOW
* @Requirements : 
*/
#define CDD_UART_CODE_SLOW

/*
* @brief        : To be used for global or static constants
* @implements   : <PREFIX>_CONST.
* @Requirements : 
*/
#define CDD_UART_CONST

/*
* @brief        : To be used for calibration constants.
* @implements   : <PREFIX>_CALIB.
* @Requirements : 
*/
#define CDD_UART_CALIB

/*
* @brief        : To be used for module configuration constants.
* @implements   :  <PREFIX>_CONFIG_DATA
* @Requirements : 
*/
#define CDD_UART_CONFIG_DATA

/*
* @brief        : To be used for ROM buffers of variables saved in non-volatile memory. X shall be 
                  replaced with the number of bytes (i.e. 8,16 or 32).
* @implements   :  <PREFIX>_CONST_SAVED_RECOVERY_ZONE<X>
* @Requirements : 
*/
#define CDD_UART_CONST_SAVED_RECOVERY_ZONE8
#define CDD_UART_CONST_SAVED_RECOVERY_ZONE16
#define CDD_UART_CONST_SAVED_RECOVERY_ZONE32

/*
* @brief        : To be used for references on application data (expected to be in RAM or ROM) 
                  passed via API 
* @implements   : <PREFIX>_APPL_DATA
* @Requirements : 
*/
#define CDD_UART_APPL_DATA

/*
* @brief        : To be used for references on application constants (expected to be certainly in 
                  ROM, for instance pointer of Init-function) passed via API. 
* @implements   : <PREFIX>_APPL_CONST
* @Requirements : 
*/
#define CDD_UART_APPL_CONST

#define CDD_UART_VAR

/*
* @brief        : INIT: Used for variables that are initialized with values after every reset.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define CDD_UART_VAR_INIT

/*
* @brief        : NO_INIT: Used for variables that are never cleared and never initialized.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define CDD_UART_VAR_NO_INIT

/*
* @brief        : POWER_ON_INIT: Used for variables that are initialized with values only after power on reset.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define CDD_UART_VAR_POWER_ON_INIT

/*
* @brief        : CLEARED: Used for variables that are cleared to zero after every reset.
*                 To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define CDD_UART_VAR_CLEARED

/*
* @brief        : POWER_ON_CLEARED: Used for variables that are cleared to zero only after power on reset
                  To be used for all global or static variables.
* @implements   : 
* @Requirements : 
*/
#define CDD_UART_VAR_POWER_ON_CLEARED

/*
* @brief        : To be used for all global or static variables that have at least one of the Following properties:
                  - Accessed bitwise.
                  - Frequently used.
                  - High number of accesses in source code.
                  Some platforms allow the use of bit instructions for variables located in this 
                  specific RAM area as well as shorter addressing instructions. This saves code 
                  and runtime.
* @implements   :  <PREFIX>_VAR_FAST_<INIT_POLICY>
* @Requirements : 
*/
#define CDD_UART_VAR_FAST
#define CDD_UART_VAR_FAST_NO_INIT
#define CDD_UART_VAR_FAST_CLEARED
#define CDD_UART_VAR_FAST_POWER_ON_INIT
#define CDD_UART_VAR_FAST_INIT
#define CDD_UART_VAR_FAST_POWER_ON_CLEARED

/*
* @brief        : To be used for all infrequently accessed global or static variables.
* @implements   : <PREFIX>_VAR_SLOW_<INIT_POLICY>
* @Requirements : 
*/
#define CDD_UART_VAR_SLOW
#define CDD_UART_VAR_SLOW_NO_INIT
#define CDD_UART_VAR_SLOW_CLEARED
#define CDD_UART_VAR_SLOW_POWER_ON_INIT
#define CDD_UART_VAR_SLOW_INIT
#define CDD_UART_VAR_SLOW_POWER_ON_CLEARED

/*
* @brief        : To be used for global or static variables which are accessible from a calibration tool.
* @implements   : <PREFIX>_INTERNAL_VAR_<INIT_POLICY>
* @Requirements : 
*/
#define CDD_UART_INTERNAL_VAR
#define CDD_UART_INTERNAL_VAR_NO_INIT
#define CDD_UART_INTERNAL_VAR_CLEARED
#define CDD_UART_INTERNAL_VAR_POWER_ON_INIT
#define CDD_UART_INTERNAL_VAR_INIT
#define CDD_UART_INTERNAL_VAR_POWER_ON_CLEARED

/*
* @brief        : To be used for RAM buffers of variables saved in non-volatile memory. X shall be 
                  replaced with the number of bytes (i.e. 8,16 or 32).
* @implements   : <PREFIX>_VAR_SAVED_ZONE<X>
* @Requirements : 
*/
#define CDD_UART_VAR_SAVED_ZONE8
#define CDD_UART_VAR_SAVED_ZONE16
#define CDD_UART_VAR_SAVED_ZONE32

/* CAN driver */
#define CAN_CODE
#define CAN_CODE_FAST
#define CAN_CODE_SLOW
#define CAN_CONST
#define CAN_CALIB
#define CAN_CONFIG_DATA
#define CAN_APPL_DATA
#define CAN_APPL_CONST
#define CAN_VAR_NO_INIT
#define CAN_VAR_CLEARED
#define CAN_VAR_POWER_ON_CLEARED
#define CAN_VAR_INIT
#define CAN_VAR_POWER_ON_INIT
#define CAN_VAR_FAST_NO_INIT
#define CAN_VAR_FAST_CLEARED
#define CAN_VAR_FAST_POWER_ON_CLEARED
#define CAN_VAR_FAST_INIT
#define CAN_VAR_FAST_POWER_ON_INIT
#define CAN_VAR_SLOW_NO_INIT
#define CAN_VAR_SLOW_CLEARED
#define CAN_VAR_SLOW_POWER_ON_CLEARED
#define CAN_VAR_SLOW_INIT
#define CAN_VAR_SLOW_POWER_ON_INIT
#define CAN_INTERNAL_VAR_NO_INIT
#define CAN_INTERNAL_VAR_CLEARED
#define CAN_INTERNAL_VAR_POWER_ON_CLEARED
#define CAN_INTERNAL_VAR_INIT
#define CAN_INTERNAL_VAR_POWER_ON_INIT
/* Ethernet Transceiver
*/

#define ETHTRCV_CODE
#define ETHTRCV_CODE_FAST
#define ETHTRCV_CODE_SLOW
#define ETHTRCV_CONST
#define ETHTRCV_CALIB
#define ETHTRCV_CONFIG_DATA
#define ETHTRCV_APPL_DATA
#define ETHTRCV_APPL_CONST
#define ETHTRCV_VAR_NO_INIT
#define ETHTRCV_VAR_CLEARED
#define ETHTRCV_VAR_POWER_ON_CLEARED
#define ETHTRCV_VAR_INIT
#define ETHTRCV_VAR_POWER_ON_INIT
#define ETHTRCV_VAR_FAST_NO_INIT
#define ETHTRCV_VAR_FAST_CLEARED
#define ETHTRCV_VAR_FAST_POWER_ON_CLEARED
#define ETHTRCV_VAR_FAST_INIT
#define ETHTRCV_VAR_FAST_POWER_ON_INIT
#define ETHTRCV_VAR_SLOW_NO_INIT
#define ETHTRCV_VAR_SLOW_CLEARED
#define ETHTRCV_VAR_SLOW_POWER_ON_CLEARED
#define ETHTRCV_VAR_SLOW_INIT
#define ETHTRCV_VAR_SLOW_POWER_ON_INIT
#define ETHTRCV_INTERNAL_VAR_NO_INIT
#define ETHTRCV_INTERNAL_VAR_CLEARED
#define ETHTRCV_INTERNAL_VAR_POWER_ON_CLEARED
#define ETHTRCV_INTERNAL_VAR_INIT
#define ETHTRCV_INTERNAL_VAR_POWER_ON_INIT

#define RTE_CODE


/* ETH driver */
#define ETH_CODE

#define ETH_CODE_FAST

#define ETH_CODE_SLOW

#define ETH_CONST

#define ETH_CALIB

#define ETH_CONFIG_DATA

#define ETH_APPL_DATA
#define ETH_APPL_CONST
#define ETH_VAR_NO_INIT

#define ETH_VAR_CLEARED

#define ETH_VAR_POWER_ON_CLEARED

#define ETH_VAR_INIT

#define ETH_VAR_POWER_ON_INIT

#define ETH_VAR_FAST_NO_INIT

#define ETH_VAR_FAST_CLEARED

#define ETH_VAR_FAST_POWER_ON_CLEARED

#define ETH_VAR_FAST_INIT

#define ETH_VAR_FAST_POWER_ON_INIT

#define ETH_VAR_SLOW_NO_INIT

#define ETH_VAR_SLOW_CLEARED

#define ETH_VAR_SLOW_POWER_ON_CLEARED

#define ETH_VAR_SLOW_INIT

#define ETH_VAR_SLOW_POWER_ON_INIT

#define ETH_INTERNAL_VAR_NO_INIT

#define ETH_INTERNAL_VAR_CLEARED

#define ETH_INTERNAL_VAR_POWER_ON_CLEARED

#define ETH_INTERNAL_VAR_INIT

#define ETH_INTERNAL_VAR_POWER_ON_INIT


/* RTE driver */
#define RTE_CODE

#define RTE_CODE_FAST

#define RTE_CODE_SLOW

#define RTE_CONST

#define RTE_CALIB

#define RTE_CONFIG_DATA

#define RTE_APPL_DATA
#define RTE_APPL_CONST
#define RTE_VAR_NO_INIT

#define RTE_VAR_CLEARED

#define RTE_VAR_POWER_ON_CLEARED

#define RTE_VAR_INIT

#define RTE_VAR_POWER_ON_INIT

#define RTE_VAR_FAST_NO_INIT

#define RTE_VAR_FAST_CLEARED

#define RTE_VAR_FAST_POWER_ON_CLEARED

#define RTE_VAR_FAST_INIT

#define RTE_VAR_FAST_POWER_ON_INIT

#define RTE_VAR_SLOW_NO_INIT

#define RTE_VAR_SLOW_CLEARED

#define RTE_VAR_SLOW_POWER_ON_CLEARED

#define RTE_VAR_SLOW_INIT

#define RTE_VAR_SLOW_POWER_ON_INIT

#define RTE_INTERNAL_VAR_NO_INIT

#define RTE_INTERNAL_VAR_CLEARED

#define RTE_INTERNAL_VAR_POWER_ON_CLEARED

#define RTE_INTERNAL_VAR_INIT

#define RTE_INTERNAL_VAR_POWER_ON_INIT



/* ETHIF driver */
#define ETHIF_CODE

#define ETHIF_CODE_FAST

#define ETHIF_CODE_SLOW

#define ETHIF_CONST

#define ETHIF_CALIB

#define ETHIF_CONFIG_DATA

#define ETHIF_APPL_DATA
#define ETHIF_APPL_CONST
#define ETHIF_VAR_NO_INIT

#define ETHIF_VAR_CLEARED

#define ETHIF_VAR_POWER_ON_CLEARED

#define ETHIF_VAR_INIT

#define ETHIF_VAR_POWER_ON_INIT

#define ETHIF_VAR_FAST_NO_INIT

#define ETHIF_VAR_FAST_CLEARED

#define ETHIF_VAR_FAST_POWER_ON_CLEARED

#define ETHIF_VAR_FAST_INIT

#define ETHIF_VAR_FAST_POWER_ON_INIT

#define ETHIF_VAR_SLOW_NO_INIT

#define ETHIF_VAR_SLOW_CLEARED

#define ETHIF_VAR_SLOW_POWER_ON_CLEARED

#define ETHIF_VAR_SLOW_INIT

#define ETHIF_VAR_SLOW_POWER_ON_INIT

#define ETHIF_INTERNAL_VAR_NO_INIT

#define ETHIF_INTERNAL_VAR_CLEARED

#define ETHIF_INTERNAL_VAR_POWER_ON_CLEARED

#define ETHIF_INTERNAL_VAR_INIT

#define ETHIF_INTERNAL_VAR_POWER_ON_INIT

/* CAN Transceiver TCAN1044 driver */
#define CANTRCV_184_TCAN1044_CODE
#define CANTRCV_184_TCAN1044_CONFIG_DATA
#define CANTRCV_184_TCAN1044_CONST
#define CANTRCV_184_TCAN1044_VAR_INIT
#define CANTRCV_184_TCAN1044_VAR_NOINIT
#define CANTRCV_184_TCAN1044_APPL_DATA
#define CANTRCV_184_TCAN1044_DATA

/* CAN Transceiver TCAN1146 driver */
#define CANTRCV_184_TCAN1146_CODE
#define CANTRCV_184_TCAN1146_CONFIG_DATA
#define CANTRCV_184_TCAN1146_CONST
#define CANTRCV_184_TCAN1146_VAR_INIT
#define CANTRCV_184_TCAN1146_VAR_NOINIT
#define CANTRCV_184_TCAN1146_APPL_DATA
#define CANTRCV_184_TCAN1146_DATA

/* CRYPTO driver */
#define CRYPTO_CODE
#define CRYPTO_CONFIG_DATA
#define CRYPTO_CONST
#define CRYPTO_VAR_INIT
#define CRYPTO_VAR_NOINIT
#define CRYPTO_APPL_DATA
#define CRYPTO_DATA
#define CRYPTO_VAR_FAST_CLEARED
#define CRYPTO_CODE
#define CRYPTO_CONST
#define CRYPTO_APPL_CONST

#endif /* COMPILER_CFG_H */

/**********************************************************************************************************
**                                  End of file Compiler_Cfg.h                                           **
**********************************************************************************************************/
