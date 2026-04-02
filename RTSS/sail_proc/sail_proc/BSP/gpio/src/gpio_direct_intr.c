/*============================================================================*/
/* Project      = Automotive                                                  */
/* Module       = gpio                                                        */
/* File         = gpio_direct_intr.c                                          */
/*============================================================================*/
/*                              COPYRIGHT                                     */
/*============================================================================*/
/* Copyright(c) 2023-2025 Qualcomm                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of GPI Direct Interrupts   */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                              HEADER FILE                                   */
/*============================================================================*/

#include "gpio.h"
#include "types.h"
#include "sail_tlmm_hwio.h"
#include "gpio_direct_intr.h"
#include "gpio_os.h"
#include "chipinfo.h"
#include "interrupts.h"
/*============================================================================*/
/*                            Exported  Global Data                           */
/*============================================================================*/


/*============================================================================*/
/*                              Global Data                                   */
/*============================================================================*/

/*Direct Connect Interrupt base address and IRQ number*/

static const stSailGpioDirectIntrAddrIrq_t uiDirectIntrBaseAddrIrqLT [] =
{
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR0_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D000UL,
        .uiDirectIntrIRQNum  = 573u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR1_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D004UL,
        .uiDirectIntrIRQNum  = 574u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR2_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D008UL,
        .uiDirectIntrIRQNum  = 575u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR3_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D00CUL,
        .uiDirectIntrIRQNum  = 576u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR4_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D010UL,
        .uiDirectIntrIRQNum  = 577u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR5_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D014UL,
        .uiDirectIntrIRQNum  = 578u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR6_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D018UL,
        .uiDirectIntrIRQNum  = 579u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR7_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D01CUL,
        .uiDirectIntrIRQNum  = 580u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR8_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D020UL,
        .uiDirectIntrIRQNum  = 581u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR9_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D024UL,
        .uiDirectIntrIRQNum  = 582u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR10_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D028UL,
        .uiDirectIntrIRQNum  = 583u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR11_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D02CUL,
        .uiDirectIntrIRQNum  = 584u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR12_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D030UL,
        .uiDirectIntrIRQNum  = 585u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR13_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D034UL,
        .uiDirectIntrIRQNum  = 586u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR14_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D038UL,
        .uiDirectIntrIRQNum  = 587u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR15_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015D03CUL,
        .uiDirectIntrIRQNum  = 588u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR16_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015B004UL,
        .uiDirectIntrIRQNum  = 589u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR17_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015B008UL,
        .uiDirectIntrIRQNum  = 590u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR18_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015B00CUL,
        .uiDirectIntrIRQNum  = 591u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR19_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015B010UL,
        .uiDirectIntrIRQNum  = 592u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR20_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015B014UL,
        .uiDirectIntrIRQNum  = 570u,
    },
    {
        .uiDirectIntrBaseAddrLeM = HWIO_SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTR21_CFG_HMSS_ADDR,
        .uiDirectIntrBaseAddrMoco = 0xF015B018UL,
        .uiDirectIntrIRQNum  = 571u,
    },
};


/*Number of Direct Interrupts*/
#define  NUM_OF_DIRECT_INTR      \
(sizeof(uiDirectIntrBaseAddrIrqLT)/sizeof(uiDirectIntrBaseAddrIrqLT[0]))

/*============================================================================*/
/*                              Private Data                                  */
/*============================================================================*/

GPIO_GLOBAL_DATA static uint32_t uiDirectIntrRegCount = 0u;

/*Storing Direct Connect register base address*/
//GPIO_GLOBAL_DATA static uint32_t uiSailGpioDirectBase = 0u;

GPIO_GLOBAL_DATA static eSailGpioDirectLevelIntr_t ePolarity = PLACEHOLDER_VALUE;

/*Storing the registering callbacks*/
GPIO_GLOBAL_DATA static stGpioDirectIntrCB_type stGpioDirectCB[NUM_OF_DIRECT_INTR] = {0};

/*============================================================================*/
/*                              Function Definition                           */
/*============================================================================*/

