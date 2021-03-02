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
//	struct book b1 = { "谭浩强", "C语言程序设计", 50 };
//	printf("%s %s %d", b1.author, b1.name, b1.price);
//	printf("\n");
//	return 0;
//}

typedef struct book
{
	char author[50];
	char name[50];
	int price;
	char PublishingHouse[50];
}book;
int main()
{
	book b1 = { "谭浩强", "C语言程序设计", 50, "清华大学出版社" };
	printf("%s %s %d %s", b1.author, b1.name, b1.price, b1.PublishingHouse);
	printf("\n");
	book b2 = { "王道组成员", "王道书", 170, "王道出版社" };
	printf("%s %s %d %s", b2.author, b2.name, b2.price, b2.PublishingHouse);
	printf("\n");
	return 0;
}