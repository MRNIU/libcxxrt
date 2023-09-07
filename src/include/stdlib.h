
/**
 * @file stdlib.h
 * @brief stdlib header
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

#ifndef LIBCXXRT_STDLIB_H
#define LIBCXXRT_STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef size_t
#if defined(__i386__)
typedef unsigned int size_t;
#elif defined(__x86_64__)
typedef unsigned long size_t;
#endif
#endif

void free(void *ptr);
void *malloc(size_t size);

char *itoa(int n, char *str, int radix);

typedef void (*atexit_func_t)(void);
int atexit(atexit_func_t func);

#ifdef __cplusplus
}
#endif

#endif /* LIBCXXRT_STDLIB_H */
