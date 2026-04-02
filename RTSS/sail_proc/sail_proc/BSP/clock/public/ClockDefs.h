#ifndef CLOCKDEFS_H
#define CLOCKDEFS_H
/*
===========================================================================
*/
/**
  @file ClockDefs.h
  @brief Public definitions include file for accessing the clock device driver.
*/
/*===========================================================================
NOTE: The @brief description and any detailed descriptions above do not appear
      in the PDF.

      The Clock_Driver_API_mainpage.dox file contains all file/group
      descriptions that are in the output PDF generated using Doxygen and
      LaTeX. To edit or update any of the file/group text in the PDF, edit the
      Clock_Driver_mainpage.dox file or contact Tech Pubs.

===========================================================================*/
/*
  ===========================================================================

  Copyright (c) 2011-2019 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/public/ClockDefs.h#1 $
  $DateTime: 2025/07/09 22:36:30 $
  $Author: rmunibyr $

  ===========================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "stdint.h"
#include "stdbool.h"
#include "voltage_level.h"


/*=========================================================================
      Macro Definitions
==========================================================================*/

/**
 * Size that should be large enough to store any clock name.
 */
#define CLOCK_MAX_NAME_LEN 128

/*
 * Flags for Clock_EnableEx.
 */
#define CLOCK_ENABLE_FLAG_DONT_WAIT_FOR_CLOCK_ON  0x00000001

/*
 * Flags for Clock_DisableEx.
 */
#define CLOCK_DISABLE_FLAG_WAIT_FOR_CLOCK_OFF     0x00000001


/*=========================================================================
      Type Definitions
==========================================================================*/

/** @addtogroup clock_functions
@{ */

/**
  Handle to clock client.
 */
typedef uintptr_t ClockHandle;


/**
  Clock handle.
 */
typedef uint32_t ClockIdType;


/**
  Clock return values.
 */
typedef enum ClockResult
{
  CLOCK_SUCCESS                         = 0,
  CLOCK_ERROR                           = -1,
  CLOCK_ERROR_INVALID_PARAMETER         = -2,
  CLOCK_ERROR_INSUFFICIENT_MEMORY       = -3,
  CLOCK_ERROR_NOT_FOUND                 = -4,
  CLOCK_ERROR_INTERNAL                  = -5,
  CLOCK_ERROR_NOT_ALLOWED               = -6,
  CLOCK_ERROR_NOT_SUPPORTED             = -7,
  CLOCK_ERROR_NOT_INITIALIZED           = -8,
  CLOCK_ERROR_OUT_OF_RANGE_PARAMETER    = -9,
  CLOCK_ERROR_INVALID_ADDRESS           = -10,
  CLOCK_ERROR_INSUFFICIENT_BUFFER_LEN   = -11,
} ClockResult;

/**
  Callback handle for resource state change.
 */
typedef uint32_t ClockCallbackIdType;

/**
 * Event types supported for resource state change callbacks
 */
typedef enum
{
  CLOCK_CALLBACK_EVENT_PRE_ENABLE,   /* Before a resource is enabled */
  CLOCK_CALLBACK_EVENT_POST_ENABLE,  /* After a resource is enabled */
  CLOCK_CALLBACK_EVENT_PRE_DISABLE,  /* Before a resource is disabled */
  CLOCK_CALLBACK_EVENT_POST_DISABLE, /* After a resource is disabled */
  CLOCK_CALLBACK_EVENT_NUM_TYPES
} ClockCallbackEventType;

typedef void * ClockCallbackData;
typedef void * ClockCallbackCtxt;  /**< Client callback parameter. */
typedef void * (*ClockCallbackFn)(
                 ClockCallbackCtxt, ClockCallbackEventType,
                 ClockIdType, ClockCallbackData); /**< Client callback. */

/**
  Used to search for a matching frequency input. This type describes how
  frequency matching is done for the clock frequency selection function. It
  also indicates units in Hz, kHz, or MHz.
 */
