cmake_minimum_required(VERSION 3.16)

project(arraylib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

if(UNIX AND NOT APPLE)
    set(CMAKE_BUILD_RPATH "$ORIGIN")
endif()

add_library(arraylib SHARED src/arraylib.cpp)

target_include_directories(arraylib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_definitions(arraylib PRIVATE ARRAYLIB_BUILD)

if(MSVC)
    target_compile_options(arraylib PRIVATE /W4)
else()
    target_compile_options(arraylib PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

add_executable(app main.cpp)
target_link_libraries(app PRIVATE arraylib)

include(CTest)

if(BUILD_TESTING)
    add_executable(test_unit tests/test_unit.cpp)
    target_link_libraries(test_unit PRIVATE arraylib)

    add_executable(test_integration tests/test_integration.cpp)
    target_link_libraries(test_integration PRIVATE arraylib)

    if(MSVC)
        target_compile_options(test_unit PRIVATE /UNDEBUG)
        target_compile_options(test_integration PRIVATE /UNDEBUG)
    else()
        target_compile_options(test_unit PRIVATE -UNDEBUG)
        target_compile_options(test_integration PRIVATE -UNDEBUG)
    endif()

    add_test(NAME unit COMMAND test_unit)
    add_test(NAME integration COMMAND test_integration)
    add_executable(variant_22 examples/variant_22.cpp)
    target_link_libraries(variant_22 PRIVATE arraylib)

endif()
