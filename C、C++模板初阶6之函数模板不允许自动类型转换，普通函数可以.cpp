#define _CRT_SECURE_NO_WARNINGS   1
#include <iostream>
template<typename T>
T Add1(const T& x, const T& y)
{
	return x + y;
}
int Add2(int a, double b)
{
	return a + b;
}
int main()
{
	int a = Add1(1, 1.1); //模板函数不允许自动类型转换
	int b = Add2(1, 1.1);
	return 0;
}
