#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//
//struct book //����һ���ṹ�������struct book
//{
//	char author[50];//����
//	char name[30];  //����
//	int price;     //�۸�
//	int num;      //���
//};
//int main()
//{
//	struct book b1 = { "̷��ǿ", "C���Գ������", 50, 1 };//����һ���ṹ��ı���b1,�ֱ����Ա������ֵ
//	struct book b2 = { "����", "�����鼮", 100, 2 };
//	struct book* pa = &b1;//�ѱ���b1��ַ�浽�ṹ��ָ��pa��
//	printf("%s %s %d %d", pa->author, pa->name, pa->num, pa->price);//��paָ��ȥ���ʽṹ��ı���
//	printf("\n");
//	printf("%s %s %d %d", b2.author, b2.name, b2.num, b2.price);//�ò�����.ȥ���ʽṹ��ı���
//	printf("\n");
//	return 0;
//}

//struct b1  //�ṹ����ڴ����
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

//enum COLOR ö�ٵ�ʹ��
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

//union un ������
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