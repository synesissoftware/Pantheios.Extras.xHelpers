/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers/com/invoke.hpp
 *
 * Purpose:     Definition of the pantheios::extras::xhelpers::com::invoke overloads.
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
 * [C++ only] Definition of the pantheios::extras::xhelpers::com::invoke() overloads,
 *   as part of the
 *   \ref group__library__pantheios_extras_xhelpers "Pantheios.Extras.xHelpers" library.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE
#define PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE_MAJOR       4
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE_MINOR       1
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE_REVISION    3
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE_EDIT        38
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/extras/xhelpers/internal/common.hpp>
#include <pantheios/extras/xhelpers/com/custom/symbols.hpp>

#ifndef PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS
# include <pantheios/pantheios.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# include <platformstl\platformstl.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef __AFX_H__
# if _STLSOFT_VER < 0x01096eff
#  include <mfcstl/shims/access/string/CException.hpp>
# endif /* _STLSOFT_VER < 1.9.1 b110 */
#endif /* __AFX_H__*/
#include <stlsoft/smartptr/scoped_handle.hpp>
#ifdef PANTHEIOS_USE_WIDE_STRINGS
# include <stlsoft/shims/access/string/std/exception.hpp>
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

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
/** Extras components for using Pantheios when implementing COM components.
 *
 * When implementing COM components, one must carefully observe the
 * prohibition on allowing exceptions to escape out to the context of the
 * caller. But implementing COM components to follow this can be verbose
 * and tiresome. This function suite may be used to handle all that
 * boring guff automatically, and log the details of caught exceptions
 * to boot!
 *
 * The pantheios::extras::com::invoke_nothrow() functions can be used to wrap
 * non-member entry point functions, as illustrated in the following example
 * (an extract from the adjunct library <b>Pantheios.COM</b>):
 *
 * \code
STDAPI DllRegisterServer_()
{
  pantheios::log_NOTICE("DllRegisterServer()");

  HRESULT hr  =   S_OK;

#ifdef _MERGE_PROXYSTUB
  if(SUCCEEDED(hr))
  {
    hr = PrxDllRegisterServer();
  }
#endif \/\* _MERGE_PROXYSTUB \*\/

  if(SUCCEEDED(hr))
  {
    hr = _Module.RegisterServer(true);
  }

  if(FAILED(hr))
  {
    pantheios::log_ERROR( "Registration failed: ", pantheios::integer(hr, pantheios::fmt::fullHex)
                        , ": ", winstl::error_desc_a(hr));
  }
  else
  {
    // Translate all the other Pantheios loggers
    hr = ReregisterPantheiosEventSources();
  }

  return hr;
}

STDAPI DllRegisterServer()
{
  return pantheios::extras::com::invoke_nothrow(DllRegisterServer_, "DllRegisterServer");
}
 * \endcode
 *
 * Any exceptions thrown in the implementation function,
 * <code>DllRegisterServer_()</code> will be caught by
 * pantheios::extras::com::invoke_nothrow()
 * and translated into the appropriate <code>HRESULT</code>, and a
 * corresponding log statement called.
 *
 * The
 * pantheios::extras::com::invoke_nothrow_method()
 * functions can be used to wrap COM methods, as illustrated in the following
 * example (an extract from <a href = "http://openrj.org/">Open-RJ.COM</a>):
 *
 * \code
STDMETHODIMP Record::get_Count_(long* pVal)
{
  pantheios::log_DEBUG("Record::Count");

  return get_long_(pVal, &orj_record_t::numFields);
}

STDMETHODIMP Record::get_Count(long* pVal)
{
  return pantheios::extras::com::invoke_nothrow_method(this, &Record::get_Count_, pVal, "Record::Count");
}
 * \endcode
 */
namespace com
{

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

namespace impl
{
}/* namespace impl */

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/*
 * The logic for methods is:
 *
 *  Win32:
 *   - cdecl (symbol is STLSOFT_CDECL), if STLSOFT_CF_CDECL_SUPPORTED
 *   - stdcall (symbol is STLSOFT_STDCALL), if STLSOFT_CF_STDCALL_SUPPORTED
 * 
 *  x64:
 *   - fastcall (symbol is STLSOFT_CDECL, which is nothing in x64)
 */

/* NOTE: discriminating on STLSOFT_CF_STDCALL_SUPPORTED is a hack, because
 * currently STLSoft assumes STLSOFT_CF_CDECL_SUPPORTED is defined for x64
 * (wherein stdcall and fastcall are not), hence:
 *
 * TODO: fix this, by having STLSoft work when none of the CCs are defined
 */

#ifdef PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_
# undef PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_
#endif /* PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ */

#if defined(PANTHEIOS_DOCUMENTATION_SKIP_SECTION)

 /* default show no calling convention */
# define PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_
# include "./internal/generated/invoke_nothrow.hpp"
# include "./internal/generated/invoke_nothrow_method.hpp"

#elif defined(PLATFORMSTL_ARCH_IS_X86)

 /* x86 may have cdecl, stdcall, and thiscall (for methods) */

# ifdef STLSOFT_CF_CDECL_SUPPORTED
#  define PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_	STLSOFT_CDECL
#  include "./internal/generated/invoke_nothrow.hpp"
#  include "./internal/generated/invoke_nothrow_method.hpp"
#  undef PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_
# endif /* STLSOFT_CF_CDECL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
#  define PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_	STLSOFT_STDCALL
#  include "./internal/generated/invoke_nothrow.hpp"
#  include "./internal/generated/invoke_nothrow_method.hpp"
#  undef PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

# define PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_
# include "./internal/generated/invoke_nothrow_method.hpp"
# undef PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_

#elif defined(PLATFORMSTL_ARCH_IS_IA64) || \
	  defined(PLATFORMSTL_ARCH_IS_X64)

 /* ia64/x64 don't have (explicit) calling conventions */
# define PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_
# include "./internal/generated/invoke_nothrow.hpp"
# include "./internal/generated/invoke_nothrow_method.hpp"

#else
# error This file not currently compatible with architectures other than x86, ia64, and x64. If you require another architecture, please contact the project personnel
#endif /* architecture */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace com */
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

#endif /* !PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE */

/* ///////////////////////////// end of file //////////////////////////// */
