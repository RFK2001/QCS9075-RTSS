#ifndef __OSPI_FD_H__
#define __OSPI_FD_H__
/*
===========================================================================
*/
/**
    @file  fd_mgr.h
    @brief File descriptor functions.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/sailhyp/fd_mgr.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "spinor_cm_defs.h"

#define FD_IDX(fd)      (fd & 0xFF)

/**********************************************************
 * Resets the file descriptor
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
void fdReset(void);

/**********************************************************
 * Resets the fds upon SW reset
 *
 * @param resetCoreID [IN]
 *   Core ID that got reset.
 *
 * @return void [OUT]
 *
 **********************************************************/
void fdResetonSWreset(uint32 resetCoreID);

/**********************************************************
 * Gets the OSPI User type
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @return eSpinorUserType [OUT]
 *   Returns the type of user information.
 *
 **********************************************************/
eSpinorUserType fdGetUserType ( uint32_t fd );

/**********************************************************
 * Sets the low power flag value
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @param bLowPower [IN]
 *   low power flag.
 *
 * @return void [OUT]
 *
 **********************************************************/
void fdSetLowPowerFlag(uint32_t fd, boolean bLowPower);

/**********************************************************
 * Gets the low power flag value
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean fdGetLowPowerFlag(uint32_t fd);

/**********************************************************
 * Returns the number of users of a type
 *
 * @param eUserType [IN]
 *   OSPI User type.
 *
 * @return int [OUT]
 *   The number of users of the type.
 *
 **********************************************************/
uint16_t fdGetUserCnt(eSpinorUserType eUserType);

/**********************************************************
 * Allocates a file descriptor
 *
 * @param eUserType [IN]
 *   OSPI User type.
 *
 * @return int [OUT]
 *   Returns the file descriptor if successful.
 *
 **********************************************************/
uint32_t fdAlloc(eSpinorUserType eUserType);

/**********************************************************
 * Frees the file descriptor
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @return void [OUT]
 *
 **********************************************************/
void fdFree(uint32_t fd);

/**********************************************************
 * Checks the low power flag value
 *
 * @param pulUsedCnt [IN/OUT]
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean fdCheckLowPowerFlag(uint32_t *pulUsedCnt);

/**********************************************************
 * Checks if the file descriptor is valid
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean fdIsValid(uint32 fd);

/**********************************************************
 * Gets the current Password for the File Descriptor
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @return int [OUT]
 *   Current Password.
 *
 **********************************************************/
uint32 fdGetCurrentPwd(uint32_t fd);

/**********************************************************
 * Checks if the password for the file descriptor is valid
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @param pwd [IN]
 *   Current Password.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean fdIsPwdValid(uint32_t fd, uint32_t *pwd);

/**********************************************************
 * Updates the password for the file descriptor
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @param pwd [IN/OUT]
 *   Current Password as input.
 *   New password on return
 *
 * @return void [OUT]
 *   None.
 *
 **********************************************************/
void fdUpdatePwd(uint32_t fd, uint32_t *pwd);

/**********************************************************
 * Updates the whitelist regions for the file descriptor
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @param pGuid [IN]
 *   GUID for the current region
 *
 * @param ulStartAddr [IN]
 *   Start address of the whitelist region.
 *
 * @param ulSize [IN]
 *   Size of the whitelist region.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean fdUpdateWhitelist(uint32_t fd, void *pGuid, uint32_t ulStartAddr, uint32_t ulSize);

/**********************************************************
 * Checks if the region is in the whitelist for the file descriptor
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @param ulStartAddr [IN]
 *   Start address of the whitelist region.
 *
 * @param ulSize [IN]
 *   Size of the whitelist region.
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean fdWhitelistCheck(uint32_t fd, uint32_t ulStartAddr, uint32_t ulSize);

#endif /* __OSPI_FD_H__ */
