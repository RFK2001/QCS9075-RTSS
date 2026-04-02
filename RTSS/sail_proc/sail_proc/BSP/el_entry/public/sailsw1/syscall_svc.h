/**
 * @file syscall.h
 * @brief Sail definitions
 * Header file for the definition of Sail SVC calls
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/

#ifndef SYSCALL_SVC_H_
#define SYSCALL_SVC_H_
/*===========================================================================
                           INCLUDE FILES
===========================================================================*/

/*===========================================================================
                           DEFINES
===========================================================================*/

/*===========================================================================
                           EXTERNS
===========================================================================*/
extern void vFreertosSvcHookWrapper( uint32_t uxSvcNumber );
extern boolean xSyscallIsPrivilegedMode( void );
extern int svc_call(uint32_t *svc_id, uint32_t *param_id, uint32_t *arg1, uint32_t *arg2, uint32_t *arg3, uint32_t *arg4);


#endif /* SYSCALL_SVC_H_ */
