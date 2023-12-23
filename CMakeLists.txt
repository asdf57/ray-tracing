cmake_minimum_required(VERSION 3.10)

project(RayTracing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_TESTS "Build the unit tests" OFF)

set(BIN_DIR "${PROJECT_SOURCE_DIR}/bin")
set(OBJ_DIR "${PROJECT_SOURCE_DIR}/obj")

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BIN_DIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OBJ_DIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OBJ_DIR})
endforeach()

add_executable(raytracer src/main.cpp)

target_sources(raytracer PRIVATE
    src/vec3.cpp
    src/color.cpp
    src/ray.cpp
    src/sphere.cpp
    src/hit_record.cpp
    src/hittable_list.cpp
    src/interval.cpp
)

# Specify where the compiled object files will go
set_target_properties(raytracer PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OBJ_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OBJ_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)

if(BUILD_TESTS)
    add_subdirectory(external/googletest)
    enable_testing()
    add_subdirectory(tests)
endif()
