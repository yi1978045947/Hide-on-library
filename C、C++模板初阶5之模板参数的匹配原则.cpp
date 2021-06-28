#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}
// 通用加法函数
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	std::cout << Add(1, 2) << std::endl;       // 与非模板函数匹配，编译器不需要特化
	std::cout << Add<int>(1, 2) << std::endl; // 调用编译器特化的Add版本
}
int main()
{
	Test();
	return 0;
}

