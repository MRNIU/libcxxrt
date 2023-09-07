
# This file is a part of MRNIU/libcxxrt
# (https://github.com/MRNIU/libcxxrt).
#
# CMakeLists.txt for MRNIU/libcxxrt.

# 设置项目名与版本
project(
        system-test
        VERSION 0.0.1
)

add_executable(system_test
        example.cpp
)

target_compile_options(system_test PRIVATE
        ${COMMON_TEST_COMPILE_OPTIONS}
)

target_link_options(system_test PRIVATE
        ${COMMON_TEST_LINK_OPTIONS}
)

target_link_libraries(system_test PRIVATE
        ${COMMON_TEST_LINK_LIB}
)

gtest_discover_tests(system_test)
