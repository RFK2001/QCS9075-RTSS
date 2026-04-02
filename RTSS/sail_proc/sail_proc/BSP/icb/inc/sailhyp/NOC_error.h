#ifndef   NOC_ERROR_H
#define   NOC_ERROR_H
/*============================================================================

FILE:      NOC_Error.h

DESCRIPTION: APIs and data structure declarations 
             for NOC Error Handler

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A
 
Edit History

When        Who    What, where, why
----------  ---    ----------------------------------------------------------- 
    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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
============================================================================*/
#include "types.h"
#include "stdint.h"
#include "stdbool.h"
#include "chipinfo.h"

/*============================================================================
                          DEFINEs/MACROs
============================================================================*/
/* Reserved value of offset that indicates that the register does not apply to
 * this version of hardware
 */
#define REGISTER_NOT_APPLICABLE 0xFFFFU

/* Reserved value of interrupt vector that indicates that the no interrupt
 * registration is desired
 */
#define NO_INTERRUPT UINTPTR_MAX

#define        ICB_SAIL_CFG_EN              1
#define        ICB_SAIL_CFG_DIS             0

#define        ICB_SAIL_LEMANSAU_R2         0
#define        ICB_SAIL_NOC_POS_CFG         ICB_SAIL_CFG_DIS
#define        ICB_SAIL_NOC_POC_CFG         ICB_SAIL_CFG_DIS
#define        ICB_SAIL_NOC_TIMEOUT_CFG     ICB_SAIL_CFG_DIS

extern ChipInfoVersionType ICB_LeManSailVersion_el2 ;
extern ChipInfoFamilyType ICB_SailFamily_el2 ;

#define ICB_LEMANS_SAIL_R1_VERSION          0x00010000u /* 16bit Major - 16bit Minor version */
#define ICB_LEMANS_SAIL_R2_VERSION          0x00020000u /* 16bit Major - 16bit Minor version */

/*============================================================================
                          TYPE DEFINITION
============================================================================*/
/**
 * NOC Error logger Register Interface
 */
typedef struct
{
   uint32_t swid_low;
   uint32_t swid_high;
   uint32_t main_ctl_low;
   uint32_t err_valid_low;
   uint32_t err_clear_low;
   uint32_t errlog0_low;
   uint32_t errlog0_high;
   uint32_t errlog1_low;
   uint32_t errlog1_high;
   uint32_t errlog2_low;
   uint32_t errlog2_high;
   uint32_t errlog3_low;
   uint32_t errlog3_high;
   /* Additional fields for gladiator NoC errors. */
   uint32_t errlog2_1_low;
   uint32_t errlog2_1_high;
   uint32_t errlog4_3_low;
   uint32_t errlog4_3_high;
   uint32_t errlog6_5_low;
   uint32_t errlog6_5_high;
   uint32_t errlog8_high;
   /* New fields for new NoC versions go here */
} NOC_errlog_hw_type;

/*
 * NOC SidebandManager with faultin Register Interface
 */
typedef struct
{
   uint32_t swid_low;
   uint32_t swid_high;
   uint32_t faultin_en0_low;
   uint32_t faultin_en0_high;
   uint32_t faultin_status0_low;
   uint32_t faultin_status0_high;
   uint32_t faultin_en1_low;
   uint32_t faultin_en1_high;
   uint32_t faultin_status1_low;
   uint32_t faultin_status1_high;
   uint32_t flagout_clr0_low;
   uint32_t flagout_clr0_high;
   uint32_t flagout_set0_low;
   uint32_t flagout_set0_high;
   uint32_t flagout_status0_low;
   uint32_t flagout_status0_high;
   uint32_t sensein0_low;
   uint32_t sensein0_high;
   /* New fields for new NoC SidebandManager versions go here */
} NOC_sideband_hw_type;

/*
 * NOC Point-Of-Serialization Register Interface
 */
