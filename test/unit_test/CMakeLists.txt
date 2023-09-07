
# This file is a part of MRNIU/libcxxrt
# (https://github.com/MRNIU/libcxxrt).
#
# CMakeLists.txt for MRNIU/libcxxrt.

# 设置项目名与版本
project(
        unit-test
        VERSION 0.0.1
)

add_executable(unit_test
        example.cpp
)

target_compile_options(unit_test PRIVATE
        ${COMMON_TEST_COMPILE_OPTIONS}
)

target_link_options(unit_test PRIVATE
        ${COMMON_TEST_LINK_OPTIONS}
)

target_link_libraries(unit_test PRIVATE
        ${COMMON_TEST_LINK_LIB}
)

gtest_discover_tests(unit_test)
