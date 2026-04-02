/**
 * @file gpio_summary_intr.c
 * @brief
 * Source file for gpio interrupt driver of SAIL
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include "gpio.h"
#include "gpio_summary_intr.h"
#include "types.h"
#include "sail_tlmm_hwio.h"
#include "gpio_os.h"
#include "debug_log.h"

#ifdef SAILSW1
  #include "sleepEl1.h"
#endif


#define MAX_NUMBER_OF_UGPIOS        (10u)
#define MAX_NUMBER_OF_GPIOS         (79u)

#define VALID_UGPIO(x)     ((x) < MAX_NUMBER_OF_GPIOS)
#define VALID_UGPIO_IDX(x) (uGPIOIntData.aGPIOLUT[(x)] != UGPIOINT_NONE)
#define UGPIOINT_IDX(x)    (uGPIOIntData.aGPIOLUT[(x)])

/*
 * uGPIOIntDataType
 *
 * Structure storing the details for micro GPIO interrupts
 */
typedef struct
{
  uint16                nInterrupt;
  uint8                 nTrigger;
  //uint8                 nFlags;
  uint8                 nGPIO;
  uGPIOINTISR           pCB;
  uGPIOINTISR        params;
} uGPIOIntDataType;

/*
 * uGPIOIntCntrlType
 *
 * Container for all local data
 *
 * state            State table
 * uGPIOIntLock     Synchronization object
 * puGPIOIntConfig  Pointer to target config data
 * nNumConfigs      Number of entries in target config data
 * hPDQDI           QDI handle for reserving/freeing GPIOs in GPIOInt_PD
 * aGPIOLUT         LUT for GPIO entry's index in state table
 * bInit            Flag for marking the driver as initialized
 */
typedef struct
{
  uGPIOIntDataType       state[MAX_NUMBER_OF_UGPIOS];
  mutex_t                uGPIOIntLock;
  uint32_t                 nNumConfigs;
  uint8                  aGPIOLUT[MAX_NUMBER_OF_GPIOS];
  uint8                  bInit;
} uGPIOIntCntrlType;

GPIO_GLOBAL_DATA static uGPIOIntCntrlType uGPIOIntData;

#ifdef SAILSW1

  GPIO_GLOBAL_DATA static uint32 ulGPIOSummaryIRQSleepHandle = 0;

  static void prvGPIOSummaryIRQDeInit_Sleep( const sleepModeType_e eState );

#endif

/*===========================================================================
**  Function :  uGPIOSummaryInt_IsGPIOIntConfigured
** ==========================================================================
*/
/*!
*
* @brief
*   Function to check if a gpio is already configured as interrupt
*
* @param
*
* @par Dependencies
*   None
* @retval
* UGPIOINT_SUCCESS -- Is returned if the gpio interruptalready configured
  UGPIOINT_ERROR --   Is returned if gpio interrupt is not configured
* @par Side Effects
*   None
*
*/
static int32 uGPIOSummaryInt_IsGPIOIntConfigured
(
    uint32 nGPIO
)
{
    uint32 nIdx = 0;
    uint32 pnState = 0;
    int32 siReturnStatus = UGPIOINT_ERROR;

    for (nIdx = 0; nIdx < MAX_NUMBER_OF_UGPIOS; nIdx++)
    {  

        if(nGPIO == uGPIOIntData.state[nIdx].nGPIO)
        {
           siReturnStatus =  UGPIOINT_SUCCESS;
           break;
        }

    }

    return siReturnStatus;
} /* End of uGPIOSummaryInt_IsGPIOIntConfigured*/

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
eSailGPIOStatus_t uGPIOClearSummaryIntrStatus(uint32_t uiGPIOn)
{
  uint32 RegReadVal = 0u;
  eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;
  if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
  {
    out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_STATUS_REG_OFFS_BMSK, 0u);
    RegReadVal = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_STATUS_REG_OFFS_BMSK);
    if(0U == RegReadVal)
    {
      eGpioStatus = GPIO_E_OK;
    }
  }
  return eGpioStatus;
} /* End of uGPIOSummaryInt_ClearInterruptStatus*/


