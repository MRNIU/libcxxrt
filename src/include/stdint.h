
/**
 * @file stdint.h
 * @brief stdint header
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

#ifndef LIBCXXRT_STDINT_H
#define LIBCXXRT_STDINT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

#ifdef __cplusplus
}
#endif

#endif /* LIBCXXRT_STDINT_H */
