#ifndef UCLIB_ERR_HEADER
#define UCLIB_ERR_HEADER

/* ====================================================================
 * Copyright (c) 2017 - 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Library - Errors

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/
#include <stdint.h>

/* Error Modules */
#define UCM_CMN                0U /** Common */
#define UCM_ENV                1U /** Environment */
#define UCM_CEHW               2U /** Crypto Engine HWIO HAL Driver */
#define UCM_CEBAM              3U /** Crypto Engine BAM HAL Driver */
#define UCM_HASH               4U /** Hash */
#define UCM_CIPHER             5U /** Cipher */
#define UCM_AES                6U /** AES */
#define UCM_DES                7U /** DES */
#define UCM_PRNG               8U /** PRNG */
#define UCM_PKEY               9U /** Public-Key */
#define UCM_BIGINT            10U /** Crypto Big-Integer */
#define UCM_MAC               11U /** MAC */
#define UCM_KDF               12U /** KDF */
#define UCM_TMECOM            13U /** Remote */

/**
 Macro to create error code.
 31*******************20**********************************0
 +--------------------+-----------------------------------+
 |    12 bits for     |          20 bits
 |    Module Name     |        error code
 +--------------------+-----------------------------------+
*/
#define UCLIB_GET_EC(mod, ec)    ((((mod) & 0xFFFU) << 20U) + ((uint32_t)(ec) & 0xFFFFFU))
#define UCLIB_ERR(mod, ec)       ((int)UCLIB_GET_EC(mod, ec))


  /** Common UCLIB Error Codes */
#define  UCLIB_SUCCESS                   UCLIB_ERR(UCM_CMN, 0)         /** Operation successful                 */
#define  UCLIB_ERR_FAILURE               UCLIB_ERR(UCM_CMN, 1)         /** Operation failed due to unknown err  */
#define  UCLIB_ERR_INVALID_ARG           UCLIB_ERR(UCM_CMN, 2)         /** Arg is not recognized                */
#define  UCLIB_ERR_OUT_OF_RANGE          UCLIB_ERR(UCM_CMN, 3)         /** Arg value is out of range            */
#define  UCLIB_ERR_VERSION_MISMATCH      UCLIB_ERR(UCM_CMN, 4)         /** Unexpected software or protocol ver. */
#define  UCLIB_ERR_NOT_SUPPORTED         UCLIB_ERR(UCM_CMN, 5)         /** Operation not yet implemented        */
#define  UCLIB_ERR_INVALID_CONTEXT       UCLIB_ERR(UCM_CMN, 6)         /** Invalid context                      */
#define  UCLIB_ERR_OUT_OF_MEMORY         UCLIB_ERR(UCM_CMN, 7)         /** Out of memory                        */
#define  UCLIB_ERR_INV_DGST_SIZE         UCLIB_ERR(UCM_CMN, 9)         /** Invalid digest size                  */
#define  UCLIB_ERR_INV_DGST_CONTEXT      UCLIB_ERR(UCM_CMN, 10)        /** Invalid digest context               */
#define  UCLIB_ERR_ADD_OVERFLOW          UCLIB_ERR(UCM_CMN, 11)        /** Addition Overflow                    */
#define  UCLIB_ERR_HEAP_LITE_FAILED      UCLIB_ERR(UCM_CMN, 12)        /** Heap API failed                      */
#define  UCLIB_ERR_SELF_TEST_FAILED      UCLIB_ERR(UCM_CMN, 13)        /** Self test failed                     */
  /* These error codes for event handling are used by corresponding callback functions in modem env file   */
#define  UCLIB_ERR_EVENT_CREATE_FAILED   UCLIB_ERR(UCM_CMN, 14)        /** Event create failed                  */
#define  UCLIB_ERR_EVENT_DEL_FAILED      UCLIB_ERR(UCM_CMN, 15)        /** Event delete failed                  */
#define  UCLIB_ERR_EVENT_WAIT_FAILED     UCLIB_ERR(UCM_CMN, 16)        /** Event wait failed                    */
#define  UCLIB_ERR_EVENT_TRIGGER_FAILED  UCLIB_ERR(UCM_CMN, 17)        /** Event trigger failed                 */

  /** Environment Error Codes */