/*===========================================================================
**  Function :  uGPIOSummaryInt_ConfigureInterrupt
** ==========================================================================
*/
/*!
*
* @brief
*   This function configures a gpio interrupt at tlmm
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
static eSailGPIOStatus_t uGPIOSummaryInt_ConfigureInterrupt(uint32_t uiGPIOn, uint32_t nTrigger, uint32_t nRawStatusEn, uint32_t nTargetProc)
{
	uint32_t nRegValue = 0u;
  uint32_t RegReadVal = 0u;
  eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;

  if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
  {
	nRegValue = nTrigger;
	nRegValue |= GPIO_INTR_CFG(nRawStatusEn, nTargetProc);

	  out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, nRegValue);
    RegReadVal = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);
    if(nRegValue == RegReadVal)
    {
      eGpioStatus = GPIO_E_OK;
    }
  }
  return eGpioStatus;
} /*End of uGPIOSummaryInt_ConfigureInterrupt*/

/*===========================================================================
**  Function :  uGPIOSummaryInt_DeConfigureInterrupt
** ==========================================================================
*/
/*!
*
* @brief
*   This function de-configures a gpio interrupt at tlmm
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
static eSailGPIOStatus_t uGPIOSummaryInt_DeConfigureInterrupt(uint32_t uiGPIOn)
{
  uint32_t RegReadVal = 0u;
  eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;
  if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
  {
  /* Write reset value to intr config register*/
	  out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, SAIL_GPIO_INTR_CFG_REG_DEFAULT_VAL);
    RegReadVal = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);
    if(SAIL_GPIO_INTR_CFG_REG_DEFAULT_VAL == RegReadVal)
    {
      eGpioStatus = GPIO_E_OK;
    }
  }
  return eGpioStatus;
} /*End of uGPIOSummaryInt_DeConfigureInterrupt*/

/*==========================================================================

   FUNCTION      uGPIOSummaryInt_GetTrigger

  DESCRIPTION   This function gets the trigger type for the gpio interrupt.

  PARAMETERS    
  uint32 nInterrupt  : The interrupt vector number.
  uint32 nTrigger    : The interrupt trigger type.

  DEPENDENCIES  None.

  RETURN VALUE  None.

  SIDE EFFECTS  None.

==========================================================================*/

static uint32 uGPIOSummaryInt_GetTrigger
(
  uint32              nGPIO,
  uGPIOIntTriggerType eTrigger
)
{
     GPIO_UNUSED_PARAMETER(nGPIO);
    uint32  uValGPIOIntrCfg = 0;
    switch(eTrigger)
    {
        case UGPIOINT_TRIGGER_HIGH:
            uValGPIOIntrCfg = UGPIOINT_LEVEL_HIGH;
        break;

        case UGPIOINT_TRIGGER_LOW:
            uValGPIOIntrCfg = UGPIOINT_LEVEL_LOW;
        break;

        case UGPIOINT_TRIGGER_RISING:
            uValGPIOIntrCfg = UGPIOINT_EDGE_POS;
        break;

        case UGPIOINT_TRIGGER_FALLING:
            uValGPIOIntrCfg = UGPIOINT_EDGE_NEG;
        break;

        case UGPIOINT_TRIGGER_DUAL_EDGE:
            uValGPIOIntrCfg = UGPIOINT_EDGE_DUAL;
        break;

        default:
            uValGPIOIntrCfg = UGPIOINT_LEVEL_HIGH;
        break;
    }

    return uValGPIOIntrCfg;

} /* End of uGPIOSummaryInt_GetTrigger*/

