/**************************************************************************************************
    Copyright (c) Qualcomm Technologies, Inc.
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
    File Name          : common_functions.h
    Component Name     : Common Functions
    Description        : Header file for common functions
    $Header: 
    $DateTime: 
    $Author: 
==================================================================================================*/
/* Include header file guard */
#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include <types.h>
#include <stdbool.h>
#include "sail_mem_map.h"

/*==================================================================================================
**                                      Macros                                                    **
==================================================================================================*/
/* Number of Execution Environments */
/* 0 - index EL1, 1 = index EL2 */
#define NUM_OF_EL_MODES_SUPPORTED               0x2U
#define NUM_OF_CORES                            0x4U

/* LogCode SM Reservation*/
#define MAX_NO_OF_SERIAL_ENGINE					0x6U
#define MAX_NO_OF_I2C_CHANNELS					0x10U
#define MAX_NO_OF_I2C_EL1_CHANNELS		        0x10U
#define MAX_NO_OF_SPI_CHANNELS					0xAU
/* According to DTS update the hardware IDs*/
#define i2cPMIC_PSAIL_HW						0x0U
#define i2c_SE3_HW						        0x1U
/* According to DTS update the hardware IDs*/
#define i2cSE0_HW_CHANNEL                       0x0U
#define i2cSE3_HW_CHANNEL                       0x1U
#ifdef CONFIG1
#define uartDEBUG_HW							0x0U
#define uartVIP_HW								0x1U
#else
#define uartDEBUG_HW							0x1U
#define uartVIP_HW								0x0U
#endif /* CONFIG1 */

#define QSPI_CONTROL_SAIL                 0x0U
#define QSPI_CONTROL_MD                   0x1U

#define MD_OK                                   0x0U
#define MD_BOOT_EDL                             0x1U
#define MD_NOT_OK                               0x2U

/*Psail Fault cookie for SSM*/
#define PSAIL_ERROR_COOKIE                ( 0xFFu )

/* Define  TEST_SRC_ENABLED when, required to run test framework */
//#define TEST_SRC_ENABLED


/* ======================================================= SST TEST FLAGS START ======================================================= */

/* SST PRNG TEST SOURCE FLAG */
// #define SST_PRNG_SRC

/* SST GPCE TEST SOURCE FLAG */                
// #define SST_GPCE_SRC

/* SST PKE TEST SOURCE FLAG */      
// #define SST_PKE_SRC

/* SST SECBOOT TEST SOURCE FLAG */ 
// #define SST_SECBOOT_SRC

/* SST SECURE STORAGE TEST SOURCE FLAG */ 
// #define SST_SS_SRC             

/* SST SHE TEST SOURCE FLAG */ 
// #define SST_SHE_SRC  

/* SST GPCE TEST SOURCE SUB FLAGS */ 
#ifdef  SST_GPCE_SRC 
	#define SST_GPCE_AES_ECB_SRC                 
	#define SST_GPCE_AES_CBC_SRC                 
	#define SST_GPCE_AES_CTR_SRC                
	#define SST_GPCE_AES_XTS_SRC                
	#define SST_GPCE_AES_GCM_SRC                
	#define SST_GPCE_AES_GMAC_SRC                
	#define SST_GPCE_AES_CCM_SRC 
	#define SST_GPCE_AES_CMAC_SRC 
	#define SST_GPCE_HASH_SRC 
	#define SST_GPCE_SM3_SRC 
	#define SST_GPCE_SM4_SRC 
	#define SST_GPCE_HMAC_SRC
#endif /* SST GPCE TEST SOURCE SUB FLAGS */

/* SST PKE TEST SOURCE SUB FLAGS */    
#ifdef  SST_PKE_SRC 
    #define SST_PKE_ECDSA_KEYGEN_SRC
    #define SST_PKE_ECDSA_SIGN_VERIFY_SRC
	#define SST_PKE_ECDSA_ECDH_SRC
	#define SST_PKE_RSA_KEYGEN_SRC
	#define SST_PKE_RSA_SIGN_VERIFY_SRC
	#define SST_PKE_RSA_ENCRYPT_DECRYPT_SRC
	#define SST_PKE_EDDSA_KEYGEN_SRC
	#define SST_PKE_EDDSA_SIGN_VERIFY_SRC
	#define SST_PKE_EDDSA_ECDH_SRC
#endif /* SST PKE TEST SOURCE SUB FLAGS */

/* SST SECBOOT TEST SOURCE SUB FLAGS */ 
#ifdef  SST_SECBOOT_SRC 
	#define SST_SECBOOT_MRC_SRC
	#define SST_SECBOOT_ARB_SRC
	#define SST_SECBOOT_LCI_SRC
