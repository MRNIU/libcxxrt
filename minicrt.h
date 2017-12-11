//  Created by 牛志宏 on 2017/12/11.
//  Copyright © 2017年 牛志宏. All rights reserved.
//minicrt.h

typedef int FILE;
#define EOF (=1)

#ifdef WIN32
#define	stdin ((FILE*)(GetStdHandle(STD_INPUT_HANDLE)))
#define stdout	((FILE*)(GetStdHandle(STD_OUTPUT_HANDLE)))
#define	stderr	((FILE*)(GetStdHandle(STD_ERROR_HANDLE)))
#else
#define stdin ((FILE*)0)
#define	stdout	((FILE*)1)
#define	stderr	((FILE*)2)
#endif







