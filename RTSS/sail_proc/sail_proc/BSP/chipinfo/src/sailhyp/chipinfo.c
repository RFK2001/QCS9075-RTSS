/*==============================================================================
  @file chipinfo.c

  ChipInfo functions for the SAIL chipinfo driver

================================================================================
        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
               All Rights Reserved.
            QUALCOMM Proprietary/GTDR
================================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "HALhwio.h"
#include <stdint.h>
#include "chipinfo.h"
#include "sail_csr_hwio.h"
#include "sail_security_control_hwio.h"
#include "sail_tlmm_hwio.h"
//#include "string_wrapper.h"
#include "chipinfodefs.h"
#include "platforminfodefs.h"
#include "common_functions.h"

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
/**
 * Chipset-specific numbers of cores and clusters.
 * CHIPINFO_PARTIALGOODS_NUM_CLUSTERS is different from
 * ChipInfoDefs.h/CHIPINFO_MAX_CPU_CLUSTERS since the latter is a global
 * maximum across all supported chips, while the former only applies to
 * the current chip.
 */
#define CHIPINFO_PARTIALGOODS_NUM_CLUSTERS                    1

/**
 * The PARTIAL_GOOD fuses contain a bitmask of all the defective bins,
 * with bit0 = Bin A, bit1 = Bin B, etc. If Bins A and B are both defective,
 * the fuses would hold 0b0011. Bins A through D are supported.
 * This macro expects uppercase letters only. It will be used to mask the
 * contents of the PARTIAL_GOOD fuses to identify the blown fuses.
 */
#define CHIPINFO_PARTIALGOODS_BIN(x)                          0x1 << ((char)(x) - 'A')

/*
 * Macro to check if sub-binning is enabled for the specified bin.
 *
 */
#define CHIPINFO_SUB_BINNING_ENABLED(val, bin)                ((val) & (0x1 << 4))

/**
 * Statically allocate the CPU clusters array so we don't need to do dynamic
 * allocation and have a dependency on heap.
 */
#define CHIPINFO_CLUSTER0_GOLD_PLUS_CORES_MASK   0x1
#define CHIPINFO_CLUSTER0_GOLD_PLUS_CORES_SHFT   7
#define CHIPINFO_CLUSTER0_GOLD_CORES_MASK        0x7
#define CHIPINFO_CLUSTER0_GOLD_CORES_SHFT        4
#define _CHIPINFO_MASK_CPU_CORES(c, x)    \
  CHIPINFO_CLUSTER##c##_##x##_CORES_MASK << CHIPINFO_CLUSTER##c##_##x##_CORES_SHFT
#define CHIPINFO_MASK_CLUSTER0(x) _CHIPINFO_MASK_CPU_CORES(0, x)

#define PLATFORMINFO_TYPE_SILICON             0U             /* default setting for Platform Type */

/*==============================================================================
      Data Definitons
==============================================================================*/

/*
 * ChipInfoDataLUT
 *
 * Array of chip id strings, chip IDs, part numbers, and modem support.
 *
 * Various HLOS clients still expect to see the old naming convention for
 * Hana variants. Continue to report the legacy names for Hana.
 *
 * This table only needs to contain mappings for targets supported out of this warehouse.
 */
static const ChipInfoDataLUTType ChipInfoDataLUT[] =
{
  { "UNKNOWN",              CHIPINFO_ID_UNKNOWN,              CHIPINFO_PARTNUM_UNKNOWN,              CHIPINFO_MODEM_UNKNOWN    },
  { "SM_LAHAINA",           CHIPINFO_ID_SM_LAHAINA,           CHIPINFO_PARTNUM_SM_LAHAINA,           CHIPINFO_MODEM_SUPPORTED  },
  { "SMP_LAHAINA",          CHIPINFO_ID_SMP_LAHAINA,          CHIPINFO_PARTNUM_SMP_LAHAINA,          CHIPINFO_MODEM_UNKNOWN    },
  { "SM_CEDROS",            CHIPINFO_ID_SM_CEDROS,            CHIPINFO_PARTNUM_SM_CEDROS,            CHIPINFO_MODEM_SUPPORTED  },
  { "SC_MAKENA",            CHIPINFO_ID_SC_MAKENA,            CHIPINFO_PARTNUM_SC_MAKENA,            CHIPINFO_MODEM_UNKNOWN    },
  { "SM_LAHAINA_MODULE",    CHIPINFO_ID_SM_LAHAINA,           CHIPINFO_PARTNUM_SM_LAHAINA,           CHIPINFO_MODEM_SUPPORTED  },
  { "SM_WAIPIO",            CHIPINFO_ID_SM_WAIPIO,            CHIPINFO_PARTNUM_SM_WAIPIO,            CHIPINFO_MODEM_SUPPORTED  },
  { "SM_OLYMPIC",           CHIPINFO_ID_SDX_OLYMPIC,          CHIPINFO_PARTNUM_SDX_OLYMPIC,          CHIPINFO_MODEM_SUPPORTED  },
  { "SA_MAKENA_IVI",        CHIPINFO_ID_SA_MAKENA_IVI,        CHIPINFO_PARTNUM_SA_MAKENA_IVI,        CHIPINFO_MODEM_UNKNOWN    },
  { "SA_MAKENA_ADAS",       CHIPINFO_ID_SA_MAKENA_ADAS,       CHIPINFO_PARTNUM_SA_MAKENA_ADAS,       CHIPINFO_MODEM_UNKNOWN    },
  
  { "SA_LEMANSAU_IVI",        CHIPINFO_ID_SA_LEMANSAU_IVI,        CHIPINFO_PARTNUM_SA_LEMANSAU_IVI,        CHIPINFO_MODEM_UNKNOWN   },
  { "SA_LEMANSAU_ADAS",       CHIPINFO_ID_SA_LEMANSAU_ADAS,       CHIPINFO_PARTNUM_SA_LEMANSAU_ADAS,       CHIPINFO_MODEM_UNKNOWN   },
  { "SA_LEMANSAU_IVI_ADAS",   CHIPINFO_ID_SA_LEMANSAU_IVI_ADAS,   CHIPINFO_PARTNUM_SA_LEMANSAU_IVI_ADAS,   CHIPINFO_MODEM_UNKNOWN   },
  { "SA_LEMANSAU_ADAS_H",     CHIPINFO_ID_SA_LEMANSAU_ADAS_H,     CHIPINFO_PARTNUM_SA_LEMANSAU_ADAS_H,     CHIPINFO_MODEM_UNKNOWN   },
  { "SA_LEMANSAU_IVI_ADAS_L", CHIPINFO_ID_SA_LEMANSAU_IVI_ADAS_L, CHIPINFO_PARTNUM_SA_LEMANSAU_IVI_ADAS_L, CHIPINFO_MODEM_UNKNOWN   },
  { "QRB_LEMANSAU",           CHIPINFO_ID_QRB_LEMANS,             CHIPINFO_PARTNUM_QRB_LEMANS,             CHIPINFO_MODEM_UNKNOWN   },
  { "QCS_LEMANS",           CHIPINFO_ID_QCS_LEMANS,             CHIPINFO_PARTNUM_QCS_LEMANS,            CHIPINFO_MODEM_UNKNOWN   },
  { "QCS_LEMANS_INDUSTRIAL",CHIPINFO_ID_QCS_LEMANS_INDUSTRIAL,  CHIPINFO_PARTNUM_QCS_LEMANS_INDUSTRIAL, CHIPINFO_MODEM_UNKNOWN   },

  { "SA_MONACOAU_SRV1L",      CHIPINFO_ID_SA_MONACOAU_SRV1L,      CHIPINFO_PARTNUM_SA_MONACOAU_SRV1L,      CHIPINFO_MODEM_UNKNOWN   },
  { "SA_MONACOAU_IVI",        CHIPINFO_ID_SA_MONACOAU_IVI,        CHIPINFO_PARTNUM_SA_MONACOAU_IVI,        CHIPINFO_MODEM_UNKNOWN   },
  { "SA_MONACOAU_ADAS",       CHIPINFO_ID_SA_MONACOAU_ADAS,       CHIPINFO_PARTNUM_SA_MONACOAU_ADAS,       CHIPINFO_MODEM_UNKNOWN   },
  { "SA_MONACOAU_SRV1L_FFC",  CHIPINFO_ID_SA_MONACOAU_SRV1L_FFC,  CHIPINFO_PARTNUM_SA_MONACOAU_SRV1L_FFC,  CHIPINFO_MODEM_UNKNOWN   },
  { "QCS_MONACO_INDUSTRIAL_SAFE", CHIPINFO_ID_QCS_MONACO_INDUSTRIAL_SAFE, CHIPINFO_PARTNUM_QCS_MONACO_INDUSTRIAL_SAFE,  CHIPINFO_MODEM_UNKNOWN   },
  { "QCS_MONACO_INDUSTRIAL",      CHIPINFO_ID_QCS_MONACO_INDUSTRIAL,      CHIPINFO_PARTNUM_QCS_MONACO_INDUSTRIAL,       CHIPINFO_MODEM_UNKNOWN   },
  { "SA_MONACOAU_FLEX",           CHIPINFO_ID_SA_MONACOAU_FLEX,           CHIPINFO_PARTNUM_SA_MONACOAU_FLEX,            CHIPINFO_MODEM_UNKNOWN   },
};


