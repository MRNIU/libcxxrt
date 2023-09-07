
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// string.h for MRNIU/MiniCRT.

#ifndef __STRING_H__
#define __STRING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

int8_t strcmp(const char *src, const char *dst);
char *strcpy(char *dest, const char *src);
uint64_t strlen(const char *str);
void memset(void *dest, uint8_t val, uint32_t len);
void bzero(void *dest, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* __STRING_H__ */
