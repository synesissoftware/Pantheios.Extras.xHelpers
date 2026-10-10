# Windows-only COM overloads (HRESULT mapping)
if(WIN32)

	add_subdirectory(test.unit.xhelpers.com.functions.1)
endif(WIN32)

add_subdirectory(test.unit.version)
add_subdirectory(test.unit.xhelpers.functions.1)
