#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//class Person
//{
//public:
//	virtual Person& BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		return *this;
//	}
//};
//class Student :public Person
//{
//	virtual Student& BuyTicket()  //派生类的virtual关键字也可以不用写也构成重写
//	{
//		cout << "买票-半价" << endl;
//		return *this;
//	}
//};
class Person
{
public:
	virtual Person* BuyTicket()
	{
		cout << "买票-全价" << endl;
		return 0;
	}
};
class Student :public Person
{
	virtual Student* BuyTicket()  //派生类的virtual关键字也可以不用写也构成重写
	{
		cout << "买票-半价" << endl;
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

	//传对象
	Func1(p);
	Func1(s);

	//传对象的地址
	Func2(&p);
	Func2(&s);
	return 0;
}