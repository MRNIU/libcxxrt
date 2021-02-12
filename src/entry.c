
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// entry.c for MRNIU/MiniCRT.

#include "minicrt.h"
#include "stddef.h"
#include "unistd.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#include <Windows.h>
#endif

extern int main(int argc, char *argv[]);
void       exit(int);

static void crt_fatal_error(const char *msg) {
    printf("fatal error: %s", msg);
    exit(1);
    return;
}

void mini_crt_entry(void) {
    int ret = 0;

#ifdef WIN32
    int   flag = 0;
    int   argc = 0;
    char *argv[16];
    char *cl = GetCommandLineA();

    //解析命令行
    argv[0] = cl;
    argc++;
    while (*cl) {
        if (*cl == '\"')
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
        else if (*cl == ' ' && flag == 0) {
            if (*(cl + 1)) {
                argv[argc] = cl + 1;
                argc++;
            }
            *cl = '\0';
        }
        cl++;
    }

#else
    int    argc = 0;
    char **argv = NULL;

#if defined(__i386__)
    char *ebp_reg = NULL;
    __asm__ __volatile__("movl %%ebp, %0" : "=r"(ebp_reg));
    argc = *(int *)(ebp_reg + 4);
    argv = (char **)(ebp_reg + 8);
#elif defined(__x86_64__)
#if __APPLE__
    long argcL = 0;
    long argvL = 0;
    __asm__ __volatile__("mov %%rdi, %0" : "=r"(argcL));
      __asm__ __volatile__("mov %%rsi, %0" : "=r"(argvL));
    argc = (int)argcL;
    argv = (char **)argvL;
#elif __linux__
    char * rbp_reg=NULL;
        __asm__ __volatile__("mov %%rbp, %0":"=r"(rbp_reg));
    argc=*(long*)(rbp_reg+8);
    argv=(char**)(rbp_reg+16);
#endif
#endif
#endif

    if (mini_crt_heap_init() != 0) {
        crt_fatal_error("heap initialize failed");
    }

    if (mini_crt_io_init() != 0) {
        crt_fatal_error("IO initialize failed");
    }
    /*do_global_ctors();*/
    ret = main(argc, argv);
    exit(ret);
    return;
}

void exit(int exitCode) {
    // mini_crt_call_exit_routine();
#ifdef WIN32
    ExitProcess(exitCode);
#elif defined(__i386__)
    __asm__ __volatile__("int $80" : : "0"(SYSCALL_exit), "b"(exitCode));
#elif defined(__x86_64__)
    __asm__ __volatile__("syscall" : : "a"(SYSCALL_exit), "D"(exitCode));
#endif
    return;
}

#ifdef __cplusplus
}
#endif
