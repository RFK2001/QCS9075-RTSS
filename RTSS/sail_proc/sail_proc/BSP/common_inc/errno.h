#ifndef ERRNO_H
#define ERRNO_H
/*===========================================================================

               E R R O R   N U M B E R   D E F I N I T I O N S

DESCRIPTION
  This contains the definition of the return codes (error numbers).
  Functions using this definition either return an error code, or set
  a global variable to the appropriate value.
 

Copyright (c) 2021-2025 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                      EDIT HISTORY FOR FILE

$Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/common_inc/errno.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
10/08/21   owen    Modify values from enum to defines for MISRA mitigation.
10/28/09   chm     Add support for more informational return values from 
                   WMDRM.
02/20/06   ssm     Deleted IxErrno in Interfaces dir and copied to services
                   folder
01/03/06   ssm     Cloned from errno.h

===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

/*===========================================================================

              DEFINITIONS AND CONSTANTS FOR ERROR CODES

===========================================================================*/

/*** Generic outcomes of operations ***/
#define E_SUCCESS            (0)    /* Operation successful                  */
#define E_FAILURE            (1)    /* Operation failed due to unknown err   */
#define E_NOT_ALLOWED        (2)    /* Operation currently not allowed       */
#define E_NOT_AVAILABLE      (3)    /* Operation currently not available     */
#define E_NOT_SUPPORTED      (4)    /* Operation not yet implemented         */
#define E_CANCELED           (5)    /* Operation was scheduled but canceled  */
#define E_ABORTED            (6)    /* Operation was started but interrp'd   */
#define E_INTERRUPTED        (7)    /* Operation was started but interrp'd   */
#define E_DEADLOCK           (8)    /* Operation would cause a deadlock      */
#define E_AGAIN              (9)    /* Caller should retry operation         */
#define E_RESET              (10)    /* Executing module was reset            */
#define E_WOULD_BLOCK        (11)    /* nonblocking IO operation would block  */
#define E_IN_PROGRESS        (12)    /* Operation in progress                 */
#define E_ALREADY_DONE       (13)    /* Operation already completed           */

/*** Memory management related error conditions ***/
#define E_NO_DSM_ITEMS       (14)    /* Out of DSM items                      */
#define E_NO_MEMORY          (15)    /* Allocation from a memory pool failed  */

/*** Parameter or data parsing related error conditions ***/
#define E_INVALID_ARG        (16)    /* Arg is not recognized                 */
#define E_OUT_OF_RANGE       (17)    /* Arg value is out of range             */
#define E_BAD_ADDRESS        (18)    /* Ptr arg is bad address                */
#define E_NO_DATA            (19)    /* Expected data) received none          */
#define E_BAD_DATA           (20)    /* Data failed sanity check) e.g. CRC    */
#define E_DATA_INVALID       (21)    /* Data is correct) but contents invalid */
#define E_DATA_EXPIRED       (22)    /* Data is not yet or not any more valid */
#define E_DATA_TOO_LARGE     (23)    /* Data is too large to process          */

/*** Hardware related error conditions ***/
#define E_NO_DEV             (24)    /* Hardware resource not available       */
#define E_DEV_FAILURE        (25)    /* Hardware failure                      */
#define E_NV_READ_ERR        (26)    /* Operation failed due to NV read err   */
#define E_NV_WRITE_ERR       (27)    /* Operation failed due to NV write err  */
#define E_EFS_ERROR          (28)    /* EFS interface error.                  */
#define E_DSP_ERROR          (29)    /* DSP returned error on cmd (-1)        */

/*** Protocol operation related error conditions ***/
#define E_TIMER_EXP          (30)    /* Operation not completed (timer exp)   */
#define E_VERSION_MISMATCH   (31)    /* Unexpected software or protocol ver.  */
#define E_TASK_SIG_ERR       (32)    /* Signal unknown or no handler          */
#define E_TASK_Q_FULL        (33)    /* Task queue is full                    */
#define E_PROT_Q_FULL        (34)    /* Protocol queue is full                */
#define E_PROT_TX_Q_FULL     (35)    /* Protocol tx data queue is full        */
#define E_PROT_RX_Q_FULL     (36)    /* Protocol rx data queue is full        */
#define E_PROT_UNKN_CMD      (37)    /* Protocol doesn't understand cmd       */
#define E_PROT_UNKN_IND      (38)    /* Protocol doesn't understand ind       */
#define E_PROT_UNKN_MSG      (39)    /* Protocol doesn't understand msg       */
#define E_PROT_UNKN_SIG      (40)    /* Protocol doesn't understand signal    */

