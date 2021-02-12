
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// atexit.c for MRNIU/MiniCRT.

#ifdef __cplusplus
extern "C" {
#endif

#include "stdlib.h"

 typedef void (*cxa_func_t)(void*);
 typedef void (*atexit_func_t)(void);
 int __cxa_atexit(cxa_func_t func, void* arg, void*);
 int atexit(atexit_func_t func);

 typedef struct func_node{
    atexit_func_t func;
    void* arg;
    int is_cxa;
struct func_node *next;
 }func_node_t;

static func_node_t * atexit_list=0;

int register_atexit(atexit_func_t func,void*arg,int is_cxa){
    func_node_t * node;
    if(func==0){
        return -1;
    }
    node->func=func;
    node->arg=arg;
    node->is_cxa=is_cxa;
    node->next=atexit_list;
    atexit_list=node;
    return 0;
}

#ifdef WIN32

#else
int __cxa_atexit(cxa_func_t func,void* arg,void*unused){
    return register_atexit((atexit_func_t)func,arg,1);
}

#endif

int atexit(atexit_func_t func){
    return register_atexit(func,0,0);
}

void mini_crt_call_exit_routine(void){
    func_node_t *p=atexit_list;
    while(p!=0){
        #ifdef WIN32
    p->func();
#else
    if(p->is_cxa){
        ((cxa_func_t)p->func)(p->arg);
    }
    else{
    p->func();
    }
    }
#endif
    free(p);
    atexit_list=0;
    return;
}

#ifdef __cplusplus
}
#endif







