#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//�����ɹ��캯�������ǿ������������
//int n=0;  ȫ�ֵ�˭�������޸�
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
	static int GetN()           //�õ��������
	{
		return n;
	}
private:
	static int n;   //��̬��Ա������������������ĳ������������������ж�����������࣬���������ⶨ��
	                //n���ڶ����У�n���ھ�̬��
};

int A::n = 0;      //��̬��Ա�����Ķ���
//A& f1(A& a)
A f1(A a)
{
	return a;
}
int main()
{
	//cout << A::n << endl;   ���еĲ��ܷ���
	//n = 1;  �������Ϊȫ�ֵ�ÿ���˶�������ȥ�޸�
	cout << A::GetN() << endl;
	A a1;
	A a2;
	f1(a1);
	f1(a2);
	//cout << A::n << endl;   ���еĲ��ܷ���
	cout << a1.GetN() << endl;
	cout << a2.GetN() << endl;
	cout << A::GetN() << endl;
	return 0;
}