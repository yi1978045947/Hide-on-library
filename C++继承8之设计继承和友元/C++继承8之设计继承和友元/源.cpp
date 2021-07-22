#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Student;
class Person
{
	friend void Display(const Person& p, const Student& s);
protected:
	string _name = "¹þÊ¿Ææ"; //ÐÕÃû
};
class Student:public Person
{
protected:
	int _num; // Ñ§ºÅ
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._num << endl;
}
int main()
{
	Person p;
	Student s;
	Display(p, s);
	return 0;
}
