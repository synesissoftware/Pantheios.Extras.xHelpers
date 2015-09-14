/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers/com/custom/symbols.hpp
 *
 * Purpose:     File specifying customisable symbols for use with the COM
 *              overloads in the "Pantheios.Extras.xHelpers" library.
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


/** \file pantheios/extras/xhelpers/com/custom/symbols.hpp
 * [C++ only] File specifying customisable symbols for use with the COM
 *   overloads in the
 *   \ref group__library__pantheios_extras_xhelpers "Pantheios.Extras.xHelpers" library.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_COM_CUSTOM_HPP_SYMBOLS
#define PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_COM_CUSTOM_HPP_SYMBOLS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_CUSTOM_HPP_SYMBOLS_MAJOR       4
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_CUSTOM_HPP_SYMBOLS_MINOR       0
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_CUSTOM_HPP_SYMBOLS_REVISION    4
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_CUSTOM_HPP_SYMBOLS_EDIT        34
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/extras/xhelpers/internal/common.hpp>
#include <pantheios/extras/xhelpers/custom/symbols.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Feature control
 */

#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
# define PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */



/** \def PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log
 *
 * User-customisable macro that is used in logging exceptions.
 *
 * Defaults to \c PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log
 */

/** \def PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert
 *
 * User-customisable macro that is used in logging exceptions.
 *
 * Defaults to \c PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert
 */

/** \def PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency
 *
 * User-customisable macro that is used in logging exceptions.
 *
 * Defaults to \c PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log
# define PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log					PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert
# define PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert					PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency
# define PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency				PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency */

/** \def PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
 *
 * User-customisable macro that defines a catch-clause to appear
 * immediately after the clause for <code>std::bad_alloc</code>.
 *
 * Defaults to PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
# define PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0 */

/** \def PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
 *
 * User-customisable macro that defines a catch-clause to appear
 * immediately preceeding the catch-all clause.
 *
 * Defaults to PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# define PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1 */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_COM_CUSTOM_HPP_SYMBOLS */

/* ///////////////////////////// end of file //////////////////////////// */
