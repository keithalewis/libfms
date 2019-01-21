project(test_prob)
add_executable(test_prob test_prob.cpp)
include_directories (${prob_SOURCE_DIR})
target_link_libraries(test_prob
	prob
)