/*******************************************************************************
** Function Name        : eGpio_DirectConnectIntrCfg
**
**
** Description          : Interrupts are routed to the Target core 
**                        This API configures/selects the Target Core (ARM R52)
**
** Input Parameters     : uiGPIO : GPIO pin number
**                        uiTargetProc :UGPIOINT_TARGET_PROC_HMSS: 
**                                      HMSS is for ARM R52 core (0x3u)
**                        
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
**
** Functions invoked    : None 
**
** Registers Used       : SAILSS_TLMM_SAILSS_TLMM_GPIO_INTR_CFGn
**                        (n: Gpio pin number)
*******************************************************************************/

static eSailGPIOStatus_t eGpio_DirectConnectIntrCfg(uint32_t uiGPIO, const stSailGpioDirectIntrCfg_t* const pDirectIntrCfg)
{
    eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
    uint32_t uiRegValue = 0u;
    uint32_t uiRegReadbackValue = 0u;

    if(uiGPIO <= SAIL_GPIO_MAX_NUM_PINS)
    {
        /* Concatinating the configured values */
        uiRegValue = ( (pDirectIntrCfg->bfTargetProcessor) | (pDirectIntrCfg->bfIntrLevelEdgeSel) | ((uint32_t)ePolarity << 1u) );

        out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, uiRegValue);

        uiRegReadbackValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);

        if(uiRegReadbackValue == uiRegValue)
        {
            estatus = GPIO_E_OK;
        }
    }

    return estatus;
}

/*******************************************************************************
** Function Name        : eGpio_IsDirectIntrPending
**
**
** Description          : This API cheks for the TLMM/GPIO Direct connect
**                        Interrupts pending status.
**
** Input Parameters     : uiGPIO : GPIO pin number
**                        
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
** Functions invoked    : None
**
** Registers Used       : SAILSS_TLMM_SAILSS_TLMM_GPIO_INTR_CFGn
**                        (n: Gpio pin number)
*******************************************************************************/

static eSailGPIOStatus_t eGpio_IsDirectIntrPending(uint32_t uiGPIO)
{
    eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
    uint32_t uiRegValue = 0u;

    if(uiGPIO <= SAIL_GPIO_MAX_NUM_PINS)
    {
        uiRegValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);

        /* Reading the 8th bit to check if the interrupt is pending or not*/
        uiRegValue &=  SAIL_GPIO_DIRECT_INTR_ENABLE;

        if(uiRegValue == SAIL_GPIO_DIRECT_INTR_ENABLE)
        {
          estatus = GPIO_E_OK;  
        }
    }

    return estatus;

}

/*******************************************************************************
** Function Name        : eGpio_ClearDirectIntrStatus
**
**
** Description          : This API Clears the TLMM/GPIO Direct
**                        Interrupts Pending status.
**
** Input Parameters     : uiGPIO : GPIO pin number
**                        
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
**
** Functions invoked    : None
**
** Registers Used       : SAILSS_TLMM_SAILSS_TLMM_GPIO_INTR_CFGn
**                        
*******************************************************************************/

eSailGPIOStatus_t eGpio_ClearDirectIntrStatus(uint32_t uiGPIO)
{
    eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
    uint32_t uiRegReadbackValue = 0u;

    if((uiGPIO <= SAIL_GPIO_MAX_NUM_PINS) && (GPIO_E_OK == eGpioDirectIntrInitStatus))
    {
        out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_STATUS_REG_OFFS_BMSK, 0u);

        uiRegReadbackValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_STATUS_REG_OFFS_BMSK);

        if(0u == uiRegReadbackValue)
        {
            estatus = GPIO_E_OK;
        }

    }

    return estatus;
} 

/*******************************************************************************
** Function Name        : vGpio_ISR_CallBack
**
**
** Description          : This API is GPIO callback.
**                        Interrupts.
**
** Input Parameters     : args: This a Pointer to void.
**                        
**
** Return parameter     : None
**
**
** Functions invoked    : eGpio_IsDirectIntrPending
**
** Registers Used       : None
*******************************************************************************/

static void vGpio_ISR_CallBack( void *args)
{
    GPIO_UNUSED_PARAMETER(args);
    uint32_t uiIndex = 0u;
    eSailGPIOStatus_t eStatus = GPIO_E_NOT_OK;

    for(uint32_t Count = 0u;Count < NUM_OF_DIRECT_INTR;Count++)
    {
        /* Checking for the pending interrupts*/
        eStatus = eGpio_IsDirectIntrPending(stGpioDirectCB[Count].uiGpioNum);

        if(GPIO_E_OK == eStatus)
        {
            uiIndex = Count;
            break;

        }
    }
    /* Calling the Application registered callback */ 
    (void)stGpioDirectCB[uiIndex].pCB(stGpioDirectCB[uiIndex].params);

    /* Clearing the interrupt status */  
    (void)eGpio_ClearDirectIntrStatus(stGpioDirectCB[uiIndex].uiGpioNum);

}

