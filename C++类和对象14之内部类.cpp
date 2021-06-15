#define _CRT_SECURE_NO_WARNINGS   1
#include <iostream>
using namespace std;
class A
{
private:
	static int k;
	int h=5;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 10;
int main()
{
	A::B b;
	b.foo(A());
	return 0;
}


