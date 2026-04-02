/*
===========================================================================
*/
/**
    @file  Dio.c
    @brief This file contains Autosar Dio Implementation 

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
/*==============================================================================
**                      Include Section                                       **
==============================================================================*/
#include "gpio.h"
#include "Dio.h"

/*==============================================================================
**                      		PRIVATE OBJ		                      		  **
==============================================================================*/

/*==============================================================================
**                      			PRIVATE APIs                       		  **
==============================================================================*/

/*==============================================================================
**                      		PUBLIC APIs                                   **
==============================================================================*/

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
Dio_LevelType Dio_ReadChannel(const Dio_ChannelType ChannelId)
{
  Dio_LevelType RetVal = (Dio_LevelType)STD_LOW;
  GPIOValueType gpioState = GPIO_LOW;
  if( ( ChannelId >= DIO_CHANNEL_MAX ) || ( ChannelId < 0U ) )
  {
	;
  }
  else
  {
    /*Call the gpio read pin api of sail bsp gpio driver */
    gpioState = sail_gpio_ReadPin(ChannelId);
    RetVal = (( gpioState != GPIO_LOW )?(Dio_LevelType)STD_HIGH:(Dio_LevelType)STD_LOW);  
  }
  return RetVal;
}

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
void Dio_WriteChannel(const Dio_ChannelType ChannelId, const Dio_LevelType Level)
{
  int Status = 0;
  GPIOValueType gpioState = GPIO_LOW;
  if( ( ChannelId >= DIO_CHANNEL_MAX ) || ( ChannelId < 0U ) )
  {
	  ;
  }
  else
  {
	  gpioState = ((Level != STD_LOW)? (GPIOValueType)GPIO_HIGH: (GPIOValueType)GPIO_LOW);
    /* Call the gpio write pin api of sail BSP driver */
	  sail_gpio_WritePin(ChannelId, gpioState);
  }
  return;
}

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
Dio_PortLevelType Dio_ReadPort( const Dio_PortType PortId )
{
  Dio_PortLevelType  RetVal = STD_LOW;

  /* TODO once DIO groups are available. */
  return (RetVal);
}

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
void Dio_WritePort(const Dio_PortType PortId, const  Dio_PortLevelType Level)
{
  /* TODO once DIO groups are available. */
  return;
}

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
Dio_PortLevelType Dio_ReadChannelGroup
(	
	const Dio_ChannelGroupType* const ChannelGroupIdPtr
)
{
  Dio_PortLevelType  RetVal = STD_LOW;
  /* TODO once DIO channel and port groups are available. */
  return (RetVal);
} 

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
void Dio_WriteChannelGroup
( 
	const Dio_ChannelGroupType * const ChannelGroupIdPtr,
	const Dio_PortLevelType Level
)
{
  /* TODO once DIO channel and port groups are available. */
  return ;
} 

#if ( DIO_FLIP_CHANNEL_API == STD_ON )
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
Dio_LevelType Dio_FlipChannel(const Dio_ChannelType ChannelId)
{
  Dio_LevelType DioLevel = (Dio_LevelType)STD_LOW;
  Dio_LevelType RetVal = (Dio_LevelType)STD_LOW;
  
  DioLevel = Dio_ReadChannel(ChannelId);
  RetVal = ((DioLevel != STD_LOW) ? STD_LOW: STD_HIGH);

  Dio_WriteChannel(ChannelId, RetVal);
  return RetVal;
}
#endif /* ( DIO_FLIP_CHANNEL_API == STD_ON ) */

#if ( DIO_VERSION_INFO_API == STD_ON )
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
void Dio_GetVersionInfo(Std_VersionInfoType * const VersionInfo)
{
  Std_VersionInfoType Version = 0;

  Version = ((DIO_MAJOR_VERSION << 16) | (DIO_MNOR_VERSION << 8) || DIO_REVISION);
  *VersionInfo = Version;
  return ;
}
#endif /* #if ( DIO_VERSION_INFO_API == STD_ON ) */
/*==============================================================================
**                      			END	                               		  **
==============================================================================*/