/*===========================================================================
**  Function :  uGPIO_ISR_CB
** ==========================================================================
*/
/*!
*
* @brief
*   Gpio ISR for summary interrupts
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
static void uGPIO_ISR_CB(void *args)
{
    uint32 nIdx = 0u;
    uint32 pnState = 0u;

    GPIO_UNUSED_PARAMETER(args);

    for (nIdx = 0u; nIdx < MAX_NUMBER_OF_UGPIOS; nIdx++)
    {  
        (void)uGPIO_Is_SummaryIntr_Pending( uGPIOIntData.state[nIdx].nGPIO, &pnState);
        if(1u == pnState)
        {
            if
			      ( 
                (uGPIOIntData.state[nIdx].nTrigger == (uint8)UGPIOINT_TRIGGER_HIGH) || 
                (uGPIOIntData.state[nIdx].nTrigger == (uint8)UGPIOINT_TRIGGER_LOW) 
            )
            {
                /* 
                  For a level trigerred interrupt, if the interrupt is cleared 
                  before handling the interrupt trigger would result in another
                  interrupt. So the ISR is called before clearing interrupt
                 */
                (void)uGPIOIntData.state[nIdx].pCB(uGPIOIntData.state[nIdx].params);
                (void)uGPIOClearSummaryIntrStatus(uGPIOIntData.state[nIdx].nGPIO);
            }
            else
            {
                /* 
                   For an edge triggered interrupt if the interrupt is cleared after
                   calling client handler then the falling edge interrupts are lost
                   Therefore edge triggered interrupts are cleared before client 
                   handler is called 
                */
                (void)uGPIOClearSummaryIntrStatus(uGPIOIntData.state[nIdx].nGPIO);
                (void)uGPIOIntData.state[nIdx].pCB(uGPIOIntData.state[nIdx].params);
            }
            

            break;
        }
    }
} /*End of uGPIO_ISR*/

static void uGPIO_ISR(void *args)
{
  //EL1(FreeRTOS)/EL2 ISR handles FPU registers save/restore.
  uGPIO_ISR_CB(args);
} /*End of uGPIO_ISR*/

/*==========================================================================

  FUNCTION      uGPIOSummaryInt_AssignInterruptIndex

  DESCRIPTION   Stores the index assigned for gpio in state table to LUT

==========================================================================*/

static int32 uGPIOSummaryInt_AssignInterruptIndex
(
  uint32 nGPIO
)
{
  uint32 nIdx;
  int32 siReturnStatus = UGPIOINT_ERROR;

  if (uGPIOIntData.aGPIOLUT[nGPIO] == UGPIOINT_NONE)
  {
    for (nIdx = 0; nIdx < MAX_NUMBER_OF_UGPIOS; nIdx++)
    {
      if (uGPIOIntData.state[nIdx].nGPIO == UGPIOINT_NONE)
      {
        uGPIOIntData.state[nIdx].nGPIO = (uint8)nGPIO;
        uGPIOIntData.aGPIOLUT[nGPIO] = (uint8)nIdx;
        siReturnStatus =  UGPIOINT_SUCCESS;
        break;
      }
    }
  }

  return siReturnStatus;
} /*End of uGPIOSummaryInt_AssignInterruptIndex*/

/*==========================================================================

   FUNCTION      uGPIOSummaryInt_RegisterInterrupt

   DESCRIPTION   See gpio_summary_intr.h

==========================================================================*/
int32 uGPIORegister_SummaryIntr
(   
    uint32 nGPIO,
    uGPIOIntTriggerType eTrigger,
    uGPIOINTISR isr,
	uGPIOINTISR param
)
{

  int32 siReturnStatus = UGPIOINT_ERROR;

    if ((VALID_UGPIO_IDX(nGPIO)) || (!VALID_UGPIO(nGPIO)) || (eTrigger < UGPIOINT_TRIGGER_HIGH) || (eTrigger > UGPIOINT_TRIGGER_DUAL_EDGE))
    {
        // if condition true then status is UGPIOINT_ERROR
    }
    else
    {
      GPIOOS_MutexLock(&uGPIOIntData.uGPIOIntLock);

      if (UGPIOINT_SUCCESS == uGPIOSummaryInt_AssignInterruptIndex(nGPIO))
      {
        uGPIOIntData.nNumConfigs++;
        uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].nTrigger = (uint8)eTrigger;

        /* Only cosnidering summary interrupts*/
        uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].nInterrupt = UGIOINT_SUMMARY_INTID;

        uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].pCB = isr;
        uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].params = param;

        /*configure interrupt at tlmm*/
        (void)uGPIOSummaryInt_ConfigureInterrupt(nGPIO, uGPIOSummaryInt_GetTrigger(nGPIO, eTrigger), 0x1, UGPIOINT_TARGET_PROC_HMSS);

        siReturnStatus = UGPIOINT_SUCCESS;
      }

      GPIOOS_MutexUnlock(&uGPIOIntData.uGPIOIntLock);
    }

    return siReturnStatus;

}/* END uGPIOSummaryInt_RegisterInterrupt */

