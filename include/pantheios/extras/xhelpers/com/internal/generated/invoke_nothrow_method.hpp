/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/xhelpers/com/generated/invoke_nothrow_method.hpp
 *
 * Purpose:     Definitions of the invoke_nothrow_method() N-ary function
 *              template suite.
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
/// Wraps a 0-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(), pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)();

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
/// Wraps a 1-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0), A0 a0, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0);

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
/// Wraps a 2-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1), A0 a0, A1 a1, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1);

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
/// Wraps a 3-parameter class member function in an exception-handler and logs any
/// exceptions using Pantheios.
///
/// \param pThis The instance on which the member function will be invoked
/// \param pfn The member function that will be invoked
/// \param a0 The first argument to the function
/// \param a1 The second argument to the function
/// \param a2 The third argument to the function
/// \param functionName The name of the function, used in any diagnostic logging messages
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2), A0 a0, A1 a1, A2 a2, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2);

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
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2, A3), A0 a0, A1 a1, A2 a2, A3 a3, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2, a3);

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
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2, A3, A4), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2, a3, a4);

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
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2, A3, A4, A5), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2, a3, a4, a5);

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
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2, A3, A4, A5, A6), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6);

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
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7);

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
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8);

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
#endif /* PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
template <typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
inline R invoke_nothrow_method(C *pThis, R (PANTHEIOS_EXTRAS_HELPERS_CALLCONV_SYMBOL_ C::*pfn)(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9), A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, pan_char_t const* functionName)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        HRESULT hr = (pThis->*pfn)(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);

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
