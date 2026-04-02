#ifndef IPCC_H__
#define IPCC_H__
/*
===========================================================================
*/
/**
  @file IPCC.h
  @brief Public interface include file for accessing the IPCC device driver.

  The IPCC.h file is the public API interface to the Inter-Processor 
  Communication Controller driver.
*/
/*
  ===========================================================================

  Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/public/IPCC.h#1 $
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

#include <stdint.h>

/*=========================================================================
      Type Definitions
==========================================================================*/

#ifndef SAILEL2
#define IPCC_FUNC  __attribute__ ( ( section ( "ipcc_func" ) ) )
#else
#define IPCC_FUNC
#endif

/** @addtogroup data_types
@{ */

/**
 * Opaque handle for clients reference to the driver.
 */
typedef void*         IPCC_Handle;

/**
 * Signal value to listen in on or to trigger. 
 * Values range from 0 to number supported. 
 */
typedef uint32_t      IPCC_Signal;

/**
 * Return value is a number.  They generally take form 
 * of definitions defined as IPCC_E*. Success generally 
 * returns IPCC_EOK for example. 
 */
typedef uint32_t      IPCCErr;

/**
 * Protocol enumeration based on IPCC specification.
 */
typedef enum
{
  /**< MPROC Protocol */
  IPCC_P_MPROC = 0,

  /**< Compute Level 0 Protocol */
  IPCC_P_COMPUTEL0 = 1,

  /**< Compute Level 1 Protocol */
  IPCC_P_COMPUTEL1 = 2,

  /**< PCIe Message Signal Interrupt Protocol */
  IPCC_P_PCIEMSI = 3,

  /**< SAIL CPU Cores Message Signal Interrupt Protocol */
  IPCC_P_SAIL_MPROC = 4,
  
  /**< Total number of supported protocols */
  IPCC_P_TOTAL
}
IPCC_Protocol;

/**
 * Client enumeration based on IPCC specification.
 */
typedef enum
{
  /**< Always-On Processor */
  IPCC_C_AOP = 0u,

  /**< Trustzone (Secure Application Processor) */
  IPCC_C_TZ = 1u,

  /**< Modem DSP */
  IPCC_C_MPSS = 2u,

  /**< Low-Power Audio DSP */
  IPCC_C_LPASS = 3u,

  /**< Sensors Low Power Island DSP */
  IPCC_C_SLPI = 4u,

  /**< Sensors Co-Processor */
  IPCC_C_SDC = 5u,

  /**< Neuro System Processor (0) / Turing */
  IPCC_C_NSP0 = 6u,
  IPCC_C_CDSP = IPCC_C_NSP0,

  /**< Neuro Processing Unit */
  IPCC_C_NPU = 7u,

  /**< Application Processor (Non-Secure) */
  IPCC_C_APPS = 8u,

  /**< Graphics Processing Unit */
  IPCC_C_GPU = 9u,

  /**< Computer Vision Processor */
  IPCC_C_CVP = 10u,

  /**< Camera Processor */
  IPCC_C_CAM = 11u,

  /**< Video Processing Unit */
  IPCC_C_VPU = 12u,

  /**< PCIe Client 0 */
  IPCC_C_PCIE0 = 13u,

  /**< PCIe Client 1 */
  IPCC_C_PCIE1 = 14u,

  /**< PCIe Client 2 */
  IPCC_C_PCIE2 = 15u,

  /**< Secure Processor */
  IPCC_C_SPSS = 16u,

  /**< Safety Management Subsystem */
  IPCC_C_SMSS = 17u,

  /**< Neuro System Processor */
  IPCC_C_NSP1 = 18u,

  /**< PCIe Client 3 */
  IPCC_C_PCIE3 = 19u,

  /**< PCIe Client 4 */
  IPCC_C_PCIE4 = 20u,

  /**< PCIe Client 5 */
  IPCC_C_PCIE5 = 21u,

  /**< PCIe Client 6 */
  IPCC_C_PCIE6 = 22u,

  /**< Trust Management Engine Subsystem */
  IPCC_C_TMESS = 23u,

  /**< Wireless Processor Subsystem */
  IPCC_C_WPSS = 24u,

  /**< DPU */
  IPCC_C_DPU = 25u,

  /**< IPA */
  IPCC_C_IPA = 26u,
  
  /**< SAIL0 */
  IPCC_C_SAIL0	= 27u,
  
  /**< SAIL1 */
  IPCC_C_SAIL1	= 28u,
  
  /**< SAIL2 */
  IPCC_C_SAIL2	= 29u,
  
  /**< SAIL3 */
  IPCC_C_SAIL3	= 30u,
  
  /**< GPDSP0 */
  IPCC_C_GPDSP0	= 31u,
  
  /**< GPDSP1 */
  IPCC_C_GPDSP1	= 32u,
  
  /**< APSS_NS1 */
  IPCC_C_APSS_NS1	= 33u,
  
  /**< APSS_NS2 */
  IPCC_C_APSS_NS2	= 34u,
  
  /**< APSS_NS3 */
  IPCC_C_APSS_NS3	= 35u,
  
  /**< APSS_NS4 */
  IPCC_C_APSS_NS4	= 36u, 

  /**< Total number of supported clients */
  IPCC_C_TOTAL
}IPCC_Client;

/**
 * Callback data type, natural datatype size based on processor.
 */
typedef void*         IPCC_CBData;


/**
 * Callback function prototype for receiving incoming interrupt 
 * signals. 
 */
typedef void (*IPCC_CB) (IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal);

/** @} */ /* end_data_types */

/** @addtogroup constants_macros
@{ */

/**
 * Return value MACROs.
 */


/** @} */ /* end_addtogroup constants_macros */

typedef enum 
{
  IPCC_GIC_SGI_ERROR             = -10,/**<IPCC Handle creation failed */
  IPCC_GIC_REGISTER_ERROR        = -9,/**<IPCC GIC error */
  IPCC_INTR_REGISTRATION_ERROR   = -8,/**<GIC IPCC ISR for core failed */
  IPCC_ENOTSUPPORTED 			 = -7, /**< Signal not supported error */
  IPCC_ENOTFOUND     			 = -6,/**< Signal not found error */
  IPCC_EUNUSED       			 = -5, /**< Signal not used error */
  IPCC_EINUSE        			 = -4, /**< Signal in-use error */
  IPCC_EARG          			 = -3, /**< Argument error */
  IPCC_EMEM          			 = -2, /**< Memory error */
  IPCC_EGENERR       			 = -1, /**< Generic (unspecified) error */
  IPCC_EOK           			 =  0 /**< Success */
}IPCC_Status_t;




/*=========================================================================
      Interface Declarations
==========================================================================*/
/** @addtogroup ipcc_functions
@{ */

/* =========================================================================
**  Function : IPCC_AttachEx
** =========================================================================*/
/**
  Attaches given handle to IPCC driver and protocol.

  This function takes a reference to a user handle and protocol enumeration.
  This function must be called before calling any other IPCC API in order to
  notify the IPCC driver of the requirement to use the protocol requested.  

  @param pH        [out] Reference to a client handle.
  @param eProtocol [in]  IPCC protocol requested to use.
  @param eClient   [in]  Client of the IPCC protocol.
  @param sail_client_idx   [in]  Client idx of the IPCC protocol.

  @return
  IPCC_EOK -- Successfully attached to protocol eProtocol. \n
  IPCC_EGENERR -- IPCC not yet initialized. \n
  IPCC_EMEM -- Insufficient memory available for client handle reference. \n
  IPCC_ENOTSUPPORTED -- Protocol requested is not supported. \n
  IPCC_EARG -- Unsupported argument passed in by client.

  @dependencies
  Driver must be initialized.
*/

IPCC_Status_t
IPCC_AttachEx
(
  IPCC_Handle   *pH,
  IPCC_Protocol eProtocol,
  IPCC_Client   eClient,
  uint32_t      sail_client_idx
);

// IPCC diagnostics function prototype
extern IPCC_FUNC IPCC_Status_t IPCC_diagnostics(void);


extern IPCC_FUNC void IPCC_InitEx(IPCC_Protocol eProtocol,uint32_t   sail_client_idx);


/* =========================================================================
**  Function : IPCC_Detach
** =========================================================================*/
/**
  Detaches the given handle from IPCC driver.

  This function takes a reference to a user handle and detaches it from the
  driver.  It should only be used if there is no requirement for this handle
  at the point it's called.  

  @param pH        [out] Reference to a client handle.

  @return
  IPCC_EOK -- Successfully detached client handle. \n
  IPCC_EARG -- Unsupported argument passed in by client.

  @dependencies
  Handle must be valid, and driver must be initialized.
*/

IPCC_Status_t
IPCC_Detach
(
  IPCC_Handle *pH
);

/**
  Detaches the given handle from IPCC driver.

  This function takes a reference to a user handle and detaches it from the
  driver.  It should only be used if there is no requirement for this handle
  at the point it's called.  

  @param pH        [in] Reference to a client handle.
  @param sail_client_id [in] Reference to a client ID.

  @return
  IPCC_EOK -- Successfully detached client handle. \n
  IPCC_EARG -- Unsupported argument passed in by client.

  @dependencies
  Handle must be valid, and driver must be initialized.
*/
IPCC_FUNC IPCC_Status_t IPCCDrv_DetachEx
( 
	IPCC_Handle *pH,
	uint32_t sail_client_id
);
/* =========================================================================
**  Function : IPCC_RegisterInterrupt
** =========================================================================*/
/**
  Registers a callback function for when signals are received from a given
  sender.

  This function is used to register a notification with the IPCC driver.
  The callback function pfnCB is called whenever the sender eSenderCID
  signals the processor running this SW with any of the signals in the
  range nSignalLow to nSignalHigh.  If only one signal is being registered,
  then nSignalLow should be the same as nSignalHigh.  If any of the signals
  are in use, then the API will fail and none of the requested signals will
  be registered.

  @param h           [in] Client handle.
  @param eSenderCID  [in] Client ID of the sender.
  @param nSignalLow  [in] Lowest signal number to listen on.
  @param nSignalHigh [in] Highest signal number to listen on.
  @param pfnCB       [in] Callback function for when signal is received.
  @param nData       [in] Data to pass into callback function when signal
                          is received.

  @return
  IPCC_EOK -- Successfully registered the signals for eSenderCID. \n
  IPCC_EARG -- Unsupported argument passed in by client. \n
  IPCC_EINUSE -- One or more of the requested signals are in use.

  @dependencies
  Handle must be valid, and driver must be initialized.
*/

IPCC_FUNC IPCC_Status_t
IPCC_RegisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh,
  IPCC_CB           pfnCB,
  IPCC_CBData       nData
);


/* =========================================================================
**  Function : IPCC_DeregisterInterrupt
** =========================================================================*/
/**
  Deregisters a previously registered callback function for signals
  received from a given sender.

  This function is used to deregister a notification from the IPCC driver.
  This will remove all future notificatoins of the previously registered
  callback function from happening.  If only one signal is being deregistered,
  then nSignalLow should be the same as nSignalHigh.  If any of the signals
  are not in use, then the API will fail and none of the requested signals will
  be deregistered.

  @param h           [in] Client handle.
  @param eSenderCID  [in] Client ID of the sender.
  @param nSignalLow  [in] Lowest signal number to deregister.
  @param nSignalHigh [in] Highest signal number to deregister.

  @return
  IPCC_EOK -- Successfully deregistered the signals for eSenderCID. \n
  IPCC_EARG -- Unsupported argument passed in by client. \n
  IPCC_EUNUSED -- One or more of the requested signals are not in use.

  @dependencies
  Handle must be valid, and driver must be initialized.
*/

IPCC_FUNC IPCC_Status_t
IPCC_DeregisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
);


/* =========================================================================
**  Function : IPCC_Trigger
** =========================================================================*/
/**
  Triggers interrupts on remote clients.

  This function is used to assert the signals in the range nSignalLow to
  nSignalHigh on target eTargetCID.  

  @param h           [in] Client handle.
  @param eTargetCID  [in] Client ID of the target.
  @param nSignalLow  [in] Lowest signal number to assert.
  @param nSignalHigh [in] Highest signal number to assert.

  @return
  IPCC_EOK -- Successfully trigger the signals to eTargetCID. \n
  IPCC_EARG -- Unsupported argument passed in by client.

  @dependencies
  Handle must be valid, and driver must be initialized.
*/

IPCC_FUNC IPCC_Status_t
IPCC_Trigger
(
  IPCC_Handle       h,
  IPCC_Client       eClient,
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
);


#ifdef TEST_SRC_ENABLED
IPCC_Handle *IPCC_GetHandle(uint8_t cpu_id);
#endif
//Add test APIs
// GetInfo?
// GetSupportedClientIDs?
// IsClientSupported?

/** @} */ /* end_addtogroup ipcc_functions */

#endif /*__IPCC_H__*/
