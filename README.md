
# MiniCRT

来自 程序员的自我修养——链接、装载与库

## 以 ANIS C 的标准库为目标，尽量做到与其接口一致

### 入口函数 mini_crt_entry
### 进程相关操作 exit
### 堆操作 malloc、free
### 基本的文件操作 fopen、fread、fwrite、fclose、fseek
### 基本的字符串操作 strcpy、strlen、strcmp
### 格式化字符串和输出操作 printf、sprintf
### 支持 atexit() 函数
### 同时支持 Linux 和 Windows
### 仅包含基本实现，尽量简单

## 使用方法 Usage

```shell
git clone https://github.com/MRNIU/MiniCRT.git
cd MiniCRT
mkdir build
cmake ..
```

	构建完成后，库文件保存在 build/lib/libminicrt.a
	测试程序为 build/bin/test

## TODO

C++ Run Time
