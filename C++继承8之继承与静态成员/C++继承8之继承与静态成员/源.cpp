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
	string _name; //����
public:
	static int _count;//����
};
int Person::_count = 0;  //��̬��Ա�������ʼ��
class Student :public Person
{
protected:
	int _stuNum; //ѧ��
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