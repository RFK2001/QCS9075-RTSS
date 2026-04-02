/* ===========================================================================
 * Copyright (c) 2022 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ===========================================================================
 */

#ifndef HWKM_ERR_H
#define HWKM_ERR_H

#include <stdint.h>

/** SW HAL error codes */
#define HWKM_SUCCESS                                      INT32_C(0)
#define HWKM_ERR_GENERIC                                  INT32_C(1)
#define HWKM_NOT_SUPPORTED                                INT32_C(2)
#define HWKM_INVALID_ARG                                  INT32_C(3)
#define HWKM_NO_MEMORY                                    INT32_C(4)
#define HWKM_INVALID_DESTINATION                          INT32_C(5)
#define HWKM_CMD_FIFO_NOT_EMPTY                           INT32_C(6)
#define HWKM_CMD_FIFO_TIMEOUT                             INT32_C(7)
#define HWKM_RESPONSE_UNDERFLOW                           INT32_C(8)
#define HWKM_RESPONSE_OVERFLOW                            INT32_C(9)
#define HWKM_RSP_FIFO_TIMEOUT                             INT32_C(10)
#define HWKM_CLK_ERROR                                    INT32_C(11)
#define HWKM_SET_TPKEY_FAILURE                            INT32_C(12)
#define HWKM_PROVISION_HW_KEY_FAILURE                     INT32_C(13)

/** Generates a mask with only this err bit */
#define HWKM_ERR_BIT(bit) (UINT32_C(1) << (bit))

/** Check if this err bit is set in the error status */
#define HWKM_IS_ERR_SET(status, err) (((status) & (err)) != 0)

/** SUCCESS code in status field of response packet */
#define HWKM_TRANSACTION_SUCCESS                          UINT32_C(0)

/** HWKM Error Codes common to all opcodes */
#define HWKM_COMMON_ERR_RESP_FIFO_UNDERFLOW               HWKM_ERR_BIT(0)
#define HWKM_COMMON_ERR_CMD_FIFO_OVERFLOW                 HWKM_ERR_BIT(1)
#define HWKM_COMMON_ERR_OPCODE_NOT_SUPPORTED              HWKM_ERR_BIT(2)
#define HWKM_COMMON_ERR_INVALID_OPCODE                    HWKM_ERR_BIT(3)
#define HWKM_COMMON_ERR_INCORRECT_CMD_LENGTH              HWKM_ERR_BIT(4)
#define HWKM_COMMON_ERR_CMD_CRC_CHECK                     HWKM_ERR_BIT(5)
#define HWKM_COMMON_ERR_BBAC_ACCESS                       HWKM_ERR_BIT(6)
#define HWKM_COMMON_ERR_RESERVED                          HWKM_ERR_BIT(7)

/* Common internal errors */
#define HWKM_COMMON_ERR_INTERNAL (HWKM_COMMON_ERR_RESP_FIFO_UNDERFLOW | \
                                  HWKM_COMMON_ERR_CMD_FIFO_OVERFLOW | \
                                  HWKM_COMMON_ERR_OPCODE_NOT_SUPPORTED | \
                                  HWKM_COMMON_ERR_INVALID_OPCODE | \
                                  HWKM_COMMON_ERR_INCORRECT_CMD_LENGTH | \
                                  HWKM_COMMON_ERR_CMD_CRC_CHECK | \
                                  HWKM_COMMON_ERR_BBAC_ACCESS)

/** NIST_KEYGEN errors */
/* DKS key slot id is out of range */
#define HWKM_KEYGEN_ERR_KEYSLOT_ID_OUT_OF_RANGE           HWKM_ERR_BIT(8)
/* Key size is not supported */
#define HWKM_KEYGEN_ERR_UNSUPPORTED_KEY_SIZE              HWKM_ERR_BIT(9)
/* Integrity error. Memory has been attacked */
#define HWKM_KEYGEN_ERR_KT_PARITY                         HWKM_ERR_BIT(10)
/* Write Op: Key type is not part of the Spec list */
#define HWKM_KEYGEN_ERR_INVALID_KEY_TYPE                  HWKM_ERR_BIT(11)
/* Write Op: ALG is not part of the Spec list */
#define HWKM_KEYGEN_ERR_INVALID_ALG_ALLOWED               HWKM_ERR_BIT(12)
/* Other: Consistency check failed */
#define HWKM_KEYGEN_ERR_CONSISTENCY_CHECK_FAILED          HWKM_ERR_BIT(13)
/* TPKEY: Consistency check failed */
#define HWKM_KEYGEN_ERR_INVALID_TPKEY_ATTRIB              HWKM_ERR_BIT(14)
/* KSK: Consistency check failed */
#define HWKM_KEYGEN_ERR_INVALID_KSK_ATTRIB                HWKM_ERR_BIT(15)
/* KWK: Consistency check failed */
#define HWKM_KEYGEN_ERR_INVALID_KWK_ATTRIB                HWKM_ERR_BIT(16)
/* KDK: Consistency check failed */
#define HWKM_KEYGEN_ERR_INVALID_KDF_DEPTH                 HWKM_ERR_BIT(17)
/* Write Op: Security Level is not part of the Spec list */
#define HWKM_KEYGEN_ERR_INVALID_SECURITY_LEVEL            HWKM_ERR_BIT(18)
/* Key slot ID pointed to by the DKS in the command packet is not empty */
#define HWKM_KEYGEN_ERR_DKS_SLOT_NOT_EMPTY                HWKM_ERR_BIT(19)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_KEYGEN_ERR_ACCESS_VIOLATION                  HWKM_ERR_BIT(20)

