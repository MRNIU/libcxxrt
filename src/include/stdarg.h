
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// stdarg.h for MRNIU/MiniCRT.

#ifndef __STDARG_H__
#define __STDARG_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#include <Windows.h>
#elif defined(__i386__)
typedef char *va_list;
#define __va_SIZE(TYPE)                                                        \
    (((sizeof(TYPE) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))
#define va_start(AP, LASTARG)                                                  \
    (AP = ((va_list) & (LASTARG) + __va_SIZE(LASTARG)))
#define va_arg(AP, TYPE)                                                       \
    (AP += __va_SIZE(TYPE), *((TYPE *)(AP - __va_SIZE(TYPE))))
#define va_end(AP) (AP = (va_list)0)

#elif defined(__x86_64__)
// TODO: 独立实现
#define va_list __builtin_va_list
#define va_arg(ap, type) __builtin_va_arg(ap, type)
#define va_start(v, l) __builtin_va_start(v, l)
#define va_end(v) __builtin_va_end(v)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __STDARG_H__ */