/*
 * ChipInfoArchFamilyArray
 *
 * Array of default chip ID and family IDs to use if the JTAG ID is not recognized.
 * The product family can be identified using TCSR_SOC_HW_VERSION, which is defined
 * in RTL and is therefore always available. This is typically only needed when
 * parts haven't yet been fused (e.g. RUMI or early during silicon bring up).
 *
 * This array only needs to contain information for product families being supported
 * from this warehouse.
 */
static const ChipInfoArchFamilyDataType ChipInfoArchFamilyArray[] =
{
  { CHIPINFO_ARCH_FAMILY_UNKNOWN,     0,  CHIPINFO_FAMILY_UNKNOWN,  CHIPINFO_ID_UNKNOWN          },

  { CHIPINFO_ARCH_FAMILY_HOYA,        15, CHIPINFO_FAMILY_LAHAINA,  CHIPINFO_ID_SM_LAHAINA       },

  { CHIPINFO_ARCH_FAMILY_HOYA,        20, CHIPINFO_FAMILY_MAKENA,   CHIPINFO_ID_SA_MAKENA_ADAS   },
  
  { CHIPINFO_ARCH_FAMILY_HOYA,        25, CHIPINFO_FAMILY_LEMANSAU, CHIPINFO_ID_SA_LEMANSAU_ADAS },

  { CHIPINFO_ARCH_FAMILY_HOYA,        26, CHIPINFO_FAMILY_MONACOAU, CHIPINFO_ID_SA_MONACOAU_ADAS },

  { CHIPINFO_ARCH_FAMILY_WILDCAT,     23, CHIPINFO_FAMILY_NORDAU,   CHIPINFO_ID_SMP_NORDAU       },
};


static ChipInfoBSPType ChipInfoBSP =
{
  .aLUT = ChipInfoDataLUT,
  .nNumLUTEntries = ARRAY_SIZE(ChipInfoDataLUT),
  .aArchFamilyData = ChipInfoArchFamilyArray,
  .nNumArchFamilyDataEntries = ARRAY_SIZE(ChipInfoArchFamilyArray),
};

uint32_t aCPUClusters[CHIPINFO_PARTIALGOODS_NUM_CLUSTERS] = { 0 };

/*
 * Internal structure to hold chip info.
 *
 */
ChipInfoCtxtType ChipInfoCtxt;
/*==============================================================================
      Functions
==============================================================================*/

ChipInfoBSPType *ChipInfo_GetBSPData
(
  void
)
{
  return &ChipInfoBSP;
}

/*==============================================================================
  FUNCTION      ChipInfo_InitChipset

  DESCRIPTION   Chipset-specific initialization sequences, including reading
                PTE fuses to determine which parts are defective

==============================================================================*/
void ChipInfo_InitChipset(ChipInfoCtxtType *pChipInfoCtxt)
{

  if (pChipInfoCtxt == NULL)
  {
    return;
  }

  pChipInfoCtxt->nNumClusters = CHIPINFO_PARTIALGOODS_NUM_CLUSTERS;
  pChipInfoCtxt->aCPUClusters = aCPUClusters;
}

ChipInfoVersionType ChipInfo_GetChipVersion(void)
{
  return ChipInfoCtxt.nVersion;
} /* END ChipInfo_GetChipVersion */

ChipInfoVersionType ChipInfo_GetSailChipVersion(void)
{
  return ChipInfoCtxt.nSailVersion;
} /* END ChipInfo_GetSailChipVersion */

