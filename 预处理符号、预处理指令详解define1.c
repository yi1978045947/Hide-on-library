#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>

int main()  //预处理(定义)符号
{
int i = 0;
for (i = 0; i < 10; i++)
{
printf("file:%s line=%d data=%s time=%s function=%s i=%d\n", __FILE__,__LINE__ ,__DATE__,__TIME__,__FUNCTION__,i);
}
return 0;
}

/*
__FILE__      //进行编译的源文件
__LINE__     //文件当前的行号
__DATE__    //文件被编译的日期
__TIME__    //文件被编译的时间
__FUNCTIO__ // 文件被执行的函数
__STDC__    //如果编译器遵循ANSI C，其值为1，否则未定义
*/

/*
预处理指令包括
#define
#include
#if
#ifdef
*/

// #define 定义标识符

#define MAX 100
#define STR "bit education"
#define reg register
#define print printf("bit education\n")
int main() //预处理指令
{
reg int age;
printf("%d\n", MAX);
printf("%s\n", STR);
print;
return 0;
}


//#define 定义宏 ,#define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏（macro）或定义宏（definemacro）
#define SQUARE(X) X*X

//#define SQUARE(X) (X)*(X)

//定义中我们使用了括号，想避免之前的问题，但是这个宏可能会出现新的错误。所以使用宏时候不要省括号
#define DOUBLE(X) (X)+(X)
int main()
{
	printf("%d\n", SQUARE(3));
	printf("%d\n", 3 * 3);
	printf("%d\n", SQUARE(3 + 2)); //11
	printf("%d\n", 3 + 2 * 3 + 2);
	//printf("%d\n", SQUARE(3 + 2)); //25
	printf("%d\n", 2 * DOUBLE(5));
	printf("%d\n", 2 * 5 + 5);
	return 0;
}

#define 替换规则
在程序中扩展#define定义符号和宏时，需要涉及几个步骤。
1. 在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，它们首先被替换。
2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
3. 最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述处理过程。
注意：
1. 宏参数和#define定义中可以出现其他#define定义的变量。但是对于宏，不能出现递归。
2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。