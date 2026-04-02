#ifndef SAIL_GPIO_DRIVER_H_
#define SAIL_GPIO_DRIVER_H_

/**
 * @file gpio.h
 * @brief
 * Header file for gpio driver of sail
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include <stdio.h>
#include <stdlib.h>

#include "HALhwio.h"
#include "common_functions.h"


#define GPIO_GLOBAL_DATA   BSP_GLOBAL_DATA

#define PIN_WIDTH                                 0x1000u
#define SAIL_GPIO_IN_OUT_REG_OFFS_BMSK            0x00000004u
#define SAIL_GPIO_INT_CFG_REG_OFFS_BMSK           0x00000008u
#define SAIL_GPIO_INT_STATUS_REG_OFFS_BMSK        0x0000000Cu

#define SAIL_GPIO_MIN_NUM_PINS              (0u)
#define SAIL_GPIO_MAX_NUM_PINS              (78u)
#define UGPIOINT_TARGET_PROC_HMSS          (0x3u)
#define GPIO_GET_CURRENT_CORE()                  get_curr_phys_cpu_num()
#define GPIO_UNUSED_PARAMETER(x)           ((void)(x))

#define SAIL_R52_CLUSTER_0_CORE_0              (0x0u)
#define SAIL_R52_CLUSTER_0_CORE_1              (0x1u)
#define SAIL_R52_CLUSTER_1_CORE_0              (0x2u)
#define SAIL_R52_CLUSTER_1_CORE_1              (0x3u)
/*
 * GPIO_CFGx register format for configuring GPIO settings.
 */
#define SAIL_GPIO_CFG_TO_REG(func, dir, pull, drive) \
              (((uint16_t)(pull)  & 0x3u)        | \
              (((uint16_t)(func)  & 0xFu) << 2u)  | \
              (((uint16_t)(dir)   & 0x1u) << 9u)  | \
              (((uint16_t)(drive) & 0x7u) << 6u))

/*
 * Accessor macros for retrieving GPIO settings.
 */
#define SAIL_GPIO_GET_FUNC(reg)      (((reg) >> 2u) & 0xFu)
#define SAIL_GPIO_GET_DIR(reg)       (((reg) >> 9u) & 0x1u)
#define SAIL_GPIO_GET_PULL(reg)       ((reg) & 0x3u)
#define SAIL_GPIO_GET_DRIVE(reg)     (((reg) >> 6u) & 0x7u)

#define SAIL_GPIO_CFG(gpio, func, dir, pull, drive) \
                          (((gpio) & 0x3FFu) << 4u  | \
                           ((func) & 0xFu  ) << 0u  | \
                           ((dir)  & 0x1u  ) << 14u | \
                           ((pull) & 0x3u  ) << 15u | \
                           ((drive)& 0xFu  ) << 17u)


#define GPIO_NUMBER(config)    (((config) >> 4u) & 0x3FFu)
#define GPIO_FUNCTION(config)   ((config) & 0xFu)
#define GPIO_DIRECTION(config) (((config) >> 14u) & 0x1u)
#define GPIO_PULL(config)      (((config) >> 15u) & 0x3u)
#define GPIO_DRIVE(config)     (((config) >> 17u) & 0xFu)
#define GPIO_INTR_CFG(nRawStatusEn, nTargetProc) \
                            (((nRawStatusEn) & 0x1u) << 4u | \
                             ((nTargetProc ) & 0x7u) << 5u)

#define GPIO_DIRECT_LEVEL_EDGE_SEL(IntrLevelEdge)     ((IntrLevelEdge) << 2u)
/*
 * SAIL gpio sleep set config to reduce leakage
 * input pull down
*/
#define SAIL_GPIO_SLEEP_CFG {0, GPIO_IN, GPIO_PD, GPIO_2MA}

typedef void (*uGPIOINTISR)(void *arg);  /**< This is the void function pointer client callback to be registered with the uGPIOInt driver. */

/*
 * GPIOPullType
 *
 * GPIO Pull type.  Used for input GPIOs to specify, pull-down, no-pull,
 * keeper, or pull-up.
 */
typedef enum
{
  GPIO_NP = 0,  /**<-- GPIO No Pull   >*/
  GPIO_PD,      /**<-- GPIO Pull Down >*/
  GPIO_KP,      /**<-- GPIO Keeper    >*/
  GPIO_PU,      /**<-- GPIO Pull Up   >*/

  GPIO_PULL_FORCE32 = 0x7FFFFFFF

}GPIOPullType;