#endif /* SST SECBOOT TEST SOURCE SUB FLAGS */
/* ======================================================= SST TEST FLAGS END ======================================================= */

/* ========= SECURE STORAGE TEST FLAG ========= */
//#define SECURE_STORAGE_TEST
/* ======= SECURE STORAGE TEST FLAG END ======= */

#define DEVICE_IS_IN_WARM_BOOT        0xEu

/* Function to set a bit at position n*/
#define BIT(n)    ((uint32) 1U << (uint32) (n))

#define REG_IN_RAW(base, offset) \
    (*(volatile uint32 *)((uint32) base + (uint32) offset))
#define REG_OUT_RAW(base, offset, data) \
    (*(volatile uint32 *)((uint32) base + (uint32) offset)) = (uint32) data;



#define SM_APP_DATA __attribute__ ( ( section ( "sm_app_data" ) ) )


extern unsigned int Image$$lnkBSP_PRIV_DATAStartAddr$$ZI$$Base;
extern unsigned int Image$$lnkBSP_PRIV_DATAEndAddr$$ZI$$Base;

#define SAILBSP_PRIV_DATA_ADDR_BASE    (void *)&Image$$lnkBSP_PRIV_DATAStartAddr$$ZI$$Base
#define SAILBSP_PRIV_DATA_ADDR_SIZE    (portUInt32Type)( (uint32_t)&Image$$lnkBSP_PRIV_DATAEndAddr$$ZI$$Base -\
                                                             (uint32_t)&Image$$lnkBSP_PRIV_DATAStartAddr$$ZI$$Base )



#define BSP_PRIV_DATA __attribute__ ( ( section ( "bsp_priv_data" ) ) )
#define BSP_UNPRIV_DATA __attribute__ ( ( section ( "bsp_global_data" ) ) )

/*=========================================================================
**  Function : bIsCurrentModeHyp
** =========================================================================*/
/**
  This function will check if current task mode is CPSR_MODE_HYP and returns TRUE

  @param
  [in]None

  @return
   TRUE or FALSE

  @dependencies
  None.
*/
boolean bIsCurrentModeHyp(void);

/*===========================================================================
**  Function :  read_mpidr
** ==========================================================================
*/
/*!
*
* @brief
*   helper function to read mpidr register
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   cuurent value of mpidr register
* @par Side Effects
*   None
*
*/
uint32 read_mpidr(void);

/*===========================================================================
**  Function :  xSyscallIsIrqMode
** ==========================================================================
*/
/*!
*
* @brief
*   This function will check the irq mode.
*
* @param
*  None
* @par Dependencies
*   None
* @retval
*   boolean- TRUE/FALSE
* @par Side Effects
*   None
*
*/
boolean xSyscallIsIrqMode( void );

/*===========================================================================
**  Function :  get_curr_cpu_num
** ==========================================================================
*/
/*!
*
* @brief
*   Function to get the current cpu number
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   current cpu number
* @par Side Effects
*   None
*
*/
uint get_curr_cpu_num(void);

/*===========================================================================
**  Function :  get_curr_cluster_num
** ==========================================================================
*/
/*!
*
* @brief
*   Function to get the current cluster number
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   current cluster number
* @par Side Effects
*   None
*
*/
uint get_curr_cluster_num(void);

/*===========================================================================
**  Function :  get_curr_cluster_num
** ==========================================================================
*/
/*!
*
* @brief
*   Function to get the current cpu physical number.
*   For example if we have 2 clusters each with 2 cpus:
*   Cluster 0 core 0 = 0
*   Cluster 0 core 1 = 1 
*   Cluster 1 core 0 = 2 
*   Cluster 1 core 1 = 3 
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   current cpu physical number
* @par Side Effects
*   None
*
*/
uint get_curr_phys_cpu_num(void);

/*===========================================================================
**  Function :  sailbsp_memscpy
** ==========================================================================
*/
/*!
*
* @brief
*   secure API memscpy - Size bounded memory copy.
*
* @param
*   [in/out] dst : pointer to destination array
*   [in] dst_size : size to copy to the destination
*   [in/out] src : pointer to source array
*   [in] src_size : size to copy from the source
*
* @par Dependencies
*   None
* @retval
*   size of items copied from source to destination
* @par Side Effects
*   None
*
*/
size_t sailbsp_memscpy(void *dst, size_t dst_size, const void *src, size_t src_size);