typedef enum : uint32_t
{
  CLOCK_FREQUENCY_HZ_AT_LEAST         = 0x00,  /**< Frequency is the minimum allowed in Hz. */
  CLOCK_FREQUENCY_HZ_AT_MOST          = 0x01,  /**< Frequency is the maximum allowed in Hz. */
  CLOCK_FREQUENCY_HZ_CLOSEST          = 0x02,  /**< Closest match in Hz. */
  CLOCK_FREQUENCY_HZ_EXACT            = 0x03,  /**< Exact match only in Hz. */
  CLOCK_FREQUENCY_HZ_AT_LEAST_OR_MAX  = 0x04,  /**< Frequency is the minimum allowed in Hz, capped to maximum supported frequency. */

  CLOCK_FREQUENCY_KHZ_AT_LEAST        = 0x10,  /**< Frequency is the minimum allowed in kHz. */
  CLOCK_FREQUENCY_KHZ_AT_MOST         = 0x11,  /**< Frequency is the maximum allowed in kHz. */
  CLOCK_FREQUENCY_KHZ_CLOSEST         = 0x12,  /**< Closest match in kHz. */
  CLOCK_FREQUENCY_KHZ_EXACT           = 0x13,  /**< Exact match only in kHz. */
  CLOCK_FREQUENCY_KHZ_AT_LEAST_OR_MAX = 0x14,  /**< Frequency is the minimum allowed in kHz, capped to the maximum supported frequency. */

  CLOCK_FREQUENCY_MHZ_AT_LEAST        = 0x20,  /**< Frequency is the minimum allowed in MHz. */
  CLOCK_FREQUENCY_MHZ_AT_MOST         = 0x21,  /**< Frequency is the maximum allowed in MHz. */
  CLOCK_FREQUENCY_MHZ_CLOSEST         = 0x22,  /**< Closest match in MHz. */
  CLOCK_FREQUENCY_MHZ_EXACT           = 0x23,  /**< Exact match only in MHz. */
  CLOCK_FREQUENCY_MHZ_AT_LEAST_OR_MAX = 0x24,  /**< Frequency is the minimum allowed in MHz, capped to the maximum supported frequency. */
} ClockFrequencyType;


/**
  Type of clock reset. This defines how the reset to the clock domain
  is to be handled.
 */
typedef enum : uint32_t
{
  CLOCK_RESET_DEASSERT = 0,  /**< Deassert the reset signal. */
  CLOCK_RESET_ASSERT   = 1,  /**< Assert and hold the reset signal. */
  CLOCK_RESET_PULSE    = 2   /**< Assert and immediately deassert. */
} ClockResetType;


/**
  Clock queries.
 */
typedef enum
{
  CLOCK_QUERY_NUM_PERF_LEVELS,      /**< Query the number of performance levels. */
  CLOCK_QUERY_PERF_LEVEL_FREQ_HZ,   /**< Query performance level frequency. */
  CLOCK_QUERY_PERF_LEVEL_CORNER,    /**< Query performance level corner. */
  CLOCK_QUERY_PERF_LEVEL_DFS_IDX,   /**< Query performance level DFS index. 0xFF if none. */
  CLOCK_QUERY_PERF_LEVEL_SRC_NAME,  /**< Query performance level source name. */
  CLOCK_QUERY_RAIL_NAME,            /**< Query name of the clock's voltage rail. */
  CLOCK_QUERY_DFS_ENABLED,          /**< Query if DFS is enabled for this clock. */
  CLOCK_QUERY_REF_COUNT,            /**< Query the clock's reference count. */
} ClockQueryType;


/**
  Query result structure.
 */
typedef struct ClockQueryResult
{
  ClockQueryType eType; /**< Query type this result is for. */
  union
  {
    uint32_t            nNumPerfLevels;     /**< CLOCK_QUERY_NUM_PERF_LEVELS */
    uint32_t            nPerfLevelFreqHz;   /**< CLOCK_QUERY_PERF_LEVEL_FREQ_HZ */
    rail_voltage_level  ePerfLevelCorner;   /**< CLOCK_QUERY_PERF_LEVEL_CORNER */
    uint32_t            nPerfLevelDFSIdx;   /**< CLOCK_QUERY_PERF_LEVEL_DFS_IDX */
    char                szPerfLevelSrcName[CLOCK_MAX_NAME_LEN]; /* CLOCK_QUERY_PERF_LEVEL_SRC_NAME */
    char                szRailName[CLOCK_MAX_NAME_LEN];         /* CLOCK_QUERY_RAIL_NAME */
    bool                bDFSEnabled;        /* CLOCK_QUERY_DFS_ENABLED */
    uint32_t            nRefCount;          /* CLOCK_QUERY_REF_COUNT */
  } Data;
} ClockQueryResultType;