/*=============================================================================
  FUNCTION      uGPIOSummaryInt_DeregisterInterrupt

   DESCRIPTION   See gpio_summary_intr.h

=============================================================================*/

int32 uGPIODeregister_SummaryIntr( uint32  nGPIO)
{
  int32 siReturnStatus = UGPIOINT_ERROR;

    GPIOOS_MutexLock(&uGPIOIntData.uGPIOIntLock);
    if(UGPIOINT_SUCCESS != uGPIOSummaryInt_IsGPIOIntConfigured(nGPIO))
    {
      // if condition true then status returned is UGPIOINT_ERROR
    }
    else
    {
      (void)uGPIOSummaryInt_DeConfigureInterrupt(nGPIO);

      uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].nGPIO = UGPIOINT_NONE;
      uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].nTrigger = (uint8_t)UGPIOINT_TRIGGER_HIGH;
      uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].nInterrupt = UGPIOINT_NONE;
      uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].pCB = NULL;
      uGPIOIntData.state[UGPIOINT_IDX(nGPIO)].params = NULL;

      uGPIOIntData.aGPIOLUT[nGPIO] = UGPIOINT_NONE;
      uGPIOIntData.nNumConfigs--;
      siReturnStatus = UGPIOINT_SUCCESS;
    }

    GPIOOS_MutexUnlock(&uGPIOIntData.uGPIOIntLock);

    return siReturnStatus;
}/*End of uGPIOSummaryInt_DeregisterInterrupt*/

/*==========================================================================

   FUNCTION      uGPIOSummaryInt_IsInterruptPending

   DESCRIPTION   See gpio_summary_intr.h

==========================================================================*/
static int32 uGPIO_Is_SummaryIntr_Pending( uint32  nGPIO, uint32 *pnState)
{
  int32 siReturnStatus = UGPIOINT_ERROR;

    if(UGPIOINT_SUCCESS != uGPIOSummaryInt_IsGPIOIntConfigured(nGPIO))
    {
        // if condition is true then status returned is UGPIOINT_ERROR
    }
    else 
    {

      if(1u == in_dword(sail_gpio_base + (PIN_WIDTH * nGPIO) + SAIL_GPIO_INT_STATUS_REG_OFFS_BMSK))
      {
          *pnState = 1u;
      }
      else
      {
          *pnState = 0u;
      }

      siReturnStatus = UGPIOINT_SUCCESS;

    }

    return siReturnStatus;
}/*End of uGPIOSummaryInt_IsInterruptPending*/

/*==========================================================================

   FUNCTION      uGPIOSummaryInt_EnableInterrupt

   DESCRIPTION   See gpio_summary_intr.h

==========================================================================*/

int32 uGPIOSummaryInt_EnableInterrupt(uint32_t uiGPIOn)
  
{
    uint32_t nRegValue = 0u;
    uint32_t RegReadValue = 0u;
    int32_t status = (int32_t)UGPIOINT_NONE; 

	if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
  {
    if(UGPIOINT_SUCCESS != uGPIOSummaryInt_IsGPIOIntConfigured(uiGPIOn))
    {
        status =  UGPIOINT_ERROR;
    }

    if(status != UGPIOINT_ERROR)
    {
      nRegValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);
      nRegValue |= 1u;
      out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, nRegValue);

      RegReadValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);
      if(nRegValue == RegReadValue)
      {
        status = UGPIOINT_SUCCESS;
      }
    }
  }
  return status;
} /*End of uGPIOSummaryInt_EnableInterrupt*/

