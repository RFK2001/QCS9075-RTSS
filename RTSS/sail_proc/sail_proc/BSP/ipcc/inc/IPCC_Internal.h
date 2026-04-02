#ifndef IPCC_INTERNAL_H__
#define IPCC_INTERNAL_H__
/*
===========================================================================
*/
/**
  @file IPCCInternal.h
  @brief Private interface include file for accessing the IPCC internal
  device driver definitions.

  The IPCCInternal.h file is the private API interface to the Inter-Processor 
  Communication Controller driver.
*/
/*
  ===========================================================================

  Copyright (c) 2021-2025 Qualcomm Technologies,Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies,Inc.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/inc/IPCC_Internal.h#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  when       who     what, where, why
  --------   ---     ---------------------------------------------------------- 
  05/18/18   cp      Initial revision.

  ===========================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "IPCC.h"
#include "types.h"
#include "sailbsp_mutex.h"
#include <stdint.h>
#include "IPCC_OS.h"

/*=========================================================================
      Type Definitions
==========================================================================*/

#define IPCC_GET_CID(x) (((x)>>16u)&0xffffu)
#define IPCC_GET_SID(x) ((x)&0xffffu)
#define IPCC_SET_CID(x) (((x)&0xffffu)<<16u)
#define IPCC_SET_SID(x) ((x)&0xffffu)




/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * Signifies no interrupt assignment
 */
#define IPCC_INT_NONE ((uint16_t)-1)

/**
 * IPCC Rx edge info
 */
struct IPCCRxData
{
  IPCC_Signal             nSignalLow;
  IPCC_Signal             nSignalHigh;
  IPCC_CB                 pfnCb;
  IPCC_CBData             nArg;
  struct IPCCRxData* pNext;
};

typedef struct IPCCRxData   IPCCRxDataType;

/**
 * IPCC Client config data
 */
typedef struct
{
  IPCCRxDataType* pList;
  boolean         bUseLegacyByDefault;
}
IPCCClientType;

/** 
 * IPCC Protocol config definition 
 */
typedef struct
{
  char*           pszName;
  IPCC_Protocol   nProtocolId;
  uint16_t        nNumSigs;
  uint8_t         nNumClients;
  uint8_t         bIsSupported;
  uint16_t        nInterrupt;
  uintptr_t       nPhysBaseAddress;
  uintptr_t       nVirtBaseAddress;
  uintptr_t       nOffset;
  IPCCClientType* pClients;
  uint8_t         bLegacySupported;
  uint8_t         bIPCCModeSupported;
  uint8_t         bSkipOneTimeConfig;
}
IPCCProtocolType;

/**
 * IPCC Tx Common Driver Info
 */
typedef struct
{
  IPCC_Protocol          eProtocol;
  uint32_t               nRefs;
}
IPCCTxDrvInfoType;


/**
 * IPCC Tx Common Driver Info
 */
typedef struct
{
  IPCCTxDrvInfoType         TxProtocolDrv[IPCC_P_TOTAL];
  uint32_t                  nRefs;
}
IPCCTxDrvType;

/**
 * IPCC Rx Common Driver Info
 */
typedef struct
{
  IPCC_Protocol          eProtocol;
  IPCCOSMutex            sMutex;
  uint32_t               nRefs;
}
IPCCRxDrvInfoType;

/**
 * IPCC Rx Common Driver Info
 */
typedef struct
{
  IPCCOSInterruptHandle     hInterruptHandle;
  IPCCRxDrvInfoType         RxProtocolDrv[IPCC_P_TOTAL];
  uint32_t                  nRefs;
}
IPCCRxDrvType;

/**
 * Top Level IPCC Config Type
 */
typedef struct
{
  IPCCProtocolType* pProtocols;
  uint32_t          nNumProtocols;
  IPCC_Client       eClient;
  uint8_t           bIPCCMode;
}
IPCCBSPDataType;


extern IPCCBSPDataType  IPCCBSPData[ ];//SAILBSP_CPU_COUNT


/**
 * IPCC Driver context
 */
typedef struct
{
  IPCCBSPDataType*   pBSP;
  IPCCRxDrvType*     pRxDrv;
  IPCCTxDrvType*     pTxDrv;
}
IPCCDrvCtxt;

/**
 * IPCC Client context definition
 */
typedef struct
{
  IPCCProtocolType*   pProtocol;
  IPCCRxDrvInfoType*  pRxDrv;
  IPCCTxDrvInfoType*  pTxDrv;
}
IPCCClientCtxt;

#endif /*__IPCC_INTERNAL_H__*/
