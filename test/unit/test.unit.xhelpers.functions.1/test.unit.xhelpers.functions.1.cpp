/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.xhelpers.functions.1.cpp
 *
 * Purpose:     Implementation file for the test.unit.xhelpers.functions.1 library.
 *
 * Created:     24th February 2011
 * Updated:     10th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */
#ifdef _AFXDLL
# include <afx.h>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define PANTHEIOS_EXTRAS_XHELPERS_NO_COM

#include <pantheios/extras/xhelpers.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 2
 */

/* xTests header files */
#include <xtests/xtests.h>

/* Pantheios header files */
#include <pantheios/frontends/stock.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Identity
 */

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.xhelpers.functions.1");

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_0(void);
	static void test_1_1(void);
	static void test_1_2(void);
	static void test_1_3(void);
	static void test_1_4(void);
	static void test_1_5(void);
	static void test_1_6(void);
	static void test_1_7(void);
	static void test_1_8(void);
	static void test_1_9(void);
	static void test_1_10(void);
	static void test_1_11(void);
	static void test_1_12(void);
	static void test_1_13(void);
	static void test_1_14(void);
	static void test_1_15(void);
	static void test_1_16(void);
	static void test_1_17(void);
	static void test_1_18(void);
	static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.xhelpers.functions.1", verbosity))
	{
		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_1_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);
		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
		XTESTS_RUN_CASE(test_1_7);
		XTESTS_RUN_CASE(test_1_8);
		XTESTS_RUN_CASE(test_1_9);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_1_11);
		XTESTS_RUN_CASE(test_1_12);
		XTESTS_RUN_CASE(test_1_13);
		XTESTS_RUN_CASE(test_1_14);
		XTESTS_RUN_CASE(test_1_15);
		XTESTS_RUN_CASE(test_1_16);
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

	int const RC_OUTOFMEMORY		=	-1002;
	int const RC_EXCEPTION			=	-1003;
	int const RC_UNEXPECTED			=	-1004;

static void test_1_0()
{
	struct functions
	{
		static int c_api_function_nothrow_()
		{
			return -1010101;
		}
		static int c_api_function_nothrow()
		{
			return pantheios::extras::xhelpers::invoke_nothrow(c_api_function_nothrow_, PANTHEIOS_LITERAL_STRING("c_api_function_nothrow"), RC_OUTOFMEMORY, RC_EXCEPTION, RC_UNEXPECTED);
		}

		static int c_api_function_oom_()
		{
			size_t const n = 0x7fffffffu;

			char* p = new char[n];

			if(NULL == p)
			{
				throw std::bad_alloc();
			}

			return -1;
		}
		static int c_api_function_oom()
		{
			return pantheios::extras::xhelpers::invoke_nothrow(c_api_function_oom_, PANTHEIOS_LITERAL_STRING("c_api_function_oom"), RC_OUTOFMEMORY, RC_EXCEPTION, RC_UNEXPECTED);
		}

		static int c_api_function_throw_stdx_()
		{
			throw std::runtime_error("abc");
		}
		static int c_api_function_throw_stdx()
		{
			return pantheios::extras::xhelpers::invoke_nothrow(c_api_function_throw_stdx_, PANTHEIOS_LITERAL_STRING("c_api_function_throw_stdx"), RC_OUTOFMEMORY, RC_EXCEPTION, RC_UNEXPECTED);
		}

#ifdef _AFXDLL
		static int c_api_function_oom_MFC_()
		{
			AfxThrowMemoryException();

			return -1;
		}
		static int c_api_function_oom_MFC()
		{
			return pantheios::extras::xhelpers::invoke_nothrow(c_api_function_oom_MFC_, PANTHEIOS_LITERAL_STRING("c_api_function_oom_MFC"), RC_OUTOFMEMORY, RC_EXCEPTION, RC_UNEXPECTED);
		}
#endif
	};

	XTESTS_TEST_INTEGER_EQUAL(-1010101, functions::c_api_function_nothrow());

	XTESTS_TEST_INTEGER_EQUAL(RC_OUTOFMEMORY, functions::c_api_function_oom());

	XTESTS_TEST_INTEGER_EQUAL(RC_EXCEPTION, functions::c_api_function_throw_stdx());

#ifdef _AFXDLL
	XTESTS_TEST_INTEGER_EQUAL(RC_OUTOFMEMORY, functions::c_api_function_oom_MFC());
#endif
}

static void test_1_1()
{
	struct functions
	{
		static int c_api_function_nothrow_(int r)
		{
			return r;
		}
		static int c_api_function_nothrow(int r)
		{
			return pantheios::extras::xhelpers::invoke_nothrow(c_api_function_nothrow_, r, PANTHEIOS_LITERAL_STRING("c_api_function_nothrow"), RC_OUTOFMEMORY, RC_EXCEPTION, RC_UNEXPECTED);
		}

		static int c_api_function_oom_(int r)
		{
			size_t const n = 0x7fffffffu;

			char* p = new char[n];

			if(NULL == p)
			{
				throw std::bad_alloc();
			}

			return r;
		}
		static int c_api_function_oom(int r)
		{
			return pantheios::extras::xhelpers::invoke_nothrow(c_api_function_oom_, r, PANTHEIOS_LITERAL_STRING("c_api_function_oom"), RC_OUTOFMEMORY, RC_EXCEPTION, RC_UNEXPECTED);
		}

		static int c_api_function_throw_stdx_(int r)
		{
			throw std::runtime_error("abc");
		}
		static int c_api_function_throw_stdx(int r)
		{
			return pantheios::extras::xhelpers::invoke_nothrow(c_api_function_throw_stdx_, r, PANTHEIOS_LITERAL_STRING("c_api_function_throw_stdx"), RC_OUTOFMEMORY, RC_EXCEPTION, RC_UNEXPECTED);
		}

	};

	XTESTS_TEST_INTEGER_EQUAL(-1010101, functions::c_api_function_nothrow(-1010101));

	XTESTS_TEST_INTEGER_EQUAL(RC_OUTOFMEMORY, functions::c_api_function_oom(-1010101));

	XTESTS_TEST_INTEGER_EQUAL(RC_EXCEPTION, functions::c_api_function_throw_stdx(-1010101));
}

static void test_1_2()
{
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
