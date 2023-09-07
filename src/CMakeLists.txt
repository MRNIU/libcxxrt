
# This file is a part of MRNIU/libcxxrt
# (https://github.com/MRNIU/libcxxrt).
#
# CMakeLists.txt for MRNIU/libcxxrt.

enable_language(C)
enable_language(CXX)

set(SOURCE 
    entry.c
    format.c
    malloc.c
    stdio.c
    string.c
    cxxabi.cpp
    new_delete.cpp
    string.cpp
    iostream.cpp
)

add_library(cxxrt-static STATIC 
    ${SOURCE}
)

target_compile_options(cxxrt-static PRIVATE
    ${COMMON_COMPILE_OPTIONS}
)
target_link_options(cxxrt-static PRIVATE
    ${COMMON_LINK_OPTIONS}
)
target_include_directories(cxxrt-static PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

# add_library(cxxrt-shared SHARED 
#     ${SOURCE}
# )

# target_compile_options(cxxrt-shared PRIVATE
#     ${COMMON_COMPILE_OPTIONS}
# )
# target_link_options(cxxrt-shared PRIVATE
#     ${COMMON_LINK_OPTIONS}
# )
# target_include_directories(cxxrt-shared PRIVATE
#     ${CMAKE_CURRENT_LIST_DIR}/include
# )