/*==========================================================================

   FUNCTION      uGPIOSummaryInt_DisableInterrupt

   DESCRIPTION   See gpio_summary_intr.h

==========================================================================*/

int32 uGPIODisable_SummaryIntr(uint32_t uiGPIOn)
{
    uint32_t nRegValue = 0u;
    uint32_t RegReadValue = 0u;
    int32_t status = (int32_t)UGPIOINT_NONE; 
  
  	if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
    {

      if(UGPIOINT_SUCCESS != uGPIOSummaryInt_IsGPIOIntConfigured(uiGPIOn))
      {
        status =  UGPIOINT_ERROR;
      }
      else
      {
        nRegValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);
        nRegValue &= (SAIL_GPIO_DISABLE_SUMMARY_INTR);// 0xFFFFFFFEu, clear 0th bit
        out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, nRegValue);

        RegReadValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);
        if(RegReadValue == nRegValue)
        {
          status = UGPIOINT_SUCCESS;
        }
      }
    }
    return status;
} /*End of uGPIOSummaryInt_DisableInterrupt*/

/*==========================================================================

   FUNCTION      uGPIOSummaryInt_TriggerInterrupt

   DESCRIPTION   See gpio_summary_intr.h

==========================================================================*/


int32 uGPIOTrigger_SummaryIntr(uint32_t uiGPIOn)
{
  int32 siReturnStatus = UGPIOINT_ERROR;
    if(UGPIOINT_SUCCESS != uGPIOSummaryInt_IsGPIOIntConfigured(uiGPIOn))
    {
        //if conidtion is true then returned status is UGPIOINT_ERROR
    }
    else
    {
      out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn) + SAIL_GPIO_INT_STATUS_REG_OFFS_BMSK, 0x1);
      siReturnStatus = UGPIOINT_SUCCESS;
    }

    return siReturnStatus;
} /* End of uGPIOSummaryInt_TriggerInterrupt*/

/*=============================================================================
  FUNCTION      uGPIOSummaryInt_GetInterruptID

  DESCRIPTION   See gpio_summary_intr.h

=============================================================================*/
int32
uGPIOSummaryInt_GetInterruptID
(
  
  uint32 nGPIO,
  uint32* pnInterruptID
)
{
    int32 siReturnStatus = UGPIOINT_ERROR;
    if(UGPIOINT_SUCCESS != uGPIOSummaryInt_IsGPIOIntConfigured(nGPIO))
    {
        
    }
    else
    {
      *pnInterruptID = UGIOINT_SUMMARY_INTID;
      siReturnStatus = UGPIOINT_SUCCESS;
    }

    return siReturnStatus;
} /*End of uGPIOSummaryInt_GetInterruptID*/

