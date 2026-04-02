/*
  ===========================================================================
*/
/**
  @file sail_updater_msgtypes.h
  @brief sail Updater Message types definition
*/
/*
  ===========================================================================

  Copyright (c) 2022-2025 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  Qualcomm Confidential and Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly
  reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.

  ===========================================================================

  $Header: $
  $DateTime: $
  $Author: $

  ===========================================================================
*/

#ifndef __SAIL_UPDATER_MSGTYPES_H__
#define __SAIL_UPDATER_MSGTYPES_H__

#include "types.h"

#define SAIL_UPD_IMG_NAME_HYP             "SAIL_HYP"
#define SAIL_UPD_IMG_NAME_SW1             "SAIL_SW1"
#define SAIL_UPD_IMG_NAME_SW2             "SAIL_SW2"
#define SAIL_UPD_IMG_NAME_SW3             "SAIL_SW3"
#define SAIL_UPD_IMG_NAME_SW4             "SAIL_SW4"
#define SAIL_UPD_IMG_NAME_LEN             32

#define SAIL_UPD_MSG_ID_HELLO               0    /* Hello MSG for handshake after bootup */
#define SAIL_UPD_MSG_ID_CHECK_GPT           1    /* Query GPT header and GPT partition integrity */
#define SAIL_UPD_MSG_ID_READ_GPT            2    /* Read GPT header and GPT partition entry */
#define SAIL_UPD_MSG_ID_WRITE_GPT           3    /* Write new GPT header and GPT partition to fix integrity error */
#define SAIL_UPD_MSG_ID_FIX_GPT             4    /* Fix GPT using the other good GPT table as reference */
#define SAIL_UPD_MSG_ID_UPDATE_GPT          5    /* Update GPT header and GPT partition entry for reboot to take effect */
#define SAIL_UPD_MSG_ID_QUERY_IMAGES        6    /* Query Image boot Information of images specified */
#define SAIL_UPD_MSG_ID_READ_IMAGE          7    /* Read image from SPI NOR flash memory to DDR memory */
#define SAIL_UPD_MSG_ID_FLASH_IMAGE         8    /* Flash image from DDR memory to SPI NOR flash memory at given GPT header's partition */
#define SAIL_UPD_MSG_ID_BOOT_IMAGE          9    /* Boot image to SAIL RAM (Directly load the ELF from DDR to SAIL RAM */
#define SAIL_UPD_MSG_ID_BOOT_CONTINUE       10   /* Boot image to SAIL RAM (Directly load the ELF from DDR to SAIL RAM */
#define SAIL_UPD_MSG_ID_GET_BOOTINFO        11   /* Command consolidates Check GPT and Query Image in single command */
#define SAIL_UPD_MSG_ID_GET_OTA_METADATA    12   /* Gets the OTA metadata information stored on the Flash memory */
#define SAIL_UPD_MSG_ID_SET_OTA_METADATA    13   /* Writes the OTA metadata information to the Flash memory */
#define SAIL_UPD_MSG_ID_UPDATE_ARB          14   /* Anti-Rollback Update */
#define SAIL_UPD_MSG_ID_UPDATE_MRC          15   /* MRC Update */
#define SAIL_UPD_MSG_READ_OTA_METADATA      16   /* Gets the OTA metadata information from the offset on the Flash memory */
#define SAIL_UPD_MSG_WRITE_OTA_METADATA     17   /* Writes the OTA metadata information to the offset on the Flash memory */
#define SAIL_UPD_MSG_ERASE_OTA_METADATA     18   /* Erase the OTA metadata information from the block info Provided */
#define SAIL_UPD_MSG_GET_OTA_METADATAINFO   19   /* Gets the OTA metadata information stored on the Flash memory */
#define SAIL_UPD_MSG_OTA_DONE               20   /* Sets the State to OTA_DONE to prevent rollback after successful OTA and stop retry count/ abort OTA from any state */
#define SAIL_UPD_MSG_REDUNDANCY_ESTABLISHED 21   /* Sets the State to OTA_DISABLED to abort OTA with 1+1 redundancy or after successful mirroring after OTA */
#define SAIL_UPD_MSG_GET_IMAGE_DIGEST		22   /* gets the image hash digest */

