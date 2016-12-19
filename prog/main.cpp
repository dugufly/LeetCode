// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#ifdef __cplusplus    //__cplusplus是cpp中自定义的一个宏
extern "C" {          //告诉编译器，这部分代码按C语言的格式进行编译，而不是C++的
#endif
void entry_testALL();
#ifdef __cplusplus
}
#endif
int _tmain(int argc, _TCHAR* argv[])
{
	entry_testALL();
	return 0;
}

