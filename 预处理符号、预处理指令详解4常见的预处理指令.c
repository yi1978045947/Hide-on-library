#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#define MAX 100
int main()
{
	printf("%d\n", MAX);
    #undef MAX
	//printf("%d\n", MAX);
	return 0;
}

�����ж���
���C �ı������ṩ��һ���������������������ж�����š���������������̡� ���磺�����Ǹ���ͬһ��Դ�ļ�Ҫ
�������ͬ��һ������Ĳ�ͬ�汾��ʱ����������е��ô������ٶ�ĳ��������������һ��ĳ�����ȵ����飬���
�����ڴ����ޣ�������Ҫһ����С�����飬��������һ�������ڴ��д��������Ҫһ�������ܹ���д����
gcc - D ARRAY_SIZE = 10 programe.c
int main()
{
	int arr[sz] = { 0 };
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		arr[i] = i;
	}
	for (i = 0; i<sz; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
