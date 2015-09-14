/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers/invoke.hpp
 *
 * Purpose:     Definition of the pantheios::extras::xhelpers::invoke overloads.
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


/** \file pantheios/extras/xhelpers/invoke.hpp
 * [C++ only] Definition of the pantheios::extras::xhelpers::invoke() overloads,
 *   as part of the
 *   \ref group__library__pantheios_extras_xhelpers "Pantheios.Extras.xHelpers" library.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_HPP_INVOKE
#define PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_HPP_INVOKE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_HPP_INVOKE_MAJOR       4
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_HPP_INVOKE_MINOR       2
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_HPP_INVOKE_REVISION    2
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_HPP_INVOKE_EDIT        37
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/extras/xhelpers/internal/common.hpp>
#include <pantheios/extras/xhelpers/custom/symbols.hpp>

#ifndef PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS
# include <pantheios/pantheios.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS */

#include <stlsoft/smartptr/scoped_handle.hpp>
#ifdef PANTHEIOS_USE_WIDE_STRINGS
# include <stlsoft/shims/access/string/std/exception.hpp>
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
#ifdef __AFX_H__
# include <mfcstl/shims/access/string/CException.hpp>
#endif /* __AFX_H__*/

#include <new>
#include <stdexcept>

#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace pantheios
{
namespace extras
{
namespace xhelpers
{

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

namespace impl
{

/* 0-parameter */

template<   typename R
        >
inline R invoke_nothrow_0_cdecl(
    R (STLSOFT_CDECL *pfn)()
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)();
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
        goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        >
inline R invoke_nothrow_0_stdcall(
    R (STLSOFT_STDCALL *pfn)()
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)();
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}


/* 1-parameter */

template<   typename R
        ,   typename A0
        >
inline R invoke_nothrow_1_cdecl(
    R (STLSOFT_CDECL *pfn)(A0)
,   A0 a0
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0
        >
inline R invoke_nothrow_1_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0)
,   A0 a0
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}


/* 2-parameter */

template<   typename R
        ,   typename A0, typename A1
        >
inline R invoke_nothrow_2_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1)
,   A0 a0, A1 a1
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1
        >
inline R invoke_nothrow_2_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1)
,   A0 a0, A1 a1
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 3-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2
        >
inline R invoke_nothrow_3_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2)
,   A0 a0, A1 a1, A2 a2
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2
        >
inline R invoke_nothrow_3_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2)
,   A0 a0, A1 a1, A2 a2
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 4-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3
        >
inline R invoke_nothrow_4_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3)
,   A0 a0, A1 a1, A2 a2, A3 a3
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3
        >
inline R invoke_nothrow_4_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3)
,   A0 a0, A1 a1, A2 a2, A3 a3
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 5-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4
        >
inline R invoke_nothrow_5_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4
        >
inline R invoke_nothrow_5_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 6-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
        >
inline R invoke_nothrow_6_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
        >
inline R invoke_nothrow_6_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 7-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
        >
inline R invoke_nothrow_7_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
        >
inline R invoke_nothrow_7_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 8-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
        >
inline R invoke_nothrow_8_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6, a7);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
        >
inline R invoke_nothrow_8_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6, a7);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 9-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
        >
inline R invoke_nothrow_9_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
        >
inline R invoke_nothrow_9_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

/* 10-parameter */

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
        >