/*===========================================================================
**  Function :  sailbsp_checkmdedl
** ==========================================================================
*/
/*!
*
* @brief
*   Checks MD2SAIL shadow registers if MD is in EDL.
*
* @param
*   none
* @par Dependencies
*   None
* @retval
*   TRUE: MD went into EDL mode
*   FALSE: MD not in EDL mode
* @par Side Effects
*   None
*
*/
bool sailbsp_checkmdedl(void);

extern void vTestCoreHealthStatus( void);
extern uint8 ucGetCoreHealthStatus( void);

bool isNumeric(const char *str);

/*===========================================================================
**  Function :  silbsp_atoi
** ==========================================================================
*/
/*!
*
* @brief
*   convert ascii to integer.
*
* @param
*   [IN] str : null terminated integer string
* @par Dependencies
*   None
* @retval
*   converted integer
* @par Side Effects
*   None
*
*/
int32_t silbsp_atoi(const char* str);


/*===========================================================================
**  Function :  sailbsp_stricmp
** ==========================================================================
*/
/*!
*
* @brief
*   Case insensitive comparation of two strings
*
* @param
*   [IN] str1 : null terminated string1
* @param
*   [IN] str2 : null terminated string2
* @par Dependencies
*   None
* @retval
*   1 - compare success, 0 -compare fail
* @par Side Effects
*   None
*
*/
uint8 sailbsp_stricmp(char const *str1, char const *str2);

/*===========================================================================
**  Function :  sailbsp_strlcpy
** ==========================================================================
*/
/*!
*
* @brief
*   sailbsp_strlcpy - string copy.
*
* @param
*   [in/out] dstBuffer : pointer to destination buffer.
*   [in] srcStr : pointer to string which needed to be copied.
*   [in] dstBuffSize : Total size to destination buffer which can hold the string, including null terminator.
*
* @par Dependencies
*   Input strings needs to have proper null-termination.
* @retval
*   returns length of Source string.
* @par Side Effects
*   None
*
*/
size_t sailbsp_strlcpy(char *dstBuffer, char const *srcStr, size_t dstBuffSize );

#ifdef SAILEL2
extern void vQupPlatformDriverInit(void);
#endif

#if 0
/*******************************************************************************
** Syntax           : boolean bSailTsensGetPerSensorTempWrappper              **
**                    (    	uint32 ulSensorID , int8_t *suSensorTemp         **
**                    )                                                       **
**                                                                            **
** Description      :  Get Sail sensor Temperature in DegC                    **
**					               		      								  **
**                           					  							  **
**                                      									  **
** Parameters(in)   : ulSensorID - Sensor ID <0-3>                   \0       **
**                                                                            **
** Parameters (out) : *suSensorTemp - ptr to variable which holds temp        **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  TRUE  - Temp Read Success                              **
** Return value     :  FALSE - Temp Read Failure                              **
**                                                                            **
*******************************************************************************/
boolean bSailTsensGetPerSensorTempWrappper( uint32 ulSensorID , int8_t *suSensorTemp);

/*******************************************************************************
** Syntax           : boolean bSailTsensGetMaskSensorTempWrappper             **
**                    (    	uint32_t ulSensorMask , int8_t *suSensorTemp        **
**                    )                                                       **
**                                                                            **
** Description      :  Get Sail sensor Temperature in DegC for the sensor     **
**                     mask provided                                          **
**					               		      								  **
**                           					  							  **
**                                      									  **
** Parameters(in)   : ulSensorMask - Mask of sensors whose temperatures are   **
**                    to be fetched                                           **
**                                                                            **
** Parameters (out) : *suSensorTemp - ptr to variable which holds temp        **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  TRUE  - Temp Read Success                              **
** Return value     :  FALSE - Temp Read Failure                              **
**                                                                            **
*******************************************************************************/
boolean bSailTsensGetMaskSensorTempWrappper( uint32_t ulSensorMask , int8_t *suSensorTemp);

/*******************************************************************************
** Syntax           : boolean bSailTsensGetNumOfSensorWrappper                **
**                    (    	uint8_t *pulTsensNumSensor                       **
**                    )                                                       **
**                                                                            **
** Description      :  Get Number of Sensors in SAIL TSENS Controller         **
**					               		      								  **
**                           					  							  **
**                                      									  **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : pulTsensNumSensor - Pointer to variable to keep         **
**                                        Number of Sensors                   **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  TRUE  - Success                                        **
** Return value     :  FALSE - Failure                                        **
**                                                                            **
*******************************************************************************/
boolean bSailTsensGetNumOfSensorWrappper( uint8_t *pulTsensNumSensor);
#endif
#endif /* COMMON_FUNCTIONS_H  */
