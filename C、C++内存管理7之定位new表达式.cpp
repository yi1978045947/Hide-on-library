#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};
int main()
{
	// A* p = (A*)malloc(sizeof(A));

	// 等价于直接用A* p = new A
	A* p = (A*)operator new(sizeof(A));
	new(p)A; // new(p)A(3);  // 定位new，placement-new，显示调用构造函数初始化这块对象空间

	// 等于 delete p
	p->~A(); // 析构函数可以显示调用
	operator delete(p);

	return 0;
}

