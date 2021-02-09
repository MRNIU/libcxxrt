
# This file is a part of MRNIU/MiniCRT (https://github.com/MRNIU/MiniCRT).
# 
# CMakeLists.txt for MRNIU/MiniCRT.

# 由于 x64 变长参数难以实现，需要借助 builtin 函数
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -ffreestanding -nostdlib -nostdinc -O0 -Wall -Wextra -nostartfiles -e _mini_crt_entry -lSystem")

include_directories(${MiniCRT_SOURCE_CODE_DIR}/include)

add_library(minicrt
    entry.c
    format.c
    malloc.c
    stdio.c
    string.c)

add_executable(test 
        $<TARGET_OBJECTS:minicrt>
        test.c)
