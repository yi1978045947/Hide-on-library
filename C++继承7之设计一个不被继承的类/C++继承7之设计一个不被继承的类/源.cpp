#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class A
{
private:
	A()
	{}
	~A()
	{

	}
};
class B :public A
{

};
int main()
{
	B b;
	return 0;
}