/* NIST_KEYGEN internal errors */
#define HWKN_KEYGEN_ERR_INTERNAL (HWKM_COMMON_ERR_INTERNAL | \
                                  HWKM_KEYGEN_ERR_KT_PARITY)

/** KEYSLOT_RDWR errors */
/* DKS key slot id is out of range */
#define HWKM_RDWR_ERR_KEYSLOT_ID_OUT_OF_RANGE             HWKM_ERR_BIT(8)
/* Key size is not supported */
#define HWKM_RDWR_ERR_UNSUPPORTED_KEY_SIZE                HWKM_ERR_BIT(9)
/* Integrity error. Memory has been attacked */
#define HWKM_RDWR_ERR_KT_PARITY                           HWKM_ERR_BIT(10)
/* Write Op: Security Level is not part of the Spec list */
#define HWKM_RDWR_ERR_INVALID_SECURITY_LEVEL              HWKM_ERR_BIT(11)
/* Write Op: Key type is not part of the Spec list */
#define HWKM_RDWR_ERR_INVALID_KEY_TYPE                    HWKM_ERR_BIT(12)
/* Write Op: ALG is not part of the Spec list */
#define HWKM_RDWR_ERR_INVALID_ALG_ALLOWED                 HWKM_ERR_BIT(13)
/* Other: Consistency check failed */
#define HWKM_RDWR_ERR_CONSISTENCY_CHECK_FAILED            HWKM_ERR_BIT(14)
/* TPKEY: Consistency check failed */
#define HWKM_RDWR_ERR_INVALID_TPKEY_ATTRIB                HWKM_ERR_BIT(15)
/* KSK: Consistency check failed */
#define HWKM_RDWR_ERR_INVALID_KSK_ATTRIB                  HWKM_ERR_BIT(16)
/* KWK: Consistency check failed */
#define HWKM_RDWR_ERR_INVALID_KWK_ATTRIB                  HWKM_ERR_BIT(17)
/* KDK: Consistency check failed */
#define HWKM_RDWR_ERR_INVALID_KDF_DEPTH                   HWKM_ERR_BIT(18)
/* Security level of Reader is lower than the read Key Policy */
#define HWKM_RDWR_ERR_SECURITY_LEVEL_VIOLATION            HWKM_ERR_BIT(19)
/* Key slot ID pointed to by the SKS in the command packet is empty */
#define HWKM_RDWR_ERR_SKS_SLOT_EMPTY                      HWKM_ERR_BIT(20)
/* Key slot ID pointed to by the DKS in the command packet is not empty */
#define HWKM_RDWR_ERR_DKS_SLOT_NOT_EMPTY                  HWKM_ERR_BIT(21)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_RDWR_ERR_ACCESS_VIOLATION                    HWKM_ERR_BIT(22)

/* KEYSLOT_RDWR internal errors */
#define HWKN_RDWR_ERR_INTERNAL (HWKM_COMMON_ERR_INTERNAL | \
                                  HWKM_RDWR_ERR_KT_PARITY)

