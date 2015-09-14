/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/com/exception_helpers.hpp (formerly pantheios/util/com/exception_helpers.hpp)
 *
 * Purpose:     Helper functions that invoke a given method and convert any
 *              thrown exceptions (that are derived from std::exception)
 *              into a pantheios log statement and an HRESULT return code.
 *
 * Created:     1st May 2006
 * Updated:     30th January 2011
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2006-2011, Matthew Wilson and Synesis Software
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


/** \file pantheios/extras/com/exception_helpers.hpp
 * [C++ &amp; COM only] Helper functions that invoke a given method
 *   and convert any thrown exceptions (that are derived from std::exception)
 *   into a pantheios log statement and an HRESULT return code.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_EXTRAS_COM_HPP_EXCEPTION_HELPERS
#define PANTHEIOS_INCL_PANTHEIOS_EXTRAS_COM_HPP_EXCEPTION_HELPERS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_EXTRAS_COM_HPP_EXCEPTION_HELPERS_MAJOR     4
# define PANTHEIOS_VER_PANTHEIOS_EXTRAS_COM_HPP_EXCEPTION_HELPERS_MINOR     0
# define PANTHEIOS_VER_PANTHEIOS_EXTRAS_COM_HPP_EXCEPTION_HELPERS_REVISION  1
# define PANTHEIOS_VER_PANTHEIOS_EXTRAS_COM_HPP_EXCEPTION_HELPERS_EDIT      30
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

#error This file is now obsolete. Instead, include pantheios/extras/xhelpers/com.hpp, and use the components in the pantheios::extras::xhelpers::com namespace

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_EXTRAS_COM_HPP_EXCEPTION_HELPERS */

/* ///////////////////////////// end of file //////////////////////////// */
