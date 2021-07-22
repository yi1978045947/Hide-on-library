#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person()
	{
		++_count;
	}
protected:
	string _name; //姓名
public:
	static int _count;//计数
};
int Person::_count = 0;  //静态成员在类外初始化
class Student :public Person
{
protected:
	int _stuNum; //学号
};
int main()
{
	Person p;
	Student s;
	
	Person::_count++;
	Student::_count++;
	cout << p._count << endl;
	cout << s._count << endl;
	return 0;
}