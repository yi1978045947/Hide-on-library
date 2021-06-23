#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
//如何实现一个通用的交换函数呢？
void swap(int& left, int &right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
void swap(double& left, double& right)
{
	double tmp = left;
	left = right;
	right = tmp;
}
void swap(char& left, char& right)
{
	char tmp = left;
	left = right;
	right = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	swap(a, b);
	std::cout << a << " "<< b << std::endl;
	int c = 1.0;
	int d = 2.0;
	swap(c, d);
	std::cout << c << " "<< d << std::endl;
	char e = 'a';
	char f = 'b';
	swap(e, f);
	std::cout << e << " " << f << std::endl;
	return 0;
}
//使用函数重载虽然可以实现，但是有一下几个不好的地方：
//1. 重载的函数仅仅只是类型不同，代码的复用率比较低，只要有新类型出现时，就需要增加对应的函数
//2. 代码的可维护性比较低，一个出错可能所有的重载均出错