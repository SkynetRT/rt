/****************************************************************************
 * include/assert.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __INCLUDE_ASSERT_H
#define __INCLUDE_ASSERT_H

#include <stddef.h>

#ifndef __ASSEMBLY__

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/compiler.h>
#include <sys/types.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Macro Name: PANIC, ASSERT, VERIFY, et al. */

#undef PANIC        /* Unconditional abort */
#undef ASSERT       /* Assert if the condition is not true */
#undef VERIFY       /* Assert if a function returns a negative value */
#undef DEBUGPANIC   /* Like PANIC, but only if CONFIG_DEBUG_ASSERTIONS is defined */
#undef DEBUGASSERT  /* Like ASSERT, but only if CONFIG_DEBUG_ASSERTIONS is defined */
#undef DEBUGVERIFY  /* Like VERIFY, but only if CONFIG_DEBUG_ASSERTIONS is defined */

/* Macro to define the assertions file name and file line
 * | Function         |CONFIG                            | Show name/line |
 * | ---              | ---                              | ---            |
 * |assert(), ASSERT()|CONFIG_ASSERTIONS_FILENAME=y      | Yes            |
 * |assert(), ASSERT()|CONFIG_ASSERTIONS_FILENAME=n      | No             |
 * |DEBUGASSERT()     |CONFIG_DEBUG_ASSERTIONS_FILENAME=y| Yes            |
 * |DEBUGASSERT()     |CONFIG_DEBUG_ASSERTIONS_FILENAME=n| No             |
 */

#ifdef CONFIG_HAVE_FILENAME
#  ifdef CONFIG_DEBUG_ASSERTIONS_FILENAME
#    define __DEBUG_ASSERT_FILE__ __FILE__
#    define __DEBUG_ASSERT_LINE__ __LINE__
#  endif
#  ifdef CONFIG_ASSERTIONS_FILENAME
#    define __ASSERT_FILE__ __FILE__
#    define __ASSERT_LINE__ __LINE__
#  endif
#endif

#ifndef __DEBUG_ASSERT_FILE__
#  define __DEBUG_ASSERT_FILE__ 0
#  define __DEBUG_ASSERT_LINE__ 0
#endif

#ifndef __ASSERT_FILE__
#  define __ASSERT_FILE__ 0
#  define __ASSERT_LINE__ 0
#endif

#define PANIC() __assert(__ASSERT_FILE__, __ASSERT_LINE__, "panic")
#define PANIC_WITH_REGS(msg, regs) _assert(__ASSERT_FILE__, \
                                           __ASSERT_LINE__, msg, regs)

#define __ASSERT__(f, file, line, _f) \
  (predict_false(!(f))) ? __assert(file, line, _f) : ((void)0)

#define __VERIFY__(f, file, line, _f) \
  (predict_false((f) < 0)) ? __assert(file, line, _f) : ((void)0)

#ifdef CONFIG_DEBUG_ASSERTIONS_EXPRESSION
#  define _ASSERT(f,file,line) __ASSERT__(f, file, line, #f)
#  define _VERIFY(f,file,line) __VERIFY__(f, file, line, #f)
#else
#  define _ASSERT(f,file,line) __ASSERT__(f, file, line, NULL)
#  define _VERIFY(f,file,line) __VERIFY__(f, file, line, NULL)
#endif

#ifdef CONFIG_DEBUG_ASSERTIONS
#  define DEBUGPANIC()   __assert(__DEBUG_ASSERT_FILE__, __DEBUG_ASSERT_LINE__, "panic")
#  define DEBUGASSERT(f) _ASSERT(f, __DEBUG_ASSERT_FILE__, __DEBUG_ASSERT_LINE__)
#  define DEBUGVERIFY(f) _VERIFY(f, __DEBUG_ASSERT_FILE__, __DEBUG_ASSERT_LINE__)
#else
#  define DEBUGPANIC()
#  define DEBUGASSERT(f) ((void)(1 || (f)))
#  define DEBUGVERIFY(f) ((void)(f))
#endif

/* The C standard states that if NDEBUG is defined, assert will do nothing.
 * Users can define and undefine NDEBUG as they see fit to choose when assert
 * does something or does not do anything.
 *
 * #define assert(ignore) ((void)0)
 *
 * Reference link:
 * https://pubs.opengroup.org/onlinepubs/009695399/basedefs/assert.h.html
 */

#ifdef NDEBUG
#  define assert(f) ((void)0)
#else
#  define assert(f) _ASSERT(f, __ASSERT_FILE__, __ASSERT_LINE__)
#endif

/* ASSERT/VERIFY are NuttX-specific APIs.
 * They are always enabled, regardless of NDEBUG/CONFIG_DEBUG_ASSERTIONS.
 * The argument is evaluated exactly once.
 */

#define ASSERT(f) _ASSERT(f, __ASSERT_FILE__, __ASSERT_LINE__)
#define VERIFY(f) _VERIFY(f, __ASSERT_FILE__, __ASSERT_LINE__)

/* Suppress 3rd party library redefine _assert/__assert */

#define _assert _assert
#define __assert __assert

/* Definition required for C11 compile-time assertion checking.  The
 * static_assert macro simply expands to the _Static_assert keyword.
 */

#ifndef __cplusplus
#  if defined(__STDC_VERSION__) && __STDC_VERSION__  > 199901L
#    define static_assert _Static_assert
#  else
#    define static_assert(cond, msg) \
       extern int (*__static_assert_function(void)) \
       [!!sizeof (struct { int __error_if_negative: (cond) ? 2 : -1; })]
#  endif
#endif

#ifndef COMPILE_TIME_ASSERT
#  define COMPILE_TIME_ASSERT(x) static_assert(x, "compile time assert failed")
#endif

/* Force a compilation error if condition is true, but also produce a
 * result (of value 0 and type int), so the expression can be used
 * e.g. in a structure initializer (or where-ever else comma expressions
 * aren't permitted).
 */

#define BUILD_BUG_ON_ZERO(e) ((int)(sizeof(struct { int:(-!!(e)); })))

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: _assert
 *
 * Description:
 *   This is the assert system call that performs the core dump etc. Function
 *   might not return if it is not safe to do so (in IRQ or in IDLE task).
 *
 ****************************************************************************/

void _assert(FAR const char *filename, int linenum,
             FAR const char *msg, FAR void *regs);

/****************************************************************************
 * Name: __assert
 *
 * Description:
 *   This is the user space assert procedure.
 *
 ****************************************************************************/

void __assert(FAR const char *filename, int linenum,
              FAR const char *msg) noreturn_function;

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __INCLUDE_ASSERT_H */
