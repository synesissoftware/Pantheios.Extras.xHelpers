/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers.hpp
 *
 * Purpose:     Main C++ header for the Pantheios.Extras.xHelpers library.
 *
 * Created:     30th January 2011
 * Updated:     10th September 2015
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2011-2015, Matthew Wilson and Synesis Software
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


/** \file pantheios/extras/xhelpers.hpp
 * [C++ only] Main C++ header for the
 *   \ref group__library__pantheios_extras_xhelpers "Pantheios.Extras.xHelpers" library.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_HPP_XHELPERS
#define PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_HPP_XHELPERS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_XHELPERS_EXTRAS_VER_PANTHEIOS_EXTRAS_HPP_XHELPERS_MAJOR      1
# define PANTHEIOS_XHELPERS_EXTRAS_VER_PANTHEIOS_EXTRAS_HPP_XHELPERS_MINOR      0
# define PANTHEIOS_XHELPERS_EXTRAS_VER_PANTHEIOS_EXTRAS_HPP_XHELPERS_REVISION   3
# define PANTHEIOS_XHELPERS_EXTRAS_VER_PANTHEIOS_EXTRAS_HPP_XHELPERS_EDIT       3
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/extras/xhelpers/internal/common.hpp>

#include <pantheios/extras/xhelpers/invoke.hpp>
#include <platformstl/platformstl.h>
#ifndef PANTHEIOS_EXTRAS_XHELPERS_NO_COM
# ifdef PLATFORMSTL_OS_IS_WINDOWS
#  include <pantheios/extras/xhelpers/com.hpp>
# endif /* PLATFORMSTL_OS_IS_WINDOWS */
#endif /* !PANTHEIOS_EXTRAS_XHELPERS_NO_COM */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_HPP_XHELPERS */

/* ///////////////////////////// end of file //////////////////////////// */
