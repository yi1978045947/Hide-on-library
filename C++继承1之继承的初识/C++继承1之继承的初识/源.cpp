#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	void print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
private:
	string _name = "张三";
	int _age = 20;
};
class Student:public Person
{
protected:
	int _stuid;//学号
};
class Teacher :public Person
{
protected:
	int _jobid;//工号
};
int main()
{
	Student s;
	s.print();
	Teacher t;
	t.print();

	return 0;
}