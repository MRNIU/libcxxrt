
/**
 * @file stdarg.h
 * @brief stdarg header
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

#ifndef LIBCXXRT_STDARG_H
#define LIBCXXRT_STDARG_H

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

#endif /* LIBCXXRT_STDARG_H */
