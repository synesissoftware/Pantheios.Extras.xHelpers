
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

if(b64_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			b64::core
	)
endif()

if(TARGET xTests::core)

	target_link_libraries(test.scratch.versions
		PRIVATE
			xTests::core
	)
endif()
