#define _CRT_SECURE_NO_WARNINGS   1
#include"header.h"
enum option{  //ö�ٳ�ʼ�����㿪ʼ
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	CLEAR,
	SAVE
};
void menu()
{
	printf("*************************************\n");
	printf("********* 1.add     2.del    ********\n");
	printf("********* 3.search  4.modify ********\n");
	printf("********* 5.show    6.sort   ********\n");
	printf("********* 0.exit    7.clear  ********\n");
	printf("********* 8.save             ********\n");
	printf("*************************************\n");
}
void test()
{
	int input = 0;
	struct Contact con;//����һ��ͨѶ¼con
	InitContact(&con); //��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼!\n");
			break;
		default:
			printf("������д���,����������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}