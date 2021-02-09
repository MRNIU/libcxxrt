# MiniCRT

来自 程序员的自我修养——链接、装载与库

简单 C 运行时库实现
Simple C run time lib

## 支持 Suport

```C
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
```


## 使用方法 Usage

```shell
git clone https://github.com/MRNIU/MiniCRT.git
cd MiniCRT
mkdir build
cmake ..
make
```

构建完成后，库文件保存在 build/lib/libminicrt.a
测试程序为 build/bin/test


## TODO

C++ run time