#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		_count++;
	}
	A(const A& a)
	{
		_count++;
	}

	static int GetCount()
	{
		return _count;
	}
private:
	static int _count;
};

class B
{
public:
	B()
	{
		_sum = _sum + _i;
	}
	static int GetSum()
	{
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};
int B::_i = 0;
int B::_sum = 0;

int A::_count = 0;
int main()
{
	cout << A::GetCount() << endl;
	cout << sizeof(A) << endl;
	A a1;
	A a3;
	A a2(a1);
	cout << A::GetCount() << endl;
	return 0;
}
