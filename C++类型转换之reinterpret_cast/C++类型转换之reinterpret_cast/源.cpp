#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

int main()
{
	int i = 1;
	int* p = nullptr;
	p = (int*)i;
	cout << p << endl;

	p = reinterpret_cast<int*>(i);
	cout << p << endl;
	return 0;
}