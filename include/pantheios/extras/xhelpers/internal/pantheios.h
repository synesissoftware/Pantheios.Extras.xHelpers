/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers/internal/pantheios.h
 *
 * Purpose:     "Entry point" include into the Pantheios Main library.
 *
 * Created:     22nd November 2011
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


/** \file pantheios/extras/xhelpers/internal/pantheios.h
 * [C, C++] "Entry point" include into the Pantheios Main library.
 */

#ifndef PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_INTERNAL_H_PANTHEIOS
#define PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_INTERNAL_H_PANTHEIOS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_INTERNAL_H_PANTHEIOS_MAJOR       1
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_INTERNAL_H_PANTHEIOS_MINOR       0
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_INTERNAL_H_PANTHEIOS_REVISION    2
# define PANTHEIOS_EXTRAS_XHELPERS_VER_PANTHEIOS_EXTRAS_XHELPERS_INTERNAL_H_PANTHEIOS_EDIT        2
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility checks
 */

/* Pantheios version check */

#if !defined(PANTHEIOS_VER) || \
	PANTHEIOS_VER < 0x010001d7
# error Pantheios.Extras.xHelpers required Pantheios 1.0.1 beta 215, or later
#endif /* !PANTHEIOS_NO_NAMESPACE */

#if defined(__cplusplus) && \
    defined(PANTHEIOS_NO_NAMESPACE)
# error Pantheios.Extras.xHelpers requires that Pantheios` namespace has not been disabled in C++ compilation
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_INTERNAL_H_STLSOFT */

/* ///////////////////////////// end of file //////////////////////////// */
