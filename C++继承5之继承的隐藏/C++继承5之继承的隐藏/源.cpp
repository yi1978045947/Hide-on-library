#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
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