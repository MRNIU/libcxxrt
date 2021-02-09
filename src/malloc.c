
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// malloc.c for MRNIU/MiniCRT.

#include "minicrt.h"

typedef struct heap_header {
    enum {
        // magic number of free block
        HEAP_BLOCK_FREE = 0xABABABAB,
        // magic number of used block
        HEAP_BLOCK_USED = 0xCDCDCDCD,
    } type;

    uint32_t            size;
    struct heap_header *prev;
    struct heap_header *next;
} heap_header_t;

#define ADDR_ADD(a, o) (((char *)(a)) + o)
#define HEADER_SIZE (sizeof(heap_header_t))

static heap_header_t *list_head = NULL;

void free(void *ptr) {
    heap_header_t *header = (heap_header_t *)ADDR_ADD(ptr, -HEADER_SIZE);
    if (header->type != HEAP_BLOCK_USED) {
        return;
    }

    header->type = HEAP_BLOCK_FREE;
    if (header->prev != NULL && header->prev->type == HEAP_BLOCK_FREE) {
        // merge
        header->prev->next = header->prev;
        if (header->next != NULL) {
            header->next->prev = header->prev;
        }
        header->prev->size += header->size;
        header = header->prev;
    }

    if (header->next != NULL && header->next->type == HEAP_BLOCK_FREE) {
        // merge
        header->size += header->next->size;
        header->next = header->next->next;
    }
}

void *malloc(uint64_t size) {
    if (size == 0) {
        return NULL;
    }
    heap_header_t *header = list_head;
    while (header != NULL) {
        if (header->type == HEAP_BLOCK_USED) {
            header = header->next;
            continue;
        }
        // 块大小足够 size，但是不够分配 HEADER_SIZE
        if (header->size > size + HEADER_SIZE &&
            header->size <= size + HEADER_SIZE * 2) {
            // 设置后返回
            header->type = HEAP_BLOCK_USED;
            return ADDR_ADD(header, HEADER_SIZE);
        }

        // 块大小足够切割出 next 块
        if (header->size > size + HEADER_SIZE * 2) {
            // 切割
            heap_header_t *next =
                (heap_header_t *)ADDR_ADD(header, size + HEADER_SIZE);
            next->prev   = header;
            next->next   = header->next;
            next->type   = HEAP_BLOCK_FREE;
            next->size   = header->size - (size - HEADER_SIZE);
            header->next = next;
            header->size = size + HEADER_SIZE;
            header->type = HEAP_BLOCK_USED;
            // 返回
            return ADDR_ADD(header, HEADER_SIZE);
        }
        header = header->next;
    }
    // 执行到这里说明没有找到
    return NULL;
}

#ifdef WIN32
#include <Windows.h>
#else
// Linux mmap system call
static void *mmap(uint64_t len) {
    void *ret = NULL;
#if defined(__i386__)

#elif defined(__x86_64__)
    void *            addr               = NULL;
    int64_t           prot               = PROT_READ | PROT_WRITE;
    int64_t           flag               = MAP_ANON | MAP_PRIVATE;
    int64_t           fd                 = -1;
    uint64_t          off                = 0;
    register int64_t  r10 __asm__("r10") = flag;
    register int64_t  r8 __asm__("r8")   = fd;
    register uint64_t r9 __asm__("r9")   = off;
    __asm__ __volatile__("syscall"
                         : "=a"(ret)
                         : "a"(SYSCALL_mmap), "D"(addr), "S"(len), "d"(prot),
                           "r"(r10), "r"(r8), "r"(r9)
                         : "rcx", "r11", "memory");
#endif
    return ret;
}
#endif

int32_t mini_crt_heap_init() {
    // 32MB heap size
    uint64_t heap_size = 1024 * 1024 * 32;

#ifdef WIN32
    list_head = (heap_header_t *)VirtualAlloc(
        0, heap_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (list_head == NULL) {
        return 0;
    }
#else
    list_head = (heap_header_t *)mmap(heap_size);
    if (list_head == MAP_FAILED) {
        return -1;
    }
#endif

    list_head->size = heap_size;
    list_head->type = HEAP_BLOCK_FREE;
    list_head->next = NULL;
    list_head->prev = NULL;
    return 0;
}
