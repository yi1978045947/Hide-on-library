#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
void f()
{
	// �����÷���malloc��free����ȫһ���ģ����ܶ����ڶ��������ͷſռ�
	// ʧ���˴���ʽ��һ����mallocʧ�ܷ���NULL��operator newʧ���Ժ����쳣
	void* p3 = malloc(0x7fffffff);
	if (p3 == NULL)
	{
		cout << "malloc fail" << endl;
	}
	void* p4 = operator new(11);
	char* p5 = new char[0x7fffffff];
	cout << "����" << endl;
}
int main()
{
	try
	{
		f();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

