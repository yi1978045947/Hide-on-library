#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//class A
//{
//private:
//	double weight;
//	static double total_weight;
//	static double total_number;
//public:
//	A(double w)
//	{
//		weight = w;
//		total_weight += w;
//		total_number++;
//	}
//	void display()
//	{
//		cout << "货物的重量是:" << weight << "千克" << endl;
//	}
//	static void total_disp()
//	{
//		cout << total_number << "件货物的总重量是:" << total_weight << "千克" << endl;
//	}
//};
//double A::total_weight = 0;
//double A::total_number = 0;
//void main()
//{
//	A a1(2.5), a2(2.6);
//	a1.display();
//	a2.display();
//	A::total_disp();
//}

class B;
class A
{
private:
	int x;
public:
	A()
	{
		this->x = 0;
	}
	void display(B &v);
};
class B
{
private:
	int y;
	int z;
public:
	B();
	B(int, int);
	friend void A::display(B &);
};
void A::display(B &v)
{
	cout << "v.y=" << v.y << endl;
	cout << "v.z=" << v.z << endl;
	x = v.y + v.z;
	cout << "x=" << x << endl;
}
B::B()
{
	this->y = 0;
	this->z = 0;
}
B::B(int y, int z)
{
	this->y = y;
	this->z = z;
}
int main()
{
	A a;
	B b(2, 3);
	a.display(b);
	return 0;
}