#define  UCLIB_ERR_SET_CLK_BW            UCLIB_ERR(UCM_ENV, 1)         /** Set Clock BW failed                  */
#define  UCLIB_ERR_VTOP_FAILED           UCLIB_ERR(UCM_ENV, 2)         /** VA to PA failed                      */
#define  UCLIB_ERR_MUTEX_INIT            UCLIB_ERR(UCM_ENV, 3)         /** Mutex Init API failed                */
#define  UCLIB_ERR_MUTEX_LOCK            UCLIB_ERR(UCM_ENV, 4)         /** Mutex Lock API failed                */
#define  UCLIB_ERR_MUTEX_RELEASE         UCLIB_ERR(UCM_ENV, 5)         /** Mutex Release API failed             */
#define  UCLIB_ERR_HEAP_NOT_SUPPORTED    UCLIB_ERR(UCM_ENV, 6)         /** Heap API not supported               */
#define  UCLIB_ERR_HEAP_INIT_FAILED      UCLIB_ERR(UCM_ENV, 7)         /** Heap init. failed                    */
#define  UCLIB_ERR_INV_BAM_CTX_SIZE      UCLIB_ERR(UCM_ENV, 8)         /** Invalid BAM Driver CTX size          */
#define  UCLIB_ERR_INV_BAM_CTX           UCLIB_ERR(UCM_ENV, 9)         /** Invalid BAM Driver CTX               */
#define  UCLIB_ERR_PRNG_CLK_FAILED       UCLIB_ERR(UCM_ENV, 10)        /** PRNG Clock Vote API failed           */
#define  UCLIB_ERR_INV_BAM_BUF_ADDR      UCLIB_ERR(UCM_ENV, 11)        /** Invalid BAM Buf Address              */
#define  UCLIB_ERR_INV_ENV_PTR           UCLIB_ERR(UCM_ENV, 12)        /** Invalid env ctx pointer              */

  /** CE HWIO HAL Driver Error Codes */
#define  UCLIB_ERR_INV_AUTH_XFER_SZ           UCLIB_ERR(UCM_CEHW, 1)       /** Invalid Auth Transfer size              */
#define  UCLIB_ERR_INV_CIPHER_XFER_SZ         UCLIB_ERR(UCM_CEHW, 2)       /** Invalid Cipher Transfer size            */
#define  UCLIB_ERR_CE_HAL_CTX_INVALID         UCLIB_ERR(UCM_CEHW, 3)       /** Invalid CE HAL Context                  */
#define  UCLIB_ERR_HAL_MAC_FAILED             UCLIB_ERR(UCM_CEHW, 4)       /**                                         */
#define  UCLIB_ERR_HAL_ACCESS_VIOL            UCLIB_ERR(UCM_CEHW, 5)       /**                                         */
#define  UCLIB_ERR_HAL_PIPE_ACTIVE_ERR        UCLIB_ERR(UCM_CEHW, 6)       /**                                         */
#define  UCLIB_ERR_HAL_CFG_CHNG_ERR           UCLIB_ERR(UCM_CEHW, 7)       /**                                         */
#define  UCLIB_ERR_HAL_DOUT_ERR               UCLIB_ERR(UCM_CEHW, 8)       /**                                         */
#define  UCLIB_ERR_HAL_DIN_ERR                UCLIB_ERR(UCM_CEHW, 9)       /**                                         */
#define  UCLIB_ERR_HAL_AXI_ERR                UCLIB_ERR(UCM_CEHW, 10)      /**                                         */
#define  UCLIB_ERR_HAL_CE_BUSY_ERR            UCLIB_ERR(UCM_CEHW, 11)      /**                                         */
#define  UCLIB_ERR_HAL_SET_IV_FAILED          UCLIB_ERR(UCM_CEHW, 12)      /**                                         */
#define  UCLIB_ERR_HAL_INSTALL_HW_KEY_FAILED  UCLIB_ERR(UCM_CEHW, 13)      /** Failed to install key in HW Key Manager */
#define  UCLIB_ERR_HAL_NO_WRAPPED_KEY         UCLIB_ERR(UCM_CEHW, 14)      /** No wrapped key was provided             */
#define  UCLIB_ERR_HAL_HSD_ERR                UCLIB_ERR(UCM_CEHW, 15)      /** CRYPTO_STATUS[HSD_ERR]                  */
#define  UCLIB_ERR_HAL_BIST_ERR               UCLIB_ERR(UCM_CEHW, 16)      /** CRYPTO_STATUS2[BIST_ERROR]              */
#define  UCLIB_ERR_HAL_KEY_ERR                UCLIB_ERR(UCM_CEHW, 17)      /** CRYPTO_STATUS2[KEY_ERR]                 */
#define  UCLIB_ERR_HAL_PIPE_KEY_USAGE_ERR     UCLIB_ERR(UCM_CEHW, 18)      /** CRYPTO_STATUS2[PIPE_KEY_USAGE_ERR]      */
#define  UCLIB_ERR_HAL_PIPE_KEY_TIMER_ERR     UCLIB_ERR(UCM_CEHW, 19)      /** CRYPTO_STATUS2[PIPE_KEY_TIMER_ERR]      */
#define  UCLIB_ERR_HAL_PIPE_KEY_PAUSE_ERR     UCLIB_ERR(UCM_CEHW, 20)      /** CRYPTO_STATUS2[PIPE_KEY_PAUSE_ERR]      */
#define  UCLIB_ERR_HAL_HW_KEY_USAGE_ERR       UCLIB_ERR(UCM_CEHW, 21)      /** CRYPTO_STATUS2[HW_KEY_USAGE_ERR]        */

  /** CE BAM HAL Driver Error Codes */
