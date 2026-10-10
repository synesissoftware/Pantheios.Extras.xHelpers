/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.xhelpers.com.functions.1.cpp
 *
 * Purpose: Unit tests for the Windows COM `invoke_nothrow()` overloads
 *          (HRESULT mapping).
 *
 * Created: 10th October 2026
 * Updated: 10th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Absorb unexpected exceptions so catch(...) returns E_UNEXPECTED rather
 * than calling ExitProcess (which would abort the test runner).
 */
#define PANTHEIOS_EXTRAS_COM_ABSORB_UNKNOWN_EXCEPTIONS

#include <pantheios/extras/xhelpers.hpp>

#include <xtests/xtests.h>

#include <pantheios/frontends/stock.h>

#include <stdexcept>

#include <stdlib.h>


PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.xhelpers.com.functions.1");


namespace
{

static void TEST_invoke_nothrow_0_RETURNS_S_OK(void);
static void TEST_invoke_nothrow_0_ON_bad_alloc_RETURNS_E_OUTOFMEMORY(void);
static void TEST_invoke_nothrow_0_ON_E_OUTOFMEMORY_RETURNS_E_OUTOFMEMORY(void);
static void TEST_invoke_nothrow_0_ON_std_exception_RETURNS_E_FAIL(void);
static void TEST_invoke_nothrow_0_ON_UNKNOWN_EXCEPTION_RETURNS_E_UNEXPECTED(void);
static void TEST_invoke_nothrow_1_RETURNS_S_OK(void);
static void TEST_invoke_nothrow_1_ON_std_exception_RETURNS_E_FAIL(void);

} /* anonymous namespace */


int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.xhelpers.com.functions.1", verbosity))
    {
        XTESTS_RUN_CASE(TEST_invoke_nothrow_0_RETURNS_S_OK);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_0_ON_bad_alloc_RETURNS_E_OUTOFMEMORY);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_0_ON_E_OUTOFMEMORY_RETURNS_E_OUTOFMEMORY);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_0_ON_std_exception_RETURNS_E_FAIL);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_0_ON_UNKNOWN_EXCEPTION_RETURNS_E_UNEXPECTED);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_1_RETURNS_S_OK);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_1_ON_std_exception_RETURNS_E_FAIL);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


namespace
{

using pantheios::extras::xhelpers::com::invoke_nothrow;

static HRESULT com_api_nothrow_()
{
    return S_OK;
}

static HRESULT com_api_oom_throw_()
{
    throw std::bad_alloc();
}

static HRESULT com_api_oom_hr_()
{
    return E_OUTOFMEMORY;
}

static HRESULT com_api_throw_stdx_()
{
    throw std::runtime_error("abc");
}

static HRESULT com_api_unexpected_()
{
    throw 42;
}

static HRESULT com_api_1_nothrow_(int /* a0 */)
{
    return S_OK;
}

static HRESULT com_api_1_throw_stdx_(int /* a0 */)
{
    throw std::runtime_error("abc");
}


static void TEST_invoke_nothrow_0_RETURNS_S_OK(void)
{
    XTESTS_TEST_INTEGER_EQUAL(
        static_cast<long>(S_OK)
    ,   static_cast<long>(invoke_nothrow(com_api_nothrow_, PANTHEIOS_LITERAL_STRING("com_api_nothrow")))
    );
}

static void TEST_invoke_nothrow_0_ON_bad_alloc_RETURNS_E_OUTOFMEMORY(void)
{
    XTESTS_TEST_INTEGER_EQUAL(
        static_cast<long>(E_OUTOFMEMORY)
    ,   static_cast<long>(invoke_nothrow(com_api_oom_throw_, PANTHEIOS_LITERAL_STRING("com_api_oom_throw")))
    );
}

static void TEST_invoke_nothrow_0_ON_E_OUTOFMEMORY_RETURNS_E_OUTOFMEMORY(void)
{
    XTESTS_TEST_INTEGER_EQUAL(
        static_cast<long>(E_OUTOFMEMORY)
    ,   static_cast<long>(invoke_nothrow(com_api_oom_hr_, PANTHEIOS_LITERAL_STRING("com_api_oom_hr")))
    );
}

static void TEST_invoke_nothrow_0_ON_std_exception_RETURNS_E_FAIL(void)
{
    XTESTS_TEST_INTEGER_EQUAL(
        static_cast<long>(E_FAIL)
    ,   static_cast<long>(invoke_nothrow(com_api_throw_stdx_, PANTHEIOS_LITERAL_STRING("com_api_throw_stdx")))
    );
}

static void TEST_invoke_nothrow_0_ON_UNKNOWN_EXCEPTION_RETURNS_E_UNEXPECTED(void)
{
    XTESTS_TEST_INTEGER_EQUAL(
        static_cast<long>(E_UNEXPECTED)
    ,   static_cast<long>(invoke_nothrow(com_api_unexpected_, PANTHEIOS_LITERAL_STRING("com_api_unexpected")))
    );
}

static void TEST_invoke_nothrow_1_RETURNS_S_OK(void)
{
    XTESTS_TEST_INTEGER_EQUAL(
        static_cast<long>(S_OK)
    ,   static_cast<long>(invoke_nothrow(com_api_1_nothrow_, 1, PANTHEIOS_LITERAL_STRING("com_api_1_nothrow")))
    );
}

static void TEST_invoke_nothrow_1_ON_std_exception_RETURNS_E_FAIL(void)
{
    XTESTS_TEST_INTEGER_EQUAL(
        static_cast<long>(E_FAIL)
    ,   static_cast<long>(invoke_nothrow(com_api_1_throw_stdx_, 1, PANTHEIOS_LITERAL_STRING("com_api_1_throw_stdx")))
    );
}

} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */
