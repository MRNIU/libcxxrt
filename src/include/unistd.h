
/**
 * @file unistd.h
 * @brief unistd header
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

#ifndef LIBCXXRT_UNISTD_H
#define LIBCXXRT_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

// linux 系统调用号
#if __linux__
#define SYSCALL_read 0
#define SYSCALL_write 1
#define SYSCALL_open 2
#define SYSCALL_close 3
#define SYSCALL_lseek 8
#define SYSCALL_mmap 9
#define SYSCALL_exit 60

#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define MAP_ANON 0x20
#define MAP_PRIVATE 0x2
#define MAP_FAILED ((void *)-1)

#define O_RDONLY 00000000
#define O_WRONLY 00000001
#define O_RDWR 00000002
#define O_ADDMODE 00000003
#define O_CREAT 00000100
#define O_TRUNC 00001000
#define O_EXCL 00000200
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

#endif /* LIBCXXRT_UNISTD_H */
