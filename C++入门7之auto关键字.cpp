#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
int main()
{
	int x = 10;
	auto a = &x;  // int* 
	auto* b = &x; // int*
	int& y = x;   // y的类型是什么？int
	auto c = y;  // int 
	auto& d = x; // d的类型是int， 但是这里指定了d是x的引用

	// 打印变量的类型
	cout << typeid(x).name() << endl;
	cout << typeid(y).name() << endl;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	return 0;
}