/*==========================================================================

   FUNCTION      uGPIOSummaryInt_Init

   DESCRIPTION   See gpio_summary_intr.h

==========================================================================*/
int32 uGPIOSummaryInt_Init
(
    void
)
{
    uint32 nIdx = 0;

    if(uGPIOIntData.bInit != 1u)
    {
        GPIOOS_MutexInit(&uGPIOIntData.uGPIOIntLock);

        /*
        * Initialize the uGPIOInt LUT table
        */
        for (nIdx = 0; nIdx < MAX_NUMBER_OF_GPIOS; nIdx++)
        {
          uGPIOIntData.aGPIOLUT[nIdx] = UGPIOINT_NONE;
        }

        /*
        * Initialize the uGPIO state table
        */
        for (nIdx = 0; nIdx < MAX_NUMBER_OF_UGPIOS; nIdx++)
        {
            uGPIOIntData.state[nIdx].nInterrupt = UGPIOINT_NONE;
            uGPIOIntData.state[nIdx].nGPIO = UGPIOINT_NONE;
        }
        /* Set Number fo Configd to 0*/
        uGPIOIntData.nNumConfigs = 0;

        /* Set GPIO initialised */
        uGPIOIntData.bInit = 1;

        /*Configue interrupt at interrupt controller*/
        /*Summary interrupts at GIC level can either be level or edge triggered.
          GPIO Driver configures it as level trigerred */
        (void)GPIOOS_RegisterInterrupt
        (
          UGIOINT_SUMMARY_INTID,
          GPIOOS_TRIGGER_LEVEL,
          (GPIOOSInterruptHandle*) uGPIO_ISR,
          NULL
        );
    }

    #ifdef SAILSW1

    if ( ulGPIOSummaryIRQSleepHandle == 0U )
    {
      if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&prvGPIOSummaryIRQDeInit_Sleep,&ulGPIOSummaryIRQSleepHandle,get_curr_phys_cpu_num()))
      {
          DEBUG_LOG(SAIL_ERROR,"prvGPIOSummaryIRQDeInit_Sleep Sleep Reg Failed\n\r");
      }
      else
      {
          DEBUG_LOG(SAIL_INFO,"prvGPIOSummaryIRQDeInit_Sleep Sleep Reg Success\n\r");
      }
    }
  #endif

    return UGPIOINT_SUCCESS;
}/* END uGPIOSummaryInt_Init */

/*===========================================================================
**  Function :  GPIO_DeRegisterInterrupt
** ==========================================================================
*/
/*!
*
* @brief
*   GPIO_DeRegisterInterrupt API De-registers the summary Interrupt
*
* @param
*
* @par nVectorId: IRQ number or vector ID
*      nFlags :   FALSE - Disable / TRUE - Enable
* @retval
*   None
* @par Side Effects
*   None
*
*/

static void GPIO_DeRegisterInterrupt(uint32_t nVectorId, uint32_t nFlags)
{
  
  
    (void)GPIOOS_DeRegisterInterrupt( nVectorId, nFlags);
  
}


/*===========================================================================
**  Function :  sail_gpio_Deinit
** ==========================================================================
*/
/*!
*
* @brief
*   Gpio De-init function
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

eSailGPIOStatus_t sail_gpio_Deinit(void)
{

  eSailGPIOStatus_t eStatus = GPIO_E_NOT_OK;
	if(uGPIOIntData.bInit == 1u)
	{
		GPIO_DeRegisterInterrupt(UGIOINT_SUMMARY_INTID,FALSE);
    uGPIOIntData.bInit = 0u;
    eStatus = GPIO_E_OK;
	}

  return eStatus;

}

#ifdef SAILSW1

/*========================================================================================================
 @Service name        prvGPIOSummaryIRQDeInit_Sleep
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit GPIOSummaryIRQ Driver
                                SLEEP_ABORT = arg from sleep driver in case sleep Driver want to abort sleep
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 =========================================================================================================*/

static void prvGPIOSummaryIRQDeInit_Sleep( const sleepModeType_e eState )
{
              DEBUG_LOG(SAIL_ERROR,"###### prvGPIOSummaryIRQDeInit_Sleep \n\r");

    if(( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))
    {
        if ( GPIO_E_OK == sail_gpio_Deinit() )
        {
          if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(ulGPIOSummaryIRQSleepHandle,DRIVER_SLEEP,get_curr_phys_cpu_num()))
          {
              DEBUG_LOG(SAIL_INFO,"[GPIO] : prvGPIOSummaryIRQDeInit_Sleep xSleepDriverAck Success\n\r");
          }else
          {
              DEBUG_LOG(SAIL_ERROR,"[GPIO] prvGPIOSummaryIRQDeInit_Sleep xSleepDriverAck Failed\r\n");
          }
          
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"[GPIO] : uGPIODeregister_SummaryIntr Failed\r\n");
        }
    }
    else
    {
        DEBUG_LOG(SAIL_ERROR,"[GPIO] : Abort Request Recieved\r\n");
    }
}

#endif
