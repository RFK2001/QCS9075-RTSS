/*===========================================================================
 Copyright (c) Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
#ifndef SAIL_SEC_FUSE_INFO_H
#define SAIL_SEC_FUSE_INFO_H

typedef enum {
	OEMFUSE_DBGEN = 0,
	OEMFUSE_NIDEN,
	OEMFUSE_HIDEN,
	OEMFUSE_HNIDEN,
	OEMFUSE_C0_DBGEN,
	OEMFUSE_C0_NIDEN,
	OEMFUSE_C1_DBGEN,
	OEMFUSE_C1_NIDEN,
	OEMFUSE_C2_DBGEN,
	OEMFUSE_C2_NIDEN,
	OEMFUSE_C3_DBGEN,
	OEMFUSE_C3_NIDEN,
	OEMFUSE_CPU_SCAN_EN,
	OEMFUSE_DCC_SCAN_EN,
	OEMFUSE_WDOG_EN,
	OEMFUSE_OEM_SECURE_BOOTN_AUTH_EN,
	OEMFUSE_ANTI_ROLLBACK_FEATURE_HYP_EN, 
	OEMFUSE_ANTI_ROLLBACK_FEATURE_SW_EN,
	OEMFUSE_OEM_SEC_BOOT_FEC_EN,
	OEMFUSE_OEM_SEC_BOOT_WRITE_DIS,
	OEMFUSE_MAX_BITSTATUS_ID
}OEMFuseStatus_t;

typedef enum {
	OEMFUSE_ROOT_CERT_ACTIVATION_LIST= 0,
	OEMFUSE_ROOT_CERT_REVOCATION_LIST,
	OEMFUSE_ANTI_ROLLBACK_HYP_LSB,
	OEMFUSE_ANTI_ROLLBACK_HYP_MSB,
	OEMFUSE_ANTI_ROLLBACK_SW1_LSB,
	OEMFUSE_ANTI_ROLLBACK_SW1_MSB,
	OEMFUSE_ANTI_ROLLBACK_SW2_LSB,
	OEMFUSE_ANTI_ROLLBACK_SW2_MSB,
	OEMFUSE_ANTI_ROLLBACK_SW3_LSB,
	OEMFUSE_ANTI_ROLLBACK_SW3_MSB,
	OEMFUSE_ANTI_ROLLBACK_SW4_LSB,
	OEMFUSE_ANTI_ROLLBACK_SW4_MSB,
	OEMFUSE_ANTI_ROLLBACK_DEBUG_POLICY,
	OEMFUSE_PK_HASH0_0,
	OEMFUSE_PK_HASH0_1,
	OEMFUSE_PK_HASH0_2,
	OEMFUSE_PK_HASH0_3,
	OEMFUSE_PK_HASH0_4,
	OEMFUSE_PK_HASH0_5,
	OEMFUSE_PK_HASH0_6,
	OEMFUSE_PK_HASH0_7,
	OEMFUSE_PK_HASH0_8,
	OEMFUSE_PK_HASH0_9,
	OEMFUSE_PK_HASH0_10,
	OEMFUSE_PK_HASH0_11,
	OEMFUSE_PK_HASH0_12,
	OEMFUSE_PK_HASH0_13,
	OEMFUSE_PK_HASH0_14,
	OEMFUSE_PK_HASH0_15,
	OEMFUSE_MAX_VALUE_ID
}OEMFuseValue_t;

#define IS_BIT_SET(x, bit) ((((x) & (1UL << (bit))) != 0UL) ? 1U : 0U)
#define SET_BIT(x, bit) ((x) | (1UL << (bit)))

/*
 *@brief Returns Fuse Register Value as per the input Fuse Enum
 *
 *@param[in] oemFuseid - Enum Value of Fuse register as per OEMFuseValue_t that needs to be read
 *@param[out] value - Buffer to store the Fuse Register data
 *
 *@return E_NOT_SUPPORTED -  Error while reading bits/Invalid input.
 *        E_NOT_ALLOWED - Error if the Fuse is read protected
 *        E_SUCCESS -  Reading Fuse Status success
 */
int32_t secboot_oem_fuse_value(OEMFuseValue_t oemFuseid, uint32_t *value);

/*
 *@brief Returns Fuse BIT Status as per the input Fuse Bits list
 *
 *@param[in] inFuseList - List of bits as per OEMFuseStatus_t whose Fuse Status needs to be read
 *@param[out] status - Buffer to store the Fuse Status
 *
 *@return E_NOT_SUPPORTED -  Error while reading bits/Invalid input.
 *        E_NOT_ALLOWED - Error if any one of the Fuse in the list is read protected
 *        E_SUCCESS -  Reading Fuse Status success
 */
int32_t secboot_oem_fuse_status(uint32_t inFuseList, uint32_t *status);

#endif /* SAIL_SEC_FUSE_INFO_H */
