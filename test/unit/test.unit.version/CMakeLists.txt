
define_automated_test_program(test.unit.version test.unit.version.cpp)

target_link_libraries(test.unit.version
	PRIVATE
		Pantheios::Pantheios.be.null
		Pantheios::Pantheios.bec.null
		Pantheios::Pantheios.fe.simple
		Pantheios::Pantheios.util
)
