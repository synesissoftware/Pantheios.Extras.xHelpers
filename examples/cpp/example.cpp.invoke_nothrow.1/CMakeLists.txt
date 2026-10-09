
define_example_program(example.cpp.invoke_nothrow.1 main.cpp)

target_link_libraries(example.cpp.invoke_nothrow.1
	PRIVATE
		Pantheios::Pantheios.be.fprintf
		Pantheios::Pantheios.bec.fprintf
		Pantheios::Pantheios.fe.simple
		Pantheios::Pantheios.util
)
