
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
// Based on https://wiki.osdev.org/C%2B%2B
// cxxabi.cpp for MRNIU/MiniCRT.

#include "cxxabi.h"
#include "stddef.h"

#ifdef WIN32
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
#else
atexit_func_entry_t __atexit_funcs[ATEXIT_MAX_FUNCS];
uarch_t             __atexit_func_count = 0;

void *__dso_handle = 0;
void *__stack_chk_guard(0);

int __cxa_atexit(void (*f)(void *), void *objptr, void *dso) {
    if (__atexit_func_count >= ATEXIT_MAX_FUNCS) {
        return -1;
    };
    __atexit_funcs[__atexit_func_count].destructor_func = f;
    __atexit_funcs[__atexit_func_count].obj_ptr         = objptr;
    __atexit_funcs[__atexit_func_count].dso_handle      = dso;
    __atexit_func_count++;
    return 0;
};

void __cxa_finalize(void *f) {
    uarch_t i = __atexit_func_count;
    if (!f) {
        while (i--) {
            if (__atexit_funcs[i].destructor_func) {
                (*__atexit_funcs[i].destructor_func)(__atexit_funcs[i].obj_ptr);
            };
        };
        return;
    };

    while (i--) {
        if (__atexit_funcs[i].destructor_func == f) {
            (*__atexit_funcs[i].destructor_func)(__atexit_funcs[i].obj_ptr);
            __atexit_funcs[i].destructor_func = 0;
        }
    }
    return;
}

void __cxa_pure_virtual() {
    return;
}

void __attribute__((noreturn)) __stack_chk_fail() {
    for (;;) {
        ;
    }
}

void __stack_chk_guard_setup() {
    unsigned char *Guard;
    Guard                                = (unsigned char *)&__stack_chk_guard;
    Guard[sizeof(__stack_chk_guard) - 1] = 255;
    Guard[sizeof(__stack_chk_guard) - 2] = '\n';
    Guard[0]                             = 0;
    return;
}

void _Unwind_Resume() {
    return;
}

namespace __cxxabiv1 {
    int __cxa_guard_acquire(__guard *g) {
        return !*(char *)(g);
    }

    void __cxa_guard_release(__guard *g) {
        *(char *)g = 1;
        return;
    }

    void __cxa_guard_abort(__guard *) {
        return;
    }
}

void *__gxx_personality_v0 = (void *)0xDEADBEAF;

#if __clang__
extern "C" void do_global_ctors(void) {
    const Initializer *p;
    for (p = &inits_start; p < &inits_end; ++p) {
        (*p)(0, 0, 0, 0);
    }
    return;
}

#elif __linux__
extern "C" void do_global_ctors(void) {
    constructor_func *f;
    for (f = ctors_start; f < ctors_end; f++) {
        (*f)();
    }
    return;
}
#endif

#endif