static void vGpio_CallBack( void *args)
{
    //EL1(FreeRTOS)/EL2 ISR handles FPU registers save/restore.
    vGpio_ISR_CallBack( args);
}

/*******************************************************************************
** Function Name        : eGpio_DirectConnectIntr
**
**
** Description          : This API Configures Interrupt Polarity and registers  
**                        the call backs for the TLMM/GPIO Direct Interrupts.
**                        
**
** Input Parameters     : uiGPIO : GPIO pin number
**                        uiPolarity :The GPIO interrupt will trigger only if 
**                        the input signal is low SAIL_GPIO_TRIGGER_DIRECT_INT_LOW
**                        The GPIO interrupt will trigger only if the input signal 
**                        is high SAIL_GPIO_TRIGGER_DIRECT_INT_HIGH
**                        Callback: Function pointer 
**                        args : Pointer to void
**                        
**                        
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
**
** Functions invoked    : GPIOOS_RegisterInterrupt
**
** Registers Used       : SAILSS_TLMM_SAILSS_TLMM_DIR_CONN_INTRn_CFG_HMSS
**                        
*******************************************************************************/

static eSailGPIOStatus_t eGpio_DirectConnectIntr
(
    uint32_t uiGPIO,
    eGpioDirectIntrPolarityEdgeSel_t uiPolarity,
    uGPIOINTISR Callback,
	uGPIOINTISR args
)
{
    eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
    uint32_t uiRegValue = 0u;
    uint32_t uiRegReadbackValue = 0u;
    GPIOOS_TriggerType eIntrTrigger;
    uint32_t uiSailGpioDirectBase = 0u;

    if((uiPolarity == SAIL_GPIO_TRIGGER_FALLING_EDGE) || (uiPolarity == SAIL_GPIO_TRIGGER_RISING_EDGE) || (SAIL_GPIO_TRIGGER_DUAL_EDGE == uiPolarity))
    {
        // Polarity 0: Edge triggered interrupts

        eIntrTrigger = GPIOOS_TRIGGER_EDGE; 
        ePolarity = SAIL_GPIO_TRIGGER_DIRECT_INT_POLARITY_0; 
    }
    else
    {
        // Polarity 1: Level triggered interrupts
        eIntrTrigger = GPIOOS_TRIGGER_LEVEL;
        ePolarity = SAIL_GPIO_TRIGGER_DIRECT_INT_POLARITY_1; 
        
    }

    if((uiGPIO <= SAIL_GPIO_MAX_NUM_PINS) && (uiDirectIntrRegCount < NUM_OF_DIRECT_INTR))
    {
        /* Get the base address of the direct interrupt connect register */ 
#ifdef monaco
        uiSailGpioDirectBase = uiDirectIntrBaseAddrIrqLT[uiDirectIntrRegCount].uiDirectIntrBaseAddrMoco;
#else
        uiSailGpioDirectBase = uiDirectIntrBaseAddrIrqLT[uiDirectIntrRegCount].uiDirectIntrBaseAddrLeM;
#endif
        /* bit 8: 0: rising and falling trigger bit 8: 1: level trigger */ 
        uiRegValue &= (((uint32_t)ePolarity << 8u));

        /* Selecting the GPIO pin for direct connect Intr */ 
        uiRegValue |= uiGPIO;

        out_dword(uiSailGpioDirectBase, uiRegValue);

        uiRegReadbackValue = in_dword(uiSailGpioDirectBase);

        if(uiRegReadbackValue == uiRegValue)
        {
            /* Registering SAIL GPIO Application callback */ 
            stGpioDirectCB[uiDirectIntrRegCount].uiGpioNum = uiGPIO;

            stGpioDirectCB[uiDirectIntrRegCount].pCB = Callback;

            stGpioDirectCB[uiDirectIntrRegCount].params = args;

            // registering SAIL GPIO direct connect callback
            (void)GPIOOS_RegisterInterrupt
            (
                /* Direct connect vector or IRQ number */
                uiDirectIntrBaseAddrIrqLT[uiDirectIntrRegCount].uiDirectIntrIRQNum,
                /*
                SAILSw1:
                2u: Configuring GPIO Edge triggered
                0u: Configuring GPIO Level triggered

                SAILhyp:
                1u: Configuring GPIO Edge triggered
                0u: Configuring GPIO Level triggered
                */
                eIntrTrigger,
                //Callback function
                (GPIOOSInterruptHandle*) vGpio_CallBack,
                //arguments 
                NULL 
            );

            estatus = GPIO_E_OK;

            uiDirectIntrRegCount++;
        }

    }

    return estatus;
}

