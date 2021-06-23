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
	double d = 20.0;
	//ÏÔÊ¾ÊµÀý»¯
	//std::cout << Add<int>(a, d) << std::endl;
	std::cout << Add<double>(a, d) << std::endl;


	//std::cout << Add<int>(1, "123") << std::endl;
	return 0;
}