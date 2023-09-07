
# This file is a part of MRNIU/libcxxrt
# (https://github.com/MRNIU/libcxxrt).
# 
# gcc.cmake for MRNIU/libcxxrt.

if (APPLE)
    message(STATUS "Now is Apple systens.")
    # GCC
    find_program(Compiler_gcc g++-13)
    if (NOT Compiler_gcc)
        message(FATAL_ERROR "g++-13 not found.\n"
                "Run `brew install gcc` to install.")
    else ()
        message(STATUS "Found g++-13 ${Compiler_gcc}")
    endif ()

    set(CMAKE_C_COMPILER gcc-13)
    set(CMAKE_CXX_COMPILER g++-13)
endif ()
