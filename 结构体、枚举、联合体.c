#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//
//struct book //定义一个结构体的类型struct book
//{
//	char author[50];//作者
//	char name[30];  //书名
//	int price;     //价格
//	int num;      //编号
//};
//int main()
//{
//	struct book b1 = { "谭浩强", "C语言程序设计", 50, 1 };//创建一个结构体的变量b1,分别给成员变量赋值
//	struct book b2 = { "咸鱼", "王道书籍", 100, 2 };
//	struct book* pa = &b1;//把变量b1地址存到结构体指针pa中
//	printf("%s %s %d %d", pa->author, pa->name, pa->num, pa->price);//用pa指针去访问结构体的变量
//	printf("\n");
//	printf("%s %s %d %d", b2.author, b2.name, b2.num, b2.price);//用操作符.去访问结构体的变量
//	printf("\n");
//	return 0;
//}

//struct b1  //结构体的内存对齐
//{
//	char c1;
//	int c2;
//	char c3;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct b1));
//	return 0;
//}
//struct b2{
//	char c1;
//	char c2;
//	int c3;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct b2));
//	return 0;
//}
//struct b3
//{
//	int _b : 5;
//	int _c : 10;
//	int _d : 20;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct b3));
//	return 0;
//}

//enum COLOR 枚举的使用
//{
//	RED = 1,
//	GREEN,
//	BLUE 
//};
//int main()
//{
//	printf("%d\n", RED);
//	printf("%d\n", GREEN);
//	printf("%d\n", BLUE);
//	return 0;
//}

//union un 联合体
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union un u;
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//	printf("%d\n", sizeof(union un));
//	return 0;
//}

union b1
{
	char c[5];
	int i;
};
union b2
{
	char c[7];
	int i;
};
int main()
{
	printf("%d\n", sizeof(union b1));
	printf("%d\n", sizeof(union b2));
	return 0;
}