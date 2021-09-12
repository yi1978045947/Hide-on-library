#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
void test()
{
	int i = 1;
	//隐士类型转换
	double d = 8.88;
	i = d;
	cout << i << " " << d << endl;

	int* p = &i;
	int address = (int)p;
	cout << p << " " << address << endl;
}
int main()
{
	test();
	return 0;
}