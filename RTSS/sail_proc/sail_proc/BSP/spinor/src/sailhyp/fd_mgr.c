/*
===========================================================================
*/
/**
    @file  fd_mgr.c
    @brief File descriptor functions.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/sailhyp/fd_mgr.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "fd_mgr.h"
#include "gpt_p1.h"
#include "autosar_crc.h"
#include "common_functions.h"

#define OSPI_FD_MAX_NUM          10

typedef struct {
    uint32_t fd;
    boolean bLowPowerFlag;
    boolean bUsed;
    eSpinorUserType eUserType;
    guid_t xGuid;
    uint32_t ulWhitelistStart;
    uint32_t ulWhitelistSize;
    uint32 pwd;
    uint32 coreId;
} FdContextType;

static uint16_t gusFdCount;
static FdContextType ospiFd[OSPI_FD_MAX_NUM];

/**********************************************************
 * Gets the Prefix
 *
 * @return gusFdCount [OUT]
 *   Returns the count value.
 *
 **********************************************************/
static uint16_t fdUtilGetPrefix(void)
{
    gusFdCount++;
    if (gusFdCount == 0)
    {
        gusFdCount++;
    }
    return gusFdCount;
}

/**********************************************************
 * Gets the entry from file descriptor
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @return FdContextType [OUT]
 *   Returns the fd entry.
 *
 **********************************************************/
static FdContextType* fdUtilGetEntry(uint32_t fd)
{
    uint16_t idx = FD_IDX(fd);
    if (idx < OSPI_FD_MAX_NUM && ospiFd[idx].fd == fd && ospiFd[idx].bUsed)
    {
        return &ospiFd[idx];
    }
    else
    {
        return NULL;
    }
}

#ifdef SPINOR_FD_WHITELIST_CHECK
/**********************************************************
 * Checks if the region is a duplicate in the current whitelist
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
static boolean fdCheckDuplicateRegions(uint32_t fd, uint32_t ulStartAddr, uint32_t ulSize)
{
    for (uint16_t i = 0; i < OSPI_FD_MAX_NUM; i++)
    {
        if (ospiFd[i].bUsed == TRUE)
        {
            if( (ospiFd[i].ulWhitelistSize == ulSize ) && (ospiFd[i].ulWhitelistStart == ulStartAddr ) && (fd != ospiFd[i].fd))
            {
                return TRUE;

            }
        }
    }
    return FALSE;
}
#endif /* SPINOR_FD_WHITELIST_CHECK */

#ifdef FD_HANDLE_USE_PWD
/**********************************************************
 * Generates a new password
 *
 * @param pGuid [IN]
 *   GUID.
 *
 * @param pwd [IN]
 *   Current password.
 *
 * @return int [OUT]
 *   New generated password.
 *
 **********************************************************/
