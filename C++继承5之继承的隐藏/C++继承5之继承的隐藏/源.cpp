#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B :public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)" << endl;
	}
};
int main()
{
	B b;
	b.fun(10);
	return 0;
}