/** SYSTEM_KDF errors */
/* Fuse region read not supported on slave */
#define HWKM_KDF_ERR_FR_RD_ERR_ON_SLAVE                   HWKM_ERR_BIT(8)
/* L1/L2 keys are not allowed as mixing key */
#define HWKM_KDF_ERR_MKS_L1L2_NOT_ALLOWED                 HWKM_ERR_BIT(9)
/* Security Control interface error */
#define HWKM_KDF_ERR_SEC_CTRL_ACCESS                      HWKM_ERR_BIT(10)
/* Integrity error. Memory has been attacked */
#define HWKM_KDF_ERR_KT_PARITY                            HWKM_ERR_BIT(11)
/* BSVE bit is not supported */
#define HWKM_KDF_ERR_BSVE_BIT_NOT_SUPPORTED               HWKM_ERR_BIT(12)
/* Write Op: Security Level is not part of the Spec list */
#define HWKM_KDF_ERR_INVALID_SECURITY_LEVEL               HWKM_ERR_BIT(13)
/* Write Op: Key type is not part of the Spec list */
#define HWKM_KDF_ERR_INVALID_KEY_TYPE                     HWKM_ERR_BIT(14)
/* Write Op: ALG is not part of the Spec list */
#define HWKM_KDF_ERR_INVALID_ALG_ALLOWED                  HWKM_ERR_BIT(15)
/* Swap export: swap_export_allowed check failed */
#define HWKM_KDF_ERR_SWAP_EXPORT_NOT_ALLOWED              HWKM_ERR_BIT(16)
/* invalid_kdf_depth, invalid_[kwk/ksk/tpkey/key_type_other]_attrib */
#define HWKM_KDF_ERR_KEYPOLICY_CONSISTENCY                HWKM_ERR_BIT(17)
/* Key cannot be encrypted */
#define HWKM_KDF_ERR_ENCRYPT_NOT_ALLOWED                  HWKM_ERR_BIT(18)
/* Unexpected algorithm for the key */
#define HWKM_KDF_ERR_UNEXPECTED_ALG_ALLOWED               HWKM_ERR_BIT(19)
/* Unexpected key type */
#define HWKM_KDF_ERR_UNEXPECTED_KEY_TYPE                  HWKM_ERR_BIT(20)
/* KDF depth error */
#define HWKM_KDF_ERR_KDF_DEPTH_ERROR                      HWKM_ERR_BIT(21)
/* Wrong key type */
#define HWKM_KDF_ERR_KDK_TYPE                             HWKM_ERR_BIT(22)
/* Wrong key size */
#define HWKM_KDF_ERR_KEY_SIZE                             HWKM_ERR_BIT(23)
/* km_err_dks_slot_not_empty, km_err_[sks/mks]_slot_empty */
#define HWKM_KDF_ERR_KEYSLOT_SLOT                         HWKM_ERR_BIT(24)
/* [dks/mks/kdk]_out_of_range */
#define HWKM_KDF_ERR_KEYSLOT_OUT_OF_RANGE                 HWKM_ERR_BIT(25)
/* Derived key is 512-bits and DKS is not even */
#define HWKM_KDF_ERR_DOUBLE_KEY_SLOT_NOT_EVEN             HWKM_ERR_BIT(26)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_KDF_ERR_ACCESS_VIOLATION                     HWKM_ERR_BIT(27)
/* Security level of KDK is lower than the MKS or child key policy level */
#define HWKM_KDF_ERR_SECURITY_LEVEL_VIOLATION             HWKM_ERR_BIT(28)

/* SYSTEM_KDF internal errors */
#define HWKN_KDF_ERR_INTERNAL (HWKM_COMMON_ERR_INTERNAL | \
                               HWKM_KDF_ERR_SEC_CTRL_ACCESS | \
                               HWKM_KDF_ERR_KT_PARITY)

