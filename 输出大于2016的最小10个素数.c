#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int index = 0;  //�����±�
	int arr[10]; //����Ϊ10����
	int n = 0;   //��Ҫ�����ֵ
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 2016; i < n; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d ", arr[index++] = j); //�ŵ���������
		}
		if (index == 10)                //����Ԫ��Ϊ10����ô�˳�����
		{
			break;
		}
	}
	printf("\n");
	return 0;
}