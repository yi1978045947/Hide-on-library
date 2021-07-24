#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
class Student :public Person
{
public:
	virtual ~Student()   //不加virtual也构成重写
	{
		cout << "~Student()" << endl;
	}
};
int main()
{
	Person* p1 = new Person;
	delete p1;

	Person* p2 = new Student;
	delete p2;
	return 0;
}