/** KEY_WRAP_EXPORT errors */
/* KWK slot not even (should be even for double key */
#define HWKM_EXPORT_ERR_KWK_DOUBLE_KEY_ODD_SLOT           HWKM_ERR_BIT(8)
/* SKS cannot be encrypted */
#define HWKM_EXPORT_ERR_ENCRYPT_NOT_ALLOWED               HWKM_ERR_BIT(9)
/* SKS is not single (256 bits) */
#define HWKM_EXPORT_ERR_SKS_SIZE_ERROR                    HWKM_ERR_BIT(10)
/* SKS key is out of range */
#define HWKM_EXPORT_ERR_SKS_SLOT_OUT_OF_RANGE             HWKM_ERR_BIT(11)
/* KWK is not double (512 bits) */
#define HWKM_EXPORT_ERR_KWK_SIZE_ERROR                    HWKM_ERR_BIT(12)
/* KWK is out of range */
#define HWKM_EXPORT_ERR_KWK_SLOT_OUT_OF_RANGE             HWKM_ERR_BIT(13)
/* Integrity error. Memory has been attacked */
#define HWKM_EXPORT_ERR_KT_PARITY                         HWKM_ERR_BIT(14)
/* Wrap with TPKEY: wrap_with_tpkey_allowed check failed */
#define HWKM_EXPORT_ERR_WRAP_WITH_TPKEY_NOT_ALLOWED       HWKM_ERR_BIT(15)
/* Swap export: swap_export_allowed check failed */
#define HWKM_EXPORT_ERR_SWAP_EXPORT_NOT_ALLOWED           HWKM_ERR_BIT(16)
/* Wrap export: wrap_export_allowed check failed */
#define HWKM_EXPORT_ERR_WRAP_EXPORT_NOT_ALLOWED           HWKM_ERR_BIT(17)
/* Unexpected algorithm for the key */
#define HWKM_EXPORT_ERR_UNEXPECTED_ALG_ALLOWED            HWKM_ERR_BIT(18)
/* KWK:SECURITY_LEVEL < SKS:SECURITY_LEVEL */
#define HWKM_EXPORT_ERR_SECURITY_LEVEL_ERROR              HWKM_ERR_BIT(19)
/* KDK:KEY_TYPE is not KDK. KWK:KEY_TYPE is not one of {KWK, KSK or TPKEY} */
#define HWKM_EXPORT_ERR_UNEXPECTED_KEY_TYPE               HWKM_ERR_BIT(20)
/* Key slot ID pointed to by the KWK in the command packet is empty */
#define HWKM_EXPORT_ERR_KWK_SLOT_EMPTY                    HWKM_ERR_BIT(21)
/* Key slot ID pointed to by the SKS in the command packet is empty */
#define HWKM_EXPORT_ERR_SKS_SLOT_EMPTY                    HWKM_ERR_BIT(22)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_EXPORT_ERR_SKS_ACCESS_VIOLATION              HWKM_ERR_BIT(23)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_EXPORT_ERR_KWK_ACCESS_VIOLATION              HWKM_ERR_BIT(24)

/* KEY_WRAP_EXPORT internal errors */
#define HWKN_EXPORT_ERR_INTERNAL (HWKM_COMMON_ERR_INTERNAL | \
                                  HWKM_EXPORT_ERR_KT_PARITY)

/** KEY_UNWRAP_IMPORT errors */
/* Unwrap has failed authentication */
#define HWKM_IMPORT_ERR_UNWRAP_FAILED                     HWKM_ERR_BIT(8)
/* KWK slot not even (should be even for double key */
#define HWKM_IMPORT_ERR_KWK_DOUBLE_KEY_ODD_SLOT           HWKM_ERR_BIT(9)
/* KWK is not double (512 bits) */
#define HWKM_IMPORT_ERR_KWK_SIZE_ERROR                    HWKM_ERR_BIT(10)
/* DKS is not double (512 bits) */
#define HWKM_IMPORT_ERR_DKS_SIZE_ERROR                    HWKM_ERR_BIT(11)
/* DKS is out of range */
#define HWKM_IMPORT_ERR_DKS_OUT_OF_RANGE                  HWKM_ERR_BIT(12)
/* KWK is out of range */
#define HWKM_IMPORT_ERR_KWK_SLOT_OUT_OF_RANGE             HWKM_ERR_BIT(13)
/* Integrity error. Memory has been attacked */
#define HWKM_IMPORT_ERR_KT_PARITY                         HWKM_ERR_BIT(14)
/* KWK:SECURITY_LEVEL < SKS:SECURITY_LEVEL */
#define HWKM_IMPORT_ERR_SECURITY_LEVEL_ERROR              HWKM_ERR_BIT(15)
/* Write Op: Security Level is not part of the Spec list */
#define HWKM_IMPORT_ERR_INVALID_SECURITY_LEVEL            HWKM_ERR_BIT(16)
/* Write Op: Key Type is not part of the Spec list */
#define HWKM_IMPORT_ERR_INVALID_KEY_TYPE                  HWKM_ERR_BIT(17)
/* Write Op: ALG is not part of the Spec list */
#define HWKM_IMPORT_ERR_INVALID_ALG_ALLOWED               HWKM_ERR_BIT(18)
/* Other: Consistency check failed */
#define HWKM_IMPORT_ERR_CONSISTENCY_CHECK_FAILED          HWKM_ERR_BIT(19)
/* TPKEY: Consistency check failed */
#define HWKM_IMPORT_ERR_INVALID_TPKEY_ATTRIB              HWKM_ERR_BIT(20)
/* KSK: Consistency check failed */
#define HWKM_IMPORT_ERR_INVALID_KSK_ATTRIB                HWKM_ERR_BIT(21)
/* KWK: Consistency check failed */
#define HWKM_IMPORT_ERR_INVALID_KWK_ATTRIB                HWKM_ERR_BIT(22)
/* KDK: Consistency check failed */
#define HWKM_IMPORT_ERR_INVALID_KDF_DEPTH                 HWKM_ERR_BIT(23)
/* KWK:DECRYPT_ALLOWED=0 */
#define HWKM_IMPORT_ERR_DECRYPT_NOT_ALLOWED               HWKM_ERR_BIT(24)
/* Unexpected algorithm for the key */
#define HWKM_IMPORT_ERR_UNEXPECTED_ALG_ALLOWED            HWKM_ERR_BIT(25)
/* KDK:KEY_TYPE is not KDK. KWK:KEY_TYPE is not one of {KWK, KSK or TPKEY} */
#define HWKM_IMPORT_ERR_UNEXPECTED_KEY_TYPE               HWKM_ERR_BIT(26)
/* Key slot ID pointed to by the KWK in the command packet is empty */
#define HWKM_IMPORT_ERR_KWK_SLOT_EMPTY                    HWKM_ERR_BIT(27)
/* Key slot ID pointed to by the DKS in the command packet is not empty */
#define HWKM_IMPORT_ERR_DKS_SLOT_NOT_EMPTY                HWKM_ERR_BIT(28)