typedef struct
{
   uint32_t swid_low;
   uint32_t swid_high;
   uint32_t errlog_low;
   uint32_t errlog_high;
   uint32_t errlogclr_low;
   /* New fields for new NoC PoS versions go here */
} NOC_pos_hw_type;

/*
 * NOC Point-Of-Coherency Register Interface
 */
typedef struct
{
   uint32_t swid_low;
   uint32_t swid_high;
   uint32_t errset_low;
   uint32_t errstatus_low;
   uint32_t errack_low;
   uint32_t errlogmain_low;
   uint32_t errlogmain_high;
   uint32_t errlogaddr_low;
   uint32_t errlogaddr_high;
   uint32_t errloguser_low;
   uint32_t errloguser_high;
   /* New fields for new NoC PoC versions go here */
} NOC_poc_hw_type;

/**
 * NOC Error Syndrome Register Data Types
 */
typedef struct
{
  uint32_t FAULTINSTATUS0_LOW;
  uint32_t FAULTINSTATUS0_HIGH;
  uint32_t FAULTINSTATUS1_LOW;
  uint32_t FAULTINSTATUS1_HIGH;
} NOCERR_sbm_syndrome_type;

typedef struct
{
  uint32_t ERRLOG_LOW;
  uint32_t ERRLOG_HIGH;
} NOCERR_pos_syndrome_type;

typedef struct
{
  uint32_t ERRLOGSTATUS_LOW;
  uint32_t ERRLOGMAIN_LOW;
  uint32_t ERRLOGMAIN_HIGH;
  uint32_t ERRLOGADDR_LOW;
  uint32_t ERRLOGADDR_HIGH;
  uint32_t ERRLOGUSER_LOW;
  uint32_t ERRLOGUSER_HIGH;
} NOCERR_poc_syndrome_type;

/**
 * Safety Manager Register Data Types
 */
typedef struct
{
  uint32_t STATUS_LOW;
  uint32_t CFLTA_LOW;
  uint32_t CFLTA_HIGH;
  uint32_t UFLTA_LOW;
  uint32_t UFLTA_HIGH;
  uint32_t CFLTB_LOW;
  uint32_t CFLTB_HIGH;
  uint32_t UFLTB_LOW;
  uint32_t UFLTB_HIGH;
} NOCERR_sfty_ctl_syndrome_type;

typedef struct
{
  uint32_t STATUS_LOW;
  uint32_t CCNT_LOW;
  uint32_t UCNT_LOW;
} NOCERR_sfty_agg_syndrome_type;

typedef struct
{
  uint32_t ERRLOG0_LOW;
  uint32_t ERRLOG0_HIGH;
  uint32_t ERRLOG1_LOW;
  uint32_t ERRLOG1_HIGH;
  uint32_t ERRLOG2_LOW;
  uint32_t ERRLOG2_HIGH;
  uint32_t ERRLOG3_LOW;
  uint32_t ERRLOG3_HIGH;
  uint32_t ERRLOG2_1_LOW;
  uint32_t ERRLOG2_1_HIGH;
  uint32_t ERRLOG4_3_LOW;
  uint32_t ERRLOG4_3_HIGH;
  uint32_t ERRLOG6_5_LOW;
  uint32_t ERRLOG6_5_HIGH;
  uint32_t ERRLOG8_HIGH;
  NOCERR_sbm_syndrome_type *sbms;
  NOCERR_pos_syndrome_type *pos;
  NOCERR_poc_syndrome_type *poc;
  NOCERR_sfty_ctl_syndrome_type *sfty_ctl;
  NOCERR_sfty_agg_syndrome_type *sfty_agg;
} NOCERR_syndrome_type;

/**
 * Safety Manager Register Interface
 */


