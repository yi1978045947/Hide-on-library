#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

int main()
{
	int x = 1;
	int y = 2;

	//左值引用的定义
	int a = 0;
	int &b = a;

	//左值引用不能引用右值，但const左值引用可以
	//int& e = 10;
	//int& f = x + y;
	const int& e = 10;
	const int& f = x + y;

	//右值引用的定义
	int&& c = 10;
	int&& d = x + y;

	//右值引用不能引用左值，但是可以引用move后左值
	//int&& m = a;
	int&& m = move(a);


	return 0;
}
