#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//条件编译:满足某种条件时就参与编译，不满足条件时就不参与编译
#define __DEBUG__ 1
#define PRINT 1
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
#ifdef  __DEBUG__
		printf("bit education\n");
#endif
	}

#ifdef PRINT    //正面
	printf("哈哈\n");
#endif
#ifndef PRINT  //反面
	printf("哈哈啊\n");
#endif

#if defined PRINT    //正面
	printf("bit\n");
#endif
#if !defined PRINT  //反面
	printf("bit啊\n");
#endif

#if 5-3
	printf("bit NB\n");
#elif 5-5
	printf("bit CA\n");
#elif
	printf("呵呵\n");
#endif
	return 0;
}

//常见的条件编译指令：

//1.
//#if 常量表达式
////... 
//#endif //常量表达式由预处理器求值。
//如：
//#define __DEBUG__ 1 
//#if __DEBUG__ 
////.. 
//#endif 

//2.多个分支的条件编译
//#if 常量表达式
////... 
//#elif 常量表达式
////... 
//#else 
////... 
//#endif 

//3.判断是否被定义
//#if defined(symbol) 
//#ifdef symbol 
//#if !defined(symbol) 
//#ifndef symbol 

//4.嵌套指令
//#if defined(OS_UNIX) 
//#ifdef OPTION1 
//unix_version_option1();
//#endif 
//#ifdef OPTION2 
//unix_version_option2();
//#endif 
//#elif defined(OS_MSDOS) 
//#ifdef OPTION2 
//msdos_version_option2();
//#endif 
//#endif