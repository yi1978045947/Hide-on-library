#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//对象由构造函数或者是拷贝构造产生的
//int n=0;  全局的谁都可以修改
class A
{
public:
	A()
	{
		n++;
	}
	A(const A& a)
	{
		n++;
	}
	static int GetN()           //拿到这个对象
	{
		return n;
	}
private:
	static int n;   //静态成员变量的声明，不属于某个对象，是属于类的所有对象，属于这个类，所以在类外定义
	                //n不在对象中，n属于静态区
};

int A::n = 0;      //静态成员变量的定义
//A& f1(A& a)
A f1(A a)
{
	return a;
}
int main()
{
	//cout << A::n << endl;   公有的才能访问
	//n = 1;  如果定义为全局的每个人都都可以去修改
	cout << A::GetN() << endl;
	A a1;
	A a2;
	f1(a1);
	f1(a2);
	//cout << A::n << endl;   公有的才能访问
	cout << a1.GetN() << endl;
	cout << a2.GetN() << endl;
	cout << A::GetN() << endl;
	return 0;
}