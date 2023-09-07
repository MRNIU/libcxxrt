
/**
 * @file minicrt.h
 * @brief minicrt header
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

#ifndef __MINICRT_H__
#define __MINICRT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

int mini_crt_io_init();
int32_t mini_crt_heap_init();

// internal
void do_global_ctors();
void mini_crt_call_exit_routine();

#ifdef __cplusplus
}
#endif

#endif /* __MINICRT_H__ */
