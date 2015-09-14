/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers/com/generated/invoke_nothrow.hpp
 *
 * Purpose:     Definitions of the invoke_nothrow() N-ary function template
 *              suite.
 *
 * Generated:   6th June 2012
 *
 * Status:      This file is auto-generated: DO NOT EDIT!
 *
 * Copyright:   The copyright restrictions of the Pantheios library,
 *              enumerated in the header file <pantheios/pantheios.h>,
 *              apply to this file
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef PANTHEIOS_EXTRAS_XHELPERS_INCL_PANTHEIOS_EXTRAS_XHELPERS_COM_HPP_INVOKE
# error This file is included by the Pantheios API, and cannot be included directly
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */


#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
/// Wraps a 0-parameter function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R>
inline R invoke_nothrow(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(), pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr  =   (*pfn)();

        if(E_OUTOFMEMORY == hr)
        {
            goto out_of_memory;
        }

        return hr;
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
        goto out_of_memory;
    }
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return E_FAIL;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
    catch(CException* px)
    {
        log(alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);
        px->Delete();
        return E_FAIL;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

# if defined(PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS)
        return E_UNEXPECTED;
# elif defined(PANTHEIOS_EXTRAS_COM_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
# else
        ::ExitProcess(EXIT_FAILURE);
# endif /* PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS */
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return E_OUTOFMEMORY;
}

#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
/// Wraps a 1-parameter function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
template <typename R, typename A0>
inline R invoke_nothrow(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0), A0 a0, pan_char_t const* functionName)
#else /* ? PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename A0>
inline R invoke_nothrow_1(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0), A0 a0, pan_char_t const* functionName);
template <typename R, typename A0>
inline R invoke_nothrow(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0), A0 a0, pan_char_t const* functionName)
{
    return invoke_nothrow_1<R, A0, A1>(pfn, a0, functionName);
}
template <typename R, typename A0>
inline R invoke_nothrow_1(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0), A0 a0, pan_char_t const* functionName)
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr  =   (*pfn)(a0);

        if(E_OUTOFMEMORY == hr)
        {
            goto out_of_memory;
        }

        return hr;
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
        goto out_of_memory;
    }
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return E_FAIL;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
    catch(CException* px)
    {
        log(alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);
        px->Delete();
        return E_FAIL;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

# if defined(PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS)
        return E_UNEXPECTED;
# elif defined(PANTHEIOS_EXTRAS_COM_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
# else
        ::ExitProcess(EXIT_FAILURE);
# endif /* PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS */
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return E_OUTOFMEMORY;
}

#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
/// Wraps a 2-parameter function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
template <typename R, typename A0, typename A1>
inline R invoke_nothrow(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1), A0 a0, A1 a1, pan_char_t const* functionName)
#else /* ? PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename A0, typename A1>
inline R invoke_nothrow_2(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1), A0 a0, A1 a1, pan_char_t const* functionName);
template <typename R, typename A0, typename A1>
inline R invoke_nothrow(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1), A0 a0, A1 a1, pan_char_t const* functionName)
{
    return invoke_nothrow_2<R, A0, A1>(pfn, a0, a1, functionName);
}
template <typename R, typename A0, typename A1>
inline R invoke_nothrow_2(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1), A0 a0, A1 a1, pan_char_t const* functionName)
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr  =   (*pfn)(a0, a1);

        if(E_OUTOFMEMORY == hr)
        {
            goto out_of_memory;
        }

        return hr;
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
        goto out_of_memory;
    }
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return E_FAIL;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
    catch(CException* px)
    {
        log(alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);
        px->Delete();
        return E_FAIL;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

# if defined(PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS)
        return E_UNEXPECTED;
# elif defined(PANTHEIOS_EXTRAS_COM_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
# else
        ::ExitProcess(EXIT_FAILURE);
# endif /* PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS */
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return E_OUTOFMEMORY;
}

#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
/// Wraps a 3-parameter function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pfn The function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
#ifdef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
template <typename R, typename A0, typename A1, typename A2>
inline R invoke_nothrow(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1, A2), A0 a0, A1 a1, A2 a2, pan_char_t const* functionName)
#else /* ? PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename A0, typename A1, typename A2>
inline R invoke_nothrow_3(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1, A2), A0 a0, A1 a1, A2 a2, pan_char_t const* functionName);
template <typename R, typename A0, typename A1, typename A2>
inline R invoke_nothrow(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1, A2), A0 a0, A1 a1, A2 a2, pan_char_t const* functionName)
{
    return invoke_nothrow_3<R, A0, A1, A2>(pfn, a0, a1, a2, functionName);
}
template <typename R, typename A0, typename A1, typename A2>
inline R invoke_nothrow_3(R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ *pfn)(A0, A1, A2), A0 a0, A1 a1, A2 a2, pan_char_t const* functionName)
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr  =   (*pfn)(a0, a1, a2);

        if(E_OUTOFMEMORY == hr)
        {
            goto out_of_memory;
        }

        return hr;
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::bad_alloc&)
    {
        goto out_of_memory;
    }
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_0
    catch(std::exception& x)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), x);

        return E_FAIL;
    }
# ifdef __AFX_H__
    catch(CMemoryException* px)
    {
        px->Delete();
        goto out_of_memory;
    }
    catch(CException* px)
    {
        log(alert, functionName, PANTHEIOS_LITERAL_STRING(": exception: "), *px);
        px->Delete();
        return E_FAIL;
    }
# endif /* __AFX_H__*/
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_CUSTOM_CLAUSE_1
    catch(...)
    {
        PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_emergency, functionName, PANTHEIOS_LITERAL_STRING(": unexpected exception!"));

# if defined(PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS)
        return E_UNEXPECTED;
# elif defined(PANTHEIOS_EXTRAS_COM_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
# else
        ::ExitProcess(EXIT_FAILURE);
# endif /* PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS */
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

out_of_memory:
    PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_log(PANTHEIOS_EXTRAS_XHELPERS_COM_EXCEPTION_HELPERS_alert, functionName, PANTHEIOS_LITERAL_STRING(": out of memory"));

    return E_OUTOFMEMORY;
}

/* ///////////////////////////// end of file //////////////////////////// */
