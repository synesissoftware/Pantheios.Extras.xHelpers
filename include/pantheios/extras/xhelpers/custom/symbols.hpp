/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers/custom/symbols.hpp
 *
 * Purpose:     File specifying customisable symbols for
 *              the "Pantheios.Extras.xHelpers" library.
 *
 * Created:     1st May 2006
 * Updated:     10th September 2015
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2006-2015, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file pantheios/extras/xhelpers/custom/symbols.hpp
 * [C++ only] File specifying customisable symbols for the
 *   \ref group__library__pantheios_extras_xhelpers "Pantheios.Extras.xHelpers" library.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_CUSTOM_HPP_SYMBOLS
#define PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_CUSTOM_HPP_SYMBOLS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_CUSTOM_HPP_SYMBOLS_MAJOR       4
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_CUSTOM_HPP_SYMBOLS_MINOR       1
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_CUSTOM_HPP_SYMBOLS_REVISION    3
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_CUSTOM_HPP_SYMBOLS_EDIT        33
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/extras/xhelpers/internal/common.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Feature control
 */

/* The manner in which Pantheios.Extras.xHelpers reacts to unknown
 * exceptions - via the <code>catch(...) {}</code> clause - is determined by
 * the following user-definable pre-processor symbols:
 *
 * - PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL
 * - PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
 * - PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS
 * - PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
 *
 *
 * These apply according to the following rules:
 *
 * 1. If PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL is explicitly specified, no
 *    catch-all functionality is enabled, regardless of any other
 *    circumstances.
 *
 * 2. Except for rule 1, if PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL is
 *    explicitly specified, catch-all functionality is enabled, regardless
 *    of any other circumstances.
 *
 * 3. If neither PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL nor
 *    PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL are explicitly specified, then
 *    the presence of the pre-processor symbol NDEBUG will determine which
 *    is implicitly defined:
 *
 *      if NDEBUG      => PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
 *      else (!NDEBUG) => PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL
 *
 * 4. Only in the case where PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL is
 *    defined (either 2 or 3+NDEBUG), the symbols
 *    PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS and
 *    PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS take
 *    effect, as described in 4.1-4.3. Note that in all cases, the catch-all
 *    clause issues diagnostic logging statement and contingent report prior
 *    to taking the further action.
 *
 * 4.1. If PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS
 *      is defined, then the catch-all clause will do nothing with the
 *      caught exception, and return the unexpected code.
 *      <code>EXIT_FAILURE</code>.
 * 4.2. If PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS is
 *      defined, then the catch-all clause will issue a <code>throw;</code>
 *      statement, rethrowing the caught exception.
 * 4.3. If neither is defined, then the catch-all clause will issue a call
 *      to <code>pantheios::core::exitProcess()</code>, passing
 *      <code>EXIT_FAILURE</code> to designate the program exit status. This
 *      call will result in an immediate exit to the program, and non-local
 *      object destructors will not be invoked. Although this is not
 *      "desired", it is the most sensible, since a program that is in
 *      receipt of an unknown exception may not be in a state suitable for
 *      further execution (including deallocation of resources in non-local
 *      object destructors).
 */

#if defined(PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL)
 /* 1. */
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
#  undef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
# ifdef PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS
#  undef PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS
# endif /* PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS */
# ifdef PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
#  undef PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
# endif /* PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS */

#elif defined(PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL)
 /* 2. */
# ifdef PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL */

#else /* ? PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL || PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
 /* 3. */
# ifdef PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL */
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */

# ifdef NDEBUG
#  define PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
# else /* ? NDEBUG */
#  define PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL
# endif /* NDEBUG */

#endif /* PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL || PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */


#ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
 /* 4. */
# ifdef PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_XHELPERS_NO_CATCHALL */

# if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
 /* 4.1 */
#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
#   error Define at most one of PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS and PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
#  endif

# elif defined (PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
/* 4.2 */
#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
#   error Define at most one of PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS and PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
#  endif

# else /* PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS || PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS */
/* 4.1 */

# endif /* PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS || PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS */

#endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */

/* The manner in which non-normative conditions are logged is determined by
 * the following user-definable pre-processor symbols:
 *
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
 *
 *
 * These affect what is caught, and how corresponding reporting, via
 * diagnostic log statements, is carried out.
 *
 * Reporting:
 *
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log() is the log function
 *   used. It defaults to <code>log()</code>.
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert is the severity level
 *   applied to diagnostic logging of non-faulted exceptional conditions. It
 *   defaults to <code>alert</code>.
 * - PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency is the severity
 *   level applied to diagnostic logging of non-faulted exceptional
 *   conditions. It defaults to <code>emergency</code>.
 *
 * Coverage:
 *
 * By default, std::bad_alloc, std::exception and, conditionally, ... catch
 * clauses are employed. If compiling in the presence of MFC, CException*
 * and CMemoryException* are also caught. If you are working with other
 * frameworks whose exception types do not derive from std::exception, you
 * may insert catches for them using the macros 
 * PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0 and
 * PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1.
 *
 * PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0 is inserted
 * immediately after the standard memory exception clause(s).
 *
 * PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1 is inserted
 * immediately before the catch-all clause (if present).
 */

/** \def PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log
 *
 * User-customisable macro that is used in logging exceptions.
 *
 * Defaults to \c log
 */

/** \def PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert
 *
 * User-customisable macro that is used in logging exceptions.
 *
 * Defaults to \c alert
 */

/** \def PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency
 *
 * User-customisable macro that is used in logging exceptions.
 *
 * Defaults to \c emergency
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log
# define PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log         log
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert
# define PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert       alert
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency
# define PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency   emergency
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency */

/** \def PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
 *
 * User-customisable macro that defines a catch-clause to appear
 * immediately after the clause for <code>std::bad_alloc</code>.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
# define PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0 */

/** \def PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
 *
 * User-customisable macro that defines a catch-clause to appear
 * immediately preceeding the catch-all clause.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# define PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1 */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_CUSTOM_HPP_SYMBOLS */

/* ///////////////////////////// end of file //////////////////////////// */
