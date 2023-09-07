
/**
 * @file new_delete.cpp
 * @brief new_delete cpp
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

#include "port.h"
#include "stdlib.h"

void *operator new(size_t size) { return malloc(size); }

void *operator new[](size_t size) { return malloc(size); }

void operator delete(void *p) {
  if (p != NULL) {
    free(p);
  }
}

void operator delete[](void *p) {
  if (p != NULL) {
    free(p);
  }
}

void operator delete(void *p, size_t UNUSED(size)) {
  if (p != NULL) {
    free(p);
  }
}

void operator delete[](void *p, size_t UNUSED(size)) {
  if (p != NULL) {
    free(p);
  }
}
