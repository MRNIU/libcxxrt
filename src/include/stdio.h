
/**
 * @file stdio.h
 * @brief stdio header
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

#ifndef LIBCXXRT_STDIO_H
#define LIBCXXRT_STDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

typedef int FILE;
#define EOF (-1)

#ifdef WIN32
#define stdin ((FILE *)(GetStdHandle(STD_INPUT_HANDLE)))
#define stdout ((FILE *)(GetStdHandle(STD_OUTPUT_HANDLE)))
#define stderr ((FILE *)(GetStdHandle(STD_ERROR_HANDLE)))
#else
#define stdin ((FILE *)0)
#define stdout ((FILE *)1)
#define stderr ((FILE *)2)
#endif

FILE *fopen(const char *filename, const char *mode);
int64_t fread(void *buffer, uint64_t size, uint64_t count, FILE *stream);
int64_t fwrite(const void *buffer, uint64_t size, uint64_t count, FILE *stream);
int64_t fclose(FILE *fp);
int64_t fseek(FILE *fp, uint64_t offest, int set);

int fputc(int c, FILE *stream);
int fputs(const char *str, FILE *stream);
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* LIBCXXRT_STDIO_H */
