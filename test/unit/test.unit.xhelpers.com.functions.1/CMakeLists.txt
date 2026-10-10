
define_automated_test_program(test.unit.xhelpers.com.functions.1 test.unit.xhelpers.com.functions.1.cpp)

target_link_libraries(test.unit.xhelpers.com.functions.1
	PRIVATE
		Pantheios::Pantheios.be.null
		Pantheios::Pantheios.bec.null
		Pantheios::Pantheios.fe.simple
		Pantheios::Pantheios.util
)
