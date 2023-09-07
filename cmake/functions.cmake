
# This file is a part of MRNIU/libcxxrt
# (https://github.com/MRNIU/libcxxrt).
#
# functions.cmake for MRNIU/libcxxrt.
# 辅助函数

# 添加测试覆盖率 target
# DEPENDS 要生成的 targets
# SOURCE_DIR 源码路径
# BINARY_DIR 二进制文件路径
# EXCLUDE_DIR 要排除的目录
function(add_coverage)
    # 解析参数
    set(options)
    set(one_value_keywords SOURCE_DIR BINARY_DIR)
    set(multi_value_keywords DEPENDS EXCLUDE_DIR)
    cmake_parse_arguments(
            ARG "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN}
    )

    # 不检查的目录
    list(APPEND EXCLUDES --exclude)
    foreach (_item ${ARG_EXCLUDE_DIR})
        list(APPEND EXCLUDES '${_item}')
    endforeach ()

    # 添加 target
    add_custom_target(coverage DEPENDS ${ARG_DEPENDS}
            COMMAND ${CMAKE_CTEST_COMMAND}
    )
    # 在 coverage 执行完毕后生成报告
    add_custom_command(TARGET coverage
            COMMENT "Generating coverage report ..."
            POST_BUILD
            WORKING_DIRECTORY ${ARG_BINARY_DIR}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${COVERAGE_OUTPUT_DIR}
            COMMAND ${LCOV_EXE}
            -c
            -o ${COVERAGE_OUTPUT_DIR}/coverage.info
            -d ${ARG_BINARY_DIR}
            -b ${ARG_SOURCE_DIR}
            --no-external
            ${EXCLUDES}
            --rc lcov_branch_coverage=1
            COMMAND ${GENHTML_EXE}
            ${COVERAGE_OUTPUT_DIR}/coverage.info
            -o ${COVERAGE_OUTPUT_DIR}
            --branch-coverage
    )
endfunction()
