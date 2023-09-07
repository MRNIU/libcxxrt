
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// stdio.c for MRNIU/MiniCRT.

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "string.h"
#include "unistd.h"

int mini_crt_io_init() { return 0; }

#ifdef WIN32
#include <Windows.h>
FILE *fopen(const char **filename, const char *mode) {
  HANDLE hfile = 0;
  int access = 0;
  int creation = 0;

  if (strcmp(mode, "w") == 0) {
    access |= GENERIC_WRITE;
    creation |= CREATE_ALWAYS;
  }

  if (strcmp(mode, "w+") == 0) {
    access |= GENERIC_WRITE | GENERIC_READ;
    creation |= CREATE_ALWAYS;
  }

  if (strcmp(mode, "r") == 0) {
    access |= GENERIC_READ;
    creation += OPEN_EXISTING;
  }

  if (strcmp(mode, "r+") == 0) {
    access |= GENERIC_WRITE | GENERIC_READ;
    creation |= TRUNCATE_EXISTING;
  }

  hFile = CreateFileA(filename, access, 0, 0, creation, 0, 0);
  if (hFile == INVALID_HANDLE_VALUE) {
    return 0;
  }

  return (FILE *)hFile;
}

int fread(void *buffer, int size, int count, FILE *stream) {
  int read = 0;
  if (!ReadFile((HANDLE)stream, buffer, size * count, &read, 0)) {
    return 0;
  }
  return read;
}

int fwrite(const void *buffer, int size, int count, FILE *stream) {
  int written = 0;
  if (!WriteFile((HANDLE)stream, buffer, size * count, &written, 0)) {
    return 0;
  }
  return written;
}

int fclose(FILE *fp) { return CloseHandle((HANDLE)fp); }

int fseek(FILE *fp, int offest, int set) {
  return SetFilePointer((HANDLE)fp, offest, 0, set);
}

#else

static int64_t read(int fd, void *buffer, uint64_t size) {
  int64_t ret = 0;
#if defined(__i386__)
  // __asm__ __volatile__("mov $3,%%eax	\n\t"
  //                      "mov %1,%%ebx	\n\t"
  //                      "mov %2,%%ecx	\n\t"
  //                      "mov %3,%%edx	\n\t"
  //                      "int $0x80		\n\t"
  //                      : "=m"(ret)
  //                      : "m"(fd), "m"(buffer), "m"(size));
  __asm__ __volatile__("int $0x80"
                       : "=m"(ret)
                       : "a"(SYSCALL_read), "b"(fd), "c"(buffer),
                         "d"((uint32_t)size));
#elif defined(__x86_64__)
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(SYSCALL_read), "D"(fd), "S"(buffer), "d"(size));
#endif
  return ret;
}

static int64_t write(int fd, const void *buffer, uint64_t size) {
  int64_t ret = 0;
#if defined(__i386__)
  // __asm__ __volatile__("mov $4,%%eax	\n\t"
  //                      "mov %1,%%ebx	\n\t"
  //                      "mov %2,%%ecx	\n\t"
  //                      "mov %3,%%edx	\n\t"
  //                      "int $0x80		\n\t"
  //                      "mov %%eax,%0	\n\t"
  //                      : "=m"(ret)
  //                      : "m"(fd), "m"(buffer), "m"(size));
  __asm__ __volatile__("int $0x80"
                       : "=m"(ret)
                       : "a"(SYSCALL_write), "b"(fd), "c"(buffer),
                         "d"((uint32_t)size));
#elif defined(__x86_64__)
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(SYSCALL_write), "D"(fd), "S"(buffer), "d"(size));
#endif
  return ret;
}

static int64_t open(const char *pathname, int flags, int mode) {
  int fd = 0;
#if defined(__i386__)
  // __asm__ __volatile__("mov $5,%%eax	\n\t"
  //                      "mov %1,%%ebx	\n\t"
  //                      "mov %2,%%ecx	\n\t"
  //                      "mov %3,%%edx	\n\t"
  //                      "int $0x80		\n\t"
  //                      : "=m"(fd)
  //                      : "m"(pathname), "m"(flags), "m"(mode));
  __asm__ __volatile__("int $0x80"
                       : "=m"(fd)
                       : "a"(SYSCALL_open), "b"(pathname), "c"(flags),
                         "d"(mode));
#elif defined(__x86_64__)
  __asm__ __volatile__("syscall"
                       : "=a"(fd)
                       : "a"(SYSCALL_open), "D"(pathname), "S"(flags),
                         "d"(mode));
#endif
  return fd;
}

static int64_t close(int fd) {
  int64_t ret = 0;
#if defined(__i386__)
  __asm__ __volatile__("mov $6,%%eax	\n\t"
                       "mov %1,%%ebx	\n\t"
                       "int $0x80		\n\t"
                       "mov %%eax,%0	\n\t"
                       : "=m"(ret)
                       : "m"(fd));
#elif defined(__x86_64__)
  __asm__ __volatile__("syscall" : "=a"(ret) : "a"(SYSCALL_close), "D"(fd));
#endif
  return ret;
}

static int64_t seek(int fd, uint64_t offest, int mode) {
  int64_t ret = 0;
#if defined(__i386__)
  // __asm__ __volatile__("mov $19,%%eax	\n\t"
  //                      "mov %1,%%ebx	\n\t"
  //                      "mov %2,%%ecx	\n\t"
  //                      "mov %3,%%edx	\n\t"
  //                      "int $0x80		\n\t"
  //                      "mov %%eax,%0	\n\t"
  //                      : "=m"(ret)
  //                      : "m"(fd), "m"(offest), "m"(mode));
  __asm__ __volatile__("int $0x80"
                       : "=m"(ret)
                       : "a"(SYSCALL_lseek), "b"(fd), "c"((uint32_t)offest),
                         "d"(mode));
#elif defined(__x86_64__)
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(SYSCALL_lseek), "D"(fd), "S"(offest), "d"(mode));
#endif
  return ret;
}

int64_t fread(void *buffer, uint64_t size, uint64_t count, FILE *stream) {
  return read((int)(long)stream, buffer, size * count);
}

int64_t fwrite(const void *buffer, uint64_t size, uint64_t count,
               FILE *stream) {
  return write((int)(long)stream, buffer, size * count);
}

FILE *fopen(const char *filename, const char *mode) {
  int fd = -1;
  int flags = 0;
  // 文件权限
  int access = 00700;

  if (strcmp(mode, "w") == 0) {
    flags |= O_WRONLY | O_CREAT | O_TRUNC;
  }
  if (strcmp(mode, "w+") == 0) {
    flags |= O_RDWR | O_CREAT | O_TRUNC;
  }
  if (strcmp(mode, "r") == 0) {
    flags |= O_RDONLY;
  }
  if (strcmp(mode, "r+") == 0) {
    flags |= O_RDWR | O_CREAT;
  }
  fd = open(filename, flags, access);
  return (FILE *)(long)fd;
}

int64_t fclose(FILE *fp) { return close((int)(long)fp); }

int64_t fseek(FILE *fp, uint64_t offest, int set) {
  return seek((int)(long)fp, offest, set);
}

#ifdef __cplusplus
}
#endif

#endif /* WIN32 */
