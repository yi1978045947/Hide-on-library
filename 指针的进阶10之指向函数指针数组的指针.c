#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	//����ָ��
	int(*p)(int, int);
	//����ָ������
	int(*pArr[4])(int, int);
	//ppArr��ָ����ָ�������ָ��,ָ��pArr������飬�����ÿ��Ԫ�ض����Ǻ���ָ��
	int(*(*ppArr)[4])(int, int) = &pArr;
	return 0;
}