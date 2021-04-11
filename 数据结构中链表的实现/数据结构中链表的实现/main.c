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
		printf("���������ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��������Ҫβ�������(-1����):>");
			while (scanf("%d", &num), num != -1)
			{
				SListPushBack(&s, num);
			}
			printf("β�����ݳɹ�!\n");
			break;
		case 2:
			printf("��������Ҫͷ�������(-1����):>");
			while (scanf("%d", &num), num != -1)
			{
				SListPushFront(&s, num);
			}
			printf("ͷ�����ݳɹ�!\n");
			break;
		case 3:
			SListPrint(s);
			break;
		case 4:
			SListPopBack(&s);
			printf("β��ɾ�����ݳɹ�!\n");
			break;
		case 5:
			SListPopFront(&s);
			printf("ͷ��ɾ�����ݳɹ�!\n");
			break;
		case 6:
			printf("��������Ҫ���ҵ�����:>");
			scanf("%d", &num);
			SLTNode* pos = SListFindKey(s, num);
			if (pos)
			{
				printf("�ҵ���!\n");
			}
			else
			{
				printf("�Ҳ���!\n");
			}
			break;
		case 7:
			printf("��������Ҫ���������:>");
			scanf("%d", &num);
			SListInsertAfter(s, num);
			printf("�������ݳɹ�!\n");
			break;
		case 8:
			printf("��������Ҫ���������:>");
			scanf("%d", &num);
			SListInsertBefore(&s, s, num);
			break;
		case 9:
			printf("��������Ҫɾ��������:>");
			scanf("%d", &num);
			SListEarseAfter(s);
			break;
		case 0:
			printf("�˳�����!\n");
			break;
		default:
			printf("�������ѡ���д�������������!\n");
			break;
		}
	}
}