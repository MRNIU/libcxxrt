
# This file is a part of MRNIU/MiniCRT (https://github.com/MRNIU/MiniCRT).
# 
# CMakeLists.txt for MRNIU/MiniCRT.

# 由于 x64 变长参数难以实现，需要借助 builtin 函数
message(STATUS "C compiler: ${CMAKE_C_COMPILER_ID}, version: ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID}, version: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib -fno-builtin")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffreestanding -fno-exceptions")

if (CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -fno-rtti")
    add_link_options(-e _mini_crt_entry -lSystem -nostartfiles)
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdinc")
    add_link_options(-e mini_crt_entry -nostartfiles)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -fno-rtti -nostdinc++")
endif ()

message(STATUS "C FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "CXX FLAGS: ${CMAKE_CXX_FLAGS}")

include_directories(${MiniCRT_SOURCE_CODE_DIR}/include)

add_library(minicrt STATIC
    entry.c
    format.c
    malloc.c
    stdio.c
    string.c
    cxxabi.cpp
    new_delete.cpp
    string.cpp
    iostream.cpp)

add_executable(test 
        $<TARGET_OBJECTS:minicrt>
        test.cpp)
