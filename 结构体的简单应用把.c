#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//struct book
//{
//	char author[30];
//	char name[50];
//	int price;
//};
//int main()
//{
//	struct book b1 = { "̷��ǿ", "C���Գ������", 50 };
//	printf("%s %s %d", b1.author, b1.name, b1.price);
//	printf("\n");
//	return 0;
//}

typedef struct book //���������� ��struct book ���͸ĳ�book���ͣ��Ժ󴴽�ʱbook ��������
{
	char author[50];
	char name[50];
	int price;
	char PublishingHouse[50];
}book;//�� struct book������������Ϊbook
int main()
{
	book b1 = { "̷��ǿ", "C���Գ������", 50, "�廪��ѧ������" };
	printf("%s %s %d %s", b1.author, b1.name, b1.price, b1.PublishingHouse);
	printf("\n");
	book b2 = { "�������Ա", "������", 170, "����������" };
	printf("%s %s %d %s", b2.author, b2.name, b2.price, b2.PublishingHouse);
	printf("\n");
	return 0;
}