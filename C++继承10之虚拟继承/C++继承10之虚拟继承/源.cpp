#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	string _name; //姓名
};
class Student : virtual public Person
{
protected:
	int _num;    //学号
};
class Teacher : virtual public Person
{
protected:
	int _id;     //编号
};
class Assistant :public Student, public Teacher
{
protected:
	string _majorCourse; //主修课程
};
int main()
{
	Assistant a;
	//这里会有二义性无法明确访问的是哪一个类中的name
	//a._name = "哈士奇";

	//显示指定访问解决二义性的问题
	a.Student::_name = "阿拉";
	a.Teacher::_name = "哈士";
	return 0;
}