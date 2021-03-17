#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main() //memmove�ص������ڴ��
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	memmove(arr + 2, arr, 32);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//ʹ��memmoveӦ��ע��ĵط�
//1.���dest����src�����ʱ�򣬴�ǰ��󿽱�
//2.���dest����src���ұ�ʱ�򣬴Ӻ���ǰ����
//3.��memcpy�Ĳ�����memmove���������Դ�ڴ���Ŀ���ڴ���ǿ����ص��ġ�
//4.���Դ�ռ��Ŀ��ռ�����ص����͵�ʹ��memmove��������

void* my_memmove(void* arr1, const void* arr2, size_t count)
{
	void* ret = arr1;
	assert(arr1&&arr2);
	if (arr1 < arr2) //��ǰ��󿽱�
	{
		while (count--)
		{
			*(char*)arr1 = *(char*)arr2;
			((char*)arr1)++;
			((char*)arr2)++;
		}
	}
	else //�Ӻ���ǰ����
	{
		while (count--)
		{
			*((char*)arr1 + count) = *((char*)arr2 + count);  //����count��ʵ����󿽱�
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	my_memmove(arr + 2, arr, 24);
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
//��׼�涨��memcpy�ڴ溯������ʵ�ֲ��ص�����
//VS�涨��memcpy��������ʵ���ص�����
//������ʵ���ص�����������memmove����