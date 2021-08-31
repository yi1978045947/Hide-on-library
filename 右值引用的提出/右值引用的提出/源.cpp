#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

void Swap(int& left, int & right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
int add(int a, int b)
{
	return a + b;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);

	const int&& ra = 10;

	// 引用函数返回值，返回值是一个临时变量，为右值
	int&& rRet = add(10, 20);

	return 0;
}