#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

//��������:�Ǻ�����һ�����������C++������ͬһ�����������������������Ƶ�ͬ��������
//��Щͬ���������β��б�(�������� �� ���� �� ˳��)���벻ͬ��
//����������ʵ�ֹ��������������Ͳ�ͬ������

//ȱʡ�����������أ������õ�ʱ���������ʶ�������ص����ĸ�����
void fun(int a, int b, int c = 10)
{

}
void fun(int a, int b)
{

}

int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}

int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(10.5, 20.0) << endl;
	//fun();
	return 0;
}