ChipInfoIdType ChipInfo_GetChipId(void)
{
  return ChipInfoCtxt.eChipInfoId;
} /*  END ChipInfo_GetChipId  */

ChipInfoFamilyType ChipInfo_GetChipFamily(void)
{
  return ChipInfoCtxt.eFamilyId;
} /* END Chipinfo_GetChipFamily */

bool ChipInfo_Init(void)
{
  uint32_t MajorVersion, MinorVersion, RawArchFamilyId, RawDeviceId, RawFoundryId;
  uint32_t SailMajorVersion, SailMinorVersion;
  uint32_t LUTIdx, DefaultChipIdLUTIdx, ArchFamilyArrayIdx;
  ChipInfoIdType eDefaultChipId;
  ChipInfoArchFamilyType eArchFamilyId;
  ChipInfoFamilyType eFamilyId;
  ChipInfoArchFamilyDataType ArchFamilyData = { (ChipInfoArchFamilyType)0 };
  ChipInfoBSPType *pBSP = ChipInfo_GetBSPData();
  const ChipInfoDataLUTType *pLUT = pBSP->aLUT;
  const ChipInfoArchFamilyDataType *paArchFamilyArray = pBSP->aArchFamilyData;
  const uint32_t nLUTSize = pBSP->nNumLUTEntries;
  const uint32_t nArchFamilyDataEntries = pBSP->nNumArchFamilyDataEntries;

  if (ChipInfoCtxt.bInitComplete)
  {
    return TRUE;
  }

  /*
   * Read each register and parse out the relevant info.
   * Some of this info needs to be validated before being stored
  */
  ChipInfoCtxt.nRawPartNum          = HWIO_INF(CHIPINFO_JTAG_ID_REG, PRODUCT_DEVICE_ID);
  ChipInfoCtxt.nRevNumber           = HWIO_INF(CHIPINFO_REVISION_NUMBER_REG, VERSION_ID);

  MajorVersion                      = HWIO_INF(CHIPINFO_TCSR_SOC_HW_VERSION, MAJOR_VERSION);
  MinorVersion                      = HWIO_INF(CHIPINFO_TCSR_SOC_HW_VERSION, MINOR_VERSION);
  ChipInfoCtxt.nVersion             = CHIPINFO_VERSION(MajorVersion, MinorVersion);

  SailMajorVersion                  = HWIO_INF(SAILSS_CSR_SAIL_HW_VER, MAJOR_VERSION);
  SailMinorVersion                  = HWIO_INF(SAILSS_CSR_SAIL_HW_VER, MINOR_VERSION);
  ChipInfoCtxt.nSailVersion         = CHIPINFO_VERSION(SailMajorVersion, SailMinorVersion);

  RawArchFamilyId                   = HWIO_INF(CHIPINFO_TCSR_SOC_HW_VERSION, FAMILY_NUMBER);
  RawDeviceId                       = HWIO_INF(CHIPINFO_TCSR_SOC_HW_VERSION, DEVICE_NUMBER);

  RawFoundryId                      = HWIO_INF(CHIPINFO_FOUNDRY_ID_REG, FOUNDRY_ID);

  ChipInfoCtxt.nSerialNum           = HWIO_INF(CHIPINFO_SERIAL_NUM_REG, SERIAL_NUM);

  ChipInfoCtxt.nQFPROMChipId        = HWIO_INF(CHIPINFO_QFPROM_CHIP_ID_REG, CHIP_ID);

  /* Validate the raw values, where necessary */

  /*
   * Process the foundry Id.
   * Account for the additional CHIPINFO_FOUNDRY_ID_UNKNOWN, which
   * isn't actually a foundry ID reported by HW
  */
  if (RawFoundryId < CHIPINFO_NUM_FOUNDRYIDS - 1)
  {
    ChipInfoCtxt.eFoundryId = (ChipInfoFoundryIdType)(RawFoundryId + 1);
  }
  else
  {
    ChipInfoCtxt.eFoundryId = CHIPINFO_FOUNDRYID_UNKNOWN;
  }

  /* Parse the internal family ID using the architectural family info from HW */
  ChipInfoCtxt.nRawFamilyId = RawArchFamilyId;
  ChipInfoCtxt.nFamilyDeviceId = RawDeviceId;
  if (RawArchFamilyId >= CHIPINFO_NUM_ARCH_FAMILIES - 1 )
  {
    ChipInfoCtxt.eFamilyId = CHIPINFO_FAMILY_UNKNOWN;
    eArchFamilyId = CHIPINFO_ARCH_FAMILY_UNKNOWN;
  }
  else
  {
    /*
     * eArchFamilyId is going to be used to search the BSP
     * for the internal family ID corresponding to
     * RawArchFamilyId and RawDeviceNum. RawArchFamilyId doesn't account
     * for CHIPINFO_ARCH_FAMILY_UNKNOWN, so account for it
     * while converting it to its enum value
    */
    eArchFamilyId = (ChipInfoArchFamilyType)(RawArchFamilyId + 1);
  }

  /*
   * Search the arch family array for a family ID corresponding to
   * the HW arch family value and device number
  */
  eFamilyId = CHIPINFO_FAMILY_UNKNOWN;
  eDefaultChipId = CHIPINFO_ID_UNKNOWN;
  for (ArchFamilyArrayIdx = 0; ArchFamilyArrayIdx < nArchFamilyDataEntries; ArchFamilyArrayIdx++)
  {
    ArchFamilyData = paArchFamilyArray[ArchFamilyArrayIdx];
    if(ArchFamilyData.eArchFamily == eArchFamilyId && ArchFamilyData.nArchFamilyDeviceNum == RawDeviceId)
    {
      eFamilyId = ArchFamilyData.eDeviceFamily;
      eDefaultChipId = ArchFamilyData.eDefaultChipId;
      break;
    }
  }

  ChipInfoCtxt.eFamilyId = eFamilyId;

  /* Get the chip's name, internal ID, and supported modems from the LUT  */
  LUTIdx = 0;
  DefaultChipIdLUTIdx = 0;
  for (LUTIdx = 0; LUTIdx < nLUTSize; LUTIdx++)
  {
    if (pLUT[LUTIdx].nPartNum == ChipInfoCtxt.nRawPartNum)
    {
      break;
    }
    else if (pLUT[LUTIdx].eChipId == eDefaultChipId)
    {
      /*
       * Record the index of the defualt info so it can be retrieved
       * without looping through the LUT again
      */
      DefaultChipIdLUTIdx = LUTIdx;
    }
  }

  if (LUTIdx == nLUTSize)
  {
    /*
     * Searched the LUT without finding a matching part number, so try using
     * the index of the default chip ID. If one wasn't provided, or if the default
     * wasn't found in the LUT either, this defaults to 0 (UNKNOWN)
    */
    LUTIdx = DefaultChipIdLUTIdx;
  }

  ChipInfoCtxt.eChipInfoId = pLUT[LUTIdx].eChipId;

  if((sailbsp_strlcpy(ChipInfoCtxt.szChipIdString, pLUT[LUTIdx].szChipIdStr,
   sizeof(ChipInfoCtxt.szChipIdString))) >= sizeof(ChipInfoCtxt.szChipIdString))
  {
    return FALSE;
  }

  /*
   * Get the supported modems from the BSP
   * TODO: Decide on what to do with modem support
   */
  //ChipInfoCtxt.nModemSupported = pLUT[LUTIdx].nModem;

  /* Fill in Partial Goods information  */
  ChipInfo_InitChipset(&ChipInfoCtxt);

  ChipInfoCtxt.bInitComplete  = TRUE;
  return TRUE;
}

PlatformInfoPlatformType PlatformInfo_DetectPlatformType (void)
{
  uint32_t nVal;

  /* NOTE:
     default SILICON  - PLATFORMINFO_TYPE_SILICON = 0U
     0x0: Silicon
     0x1: RUMI
     0x2: Veloce
     0x3: Virtio
   */
  nVal = PLATFORMINFO_TYPE_SILICON;
  switch (nVal)
  {
    case 1:   return PLATFORMINFO_TYPE_RUMI;
    case 3:   return PLATFORMINFO_TYPE_VIRTIO;
    default:
      return PLATFORMINFO_TYPE_UNKNOWN;
  }

} /* END PlatformInfo_DetectPlatformType */

PlatformInfoPlatformType PlatformInfo_Platform()
{
	return PlatformInfo_DetectPlatformType();
}
