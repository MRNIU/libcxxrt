
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// port.h for MRNIU/MiniCRT.

#ifndef __PORT_H__
#define __PORT_H__

#ifdef WIN32
#define UNUSED(x)
#else
#define UNUSED(x) (x) __attribute__((unused))
#define FALLTHROUHT __attribute__((fallthrough))
#endif

#endif /* __PORT_H__ */
