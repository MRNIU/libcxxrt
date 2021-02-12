
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// ctor.cpp for MRNIU/MiniCRT.

#include "stdlib.h"

#ifdef WIN32
typedef void (*init_func)(void);
#pragma section(".CRT$XCA", long, read)
#pragma section(".CRT$XCZ", long, read)

__declspec(allocate(".CRT$XCA")) init_func ctors_begin[] = {0};
__declspec(allocate(".CRT$XCZ")) init_func ctors_end[]   = {0};

extern "C" void do_global_ctors(void) {
    init_func *p = ctors_begin;
    while (p < ctors_end) {
        if (*p != NULL) {
            (**p)();
        }
        p++;
    }
    return;
}

#elif __APPLE__

typedef void (*Initializer)(int argc, const char *argv[], const char *envp[],
                            const char *apple[]);
extern const Initializer
    inits_start __asm__("section$start$__DATA$__mod_init_func");
extern const Initializer
    inits_end __asm__("section$end$__DATA$__mod_init_func");

extern "C" void do_global_ctors(void) {
    const Initializer *p;
    for (p = &inits_start; p < &inits_end; ++p) {
        (*p)(0, 0, 0, 0);
    }
    return;
}

#elif __linux__

typedef void (*ctor_func_t)();

extern "C" ctor_func_t ctors_start[1]
    __attribute__((section(".ctors"))) = {(ctor_func_t)-1};
extern "C" ctor_func_t ctors_end[1]
    __attribute__((section(".ctors"))) = {(ctor_func_t)-1};

extern "C" void do_global_ctors(void) {
    ctor_func_t *f;
    for (f = ctors_start; f < ctors_end; f++) {
        (*f)();
    }
    return;
}

#endif