typedef struct
{
  uint32_t swid_low;
  uint32_t swid_high;
  uint32_t bistctl_low;
  uint32_t status_low;
  uint32_t outen_low;
  uint32_t cflta_low;
  uint32_t cflta_high;
  uint32_t uflta_low;
  uint32_t uflta_high;
  uint32_t cfltb_low;
  uint32_t cfltb_high;
  uint32_t ufltb_low;
  uint32_t ufltb_high;
} NOC_sfty_ctl_hw_type;

typedef struct
{
  uint32_t swid_low;
  uint32_t swid_high;
  uint32_t mainctl_low;
  uint32_t status_low;
  uint32_t ccnt_low;
  uint32_t ucnt_low;
} NOC_sfty_agg_hw_type;

typedef struct 
{
  void*                 addr;      /**< NOC SFTY_CTL base addresses */
  NOC_sfty_agg_hw_type *hw;        /**< NOC SFTY_CTL register offsets */
  uint32_t              aggregid;  /**< NOC SFTY_CTL AggregID for BIST */
} NOC_sfty_agg_type;
  
/**
 * Internal NOC error Info data type
 */
typedef struct
{
  char*                  name;            /**< NOC name */
  NOC_errlog_hw_type    *erl_hw;          /**< NOC error logger register offsets */
  uint32_t              *erl_base_addr;   /**< NOC error logger base address */
  uintptr_t              intr_vector[3];  /**< NOC interrupt vector */
  uint32_t               num_sbms;        /**< Number of NoC sideband managers */
  NOC_sideband_hw_type **sb_hw;           /**< NOC sideband register offsets */
  void**                 sb_base_addrs;   /**< NOC sideband base addresses */
  uint32_t               num_tos;         /**< Number of timeout enable registers */
  void**                 to_addrs;        /**< NOC timeout enable registers */
  NOCERR_syndrome_type   syndrome;        /**< Error syndrome */
  uint32_t               num_pos;         /**< Number of PoS blocks. */
  NOC_pos_hw_type      **pos_hw;          /**< NOC PoS register offsets */
  void**                 pos_base_addrs;  /**< NOC PoS base addresses */
  uint32_t               num_poc;         /**< Number of PoC blocks. */
  NOC_poc_hw_type      **poc_hw;          /**< NOC PoC register offsets */
  void**                 poc_base_addrs;  /**< NOC PoC base addresses */
  uint32_t               num_sfty_ctl;    /**< Number of safety controllers */
  NOC_sfty_ctl_hw_type **sfty_ctl_hw;     /**< NOC SFTY_CTL register offsets */
  void**                 sfty_ctl_addrs;  /**< NOC SFTY_CTL base addresses */
  uint32_t              *num_sfty_aggs;   /**< Number of safety aggregators per ctl */
  NOC_sfty_agg_type    **sfty_aggs;       /**< NOC SFT_CTL aggregators per ctl*/
} NOCERR_info_type;

/**
 * OEM NOC error Info data type
 */
typedef struct
{
  uint32_t faultin_en0_low;
  uint32_t faultin_en0_high;
  uint32_t faultin_en1_low;
  uint32_t faultin_en1_high;
} NOCERR_sbm_info_type_oem;

typedef struct
{
  bool enable;
} NOCERR_pos_info_type_oem;

typedef struct
{
  uint32_t outen_low;
} NOCERR_sfty_ctl_info_type_oem;

typedef struct
{
  char*                          name;         /**< NOC name */
  bool                           intr_enable;  /**< NOC errorlogger interrupt enable */
  bool                           error_fatal;  /**< NOC interrupt error fatal */ 
  NOCERR_sbm_info_type_oem *     sbms;         /**< NOC sideband manager cfgs */
  NOCERR_sbm_info_type_oem *     obs_mask;     /**< NOC sideband manager for obs cfg */
  uint32_t *                     to_reg_vals;  /**< NOC timeout enable register values */
  NOCERR_pos_info_type_oem *     pos;          /**< NOC PoS enables. */
  NOCERR_pos_info_type_oem *     poc;          /**< NOC PoC enables. */
  NOCERR_sfty_ctl_info_type_oem *sfty_ctl;     /**< NOC Safety controller config */
} NOCERR_info_type_oem;


