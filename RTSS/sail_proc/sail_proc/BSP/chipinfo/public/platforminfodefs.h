#ifndef PLATFORMINFODEFS_H
#define PLATFORMINFODEFS_H

/**
  @file PlatformInfo.h

  Public definitions for the PlatformInfo driver.
*/
/*
  ====================================================================

  Copyright (c) 2021-2025 Qualcomm Technologies, Incorporated.
  All Rights Reserved.
  Qualcomm Technologies, Confidential and Proprietary.

  ====================================================================


  ====================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/
#include <stdint.h>
#include <stdbool.h>


/*=========================================================================
      Type Definitions
==========================================================================*/

/**
  @addtogroup platform_info
  @{
*/

/**
 * Generate a platform version number.
 *
 * This macro generates the platform version number from the specified
 * major and minor numbers. For example, version 1.2 is represented by
 * @code DALPLATORMINFO_VERSION(1,2) @endcode
 *
*/
#define PLATFORMINFO_VERSION(major, minor)  (((major) << 16) | (minor))


/**
  Target type of the device on which the platform is running.
 */
typedef enum
{
  PLATFORMINFO_TYPE_UNKNOWN      = 0x00,  /**< Unknown target device. */
  PLATFORMINFO_TYPE_SURF         = 0x01,  /**< Target is a SURF device. */
  PLATFORMINFO_TYPE_CDP          = PLATFORMINFO_TYPE_SURF, /**< Target is a CDP (aka SURF) device. */
  PLATFORMINFO_TYPE_FFA          = 0x02,  /**< Target is an FFA device. */
  PLATFORMINFO_TYPE_FLUID        = 0x03,  /**< Target is a FLUID device. */
  PLATFORMINFO_TYPE_FUSION       = 0x04,  /**< Target is a FUSION device. */
  PLATFORMINFO_TYPE_OEM          = 0x05,  /**< Target is an OEM device. */
  PLATFORMINFO_TYPE_QT           = 0x06,  /**< Target is a QT device. */
  PLATFORMINFO_TYPE_MTP          = 0x08,  /**< Target is a MTP device. */
  PLATFORMINFO_TYPE_MTP_MDM      = PLATFORMINFO_TYPE_MTP, /**< Target is a MDM MTP device. */
  PLATFORMINFO_TYPE_MTP_MSM      = PLATFORMINFO_TYPE_MTP, /**< Target is a MSM MTP device. */
  PLATFORMINFO_TYPE_LIQUID       = 0x09,  /**< Target is a LiQUID device. */
  PLATFORMINFO_TYPE_DRAGONBOARD  = 0x0A,  /**< Target is a DragonBoard device. */
  PLATFORMINFO_TYPE_QRD          = 0x0B,  /**< Target is a QRD device. */
  PLATFORMINFO_TYPE_EVB          = 0x0C,  /**< Target is an EVB device. */
  PLATFORMINFO_TYPE_HRD          = 0x0D,  /**< Target is a HRD device. */
  PLATFORMINFO_TYPE_DTV          = 0x0E,  /**< Target is a DTV device. */
  PLATFORMINFO_TYPE_RUMI         = 0x0F,  /**< Target is on RUMI. */
  PLATFORMINFO_TYPE_VIRTIO       = 0x10,  /**< Target is on VIRTIO. */
  PLATFORMINFO_TYPE_GOBI         = 0x11,  /**< Target is a GOBI device. */
  PLATFORMINFO_TYPE_CBH          = 0x12,  /**< Target is a CBH device. */
  PLATFORMINFO_TYPE_BTS          = 0x13,  /**< Target is a BTS device. */
  PLATFORMINFO_TYPE_XPM          = 0x14,  /**< Target is a XPM device. */
  PLATFORMINFO_TYPE_RCM          = 0x15,  /**< Target is a RCM device. */
  PLATFORMINFO_TYPE_DMA          = 0x16,  /**< Target is a DMA device. */
  PLATFORMINFO_TYPE_STP          = 0x17,  /**< Target is a STP device. */
  PLATFORMINFO_TYPE_SBC          = 0x18,  /**< Target is a SBC device. */
  PLATFORMINFO_TYPE_ADP          = 0x19,  /**< Target is a ADP device. */
  PLATFORMINFO_TYPE_CHI          = 0x1A,  /**< Target is a CHI device. */
  PLATFORMINFO_TYPE_SDP          = 0x1B,  /**< Target is a SDP device. */
  PLATFORMINFO_TYPE_RRP          = 0x1C,  /**< Target is a RRP device. */
  PLATFORMINFO_TYPE_CLS          = 0x1D,  /**< Target is a CLS device. */
  PLATFORMINFO_TYPE_TTP          = 0x1E,  /**< Target is a TTP device. */
  PLATFORMINFO_TYPE_HDK          = 0x1F,  /**< Target is a HDK device. */
  PLATFORMINFO_TYPE_IOT          = 0x20,  /**< Target is a IOT device. */
  PLATFORMINFO_TYPE_ATP          = 0x21,  /**< Target is a ATP device. */
  PLATFORMINFO_TYPE_IDP          = 0x22,  /**< Target is a IDP device. */
  PLATFORMINFO_TYPE_AEDK         = 0x23,  /**< AI Edge Development Kit. */
  PLATFORMINFO_TYPE_WDP          = 0x24,  /**< Wearable (reference) Design Platform. */
  PLATFORMINFO_TYPE_QAM          = 0x25,  /**< Small form factored automotive platform. */
  PLATFORMINFO_TYPE_QXR          = 0x26,  /**< QualcommeXtendedReality Reference devices that are form-accurate for XR products. */
  PLATFORMINFO_TYPE_X100         = 0x27,  /**< Target is a X100 device.*/
  PLATFORMINFO_TYPE_CRD          = 0x28,  /**< Target is a CRD device.*/
  PLATFORMINFO_TYPE_QQVP         = 0x29,  /**< Qualcomm QEMU Virtual device.*/

  PLATFORMINFO_NUM_TYPES, /**< Number of known targets (including unknown). */
  /** @cond */
  PLATFORMINFO_TYPE_32BITS       = 0x7FFFFFFF
  /** @endcond */
} PlatformInfoPlatformType;


/**
 * Keys to get data out of the CDT.
 */
typedef enum
{
  PLATFORMINFO_KEY_UNKNOWN       = 0x00,
  PLATFORMINFO_KEY_DDR_FREQ      = 0x01,
  PLATFORMINFO_KEY_GFX_FREQ      = 0x02,
  PLATFORMINFO_KEY_CAMERA_FREQ   = 0x03,
  PLATFORMINFO_KEY_FUSION        = 0x04,
  PLATFORMINFO_KEY_CUST          = 0x05,
  PLATFORMINFO_KEY_NAND_SCRUB    = 0x06,
  PLATFORMINFO_KEY_SLT           = 0x07,
  PLATFORMINFO_KEY_PMIC          = 0x08,

  PLATFORMINFO_NUM_KEYS,

  /** @cond */
  PLATFORMINFO_KEY_32BITS  = 0x7FFFFFFF
  /** @endcond */
} PlatformInfoKeyType;


/**
  @brief Stores the target platform, the platform version, and the
  platform subtype.
 */
typedef struct
{
  PlatformInfoPlatformType     platform;   /**< Type of the current target. */
  uint32_t                     version;    /**< Version of the platform in use. */
  uint32_t                     subtype;    /**< Sub-type of the platform. */
  bool                         fusion;     /**< TRUE if Fusion; FALSE otherwise. */
} PlatformInfoPlatformInfoType;

#endif

