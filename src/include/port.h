
/**
 * @file port.h
 * @brief port header
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
#ifndef LIBCXXRT_PORT_H
#define LIBCXXRT_PORT_H

#ifdef WIN32
#define UNUSED(x)
#else
#define UNUSED(x) (x) __attribute__((unused))
#define FALLTHROUHT __attribute__((fallthrough))
#endif

#endif /* LIBCXXRT_PORT_H */
