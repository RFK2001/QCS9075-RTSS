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
    File Name          : Std_Types.h
    Component Name     : STD or Base
    Description        : AUTOSAR standard types header file. It contains all types that are used across 
	                     several modules of the basic software and that are platform and
                         compiler independent.
    $Header:    $
    $DateTime:  $
    $Author:    $
=========================================================================================================*/

/*@Requirements : [SWS_Std_00014] The standard types header file shall be protected against multiple inclusion [SRS_BSW_00059]*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/*@Requirements : [SWS_Std_00004] It is not allowed to add any project or supplier specific extension
to this file. Any extension invalidates the AUTOSAR conformity.[SRS_BSW_00161]*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include "types.h"
//#include "Compiler.h"

#ifndef CAN_DATA
#define CAN_DATA __attribute__ ((section("can_data")))
#endif
#ifndef CAN_CONST_DATA
#define CAN_CONST_DATA __attribute__ ((section("can_const_data")))
#endif
#ifndef CAN_CONST_PTR
#define CAN_CONST_PTR __attribute__ ((section("can_const_ptr")))
#endif

/*=========================================================================================================
**                                         defines and macros                                            **
=========================================================================================================*/

/*------------------< Component Identification >------------------*/
#define AUTOSAR_STD_VENDOR_ID                 0U
#define AUTOSAR_STD_MODULE_ID                 197U
#define AUTOSAR_STD_RELEASE_MAJOR_VERSION     22U
#define AUTOSAR_STD_RELEASE_MINOR_VERSION     11U
#define AUTOSAR_STD_RELEASE_REVISION_VERSION  0U
#define STD_SW_MAJOR_VERSION                  1U
#define STD_SW_MINOR_VERSION                  0U
#define STD_SW_PATCH_VERSION                  0U

#define STD_AR_RELEASE_MAJOR_VERSION		4U
#define STD_AR_RELEASE_MINOR_VERSION		8U
/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/
#ifndef SPI_H
/*
* @brief : This type can be used as standard API return type which is shared between the RTE and the BSW
*          modules. 
* @implements :
*              E_OK      0 
*              E_NOT_OK  1
*              0x02-0x3F 2 Available to user specific errors
* @Requirements : [SWS_Std_00005]
*/
typedef uint8 Std_ReturnType;
#endif

/*
* @brief : This type is used to encode different types of results for response messages. - Currently this
*          encoding is limited to the distinction between OK and ERROR responses.
* @implements :
*              STD_MESSAGERESULT_OK       0 
*              STD_MESSAGERESULT_ERROR    1  Messageresult for an ERROR response
*              0x02-0x3F                  2  Reserverd for future message results
* @Requirements : [SWS_Std_91002]
*/
typedef uint8 Std_MessageResultType;


/*
* @brief : This type is used to encode the different type of messages. - Currently this encoding is limited to
*          the distinction between requests and responses in C/S communication.
* @implements :
*              STD_MESSAGETYPE_REQUEST   0  Message type for a request message
*              STD_MESSAGETYPE_RESPONSE  1  Message type for a response message
*              0x02-0x3F                 2  Reserverd for future message type
* @Requirements : [SWS_Std_91001]
*/
typedef uint8 Std_MessageTypeType;


/*
* @brief : The type of the Std_TransformerError.
* @implements : The values are specified for each transformer class in ASWS_TransformerGeneral
* @Requirements : [SWS_Std_00022]
*/
typedef uint8 Std_TransformerErrorCode;

/*
* @brief : The Std_TransformerClass represents the transformer class in which the error occurred.
* @implements :
*         STD_TRANSFORMER_UNSPECIFIED   0x00  Transformer of a unspecified transformer class.
*         STD_TRANSFORMER_SERIALIZER    0x01  Transformer of a serializer class
*         STD_TRANSFORMER_SAFETY        0x02  Transformer of a safety class.
*         STD_TRANSFORMER_SECURITY      0x03  Transformer of a security class.
*         STD_TRANSFORMER_CUSTOM        0xFF  Transformer of a custom class not standardized by AUTOSAR
* @Requirements : [SWS_Std_00023]
*                 [SWS_Std_00024]
*                 [SWS_Std_00025]
*                 [SWS_Std_00026]
*/
typedef uint8 Std_TransformerClass;


