#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

//函数重载:是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，
//这些同名函数的形参列表(参数个数 或 类型 或 顺序)必须不同，
//常用来处理实现功能类似数据类型不同的问题

//缺省参数构成重载，但调用的时候编译器不识别函数重载调用哪个函数
void fun(int a, int b, int c = 10)
{

}
void fun(int a, int b)
{

}

int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}

int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(10.5, 20.0) << endl;
	//fun();
	return 0;
}