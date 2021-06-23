#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a = 10;
	int b = 20;
	double c = 10.0;
	double d = 20.0;
	std::cout << Add(a, b) << std::endl;
	std::cout << Add(c, d) << std::endl;

	
	std::cout << Add(a, (int)c) << std::endl;
	return 0;
}