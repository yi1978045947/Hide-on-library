#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class Car
{
public:
	virtual void Drive() final
	{}
};
class Benz :public Car
{
	virtual void Drive()
	{
		cout << "Benz-Êæ·þ" << endl;
	}
};
int main()
{
	Car c;
	Benz b;
	c.Drive();
	//b.Drive();
	return 0;
}