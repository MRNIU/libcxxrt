
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// string.cpp for MRNIU/MiniCRT.

#include "stdint.h"
#include "string.h"
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
        len  = s.len;
        pbuf = strcpy(new char[len + 1], s.pbuf);
        return *this;
    }

    string &string::operator=(const char *s) {
        this->~string();
        len  = strlen(s);
        pbuf = strcpy(new char[len + 1], s);
        return *this;
    }

    const char &string::operator[](size_t idx) const {
        return pbuf[idx];
    }

    char &string::operator[](size_t idx) {
        return pbuf[idx];
    }

    const char *string::c_str(void) const {
        return pbuf;
    }

    size_t string::length(void) const {
        return len;
    }

    size_t string::size(void) const {
        return len;
    }

    ofstream &operator<<(ofstream &o, const string &s) {
        return o << s.c_str();
    }
};
