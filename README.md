# This is a mini CRT 
来自程序员的自我修养——链接、装载与库

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

## 使用方法

### 编译源文件
#### Linux

	gcc -c -fno-builtin -nostdlib -fno-stack-protector entry.c malloc.c stdio.c string.c format.c 

	ar -rs minicrt.a malloc.o format.o stdio.o string.o
	
#### Windows

	>cl /c /DWIN32 /GS- entry.c malloc.c stdio.c string.c format.c
	>lib entry.obj malloc.obj stdio.obj string.obj format.obj /OUT:minicrt.lib
	
### 测试代码
#### Linux

	gcc -c -ggdb -fno-builtin -nostdlib -fno-stack-protector test.c
	ld -static -e _mini_crt_entry entry.o test.o minicrt.a -o test
	
	//ld -static -e mini_crt_entry entry.o test.o minicrt.a -o test有问题
	//	mini_crt_entry	_mini_crt_entry
	
	
	
	
	
	
	
	