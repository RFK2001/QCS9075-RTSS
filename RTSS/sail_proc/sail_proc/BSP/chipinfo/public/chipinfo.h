
#ifndef _CHIPINFO_H_
#define _CHIPINFO_H_
/**
 * @file chipinfo.h
 * @brief
 * Header file for chipinfo driver
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/
#include "chipinfodefs.h"
#include "platforminfodefs.h"

/*
 * CHIPINFO_MFGNUM_*
 *
 * Manufacturer IDs
 * TODO Doesn't seem to be used anywhere. It was used in DalChipInfo_GetManufacturer,
 * which we no longer have.
 */
#define CHIPINFO_MFGNUM_QUALCOMM 0x170

#ifndef SAILEL2
#define CHIPINFO_FUNC  __attribute__ ( ( section ( "chipinfo_func" ) ) )
#else
#define CHIPINFO_FUNC
#endif


/*
 * CHIPINFO_PARTNUM_*
 *
 * Definitions of part number/JTAG-ID fields.
 * Organized in alphabetical order of target name.
 */
#define CHIPINFO_PARTNUM_APQ8026               0x804
#define CHIPINFO_PARTNUM_APQ8028               0x913
#define CHIPINFO_PARTNUM_APQ8062               0x912
#define CHIPINFO_PARTNUM_APQ8074               0x7B3
#define CHIPINFO_PARTNUM_APQ8074_AA            0x7BF
#define CHIPINFO_PARTNUM_APQ8074_AB            0x7BB
#define CHIPINFO_PARTNUM_APQ8074_PRO           0x7B7
#define CHIPINFO_PARTNUM_APQ8084_0             0x900
#define CHIPINFO_PARTNUM_APQ8084_1             0x901
#define CHIPINFO_PARTNUM_APQ8096               0x03E
#define CHIPINFO_PARTNUM_APQ8096SG             0x064
#define CHIPINFO_PARTNUM_APQ8096SGAU           0x071
#define CHIPINFO_PARTNUM_APQ8098               0x062
#define CHIPINFO_PARTNUM_FSM9900               0x80F
#define CHIPINFO_PARTNUM_FSM9910               0x80E
#define CHIPINFO_PARTNUM_FSM9915               0x80D
#define CHIPINFO_PARTNUM_FSM9950               0x80C
#define CHIPINFO_PARTNUM_FSM9955               0x80B
#define CHIPINFO_PARTNUM_FSM9965               0x80A
#define CHIPINFO_PARTNUM_MDM8225               0x7F0
#define CHIPINFO_PARTNUM_MDM8225M              0x7F3
#define CHIPINFO_PARTNUM_MDM8630               0x924
#define CHIPINFO_PARTNUM_MDM9225               0x7F1
#define CHIPINFO_PARTNUM_MDM9225M              0x7F2
#define CHIPINFO_PARTNUM_MDM9225M_1            0x7F2
#define CHIPINFO_PARTNUM_MDM9225_1             0x7F1
#define CHIPINFO_PARTNUM_MDM9230               0x922
#define CHIPINFO_PARTNUM_MDM9235M              0x923
#define CHIPINFO_PARTNUM_MDM9240               0x951
#define CHIPINFO_PARTNUM_MDM9245               0x955
#define CHIPINFO_PARTNUM_MDM9250               0x032
#define CHIPINFO_PARTNUM_MDM9255               0x034
#define CHIPINFO_PARTNUM_MDM9320               0x7F7
#define CHIPINFO_PARTNUM_MDM9330               0x925
#define CHIPINFO_PARTNUM_MDM9340               0x952
#define CHIPINFO_PARTNUM_MDM9350               0x039
#define CHIPINFO_PARTNUM_MDM9625               0x7F4
#define CHIPINFO_PARTNUM_MDM9625M              0x7F5
#define CHIPINFO_PARTNUM_MDM9630               0x920
#define CHIPINFO_PARTNUM_MDM9635M              0x921
#define CHIPINFO_PARTNUM_MDM9640               0x950
#define CHIPINFO_PARTNUM_MDM9645               0x954
#define CHIPINFO_PARTNUM_MDM9650               0x03A
#define CHIPINFO_PARTNUM_MDM9655               0x03B
#define CHIPINFO_PARTNUM_MDM9660               0x07D
#define CHIPINFO_PARTNUM_MDM9665               0x07F
#define CHIPINFO_PARTNUM_MPQ8092               0x930
#define CHIPINFO_PARTNUM_MSM8110               0x810
#define CHIPINFO_PARTNUM_MSM8112               0x816
#define CHIPINFO_PARTNUM_MSM8126               0x803
#define CHIPINFO_PARTNUM_MSM8128               0x914
#define CHIPINFO_PARTNUM_MSM8210               0x811
#define CHIPINFO_PARTNUM_MSM8212               0x814
#define CHIPINFO_PARTNUM_MSM8226               0x800
#define CHIPINFO_PARTNUM_MSM8228               0x915
#define CHIPINFO_PARTNUM_MSM8262               0x911
#define CHIPINFO_PARTNUM_MSM8274               0x7B2
#define CHIPINFO_PARTNUM_MSM8274_AA            0x7BE
#define CHIPINFO_PARTNUM_MSM8274_AB            0x7BA
#define CHIPINFO_PARTNUM_MSM8274_PRO           0x7B6
#define CHIPINFO_PARTNUM_MSM8326               0x806
#define CHIPINFO_PARTNUM_MSM8510               0x817
#define CHIPINFO_PARTNUM_MSM8512               0x818
#define CHIPINFO_PARTNUM_MSM8526               0x802
#define CHIPINFO_PARTNUM_MSM8528               0x916
#define CHIPINFO_PARTNUM_MSM8610               0x812
#define CHIPINFO_PARTNUM_MSM8612               0x815
#define CHIPINFO_PARTNUM_MSM8626               0x801
#define CHIPINFO_PARTNUM_MSM8628               0x917
#define CHIPINFO_PARTNUM_MSM8674               0x7B1
#define CHIPINFO_PARTNUM_MSM8674_AA            0x7BD
#define CHIPINFO_PARTNUM_MSM8674_AB            0x7B9
#define CHIPINFO_PARTNUM_MSM8674_PRO           0x7B5
#define CHIPINFO_PARTNUM_MSM8810               0x813
#define CHIPINFO_PARTNUM_MSM8916               0x705
#define CHIPINFO_PARTNUM_MSM8926               0x805
#define CHIPINFO_PARTNUM_MSM8928               0x918
#define CHIPINFO_PARTNUM_MSM8962               0x910
#define CHIPINFO_PARTNUM_MSM8974               0x7B0
#define CHIPINFO_PARTNUM_MSM8974_AA            0x7BC
#define CHIPINFO_PARTNUM_MSM8974_AB            0x7B8
#define CHIPINFO_PARTNUM_MSM8974_PRO           0x7B4
#define CHIPINFO_PARTNUM_MSM8994               0x940
#define CHIPINFO_PARTNUM_MSM8996               0x947
#define CHIPINFO_PARTNUM_MSM8996SG             0x05F
#define CHIPINFO_PARTNUM_MSM8996SGAU           0x06F
#define CHIPINFO_PARTNUM_MSM8997               0x06C
#define CHIPINFO_PARTNUM_MSM8998               0x05E
#define CHIPINFO_PARTNUM_MSM8998               0x05E
#define CHIPINFO_PARTNUM_QCA6390               0x0D9
#define CHIPINFO_PARTNUM_QCS605                0x0AA
#define CHIPINFO_PARTNUM_QDF2432               0x944
#define CHIPINFO_PARTNUM_SA4155P 	           0x0F2
#define CHIPINFO_PARTNUM_SA6145P	           0x0F1
#define CHIPINFO_PARTNUM_SA6150P	           0x0EF
#define CHIPINFO_PARTNUM_SA6155P	           0x0EE
#define CHIPINFO_PARTNUM_SA8150                0x0E8
#define CHIPINFO_PARTNUM_SA8150P               0x0E9
#define CHIPINFO_PARTNUM_SA_MAKENA_ADAS        0x14C
#define CHIPINFO_PARTNUM_SA_MAKENA_IVI         0x14B
#define CHIPINFO_PARTNUM_SC_MAKENA             0x14A
#define CHIPINFO_PARTNUM_SDA670                0x093
#define CHIPINFO_PARTNUM_SDA855                0x0A6
#define CHIPINFO_PARTNUM_SDA865                0x0C3
#define CHIPINFO_PARTNUM_SDC830                0x092
#define CHIPINFO_PARTNUM_SDC845                0x08E
#define CHIPINFO_PARTNUM_SDA845                CHIPINFO_PARTNUM_SDC845
#define CHIPINFO_PARTNUM_SDM450                0x09A
#define CHIPINFO_PARTNUM_SDM630                0x07E
#define CHIPINFO_PARTNUM_SDM640                0x095
#define CHIPINFO_PARTNUM_SDM660                0x07D
#define CHIPINFO_PARTNUM_SDM670                0x091
#define CHIPINFO_PARTNUM_SDM830                0x08F
#define CHIPINFO_PARTNUM_SDM845                0x08B
#define CHIPINFO_PARTNUM_SDM855                0x0A5
#define CHIPINFO_PARTNUM_SDM855A               0x0CB // Different JTAG ID from SA8150, but same chip.
#define CHIPINFO_PARTNUM_SDM1000               0x0B8
#define CHIPINFO_PARTNUM_SDX24                 0x096
#define CHIPINFO_PARTNUM_SDX24M                0x097
#define CHIPINFO_PARTNUM_SDX55                 0x0CF
#define CHIPINFO_PARTNUM_SM7150                0x0E6
#define CHIPINFO_PARTNUM_SM7150P               0x0E7
#define CHIPINFO_PARTNUM_SM8150                CHIPINFO_PARTNUM_SDM855
#define CHIPINFO_PARTNUM_SM8150P               CHIPINFO_PARTNUM_SDA855
#define CHIPINFO_PARTNUM_SM6150                CHIPINFO_PARTNUM_SDM640
#define CHIPINFO_PARTNUM_SM6150P               0x0EC
#define CHIPINFO_PARTNUM_SM_LAHAINA            0x135
#define CHIPINFO_PARTNUM_SM_LAHAINA_MODULE     0x152
#define CHIPINFO_PARTNUM_SMP_LAHAINA           0x142
#define CHIPINFO_PARTNUM_SM_CEDROS             0x159
#define CHIPINFO_PARTNUM_SA_LEMANSAU_ADAS      0x1CE
#define CHIPINFO_PARTNUM_SA_LEMANSAU_IVI_ADAS  0x1D2
#define CHIPINFO_PARTNUM_SA_LEMANSAU_ADAS_H    0x1D1
#define CHIPINFO_PARTNUM_SA_LEMANSAU_IVI       0x1CF
#define CHIPINFO_PARTNUM_SA_LEMANSAU_IVI_ADAS_L 0x27B
#define CHIPINFO_PARTNUM_SA_MONACOAU_SRV1L     0x26E
#define CHIPINFO_PARTNUM_SA_MONACOAU_IVI       0x26C
#define CHIPINFO_PARTNUM_SA_MONACOAU_ADAS      0x26D
#define CHIPINFO_PARTNUM_SA_MONACOAU_SRV1L_FFC 0x28F
#define CHIPINFO_PARTNUM_QCS_LEMANS                 0x2B5
#define CHIPINFO_PARTNUM_QRB_LEMANS            	0x2C4
#define CHIPINFO_PARTNUM_QAM8797P                 	0x2CC
#define CHIPINFO_PARTNUM_QAM8397P                 	0x2E3
#define CHIPINFO_PARTNUM_QCS_MONACO_INDUSTRIAL_SAFE	0x2E6
#define CHIPINFO_PARTNUM_QCS_MONACO_INDUSTRIAL      	0x2E7
#define CHIPINFO_PARTNUM_QCS_LEMANS_INDUSTRIAL		0x2EB
#define CHIPINFO_PARTNUM_QAIM200H                	0x2EF
#define CHIPINFO_PARTNUM_QAIM200L                	0x2F1
#define CHIPINFO_PARTNUM_SA_MONACOAU_FLEX         	0x2FB
#define CHIPINFO_PARTNUM_SMP_NORDAU             	0x0 //@TODO once ipcat is updated

