#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
	string _name = "��Ʈ";  //����
	int _num = 111;         //���֤��
};
class Student :public Person
{
public:
	void print()
	{
		cout << "����:" << _name << endl;
		cout << "���֤��:" << Person::_num << endl;
		cout << "ѧ��:" << _num << endl;
	}
protected:
	int _num = 999;//ѧ��
};
int main()
{
	Student s1;
	s1.print();
	return 0;
}