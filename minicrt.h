//  Created by 牛志宏 on 2017/12/11.
//  Copyright © 2017年 牛志宏. All rights reserved.
//minicrt.h

#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__

#ifdef __cplusplus
extern "C"{
#endif

//malloc.c
#ifndef NULL
#define NULL (0)
#endif

void free(void *ptr);
void *malloc(unsigned size);
int mini_crt_init_heap();


//string.c
char *itoa(int n,char *str,int radix);
int strcmp(const char *src,const char *dst);
char *strcpy(char *dest,const char *src);
unsigned strlen(const char *str);


//stdio.c
typedef int FILE;
#define EOF (-1)

#ifdef WIN32
#define	stdin ((FILE*)(GetStdHandle(STD_INPUT_HANDLE)))
#define stdout	((FILE*)(GetStdHandle(STD_OUTPUT_HANDLE)))
#define	stderr	((FILE*)(GetStdHandle(STD_ERROR_HANDLE)))
#else
#define stdin ((FILE*)0)
#define	stdout	((FILE*)1)
#define	stderr	((FILE*)2)
#endif

int mini_crt_init_io();
FILE* fopen(const char *filename,const char *mode);
int fread(void *buffer,int size,int count,FILE *stream);
int fwrite(const void *buffer,int size,int count,FILE *stream);
int fclose(FILE *fp);
int fseek(FILE *fp,int offest,int set);


//format.c
int fputc(int c,FILE *stream);
int fputs(const char *str,FILE *stream);
int printf(const char *format,...);
int fptintf(FILE *stream,const char *format,...);


//internal
void do_global_ctors();
void mini_crt_call_exit_routine();


//atexit
typedef void (*atexit_func_t)(void);
int atexit(atexit_func_t func);


#ifdef __cplusplus
}
#endif

#endif	// __MINI_CRT_H__
