#define _CRT_SECURE_NO_WARNINGS   1
#include"List.h"
void menu()
{
	printf("******************************\n");
	printf("*1.push_back    2.push_front**\n");
	printf("*3.show                     **\n");
	printf("*4.pop_back     5.pop_front **\n");
	printf("*6.find                     **\n");
	printf("*7.insert       8.erase     **\n");
	printf("*9.empty        10.length   **\n");
	printf("*0.exit         11.destory  **\n");
	printf("******************************\n");
}
int main()
{
	LTDataType select = 1;
	LTDataType num = 0;
	struct ListNode* plist = ListInit();
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
				ListPushBack(plist, num);
			}
			printf("尾插数据成功!\n");
			break;
		case 2:
			printf("请输入你要头插的数据(-1结束):>");
			while (scanf("%d", &num), num != -1)
			{
				ListPushFront(plist, num);
			}
			printf("尾插数据成功!\n");
			break;
		case 3:
			ListPrint(plist);
			break;
		case 4:
			ListPopBack(plist);
			printf("尾删数据成功!\n");
			break;
		case 5:
			ListPopFront(plist);
			printf("头删数据成功!\n");
			break;
		case 6:
			printf("请输入你要查找的位置:>");
			scanf("%d", &num);
			struct ListNode* pos1=ListFind(plist, num);
			printf("%d\n", pos1);
			break;
		case 7:
			printf("请输入你要插入的位置:>");
			scanf("%d", &num);
			struct ListNode* pos2 = ListFind(plist,num);
			if (pos2)
			{
				ListInsert(plist, num);
			}
			break;
		case 8:
			printf("请输入你要删除的位置:>");
			scanf("%d", &num);
			struct ListNode* pos3 = ListFind(plist, num);
			ListEarse(pos3);
			break;
		case 9:
		    int ret = ListEmpty(plist);
			if (ret == 1)
			{
				printf("链表不为空!\n");
			}
			else
			{
				printf("链表为空!\n");
			}
			break;
		case 10:
			int len = ListSize(plist);
			printf("链表长度:%d\n", len);
			break;
		case 11:
			ListDestory(plist);
			plist = NULL;
			break;
		case 0:
			printf("退出程序!\n");
			break;
		default:
			printf("输入有误,请重新输入!\n");
			break;
		}
	}
}