typedef struct
{
  /* Chip version information for this device data. */
  ChipInfoFamilyType   family;
  bool                 match;
  ChipInfoVersionType  version;

  /* Associated target data */
  uint32_t          len;             /**< Length of cfgdata array */
  NOCERR_info_type* NOCInfo;         /**< Pointer to internal cfgdata array*/
  uint32_t          num_clock_regs;  /**< Number of external timeout clock regs */
  void**            clock_reg_addrs; /**< External timeout clock regs */
} NOCERR_propdata_type;

typedef struct
{
  uint32_t              num_configs;
  NOCERR_propdata_type *configs;
} NOCERR_config_info_type;

/**
 * NOC Error OEM Property Data type
 */
typedef struct
{
  /* Chip version information for this device data. */
  ChipInfoFamilyType   family;
  bool                 match;
  ChipInfoVersionType  version;

  /* Associated target data */
  uint32_t              len;            /**< Length of cfgdata array */
  NOCERR_info_type_oem* NOCInfoOEM;     /**< Pointer to OEM cfgdata array*/
  uint32_t *            clock_reg_vals; /**< NOC timeout external register values */
} NOCERR_propdata_type_oem;

typedef struct
{
  uint32_t                  num_configs;
  NOCERR_propdata_type_oem *configs;
} NOCERR_config_info_type_oem;

/*============================================================================
                        NOC HW Register DEFINITIONS 
============================================================================*/
/* NOC Error Logger HW Register Offsets Version 4.0 */
/* Use ERRLOG_SWID_LOW as base address. */
static NOC_errlog_hw_type QNOC_4_0 = {
  .swid_low       = 0x0,
  .swid_high      = 0x4,
  .main_ctl_low   = 0x8,
  .err_valid_low  = 0x10,
  .err_clear_low  = 0x18,
  .errlog0_low    = 0x20,
  .errlog0_high   = 0x24,
  .errlog1_low    = 0x28,
  .errlog1_high   = 0x2C,
  .errlog2_low    = 0x30,
  .errlog2_high   = 0x34,
  .errlog3_low    = 0x38,
  .errlog3_high   = 0x3C,
  .errlog2_1_low  = REGISTER_NOT_APPLICABLE,
  .errlog2_1_high = REGISTER_NOT_APPLICABLE,
  .errlog4_3_low  = REGISTER_NOT_APPLICABLE,
  .errlog4_3_high = REGISTER_NOT_APPLICABLE,
  .errlog6_5_low  = REGISTER_NOT_APPLICABLE,
  .errlog6_5_high = REGISTER_NOT_APPLICABLE,
  .errlog8_high   = REGISTER_NOT_APPLICABLE,
};

/* NOC HW Register Offsets Gladiator Version */
/* Use ERRORVLD_LOW as base address. */
static NOC_errlog_hw_type GLADIATOR_0_0 = {
  .swid_low       = REGISTER_NOT_APPLICABLE,
  .swid_high      = REGISTER_NOT_APPLICABLE,
  .main_ctl_low   = 0x0,  /**< gladiator errvld_low */
  .err_valid_low  = 0x4,  /**< gladiator errvld_high */
  .err_clear_low  = 0x8,  /**< gladiator errlog0_low */
  .errlog0_low    = REGISTER_NOT_APPLICABLE,
  .errlog0_high   = 0xC,
  .errlog1_low    = REGISTER_NOT_APPLICABLE,
  .errlog1_high   = REGISTER_NOT_APPLICABLE,
  .errlog2_low    = REGISTER_NOT_APPLICABLE,
  .errlog2_high   = REGISTER_NOT_APPLICABLE,
  .errlog3_low    = REGISTER_NOT_APPLICABLE,
  .errlog3_high   = REGISTER_NOT_APPLICABLE,
  .errlog2_1_low  = 0x10,
  .errlog2_1_high = 0x14,
  .errlog4_3_low  = 0x18,
  .errlog4_3_high = 0x1C,
  .errlog6_5_low  = 0x20,
  .errlog6_5_high = 0x24,
  .errlog8_high   = 0x2C,
};

