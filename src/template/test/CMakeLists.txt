cmake_minimum_required (VERSION 3.10)
project(test_template)
add_executable(test_template test_template.cpp)
include_directories (${template_SOURCE_DIR})
include_directories($ENV{INSTALLROOT}/include)
target_link_libraries(test_template
	template
)
