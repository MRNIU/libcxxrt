
/**
 * @file string.cpp
 * @brief string cpp
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

#include "string.h"
#include "stdint.h"
#include "string"

namespace std {
string::string(const char *str) : len(0), pbuf(0) {
  *this = str;
  return;
}

string::string(const string &s) : len(0), pbuf(0) {
  *this = s;
  return;
}

string::~string(void) {
  if (pbuf != NULL) {
    delete[] pbuf;
    pbuf = 0;
  }
  return;
}

string &string::operator=(const string &s) {
  if (&s == this) {
    return *this;
  }
  this->~string();
  len = s.len;
  pbuf = strcpy(new char[len + 1], s.pbuf);
  return *this;
}

string &string::operator=(const char *s) {
  this->~string();
  len = strlen(s);
  pbuf = strcpy(new char[len + 1], s);
  return *this;
}

const char &string::operator[](size_t idx) const { return pbuf[idx]; }

char &string::operator[](size_t idx) { return pbuf[idx]; }

const char *string::c_str(void) const { return pbuf; }

size_t string::length(void) const { return len; }

size_t string::size(void) const { return len; }

ofstream &operator<<(ofstream &o, const string &s) { return o << s.c_str(); }
}; // namespace std