#define SAIL_UPD_MSG_TEST_ERROR_INJECTION   255  /* Trigger for the error injection on next command */

typedef enum
{
    SAIL_OTA_TRIG_NO_ERROR=0,                           /* no error state. No Error triggers */
    SAIL_OTA_TRIG_ERROR_PRE_INPROGRESS_FLASHIMG,        /* Error before starting to update IN_PROGRESS in book keeping */
    SAIL_OTA_TRIG_ERROR_WR_INPROGRESS_A,                /* Error while writing IN_PROGRESS to book keeping in Primary partition */
    SAIL_OTA_TRIG_ERROR_WR_INPROGRESS_B,                /* Error while writing IN_PROGRESS to book keeping in Secondary partition */
    SAIL_OTA_TRIG_ERROR_ER_FLASHIMG,                    /* Error while erasing partition while flashing image */
    SAIL_OTA_TRIG_ERROR_WR_FLASHIMG,                    /* Error while writing partition while flashing image */
    SAIL_OTA_TRIG_ERROR_RD_FLASHIMG,                    /* Error while reading partition while flashing image */
    SAIL_OTA_TRIG_ERROR_INVALIDALTGPT_PRE_UPDATEGPT,    /* Error due to Alternate GPT is invalid */
    SAIL_OTA_TRIG_ERROR_INVALIDGPT_PRE_UPDATEGPT,       /* Error due to Primary GPT is invalid before update GPT process */
    SAIL_OTA_TRIG_ERROR_WR_UPDATESTART_A,               /* Error while writing UPDATE_START to book keeping in Primary partition */
    SAIL_OTA_TRIG_ERROR_WR_UPDATESTART_B,               /* Error while writing UPDATE_START to book keeping in Secondary partition */
    SAIL_OTA_TRIG_ERROR_ER_GPTHDR_UPDATEGPT,            /* Error while erasing GPT Header while updating GPT */
    SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_UPDATEGPT,          /* Error while erasing GPT Partition Entries while updating GPT */
    SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_UPDATEGPT,          /* Error while writing GPT Partition Entries while updating GPT */
    SAIL_OTA_TRIG_ERROR_WR_GPTHDR_UPDATEGPT,            /* Error while writing GPT Header while updating GPT */
    SAIL_OTA_TRIG_ERROR_POST_UPDATEGPT,                 /* Error after update GPT process */
    SAIL_OTA_TRIG_ERROR_PRE_OTADONE,                    /* Error before starting to update OTA_DONE in bookkeeping */
    SAIL_OTA_TRIG_ERROR_WR_OTADONE_A,                   /* Error while writing OTA_DONE to book keeping in Primary partition */
    SAIL_OTA_TRIG_ERROR_WR_OTADONE_B,                   /* Error while writing OTA_DONE to book keeping in Secondary partition */
    SAIL_OTA_TRIG_ERROR_INVALIDALTGPT_PRE_FIXGPT,       /* Error due to Alternate GPT is invalid */
    SAIL_OTA_TRIG_ERROR_ER_GPTHDR_FIXGPT,               /* Error while erasing GPT Header while Fixing GPT */
    SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_FIXGPT,             /* Error while erasing GPT Partition Entries while Fixing GPT */
    SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_FIXGPT,             /* Error while writing GPT Partition Entries while Fixing GPT */
    SAIL_OTA_TRIG_ERROR_WR_GPTHDR_FIXGPT,               /* Error while writing GPT Header while Fixing GPT */
    SAIL_OTA_TRIG_ERROR_INVALIDGPT_POST_FIXGPT,         /* Error due to invalid GPTafter Fix GPT process */
    SAIL_OTA_TRIG_ERROR_PRE_OTADDISABLED_FIXGPT,        /* Error before starting to update OTA_DISABLED in bookkeeping */
    SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_A_FIXGPT,       /* Error while writing OTA_DISABLED to book keeping in Primary partition */
    SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_B_FIXGPT,       /* Error while writing OTA_DISABLED to book keeping in Secondary partition */
    SAIL_OTA_TRIG_ERROR_POST_FIXGPT,                    /* Error after FIX GPT process */
    SAIL_OTA_TRIG_ERROR_PRE_REDUNDANCY,                 /* Error before starting to update OTA_DISABLED in bookkeeping */
    SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_A_REDUNDANCY,   /* Error while writing OTA_DISABLED to book keeping in Primary partition */
    SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_B_REDUNDANCY,   /* Error while writing OTA_DISABLED to book keeping in Secondary partition */
    SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_A,           /* Corrupt the bookkeeping partition A's last entry */
    SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_A,       /* Corrupt the bookkeeping partition A's mid entry */
    SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_B,           /* Corrupt the bookkeeping partition B's last entry */
    SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_B,       /* Corrupt the bookkeeping partition B's mid entry */
    SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_AB,          /* Corrupt the bookkeeping partition A and B 's last entry */
    SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_AB,      /* Corrupt the bookkeeping partition A and B's mid entry */
    SAIL_OTA_TRIG_CORRUPT_PRIMARYGPT_NON_UPDATESTART,   /* Corrupt the Primary GPT in non-updatestart state */
    SAIL_OTA_TRIG_ERROR_PRE_FIXGPTCORRUPTION_XBL,       /* Error before fixGPT corruption in XBL */
    SAIL_OTA_TRIG_ERROR_ER_FIXGPTCCORRUPTION_XBL,       /* Error while erase during fixGPT corruption in XBL */
    SAIL_OTA_TRIG_ERROR_WR_ENTRY_FIXGPTCCORRUPTION_XBL, /* Error while writing partition entry during fixGPT corruption in XBL */
    SAIL_OTA_TRIG_ERROR_WR_HDR_FIXGPTCCORRUPTION_XBL,   /* Error while writing Header entry during fixGPT corruption in XBL */
    SAIL_OTA_TRIG_ERROR_POST_FIXGPTCORRUPTION_XBL,      /* Error post fixGPT corruption in XBL */
    SAIL_OTA_TRIG_ERROR_PRE_GPT_ROLLBACK,               /* Error before attempting Rollback in XBL (in Booting state) */
    SAIL_OTA_TRIG_ERROR_ER_GPT_ROLLBACK_XBL,            /* Error while erase during Rollback in XBL */
    SAIL_OTA_TRIG_ERROR_WR_ENTRY_GPT_ROLLBACK_XBL,      /* Error while writing partition entry during Rollback in XBL */
    SAIL_OTA_TRIG_ERROR_WR_HDR_GPT_ROLLBACK_XBL,        /* Error while writing Header entry during Rollback in XBL */
    SAIL_OTA_TRIG_ERROR_POST_GPT_ROLLBACK,              /* Error post Rollback in XBL before writing state */
    SAIL_OTA_TRIG_ERROR_PRE_ROLLBACK,                   /* Error before updating rollback to bookkeeping in XBL */
    SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_A,                  /* Error while writing ROLLBACK to book keeping in Primary partition */
    SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_B,                  /* Error while writing ROLLBACK to book keeping in Secondary partition */
    SAIL_OTA_TRIG_ERROR_POST_ROLLBACK,                  /* Error after writing ROLLBACK to bookeeping in XBL */
    SAIL_OTA_TRIG_ERROR_MAX                             /* MAX value */
}sailUpdaterErrorTriggerIdType;