/*
 * Placeholders for currently unknown part numbers
 */
#define CHIPINFO_PARTNUM_UNKNOWN               0xFFFF
#define CHIPINFO_PARTNUM_SM_WAIPIO             CHIPINFO_PARTNUM_UNKNOWN
#define CHIPINFO_PARTNUM_SDX_OLYMPIC           CHIPINFO_PARTNUM_UNKNOWN
/*=============================================================================
  Type definitions
  =============================================================================*/
/**
 * ChipInfoArchFamilyType
 *
 * ChipInfo architectural families. Each architectural family refers to
 * multiple ChipInfo internal device families
 */
typedef enum
{
  CHIPINFO_ARCH_FAMILY_UNKNOWN = 0,
  CHIPINFO_ARCH_FAMILY_BADGER,
  CHIPINFO_ARCH_FAMILY_ULT,
  CHIPINFO_ARCH_FAMILY_BEAR,
  CHIPINFO_ARCH_FAMILY_HONEYBADGER,
  CHIPINFO_ARCH_FAMILY_QCA,
  CHIPINFO_ARCH_FAMILY_DRAGONFLY,
  CHIPINFO_ARCH_FAMILY_HOYA,
  CHIPINFO_ARCH_FAMILY_MODEMIP,
  CHIPINFO_ARCH_FAMILY_BLACKGHOST,
  CHIPINFO_ARCH_FAMILY_BRUIN,
  CHIPINFO_ARCH_FAMILY_WILDCAT,

  CHIPINFO_NUM_ARCH_FAMILIES,
} ChipInfoArchFamilyType;