/*
* @brief : The Std_TransformerClass represents the transformer class in which the error occurred.
* @implements :
*         E_OK                    0x00  No specific error to be injected.
*         E_SAFETY_INVALID_REP    0x01  Repeat the last used sequence number.
*         E_SAFETY_INVALID_SEQ    0x02  Use a wrong sequence number.
*         E_SAFETY_INVALID_CRC    0x03  Generate a deliberately wrong CRC.        
* @Requirements : [SWS_Std_00029]
*/
typedef uint8 Std_TransformerForwardCode;
#if 0
/*------------------< Std_ExtractProtocolHeaderFieldsType >------------------*/

/*
* @brief          : Type for the function pointer to extract the relevant protocol header fields of the message and
*                   the type of the message result of a transformer. - At the time being, this is limited to the types
*                   used for C/S communication (i.e., REQUEST and RESPONSE and OK and ERROR).
* @implements     :
* parameter(in)   :  buffer -->Buffer allocated by the RTE, where the transformed data has to be stored by the transformer
*                    bufferLength --> Length of the buffer
* messageType(out): messageType --> Canonical representation of the message type (extracted from the transformers protocol header).
*                    messageResult --> Canonical representation of the message result type (extracted
*                                      from the transformers protocol header).
* @Requirements   : [SWS_Std_91003]
*
*/

Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType) (
const uint8* buffer,
uint32 bufferLength,
Std_MessageTypeType* messageType,
Std_MessageResultType* messageResult
);
#endif
/* All AUTOSAR standard types and constants shall be placed and organized in a standard type
header file [SRS_BSW_00348] */
/*
* @brief        : Physical state 5V or 3.3V
* @implements
* @Requirements : [SWS_Std_00007]
*/
#define STD_HIGH        0x01U

/*
* @brief        : Physical state 0V 
* @implements
* @Requirements : [SWS_Std_00007]
*/
#define STD_LOW         0x00U

/*
* @brief        : Logical state active
* @implements
* @Requirements : [SWS_Std_00013]
*/
#define STD_ACTIVE       0x01U

/*
* @brief        :  Logical state idle
* @implements
* @Requirements : [SWS_Std_00013]
*/
#define STD_IDLE          0x00U

#ifndef STD_ON
/*
* @brief        :  
* @implements
* @Requirements : [SWS_Std_00010]
*/
#define STD_ON             0x01U
#endif

/*
* @brief 
* @implements
* @Requirements : [SWS_Std_00010]
*/
#define STD_OFF            0x00U

/*
* @brief        :  E_OK is already defined within OSEK, the symbol E_OK has to be shared. To avoid name clashes and 
*                  redefinition problems, the symbols have to be defined in the following way
*                  (approved within implementation):
* @implements
* @Requirements : [SWS_Std_00006]
*/
#ifndef STATUSTYPEDEFINED

    #define STATUSTYPEDEFINED
	
    #define E_OK 0x00u
	
    typedef unsigned char StatusType; /* OSEK compliance */
	
#endif

#define E_NOT_OK 0x01u

/*
* @brief        : The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero definition.
* @implements   : void pointer
* @Requirements : [SWS_Std_000031]
*/
#define NULL_PTR            ((void *)0)

/*
* @brief        : This type shall be used to request the version of a BSW module using the <Module name>_Get
*                 VersionInfo() function
* @implements   : 
* @Requirements : [SWS_Std_00015]
*/
typedef struct
{
   uint16 vendorID;              /*<-- vendor ID ->*/
   uint16 moduleID;              /*<-- BSW/CDD module ID ->*/
   uint8  sw_major_version;      /*<-- BSW/CDD Software major version ->*/
   uint8  sw_minor_version;      /*<-- BSW/CDD Software minor version ->*/
   uint8  sw_patch_version;      /*<-- BSW/CDD Software patch version ->*/
} Std_VersionInfoType;

/*
* @brief    : Std_TransformerError represents a transformer error in the context of a certain transformer chain.
* @implements
* @Requirements : [SWS_Std_00021]
*/
typedef struct
{
   Std_TransformerErrorCode errorCode;  
   Std_TransformerClass     transformerClass;       
} Std_TransformerError;

#endif /* STD_TYPES_H */

/**********************************************************************************************************
**                                  End of file Std_Types.h                                              **
**********************************************************************************************************/