#define  UCLIB_ERR_BAM_INIT_FAILED       UCLIB_ERR(UCM_CEBAM, 1)      /** BAM driver init. failed               */
#define  UCLIB_ERR_BAM_INIT_TXPIPE       UCLIB_ERR(UCM_CEBAM, 2)      /** BAM Tx pipe init. failed              */
#define  UCLIB_ERR_BAM_INIT_RXPIPE       UCLIB_ERR(UCM_CEBAM, 3)      /** BAM Rx pipe init. failed              */
#define  UCLIB_ERR_BAM_TX_IRQ_MODE       UCLIB_ERR(UCM_CEBAM, 4)      /** BAM Tx IRQ Mode set failed            */
#define  UCLIB_ERR_BAM_RX_IRQ_MODE       UCLIB_ERR(UCM_CEBAM, 5)      /** BAM Rx IRQ Mode set failed            */
#define  UCLIB_ERR_BAM_XFR_CMD_DSC       UCLIB_ERR(UCM_CEBAM, 6)      /** BAM Command Descriptor Xfer failed    */
#define  UCLIB_ERR_BAM_XFR_DAT_DSC       UCLIB_ERR(UCM_CEBAM, 7)      /** BAM Data Descriptor Xfer failed       */
#define  UCLIB_ERR_BAM_XFR_RSLT_DSC      UCLIB_ERR(UCM_CEBAM, 8)      /** BAM Result Dump Xfer failed           */
#define  UCLIB_ERR_BAM_BUF_PA_XLATE      UCLIB_ERR(UCM_CEBAM, 9)      /** Data buffer VTOP failed               */
#define  UCLIB_ERR_BAM_PIPE_UNLCK        UCLIB_ERR(UCM_CEBAM, 10)     /** BAM pipe unlock request failed        */
#define  UCLIB_ERR_BAM_TX_PIPE_POLL      UCLIB_ERR(UCM_CEBAM, 11)     /** Tx pipe poll API failed               */
#define  UCLIB_ERR_BAM_RX_PIPE_POLL      UCLIB_ERR(UCM_CEBAM, 12)     /** Rx pipe poll API failed               */
#define  UCLIB_ERR_BAM_PIPE_BUSY         UCLIB_ERR(UCM_CEBAM, 13)     /** Tx/Rx pipe is still busy              */
#define  UCLIB_ERR_BAM_NO_ENG_EN         UCLIB_ERR(UCM_CEBAM, 14)     /** No engine enabled                     */
#define  UCLIB_ERR_BAM_SZ_TOO_LARGE      UCLIB_ERR(UCM_CEBAM, 15)     /** Transfer size in non-blocking mode is too large */
#define  UCLIB_ERR_BAM_XFR_DAT_DSC_RX    UCLIB_ERR(UCM_CEBAM, 16)     /** BAM Data Descriptor Xfer failed       */
#define  UCLIB_ERR_BAM_IRQ_WAIT          UCLIB_ERR(UCM_CEBAM, 17)     /** BAM Tx/Rx IRQ wait failed             */
#define  UCLIB_ERR_BAM_POLL_API_ERR      UCLIB_ERR(UCM_CEBAM, 18)     /** BAM poll API returned error           */
#define  UCLIB_ERR_BAM_POLL_TX_TIMEOUT   UCLIB_ERR(UCM_CEBAM, 19)     /** Max iterations of BAM poll exceeded   */
#define  UCLIB_ERR_BAM_POLL_RX_TIMEOUT   UCLIB_ERR(UCM_CEBAM, 20)     /** Max iterations of BAM poll exceeded   */

  /** CE Cipher Error Codes */
