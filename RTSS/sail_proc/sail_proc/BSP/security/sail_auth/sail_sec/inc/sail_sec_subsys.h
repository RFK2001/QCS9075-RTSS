#ifndef SAIL_SEC_SUBSYS_H
#define SAIL_SEC_SUBSYS_H

#include <stdint.h>
#include <stdbool.h>
#include "secboot_swid.h"
#include "sec_img_auth.h"

struct SAILSECSubsys_s;
typedef struct 
{
  uintptr_t entry_point;
  Elf_Class elf_type;
  const sec_img_auth_elf_info_type *img_data;
  // Subsystem-specific configuration parameters and function callbacks
  int (* subsys_init)(struct SAILSECSubsys_s *);
}SAILSECSubsys_cfg;

typedef struct SAILSECSubsys_s
{
  uint32_t sw_id;
  bool uses_partial_hashing;
  SAILSECSubsys_cfg cfg;
} SAILSECSubsys;

int misc_init(SAILSECSubsys * subsys);

/**
 * @brief This API will be invoked just after authenticating debug policy image
 *  in boot sequence where this will do verification and apply of debug policy.
 *
 * @param [IN] subsys Context Pointer
 * 
 * @return E_FAILURE if sizeof(sec_dbg_t) is not within apdp range
 *         E_SUCCESS (other failures are not checked, if debug policy verification fails, its not applied and continues)
 */
int sail_dp_init(SAILSECSubsys * subsys);

SAILSECSubsys * SAILSECSubsys_get_ctx(uint32_t sw_id);
SAILSECSubsys * SAILSECSubsys_get_ctx_by_idx(size_t idx);
size_t SAILSECSubsys_get_num(void);
void sail_sec_subsys_configure(uint32_t sw_id);

#endif /* SAIL_SEC_SUBSYS_H */
