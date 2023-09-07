
/**
 * @file string.h
 * @brief string header
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

#ifndef LIBCXXRT_STRING_H
#define LIBCXXRT_STRING_H

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

#endif /* LIBCXXRT_STRING_H */
