#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Person
{
protected:
	string _name;
	string _sex;
	int _age;
};
class Student :public Person
{
public:
	int _No;
};
void Test()
{
	Student s;
	Person p = s;    //派生类的对象可以赋值给基类的对象
	Person* pp = &s; //派生类的地址可以赋值给基类的指针
	Person& rp = s; //派生类的对象可以赋值给基类的引用

	s = p;         //基类的对象不能赋值给派生类对象

	pp = &s;
	Student* ss = (Student*)pp;  //基类的指针可以通过强制类型转换赋值给派生类的指针，但会存在访问越界问题
}
int main()
{
	Test();
	return 0;
}