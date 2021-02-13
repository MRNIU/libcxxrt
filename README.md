# MiniCRT

来自 程序员的自我修养——链接、装载与库

简单 C/C++ 运行时库实现
Simple C/C++ run time lib

## 支持 Support

|         | X86  | X64  | ARM  | AARCH64 |
| :-----: | :--: | :--: | :--: | :-----: |
|  WIN10  |    |      |      |         |
|   OSX   |  N/A  |  ✅  |      |         |
| Manjaro |     |  ✅  |      |         |
| Ubuntu  |     | ✅ |      |         |



```c++
// io
FILE *  fopen(const char *filename, const char *mode);
int64_t fread(void *buffer, uint64_t size, uint64_t count, FILE *stream);
int64_t fwrite(const void *buffer, uint64_t size, uint64_t count, FILE *stream);
int64_t fclose(FILE *fp);
int64_t fseek(FILE *fp, uint64_t offest, int set);
int fputc(int c, FILE *stream);
int fputs(const char *str, FILE *stream);
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
// string
int8_t   strcmp(const char *src, const char *dst);
char *   strcpy(char *dest, const char *src);
uint64_t strlen(const char *str);
void     memset(void *dest, uint8_t val, uint32_t len);
void     bzero(void *dest, uint32_t len);
// stdlib
void  free(void *ptr);
void *malloc(size_t size);
char *itoa(int n, char *str, int radix);
int atexit(atexit_func_t func);
// iostream
// ofstream
class ofstream {
private:
protected:
    FILE *fp;
    ofstream(const ofstream &lhs);

public:
    enum openmode : uint8_t {
        in     = 1,
        out    = 2,
        binary = 4,
        trunc  = 8,
    };
    ofstream(void);
    explicit ofstream(const char *       filename,
                      ofstream::openmode md = ofstream::out);
    ~ofstream(void);
    ofstream &operator<<(char c);
    ofstream &operator<<(int n);
    ofstream &operator<<(const char *lhs);
    ofstream &operator<<(ofstream &(*)(ofstream &));

    void open(const char *filename, ofstream::openmode md = ofstream::out);
    void close(void);
    ofstream &write(const char *buf, unsigned size);
};

// string
class string {
private:
    size_t len;
    char * pbuf;

protected:
public:
    explicit string(const char *str);
    string(const string &s);
    ~string(void);
    string &    operator=(const string &s);
    string &    operator=(const char *s);
    const char &operator[](size_t idx) const;
    char &      operator[](size_t idx);
    const char *c_str(void) const;
    size_t      length(void) const;
    size_t      size(void) const;
};
```


## 使用方法 Usage

```shell
git clone https://github.com/MRNIU/MiniCRT.git
cd MiniCRT
mkdir build
# ARCH: 32, 64
# CMAKE_BUILD_TYPE: DEBUG, RELEASE
cmake -DARCH=64 -DCMAKE_BUILD_TYPE=RELEASE ..
make
```

构建完成后，库文件保存在 build/lib/libminicrt.a
测试程序为 build/bin/test

## TODO

多平台适配

