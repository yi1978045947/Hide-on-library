#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct a   //����������������Ա�Ľṹ��Ĵ�С��ʱ�򣬲��������������Ա�����������Ա�Ĵ�Сʱ�ɱ��
{
	int i;
	int arr[];
};
struct b 
{
	char c;
	int i;
	int arr[];
};
struct c
{
	int a;
	int* arr;
};
int main()
{
	printf("%d\n", sizeof(struct a));
	printf("%d\n", sizeof(struct b)); //�����������ڴ����Ӱ��  //���������Ա���Ǵ�����
	printf("%d\n", sizeof(struct c));
	struct a* pa = (struct a*)malloc(sizeof(struct a) + sizeof(int)* 10);
	pa->i = 100;
	int b = 0;
	for (b = 0; b < 10; b++)
	{
		pa->arr[b] = b;
	}
	for (b = 0; b < 10; b++)
	{
		printf("%d ", pa->arr[b]);
	}
	printf("\n");
	for (b = 0; b < 10; b++)
	{
		printf("%d ", *(pa + b));//��ʱ��Ϊ�ȿ����˿ռ䣬���Ե�һ���ռ��ǽṹ��Ŀռ�
	}
	printf("\n");
	free(pa);
	pa = NULL;
	struct c* pb = (struct c*)malloc(sizeof(struct c));
	pb->arr = (int*)malloc(sizeof(int));
	free(pb);	
	free(pb->arr);
	pb = NULL;
	pb->arr = NULL;
	return 0;
}
//1.�ṹ�е����������Աǰ���������һ��������Ա��
//2.sizeof ���ص����ֽṹ��С����������������ڴ档
//3.�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ���������Ԥ�ڴ�С��