/* NOC SidebandManager HW Register Offsets */
static NOC_sideband_hw_type QNOC_SB_4_0_L = {
  .swid_low             = 0x0,
  .swid_high            = 0x4,
  .faultin_en0_low      = 0x40,
  .faultin_en0_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status0_low  = 0x48,
  .faultin_status0_high = REGISTER_NOT_APPLICABLE,
  .faultin_en1_low      = REGISTER_NOT_APPLICABLE,
  .faultin_en1_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status1_low  = REGISTER_NOT_APPLICABLE,
  .faultin_status1_high = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_low     = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_set0_low     = REGISTER_NOT_APPLICABLE,
  .flagout_set0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_status0_low  = REGISTER_NOT_APPLICABLE,
  .flagout_status0_high = REGISTER_NOT_APPLICABLE,
  .sensein0_low         = REGISTER_NOT_APPLICABLE,
  .sensein0_high        = REGISTER_NOT_APPLICABLE,
};

static NOC_sideband_hw_type QNOC_SB_4_0 = {
  .swid_low             = 0x0,
  .swid_high            = 0x4,
  .faultin_en0_low      = 0x40,
  .faultin_en0_high     = 0x44,
  .faultin_status0_low  = 0x48,
  .faultin_status0_high = 0x4C,
  .faultin_en1_low      = REGISTER_NOT_APPLICABLE,
  .faultin_en1_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status1_low  = REGISTER_NOT_APPLICABLE,
  .faultin_status1_high = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_low     = 0x80,
  .flagout_clr0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_set0_low     = 0x88,
  .flagout_set0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_status0_low  = 0x90,
  .flagout_status0_high = REGISTER_NOT_APPLICABLE,
  .sensein0_low         = 0x100,
  .sensein0_high        = REGISTER_NOT_APPLICABLE,
};

static NOC_sideband_hw_type QNOC_SB_4_0_IOS_L= {
  .swid_low             = 0x0,
  .swid_high            = 0x4,
  .faultin_en0_low      = 0x40,
  .faultin_en0_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status0_low  = 0x48,
  .faultin_status0_high = REGISTER_NOT_APPLICABLE,
  .faultin_en1_low      = REGISTER_NOT_APPLICABLE,
  .faultin_en1_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status1_low  = REGISTER_NOT_APPLICABLE,
  .faultin_status1_high = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_low     = 0x80,
  .flagout_clr0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_set0_low     = 0x88,
  .flagout_set0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_status0_low  = 0x90,
  .flagout_status0_high = REGISTER_NOT_APPLICABLE,
  .sensein0_low         = 0x100,
  .sensein0_high        = REGISTER_NOT_APPLICABLE,
};

static NOC_sideband_hw_type QNOC_SB_4_0_IO_L= {
  .swid_low             = 0x0,
  .swid_high            = 0x4,
  .faultin_en0_low      = 0x40,
  .faultin_en0_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status0_low  = 0x48,
  .faultin_status0_high = REGISTER_NOT_APPLICABLE,
  .faultin_en1_low      = REGISTER_NOT_APPLICABLE,
  .faultin_en1_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status1_low  = REGISTER_NOT_APPLICABLE,
  .faultin_status1_high = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_low     = 0x80,
  .flagout_clr0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_set0_low     = 0x88,
  .flagout_set0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_status0_low  = 0x90,
  .flagout_status0_high = REGISTER_NOT_APPLICABLE,
  .sensein0_low         = REGISTER_NOT_APPLICABLE,
  .sensein0_high        = REGISTER_NOT_APPLICABLE,
};

