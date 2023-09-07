
# This file is a part of MRNIU/libcxxrt
# (https://github.com/MRNIU/libcxxrt).
#
# CMakeLists.txt for MRNIU/libcxxrt.

# 设置项目名与版本
project(
        test
        VERSION 0.0.1
)

enable_testing()
include(GoogleTest)

list(APPEND COMMON_TEST_COMPILE_OPTIONS
        --coverage
)

list(APPEND COMMON_TEST_LINK_OPTIONS
        --coverage
        -fsanitize=leak
        -fsanitize=address
        -fno-omit-frame-pointer
)

list(APPEND COMMON_TEST_LINK_LIB
        gtest_main
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/unit_test)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/integration_test)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/system_test)

add_coverage(
        DEPENDS unit_test integration_test system_test
        SOURCE_DIR ${CMAKE_SOURCE_DIR}
        BINARY_DIR ${CMAKE_BINARY_DIR}
        EXCLUDE_DIR ${CMAKE_SOURCE_DIR}/3rd/*
)
