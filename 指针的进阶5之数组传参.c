#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//һά���鴫��
void test1(int arr1[])
{

}
void test1(int arr1[10])
{

}
void test1(int* arr1)
{

}
void test2(int *arr2[20])
{

}
void test2(int **arr2) //ָ�����鴫�Σ����ε�����Ԫ�ص�ַ����Ԫ�ص�ַ������int*,������int** ������
{

}

//��ά���鴫��
void test3(int arr[3][5])
{

}
void test3(int arr3[][]) //�����д��->,�п��Բ�д,�в��ܲ�д
{

}
void test3(int arr3[][5])
{

}
void test3(int* arr3) //�����д����arr3��һ����ά���飬����������ָ��������
{

}
void test3(int* arr3[5]) //�����д����arr3��һ����ά���飬����һ��ָ������������
{

}
void test3(int(*arr3)[5]) //arr3��һ��ָ�룬ָ���arr3�и�Ԫ�أ�ÿ��Ԫ��������int����
{

}
void test3(int** arr3)  //�����д��������ָ������������һ��ָ��ĵ�ַ
{

}
int main()
{
	//һά���鴫��
	int arr1[10] = { 0 };
	int* arr2[20] = { 0 };
	test1(arr1);
	test2(arr2);
	//��ά���鴫��
	int arr3[3][5] = { 0 };
	test3(arr3);
	return 0;
}