/**
 * Note: this error bit is documented in the HPG as ERR_DKS_ACCESS_VIOLATION,
 * but it can be set when the WKB is incorrect.
 */
#define HWKM_IMPORT_ERR_WKB_CORRUPTED                     HWKM_ERR_BIT(29)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_IMPORT_ERR_DKS_ACCESS_VIOLATION              HWKM_ERR_BIT(29)

/* Access violation. Current key cannot be managed by the EE */
#define HWKM_IMPORT_ERR_KWK_ACCESS_VIOLATION              HWKM_ERR_BIT(30)

/* KEY_UNWRAP_IMPORT internal errors */
#define HWKN_IMPORT_ERR_INTERNAL (HWKM_COMMON_ERR_INTERNAL | \
                                  HWKM_IMPORT_ERR_KT_PARITY)

/** SET_TPKEY errors */
/* Integrity error. Memory has been attacked */
#define HWKM_TPKEY_ERR_KT_PARITY                          HWKM_ERR_BIT(8)
/* Addressing a Double Key with wrong Key Slot ID */
#define HWKM_TPKEY_ERR_DOUBLE_KEY_SLOT_NOT_EVEN           HWKM_ERR_BIT(9)
/* Key size is wrong. Should be 512 bits */
#define HWKM_TPKEY_ERR_WRONG_KEY_SIZE                     HWKM_ERR_BIT(10)
/* SKS key slot id is out of range */
#define HWKM_TPKEY_ERR_KEYSLOT_ID_OUT_OF_RANGE            HWKM_ERR_BIT(11)
/* KEY_TYPE is not TPKEY */
#define HWKM_TPKEY_ERR_UNEXPECTED_KEY_TYPE                HWKM_ERR_BIT(12)
/* Key slot ID pointed to by SKS in the command packet is empty */
#define HWKM_TPKEY_ERR_SKS_SLOT_EMPTY                     HWKM_ERR_BIT(13)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_TPKEY_ERR_ACCESS_VIOLATION                   HWKM_ERR_BIT(14)

/* SET_TPKEY internal errors */
#define HWKN_TPKEY_ERR_INTERNAL (HWKM_COMMON_ERR_INTERNAL | \
                                 HWKM_TPKEY_ERR_KT_PARITY)

/** KEYSLOT_CLEAR errors */
/* DKS key slot id is pointing to a static one. Not clearable by SW */
#define HWKM_CLEAR_ERR_KEYSLOT_ID_NOT_ACCESSIBLE          HWKM_ERR_BIT(8)
/* DKS key slot id is out of range */
#define HWKM_CLEAR_ERR_KEYSLOT_ID_OUT_OF_RANGE            HWKM_ERR_BIT(9)
/* Wrong key size */
#define HWKM_CLEAR_ERR_KEY_SIZE                           HWKM_ERR_BIT(10)
/* DKS slot is not Even when clearing a Double Key */
#define HWKM_CLEAR_ERR_DOUBLE_KEY_DKS_SLOT_NOT_EVEN       HWKM_ERR_BIT(11)
/* Key slot id pointed to by DKS in the command packet is empty */
#define HWKM_CLEAR_ERR_DKS_SLOT_EMPTY                     HWKM_ERR_BIT(12)
/* Access violation. Current key cannot be managed by the EE */
#define HWKM_CLEAR_ERR_ACCESS_VIOLATION                   HWKM_ERR_BIT(13)

/* KEYSLOT_CLEAR internal errors */
#define HWKN_CLEAR_ERR_INTERNAL (HWKM_COMMON_ERR_INTERNAL)

#endif /* HWKM_ERR_H */
