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
	Person p = s;    //������Ķ�����Ը�ֵ������Ķ���
	Person* pp = &s; //������ĵ�ַ���Ը�ֵ�������ָ��
	Person& rp = s; //������Ķ�����Ը�ֵ�����������

	s = p;         //����Ķ����ܸ�ֵ�����������

	pp = &s;
	Student* ss = (Student*)pp;  //�����ָ�����ͨ��ǿ������ת����ֵ���������ָ�룬������ڷ���Խ������
}
int main()
{
	Test();
	return 0;
}