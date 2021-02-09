
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// stdlib.h for MRNIU/MiniCRT.

#ifndef __STDLIB_H__
#define __STDLIB_H__

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

void  free(void *ptr);
void *malloc(size_t size);

char *itoa(int n, char *str, int radix);

typedef void (*atexit_func_t)(void);
int atexit(atexit_func_t func);

#ifdef __cplusplus
}
#endif

#endif /* __STDLIB_H__ */
