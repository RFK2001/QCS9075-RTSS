/*
===========================================================================
*/
/**
  @file IPCCBSP.c

  Image specific config file for the IPC Controller driver.
*/
/*
  ====================================================================

  Copyright (c) 2021-2025 Qualcomm Technologies,Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies,Inc.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/src/sail/8650/IPCCBSP.c#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "IPCC_Internal.h"
#include "common_functions.h"

/*=========================================================================
      Macros
==========================================================================*/

/*
 *  Clients for this target are AOP to TMESS
 */
#define NUM_CLIENTS                       ((uint8_t)IPCC_C_TOTAL)

#define IPCC_MPROC_BASE_ADDRESS           (0xC0400000u)
#define IPCC_COMPUTE_L0_BASE_ADDRESS      (0xC0440000u)
#define IPCC_COMPUTE_L1_BASE_ADDRESS      (0xC0480000u)
#define IPCC_PCIE_BASE_ADDRESS            (0xC0400000u)// Ravi: this base address is wrong 
#define IPCC_SAIL_MPROC_BASE_ADDRESS      (0xF1600000u)


/*=========================================================================
      Static definitions
==========================================================================*/

//HAve one for sail cpu client .

BSP_GLOBAL_DATA static IPCCClientType IPCCClient0[NUM_CLIENTS];
BSP_GLOBAL_DATA static IPCCClientType IPCCClient1[NUM_CLIENTS];
BSP_GLOBAL_DATA static IPCCClientType IPCCClient2[NUM_CLIENTS];
BSP_GLOBAL_DATA static IPCCClientType IPCCClient3[NUM_CLIENTS];

BSP_GLOBAL_DATA static IPCCProtocolType IPCCProtocols0[] =
{  
  {
    .pszName = "MPROC",
    .nProtocolId = IPCC_P_MPROC,
    .nNumSigs = 8,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 39,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient0[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L0",
    .nProtocolId = IPCC_P_COMPUTEL0,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 43,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L0_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient0[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L1",
    .nProtocolId = IPCC_P_COMPUTEL1,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 47,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L1_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient0[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "PCIE",
    .nProtocolId = IPCC_P_PCIEMSI,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 0,
    .nInterrupt = 47,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_PCIE_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient0[0],
    .bIPCCModeSupported = 0,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "SAIL_MPROC",
    .nProtocolId = IPCC_P_SAIL_MPROC,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 32,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_SAIL_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient0[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },  
};
BSP_GLOBAL_DATA static IPCCProtocolType IPCCProtocols1[] =
{
  {
    .pszName = "MPROC",
    .nProtocolId = IPCC_P_MPROC,
    .nNumSigs = 8,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 40,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient1[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L0",
    .nProtocolId = IPCC_P_COMPUTEL0,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 44,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L0_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient1[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L1",
    .nProtocolId = IPCC_P_COMPUTEL1,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 48,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L1_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient1[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "PCIE",
    .nProtocolId = IPCC_P_PCIEMSI,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 0,
    .nInterrupt = 47,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_PCIE_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient1[0],
    .bIPCCModeSupported = 0,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "SAIL_MPROC",
    .nProtocolId = IPCC_P_SAIL_MPROC,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 33,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_SAIL_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient1[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },  
};
BSP_GLOBAL_DATA static IPCCProtocolType IPCCProtocols2[] =
{
  {
    .pszName = "MPROC",
    .nProtocolId = IPCC_P_MPROC,
    .nNumSigs = 8,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 41,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient2[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L0",
    .nProtocolId = IPCC_P_COMPUTEL0,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 45,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L0_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient2[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L1",
    .nProtocolId = IPCC_P_COMPUTEL1,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 49,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L1_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient2[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "PCIE",
    .nProtocolId = IPCC_P_PCIEMSI,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 0,
    .nInterrupt = 47,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_PCIE_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient2[0],
    .bIPCCModeSupported = 0,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "SAIL_MPROC",
    .nProtocolId = IPCC_P_SAIL_MPROC,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 34,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_SAIL_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient2[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },  
};
BSP_GLOBAL_DATA static IPCCProtocolType IPCCProtocols3[] =
{
  {
    .pszName = "MPROC",
    .nProtocolId = IPCC_P_MPROC,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 42,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient3[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L0",
    .nProtocolId = IPCC_P_COMPUTEL0,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 46,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L0_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient3[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  }, 
  {
    .pszName = "COMPUTE_L1",
    .nProtocolId = IPCC_P_COMPUTEL1,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 50,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_COMPUTE_L1_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient3[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "PCIE",
    .nProtocolId = IPCC_P_PCIEMSI,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 0,
    .nInterrupt = 47,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_PCIE_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient3[0],
    .bIPCCModeSupported = 0,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },
  {
    .pszName = "SAIL_MPROC",
    .nProtocolId = IPCC_P_SAIL_MPROC,
    .nNumSigs = 32,
    .nNumClients = NUM_CLIENTS,
    .bIsSupported = 1,
    .nInterrupt = 35,      //GEt the right vector number
    .nPhysBaseAddress = IPCC_SAIL_MPROC_BASE_ADDRESS,
    .nOffset = 0x0,
    .pClients = &IPCCClient3[0],
    .bIPCCModeSupported = 1,
    /*
     * This is required for all Wildcat arch with intro to TME
     */
    .bSkipOneTimeConfig = 1,
  },  
};




BSP_GLOBAL_DATA  IPCCBSPDataType IPCCBSPData[4] =
{
  {
  .pProtocols = &IPCCProtocols0[0],
  .nNumProtocols = (sizeof(IPCCProtocols0)/sizeof(IPCCProtocolType)),
  .eClient = IPCC_C_SAIL0,
  .bIPCCMode = 1,
  },
  {
  .pProtocols = &IPCCProtocols1[0],
  .nNumProtocols = (sizeof(IPCCProtocols1)/sizeof(IPCCProtocolType)),
  .eClient = IPCC_C_SAIL1,
  .bIPCCMode = 1,
  },
  {
  .pProtocols = &IPCCProtocols2[0],
  .nNumProtocols = (sizeof(IPCCProtocols2)/sizeof(IPCCProtocolType)),
  .eClient = IPCC_C_SAIL2,
  .bIPCCMode = 1,
  },
  {
  .pProtocols = &IPCCProtocols3[0],
  .nNumProtocols = (sizeof(IPCCProtocols3)/sizeof(IPCCProtocolType)),
  .eClient = IPCC_C_SAIL3,
  .bIPCCMode = 1,
  },  
};
