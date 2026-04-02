#ifndef SAIL_GPIO_DIRECT_INT_DRIVER_H
#define SAIL_GPIO_DIRECT_INT_DRIVER_H
/*============================================================================*/
/* Project      = Automotive                                                  */
/* Module       = gpio                                                        */
/* File         = gpio_direct_intr.h                                          */
/*============================================================================*/
/*                              COPYRIGHT                                     */
/*============================================================================*/
/* Copyright(c) 2023-2025 Qualcomm                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Macros,User defined datatypes and function              */
/* Prototype Direct Interrupts                                                */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                              HEADER FILE                                   */
/*============================================================================*/




/*============================================================================*/
/*                              MACROS                                        */
/*============================================================================*/

// Enable TLMM/GPIO Direct Interrupt
#define   SAIL_GPIO_DIRECT_INTR_ENABLE            (256u)// Setting the 8bit position

// Disable TLMM/GPIO Direct Interrupt
#define   SAIL_GPIO_DIRECT_INTR_DISABLE           (0xFFFFFEFFu)//  


/*============================================================================*/
/*                              User Defined Datatypes                        */
/*============================================================================*/

/* GPIO/TLMM direct interrupt polarity enum */
typedef enum 
{
    /* Edge Interrupt: The GPIO interrupt will trigger during rising or falling edge */
    SAIL_GPIO_TRIGGER_DIRECT_INT_POLARITY_0 = 0u, 

    /* Level Interrupt: The GPIO interrupt will trigger only if the input signal is high */
    SAIL_GPIO_TRIGGER_DIRECT_INT_POLARITY_1  = 1u, 

    PLACEHOLDER_VALUE  = 0xFF,
}eSailGpioDirectLevelIntr_t;


typedef enum 
{
    SAIL_GPIO_TRIGGER_LEVEL = 0,
    SAIL_GPIO_TRIGGER_RISING_EDGE = 1,
    SAIL_GPIO_TRIGGER_FALLING_EDGE = 2,
    SAIL_GPIO_TRIGGER_DUAL_EDGE    = 3

}eGpioDirectIntrPolarityEdgeSel_t;



typedef struct 
{

    uint32_t bfTargetProcessor;
    uint32_t bfIntrLevelEdgeSel;

}stSailGpioDirectIntrCfg_t;

typedef struct 
{
    uint32_t uiDirectIntrBaseAddrLeM;
    uint32_t uiDirectIntrBaseAddrMoco;
    uint32_t uiDirectIntrIRQNum;

}stSailGpioDirectIntrAddrIrq_t;

/*============================================================================*/
/*                              Function Prototype                            */
/*============================================================================*/

extern void eGpio_DirectIntrInit(void);

extern  eSailGPIOStatus_t eGpio_ConfigureDirectIntr
(
    uint32_t uiGPIO, 
    uint32_t uiDirectIntr
);

extern eSailGPIOStatus_t eGpio_RegisterDirectIntr
(   
    uint32_t uiGPIO,
    eGpioDirectIntrPolarityEdgeSel_t eTrigger,
    uGPIOINTISR Callback,
	uGPIOINTISR args
);

extern eSailGPIOStatus_t eGpio_DeregisterDirectIntr( uint32_t uiGPIO );

extern eSailGPIOStatus_t eGpio_ClearDirectIntrStatus(uint32_t uiGPIO);

extern eSailGPIOStatus_t eGpio_EnableDirectIntr( uint32_t uiGPIO );

extern eSailGPIOStatus_t eGpio_DisableDirectIntr( uint32_t uiGPIO );





#endif
