#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};
class Student :public Person
{
	virtual void BuyTicket()  //�������virtual�ؼ���Ҳ���Բ���дҲ������д
	{
		cout << "��Ʊ-���" << endl;
	}
};
void Func1(Person& p)
{
	p.BuyTicket();
}
void Func2(Person* p)
{
	p->BuyTicket();
}
int main()
{
	Person p;
	Student s;

	//������
	Func1(p);
	Func1(s);

	//������ĵ�ַ
	Func2(&p); 
	Func2(&s);
	return 0;
}