#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include"标头.h" //头文件的包含->相当于进行了函数的声明
#include<stddef.h>
#define MY_OFFSET0F(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)
struct stu
{
	char c;
	int i;
	double d;
};
int main()
{
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	printf("%d\n", sum);
	printf("%d\n", offsetof(struct stu, c));
	printf("%d\n", offsetof(struct stu, i));
	printf("%d\n", offsetof(struct stu, d));	
	printf("%d\n", MY_OFFSET0F(struct stu, c));
	printf("%d\n", &(((struct stu*)0)->c));
	printf("%d\n", MY_OFFSET0F(struct stu, i));
	printf("%d\n", MY_OFFSET0F(struct stu, d));
	return 0;
}
//#include<stdio.h>应用于c语言提供的库函数的头文件，如果使用<>,查找是直接去库目录下寻找
//#include"标头.h" 应用于自定义的头文件，如果使用"",查找去当前工程的目录下查找，如果找不到，再去库目录下查找
//当前目录 : D : \visua stdio 2013代码\预处理符号、预处理指令详解6文件包含\预处理符号、预处理指令详解6文件包含
//
//	每个头文件的开头写：
//#ifndef __TEST_H__ 
//#define __TEST_H__ 
//	头文件的内容
//#endif //__TEST_H__ 
//   或者：
//#pragma once 
//	就可以避免头文件的重复引入。