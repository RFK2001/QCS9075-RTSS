/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*
 * Portions Copyright 2017 The Fuchsia Authors
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT

 * Portions Copyright (c) 2014 Google Inc. All rights reserved
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <asm.h>

.text

// TODO: this definition is also duplicated in spinlock.h file
// #define USE_TICKET_LOCKS

#ifdef USE_TICKET_LOCKS

FUNCTION(arch_spin_lock)
  //; r0 holds 2 16 bit quantities
  //; the lower halfword holds the current ticket number
  //; the higher halfword holds the next ticket number but the
  //;   value in next ticket is already taken, next value is
  //;   the one which new client can get

  prfm pstl1keep, [x0]           //; preload into cache in unique state

get_ticket:
  ldaxr  w2, [x0]               //; read current and next
  add    w2, w2, #0x10000       //; increment the next number
  stxr   w3, w2, [x0]           //; and update the value
  cbnz   w3, get_ticket         //; did the exclusive pass – retry if not
  and    w3, w2, 0xffff
  cmp    w3, w2, lsr #16        //; is the current ticket ours
  b.eq   got_lock
  sevl

wait_for_ticket_turn:
  wfe
  ldaxrh  w3, [x0]              //; read current value
  cmp     w3, w2, lsr #16       //; compare it with our allocated ticket
  b.ne    wait_for_ticket_turn  //; retry (spin) if it is not the same

got_lock:
  ret

FUNCTION(arch_spin_unlock)
  prfm pstl1keep, [x0]          //; preload into cache in unique state

  ldaxrh  w2, [x0]              //; read current ticket
  add     w2, w2, #0x1          //; increment ticket # for service
  stlrh   w2, [x0]
  ret

FUNCTION(arch_spin_trylock)
get_try_ticket:
  ldaxr  w2, [x0]               //; read current and next
  add    w2, w2, #0x10000       //; increment the next number
  stxr   w3, w2, [x0]           //; and update the value
  cbnz   w3, get_try_ticket     //; did the exclusive pass – retry if not
  and    w3, w2, 0xffff
  cmp    w3, w2, lsr #16        //; is the current ticket ours
  b.eq   got_try_lock

did_not_get_it:
  mov   x0, xzr
  b .
  ret

got_try_lock:
  mov   x0, #1
  b .
  ret

#else  // ; ================ Normal locks =====
//@ToDo check if we can use the common mutex implementation after testing
FUNCTION(arch_spin_trylock)
	mov	  r2, r0
	mov	  r1, #1
	ldrex r0, [r2]
	//cbnz	r0, 1f
	cmp   r0, #0
    bne   1f	
	strex	r0, r1, [r2]
1:
	bx    lr

FUNCTION(arch_spin_lock)
	mov	 r1, #1
	sevl
1:
	wfe
	ldrex	r2, [r0]
	cmp     r2, #0
    bne     1b
	strex	r2, r1, [r0]
	cmp     r2, #0
    bne     1b
	bx      lr

FUNCTION(arch_spin_unlock)
	//stlr	xzr, [r0]
	mov     r1, #0
	stl     r1,[r0]
	bx    lr

#endif


