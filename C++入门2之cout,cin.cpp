#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
//cout���ڻ�������������������ס����ʹ��
//ostream ����ȫ�ֶ��� cout
//istream ����ȫ�ֶ��� cin
//endl    ȫ�ֵĻ��з���

struct Person
{
	char name[10];
	int age;
};
int main()
{
	std::cout << "bit education ";
	std::cout << "bit education" << std::endl;
	//cout��cin�Ա�C����printf\scanf ��˵�����Զ�ʶ������(��������+���������)
	int a = 10;
	int* p = &a;
	printf("%d,%p\n", a, p);
	std::cout << a << "," << p << std::endl;
	std::cin >> a;
	printf("%d\n", a);
	char str[100];
	std::cin >> str;  //cin����&,��Ϊ����
	std::cout << str << std::endl;

	struct Person P = { "uzi", 23 };  //��ʽ�����printf��cout��
	printf("name:%s age:%d\n", P.name, P.age);
	std::cout << "name:" << P.name<<" age:"<< P.age << "\n";
}