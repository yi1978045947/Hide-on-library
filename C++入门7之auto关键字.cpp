#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
int main()
{
	int x = 10;
	auto a = &x;  // int* 
	auto* b = &x; // int*
	int& y = x;   // y��������ʲô��int
	auto c = y;  // int 
	auto& d = x; // d��������int�� ��������ָ����d��x������

	// ��ӡ����������
	cout << typeid(x).name() << endl;
	cout << typeid(y).name() << endl;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	return 0;
}