static NOC_sideband_hw_type QNOC_SB_4_0_OS_L= {
  .swid_low             = 0x0,
  .swid_high            = 0x4,
  .faultin_en0_low      = REGISTER_NOT_APPLICABLE,
  .faultin_en0_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status0_low  = REGISTER_NOT_APPLICABLE,
  .faultin_status0_high = REGISTER_NOT_APPLICABLE,
  .faultin_en1_low      = REGISTER_NOT_APPLICABLE,
  .faultin_en1_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status1_low  = REGISTER_NOT_APPLICABLE,
  .faultin_status1_high = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_low     = 0x80,
  .flagout_clr0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_set0_low     = 0x88,
  .flagout_set0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_status0_low  = 0x90,
  .flagout_status0_high = REGISTER_NOT_APPLICABLE,
  .sensein0_low         = REGISTER_NOT_APPLICABLE,
  .sensein0_high        = REGISTER_NOT_APPLICABLE,
};

static NOC_sideband_hw_type QNOC_SB_4_0_2L = {
  .swid_low             = 0x0,
  .swid_high            = 0x4,
  .faultin_en0_low      = 0x40,
  .faultin_en0_high     = 0x44,
  .faultin_status0_low  = 0x48,
  .faultin_status0_high = 0x4C,
  .faultin_en1_low      = 0x50,
  .faultin_en1_high     = REGISTER_NOT_APPLICABLE,
  .faultin_status1_low  = 0x58,
  .faultin_status1_high = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_low     = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_set0_low     = REGISTER_NOT_APPLICABLE,
  .flagout_set0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_status0_low  = REGISTER_NOT_APPLICABLE,
  .flagout_status0_high = REGISTER_NOT_APPLICABLE,
  .sensein0_low         = REGISTER_NOT_APPLICABLE,
  .sensein0_high        = REGISTER_NOT_APPLICABLE,
};

static NOC_sideband_hw_type QNOC_SB_4_0_2 = {
  .swid_low             = 0x0,
  .swid_high            = 0x4,
  .faultin_en0_low      = 0x40,
  .faultin_en0_high     = 0x44,
  .faultin_status0_low  = 0x48,
  .faultin_status0_high = 0x4C,
  .faultin_en1_low      = 0x50,
  .faultin_en1_high     = 0x54,
  .faultin_status1_low  = 0x58,
  .faultin_status1_high = 0x5C,
  .flagout_clr0_low     = REGISTER_NOT_APPLICABLE,
  .flagout_clr0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_set0_low     = REGISTER_NOT_APPLICABLE,
  .flagout_set0_high    = REGISTER_NOT_APPLICABLE,
  .flagout_status0_low  = REGISTER_NOT_APPLICABLE,
  .flagout_status0_high = REGISTER_NOT_APPLICABLE,
  .sensein0_low         = REGISTER_NOT_APPLICABLE,
  .sensein0_high        = REGISTER_NOT_APPLICABLE,
};

static NOC_pos_hw_type QNOC_POS_4_0 = {
  .swid_low      = 0x0,
  .swid_high     = 0x4,
  .errlog_low    = 0x8,
  .errlog_high   = 0xC,
  .errlogclr_low = 0x10,
};

static NOC_poc_hw_type QNOC_POC_1_0 = {
  .swid_low        = 0x00,
  .swid_high       = 0x04,
  .errset_low      = 0x08,
  .errstatus_low   = 0x10,
  .errack_low      = 0x18,
  .errlogmain_low  = 0x20,
  .errlogmain_high = 0x24,
  .errlogaddr_low  = 0x28,
  .errlogaddr_high = 0x2C,
  .errloguser_low  = 0x30,
  .errloguser_high = 0x34,
};