#define SAIL_UPD_STATUS_SUCCESS           0
#define SAIL_UPD_STATUS_ERROR             1

#define SAIL_UPD_MD2SAIL                  0
#define SAIL_UPD_SAIL2MD                  1

#define SAIL_UPD_GPT_ID_PRIMARY           0
#define SAIL_UPD_GPT_ID_SECONDARY         1
#define SAIL_UPD_GPT_ID_MAX               2

#define SAIL_UPD_PARTITION_ID_PRIMARY     0
#define SAIL_UPD_PARTITION_ID_SECONDARY   1
#define SAIL_UPD_PARTITION_ID_MAX         2

#define SAIL_UPD_OTA_IN_PROGRESS          0x0  /* Flashing to a B partition initiated. Don’t use B for normal boot */
#define SAIL_UPD_OTA_UPDATE_START         0x1  /* OTA about to start update Primary GPT  */
#define SAIL_UPD_OTA_BOOTING              0x2  /* OTA boot in progress. In xbl if state is update start and GPT primary is healthy and GPT primary not equal to GPT secondary then change state to booting and update retry cnt */
#define SAIL_UPD_OTA_ROLLBACK             0x3  /* OTA boot failed. Rollback in progress */
#define SAIL_UPD_OTA_DISABLED             0x4  /* OTA not initiated. Regular boot */
#define SAIL_UPD_OTA_DONE                 0x5  /* OTA state with no 1+1 redundancy */

