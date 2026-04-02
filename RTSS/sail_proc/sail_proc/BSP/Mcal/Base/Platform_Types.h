/**********************************************************************************************************
    Copyright (c) 2022 Qualcomm Technologies, Inc.
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
    File Name          : Platform_Types.h
    Component Name     : Platform or Base
    Description        : header file for All platform specific abstracted AUTOSAR data types and symbols.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/Mcal/Base/Platform_Types.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
=========================================================================================================*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/*@Requirements : [SWS_Platform_00002] All platform specific abstracted AUTOSAR data types and
symbols shall be defined in the Platform_Types.h header file. It is not allowed to
add any extension to this file. Any extension invalidates the AUTOSAR conformity.
*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/


/*=========================================================================================================
**                                         defines and macros                                            **
=========================================================================================================*/
/*------------------< Component Identification >------------------*/

#define PLATFORM_AUTOSAR_VENDOR_ID                    0U
#define PLATFORM_AUTOSAR_MODULE_ID                    199U
#define PLATFORM_AUTOSAR_RELEASE_MAJOR_VERSION        21U
#define PLATFORM_AUTOSAR_RELEASE_MINOR_VERSION        11U
#define PLATFORM_AUTOSAR_RELEASE_REVISION_VERSION     0U
#define PLATFORM_SW_MAJOR_VERSION                     1U
#define PLATFORM_SW_MINOR_VERSION                     0U
#define PLATFORM_SW_PATCH_VERSION                     0U

/*------------------< CPU_TYPE >------------------*/

/*
* @brief        :  Indicating a 8 bit processor
* @implements
* @Requirements : [SWS_Platform_00064]
*                 [SWS_Platform_00045]
*/
#define CPU_TYPE_8       8U

/*
* @brief        :  Indicating a 16 bit processor
* @implements
* @Requirements : [SWS_Platform_00064]
*                 [SWS_Platform_00045]
*/
#define CPU_TYPE_16     16U

/*
* @brief        :  Indicating a 32 bit processor
* @implements
* @Requirements : [SWS_Platform_00064]
*                 [SWS_Platform_00045]
*/
#define CPU_TYPE_32     32U

/*
* @brief        :  Indicating a 64 bit processor
* @implements
* @Requirements : [SWS_Platform_00064]
*                 [SWS_Platform_00045]
*/
#define CPU_TYPE_64     64U

/*
* @brief        :  For each platform the register width of the CPU used shall be 
*                  indicated by defining CPU_TYPE
* @implements
* @Requirements : [SWS_Platform_00044]
*                 [SWS_Platform_00064]
*/
#define CPU_TYPE     (CPU_TYPE_32)

/*------------------< CPU_BIT_ORDER >------------------*/

/*
* @brief        :  The most significant bit is the first bit of the bit sequence.
* @implements
* @Requirements : [SWS_Platform_00038]
*                 [SWS_Platform_00048]
*/
#define MSB_FIRST        0

/*
* @brief        :  The least significant bit is the first bit of the bit sequence
* @implements
* @Requirements : [SWS_Platform_00038]
*                 [SWS_Platform_00049]
*/
#define LSB_FIRST        1

/*
* @brief        :  For each platform the appropriate bit order on register level
* shall be indicated in the platform types header file using the symbol CPU_BIT_ORDER
* @implements
* @Requirements : [SWS_Platform_00043]
*/
#define CPU_BIT_ORDER    (LSB_FIRST)

/*------------------< CPU_BYTE_ORDER >------------------*/

/*
* @brief        :  Within uint16, the high byte is located before the low byte.
* @implements
* @Requirements : [SWS_Platform_00039]
*                 [SWS_Platform_00050]
*/
#define HIGH_BYTE_FIRST  0

/*
* @brief        :  Within uint16, the high byte is located before the high byte.
* @implements
* @Requirements : [SWS_Platform_00039]
*                 [SWS_Platform_00051]
*/
#define LOW_BYTE_FIRST   1

/*
* @brief        :  For each platform the appropriate byte order on memory
* level shall be indicated in the platform types header file using the symbol CPU_BYTE_ORDER
* @implements
* @Requirements : [SWS_Platform_00046]
*/
#define CPU_BYTE_ORDER    (LOW_BYTE_FIRST)

/*------------------< TRUE, FALSE >------------------*/

/*
* @brief        : The symbols TRUE and FALSE shall be defined as follows 
* @implements   : FALSE 0x00 TRUE 0x01
* @Requirements : [SWS_Platform_00056]
*                 [SWS_Platform_00054] In case of in-built compiler support of the symbols, 
*                 redefinitions shall be avoided using a conditional check.
*                 [SWS_Platform_00055] These symbols shall only be used in conjunction with the
*                 boolean type defined in Platform_Types.h.
*/
#ifndef TRUE

    #define TRUE 1
	
#endif

#ifndef FALSE

    #define FALSE 0
	
#endif

