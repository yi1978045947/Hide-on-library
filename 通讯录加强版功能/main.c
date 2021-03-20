#define _CRT_SECURE_NO_WARNINGS   1
#include"header.h"
enum option{  //枚举初始化从零开始
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
	struct Contact con;//创建一个通讯录con
	InitContact(&con); //初始化通讯录
	do
	{
		menu();
		printf("请输入你的选择:>");
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
			printf("退出通讯录!\n");
			break;
		default:
			printf("输入的有错误,请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}