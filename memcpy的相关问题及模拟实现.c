#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//int main() �ڴ溯���Ŀ���memcpy
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int arr2[32] = { 0 };
//	memcpy(arr2, arr1, 20);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}

void* my_memcpy(void* arr2, const void* arr1, int count) //memcpy��ģ��ʵ��
{
	void* ret = arr2;
	assert(arr1&&arr2);
	while (count--)
	{
		*(char*)arr2 = *(char*)arr1;
		((char*)arr2)++;
		((char*)arr1)++; //++���ȼ�����
	}
	return ret;
}
int main()
{
	int arr1[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr2[32] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1[0]) * 5);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	return 0;
}
//����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
//������������� '\0' ��ʱ�򲢲���ͣ������
//���source��destination���κε��ص������ƵĽ������δ����ġ