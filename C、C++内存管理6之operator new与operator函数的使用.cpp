#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
int main()
{
	//�������ַ�ʽ���ٿռ���ͷſռ��Ч����һ����
	int* p1 = (int*)malloc(sizeof(int));      //malloc��free
	free(p1);

	int* p2 = new int;                        //new��delete
	delete p2;

	int* p3 = (int*)operator new(sizeof(int));//operator new��operator delete
	operator delete (p3);
	return 0;
}