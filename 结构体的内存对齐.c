#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct b1
{
	char a;
	int b;
	char c;
};
struct b2
{
	char d;
	double e;
	struct b1 f; //�ṹ��ĵ�Ƕ��
};
struct b3 //λ�ε��ڴ����
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
struct book 
{
	char name[50];
	char author[50];
	int price;
	int num;
};
int main()  //�ṹ����ڴ����
{
	struct book b5 = { "�����鼮", "����������", 100, 1 };
	struct book* pa = &b5;
	printf("%s %s %d %d", pa->author,pa->name,pa->num,pa->price);
	printf("\n");
	int len = sizeof(struct b2);
	printf("%d\n", len);
	printf("%d\n", sizeof(struct b3));
	return 0;
}