static uint32_t fdGeneratePwd(void *pGuid, uint32_t *pwd)
{
    DmaBufPhyAddr BufAddr;
    DmaBufLen BufLen;
    static uint8_t indata[16] = { 0 };
    static uint8_t randomindex=0;
    uint32_t sz = 1;
    uint32_t outdata;
	size_t result = 0;

    /* copying guid to indata */
    result = sailbsp_memscpy(indata, sizeof(indata), pGuid, sizeof(indata));
    if(result == 0)
    {
        return 0;
    }

    /* randomize the index to something within size of indata array */
    /* insert the bytes from current password into indata array */

    for(int i=0;i<sizeof(uint32_t);i++)
    {
        randomindex = (randomindex+indata[randomindex])%sizeof(indata);
        indata[randomindex] = (uint8_t)((*pwd>>(8*i)) & 0xff);
    }

    BufAddr = (DmaBufPhyAddr)indata;
    BufLen = (DmaBufLen)sizeof(indata);

    outdata = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &BufAddr, &BufLen, sz);

    return outdata;
}
#endif /* FD_HANDLE_USE_PWD */

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
eSpinorUserType fdGetUserType ( uint32_t fd )
{
    uint16_t idx = FD_IDX(fd);
    if (idx < OSPI_FD_MAX_NUM && ospiFd[idx].fd == fd && ospiFd[idx].bUsed)
    {
        return ospiFd[idx].eUserType;
    }
    else
    {
        return SPINOR_USER_TYPE_MAX;
    }
}

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
void fdSetLowPowerFlag(uint32_t fd, boolean bLowPower)
{
    FdContextType *ctxt = fdUtilGetEntry(fd);

    if (ctxt)
    {
        ctxt->bLowPowerFlag = bLowPower;
    }
}

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
boolean fdGetLowPowerFlag(uint32_t fd)
{
    FdContextType *ctxt = fdUtilGetEntry(fd);

    if (ctxt)
    {
        return ctxt->bLowPowerFlag;
    }
    else
    {
        /* If not found, treate not allowing low power */
        return FALSE;
    }
}

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
uint16_t fdGetUserCnt(eSpinorUserType eUserType)
{
    uint16_t cnt = 0;

    for (uint16_t i = 0; i < OSPI_FD_MAX_NUM; i++)
    {
        if ((TRUE == ospiFd[i].bUsed) && (eUserType == ospiFd[i].eUserType))
        {
            cnt++;
        }
    }
    return cnt;
}

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
uint32_t fdAlloc(eSpinorUserType eUserType)
{
    boolean bDpdDisable = FALSE;
    uint16_t prefix = fdUtilGetPrefix();
    uint32_t phys_core_id = get_curr_phys_cpu_num();

    for (uint16_t i = 0; i < OSPI_FD_MAX_NUM; i++)
    {
        if (ospiFd[i].bUsed == FALSE)
        {
            ospiFd[i].fd = ( prefix << 16 ) + ( i & 0xFF );
            ospiFd[i].bUsed = TRUE;
            ospiFd[i].bLowPowerFlag = FALSE;
            ospiFd[i].eUserType = eUserType;
            ospiFd[i].coreId = phys_core_id;
            return ospiFd[i].fd;
        }
    }
    return 0;
}

/**********************************************************
 * Frees the file descriptor
 *
 * @param fd [IN]
 *   File descriptor.
 *
 * @return void [OUT]
 *
 **********************************************************/
void fdFree(uint32_t fd)
{
    FdContextType *ctxt = fdUtilGetEntry(fd);
    if (ctxt)
    {
        memset(ctxt, 0, sizeof(FdContextType));
        ctxt->pwd = 0xDEFAFACE;
    }
}

/**********************************************************
 * Checks the low power flag value
 *
 * @param pulUsedCnt [IN/OUT]
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean fdCheckLowPowerFlag(uint32_t *pulUsedCnt)
{
    int ulUsedCnt = 0;
    int i;

    for (i = 0; i < OSPI_FD_MAX_NUM; i++)
    {
        if (!ospiFd[i].bUsed)
        {
            continue;
        }
        ulUsedCnt++;
        if (FALSE == ospiFd[i].bLowPowerFlag)
        {
            /* not allow to low power */
            return FALSE;
        }
    }
    if (pulUsedCnt)
    {
        *pulUsedCnt = ulUsedCnt;
    }
    return TRUE;
}

/**********************************************************
 * Resets the file descriptor
 *
 * @param none
 *
 * @return void [OUT]
 *
 *
 **********************************************************/
void fdReset(void)
{
    int i;
    gusFdCount = 0;
    memset(ospiFd, 0, sizeof(ospiFd));

    for (i = 0; i < OSPI_FD_MAX_NUM; i++)
    {
        ospiFd[i].pwd = 0xDEFAFACE;
    }
}

/**********************************************************
 * Resets the fds upon SW reset
 *
 * @param resetCoreID [IN]
 *   Core ID that got reset.
 *
 * @return void [OUT]
 *
 **********************************************************/
