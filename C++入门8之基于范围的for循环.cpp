#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	// ��Χfor C++11���﷨���������򵥣����鶼����
	// �Զ�����������ȡ��array�е�Ԫ�أ���ֵ��e��ֱ������
	for (auto& e : array)
	{
		e *= 2;
	}
	for (auto ee : array)
	{
		cout << ee << " ";
	}
	cout << endl;
	return 0;
}