#define  UCLIB_ERR_CIPHER_INV_KEY_PTR       UCLIB_ERR(UCM_CIPHER, 1)     /**                */
#define  UCLIB_ERR_CIPHER_INV_KEY_SZ        UCLIB_ERR(UCM_CIPHER, 2)     /**                */
#define  UCLIB_ERR_CIPHER_INV_IV_PTR        UCLIB_ERR(UCM_CIPHER, 3)     /**                */
#define  UCLIB_ERR_CIPHER_INV_IV_SZ         UCLIB_ERR(UCM_CIPHER, 4)     /**                */
#define  UCLIB_ERR_CIPHER_NO_PADDING        UCLIB_ERR(UCM_CIPHER, 5)     /**                */
#define  UCLIB_ERR_CIPHER_SMALL_OUT_BUF     UCLIB_ERR(UCM_CIPHER, 6)     /**                */
#define  UCLIB_ERR_CIPHER_INV_IBUF_SZ       UCLIB_ERR(UCM_CIPHER, 7)     /**                */
#define  UCLIB_ERR_CIPHER_INV_KEY           UCLIB_ERR(UCM_CIPHER, 8)     /**                */
#define  UCLIB_ERR_CIPHER_INV_IV            UCLIB_ERR(UCM_CIPHER, 9)     /**                */
#define  UCLIB_ERR_CIPHER_INV_NONCE_PTR     UCLIB_ERR(UCM_CIPHER, 10)    /**                */
#define  UCLIB_ERR_CIPHER_INV_NONCE_SZ      UCLIB_ERR(UCM_CIPHER, 11)    /**                */
#define  UCLIB_ERR_CIPHER_INV_NONCE_VAL     UCLIB_ERR(UCM_CIPHER, 12)    /**                */
#define  UCLIB_ERR_CIPHER_INV_TAG_SZ        UCLIB_ERR(UCM_CIPHER, 13)    /**                */
#define  UCLIB_ERR_CIPHER_ODD_TAG_SZ        UCLIB_ERR(UCM_CIPHER, 14)    /**                */
#define  UCLIB_ERR_CIPHER_INV_AAD_UPDATE    UCLIB_ERR(UCM_CIPHER, 15)    /**                */
#define  UCLIB_ERR_CIPHER_INV_DATA_UPDATE   UCLIB_ERR(UCM_CIPHER, 16)    /**                */
#define  UCLIB_ERR_CIPHER_INV_FINAL_CALL    UCLIB_ERR(UCM_CIPHER, 17)    /**                */
#define  UCLIB_ERR_CIPHER_INV_AUTH_FLD_LEN  UCLIB_ERR(UCM_CIPHER, 18)    /**                */
#define  UCLIB_ERR_CIPHER_INV_AUTH_SIZE     UCLIB_ERR(UCM_CIPHER, 19)    /**                */
#define  UCLIB_ERR_CIPHER_INV_MSG_SIZE      UCLIB_ERR(UCM_CIPHER, 20)    /**                */
#define  UCLIB_ERR_CIPHER_INV_MAC           UCLIB_ERR(UCM_CIPHER, 21)    /**                */
#define  UCLIB_ERR_CIPHER_INV_TAG_PTR       UCLIB_ERR(UCM_CIPHER, 22)    /**                */
#define  UCLIB_ERR_CIPHER_PADDING_FAILED    UCLIB_ERR(UCM_CIPHER, 23)    /**                */
#define  UCLIB_ERR_CIPHER_INV_PLD_SIZE      UCLIB_ERR(UCM_CIPHER, 24)    /**                */
#define  UCLIB_ERR_CIPHER_INV_HDR_SIZE      UCLIB_ERR(UCM_CIPHER, 25)    /**                */
#define  UCLIB_ERR_CIPHER_INV_VA_PARAM      UCLIB_ERR(UCM_CIPHER, 26)    /**                */
#define  UCLIB_ERR_CIPHER_INV_DIR           UCLIB_ERR(UCM_CIPHER, 27)    /**                */
#define  UCLIB_ERR_CIPHER_INV_BAM_PIPE      UCLIB_ERR(UCM_CIPHER, 28)    /**                */
#define  UCLIB_ERR_CIPHER_INV_FINAL_DATA    UCLIB_ERR(UCM_CIPHER, 29)    /**                */
#define  UCLIB_ERR_CIPHER_INV_XTS_KEY_PTR   UCLIB_ERR(UCM_CIPHER, 30)    /**                */
#define  UCLIB_ERR_CIPHER_INV_XTS_KEY_SZ    UCLIB_ERR(UCM_CIPHER, 31)    /**                */
#define  UCLIB_ERR_CIPHER_INV_XTS_KEY       UCLIB_ERR(UCM_CIPHER, 32)    /**                */
#define  UCLIB_ERR_CIPHER_INV_XTS_DU_SIZE   UCLIB_ERR(UCM_CIPHER, 33)    /**                */
#define  UCLIB_ERR_CIPHER_INV_CTR_SIZE      UCLIB_ERR(UCM_CIPHER, 34)    /**                */
#define  UCLIB_ERR_CIPHER_INV_HASH_ALG      UCLIB_ERR(UCM_CIPHER, 35)    /**                */
#define  UCLIB_ERR_CIPHER_INV_HASH_ORDER    UCLIB_ERR(UCM_CIPHER, 36)    /**                */
#define  UCLIB_ERR_CIPHER_INV_CTR_BUF_SZ    UCLIB_ERR(UCM_CIPHER, 37)    /**                */
#define  UCLIB_ERR_CIPHER_INV_CFB_SEG_SZ    UCLIB_ERR(UCM_CIPHER, 38)    /**                */

  /** CE Cipher - AES Error Codes */
