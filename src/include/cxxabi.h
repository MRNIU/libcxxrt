
/**
 * @file cxxabi.h
 * @brief cxxabi header
 * @author Zone.N (Zone.Niuzh@hotmail.com)
 * @version 1.0
 * @date 2023-09-07
 * @copyright MIT LICENSE
 * https://github.com/MRNIU/libcxxrt
 * @par change log:
 * <table>
 * <tr><th>Date<th>Author<th>Description
 * <tr><td>2023-09-07<td>Zone.N<td>迁移到 doxygen
 * </table>
 */

#ifndef LIBCXXRT_CXXABI_H
#define LIBCXXRT_CXXABI_H

// See https://gcc.gnu.org/onlinedocs/gccint/Initialization.html for more info

#define ATEXIT_MAX_FUNCS 128

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned uarch_t;

struct atexit_func_entry_t {
  void (*destructor_func)(void *);
  void *obj_ptr;
  void *dso_handle;
};

#ifdef WIN32
typedef void (*init_func)(void);
#pragma section(".CRT$XCA", long, read)
#pragma section(".CRT$XCZ", long, read)
__declspec(allocate(".CRT$XCA")) init_func ctors_begin[] = {0};
__declspec(allocate(".CRT$XCZ")) init_func ctors_end[] = {0};
#else
int __cxa_atexit(void (*f)(void *), void *objptr, void *dso);
void __cxa_finalize(void *f);
void __cxa_pure_virtual();
void __stack_chk_guard_setup();
void __attribute__((noreturn)) __stack_chk_fail();
void _Unwind_Resume();

namespace __cxxabiv1 {
/* guard variables */

/* The ABI requires a 64-bit type.  */
__extension__ typedef int __guard __attribute__((mode(__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release(__guard *);
extern "C" void __cxa_guard_abort(__guard *);
} // namespace __cxxabiv1

void __cxa_finalize(void *f);
#endif

#if __clang__
typedef void (*Initializer)(int argc, const char *argv[], const char *envp[],
                            const char *apple[]);
extern const Initializer
    inits_start __asm__("section$start$__DATA$__mod_init_func");
extern const Initializer
    inits_end __asm__("section$end$__DATA$__mod_init_func");
#elif __linux__
typedef void (*constructor_func)();
constructor_func ctors_start[1]
    __attribute__((section(".ctors"))) = {(constructor_func)-1};
constructor_func ctors_end[1]
    __attribute__((section(".ctors"))) = {(constructor_func)-1};
#endif

#ifdef __cplusplus
}
#endif

#endif /* LIBCXXRT_CXXABI_H */
