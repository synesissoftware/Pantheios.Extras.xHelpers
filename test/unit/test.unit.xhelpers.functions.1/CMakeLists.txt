
# NOTE: the library's invoke.hpp (and this test) carry unused parameters
# that predate -Werror; suppressed here rather than changing library
# behaviour or source in the build-boilerplate programme.
list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	unused-parameter
)

list(APPEND X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	4100 # unreferenced formal parameter
)

define_automated_test_program(test.unit.xhelpers.functions.1 test.unit.xhelpers.functions.1.cpp)

target_link_libraries(test.unit.xhelpers.functions.1
	PRIVATE
		Pantheios::Pantheios.be.null
		Pantheios::Pantheios.bec.null
		Pantheios::Pantheios.fe.simple
		Pantheios::Pantheios.util
)