#define SAIL_UPD_IMAGE_DIGEST_MAX_LEN	  128  /* image digest max len */

typedef struct {
  uint8_t  hello[SAIL_UPD_IMG_NAME_LEN];        /* Must be "HELLO" with NULL termination. It is case sensitive */
  uint32_t mailboxVersionMajor;                 /* Must be 0x1 */
  uint32_t mailboxVersionMinor;                 /* Must be 0x0 */
} __attribute__((packed)) sailUpdaterHelloMsgType;

typedef struct {
  uint32_t primaryGptHeaderCrcStatus;           /* 0 - error, 1 - pass */
  uint32_t primaryGptEntryCrcStatus;            /* 0 - error, 1 - pass */
  uint32_t primaryGptSize;                      /* in bytes            */
  uint32_t secondaryGptHeaderCrcStatus;         /* 0 - error, 1 - pass */
  uint32_t secondaryGptEntryCrcStatus;          /* 0 - error, 1 - pass */
  uint32_t secondaryGptSize;                    /* in bytes            */
  uint32_t primaryGptPartitionEntryCrc;         /* CRC32 of partition entry array. */
  uint32_t secondaryGptPartitionEntryCrc;       /* CRC32 of partition entry array. */
} __attribute__((packed)) sailUpdaterCheckGptMsgType;

typedef struct {
  uint32_t id;                                  /* GPT ID: 0 - primary, 1 - secondary */
  uint32_t bufAddr;                             /* DDR buffer address */
  uint32_t bufLen;                              /* DDR buffer length. Length has to be cacheline size Aligned */
  uint32_t bufCrc;                              /* DDR buffer CRC using IEEE-802.3 CRC32 Ethernet Standard */
} __attribute__((packed)) sailUpdaterReadGptMsgType;

typedef struct {
  uint32_t id;                                  /* GPT ID: 0 - primary, 1 - secondary */
  uint32_t bufAddr;                             /* DDR buffer address */
  uint32_t bufLen;                              /* DDR buffer length. Length has to be cacheline size Aligned */
  uint32_t bufCrc;                              /* DDR buffer CRC using IEEE-802.3 CRC32 Ethernet Standard */
} __attribute__((packed)) sailUpdaterWriteGptMsgType;

typedef struct
{
    uint8_t id;              /* GPT ID: 0 - primary, 1 - secondary */
    uint8_t reserved[2];     /* Reserved */
    uint8_t fixtype;         /* fixtype: 0 - update state based on state(if not in SAIL_UPD_OTA_IN_PROGRESS or SAIL_UPD_OTA_UPDATE_START),
                                         1 - skip updating the state to disabled */
} __attribute__((packed)) fixgptidext_t;

typedef struct {
    union {
        uint32_t id;                            /* GPT ID: 0 - primary, 1 - secondary */
        fixgptidext_t ext_id;                   /* Extended ID*/
    };
  uint32_t bufAddr;                             /* DDR buffer address which is used as work buffer in fix GPT command */
  uint32_t bufLen;                              /* DDR buffer length. Length has to be cacheline size Aligned.
                                                 * The size must be equal or larger than 2 times the GPT table size */
} __attribute__((packed)) sailUpdaterFixGptMsgType;

typedef struct {
  uint8_t  imgName[SAIL_UPD_IMG_NAME_LEN];      /* including NULL termination. It is case sensitive */
  uint32_t partitionSwapType;                   /* Image partition swapping type: 0 - A and B offset swapping, other value are reserved */
} __attribute__((packed)) sailUpdaterMsgUpdateGptEntryType;

typedef struct {
  uint32_t id;                                  /* GPT ID: 0 - primary, 1 - secondary */
  uint32_t num;                                 /* Number of partitions to be swapped between A and B */
  uint32_t bufAddr;                             /* DDR buffer address. Cast to sailUpdaterMsgUpdateGptEntryType
                                                 * to get the array of entries */
  uint32_t bufLen;                              /* DDR buffer length. Length has to be cacheline size Aligned
                                                   Buffer length should atleast ( num*sizeof(sailUpdaterMsgUpdateGptEntryType) + 24K used for Work buffer) */
  uint32_t bufCrc;                              /* DDR buffer CRC using IEEE-802.3 CRC32 Ethernet Standard.
                                                 * bufCrc is ran by (num*sizeof(sailUpdaterMsgUpdateGptEntryType)). Padding zero is needed.  */
} __attribute__((packed)) sailUpdaterUpdateGptMsgType;

typedef struct {
  uint8_t  imgName[SAIL_UPD_IMG_NAME_LEN];         	/* including NULL termination. It is case sensitive */
  uint32_t partitionType;                   		/* Image partition type: 0 - A and 1 - B, other value are reserved */
  uint32_t digestType;                   			/* digest type - 256, 384, 512 */
  uint32_t digestLen;                   			/* digest len */
  uint8_t  digest[SAIL_UPD_IMAGE_DIGEST_MAX_LEN];   /* for available std Max digest charcters go upto 128 , variable payload buffer */
} __attribute__((packed)) sailUpdaterMsgImgDigestEntryType;

typedef struct {
	uint32_t num_images;						   	/* number images digest requested */
	uint32_t bufAddr;                             	/* DDR buffer address. Cast to sailUpdaterMsgImgDigestEntryType
													 * to get the array of entries. Address has to be cacheline Aligned */
    uint32_t bufLen;                               	/* DDR buffer length. Length has to be cacheline Aligned*/
    uint32_t bufCrc;                              	/* DDR buffer CRC using IEEE-802.3 CRC32 Ethernet Standard.
													* bufCrc is ran by bufLen. Padding zero is needed.  */
} __attribute__((packed)) sailUpdaterImgDigestMsgType;

typedef struct {
  uint8_t  imgName[SAIL_UPD_IMG_NAME_LEN];        /* including NULL termination */
  uint32_t bootPartition;                       /* Boot partition entry ID (A or B) : 0 - A partition, 1 - B partition.
                                                 * If the partition is not A, OTA update should not be attempted.  */
  uint32_t bootGptId;                           /* Boot GPT ID: 0 - Primary, 1 - secondary.
                                                 * If bootGptId is not 0 (primary), OTA update should not be attempted. */
  uint32_t partitionSizeA;                      /* the maximum size of partition A in bootGptId table */
  uint32_t partitionSizeB;                      /* the maximum size of partition B in bootGptId table */
  uint32_t isTwoGptTableEntriesMatching;        /* 0 - error, 1 - Primary GPT table's two entries match secondary GPT table's two entries */
} __attribute__((packed)) sailUpdaterImageEntryType;

typedef struct {
  uint32_t num_images;
  uint32_t bufAddr;                             /* DDR buffer address. Cast to sailUpdaterImageEntryType
                                                 * to get the array of entries. Address has to be cacheline Aligned */
  uint32_t bufLen;                              /* DDR buffer length. Length has to be cacheline Aligned*/
  uint32_t bufCrc;                              /* DDR buffer CRC using IEEE-802.3 CRC32 Ethernet Standard.
                                                 * bufCrc is ran by bufLen. Padding zero is needed.  */
} __attribute__((packed)) sailUpdaterQueryImageMsgType;

typedef struct {
  uint8_t  imgName[SAIL_UPD_IMG_NAME_LEN];      /* including NULL termination */
  uint32_t readPartition;                       /* Read partition entry ID (A or B) : 0 - A partition, 1 - B partition */
  uint32_t readGptId;                           /* Read GPT ID: 0 - Primary, 1 - secondary */
  uint32_t bufAddr;                             /* DDR image address */
  uint32_t bufLen;                              /* DDR image length. Length has to be cacheline size Aligned */
  uint32_t bufCrc;                              /* DDR image CRC using IEEE-802.3 CRC32 Ethernet Standard */
} __attribute__((packed)) sailUpdaterReadImgMsgType;

typedef struct
{
    uint8_t FlashPartition;              /* Flash partition ID : 0 – A Partition, 1 – B Partition */
    uint8_t reserved[2];     /* Reserved */
    uint8_t flashtype;       /* flashtype: 0 - if image A not equal to new B, change to SAIL_UPD_OTA_IN_PROGRESS,
                                           1 - Flash Image without OTA state change
                                           2 - Flash Image and change OTA_STATE to  SAIL_UPD_OTA_IN_PROGRESS */
} __attribute__((packed)) flashimgpartitionext_t;

typedef struct {
  uint8_t  imgName[SAIL_UPD_IMG_NAME_LEN];      /* including NULL termination */
  union {
      uint32_t FlashPartition;                  /* Flash partition entry ID (A or B) : 0 - A partition, 1 - B partition */
      flashimgpartitionext_t ext_id;            /* Extended ID */
  };
  uint32_t FlashGptId;                          /* Flash GPT ID: 0 - Primary, 1 - secondary */
  uint32_t bufAddr;                             /* DDR image address */
  uint32_t bufLen;                              /* DDR image length. Length has to be cacheline size Aligned */
  uint32_t bufCrc;                              /* DDR image CRC using IEEE-802.3 CRC32 Ethernet Standard */
} __attribute__((packed)) sailUpdaterFlashImgMsgType;

typedef struct {
  uint32_t primaryGptHeaderCrcStatus;           /* 0 - error, 1 - pass */
  uint32_t primaryGptEntryCrcStatus;            /* 0 - error, 1 - pass */
  uint32_t primaryGptSize;                      /* in bytes            */
  uint32_t secondaryGptHeaderCrcStatus;         /* 0 - error, 1 - pass */
  uint32_t secondaryGptEntryCrcStatus;          /* 0 - error, 1 - pass */
  uint32_t secondaryGptSize;                    /* in bytes            */
  sailUpdaterQueryImageMsgType imgInfo;         /* Boot Information of the images */
  uint32_t primaryGptPartitionEntryCrc;         /* CRC32 of partition entry array. */
  uint32_t secondaryGptPartitionEntryCrc;       /* CRC32 of partition entry array. */
  uint32_t otaState:7;                          /* State of the OTA */
  uint32_t logicGuidASwapped:1;                 /* GUID Mapping of the GPT1's GUIDA .Is the GPT1’s GUID_A physical offset swapped from original mem map*/
  uint32_t reserved:24;                         /* Reserved fields to align to 32bits */
} __attribute__((packed)) sailUpdaterGetBootInfoMsgType;

typedef struct {
  uint32_t bufAddr;                             /* DDR image address */
  uint32_t bufLen;                              /* DDR image length. Length has to be cacheline size Aligned */
  uint32_t bufCrc;                              /* DDR image CRC using IEEE-802.3 CRC32 Ethernet Standard */
} __attribute__((packed)) sailUpdaterGetOTAMetaDataMsgType;

typedef struct {
  uint32_t bufAddr;                             /* DDR image address */
  uint32_t bufLen;                              /* DDR image length. Length has to be cacheline size Aligned */
  uint32_t bufCrc;                              /* DDR image CRC using IEEE-802.3 CRC32 Ethernet Standard */
} __attribute__((packed)) sailUpdaterSetOTAMetaDataMsgType;

typedef struct {
 uint32_t bufAddr;                              /* DDR image address */
 uint32_t bufLen;                               /* DDR image length. Length has to be cacheline size Aligned */
 uint32_t bufCrc;                               /* DDR image CRC using IEEE-802.3 CRC32 Ethernet Standard */
 uint32_t offset;                               /* offset from where the data will be read within the
                                                   partition. Needs to be 16 byte aligned */
 uint32_t size;                                 /* Needs to be 16 byte aligned. size should be <= bufLen <=
                                                   partition size */
} __attribute__((packed)) sailUpdaterReadOTAMetaDataMsgType;

typedef struct {
 uint32_t bufAddr;                              /* DDR image address */
 uint32_t bufLen;                               /* DDR image length. Length has to be cacheline size Aligned */
 uint32_t bufCrc;                               /* DDR image CRC using IEEE-802.3 CRC32 Ethernet Standard */
 uint32_t offset;                               /* offset where the data will be written within the partition.
                                                   Needs to be 16 byte aligned */
 uint32_t size;                                 /* Needs to be 16 byte aligned. size should be <= bufLen <=
                                                   partition size*/
} __attribute__((packed)) sailUpdaterWriteOTAMetaDataMsgType;

typedef struct {
 uint32_t start_block;                          /* Start block number to start erasing within the
                                                   partition. Block number should be 4k chunks within the
                                                   partition. 0 for offset 0 within the partition. start
                                                   block should align with the natural sector boundary */
 uint32_t block_cnt;                            /* Number of 4k blocks to be erased within the partition. The
                                                   block_cnt should align with the natural sector boundary.*/
} __attribute__((packed)) sailUpdaterEraseOTAMetaDataMsgType;

typedef struct {
 uint32_t offset_start_range;                   /* Offset start within the partition */
 uint32_t offset_end_range;                     /* Offset end within the partition */
 uint32_t erase_size_kB;                        /* Erase granularity within the region */
}__attribute__((packed)) OTAMetaDataSectorMapInfoType;

typedef struct {
 uint32_t partition_size;                       /* Size of the partition in KB */
 OTAMetaDataSectorMapInfoType sectorMap[3];     /* Sector Map Info of the partition */
} __attribute__((packed)) sailUpdaterGetOTAMetaDataInfoMsgType;

typedef struct {
  uint8_t  imgName[SAIL_UPD_IMG_NAME_LEN];      /* including NULL termination */
  uint32_t bootPartition;                       /* Boot partition entry ID (A or B) : 0 - A partition, 1 - B partition */
  uint32_t bootGptId;                           /* Boot GPT ID: 0 - Primary, 1 - secondary */
  uint32_t bufAddr;                             /* DDR image address */
  uint32_t bufLen;                              /* DDR image length. Length has to be cacheline size Aligned*/
  uint32_t bufCrc;                              /* DDR image CRC using IEEE-802.3 CRC32 Ethernet Standard */
} __attribute__((packed)) sailUpdaterBootImgMsgType;

typedef struct {
  uint32_t data1;                               /* Reserved for any data passed */
  uint32_t data2;                               /* Reserved for any data passed */
  uint32_t data3;                               /* Reserved for any data passed */
  uint32_t data4;                               /* Reserved for any data passed */
} __attribute__((packed)) sailUpdaterOTADoneMsgType;

