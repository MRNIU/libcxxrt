
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// new_delete.cpp for MRNIU/MiniCRT.

#include "stdlib.h"

void *operator new(size_t size) {
    return malloc(size);
}

void *operator new[](size_t size) {
    return malloc(size);
}

void operator delete(void *p) noexcept {
    if (p != NULL) {
        free(p);
    }
}

void operator delete[](void *p) noexcept {
    if (p != NULL) {
        free(p);
    }
}
