#ifndef UCLIB_PBL_ENV
#define UCLIB_PBL_ENV

/* ====================================================================
 * Copyright (c) 2017 - 2020,2022-2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Library - Environment APIs

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#define UCLIB_ENV_VERSION_MAJOR   1U
#define UCLIB_ENV_VERSION_MINOR   0U
#define UCLIB_ENV_MAGIC_NUMBER    0xD0E1A2D3U

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/
/** Environment Function Pointers */

/** CE HW Base Address */
typedef struct env_pbl_ce_hw_s
{
  uint32_t ce_base;
  uint32_t ce_bam_base;
  uint32_t ce_irq_num;
  uint32_t prng_base;
  uint32_t pka_base;
  uint32_t pke_base;
}env_pbl_ce_hw_t;

/** Sets Clock frequency for CE HW */
typedef int (*env_pbl_set_bandwidth)(env_resource ce, env_clklev lvl, uint32_t flags);
typedef size_t (*env_pbl_clk_ref)(env_var_op operation, env_resource ce);

typedef struct env_pbl_clk_cfg_s
{
  env_resource      ce_clk;           /** Clock Resource Name */
  env_clklev        lvl;              /** Bandwidth level     */
}env_pbl_clk_cfg_t;

typedef struct env_pbl_clk_fp_s
{
  env_pbl_clk_ref       ref;              /** Reference count     */
  env_pbl_set_bandwidth set_bw_fp;        /** Mandatory Env. callback if HW crypto is supported */
}env_pbl_clk_fp_t;

/** Heap API's */
typedef void * (*env_pbl_malloc)(uint32_t size);
typedef void (*env_pbl_free)(void *ptr);
typedef void * (*env_pbl_realloc)(void *ptr, uint32_t size);
typedef struct env_pbl_mem_magic_num_s
{
  uint32_t *magic_num;
  uint16_t *magic_num_index_array;
  uint16_t  magic_num_index;
}env_pbl_mem_magic_num_t;

typedef struct env_pbl_static_mem_s
{
  uint32_t            magic_num[5];
  uint32_t            mem_desc[32] ;
  uint16_t            magic_num_index_array[6];
  env_pbl_mem_magic_num_t mem_magic_num;
  unsigned int                mem_init_done;

  uint8_t             *mem_pool_ptr;
  size_t              mem_pool_size;
}env_pbl_static_mem_t;

typedef struct env_pbl_mm_s
{
  env_pbl_malloc       malloc_fp;          /** Mandatory Env. callback if heap management is supported in the image */
  env_pbl_free         free_fp;            /** Mandatory Env. callback if heap management is supported in the image */
  env_pbl_realloc      realloc_fp;         /** Mandatory Env. callback if heap management is supported in the image */

  env_pbl_static_mem_t *mem_mgr_ptr;       /** Mandatory pointer to Env. structure if heap management is not supported in the image */
}env_pbl_mm_t;

/** memory API's */
typedef void * (*env_pbl_memcpy)(void *dst, const void *src, size_t sz);
typedef void * (*env_pbl_memset)(void *str, int c, size_t n);
typedef int (*env_pbl_memcmp)(const void *str1, const void *str2, size_t n);
typedef int (*env_pbl_timesafe_memcmp)(const void *str1, const void *str2, size_t n);
typedef void * (*env_pbl_memmove)(void *dst, const void *src, size_t cpy_sz);

/** VA to PA conversion API */
typedef int (*env_pbl_vtop)(uintptr_t va, uintptr_t *pa);

/** DCache clean and invalidate API */
typedef void (*env_pbl_dcache_civ)(void *addr, size_t len);
/** DCache line size API */
typedef size_t (*env_pbl_dcache_sz)(void);

/** Memory barrier API */
typedef void (*env_pbl_mem_bar)(void);
/** Instruction barrier API */
typedef void (*env_pbl_ins_bar)(void);

typedef struct env_pbl_mu_s
{
  env_pbl_memcpy          memcpy_fp;           /** Mandatory Env. callback */
  env_pbl_memset          memset_fp;           /** Mandatory Env. callback */
  env_pbl_memcmp          memcmp_fp;           /** Mandatory Env. callback */
  env_pbl_timesafe_memcmp timesafe_memcmp_fp;  /** Mandatory Env. callback */
  env_pbl_memmove         memmove_fp;          /** Mandatory Env. callback */

  env_pbl_vtop            vtop_fp;             /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_pbl_dcache_civ      dcache_civ_fp;       /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_pbl_dcache_sz       dcache_sz_fp;        /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_pbl_mem_bar         mem_barrier_fp;      /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_pbl_ins_bar         inst_barrier_fp;     /** Mandatory Env. callback if HW crypto BAM mode is supported  */

}env_pbl_mu_t;

