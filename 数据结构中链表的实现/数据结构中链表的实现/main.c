#define _CRT_SECURE_NO_WARNINGS   1
#include "SList.h"
void menu()
{
	printf("*********************************\n");
	printf("*1.push_back     2.push_front   *\n");
	printf("*3.print         4.pop_back     *\n");
	printf("*5.pop_front     6.find         *\n");
	printf("*7.insert_after  8.insert_before*\n");
	printf("*0.exit                         *\n");
	printf("*********************************\n");
}
int main()
{
	SLTDateType num = 0;
	SLTDateType pos = 0;
	SLTDateType select = 1;
	SLTNode* s = NULL;
	while (select)
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入你要尾插的数据(-1结束):>");
			while (scanf("%d", &num), num != -1)
			{
				SListPushBack(&s, num);
			}
			printf("尾插数据成功!\n");
			break;
		case 2:
			printf("请输入你要头插的数据(-1结束):>");
			while (scanf("%d", &num), num != -1)
			{
				SListPushFront(&s, num);
			}
			printf("头插数据成功!\n");
			break;
		case 3:
			SListPrint(s);
			break;
		case 4:
			SListPopBack(&s);
			printf("尾部删除数据成功!\n");
			break;
		case 5:
			SListPopFront(&s);
			printf("头部删除数据成功!\n");
			break;
		case 6:
			printf("请输入你要查找的数据:>");
			scanf("%d", &num);
			SLTNode* pos = SListFindKey(s, num);
			if (pos)
			{
				printf("找到了!\n");
			}
			else
			{
				printf("找不到!\n");
			}
			break;
		case 7:
			printf("请输入你要插入的数据:>");
			scanf("%d", &num);
			SListInsertAfter(s, num);
			printf("插入数据成功!\n");
			break;
		case 8:
			printf("请输入你要插入的数据:>");
			scanf("%d", &num);
			SListInsertBefore(&s, s, num);
			break;
		case 9:
			printf("请输入你要删除的数据:>");
			scanf("%d", &num);
			SListEarseAfter(s);
			break;
		case 0:
			printf("退出程序!\n");
			break;
		default:
			printf("你输入的选择有错误，请重新输入!\n");
			break;
		}
	}
}