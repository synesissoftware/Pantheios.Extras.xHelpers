/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.version.cpp
 *
 * Purpose: Unit tests for Pantheios.Extras.xHelpers version macros.
 *
 * Created: 9th October 2026
 * Updated: 11th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/extras/xhelpers.hpp>

#include <xtests/xtests.h>

#include <pantheios/frontends/stock.h>

#include <stdlib.h>


PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.version");


static void test_version_components()
{
    XTESTS_TEST_INTEGER_EQUAL(0, PANTHEIOS_EXTRAS_XHELPERS_VER_MAJOR);
    XTESTS_TEST_INTEGER_EQUAL(1, PANTHEIOS_EXTRAS_XHELPERS_VER_MINOR);
    XTESTS_TEST_INTEGER_EQUAL(3, PANTHEIOS_EXTRAS_XHELPERS_VER_PATCH);
    XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_EXTRAS_XHELPERS_VER_PATCH, PANTHEIOS_EXTRAS_XHELPERS_VER_REVISION);
}

static void test_version_composite()
{
    unsigned const relstatus = static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER) & 0xff;
    unsigned const computed =
        (0
            |   (   static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER_MAJOR) << 24   )
            |   (   static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER_MINOR) << 16   )
            |   (   static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER_PATCH) <<  8   )
            |   (   relstatus                                                  <<  0   )
        );

    XTESTS_TEST_INTEGER_EQUAL(0x82u, relstatus);
    XTESTS_TEST_INTEGER_EQUAL(relstatus, static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER_RELSTATUS));
    XTESTS_TEST_INTEGER_EQUAL(relstatus, static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER_ALPHABETA));
    XTESTS_TEST_INTEGER_EQUAL(computed, static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER));
    XTESTS_TEST_INTEGER_EQUAL(static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER_0_1_3_BETA_2), static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER));
    XTESTS_TEST_INTEGER_EQUAL(0x00010382u, static_cast<unsigned>(PANTHEIOS_EXTRAS_XHELPERS_VER));
}


int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.version", verbosity))
    {
        XTESTS_RUN_CASE(test_version_components);
        XTESTS_RUN_CASE(test_version_composite);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */
