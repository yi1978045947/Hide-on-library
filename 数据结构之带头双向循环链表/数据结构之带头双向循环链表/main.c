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
		printf("���������ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��������Ҫβ�������(-1����):>");
			while (scanf("%d", &num), num != -1)
			{
				ListPushBack(plist, num);
			}
			printf("β�����ݳɹ�!\n");
			break;
		case 2:
			printf("��������Ҫͷ�������(-1����):>");
			while (scanf("%d", &num), num != -1)
			{
				ListPushFront(plist, num);
			}
			printf("β�����ݳɹ�!\n");
			break;
		case 3:
			ListPrint(plist);
			break;
		case 4:
			ListPopBack(plist);
			printf("βɾ���ݳɹ�!\n");
			break;
		case 5:
			ListPopFront(plist);
			printf("ͷɾ���ݳɹ�!\n");
			break;
		case 6:
			printf("��������Ҫ���ҵ�λ��:>");
			scanf("%d", &num);
			struct ListNode* pos1=ListFind(plist, num);
			printf("%d\n", pos1);
			break;
		case 7:
			printf("��������Ҫ�����λ��:>");
			scanf("%d", &num);
			struct ListNode* pos2 = ListFind(plist,num);
			if (pos2)
			{
				ListInsert(plist, num);
			}
			break;
		case 8:
			printf("��������Ҫɾ����λ��:>");
			scanf("%d", &num);
			struct ListNode* pos3 = ListFind(plist, num);
			ListEarse(pos3);
			break;
		case 9:
		    int ret = ListEmpty(plist);
			if (ret == 1)
			{
				printf("����Ϊ��!\n");
			}
			else
			{
				printf("����Ϊ��!\n");
			}
			break;
		case 10:
			int len = ListSize(plist);
			printf("������:%d\n", len);
			break;
		case 11:
			ListDestory(plist);
			plist = NULL;
			break;
		case 0:
			printf("�˳�����!\n");
			break;
		default:
			printf("��������,����������!\n");
			break;
		}
	}
}