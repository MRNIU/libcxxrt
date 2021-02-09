
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// minicrt.h for MRNIU/MiniCRT.

#ifndef __MINICRT_H__
#define __MINICRT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

int     mini_crt_io_init();
int32_t mini_crt_heap_init();

// internal
void do_global_ctors();
void mini_crt_call_exit_routine();

#ifdef __cplusplus
}
#endif

#endif /* __MINICRT_H__ */
