#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
	string _name = "阿飘";  //姓名
	int _num = 111;         //身份证号
};
class Student :public Person
{
public:
	void print()
	{
		cout << "姓名:" << _name << endl;
		cout << "身份证号:" << Person::_num << endl;
		cout << "学号:" << _num << endl;
	}
protected:
	int _num = 999;//学号
};
int main()
{
	Student s1;
	s1.print();
	return 0;
}