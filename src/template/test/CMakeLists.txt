project(test_template)
add_executable(test_template test_template.cpp)
include_directories (${template_SOURCE_DIR})
target_link_libraries(test_template
	template
)
