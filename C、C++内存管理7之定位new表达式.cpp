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

	// �ȼ���ֱ����A* p = new A
	A* p = (A*)operator new(sizeof(A));
	new(p)A; // new(p)A(3);  // ��λnew��placement-new����ʾ���ù��캯����ʼ��������ռ�

	// ���� delete p
	p->~A(); // ��������������ʾ����
	operator delete(p);

	return 0;
}