/** Mutex API's */
typedef int (*env_pbl_mutex_init)(void *lock);
typedef int (*env_pbl_mutex_lock)(void *lock);
typedef int (*env_pbl_mutex_release)(void *lock);
typedef struct env_pbl_mtx_cfg_s
{
  void*             lock;              /** Optional CE lock       */
}env_pbl_mtx_cfg_t;

typedef struct env_pbl_mtx_fp_s
{
  env_pbl_mutex_init    mutex_init_fp;     /** Optional Env. callback */
  env_pbl_mutex_lock    mutex_lock_fp;     /** Optional Env. callback */
  env_pbl_mutex_release mutex_release_fp;  /** Optional Env. callback */
}env_pbl_mtx_fp_t;

/** PRNG Access API's */
typedef int (*env_pbl_prng_enable_access)(void);
typedef int (*env_pbl_prng_disable_access)(void);
/** PRNG Get Data API */
typedef size_t (*pbl_prng_cb) (uint8_t *buf, size_t buf_sz);
typedef struct env_pbl_prng_cfg_s
{
  unsigned int                    prng_ac_en;  /** Mandatory flag         */
  unsigned int                    init_done;
  env_pbl_clk_cfg_t           prng_clk;
}env_pbl_prng_cfg_t;

typedef struct env_pbl_prng_fp_s
{
  env_pbl_prng_enable_access  prng_en_fp;  /** Optional Env. callback */
  env_pbl_prng_disable_access prng_dis_fp; /** Optional Env. callback */
  pbl_prng_cb                 prng_cb_fp;  /** Mandatory Env. callback if UCLIB is integrated in user space image */
  env_pbl_clk_fp_t            prng_clk_fp;
}env_pbl_prng_fp_t;

/** Log API's */
typedef void (*env_pbl_log)(const char* fmt, va_list ap);



/** BAM API's */
typedef int (*event_pbl_fp)(void);
typedef void (*pbl_reg_dump_init_fp)(void *ptr);

typedef struct env_pbl_bam_ctx_cfg_s
{
  void         *bam_drv_ctx;
  uint8_t      *tx_desc;                    /** Mandatory if BAM Engine is used. Uncached Memory with 8-byte alignment               */
  uint8_t      *rx_desc;                    /** Mandatory if BAM Engine is used. Uncached Memory with 8-byte alignment               */
  uint8_t      *rslt;                       /** Mandatory if BAM Engine is used. Size: 256 bytes with cache line size alignment      */
  uint8_t      *container;                  /** Mandatory if BAM Engine is used. Size: 256 bytes with cache line size alignment      */

  uint8_t      *cmd_desc_buf;               /** Mandatory if BAM Engine is used. Size is dependent on the max number of commands we
                                                expect to write to the CE engine for a single operation                              */
  size_t       cmd_desc_buf_sz;             /** Mandatory if BAM Engine is used. Size of command descriptor buffer                   */
  size_t       desc_sz;                     /** Mandatory if BAM Engine is used. Size in bytes. Must be multiple of 8 bytes          */
  unsigned int         uses_550_features;           /** Indicates whether CE 5.5.0 features (pipe keys, pattern processing) are required.    */
  unsigned int         cmds_over_hwio;              /** Indicates if need to use HWIO for sending command while use BAM for data             */
  uint8_t      default_pipeset_num;         /** Indicates the default pipe set num. 0 - for TZ; 2 - for uefi                         */

}env_pbl_bam_ctx_cfg_t;

typedef struct env_pbl_bam_ctx_fp_s
{
  /** BAM interrupt mode */
  event_pbl_fp              event_create;    /** Mandatory if BAM is used in interrupt mode */
  event_pbl_fp              event_delete;    /** Mandatory if BAM is used in interrupt mode */
  event_pbl_fp              event_trigger;   /** Mandatory if BAM is used in interrupt mode */
  event_pbl_fp              event_wait;      /** Mandatory if BAM is used in interrupt mode */
  pbl_reg_dump_init_fp      reg_dump_init;   /** For dumping crypto and bam registers upon crash */
}env_pbl_bam_ctx_fp_t;