#define  UCLIB_ERR_AES_SET_ENC_KEY       UCLIB_ERR(UCM_AES, 1)        /**                */
#define  UCLIB_ERR_AES_SET_DEC_KEY       UCLIB_ERR(UCM_AES, 2)        /**                */
#define  UCLIB_ERR_AES_ENC               UCLIB_ERR(UCM_AES, 3)        /**                */
#define  UCLIB_ERR_AES_DEC               UCLIB_ERR(UCM_AES, 4)        /**                */

  /** CE Cipher - DES Error Codes */
#define  UCLIB_ERR_DES_SET_ENC_KEY       UCLIB_ERR(UCM_DES, 1)        /**                */
#define  UCLIB_ERR_DES_SET_DEC_KEY       UCLIB_ERR(UCM_DES, 2)        /**                */
#define  UCLIB_ERR_DES_ENC               UCLIB_ERR(UCM_DES, 3)        /**                */
#define  UCLIB_ERR_DES_DEC               UCLIB_ERR(UCM_DES, 4)        /**                */

  /** PRNG - Error Codes */
#define  UCLIB_ERR_PRNG_ACCESS_ENABLE    UCLIB_ERR(UCM_PRNG, 1)       /**                */
#define  UCLIB_ERR_PRNG_ACCESS_DISABLE   UCLIB_ERR(UCM_PRNG, 2)       /**                */

  /** CE Public-Key Error Codes */
#define  UCLIB_ERR_PKEY_KEY_SIZE_TOO_SMALL                UCLIB_ERR(UCM_PKEY, 1)   /** Key size too small to be secure                                       */
#define  UCLIB_ERR_PKEY_KEY_SIZE_TOO_LARGE                UCLIB_ERR(UCM_PKEY, 2)   /** Key size exceeds BigInteger size                                      */
#define  UCLIB_ERR_PKEY_MSG_SIZE_TOO_LARGE                UCLIB_ERR(UCM_PKEY, 3)   /** Message size too large for padding scheme                             */
#define  UCLIB_ERR_DIGEST_ALG_UNSUPPORTED                 UCLIB_ERR(UCM_PKEY, 4)   /** The digest algorithm is not supported                                 */
#define  UCLIB_ERR_MSG_SIZE_DIGEST_MISMATCH               UCLIB_ERR(UCM_PKEY, 5)   /** Message size does not match digest size                               */
#define  UCLIB_ERR_PKEY_INVALID_SIGNATURE                 UCLIB_ERR(UCM_PKEY, 6)   /** Invalid signature                                                     */
#define  UCLIB_ERR_PKEY_DECRYPT_KEY_SIZE_INVALID          UCLIB_ERR(UCM_PKEY, 7)   /** Invalid key size for decryption                                       */
#define  UCLIB_ERR_PKEY_PADDED_PACKET_INVALID             UCLIB_ERR(UCM_PKEY, 8)   /** Invalid padding detected                                              */
#define  UCLIB_ERR_PKEY_DECRYPT_BUF_TOO_SMALL             UCLIB_ERR(UCM_PKEY, 9)   /** Buffer provided for decrypted message is not large enough             */
#define  UCLIB_ERR_PKEY_PADDING_PRNG_FAILED               UCLIB_ERR(UCM_PKEY, 10)  /** Failed to generate required number of bytes for padding               */
#define  UCLIB_ERR_PKEY_POINT_AT_INFINITY                 UCLIB_ERR(UCM_PKEY, 11)  /** Point at infinity                                                     */
#define  UCLIB_ERR_PKEY_CONV_TO_BIGVAL_FAILED             UCLIB_ERR(UCM_PKEY, 12)  /** Conversion from byte buffer to big-integer failed                     */
#define  UCLIB_ERR_PKEY_CONV_FROM_BIGVAL_FAILED           UCLIB_ERR(UCM_PKEY, 13)  /** Conversion from big-integer to byte-buffer failed                     */
#define  UCLIB_ERR_INV_PKEY_CONTEXT                       UCLIB_ERR(UCM_PKEY, 14)  /** Invalid internal/implementation context                               */
#define  UCLIB_ERR_KEY_NOT_ON_CURVE                       UCLIB_ERR(UCM_PKEY, 15)  /** The key is not a valid point on the curve                             */
#define  UCLIB_ERR_HW_ACQUIRE_FAILED                      UCLIB_ERR(UCM_PKEY, 16)  /** Acquiring/locking access to the HW failed                             */
#define  UCLIB_ERR_HW_RELEASE_FAILED                      UCLIB_ERR(UCM_PKEY, 17)  /** Releasing/unlocking access to the HW failed                           */
#define  UCLIB_ERR_HW_CLEAR_MEM_FAILED                    UCLIB_ERR(UCM_PKEY, 18)  /** Clearing of the HW regs failed                                        */
#define  UCLIB_ERR_HW_LOAD_OPERANDS_FAILED                UCLIB_ERR(UCM_PKEY, 19)  /** Loading into HW regs failed                                           */
#define  UCLIB_ERR_PKA_SIZE_TO_RADIX_FAILED               UCLIB_ERR(UCM_PKEY, 20)  /** Converting operand size to a valid radix failed or operand size zero */
#define  UCLIB_ERR_PKA_BUSY                               UCLIB_ERR(UCM_PKEY, 21)  /** PKA HW is busy actively executing a program                           */
#define  UCLIB_ERR_PKA_INVALID_FIRMWARE                   UCLIB_ERR(UCM_PKEY, 22)  /** Invalid PKA firmware                                                  */
#define  UCLIB_ERR_PKA_OPERATION_FAILED                   UCLIB_ERR(UCM_PKEY, 23)  /** PKA operation failed                                                  */

