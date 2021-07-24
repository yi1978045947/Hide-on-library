#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-Êæ·þ" << endl;
	}
};
class BMW:public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-²Ù×÷" << endl;
	}
};
int main()
{
	Car* p = new Benz;
	p->Drive();

	Car* b = new BMW;
	b->Drive();

	Car c;

	Benz b;

	BMW bb;
	return 0;
}