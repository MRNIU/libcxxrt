
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// stddef.h for MRNIU/MiniCRT.

#ifndef __STDDEF_H__
#define __STDDEF_H__

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

#ifdef __cplusplus
}
#endif

#endif /* __STDDEF_H__ */