/*
* @brief        :  This standard AUTOSAR type shall only be used together with the definitions TRUE and FALSE.
* @implements   :  FALSE 0 , TRUE 1
* @Requirements : [SWS_Platform_00026]
*/
typedef unsigned char boolean;

/*
* @brief        :  This standard AUTOSAR type shall be of 8 bit unsigned.
* @implements   :  0..255, 0x00..0xFF 
* @Requirements : [SWS_Platform_00013]
*/
typedef unsigned char uint8;

/*
* @brief        :  This standard AUTOSAR type shall be of 16 bit unsigned
* @implements   :  0..65535, 0x0000..0xFFFF
* @Requirements : [SWS_Platform_00014]
*/
typedef unsigned short uint16;

/*
* @brief        :  This standard AUTOSAR type shall be of 32 bit unsigned
* @implements   :  0..4294967295,  0x00000000..0xFFFFFFFF
* @Requirements : [SWS_Platform_00015]
*/
typedef unsigned long uint32;

/*
* @brief        :  This standard AUTOSAR type shall be of 64 bit unsigned
* @implements   :  0..18446744073709551615, 0x0000000000000000..0xFFFFFFFFFFFFFFFF
* @Requirements : [SWS_Platform_00066]
*/
typedef unsigned long long uint64;

/*
* @brief        :  This standard AUTOSAR type shall be of 8 bit signed
* @implements   :  -128.. +127 0x80..0x7F
* @Requirements : [SWS_Platform_00016]
*/
typedef signed char sint8;

/*
* @brief        :  This standard AUTOSAR type shall be of 16 bit signed
* @implements   :  -32768.. +32767 0x8000..0x7FFF 
* @Requirements : [SWS_Platform_00017]
*/
typedef signed short sint16;

/*
* @brief        :  This standard AUTOSAR type shall be of 32 bit signed
* @implements   :  -2147483648.. +2147483647 0x80000000..0x7FFFFFFF 
* @Requirements : [SWS_Platform_00018]
*/
typedef signed long sint32;

/*
* @brief        :  This standard AUTOSAR type shall be of 64 bit signed
* @implements   :  -9223372036854775808..+9223372036854775807, 0x8000000000000000..0x7FFFFFFFFFFFFFFF
* @Requirements : [SWS_Platform_00067]
*/
typedef signed long long sint64;

/*
* @brief        :  This optimized AUTOSAR type shall be at least 8 bit unsigned
* @implements   :  0..255, 0x00..0xFF 
* @Requirements : [SWS_Platform_00020]
*/
typedef unsigned char uint8_least;

/*
* @brief        :  This optimized AUTOSAR type shall be at least 16 bit unsigned
* @implements   :  0..65535, 0x0000..0xFFFF 
* @Requirements : [SWS_Platform_00021]
*/
typedef unsigned short uint16_least;

/*
* @brief        :  This optimized AUTOSAR type shall be at least 8 bit unsigned
* @implements   :  0..4294967295,  0x00000000..0xFFFFFFFF 
* @Requirements : [SWS_Platform_00022]
*/
typedef unsigned long uint32_least;

/*
* @brief        :  This optimized AUTOSAR type shall be at least 8 bit signed.
* @implements   :  -128.. +127  0x80..0x7F 
* @Requirements : [SWS_Platform_00020]
*/
typedef signed char sint8_least;

/*
* @brief        :  This optimized AUTOSAR type shall be at least 16 bit signed
* @implements   :  -32768..+32767, 0x8000..0x7FFF
* @Requirements : [SWS_Platform_00024]
*/
typedef signed char sint16_least;

/*
* @brief        :  This optimized AUTOSAR type shall be at least 32 bit signed
* @implements   :  -2147483648..+2147483647, 0x80000000..0x7FFFFFFF
* @Requirements : [SWS_Platform_00025]
*/
typedef signed char sint32_least;

/*
* @brief        :  This standard AUTOSAR type shall follow the 32-bit binary interchange format according to IEEE 754-2008 
* @implements   :  -3.4028235e+38 ..+3.4028235e+38
* @Requirements : [SWS_Platform_00041]
*/
typedef float float32;

/*
* @brief        :  This standard AUTOSAR type shall follow the 32-bit binary interchange format according to IEEE 754-2008 
* @implements   :  -1.7976931348623157e+308..+1.7976931348623157e+308
* @Requirements : [SWS_Platform_00042]
*/
typedef double float64;

/*
* @brief        :  This standard AUTOSAR type shall be a void pointer.
*                  This type shall be used for buffers that contain data returned to the caller.
* @implements   :  
* @Requirements : [SWS_Platform_91001]
*/
typedef void* VoidPtr;

/*
* @brief        :  This standard AUTOSAR type shall be a void pointer to const.
*                  This type shall be used for buffers that are passed to the callee
* @implements   :  
* @Requirements : [SWS_Platform_91002]
*/
typedef const void* ConstVoidPtr;

#endif /* PLATFORM_TYPES_H */

/**********************************************************************************************************
**                                  End of file Platform_Types.h                                              **
**********************************************************************************************************/
