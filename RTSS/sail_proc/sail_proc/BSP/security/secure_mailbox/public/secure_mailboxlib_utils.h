#ifndef SECURE_MAILBOXLIB_UTILS_H
#define SECURE_MAILBOXLIB_UTILS_H
/*===========================================================================

   Edit History:
   
When       Who     What, where, why
--------   ---     ----------------------------------------------------------
08/22/23    NR    SECURE_MAILBOX- Utilities 

=============================================================================

  Copyright (c) 2023 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  
===========================================================================*/

/*===========================================================================
              Conditional Check and Flow Control Macros
 ===========================================================================*/
#include "secure_mailbox_config.h"

#define SECURE_MAILBOX_GUARD(cond, st)          if (!(cond)){                                                            \
                                                  SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO, "SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, st);       \
                                                  return (st);                                                            \
                                                }

#define SECURE_MAILBOX_GUARD_PRINT_ERROR(cond, ret , st)          if (!(cond)){                                                            \
                                                             SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO, "SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, ret);   \
															  return (st);															  \
															}

#define SECURE_MAILBOX_GAURD_TO_EXIT(cond, label, ret)          if (!(cond)) {                                                            \
                                                SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO, "SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, ret);   \
												goto label;                                                                                           \
								     			}

#define SECURE_MAILBOX_PASS_TO_EXIT(cond, label, ret)          if (cond){                                                            \
																  SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO, "SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, st);	   \
																  goto label;														  \
																}

#define SECURE_MAILBOX_PASS(cond, st)           if (cond) { \
                                                  return (st); \
                                                }
                                                

#define SECURE_MAILBOX_BAIL_IF_FALSE(cond)      if (!(cond)) { \
                                                  return;       \
                                                }

#define SECURE_MAILBOX_BAIL_IF_TRUE(cond)       if (0 != cond) {  \
                                                  return;    \
                                                }

#define SECURE_MAILBOX_JMP_IF_FALSE(cond, label) if (!(cond)) { \
                                                  goto label;  \
                                                }

#define SECURE_MAILBOX_JMP_IF_TRUE(cond, label) if (0 != cond) {  \
                                                  goto label; \
                                                }

#define SECURE_MAILBOX_GUARD_OVERFLOW(addr, sz, st) if (((uintptr_t)(addr) + (sz)) < (uintptr_t)(addr)) {                     \
                                                    SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO, "SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, st); \
                                                  return (st);                                                            \
                                                }

#define SECURE_MAILBOX_GUARD_UNDERFLOW(addr, sz, st)    if (((uintptr_t)(addr) - (sz)) > (uintptr_t)(addr)) {                     \
                                                    SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO,"SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, st); \
                                                  return (st);                                                            \
                                                }

#define SECURE_MAILBOX_GUARD_JMP_EXIT_PRINT_RET(cond, printret, ret, st, label)                                                                       \
                                                do {                                                                        \
                                                  if (!(cond)) {                                                            \
                                                    (ret) = (st);                                                           \
                                                    SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO,"SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, printret); \
                                                    goto label;                                                             \
                                                  }                                                                         \
                                                } while (0);
                                                  

#define SECURE_MAILBOX_GUARD_JMP_EXIT_SET_RET(cond, ret, st, label)                               \
                                                 do {            \
                                                   if (!(cond)) { \
                                                      (ret) = (st); \
                                                      SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO,"SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, ret); \
                                                      goto label;                                                             \
                                                    }                                                                         \
                                                 } while (0);

#define SECURE_MAILBOX_GUARD_JMP_EXIT(cond, ret, label)                                                                       \
                                                do {                                                                        \
                                                  if (!(cond)) {                                                            \
                                                    SECURE_MAILBOX_DEBUG_LOG(SAIL_INFO,"SECURE_MAILBOX: %s(%d), ret=%x", __FUNCTION__, __LINE__, ret); \
                                                    goto label;                                                             \
                                                  }                                                                         \
                                                } while (0);
#endif                             