inline R invoke_nothrow_10_cdecl(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
        >
inline R invoke_nothrow_10_stdcall(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
    STLSOFT_SUPPRESS_UNUSED(unexpected_code);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}


}/* namespace impl */

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 0-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)()
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_0_cdecl<R>(pfn, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 0-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)()
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_0_stdcall<R>(pfn, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 1-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0)
,   A0 a0
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_1_cdecl<R, A0>(pfn, a0, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 1-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0)
,   A0 a0
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_1_stdcall<R, A0>(pfn, a0, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 2-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1)
,   A0 a0, A1 a1
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_2_cdecl<R, A0, A1>(pfn, a0, a1, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 2-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1)
,   A0 a0, A1 a1
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_2_stdcall<R, A0, A1>(pfn, a0, a1, a2, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 3-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2)
,   A0 a0, A1 a1, A2 a2
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_3_cdecl<R, A0, A1, A2>(pfn, a0, a1, a2, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 3-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2)
,   A0 a0, A1 a1, A2 a2
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_3_stdcall<R, A0, A1, A2>(pfn, a0, a1, a2, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 4-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3)
,   A0 a0, A1 a1, A2 a2, A3 a3
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_4_cdecl<R, A0, A1, A2, A3>(pfn, a0, a1, a2, a3, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 4-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3)
,   A0 a0, A1 a1, A2 a2, A3 a3
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_4_stdcall<R, A0, A1, A2, A3>(pfn, a0, a1, a2, a3, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */





#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 5-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_5_cdecl<R, A0, A1, A2, A3, A4>(pfn, a0, a1, a2, a3, a4, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 5-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_5_stdcall<R, A0, A1, A2, A3, A4>(pfn, a0, a1, a2, a3, a4, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */





#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 6-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_6_cdecl<R, A0, A1, A2, A3, A4, A5>(pfn, a0, a1, a2, a3, a4, a5, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 6-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_6_stdcall<R, A0, A1, A2, A3, A4, A5>(pfn, a0, a1, a2, a3, a4, a5, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */





#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 7-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_7_cdecl<R, A0, A1, A2, A3, A4, A5, A6>(pfn, a0, a1, a2, a3, a4, a5, a6, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 7-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_7_stdcall<R, A0, A1, A2, A3, A4, A5, A6>(pfn, a0, a1, a2, a3, a4, a5, a6, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */





#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 10-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eighth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_8_cdecl<R, A0, A1, A2, A3, A4, A5, A6, A7>(pfn, a0, a1, a2, a3, a4, a5, a6, a7, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 10-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eighth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_8_stdcall<R, A0, A1, A2, A3, A4, A5, A6, A7>(pfn, a0, a1, a2, a3, a4, a5, a6, a7, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */





#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 10-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eighth argument to the function
/// \param a8 The nineth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_9_cdecl<R, A0, A1, A2, A3, A4, A5, A6, A7, A8>(pfn, a0, a1, a2, a3, a4, a5, a6, a7, a8, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 10-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eighth argument to the function
/// \param a8 The nineth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_9_stdcall<R, A0, A1, A2, A3, A4, A5, A6, A7, A8>(pfn, a0, a1, a2, a3, a4, a5, a6, a7, a8, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */





#ifdef STLSOFT_CF_CDECL_SUPPORTED

/// Wraps a 10-parameter cdecl function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eighth argument to the function
/// \param a8 The nineth argument to the function
/// \param a9 The tenth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
        >
inline R invoke_nothrow(
    R (STLSOFT_CDECL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_10_cdecl<R, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>(pfn, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 10-parameter stdcall function in an exception-handler and logs
/// any exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eighth argument to the function
/// \param a8 The nineth argument to the function
/// \param a9 The tenth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template<   typename R
        ,   typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
        >
inline R invoke_nothrow(
    R (STLSOFT_STDCALL *pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)
,   A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using namespace ::pantheios::extras::xhelpers::impl;
#else /* ? !PANTHEIOS_NO_NAMESPACE */
    using namespace impl;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return invoke_nothrow_10_stdcall<R, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>(pfn, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, functionName, bad_alloc_code, unhandled_code, unexpected_code);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */






/// Wraps a 0-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)()
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)();
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 0-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)()
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)();
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


/// Wraps a 1-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0), A0 a0
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 1-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0), A0 a0
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


/// Wraps a 2-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1), A0 a0, A1 a1
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 2-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1), A0 a0, A1 a1
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



/// Wraps a 3-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2), A0 a0, A1 a1, A2 a2
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 3-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2), A0 a0, A1 a1, A2 a2
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */




/// Wraps a 4-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2, A3), A0 a0, A1 a1, A2 a2, A3 a3
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 4-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2, A3), A0 a0, A1 a1, A2 a2, A3 a3
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



/// Wraps a 5-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2, A3, A4), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 5-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2, A3, A4), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



/// Wraps a 6-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2, A3, A4, A5), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 6-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2, A3, A4, A5), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



/// Wraps a 7-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2, A3, A4, A5, A6), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 7-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2, A3, A4, A5, A6), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



/// Wraps a 8-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eigth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 8-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eigth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



/// Wraps a 9-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eigth argument to the function
/// \param a8 The ninth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 9-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eigth argument to the function
/// \param a8 The ninth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



/// Wraps a 10-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eigth argument to the function
/// \param a8 The ninth argument to the function
/// \param a9 The tenth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
inline R invoke_nothrow_method(C *pThis, R (C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/// Wraps a 10-parameter <code>stdcall</code> class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param a3 The fourth argument to the function
/// \param a4 The fifth argument to the function
/// \param a5 The sixth argument to the function
/// \param a6 The seventh argument to the function
/// \param a7 The eigth argument to the function
/// \param a8 The ninth argument to the function
/// \param a9 The tenth argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
inline R invoke_nothrow_method(C *pThis, R (STLSOFT_STDCALL C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
    goto out_of_memory;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return unhandled_code;
    }
# ifdef __AFX_H__
    catch(CException* px)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);

        return unhandled_code;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
# ifdef PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

#  if defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS)
        return unexpected_code;
#  elif defined(PANTHEIOS_EXTRAS_XHELPERS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_EXTRAS_XHELPERS_USE_CATCHALL */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return bad_alloc_code;
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace xhelpers */
} /* namespace extras */
} /* namespace pantheios */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_HPP_INVOKE */

/* ///////////////////////////// end of file //////////////////////////// */