#define  UCLIB_ERR_PKA_HW_CRYPTO_FAILED                   UCLIB_ERR(UCM_PKEY, 24)  /** PKA-HW error - general failure                                        */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INPROGRESS               UCLIB_ERR(UCM_PKEY, 25)  /** PKA-HW error - operation in progress                                  */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_HANDLE           UCLIB_ERR(UCM_PKEY, 26)  /** PKA-HW error - invalid handle                                         */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_CONTEXT          UCLIB_ERR(UCM_PKEY, 27)  /** PKA-HW error - invalid context                                        */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_SIZE             UCLIB_ERR(UCM_PKEY, 28)  /** PKA-HW error - invalid size                                           */
#define  UCLIB_ERR_PKA_HW_CRYPTO_NOT_INITIALIZED          UCLIB_ERR(UCM_PKEY, 29)  /** PKA-HW error - not initiated                                          */
#define  UCLIB_ERR_PKA_HW_CRYPTO_NO_MEM                   UCLIB_ERR(UCM_PKEY, 30)  /** PKA-HW error - out of memory                                          */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_ALG              UCLIB_ERR(UCM_PKEY, 31)  /** PKA-HW error - invalid algorithm                                      */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_KEY_SIZE         UCLIB_ERR(UCM_PKEY, 32)  /** PKA-HW error - invalid key size                                       */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_ARGUMENT         UCLIB_ERR(UCM_PKEY, 33)  /** PKA-HW error - invalid argument                                       */
#define  UCLIB_ERR_PKA_HW_CRYPTO_MODULE_DISABLED          UCLIB_ERR(UCM_PKEY, 34)  /** PKA-HW error - module disabled                                        */
#define  UCLIB_ERR_PKA_HW_CRYPTO_NOT_IMPLEMENTED          UCLIB_ERR(UCM_PKEY, 35)  /** PKA-HW error - not implemented                                        */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_BLOCK_ALIGNMENT  UCLIB_ERR(UCM_PKEY, 36)  /** PKA-HW error - invalid block alignment                                */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_MODE             UCLIB_ERR(UCM_PKEY, 37)  /** PKA-HW error - invalid mode                                           */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_KEY              UCLIB_ERR(UCM_PKEY, 38)  /** PKA-HW error - invalid key                                            */
#define  UCLIB_ERR_PKA_HW_CRYPTO_AUTHENTICATION_FAILED    UCLIB_ERR(UCM_PKEY, 39)  /** PKA-HW error - authentication failed                                  */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_IV_SIZE          UCLIB_ERR(UCM_PKEY, 40)  /** PKA-HW error - invalid IV size                                        */
#define  UCLIB_ERR_PKA_HW_CRYPTO_MEMORY_ERROR             UCLIB_ERR(UCM_PKEY, 41)  /** PKA-HW error - memory error                                           */
#define  UCLIB_ERR_PKA_HW_CRYPTO_LAST_ERROR               UCLIB_ERR(UCM_PKEY, 42)  /** PKA-HW error - last error                                             */
#define  UCLIB_ERR_PKA_HW_CRYPTO_HALTED                   UCLIB_ERR(UCM_PKEY, 43)  /** PKA-HW error - halted                                                 */
#define  UCLIB_ERR_PKA_HW_CRYPTO_TIMEOUT                  UCLIB_ERR(UCM_PKEY, 44)  /** PKA-HW error - timeout                                                */
#define  UCLIB_ERR_PKA_HW_CRYPTO_SRM_FAILED               UCLIB_ERR(UCM_PKEY, 45)  /** PKA-HW error - SRM failed                                             */
#define  UCLIB_ERR_PKA_HW_CRYPTO_COMMON_ERROR_MAX         UCLIB_ERR(UCM_PKEY, 46)  /** PKA-HW error - common error max                                       */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_ICV_KEY_SIZE     UCLIB_ERR(UCM_PKEY, 47)  /** PKA-HW error - invalid ICV key size                                   */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_PARAMETER_SIZE   UCLIB_ERR(UCM_PKEY, 48)  /** PKA-HW error - invalid parameter sequence                             */
#define  UCLIB_ERR_PKA_HW_CRYPTO_SEQUENCE_OVERFLOW        UCLIB_ERR(UCM_PKEY, 49)  /** PKA-HW error - sequence overflow                                      */
#define  UCLIB_ERR_PKA_HW_CRYPTO_DISABLED                 UCLIB_ERR(UCM_PKEY, 50)  /** PKA-HW error - disabled                                               */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_VERSION          UCLIB_ERR(UCM_PKEY, 51)  /** PKA-HW error - invalid version                                        */
#define  UCLIB_ERR_PKA_HW_CRYPTO_FATAL                    UCLIB_ERR(UCM_PKEY, 52)  /** PKA-HW error - fatal error                                            */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_PAD              UCLIB_ERR(UCM_PKEY, 53)  /** PKA-HW error - invalid pad                                            */
#define  UCLIB_ERR_PKA_HW_CRYPTO_FIFO_FULL                UCLIB_ERR(UCM_PKEY, 54)  /** PKA-HW error - FIFO full                                              */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_SEQUENCE         UCLIB_ERR(UCM_PKEY, 55)  /** PKA-HW error - invalid sequence                                       */
#define  UCLIB_ERR_PKA_HW_CRYPTO_INVALID_FIRMWARE         UCLIB_ERR(UCM_PKEY, 56)  /** PKA-HW error - invalid firmware                                       */
#define  UCLIB_ERR_PKA_HW_CRYPTO_NOT_FOUND                UCLIB_ERR(UCM_PKEY, 57)  /** PKA-HW error - not found                                              */
#define  UCLIB_ERR_PKA_HW_CRYPTO_CMD_FIFO_INACTIVE        UCLIB_ERR(UCM_PKEY, 58)  /** PKA-HW error - command FIFO inactive                                  */
#define  UCLIB_ERR_PKA_HW_CRYPTO_LOCK_ERROR               UCLIB_ERR(UCM_PKEY, 59)  /** PKA-HW error - lock error                                             */
#define  UCLIB_ERR_PKA_CMD_ENTRY_POINT_INVALID            UCLIB_ERR(UCM_PKEY, 60)  /** PKA-HW error - Command entry point not found                          */
#define  UCLIB_ERR_PKA_CURVE_INFO_NOT_FOUND               UCLIB_ERR(UCM_PKEY, 61)  /** PKA curve information not found                                       */
#define  UCLIB_ERR_PKA_INVALID_KEY                        UCLIB_ERR(UCM_PKEY, 62)  /** PKA-HW error - Invalid key/scalar for multiplication                  */
#define  UCLIB_ERR_PKA_INVALID_POINT                      UCLIB_ERR(UCM_PKEY, 63)  /** PKA-HW error - Invalid point supplied as input                        */