/**
 * ChipInfoDataLUTType
 *
 * Static per-chip data definitions
 *
 * szChipIdStr:   String representing the MSM name.
 * eChipId:       Incremental, internal chip ID
 * nPartNum:      JTAG ID
 * nModem:        Bitmask of supported modems on this MSM.
 *
 */
typedef struct
{
  const char          *szChipIdStr;
  ChipInfoIdType      eChipId;
  uint32_t            nPartNum;
  ChipInfoModemType   nModem;
} ChipInfoDataLUTType;

/**
 * ChipInfoArchFamilyDataType
 *
 * Information about the chip families represented by each
 * architectural family
 *
 * eArchFamily: the architectural family
 * nArchFamilyDeviceNum: the device number within the architectural family
 * eDeviceFamily: ChipInfo internal family for this device
 * eDefaultChipId: Default ChipInfo internal chip id to use if it couldn't be determined using the LUT.
 */
typedef struct
{
  ChipInfoArchFamilyType  eArchFamily;
  uint32_t                nArchFamilyDeviceNum;
  ChipInfoFamilyType      eDeviceFamily;
  ChipInfoIdType          eDefaultChipId;
} ChipInfoArchFamilyDataType;


/**
 * ChipInfoBSPType
 *
 * Static BSP data.
 */