/* NOC Safety Manager HW Register Offsets */
static NOC_sfty_ctl_hw_type QNOC_SFTY_CTL_1_0 = {
  .swid_low    = 0x00,
  .swid_high   = 0x04,
  .bistctl_low = 0x08,
  .status_low  = 0x10,
  .outen_low   = 0x18,
  .cflta_low   = 0x20,
  .cflta_high  = 0x24,
  .uflta_low   = 0x28,
  .uflta_high  = 0x2C,
  .cfltb_low   = REGISTER_NOT_APPLICABLE,
  .cfltb_high  = REGISTER_NOT_APPLICABLE,
  .ufltb_low   = REGISTER_NOT_APPLICABLE,
  .ufltb_high  = REGISTER_NOT_APPLICABLE,
};

static NOC_sfty_ctl_hw_type QNOC_SFTY_CTL_1_0_B = {
  .swid_low    = 0x00,
  .swid_high   = 0x04,
  .bistctl_low = 0x08,
  .status_low  = 0x10,
  .outen_low   = 0x18,
  .cflta_low   = 0x20,
  .cflta_high  = 0x24,
  .uflta_low   = 0x28,
  .uflta_high  = 0x2C,
  .cfltb_low   = 0x30,
  .cfltb_high  = 0x34,
  .ufltb_low   = 0x38,
  .ufltb_high  = 0x3C,
};

static NOC_sfty_ctl_hw_type QNOC_SFTY_CTL_1_0_L = {
  .swid_low    = 0x00,
  .swid_high   = 0x04,
  .bistctl_low = 0x08,
  .status_low  = 0x10,
  .outen_low   = 0x18,
  .cflta_low   = 0x20,
  .cflta_high  = REGISTER_NOT_APPLICABLE,
  .uflta_low   = 0x28,
  .uflta_high  = REGISTER_NOT_APPLICABLE,
  .cfltb_low   = REGISTER_NOT_APPLICABLE,
  .cfltb_high  = REGISTER_NOT_APPLICABLE,
  .ufltb_low   = REGISTER_NOT_APPLICABLE,
  .ufltb_high  = REGISTER_NOT_APPLICABLE,
};

static NOC_sfty_agg_hw_type QNOC_SFTY_AGG_1_0 = {
  .swid_low    = 0x00,
  .swid_high   = 0x04,
  .mainctl_low = 0x08,
  .status_low  = 0x10,
  .ccnt_low    = 0x18,
  .ucnt_low    = 0x20,
};

static NOC_sfty_agg_hw_type QNOC_SFTY_AGG_1_0_XC = {
  .swid_low    = 0x00,
  .swid_high   = 0x04,
  .mainctl_low = 0x08,
  .status_low  = 0x10,
  .ccnt_low    = REGISTER_NOT_APPLICABLE,
  .ucnt_low    = 0x20,
};

typedef struct{
	uint32_t NOC_ID; /* 0: ASIL-D, 1: ASIL-B, 2:ASIL-D ISO, 3: ASIL: B ISO*/
	uint32_t ERRLOG0_LOW;
	uint32_t ERRLOG0_HIGH;
	uint32_t ERRLOG1_LOW;
	uint32_t ERRLOG1_HIGH;
	uint32_t ERRLOG2_LOW;
	uint32_t ERRLOG2_HIGH;
	uint32_t ERRLOG3_LOW;
	uint32_t ERRLOG3_HIGH;
	uint32_t FAULTINSTATUS0_LOW;
	uint32_t FAULTINSTATUS0_HIGH;
	uint32_t FAULTINSTATUS1_LOW;
	uint32_t FAULTINSTATUS1_HIGH;
	uint32_t FAULTINSTATUS0_LOW_2;
	uint32_t FAULTINSTATUS0_HIGH_2;
	uint32_t FAULTINSTATUS1_LOW_2;
	uint32_t FAULTINSTATUS1_HIGH_2;
	uint32_t STATUS_LOW;
	uint32_t CFLTA_LOW;
	uint32_t CFLTA_HIGH;
	uint32_t UFLTA_LOW;
	uint32_t UFLTA_HIGH;
	uint32_t CFLTB_LOW;
	uint32_t CFLTB_HIGH;
	uint32_t UFLTB_LOW;
	uint32_t UFLTB_HIGH;
}ICB_SailNocErrorLogToFuSa_type;