/*******************************************************************************
** Function Name        : eGpio_RegisterDirectIntr
**
**
** Description          : This API Enables or Disables the TLMM/GPIO Direct
**                        Interrupts.
**
** Input Parameters     : uiGPIO : GPIO pin number
**                        uiDirectIntr : SAIL_GPIO_DIRECT_INTR_EN for enabling 
**                        the interrupts.
**                        SAIL_GPIO_DIRECT_INTR_DIS for disabling the interrupt.
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
**
** Functions invoked    : eGpio_DirectConnectIntrCfg
**                        eGpio_DirectConnectIntr
**
** Registers Used       : None
*******************************************************************************/

eSailGPIOStatus_t eGpio_RegisterDirectIntr
(   
    uint32_t uiGPIO,
    eGpioDirectIntrPolarityEdgeSel_t eTrigger,
    uGPIOINTISR Callback,
	uGPIOINTISR args
)
{
    eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
    eSailGPIOStatus_t estatusArr[2u] = {GPIO_E_NOT_OK,GPIO_E_NOT_OK};

    stSailGpioDirectIntrCfg_t unDirectIntrCfg = {0u};

    /* bit 7:5 Configure the target processor*/
    unDirectIntrCfg.bfTargetProcessor = GPIO_INTR_CFG(0u,UGPIOINT_TARGET_PROC_HMSS);

    /*bit 3:2 Level or edge trigger interrupts */
    unDirectIntrCfg.bfIntrLevelEdgeSel = GPIO_DIRECT_LEVEL_EDGE_SEL((uint32_t)eTrigger);

    if((uiGPIO <= SAIL_GPIO_MAX_NUM_PINS) && (GPIO_E_OK == eGpioDirectIntrInitStatus) && (uiDirectIntrRegCount < NUM_OF_DIRECT_INTR))
    {
        /* Configuring the direct connect interrupt polarity and gpio pin number */
        estatusArr[0] = eGpio_DirectConnectIntr(uiGPIO,eTrigger,Callback,args);

        /* Configuring the direct connect interrupt polarity, edge or level trigger selection and Target processor */
        estatusArr[1] = eGpio_DirectConnectIntrCfg(uiGPIO,&unDirectIntrCfg);
        
        if((GPIO_E_OK == estatusArr[0]) && (GPIO_E_OK == estatusArr[1]))
        {
            estatus = GPIO_E_OK;
        }

    }

    return estatus;

}
/*******************************************************************************
** Function Name        : eGpio_DeregisterDirectIntr
**
**
** Description          : This API deregisters the TLMM/GPIO Direct
**                        Interrupts.
**
** Input Parameters     : uiGPIO : GPIO pin number
**
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
**
** Functions invoked    : None
**
** Registers Used       : None
*******************************************************************************/

