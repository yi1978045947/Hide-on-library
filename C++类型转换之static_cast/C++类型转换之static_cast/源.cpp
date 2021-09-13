#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

int main()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;
	return 0;
}