typedef struct
{
	uint32_t magicNumber;
	uint32_t reserved;
	ICB_SailNocErrorLogToFuSa_type nocErrVal; 
}NOCERRORrecordType;

/*============================================================================
                                 FUNCTIONS
============================================================================*/

//*============================================================================*/
/**
@brief 
      Gets internal platfrom specific property data structure for configuration.
 
@param[in]  None.

@return    
      NOCERR_propdata_type* Pointer to internal property data structure.

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/
NOCERR_propdata_type* NOC_ErrPltfrmGetPrgmData(void);

//*============================================================================*/
/**
@brief 
      Gets OEM platfrom specific property data structure for configuration.
 
@param[in]  None.

@return    
      NOCERR_propdata_type_oem* Pointer to OEM property data structure.

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/
NOCERR_propdata_type_oem* NOC_ErrPltfrmGetPrgmData_OEM(void);

//*============================================================================*/
/**
@brief 
      Gets internal platfrom specific property data structure for configuration.
 
@param[in]  None.

@return    
      NOCERR_propdata_type* Pointer to internal property data structure.

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/
NOCERR_config_info_type*  NOC_Error_Platform_Get_Data(void);

//*============================================================================*/
/**
@brief 
      Gets OEM platfrom specific property data structure for configuration.
 
@param[in]  None.

@return    
      NOCERR_propdata_type_oem* Pointer to OEM property data structure.

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/

NOCERR_config_info_type_oem*  NOC_ErrPltfrmGetData_OEM(void);

//*============================================================================*/
/**
@brief 
      Performs initialization for NOC error handler.
      It enables interrupts required to handle NOC errors.
 
@param[in]  None.

@return    
      None.

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/
void NOC_Error_Init(void);

//*============================================================================*/
/**
@brief 
      Performs target specific initialization for NOC error handler.
 
@param[in]  None.

@return    
      None.

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/
void NOC_Error_Init_Target
(
  NOCERR_info_type *    noc_info,
  uint32_t              noc_cnt,
  NOCERR_info_type_oem* noc_info_oem
);

//*============================================================================*/
/**
@brief 
      Performs any target specific error action.
 
@param[in]    noc_info     - NoC info structure
@param[in]    noc_info_oem - NoC OEM info structure
@param[inout] delay_crash  - If fatal, delay crash?

@return    
      true if error is fatal, false otherwise

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/
bool NOC_Error_Handle_Target
(
  NOCERR_info_type *    noc_info, 
  NOCERR_info_type_oem *noc_info_oem,
  bool                 *delay_crash 
);

extern NOCERR_info_type NOCERR_cfgdata_R2[4];
extern NOCERR_info_type NOCERR_cfgdata_R1[4];
extern NOCERR_info_type_oem NOCERR_cfgdata_oem_R1[4];
extern NOCERR_info_type_oem NOCERR_cfgdata_oem_R2[4];
extern NOCERR_config_info_type NOCERR_propdata_MONACOAU;
extern NOCERR_config_info_type NOCERR_propdata_R1;
extern NOCERR_config_info_type NOCERR_propdata_R2;
extern NOCERR_config_info_type_oem NOCERR_propdata_oem_MONACOAU;
extern NOCERR_config_info_type_oem NOCERR_propdata_oem_R2 ;
extern NOCERR_config_info_type_oem NOCERR_propdata_oem_R1;
extern uint32_t clock_reg_vals_R2[3];
extern uint32_t clock_reg_vals_R1[3];
extern void sailbsp_early_noc_config(void);
#endif /* __NOC_ERROR_H__ */