#define  UCLIB_ERR_PKEY_SHARED_KEY_DERIVE_FAILED          UCLIB_ERR(UCM_PKEY, 64)  /** Failed to derive a shared key                                         */

  /** CE BigInteger Error Codes */
#define  UCLIB_ERR_GENPRIME_BITS_INVALID   UCLIB_ERR(UCM_BIGINT, 1)  /* Invalid number of bits provided for prime-generation           */
#define  UCLIB_ERR_GENPRIME_PRNG_FAILED    UCLIB_ERR(UCM_BIGINT, 2)  /* PRNG failed                                                    */
#define  UCLIB_ERR_BIGINT_OVERFLOW         UCLIB_ERR(UCM_BIGINT, 3)  /* Operation would exceed maximum number of bits in BigInteger    */
#define  UCLIB_ERR_BIGINT_NO_INVERSE       UCLIB_ERR(UCM_BIGINT, 4)  /* No inverse present                                             */
#define  UCLIB_ERR_BIGINT_INVALID_LENGTH   UCLIB_ERR(UCM_BIGINT, 5)  /* Length field of BigInteger exceeds length of BigInteger array  */
#define  UCLIB_ERR_BIGINT_IS_COMPOSITE     UCLIB_ERR(UCM_BIGINT, 6)  /* BigInteger is trivially composite                              */

  /** MAC Error Codes */
