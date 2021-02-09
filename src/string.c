
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// string.c for MRNIU/MiniCRT.

#ifdef __cplusplus
extern "C" {
#endif

#include "string.h"
#include "stddef.h"

// 获取字符串长度
uint64_t strlen(const char *str) {
    if (str == NULL) {
        return 0;
    }
    uint64_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

// 如果 src > dest, 则返回值大于 0，如果 src = dest, 则返回值等于 0，
// 如果 srd  < dest ,则返回值小于 0。
int8_t strcmp(const char *src, const char *dest) {
    while (*src && *dest && (*src == *dest)) {
        src++;
        dest++;
    }
    return *src - *dest;
}

char *strcpy(char *dest, const char *src) {
    char *address = dest;
    while ((*dest++ = *src++) != '\0') {
        ;
    }
    return address;
}

void backspace(char *src) {
    uint64_t len = strlen(src);
    src[len - 1] = '\0';
}

void append(char *src, char dest) {
    uint64_t len = strlen(src);
    src[len]     = dest;
    src[len + 1] = '\0';
}

char *strcat(char *dest, const char *src) {
    uint8_t *add_d = (uint8_t *)dest;
    if (dest != NULL && src != NULL) {
        while (*add_d) {
            add_d++;
        }
        while (*src) {
            *add_d++ = *src++;
        }
    }
    return dest;
}

void memcpy(void *dest, void *src, uint32_t len) {
    uint8_t *sr  = (uint8_t *)src;
    uint8_t *dst = (uint8_t *)dest;
    while (len != 0) {
        *dst++ = *sr++;
        len--;
    }
}
void memset(void *dest, uint8_t val, uint32_t len) {
    for (uint8_t *dst = (uint8_t *)dest; len != 0; len--) {
        *dst++ = val;
    }
}

void bzero(void *dest, uint32_t len) {
    memset(dest, 0, len);
}

char *itoa(int n, char *str, int radix) {
    char  digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p       = str;
    char *head    = str;
    if (!p || radix < 2 || radix > 36) {
        return p;
    }
    if (radix != 10 && n < 0) {
        return p;
    }
    if (n == 0) {
        *p++ = '0';
        *p   = 0;
        return p;
    }
    if (radix == 10 && n < 0) {
        *p++ = '-';
        n    = -n;
    }
    while (n) {
        *p++ = digit[n % radix];
        n /= radix;
    }
    *p = 0;
    for (--p; head < p; ++head, --p) {
        char temp = *head;
        *head     = *p;
        *p        = temp;
    }
    return str;
}

#ifdef __cplusplus
}
#endif
