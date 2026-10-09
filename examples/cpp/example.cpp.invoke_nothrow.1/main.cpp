/* /////////////////////////////////////////////////////////////////////////
 * File:    main.cpp
 *
 * Purpose: Demonstrates wrapping a C-API-style function, whose
 *          implementation may throw, so that it never throws to its caller.
 *
 * Created: 9th October 2026
 * Updated: 9th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/extras/xhelpers.hpp>

#include <pantheios/pantheios.hpp>
#include <pantheios/frontends/stock.h>

#include <iostream>
#include <stdexcept>

#include <stdlib.h>


PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.invoke_nothrow.1");


namespace
{

    /* plain ints, so that the template deduces the same R for the
     * function and for the three error codes
     */
    int const RC_OUT_OF_MEMORY  =   -1;
    int const RC_EXCEPTION      =   -2;
    int const RC_UNEXPECTED     =   -3;

    /* the implementation uses exceptions */
    int divide_(int numerator, int denominator)
    {
        if (0 == denominator)
        {
            throw std::invalid_argument("denominator is zero");
        }

        return numerator / denominator;
    }

    /* the C-compatible API: it must not allow exceptions to escape */
    int divide(int numerator, int denominator)
    {
        /* normative behaviour: the result of divide_() is returned as-is;
         * otherwise the exception is logged and mapped to an error code
         */
        return pantheios::extras::xhelpers::invoke_nothrow(
            divide_
        ,   numerator
        ,   denominator
        ,   PANTHEIOS_LITERAL_STRING("divide")
        ,   RC_OUT_OF_MEMORY
        ,   RC_EXCEPTION
        ,   RC_UNEXPECTED
        );
    }

} /* anonymous namespace */


int main()
{
    std::cout << "divide(6, 3) = " << divide(6, 3) << std::endl;
    std::cout << "divide(6, 0) = " << divide(6, 0) << " (RC_EXCEPTION = " << RC_EXCEPTION << ")" << std::endl;

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */
