#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
int Add2(int left, int right)
{
	return left + right;
}
inline int Add1(int left, int right)
{
	return left + right;
}
int main()
{
	int ret1, ret2;
	ret1 = Add1(1, 2);
	ret2 = Add1(1, 2);
	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
	return 0;
}