/*** File related error conditions ***/
#define E_NO_ENTRY           (41)    /* No such file or directory             */
#define E_FILENAME_TOO_LONG  (42)    /* File name too long                    */
#define E_DIR_NOT_EMPTY      (43)    /* Directory not empty                   */
#define E_IS_DIR             (44)    /* Is a directory                        */
#define E_EOF                (45)    /* End Of File                           */
#define E_XDEV               (46)    /* Attempt to cross device               */
#define E_BAD_F              (47)    /* Bad file descriptor                   */
#define E_MAX_OPEN_FILES     (48)    /* Too many open files                   */
#define E_BAD_FMT            (49)    /* Bad formatted media                   */
#define E_FILE_EXISTS        (50)    /* File already exists                   */
#define E_EFS_FULL           (51)    /* No space left on device               */
#define E_NOT_DIR            (52)    /* Not a directory                       */
#define E_NOT_EFS_ITEM       (53)    /* Not an EFS2 item                      */
#define E_ALREADY_OPEN       (54)    /* File/Directory already open           */
#define E_BUSY               (55)    /* Device/Item is busy                   */
#define E_OUT_OF_NODES       (56)    /* Too many symbolic links encountered   */

/*** SQL related error conditions ***/
#define E_SQL_INTERNAL       (57)    /* An internal logic error in SQLite     */
#define E_SQL_BUSY           (58)    /* The database file is locked           */
#define E_SQL_LOCKED         (59)    /* A table in the database is locked     */
#define E_SQL_READONLY       (60)    /* Attempt to write a readonly database  */
#define E_SQL_IOERR          (61)    /* Some kind of disk I/O error occurred  */
#define E_SQL_CORRUPT        (62)    /* The database disk image is malformed  */
#define E_SQL_NOTFOUND       (63)    /* Table or record not found             */
#define E_SQL_FULL           (64)    /* Insertion failed because DB is full   */
#define E_SQL_CANTOPEN       (65)    /* Unable to open database file          */
#define E_SQL_PROTOCOL       (66)    /* Database lock protocol error          */
#define E_SQL_EMPTY          (67)    /* Database is empty                     */
#define E_SQL_SCHEMA         (68)    /* The database schema changed           */
#define E_SQL_CONSTRAINT     (69)    /* Abort due to constraint violation     */
#define E_SQL_MISMATCH       (70)    /* Data type mismatch                    */
#define E_SQL_MISUSE         (71)    /* Library used incorrectly              */
#define E_SQL_NOLFS          (72)    /* uses OS features not supported        */
#define E_SQL_FORMAT         (73)    /* Auxiliary database format error       */
#define E_SQL_NOTADB         (74)    /* file opened that is not a db file     */
#define E_SQL_ROW            (75)    /* sqlite3_step() has another row ready  */
#define E_SQL_DONE           (76)    /* sqlite3_step() has finished executing */
#define E_NO_ATTR            (77)    /* No Attr found                         */
#define E_INVALID_ITEM       (78)    /* Invalid Item found                    */
/*** Networking related error conditions ***/
#define E_NO_NET             (100)   /* Network is not connected (up)         */
#define E_NOT_SOCKET         (101)   /* Socket operation on non-socket        */
#define E_NO_PROTO_OPT       (102)   /* Network protocol not available        */
#define E_SHUTDOWN           (103)   /* Socket is being shut down             */
#define E_CONN_REFUSED       (104)   /* Connection refused by peer            */
#define E_CONN_ABORTED       (105)   /* Connection aborted                    */
#define E_IS_CONNECTED       (106)   /* Connection is already established     */
#define E_NET_UNREACH        (107)   /* Network destination is unreachable    */
#define E_HOST_UNREACH       (108)   /* Host destination is unreachable       */
#define E_NO_ROUTE           (109)   /* No route to destination               */
#define E_ADDR_IN_USE        (110)   /* IP address is already in use          */

/*** BCMCS related error conditions ***/
#define E_DB_INVALID         (111)   /* Entire database is invalid            */
#define E_FLOW_NOT_IN_ZONE   (112)   /* The flow is not in the specified zone */
#define E_ZONE_NOT_IN_DB     (113)   /* The specified zone is not in database */
#define E_BUF_OVERFLOW       (114)   /* The output buffer is too small        */

#ifdef ENABLE_ERRNO_EOF
#define E_EOF                (115)   /* End of file is reached                */
#endif

#define E_DB_OVERFLOW        (116)   /* The db is full, no further updates    */
#define E_DB_NO_OVERWRITE    (117)   /* value exists and overwrite is false   */
#define E_NOT_FOUND          (118)   /* Data not found                        */
#define E_NO_RIGHTS          (119)   /* No Rights/Permission to access data   */
#define E_HASH_VERIF_FAIL    (120)   /* Hash Verification on DCF Failed       */

  /* WMDRM Related Error Conditions */
#define E_INVALID_STORE_PSWD  (121)   /* Invalid Secure Store Password */
#define E_MACHINE_ID_MISMATCH (122)  /* Machine ID Mismatch */
 
/*** HTTP related error conditions ***/
#define E_CONTINUE               (200)   /* Server response status code of continue */

#define E_RESERVED           (0x7FFFFFFF)

#endif /* IXERRNO_H */