typedef struct
{
  size_t        key_size_bits;

  const uint8_t *p;
  const uint8_t *a;
  const uint8_t *b;
  const uint8_t *g_x;
  const uint8_t *g_y;
  const uint8_t *n;

  const uint8_t *m_prime;
  const uint8_t *r_sqr_mod_m;
  const uint8_t *n_prime;
  const uint8_t *r_sqr_mod_n;
} ec_pbl_curve_t;

typedef struct env_pbl_pka_hw_s
{
  void *               pka_info;
  short                ee;
  unsigned int                 always_reload_fw;

  const uint32_t *     fw_arr;
  size_t               fw_arr_len;
  const uint16_t *     entry_points_arr;
  size_t               entry_points_arr_len;
  const ec_curve_t *   pka_curve_info_arr;
  size_t               pka_curve_info_arr_len;

  env_pbl_clk_cfg_t        pka_clk;
} env_pbl_pka_hw_cfg_t;

typedef struct env_pbl_pke_hw_s
{
  void *                     pke_info;
  short                      ee;

  uint32_t                   sram_offset;
  unsigned int               prng_seeded;
  const ec_pbl_curve_t *     pke_curve_info_arr;
  size_t                     pke_curve_info_arr_len;

  env_clk_cfg_t              pke_clk;
} env_pbl_pke_hw_cfg_t;

typedef unsigned int (*env_pbl_is_crypto_operation_allowed)(crypto_operation_enum operation);
typedef unsigned int (*env_pbl_is_fips_enabled)(void);

/** Crypto Yield API */
typedef void (*env_pbl_crypto_yield)(unsigned int yield);

/** Busywait */
typedef void (*env_pbl_busywait_fp)(uint32_t us);

/* Environment interface for Hardware Key Manager */
typedef struct env_pbl_hwkm_key_info_s
{
  const uint8_t *key;
  size_t key_sz;
  uint8_t pipe;
  unsigned int odd_idx;
  unsigned int auth_key;
  unsigned int encr_key;
} env_pbl_hwkm_key_info_t;

typedef unsigned int (*env_pbl_hwkm_install_fp)(env_hwkm_key_info_t *key);

/** Callback Function API's */
typedef const struct env_pbl_fp_s
{
  /** Clock Callback Function API's */
  env_pbl_clk_fp_t clk_fp;

  /** Heap Callback Function API's */
  env_pbl_mm_t mm;

  /** memory Callback Function API's */
  env_pbl_mu_t mem;

  /** Mutex Callback Function API's */
  env_pbl_mtx_fp_t mtx_fp;

  /** PRNG Callback Function Access API's */
  env_pbl_prng_fp_t prng_fp;

  /** Log Callback Function API's */
  env_pbl_log log_fp;

  /** BAM Callback Function API's */
  env_pbl_bam_ctx_fp_t bam_fp;

  /** selftest Callback Function API's */
  env_pbl_is_crypto_operation_allowed is_crypto_operation_allowed_fp;
  env_pbl_is_fips_enabled is_fips_enabled_fp;

  /** Crypto Yield Callback Function API */
  env_pbl_crypto_yield crypto_yield_fp;

  env_pbl_busywait_fp busywait_fp;

  env_pbl_hwkm_install_fp install_hw_key;
} env_pbl_fp_t;

/** Configurable env struct */
typedef struct env_pbl_cfg_s
{
  /** CE HW Base Address */
  env_pbl_ce_hw_t ce;

  /** Clock API's */
  env_pbl_clk_cfg_t clk;

  /** Mutex API's */
  env_pbl_mtx_cfg_t mtx;

  /** PRNG Access API's */
  env_pbl_prng_cfg_t prng;

  /** BAM Driver Buffer Allocations */
  env_pbl_bam_ctx_cfg_t bam;

  env_pbl_pka_hw_cfg_t pka;

  env_pbl_pke_hw_cfg_t pke;
} env_pbl_cfg_t;

struct env_pbl_s
{
  uint32_t ver;
  uint32_t magic;

  env_pbl_fp_t env_fp;

  env_pbl_cfg_t *env_cfg_ptr;
};

typedef const struct env_pbl_s env_pbl_t;

/**
 * @brief Returns pointer to HYP environment structure which will be used by PBL. This has been
 *        initialized by the image.
 *
 * @return pointer to environment structure.
 */
env_pbl_t * ucenv_get_pbl_env(void);

/**
 * @brief PBL ENV Initialization API.
 *
 */
void ucenv_pbl_init(void);

#endif /* UCLIB_PBL_ENV */
