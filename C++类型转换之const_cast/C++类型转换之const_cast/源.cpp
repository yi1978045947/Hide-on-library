#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
int main()
{
	const int a = 10;
	int* p = const_cast<int*>(&a);
	*p = 20;
	cout << a << endl;
	cout << *p << endl;
	return 0;
}