typedef struct
{
  const ChipInfoDataLUTType         *aLUT;
  const uint32_t                    nNumLUTEntries;
  const ChipInfoArchFamilyDataType  *aArchFamilyData;
  const uint32_t                    nNumArchFamilyDataEntries;
} ChipInfoBSPType;

/**
 * ChipInfoType
 *
 * Container for all chip info
 */
typedef struct
{
  bool                        bInitComplete;        /*  Driver has been initialized */
  uint32_t                    nRawPartNum;          /*  JTAG ID/Device Number */
  ChipInfoIdType              eChipInfoId;          /*  Sequential ID, unique across all chips */
  ChipInfoVersionType         nVersion;             /*  Major and Minor versions   */
  ChipInfoVersionType         nSailVersion;         /*  SAIL Major and Minor versions   */
  uint32_t                    nRevNumber;           /*  HW Revision number. e.g. 0 = v1.0, 1 = v1.1, 2 = v2.0 */
  ChipInfoFamilyType          eFamilyId;            /*  Internal ChipInfo family (not architectural family)  */
  uint32_t                    nFamilyDeviceId;      /*  Device ID within this family, unique within the family */
  uint32_t                    nRawFamilyId;         /*  Architectural family number  */
  ChipInfoFoundryIdType       eFoundryId;           /*  The foundry in which the chip was manufactured  */
  ChipInfoSerialNumType       nSerialNum;           /*  Unique (within chip family) serial number  */
  ChipInfoQFPROMChipIdType    nQFPROMChipId;        /*  Chip ID read from QFPROM fuses  */
  ChipInfoModemType           nModemSupported;      /*  Modem hardware is/isnt' supported on this platform */
  char                        szChipIdString[CHIPINFO_MAX_ID_LENGTH]; /*  The chip's name as a string, e.g. "MSM8998" */
  uint32_t                    nNumClusters;
  uint32_t                    *aCPUClusters;        /*  Bitmasks of defective CPU cores for each of nClusters clusters */
  uint32_t                    aDefectiveParts[CHIPINFO_NUM_PARTS];  /*  Set of parts marked as defective */
} ChipInfoCtxtType;

ChipInfoIdType ChipInfo_GetChipId(void);
ChipInfoVersionType ChipInfo_GetChipVersion(void);
ChipInfoVersionType ChipInfo_GetSailChipVersion(void);
bool ChipInfo_Init(void);
ChipInfoFamilyType ChipInfo_GetChipFamily(void);
PlatformInfoPlatformType PlatformInfo_Platform(void);

#endif /* _CHIPINFO_H_ */
