
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// minicrt.h for MRNIU/MiniCRT.

#ifndef __MINICRT_H__
#define __MINICRT_H__

#ifdef __cplusplus
extern "C" {
#endif

// malloc.c
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef signed char int8_t;
typedef short int   int16_t;
typedef int         int32_t;
typedef long long   int64_t;

typedef unsigned char      uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

void    free(void *ptr);
void *  malloc(uint64_t size);
int32_t mini_crt_heap_init();

// string.c
char *   itoa(int n, char *str, int radix);
int8_t   strcmp(const char *src, const char *dst);
char *   strcpy(char *dest, const char *src);
uint64_t strlen(const char *str);
void     memset(void *dest, uint8_t val, uint32_t len);
void     bzero(void *dest, uint32_t len);

// stdio.c
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

int     mini_crt_io_init();
FILE *  fopen(const char *filename, const char *mode);
int64_t fread(void *buffer, uint64_t size, uint64_t count, FILE *stream);
int64_t fwrite(const void *buffer, uint64_t size, uint64_t count, FILE *stream);
int64_t fclose(FILE *fp);
int64_t fseek(FILE *fp, uint64_t offest, int set);

// format.c
int fputc(int c, FILE *stream);
int fputs(const char *str, FILE *stream);
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);

// internal
void do_global_ctors();
void mini_crt_call_exit_routine();

// atexit
typedef void (*atexit_func_t)(void);
int atexit(atexit_func_t func);

// linux 系统调用号
#if __linux__
#define SYSCALL_read 3
#define SYSCALL_write 4
#define SYSCALL_open 5
#define SYSCALL_close 6
#define SYSCALL_lseek 19
#define SYSCALL_mmap 45
#define SYSCALL_exit 60
#endif

#if __APPLE__
// OSX 的系统调用基于 BSD，需要加上 0x2000000
#define BSD 0x2000000
#define SYSCALL_exit (BSD + 1)
#define SYSCALL_read (BSD + 3)
#define SYSCALL_write (BSD + 4)
#define SYSCALL_open (BSD + 5)
#define SYSCALL_close (BSD + 6)
#define SYSCALL_mmap (BSD + 197)
#define SYSCALL_lseek (BSD + 199)
// mmap 调用参数
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define MAP_ANON 0x1000
#define MAP_PRIVATE 0x2
#define MAP_FAILED ((void *)-1)
// open mode
// open for reading only
#define O_RDONLY 0x0000
// open for writing only
#define O_WRONLY 0x0001
// open for reading and writing
#define O_RDWR 0x0002
// mask for above modes
#define O_ACCMODE 0x0003
// create if nonexistant
#define O_CREAT 0x0200
// truncate to zero length
#define O_TRUNC 0x0400
// error if already exists
#define O_EXCL 0x0800

#endif

#ifdef __cplusplus
}
#endif

#endif /* __MINICRT_H__ */
