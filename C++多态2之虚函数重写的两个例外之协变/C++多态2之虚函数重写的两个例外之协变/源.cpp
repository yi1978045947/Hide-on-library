#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//class Person
//{
//public:
//	virtual Person& BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//		return *this;
//	}
//};
//class Student :public Person
//{
//	virtual Student& BuyTicket()  //�������virtual�ؼ���Ҳ���Բ���дҲ������д
//	{
//		cout << "��Ʊ-���" << endl;
//		return *this;
//	}
//};
class Person
{
public:
	virtual Person* BuyTicket()
	{
		cout << "��Ʊ-ȫ��" << endl;
		return 0;
	}
};
class Student :public Person
{
	virtual Student* BuyTicket()  //�������virtual�ؼ���Ҳ���Բ���дҲ������д
	{
		cout << "��Ʊ-���" << endl;
		return 0;
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