/**
 * Clock QDSS levels used for the /clk/qdss NPA resource.
 */
typedef enum
{
  CLOCK_QDSS_LEVEL_OFF,      /**< Clock rate set to CXO and disabled. */
  CLOCK_QDSS_LEVEL_DEBUG,    /**< Clock rate follows VDD_CX. */
  CLOCK_QDSS_LEVEL_HSDEBUG,  /**< Clock rate set to high speed. */
} ClockQDSSLevelType;


/**
  Type of clock configuration.  This type describes how a clock is
  configured.
 */
typedef enum
{
  CLOCK_CONFIG_HW_CTL_ON                  = 0, /**< Enable HW control */
  CLOCK_CONFIG_HW_CTL_OFF                 = 1, /**< Disable HW control. */
  CLOCK_CONFIG_MEM_CORE_FORCE_ON          = 2, /**< Force core memories on. */
  CLOCK_CONFIG_MEM_CORE_DONT_FORCE_ON     = 3, /**< Don't force core memories on. */
  CLOCK_CONFIG_MEM_PERIPH_FORCE_ON        = 4, /**< Force peripheral memories on. */
  CLOCK_CONFIG_MEM_PERIPH_DONT_FORCE_ON   = 5, /**< Don't force peripheral memories on. */
  CLOCK_CONFIG_MEM_PERIPH_FORCE_OFF       = 6, /**< Force peripheral memories off. */
  CLOCK_CONFIG_MEM_PERIPH_DONT_FORCE_OFF  = 7, /**< Don't force peripheral memories off. */
  CLOCK_CONFIG_DFS_ENABLE                 = 8, /**< Enable DFS control. */

  /** @cond
  */
  CLOCK_CONFIG_TOTAL
  /** @endcond */
} ClockConfigType;


/** @} */ /* end_addtogroup clock_functions */

/** @addtogroup misc_functions
@{ */

/**
  Processor Sleep mode. This type defines the different kinds of sleep modes
  that can be entered.
 */
typedef enum
{
  CLOCK_SLEEP_MODE_HALT,            /**< Processor halt only. */
  CLOCK_SLEEP_MODE_POWER_COLLAPSE   /**< Processor power collapse. */
} ClockSleepModeType;


/**
 Processor Sleep mode flag masks:
  RAMP_DOWN_CPU
   Triggers frequency switching to a lower performance level before SWFI.

  L2CACHE_FLUSH
   Flushes the contents of L2 cache when entering power collapse.

  RAMP_DOWN_L2CACHE
   In some cases, the L2 cache frequency needs to be lowered with the CPU
   frequency. In other cases, the L2 cache frequency needs to remain untouched.
   This is when the RAMP_DOWN_L2CACHE flag becomes useful.

  PLL_OFF
   Configures the PLL to a state where it is ready for the SPM to power it off.
   It also preloads any configuration registers necessary such that it is ready
   to be used once the SPM powers it back on.
 */
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_CPU          0x00000001
#define CLOCK_SLEEP_FLAG_L2CACHE_FLUSH          0x00000002
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_L2CACHE      0x00000004
#define CLOCK_SLEEP_FLAG_PLL_OFF                0x00000008


/** @} */ /* end_addtogroup npa_functions*/

/*
 * ClockFreqPlanType
 *
 * Structure to hold a frequency plan entry.
 */
typedef struct ClockFreqPlanType
{
  uint32_t            nFreqHz;    /* Clock frequency in Hz */
  rail_voltage_level  eVRegLevel; /* Voltage corner requirement. */
} ClockFreqPlanType;


#endif /* !CLOCKDEFS_H */

