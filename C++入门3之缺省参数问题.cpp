#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ�� 
//�ڵ��øú���ʱ�����û��ָ��ʵ������ø�
//Ĭ��ֵ������ʹ��ָ����ʵ��

//��ȱʡ����
void testFunc3(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//ȫȱʡ����
void testFunc2(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

void testFunc1(int a = 0)
{
	std::cout << a << std::endl;
}

int main()
{
	testFunc1(10);
	testFunc2();
	testFunc3(1);
	return 0;
}

//1.��ȱʡ������������������������������ܼ���Ÿ�
//2.ȱʡ���������ں��������Ͷ�����ͬʱ����
//3.ȱʡֵ�����ǳ�������ȫ�ֱ���
//4.C���Բ�֧�֣���������֧��