#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	string _name; //����
};
class Student : virtual public Person
{
protected:
	int _num;    //ѧ��
};
class Teacher : virtual public Person
{
protected:
	int _id;     //���
};
class Assistant :public Student, public Teacher
{
protected:
	string _majorCourse; //���޿γ�
};
int main()
{
	Assistant a;
	//������ж������޷���ȷ���ʵ�����һ�����е�name
	//a._name = "��ʿ��";

	//��ʾָ�����ʽ�������Ե�����
	a.Student::_name = "����";
	a.Teacher::_name = "��ʿ";
	return 0;
}