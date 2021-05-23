#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	// 范围for C++11新语法遍历，更简单，数组都可以
	// 自动遍历，依次取出array中的元素，赋值给e，直到结束
	for (auto& e : array)
	{
		e *= 2;
	}
	for (auto ee : array)
	{
		cout << ee << " ";
	}
	cout << endl;
	return 0;
}