/*
 * GPIODirType
 *
 * GPIO Direction type.  Specifies if a GPIO should be configured or input
 * or output.
 */
typedef enum
{
  GPIO_IN,   /**<-- GPIO Input   >*/
  GPIO_OUT,  /**<-- GPIO Output  >*/

  GPIO_DIR_FORCE32 = 0x7FFFFFFF

}GPIODirType;

/*
 * GPIOValuetype
 *
 * GPIO Value (HIGH/LOW) type.  Specifies whether a GPIO read is high or low
 * or whether an output pin should driver high or low.
 */
typedef enum
{
  GPIO_LOW,   /**<-- GPIO Low Value  >*/
  GPIO_HIGH,  /**<-- GPIO HighPath   >*/

  GPIO_VALUE_FORCE32 = 0x7FFFFFFF

}GPIOValueType;

typedef enum
{
  GPIO_2MA,    /**<-- GPIO Drive 2 MA  >*/
  GPIO_4MA,    /**<-- GPIO Drive 4 MA  >*/
  GPIO_6MA,    /**<-- GPIO Drive 6 MA  >*/
  GPIO_8MA,    /**<-- GPIO Drive 8 MA  >*/
  GPIO_10MA,   /**<-- GPIO Drive 10 MA  >*/
  GPIO_12MA,   /**<-- GPIO Drive 12 MA  >*/
  GPIO_14MA,   /**<-- GPIO Drive 14 MA  >*/
  GPIO_16MA,   /**<-- GPIO Drive 16 MA  >*/
}GPIODrvType;

/*
 * GPIOConfigType
 *
 * GPIO Configuration type.  This bit-field structure is used to configure a GPIO.
 */
typedef struct 
{
  unsigned int func    :  4;   /**<-- GPIO Function Select Value (uint32)  >*/
  unsigned int dir     :  1;   /**<-- GPIO Direction Value (GPIODirType)   >*/
  unsigned int pull    :  2;   /**<-- GPIO pull Value (GPIOPullType)       >*/
  unsigned int drive   : 12;   /**<-- GPIO drive Value (GPIODirType)       >*/
  unsigned int unused  : 13;   /**<-- Unused bits                          >*/
}GPIOConfigType;



typedef enum{
  UGPIOINT_TRIGGER_HIGH = 0x0,   /**< The GPIO interrupt will trigger only if the input signal is high */
  UGPIOINT_TRIGGER_LOW,  /**< The GPIO interrupt will trigger only if the input signal is low */
  UGPIOINT_TRIGGER_RISING, /**< The GPIO interrupt will trigger only if the input signal level transitions from low to high */
  UGPIOINT_TRIGGER_FALLING, /**< The GPIO interrupt will trigger only if the input signal level transitions from high to low */
  UGPIOINT_TRIGGER_DUAL_EDGE, /**< The GPIO interrupt will trigger only if the input signal level transitions from high to low or from low to high.*/
  PLACEHOLDER_uGPIOIntTriggerType = 0x7fffffff 
}uGPIOIntTriggerType;
typedef enum 
{
  GPIO_E_OK = 0x0u,
  GPIO_E_NOT_OK = 0x1u,
  GPIO_INIT_FAILED = 0x2u
}eSailGPIOStatus_t;

typedef struct
{
  uint32_t uiGpioNum;
  uGPIOINTISR  pCB;
  uGPIOINTISR  params;
} stGpioDirectIntrCB_type;
extern GPIO_GLOBAL_DATA uint32 sail_gpio_base;
extern GPIO_GLOBAL_DATA  eSailGPIOStatus_t eGpioDirectIntrInitStatus;
/*===========================================================================

                      PUBLIC FUNCTION DECLARATIONS

===========================================================================*/

extern eSailGPIOStatus_t sail_gpio_WritePin(uint32_t uiGPIOn, uint32_t uiValue);
extern GPIOValueType sail_gpio_ReadPin(uint32_t uiGPIOn);

extern GPIOValueType sail_gpio_ReadPinOutput(uint32_t uiGPIOn);

extern eSailGPIOStatus_t sail_gpio_config_pin(uint32 uiGPIOn, GPIOConfigType cfg);

extern void sail_gpio_get_pin_config(uint32 uiGPIOn, GPIOConfigType *pcfg);



extern eSailGPIOStatus_t sail_gpio_config_group( const uint32_t * uiGPIOn,  const GPIOConfigType *cfg, uint32_t nSize);

extern void sail_gpio_init(void);

extern eSailGPIOStatus_t sail_gpio_Deinit(void);

#endif /* SAIL_GPIO_DRIVER_H_ */
