add_executable(vec3_test vec3_test.cpp)
target_link_libraries(vec3_test gtest gtest_main ${OBJ_DIR}/vec3.o)
add_test(NAME vec3_test COMMAND vec3_test)
