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
	//���������paָ����,�����������?
	//���paָ������������,��ת���ɹ�
	//���paָ����Ǹ��������ת��ʧ�ܣ�����nullptr
	B* pb = dynamic_cast<B*>(pa);
	//B* pb=(B*)pa;   C�����е�ǿ������ת������
	if (pb != nullptr)
	{
		cout << "ת���ɹ�:paָ���������!" << endl;
		pb->_a = 1;
		pb->_b = 2;
		
	}
	else
	{
		cout << "ת��ʧ��:paָ�������!" << endl;
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