#define  UCLIB_ERR_MAC_ALG_NOT_SET          UCLIB_ERR(UCM_MAC, 1)  /* Underlying Hash/Cipher algorithm was not set */
#define  UCLIB_ERR_MAC_KEY_NOT_SET          UCLIB_ERR(UCM_MAC, 2)  /* MAC key was not set                          */
#define  UCLIB_ERR_MAC_IV_NOT_SET           UCLIB_ERR(UCM_MAC, 3)  /* MAC IV was not set                           */
#define  UCLIB_ERR_MAC_INV_MAC_LEN          UCLIB_ERR(UCM_MAC, 4)  /* The provided MAC length is invalid           */

  /** KDF Error Codes */
#define  UCLIB_ERR_KDF_MAC_ALG_NOT_SET           UCLIB_ERR(UCM_KDF, 1)  /* pseudorandom number function not set */
#define  UCLIB_ERR_KDF_MAC_ALG_NOT_MATCH         UCLIB_ERR(UCM_KDF, 2)  /* pseudorandom number function not match */
#define  UCLIB_ERR_KDF_R_LEN_NOT_SET             UCLIB_ERR(UCM_KDF, 3)  /* r length not set */
#define  UCLIB_ERR_KDF_CTR_LOC_NOT_SET           UCLIB_ERR(UCM_KDF, 4)  /* counter location not set */
#define  UCLIB_ERR_KDF_CIPHER_ALG_NOT_SET        UCLIB_ERR(UCM_KDF, 5)  /* cipher algorithm not set */
#define  UCLIB_ERR_KDF_CIPHER_KEY_LEN_NOT_MATCH  UCLIB_ERR(UCM_KDF, 6)  /* cipher key length not match */
#define  UCLIB_ERR_KDF_HASH_ALG_NOT_SET          UCLIB_ERR(UCM_KDF, 7)  /* hash algorithm not match */
#define  UCLIB_ERR_KDF_PASSWORD_NOT_SET          UCLIB_ERR(UCM_KDF, 8)  /* pbkdf password not set */
#define  UCLIB_ERR_KDF_SALT_NOT_SET              UCLIB_ERR(UCM_KDF, 9)  /* pbkdf salt not set */
#define  UCLIB_ERR_KDF_ITERATION_NOT_SET         UCLIB_ERR(UCM_KDF, 10) /* pbkdf iteration not set */
#define  UCLIB_ERR_KDF_KO_LEN_NOT_SET            UCLIB_ERR(UCM_KDF, 11) /* pbkdf output key length not set */
#define  UCLIB_ERR_KDF_KO_LEN_TOO_LONG           UCLIB_ERR(UCM_KDF, 12) /* pbkdf output key length too long */
#define  UCLIB_ERR_KDF_KEY_NOT_SET               UCLIB_ERR(UCM_KDF, 13) /* kbkdf key not set */
#define  UCLIB_ERR_KDF_IV_NOT_SET                UCLIB_ERR(UCM_KDF, 14) /* kbkdf iv not set */

  /** Remote Engine Error Codes */
#define  UCLIB_ERR_TMECOM_VERIFY_ERROR  UCLIB_ERR(UCM_TMECOM, 1)    /* Remote engine signature verification failed */
#define  UCLIB_ERR_TMECOM_SIGN_ERROR  UCLIB_ERR(UCM_TMECOM, 2)      /* Remote engine signing failed */
#define  UCLIB_ERR_TMECOM_DERIVE_ERROR  UCLIB_ERR(UCM_TMECOM, 3)    /* Remote engine derivation failed */
#define  UCLIB_ERR_TMECOM_PUBKEY_NOT_SET  UCLIB_ERR(UCM_TMECOM, 4)  /* Public key not set*/
#define  UCLIB_ERR_TMECOM_PRIVKEY_NOT_SET  UCLIB_ERR(UCM_TMECOM, 5) /* Private key not set*/

#endif /* UCLIB_ERR_HEADER */
