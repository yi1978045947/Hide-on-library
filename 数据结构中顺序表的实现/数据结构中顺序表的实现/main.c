#define _CRT_SECURE_NO_WARNINGS   1
#include"SeqList.h"
void menu()
{
	printf("*********************************\n");
	printf("*1.push_back     2.push_front   *\n");
	printf("*3.show_seqlist  4.search       *\n");
	printf("*5.pop_back      6.pop_front    *\n");
	printf("*7.casual_insert 8.casual_erase *\n");
	printf("*9.modify        0.exit         *\n");
	printf("*********************************\n");
}
int main()
{
	SeqDataType select = 1;
	SeqDataType num = 0;
	SeqDataType pos = 0;
	SeqList s;
	SeqListInit(&s);
	while (select)
	{
		menu();
		printf("请选择你的操作:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入你要头插的数据(-1结尾):>");
			while (scanf("%d", &num),num!=-1)
			{
				SeqListPushBack(&s, num);
			}
			break;
		case 2:
			printf("请输入你要尾插的数据(-1结尾):>");
			while (scanf("%d", &num), num != -1)
			{
				SeqListPushFront(&s, num);
			}
			break;
		case 3:
			ShowSeqList(&s);
			break;
		case 4:
			printf("请输入你要查找的数据:>");
			scanf("%d", &num);
			pos=SeqListSearchData(&s, num);
			if (pos == -1)
			{
				printf("查找的元素不存在!\n");
			}
			else
			{
				printf("查找的元素下标是:%d\n", pos);
			}
			break;
		case 5:
			SeqListPopBack(&s);
			printf("尾上删除元素成功!\n");
			break;
		case 6:
			SeqListPopFront(&s);
			printf("头上删除元素成功!\n");
			break;
		case 7:
			printf("请输入你要插入的数据:>");
			scanf("%d", &num);
			printf("请输入你要插入数据的下标:>");
			scanf("%d", &pos);
			SeqListInsert(&s, num, pos);
			printf("插入数据成功!\n");
			break;
		case 8:
			printf("请输入你要删除数据的下标:>");
			scanf("%d", &pos);
			SeqListErase(&s, pos);
			printf("删除数据成功!\n");
			break;
		case 9:
			printf("请输入你要修改数据的下标:>");
			scanf("%d", &pos);
			printf("请输入你要修改的数据:>");
			scanf("%d", &num);
			SeqListModify(&s, pos,num);
			printf("修改数据成功!\n");
			break;
		case 0:
			printf("退出程序!\n");
			break;
		default:
			printf("输入有误，请重新输入!\n");
			break;
		}
	}
	SeqListDestory(&s);
	return 0;
}