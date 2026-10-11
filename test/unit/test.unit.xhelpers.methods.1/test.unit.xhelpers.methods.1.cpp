/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.xhelpers.methods.1.cpp
 *
 * Purpose: Unit tests for `invoke_nothrow_method()` (0- and 1-parameter
 *          member functions).
 *
 * Created: 12th October 2026
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/extras/xhelpers.hpp>

#include <xtests/xtests.h>

#include <pantheios/frontends/stock.h>

#include <stdexcept>

#include <stdlib.h>


PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.xhelpers.methods.1");


namespace
{

int const RC_OUTOFMEMORY = -1001;
int const RC_EXCEPTION   = -1002;
int const RC_UNEXPECTED  = -1003;

static void TEST_invoke_nothrow_method_0_RETURNS_VALUE(void);
static void TEST_invoke_nothrow_method_0_ON_bad_alloc_RETURNS_RC_OUTOFMEMORY(void);
static void TEST_invoke_nothrow_method_0_ON_std_exception_RETURNS_RC_EXCEPTION(void);
static void TEST_invoke_nothrow_method_1_RETURNS_VALUE(void);
static void TEST_invoke_nothrow_method_1_ON_bad_alloc_RETURNS_RC_OUTOFMEMORY(void);
static void TEST_invoke_nothrow_method_1_ON_std_exception_RETURNS_RC_EXCEPTION(void);

} /* anonymous namespace */


int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.xhelpers.methods.1", verbosity))
    {
        XTESTS_RUN_CASE(TEST_invoke_nothrow_method_0_RETURNS_VALUE);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_method_0_ON_bad_alloc_RETURNS_RC_OUTOFMEMORY);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_method_0_ON_std_exception_RETURNS_RC_EXCEPTION);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_method_1_RETURNS_VALUE);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_method_1_ON_bad_alloc_RETURNS_RC_OUTOFMEMORY);
        XTESTS_RUN_CASE(TEST_invoke_nothrow_method_1_ON_std_exception_RETURNS_RC_EXCEPTION);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


namespace
{

using pantheios::extras::xhelpers::invoke_nothrow_method;

struct api
{
    int nothrow_0()
    {
        return -1010101;
    }

    int oom_0()
    {
        throw std::bad_alloc();
    }

    int throw_stdx_0()
    {
        throw std::runtime_error("abc");
    }

    int nothrow_1(int r)
    {
        return r;
    }

    int oom_1(int /* r */)
    {
        throw std::bad_alloc();
    }

    int throw_stdx_1(int /* r */)
    {
        throw std::runtime_error("abc");
    }
};


static void TEST_invoke_nothrow_method_0_RETURNS_VALUE(void)
{
    api instance;

    XTESTS_TEST_INTEGER_EQUAL(
        -1010101
    ,   invoke_nothrow_method(
            &instance
        ,   &api::nothrow_0
        ,   PANTHEIOS_LITERAL_STRING("nothrow_0")
        ,   RC_OUTOFMEMORY
        ,   RC_EXCEPTION
        ,   RC_UNEXPECTED
        )
    );
}

static void TEST_invoke_nothrow_method_0_ON_bad_alloc_RETURNS_RC_OUTOFMEMORY(void)
{
    api instance;

    XTESTS_TEST_INTEGER_EQUAL(
        RC_OUTOFMEMORY
    ,   invoke_nothrow_method(
            &instance
        ,   &api::oom_0
        ,   PANTHEIOS_LITERAL_STRING("oom_0")
        ,   RC_OUTOFMEMORY
        ,   RC_EXCEPTION
        ,   RC_UNEXPECTED
        )
    );
}

static void TEST_invoke_nothrow_method_0_ON_std_exception_RETURNS_RC_EXCEPTION(void)
{
    api instance;

    XTESTS_TEST_INTEGER_EQUAL(
        RC_EXCEPTION
    ,   invoke_nothrow_method(
            &instance
        ,   &api::throw_stdx_0
        ,   PANTHEIOS_LITERAL_STRING("throw_stdx_0")
        ,   RC_OUTOFMEMORY
        ,   RC_EXCEPTION
        ,   RC_UNEXPECTED
        )
    );
}

static void TEST_invoke_nothrow_method_1_RETURNS_VALUE(void)
{
    api instance;

    XTESTS_TEST_INTEGER_EQUAL(
        -1010101
    ,   invoke_nothrow_method(
            &instance
        ,   &api::nothrow_1
        ,   -1010101
        ,   PANTHEIOS_LITERAL_STRING("nothrow_1")
        ,   RC_OUTOFMEMORY
        ,   RC_EXCEPTION
        ,   RC_UNEXPECTED
        )
    );
}

static void TEST_invoke_nothrow_method_1_ON_bad_alloc_RETURNS_RC_OUTOFMEMORY(void)
{
    api instance;

    XTESTS_TEST_INTEGER_EQUAL(
        RC_OUTOFMEMORY
    ,   invoke_nothrow_method(
            &instance
        ,   &api::oom_1
        ,   -1010101
        ,   PANTHEIOS_LITERAL_STRING("oom_1")
        ,   RC_OUTOFMEMORY
        ,   RC_EXCEPTION
        ,   RC_UNEXPECTED
        )
    );
}

static void TEST_invoke_nothrow_method_1_ON_std_exception_RETURNS_RC_EXCEPTION(void)
{
    api instance;

    XTESTS_TEST_INTEGER_EQUAL(
        RC_EXCEPTION
    ,   invoke_nothrow_method(
            &instance
        ,   &api::throw_stdx_1
        ,   -1010101
        ,   PANTHEIOS_LITERAL_STRING("throw_stdx_1")
        ,   RC_OUTOFMEMORY
        ,   RC_EXCEPTION
        ,   RC_UNEXPECTED
        )
    );
}

} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */
