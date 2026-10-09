
# NOTE: the Pantheios front-/back-end libraries are linked because
# xhelpers.hpp pulls in the Pantheios API, which references
# pantheios_init().
define_example_program(test.scratch.versions main.cpp)

target_link_libraries(test.scratch.versions
	PRIVATE
		Pantheios::Pantheios.be.null
		Pantheios::Pantheios.bec.null
		Pantheios::Pantheios.fe.simple
		Pantheios::Pantheios.util
)
