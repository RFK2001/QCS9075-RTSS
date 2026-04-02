#ifndef SAIL_GPIO_SUMMARY_INT_DRIVER_H_
#define SAIL_GPIO_SUMMARY_INT_DRIVER_H_

/**
 * @file gpio_summary_intr.h
 * @brief
 * Header file for gpio interrupt driver of sail
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#include "gpio.h"
/*
  This macro defines an invalid value that tells the different processors how to treat the GPIO configuration.
 */
#define UGPIOINT_NONE           (uint8)0xFF

/*
  This macro defines the summary interrupt id
 */
#define UGIOINT_SUMMARY_INTID         (572u)

#define UGPIOINT_TARGET_PROC_HMSS     (0x3u)
#define SAIL_GPIO_INTR_CFG_REG_DEFAULT_VAL  (0xE2u)

#define SAIL_GPIO_DISABLE_SUMMARY_INTR       (0xFFFFFFFEu)

/*
 * The error codes are to be kept in syun with the dal error codes.
 */
#define UGPIOINT_SUCCESS         0
#define UGPIOINT_ERROR          -1
#define UGPIOINT_LEVEL_LOW       0x0
#define UGPIOINT_LEVEL_HIGH      0x2
#define UGPIOINT_EDGE_POS        0x4
#define UGPIOINT_EDGE_NEG        0x8
#define UGPIOINT_EDGE_DUAL       0xC






/**< Interrupt flags -- To be used with Register API to indicate special requirements */
#define UGPIOINTF_DSR    0x20 /**< Delayed Service Routine, Must call uGPIOSummaryInt_InterruptDone when the interrupt is ready to be re-enabled/acknowledged */
#define UGPIOINTF_ISLAND 0x40 /**< Island mode interrupt, this will allow for the interrupt to be handled in island mode */
#define UGPIOINTF_TIMESTAMP_EN  0x80 /**< Enable timestamping unit, this will allow the timestamp to be captured when interrupts are detected */

/* =========================================================================
**  Function : uGPIOSummaryInt_RegisterInterrupt
** =========================================================================*/
/*
  Registers a client callback notification for a GPIO interrupt.

  This function registers the client callback isr routine to a given GPIO 
  interrupt.Whenever an interrupt is fired the isr routine registered by the 
  user is called. \n
  
  @param[in] gpio      The GPIO pin number.
  @param[in] trigger   The interrupt trigger condition for which the client callback is being registered.
  @param[in] isr       The client ISR callback.
  @param[in] param     The Client specified parameter to be given to the client callback when the interrupt fires.
  
  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the ISR registration was a success. \n
  UGPIOINT_ERROR -- An Error if the uGPIOInt driver was not able to register the interrupt
  service routine (ISR). \n
  @dependencies
  None.
*/

int32
uGPIORegister_SummaryIntr( uint32 nGPIO,uGPIOIntTriggerType eTrigger,
uGPIOINTISR isr,uGPIOINTISR param);



/*===========================================================================
**  Function :  uGPIOSummaryInt_ClearInterruptStatus
** ==========================================================================
*/
/*!
*
* @brief
*   Function to clear the interrupt status at the tlmm
*
* @param
*
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/

extern eSailGPIOStatus_t uGPIOClearSummaryIntrStatus(uint32_t uiGPIOn);

/*=============================================================================
  FUNCTION      uGPIOSummaryInt_DeregisterInterrupt
=============================================================================*/
 /*
  Deregisters the client callback routine to a given GPIO interrupt.

  This function deregisters the client callback ISR function to a given GPIO 
  interrupt.As a result of which the interrupt is disabled. \n
   
  @param[in] gpio       The GPIO pin number.

  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the ISR deregistration was a success. \n
  UGPIOINT_ERROR -- Is returned if the uGPIOInt driver was not able to deregister 
  the client interrupt service routine. \n
  @dependencies
  None.
*/

int32
uGPIODeregister_SummaryIntr( uint32  nGPIO);


/*=============================================================================
  FUNCTION      uGPIOSummaryInt_IsInterruptPending
=============================================================================*/
/*
  Queries the GPIO interrupt pending state.

  This function tells the user if the given gpio interrupt is pending or not. \n
  
  @param[in] gpio       The GPIO pin number.
  @param[in] state      The pointer to a client allocated uint32 
                           variable which is populated by the uGPIOInt driver 
                           to indicate whether the interrupt is pending or not.

  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the gpio state query was successful. \n
  UGPIOINT_ERROR --  Is returned if the GPIO is unsupported. \n
  @dependencies
  None.
*/

static int32 uGPIO_Is_SummaryIntr_Pending( uint32  nGPIO, uint32 *pnState);


/*=============================================================================
  FUNCTION      uGPIOSummaryInt_TriggerInterrupt
=============================================================================*/
/*
  Artificially force triggers an interrupt
   
  This function is used to trigger an interrupt without the GPIO interrupt 
  being actually set in hardware.
   
  @param[in] gpio           The GPIO pin number.

  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the gpio interrupt was 
  triggered successfully. \n 
  UGPIOINT_ERROR --  Is returned if the GPIO number is invalid. 
  \n 
  @dependencies
  None.
*/

int32 uGPIOTrigger_SummaryIntr(uint32_t uiGPIOn);

/*=============================================================================
  FUNCTION      uGPIOSummaryInt_GetInterruptID
=============================================================================*/
/*
  This function gets the interrupt ID at the interrupt controller that
  this driver is running on. \n

  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the GPIO has a valid interrupt ID. \n
  UGPIOINT_ERROR --  Is returned if the GPIO does not have a valid interrupt ID. \n
  @dependencies
  None.
*/
int32
uGPIOSummaryInt_GetInterruptID
(
  
  uint32 nGPIO,
  uint32* pnInterruptID
);


/*=============================================================================
  FUNCTION      uGPIOSummaryInt_EnableInterrupt
=============================================================================*/
/*
  This function enables the interrupt at the interrupt controller for
  a given GPIO. \n

  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the GPIO has successfully been enabled. \n
  UGPIOINT_ERROR --  Is returned if the GPIO was not successfully enabled. \n
  @dependencies
  None.
*/

extern int32 uGPIOSummaryInt_EnableInterrupt(uint32_t uiGPIOn);

  


/*=============================================================================
  FUNCTION      uGPIOSummaryInt_DisableInterrupt
=============================================================================*/
/*
  This function disables the interrupt at the interrupt controller for
  a given GPIO. \n

  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the GPIO has successfully been disabled. \n
  UGPIOINT_ERROR --  Is returned if the GPIO was not successfully disabled. \n
  @dependencies
  None.
*/

extern int32 uGPIODisable_SummaryIntr(uint32_t uiGPIOn);
  

/*============================================================================= 
 
  FUNCTION      uGPIOSummaryInt_Init

  This is the main driver initialization function that is called in the
  gpio.c. \n

  DEPENDENCIES  None.
  @return
  UGPIOINT_SUCCESS -- Is returned if the uGPIOSummaryInt driver was correctly initialized. \n
  UGPIOINT_ERROR --  Is returned if the uGPIOSummaryInt initialization failed. \n
  @dependencies
  None.
 
=============================================================================*/
int32 uGPIOSummaryInt_Init
(
  void
);


#endif /*SAIL_GPIO_SUMMARY_INT_DRIVER_H_*/
