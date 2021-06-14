#define _CRT_SECURE_NO_WARNINGS   1
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	static int _n; 
//};
//// 静态成员变量的定义初始化
//int A::_n = 10;
//int main()
//{
//	A a;
//	//静态成员，不属于某个对象，突破类域就能访问
//	cout << a._n << endl;   //公有1.通过类对象突破类域进行访问
//	cout << A()._n << endl; //公有2.通过匿名对象突破类域进行访问
//	cout << A::_n << endl;  //公有3.通过类名突破类域进行访问
//	return 0;
//}

#include <iostream>
using namespace std;
class A
{
public:
	static int GetN()
	{
		return _n;
	}
private:
	static int _n;
};
// 静态成员变量的定义初始化
int A::_n = 10;
int main()
{
	A a;
	cout << a.GetN() << endl;   //1.通过实例化的对象调用成员函数进行访问
	cout << A().GetN() << endl; //2.通过匿名对象调用成员函数进行访问
	cout << A::GetN() << endl;  //3.通过类名调用静态成员函数进行访问
	return 0;
}

