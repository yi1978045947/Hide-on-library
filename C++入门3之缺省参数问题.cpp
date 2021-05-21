#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//缺省参数是声明或定义函数时为函数的参数指定一个默认值。 
//在调用该函数时，如果没有指定实参则采用该
//默认值，否则使用指定的实参

//半缺省参数
void testFunc3(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//全缺省参数
void testFunc2(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

void testFunc1(int a = 0)
{
	std::cout << a << std::endl;
}

int main()
{
	testFunc1(10);
	testFunc2();
	testFunc3(1);
	return 0;
}

//1.半缺省参数必须从右往左依次来给出，不能间隔着给
//2.缺省参数不能在函数声明和定义中同时出现
//3.缺省值必须是常量或者全局变量
//4.C语言不支持（编译器不支持