#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

class A
{
public:
	virtual void f_cast(){}

	int _a;
};
class B :public A
{
public:
	int _b;
};
void f_cast(A* pa)
{
	//如果想区分pa指向父类,还是子类对象?
	//如果pa指向的是子类对象,则转换成功
	//如果pa指向的是父类对象，则转换失败，返回nullptr
	B* pb = dynamic_cast<B*>(pa);
	//B* pb=(B*)pa;   C语言中的强制类型转换不行
	if (pb != nullptr)
	{
		cout << "转换成功:pa指向子类对象!" << endl;
		pb->_a = 1;
		pb->_b = 2;
		
	}
	else
	{
		cout << "转换失败:pa指向父类对象!" << endl;
	}
}
int main()
{
	A a;

	A* pa = &a;

	B b;

	f_cast(pa);

	pa = &b;
	f_cast(pa);
	return 0;
}
