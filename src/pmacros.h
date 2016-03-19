/*
 * Copyright (C) 2010-2016 Alexander Saprykin <xelfium@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 */

/**
 * @file pmacros.h
 * @brief Miscellaneous macros
 * @author Alexander Saprykin
 *
 * Contains useful macros for detecting host OS, compiler, etc.
 */


#if !defined (__PLIB_H_INSIDE__) && !defined (PLIB_COMPILATION)
#  error "Header files shouldn't be included directly, consider using <plib.h> instead."
#endif

#ifndef __PMACROS_H__
#define __PMACROS_H__

#include <stdio.h>

/* Operating systems */

/**
 * @def P_OS_DARWIN
 * @brief Darwin based operating system (i.e. Mac OS X)
 * @since 0.0.1
 */

/**
 * @def P_OS_DARWIN32
 * @brief Darwin based 32-bit operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_DARWIN64
 * @brief Darwin based 64-bit operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_BSD4
 * @brief BSD 4.x based operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_FREEBSD
 * @brief FreeBSD based operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_NETBSD
 * @brief NetBSD operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_OPENBSD
 * @brief OpenBSD operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_AIX
 * @brief IBM AIX operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_HPUX
 * @brief HP-UX operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_SOLARIS
 * @brief Sun (Oracle) Solaris operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_QNX
 * @brief QNX 4.x operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_QNX6
 * @brief QNX Neutrino 6.x operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_SCO
 * @brief SCO OpenServer operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_UNIXWARE
 * @brief UnixWare operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_UNIXWARE7
 * @brief UnixWare 7 operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_VMS
 * @brief VMS operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_UNIX
 * @brief UNIX based operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_LINUX
 * @brief Linux based operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC9
 * @brief Apple's Mac OS 9 operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC
 * @brief Apple's Mac OS X operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC32
 * @brief Apple's Mac OS X 32-bit operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC64
 * @brief Apple's Mac OS X 64-bit operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_CYGWIN
 * @brief Microsoft's Windows POSIX environment
 * @since 0.0.1
 */

/**
 * @def P_OS_WIN
 * @brief Microsoft's Windows 32-bit operating system
 * @since 0.0.1
 */

/**
 * @def P_OS_WIN64
 * @brief Microsoft's Windows 64-bit operating system
 * @since 0.0.1
 */

/* We need this to disable Doxygen warnings */

#ifdef DOXYGEN
#  define P_OS_DARWIN
#  define P_OS_DARWIN32
#  define P_OS_DARWIN64
#  define P_OS_BSD4
#  define P_OS_FREEBSD
#  define P_OS_NETBSD
#  define P_OS_OPENBSD
#  define P_OS_AIX
#  define P_OS_HPUX
#  define P_OS_SOLARIS
#  define P_OS_QNX
#  define P_OS_QNX6
#  define P_OS_SCO
#  define P_OS_UNIXWARE
#  define P_OS_UNIXWARE7
#  define P_OS_VMS
#  define P_OS_UNIX
#  define P_OS_LINUX
#  define P_OS_MAC9
#  define P_OS_MAC
#  define P_OS_MAC32
#  define P_OS_MAC64
#  define P_OS_CYGWIN
#  define P_OS_WIN
#  define P_OS_WIN64
#endif

/* Darwin and BSD4 */
#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
#  define P_OS_DARWIN
#  define P_OS_BSD4
#  ifdef __LP64__
#    define P_OS_DARWIN64
#  else
#    define P_OS_DARWIN32
#  endif
/* Mac OS 9 */
# elif defined(Macintosh) || defined(macintosh)
#  define P_OS_MAC9
#elif defined(__CYGWIN__)
/* Cygwin */
#  define P_OS_CYGWIN
/* Microsoft Windows */
#elif defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64)
#  define P_OS_WIN64
#elif defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
#  define P_OS_WIN
/* Linux */
#elif defined(__linux) || defined(__linux__)
#  define P_OS_LINUX
/* FreeBSD */
#elif defined(__FreeBSD__) || defined(__DragonFly__)
#  define P_OS_FREEBSD
#  define P_OS_BSD4
/* NetBSD */
#elif defined(__NetBSD__)
#  define P_OS_NETBSD
#  define P_OS_BSD4
/* OpenBSD */
#elif defined(__OpenBSD__)
#  define P_OS_OPENBSD
#  define P_OS_BSD4
/* IBM AIX */
#elif defined(_AIX)
#  define P_OS_AIX
#elif defined(hpux) || defined(__hpux)
#  define P_OS_HPUX
/* Sun Solaris */
#elif defined(__sun) || defined(sun)
#  define P_OS_SOLARIS
/* QNX6 */
#elif defined(__QNXNTO__)
#  define P_OS_QNX6
/* QNX */
#elif defined(__QNX__)
#  define P_OS_QNX
#elif defined(_SCO_DS)
/* SCO OpenServer */
#  define P_OS_SCO
/* SCO UnixWare + OpenServer (UDK + OUDK) */
#elif defined(__USLC__) || defined(__UNIXWARE__)
#  define P_OS_UNIXWARE
#  define P_OS_UNIXWARE7
/* SCO UnixWare + GCC */
#elif defined(__svr4__) && defined(i386)
#  define P_OS_UNIXWARE
#  define P_OS_UNIXWARE7
/* VMS */
#elif defined(VMS) || defined(__VMS)
#  define P_OS_VMS
#endif

#ifdef P_OS_WIN64
#  define P_OS_WIN
#endif

#if defined(P_OS_DARWIN)
#  define P_OS_MAC
#  if defined(P_OS_DARWIN64)
#     define P_OS_MAC64
#  elif defined(P_OS_DARWIN32)
#     define P_OS_MAC32
#  endif
#endif

#if defined(P_OS_WIN) || defined(P_OS_MAC9)
#  undef P_OS_UNIX
#elif !defined(P_OS_UNIX)
#  define P_OS_UNIX
#endif

/* Compilers */

/**
 * @def P_CC_MSVC
 * @brief Microsoft Visual Studio compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_GNU
 * @brief GNU C compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_MINGW
 * @brief MinGW compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_INTEL
 * @brief Intel C compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_CLANG
 * @brief LLVM Clang compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_SUN
 * @brief Sun WorkShop/Studio C compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_XLC
 * @brief IBM XL C compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_HP
 * @brief HP C/aC++ compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_WATCOM
 * @brief Watcom C compiler
 * @since 0.0.1
 */

/**
 * @def P_CC_BORLAND
 * @brief Borland C/C++ compiler
 * @since 0.0.1
 */

#ifdef DOXYGEN
#  define P_CC_MSVC
#  define P_CC_GNU
#  define P_CC_MINGW
#  define P_CC_INTEL
#  define P_CC_CLANG
#  define P_CC_SUN
#  define P_CC_XLC
#  define P_CC_HP
#  define P_CC_WATCOM
#  define P_CC_BORLAND
#endif

/* Microsoft Visual C/C++ */
#if defined(_MSC_VER)
#  define P_CC_MSVC
#  if defined(__INTEL_COMPILER)
#    define P_CC_INTEL
#  endif
/* GNU C */
#elif defined(__GNUC__)
#  define P_CC_GNU
#  if defined(__MINGW32__)
#    define P_CC_MINGW
#  endif
#  if defined(__INTEL_COMPILER)
#    define P_CC_INTEL
#  endif
#  if defined(__clang__)
#    define P_CC_CLANG
#  endif
/* Sun (Oracle) WorkShop/Studio */
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#  define P_CC_SUN
/* IBM XL C */
#elif defined(__xlc__) || defined(__xlC__)
#  define P_CC_XLC
/* HP C/aC++ */
#elif defined(__HP_cc) || defined(__HP_aCC)
#  define P_CC_HP
/* Watcom C++ */
#elif defined(__WATCOMC__)
#  define P_CC_WATCOM
/* Borland C/C++ */
#elif defined(__BORLANDC__)
#  define P_CC_BORLAND
/* Intel C/C++ */
#elif defined(__INTEL_COMPILER)
#  define P_CC_INTEL
#endif

/* For Clang */
#ifndef __has_attribute
#  define __has_attribute(x) 0
#endif

/**
 * @def P_GNUC_WARN_UNUSED_RESULT
 * @brief Gives warning if returned from function result is not used
 */
#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  define P_GNUC_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#  define P_GNUC_WARN_UNUSED_RESULT
#endif

/**
 * @def P_LIB_API
 * @brief Export symbols macro
 */
#if defined(P_CC_MSVC) || defined(P_CC_BORLAND)
#  define P_LIB_API __declspec(dllexport)
#else
#  define P_LIB_API
#endif

/* Oracle Solaris Studio at least since 12.2 has ((noreturn)) attribute */

/**
 * @def P_NO_RETURN
 * @brief Notifies compiler that function will never return a value (e.g. abort ())
 */
#ifdef P_CC_MSVC
#  define P_NO_RETURN __declspec(noreturn)
#elif __has_attribute(noreturn) || \
      defined(P_CC_GNU) || \
     (defined(__SUNPRO_C) && __SUNPRO_C >= 0x5110) || \
     (defined(__SUNPRO_CC) && __SUNPRO_CC >= 0x5110)
#  define P_NO_RETURN __attribute__((noreturn))
#else
#  define P_NO_RETURN
#endif

/**
 * @def P_UNUSED
 * @brief Macro to by-pass compiler warning on unused variables
 */
#define P_UNUSED(a) ((void) a)

/**
 * @def P_WARNING
 * @brief Prints warning message
 * @param msg Message to print.
 */
#define P_WARNING(msg) printf ("** Warning: %s **\n", msg)

/**
 * @def P_ERROR
 * @brief Prints error message
 * @param msg Message to print.
 */
#define P_ERROR(msg) printf ("** Error: %s **\n", msg)

/**
 * @def P_DEBUG
 * @brief Prints debug message
 * @param msg Message to print.
 */
#define P_DEBUG(msg) printf ("** Debug: %s **\n", msg)

/**
  * @def P_BEGIN_DECLS
  * @brief Starts .h file declarations to be exported as C functions
  */
/**
  * @def P_END_DECLS
  * @brief Closes .h file declarations to be exported as C functions,
  * should be always used after #P_END_DECLS
  */
#ifdef __cplusplus
#  define P_BEGIN_DECLS extern "C" {
#  define P_END_DECLS }
#else
#  define P_BEGIN_DECLS
#  define P_END_DECLS
#endif

#endif /* __PMACROS_H__ */