typedef struct {
  uint32_t data1;                               /* Reserved for any data passed */
  uint32_t data2;                               /* Reserved for any data passed */
  uint32_t data3;                               /* Reserved for any data passed */
  uint32_t data4;                               /* Reserved for any data passed */
} __attribute__((packed)) sailUpdaterRedundancyMsgType;

typedef struct {
  uint32_t data1;                               /* Reserved for any data passed */
  uint32_t data2;                               /* Reserved for any data passed */
  uint32_t data3;                               /* Reserved for any data passed */
  uint32_t data4;                               /* Reserved for any data passed */
} __attribute__((packed)) sailUpdaterARBUpdateMsgType;

typedef struct {
  uint32_t data1;                               /* Reserved for any data passed */
  uint32_t data2;                               /* Reserved for any data passed */
  uint32_t data3;                               /* Reserved for any data passed */
  uint32_t data4;                               /* Reserved for any data passed */
} __attribute__((packed)) sailUpdaterMRCUpdateMsgType;

typedef struct {
  uint32_t enable;                              /* Enable trigger for the test: 1-Enable, 0-Disable */
  uint32_t triggerID;                           /* Test trigger ID. Should be non 0 and less than the max supported if enable is 1
                                                    0 if enable is 0 */
  uint32_t reserved[4];                         /* Reserved for any data passed */
} __attribute__((packed)) sailUpdaterOTATestTriggerMsgType;

typedef struct {
  uint32_t headerCrc;                           /* message CRC using IEEE-802.3 CRC32 Ethernet Standard */
  uint32_t headerSize;                          /* message header size in bytes including msgCRC */
  uint32_t msgId;                               /* SAIL_UPDATE_MB_MSG_ID_<X_Y> */
  uint32_t direction;                           /* 0 - TO_SAIL, 1 - FROM_SAIL */
  uint32_t status;                              /* response status code such as SAIL_UPDATE_MB_STATUS_SUCCESS */
  union {
    sailUpdaterHelloMsgType            hello;
    sailUpdaterCheckGptMsgType         checkGpt;
    sailUpdaterReadGptMsgType          readGpt;         /*  Only for debug purpose. Disabled in mission mode */
    sailUpdaterWriteGptMsgType         writeGpt;        /*  Only for debug purpose. Disabled in mission mode */
    sailUpdaterFixGptMsgType           fixGpt;
    sailUpdaterUpdateGptMsgType        updateGpt;
    sailUpdaterQueryImageMsgType       queryImg;
    sailUpdaterGetBootInfoMsgType      bootInfo;
    sailUpdaterReadImgMsgType          readImg;
    sailUpdaterFlashImgMsgType         flashImg;
    sailUpdaterGetOTAMetaDataMsgType   getMetaData;
    sailUpdaterSetOTAMetaDataMsgType   setMetaData;
    sailUpdaterReadOTAMetaDataMsgType  readMetaData;
    sailUpdaterWriteOTAMetaDataMsgType writeMetaData;
    sailUpdaterEraseOTAMetaDataMsgType eraseMetaData;
    sailUpdaterGetOTAMetaDataInfoMsgType getMetaDataInfo;
    sailUpdaterBootImgMsgType          bootImg;
    sailUpdaterOTADoneMsgType          otaDone;
    sailUpdaterRedundancyMsgType       redundancy;
    sailUpdaterARBUpdateMsgType        arbData;
    sailUpdaterMRCUpdateMsgType        mrcData;
	sailUpdaterImgDigestMsgType        getImgDigest;
    sailUpdaterOTATestTriggerMsgType   testTrigger;
  };
} __attribute__((packed)) sailUpdaterMsgHeaderType;


/*----------------------------------------------------------------------------
 *                                  END
 *--------------------------------------------------------------------------*/
#endif /* __SAIL_UPDATER_MSGTYPES_H__ */
