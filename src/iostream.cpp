
/**
 * @file iostream.cpp
 * @brief iostream cpp
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

#include "iostream"
#include "stddef.h"
#include "string.h"

#ifdef WIN32
#include <Windows.h>
#endif

namespace std {
ofstream::ofstream(void) : fp(0) { return; }

ofstream::ofstream(const char *filename, ofstream::openmode md) {
  open(filename, md);
  return;
}

ofstream::~ofstream(void) {
  close();
  return;
}

ofstream &ofstream::operator<<(char c) {
  fputc(c, fp);
  return *this;
}

ofstream &ofstream::operator<<(int n) {
  fprintf(fp, "%d", n);
  return *this;
}

ofstream &ofstream::operator<<(const char *lhs) {
  fprintf(fp, "%s", lhs);
  return *this;
}

ofstream &ofstream::operator<<(ofstream &(*manip)(ofstream &)) {
  return manip(*this);
}

void ofstream::open(const char *filename, ofstream::openmode md) {
  char mode[4];
  close();

  switch ((uint8_t)md) {
  case out | trunc: {
    strcpy(mode, "w");
    break;
  }
  case out | in | trunc: {
    strcpy(mode, "w+");
    break;
  }
  case out | trunc | binary: {
    strcpy(mode, "wb");
    break;
  }
  case out | in | trunc | binary: {
    strcpy(mode, "wb+");
    break;
  }
  }
  fp = fopen(filename, mode);
  return;
}

void ofstream::close(void) {
  if (fp != NULL && fp != stdin && fp != stdout && fp != stderr) {
    fclose(fp);
    fp = 0;
  }
  return;
}

ofstream &ofstream::write(const char *buf, unsigned size) {
  fwrite(buf, 1, size, fp);
  return *this;
}

stdout_stream::stdout_stream(void) : ofstream() {
  fp = stdout;
  return;
}

stdout_stream::stdout_stream(const stdout_stream &) : ofstream() { return; }

stdout_stream::~stdout_stream(void) { return; }

// 这里的警告实在消不掉，出此下策
#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
stdout_stream cout;
#pragma clang diagnostic pop
#elif __linux__
stdout_stream cout;
#endif
}; // namespace std
