
# This file is a part of MRNIU/libcxxrt
# (https://github.com/MRNIU/libcxxrt).
#
# compile_config.cmake for MRNIU/libcxxrt.
# 配置信息

# 通用编译选项
list(APPEND COMMON_COMPILE_OPTIONS
        # 如果 CMAKE_BUILD_TYPE 为 Release 则使用 -O3 -Werror，否则使用 -O0 -g -ggdb
        $<$<CONFIG:Release>:-O3;-Werror>
        $<$<CONFIG:Debug>:-O0;-g;-ggdb>
        # 打开全部警告
        -Wall
        # 打开额外警告
        -Wextra
        # 启用异常处理机制
        -fexceptions

        # gcc 特定选项
        $<$<CXX_COMPILER_ID:GNU>:
        >

        # clang 特定选项
        $<$<CXX_COMPILER_ID:Clang>:
        >

        # 平台相关
        $<$<PLATFORM_ID:Darwin>:
        >
)

# 通用链接选项
list(APPEND COMMON_LINK_OPTIONS
        # 不链接 ctr0 等启动代码
        -nostartfiles
)
