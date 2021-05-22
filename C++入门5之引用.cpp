#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
void TestConstRef()
{
	//常引用是创建一个临时变量，引用名是临时变量的引用
	const int a = 10;
	//int& ra = a; // 该语句编译时会出错，a为常量
	const int& ra = a;
	// int& b = 10; // 该语句编译时会出错，b为常量
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // 该语句编译时会出错，类型不同
	const int& rd = d;
}
void Swap2(int& a, int& b) //通过引用来交换
{
	int tmp = a;
	a = b;
	b = tmp;
}
void Swap1(int* a, int *b) //通过指针来交换
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int x = 10;
	int &y = x;
	y = 20;
	std::cout << "y=" << y << std::endl;
	int &z = y;
	z = 30;
	std::cout << "z=" << z << std::endl;

	int a = 10;
	int b = 20;
	Swap1(&a, &b);
	std::cout << a << std::endl << b << std::endl;
	Swap2(a, b);
	std::cout << a << std::endl << b << std::endl;
	return 0;
}