eSailGPIOStatus_t eGpio_DeregisterDirectIntr( uint32_t uiGPIO )
{
	eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
	uint32_t uiRegValue = 0xE2;
	uint32_t uiRegReadbackValue   = 0u;
	uint32_t uiSailGpioDirectBase = 0u;
    
	if((uiGPIO <= SAIL_GPIO_MAX_NUM_PINS) && (GPIO_E_OK == eGpioDirectIntrInitStatus) && (uiDirectIntrRegCount < NUM_OF_DIRECT_INTR))
	{
		out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, uiRegValue);

		uiRegReadbackValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);

		if(uiRegReadbackValue == uiRegValue)//Read after write check
		{
			ePolarity = PLACEHOLDER_VALUE;

			uiRegValue = 0x100;
            
            /* Get the base address of the direct interrupt connect register */
            #ifdef monaco
            uiSailGpioDirectBase = uiDirectIntrBaseAddrIrqLT[uiDirectIntrRegCount].uiDirectIntrBaseAddrMoco;
			#else
            uiSailGpioDirectBase = uiDirectIntrBaseAddrIrqLT[uiDirectIntrRegCount].uiDirectIntrBaseAddrLeM;
			#endif

			out_dword(uiSailGpioDirectBase, uiRegValue);

			uiRegReadbackValue = in_dword(uiSailGpioDirectBase);

			if(uiRegReadbackValue == uiRegValue)
			{
				stGpioDirectCB[uiDirectIntrRegCount].uiGpioNum = 0;

				stGpioDirectCB[uiDirectIntrRegCount].pCB = NULL;

				stGpioDirectCB[uiDirectIntrRegCount].params = NULL;

				(void)GPIOOS_DeRegisterInterrupt(uiDirectIntrBaseAddrIrqLT[uiDirectIntrRegCount].uiDirectIntrIRQNum,FALSE);

				estatus = GPIO_E_OK;

				uiDirectIntrRegCount--; //Successfully deregistered the interrupt

			}
		}
	}

	return estatus;
}

/*******************************************************************************
** Function Name        : eGpio_EnableDirectIntr
**
**
** Description          : This API Enables the TLMM/GPIO Direct
**                        Interrupts.
**
** Input Parameters     : uiGPIO : GPIO pin number
**                        uiDirectIntr : SAIL_GPIO_DIRECT_INTR_ENABLE for enabling 
**                        the interrupts.
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
**
** Functions invoked    : None
**                        
**
** Registers Used       : None
*******************************************************************************/

eSailGPIOStatus_t eGpio_EnableDirectIntr( uint32_t uiGPIO )
{
    eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
    uint32_t uiRegValue = 0u;
    uint32_t uiRegReadbackValue = 0u;

    uiRegValue = SAIL_GPIO_DIRECT_INTR_ENABLE;

    if((uiGPIO <= SAIL_GPIO_MAX_NUM_PINS) && (GPIO_E_OK == eGpioDirectIntrInitStatus))
    {
        /*
        bit 8: '0' Disable Direct Interrupts
        bit 8: '1' Enable Direct Interrupts
        */
        out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, uiRegValue);

        uiRegReadbackValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);

        uiRegReadbackValue &= (SAIL_GPIO_DIRECT_INTR_ENABLE); 

        if(uiRegReadbackValue == uiRegValue)
        {
            estatus = GPIO_E_OK;
        }

    }

    return estatus;

}


/*******************************************************************************
** Function Name        : eGpio_DisableDirectIntr
**
**
** Description          : This API Enables or Disables the TLMM/GPIO Direct
**                        Interrupts.
**
** Input Parameters     : uiGPIO : GPIO pin number
**                        uiDirectIntr : SAIL_GPIO_DIRECT_INTR_DISABLE for Disabling 
**                        the interrupts.
**
** Return parameter     : estatus:GPIO_E_OK if Read After write check passes
**                                GPIO_E_NOT_OK if Read After Write Check Fails
**
**
** Functions invoked    : None
**                        
**
** Registers Used       : None
*******************************************************************************/

eSailGPIOStatus_t eGpio_DisableDirectIntr( uint32_t uiGPIO )
{
    eSailGPIOStatus_t estatus = GPIO_E_NOT_OK;
    uint32_t uiRegValue = 0u;
    uint32_t uiRegReadbackValue = 0u;

    uiRegValue = SAIL_GPIO_DIRECT_INTR_DISABLE;

    if((uiGPIO <= SAIL_GPIO_MAX_NUM_PINS) && (GPIO_E_OK == eGpioDirectIntrInitStatus))
    {
        /*
        bit 8: '0' Disable Direct Interrupts
        bit 8: '1' Enable Direct Interrupts
        */
        out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK, uiRegValue);

        uiRegReadbackValue = in_dword(sail_gpio_base + (PIN_WIDTH * uiGPIO) + SAIL_GPIO_INT_CFG_REG_OFFS_BMSK);

        uiRegReadbackValue = (uiRegReadbackValue >> 8u);

        if(0u == uiRegReadbackValue)
        {
             estatus = GPIO_E_OK;
        }

    }

    return estatus;

}