void fdResetonSWreset(uint32 resetCoreID)
{
    int i;

    /* EL1 and EL2 handles reset in case of core0/1 SW reset */
    for (i = 0; i < OSPI_FD_MAX_NUM; i++)
    {
        if (ospiFd[i].bUsed == TRUE && ospiFd[i].coreId == resetCoreID)
        {
            memset(&ospiFd[i], 0, sizeof(ospiFd[i]));
            ospiFd[i].pwd = 0xDEFAFACE;
        }
    }
}

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
boolean fdIsValid(uint32 fd)
{
    FdContextType *ctxt = fdUtilGetEntry(fd);

    if (NULL == ctxt)
    {
        return FALSE;
    }

    return TRUE;
}

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
uint32 fdGetCurrentPwd(uint32_t fd)
{
#ifdef FD_HANDLE_USE_PWD
    FdContextType *ctxt = fdUtilGetEntry(fd);

    if (NULL == ctxt)
    {
        return 0;
    }

    return ctxt->pwd;
#else
    return 0;
#endif /* FD_HANDLE_USE_PWD */
}

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
boolean fdIsPwdValid(uint32_t fd, uint32_t *pwd)
{
#ifdef FD_HANDLE_USE_PWD
    FdContextType *ctxt = fdUtilGetEntry(fd);

    if ((NULL == pwd) || (NULL == ctxt))
    {
        return FALSE;
    }

    if (ctxt->pwd != *pwd)
    {
        return FALSE;
    }

    return TRUE;
#else
    return TRUE;
#endif /* FD_HANDLE_USE_PWD */
}

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
void fdUpdatePwd(uint32_t fd, uint32_t *pwd)
{
#ifdef FD_HANDLE_USE_PWD
    FdContextType *ctxt = fdUtilGetEntry(fd);

    if (NULL == ctxt)
    {
        return;
    }

    *pwd = fdGeneratePwd((void*)&ctxt->xGuid,pwd);

    ctxt->pwd = *pwd;
#else
    *pwd = 0;

#endif /* FD_HANDLE_USE_PWD */
}

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
boolean fdUpdateWhitelist(uint32_t fd, void *pGuid, uint32_t ulStartAddr, uint32_t ulSize)
{
#ifdef SPINOR_FD_WHITELIST_CHECK
    FdContextType *ctxt;
    size_t result = 0;

    /* Region Invalid if the address or size is 0 */
    if ( (0 == ulStartAddr) || (0 == ulSize) )
    {
        return FALSE;
    }

    /* Check for valid FD */
    ctxt = fdUtilGetEntry(fd);
    if (NULL == ctxt)
    {
        return FALSE;
    }


   /* Validate if the entries to the whiltelist location already exists for another user in the FD  */
    if (TRUE == fdCheckDuplicateRegions(fd,ulStartAddr,ulSize))
    {
        return FALSE;
    }


    /* Copy the GUID to the FD */
    result = sailbsp_memscpy((void *)&ctxt->xGuid, sizeof(guid_t), pGuid, sizeof(guid_t));
    if(result == 0)
    {
        return FALSE;
    }

    /* Update FD's whitelist range */
    ctxt->ulWhitelistStart = ulStartAddr;
    ctxt->ulWhitelistSize = ulSize;
#endif /* SPINOR_FD_WHITELIST_CHECK */

    return TRUE;
}

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
boolean fdWhitelistCheck(uint32_t fd, uint32_t ulStartAddr, uint32_t ulSize)
{
#ifdef SPINOR_FD_WHITELIST_CHECK
    uint32_t ulEndAddr = ulStartAddr + ulSize - 1;

    FdContextType *ctxt;

    /* If size is 0 or there is an overflow return error */
    if ((0 == ulSize) || (ulEndAddr <= ulStartAddr))
    {
        return FALSE;
    }

    ctxt = fdUtilGetEntry(fd);

    if (NULL == ctxt)
    {
        return FALSE;
    }

    /* Skip whitelist check for OTA user */
    if ((SPINOR_USER_TYPE_OTA == ctxt->eUserType) || (SPINOR_USER_TYPE_EL1_SUPER == ctxt->eUserType))
    {
        return TRUE;
    }

    /* Return Error if the whitelist regions for that FD is not updated */
    if( (0 == ctxt->ulWhitelistStart) || (0 == ctxt->ulWhitelistSize) )
    {
        return FALSE;
    }

    /* [start,x,end] => valid range */

    /* Return error if address range is not between whitelist start and end region */
    if( (ulStartAddr < ctxt->ulWhitelistStart) ||
        (ulStartAddr >= (ctxt->ulWhitelistStart + ctxt->ulWhitelistSize-1)) ||
        (ulEndAddr > (ctxt->ulWhitelistStart + ctxt->ulWhitelistSize-1))
      )
    {
        return FALSE;
    }
#endif /* SPINOR_FD_WHITELIST_CHECK */
    /* Access is to Whitelist region */
    return TRUE;
}

