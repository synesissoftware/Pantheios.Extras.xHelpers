
# NOTE: the library's invoke.hpp carries unused parameters that predate
# -Werror; suppressed here rather than changing library source. The
# Pantheios front-/back-end libraries are linked because xhelpers.hpp
# pulls in the Pantheios API, which references pantheios_init().
list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	unused-parameter
)

define_example_program(test.scratch.versions main.cpp)

target_link_libraries(test.scratch.versions
	PRIVATE
		Pantheios::Pantheios.be.null
		Pantheios::Pantheios.bec.null
		Pantheios::Pantheios.fe.simple
		Pantheios::Pantheios.util
)
