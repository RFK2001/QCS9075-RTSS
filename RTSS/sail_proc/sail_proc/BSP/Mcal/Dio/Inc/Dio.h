/*
===========================================================================
*/
/**
    @file  Dio.h
    @brief Header file for Dio driver

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    ===========================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/

#ifndef DIO_H
#define DIO_H
/*==============================================================================
**                      Include Section                                       **
==============================================================================*/
//#include "Std_Types.h"
#include "Dio_Cfg.h"
/*==============================================================================
**                      Global Macro                                          **
==============================================================================*/

#define DIO_VENDOR_ID                     
#define DIO_MODULE_ID                     
/* DIO major version info */
#define DIO_MAJOR_VERSION                1U
/* DIO minor version info */
#define DIO_MNOR_VERSION                 0U
/* DIO revision info */
#define DIO_REVISION                     0U
/* invalid parameter channel  */
#define DIO_E_PARAM_INVALID_CHANNEL_ID   ((uint8_t)0x0A)
/* invalid parameter port     */
#define DIO_E_PARAM_INVALID_PORT_ID      ((uint8_t)0x14)
/* parameter group    */
#define DIO_E_PARAM_INVALID_GROUP        ((uint8_t)0x1F)
/* Null pointer               */
#define DIO_E_PARAM_POINTER              ((uint8_t)0x20)

/* DIO Port Level Low */
#define STD_LOW                          (0U)
/* DIO Port Level High */
#define STD_HIGH                         (1U)
/*==============================================================================
**                      Type definitions                               		  **
==============================================================================*/

typedef uint32_t Std_VersionInfoType; /* To be removed when std_types.h is available */
typedef uint32_t Dio_PortLevelType;
typedef uint32_t Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef uint8_t Dio_LevelType;
typedef struct
{
  /* Position of Channel Group */
  Dio_PortLevelType	mask;
  /* port on which the Channel group is defined */
  Dio_PortType 		port;
  /* position of the Channel Group on the port, counted from the LSB */
  uint8_t        		offset;
} Dio_ChannelGroupType;

/*******************************************************************************
* Service Name:    : Dio_ReadChannel
* Syntax           : Dio_ReadChannel(
*                                 const Dio_ChannelType ChannelId
*                                )
* Service Id(Hex)  : 0x00
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ChannelId: Service to set a level of a channel
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Dio_LevelType: STD_HIGH The physical level of the corresponding
*                                Pin is STD_HIGH
*                                STD_LOW The physical level of the corresponding 
*                                Pin is STD_LOW
* Description      : Returns the value of the specified DIO channel
********************************************************************************/
extern Dio_LevelType Dio_ReadChannel
(
  const Dio_ChannelType ChannelId
);

/*******************************************************************************
* Service Name:    : Dio_WriteChannel
* Syntax           : void Dio_WriteChannel(
*                                       const Dio_ChannelType ChannelId,
*                                       const Dio_LevelType Level
*                                      )
* Service Id(Hex)  : 0x01
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ChannelId: ID of DIO channel
*                    Level    : STD_HIGH The physical level of the corresponding
*                            Pin is STD_HIGH
*                            STD_LOW The physical level of the corresponding 
*                            Pin is STD_LOW
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : None
* Description      : Service to set a level of a channel
*******************************************************************************/
void Dio_WriteChannel
(
  const Dio_ChannelType ChannelId,
  const Dio_LevelType Level
);

/*******************************************************************************
* Service Name:    : Dio_ReadPort
* Syntax           : Dio_ReadPort(
*                                 const Dio_PortType PortId
*                                )
* Service Id(Hex)  : 0x02
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : PortId: Id of the Dio Port
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Dio_PortLevelType: Level of all channels of that port
* Description      : Returns the level of all channels of that port.
*******************************************************************************/
extern Dio_PortLevelType Dio_ReadPort
(
  const Dio_PortType PortId
);

/*******************************************************************************
* Service Name:    : Dio_WritePort
* Syntax           : void Dio_WritePort(
*                                       const Dio_PortType PortId,
*                                       const Dio_PortLevelType Level
*                                      )
* Service Id(Hex)  : 0x03
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ChannelId: ID of DIO port
*                    Level    : Value to be written
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : None
* Description      : Service to set a value of the port
*******************************************************************************/
extern void Dio_WritePort
(
  const Dio_PortType PortId,
  const Dio_PortLevelType Level
);

/****************************************************************************************
* Service Name:    : Dio_ReadChannelGroup
* Syntax           : Dio_PortLevelType Dio_ReadChannelGroup(
*                        const Dio_ChannelGroupType* const ChannelGroupIdPtr
*                        )
* Service Id(Hex)  : 0x04
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ChannelGroupIdPtr: Pointer to ChannelGroup
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Dio_PortLevelType: Level of a subset of the adjoining bits of a port
* Description      : This Service reads a subset of the adjoining bits of a port.
******************************************************************************************/
extern Dio_PortLevelType Dio_ReadChannelGroup
(
  const Dio_ChannelGroupType * const ChannelGroupIdPtr
);

/************************************************************************************************
* Service Name:    : Dio_WriteChannelGroup
* Syntax           : void Dio_WriteChannelGroup(
*                        const Dio_ChannelGroupType* const ChannelGroupIdPtr,
*                        const Dio_PortLevelType Level
*                        )
* Service Id(Hex)  : 0x05
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ChannelGroupIdPtr: Pointer to ChannelGroup
*                    Level    : Value to be written
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : None
* Description      : Service to set a subset of the adjoining bits of a port to a specified level.
**************************************************************************************************/
extern void Dio_WriteChannelGroup
(
  const Dio_ChannelGroupType * const ChannelGroupIdPtr,
  const Dio_PortLevelType Level
);

/************************************************************************************************
* Service Name:    : Dio_FlipChannel
* Syntax           : Dio_LevelType Dio_FlipChannel(
*                        const Dio_ChannelType ChannelId
*                        )
* Service Id(Hex)  : 0x11
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ChannelId: ID of DIO channel
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Dio_LevelType: STD_HIGH The physical level of the corresponding
*                                Pin is STD_HIGH
*                                STD_LOW The physical level of the corresponding 
*                                Pin is STD_LOW
* Description      : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel 
*                 and return the level of the channel after flip.
**************************************************************************************************/
extern Dio_LevelType Dio_FlipChannel
(
  const Dio_ChannelType ChannelId
);

/************************************************************************************************
* Service Name:    : Dio_GetVersionInfo
* Syntax           : void Dio_GetVersionInfo(
*                        Std_VersionInfoType * const VersionInfo
*                        )
* Service Id(Hex)  : 0x12
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : None
* Parameters(INOUT): None
* Parameters(OUT)  : VersionInfo: Pointer to where to store the version information of this module
* Return Value     : Dio_LevelType: Pointer to where to store the version information of this module
*Description      : Service to get the version information of this module
**************************************************************************************************/
extern void Dio_GetVersionInfo
(
  Std_VersionInfoType * const VersionInfo
);
/*==============================================================================
**                      			END	                               		  **
==============================================================================*/
#endif   /*  DIO_H  */
