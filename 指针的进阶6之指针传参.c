#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void print(int* pa, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(pa + i));
	}
	printf("\n");
}
void test1(int** pb)
{

}
void test2(int** pc)
{

}
int main()
{
	int arr1[] = { 1, 2, 4, 5, 6, 7, 8, 9, 10 };
	int* pa = &arr1;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	//һ��ָ��pa,��������
	print(pa, sz);
	//����ָ�봫��,����ָ��������
	int i = 0;
	int* pb = &i;
	int** pc = &pb;
	test1(&pb); //��һ��ָ��ĵ�ַ
	test2(pc); //������ָ��pc
	return 0;
}