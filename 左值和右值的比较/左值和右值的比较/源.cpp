#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

int main()
{
	int x = 1;
	int y = 2;

	//��ֵ���õĶ���
	int a = 0;
	int &b = a;

	//��ֵ���ò���������ֵ����const��ֵ���ÿ���
	//int& e = 10;
	//int& f = x + y;
	const int& e = 10;
	const int& f = x + y;

	//��ֵ���õĶ���
	int&& c = 10;
	int&& d = x + y;

	//��ֵ���ò���������ֵ�����ǿ�������move����ֵ
	//int&& m = a;
	int&& m = move(a);


	return 0;
}
