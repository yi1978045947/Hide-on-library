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
		printf("��ѡ����Ĳ���:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��������Ҫͷ�������(-1��β):>");
			while (scanf("%d", &num),num!=-1)
			{
				SeqListPushBack(&s, num);
			}
			break;
		case 2:
			printf("��������Ҫβ�������(-1��β):>");
			while (scanf("%d", &num), num != -1)
			{
				SeqListPushFront(&s, num);
			}
			break;
		case 3:
			ShowSeqList(&s);
			break;
		case 4:
			printf("��������Ҫ���ҵ�����:>");
			scanf("%d", &num);
			pos=SeqListSearchData(&s, num);
			if (pos == -1)
			{
				printf("���ҵ�Ԫ�ز�����!\n");
			}
			else
			{
				printf("���ҵ�Ԫ���±���:%d\n", pos);
			}
			break;
		case 5:
			SeqListPopBack(&s);
			printf("β��ɾ��Ԫ�سɹ�!\n");
			break;
		case 6:
			SeqListPopFront(&s);
			printf("ͷ��ɾ��Ԫ�سɹ�!\n");
			break;
		case 7:
			printf("��������Ҫ���������:>");
			scanf("%d", &num);
			printf("��������Ҫ�������ݵ��±�:>");
			scanf("%d", &pos);
			SeqListInsert(&s, num, pos);
			printf("�������ݳɹ�!\n");
			break;
		case 8:
			printf("��������Ҫɾ�����ݵ��±�:>");
			scanf("%d", &pos);
			SeqListErase(&s, pos);
			printf("ɾ�����ݳɹ�!\n");
			break;
		case 9:
			printf("��������Ҫ�޸����ݵ��±�:>");
			scanf("%d", &pos);
			printf("��������Ҫ�޸ĵ�����:>");
			scanf("%d", &num);
			SeqListModify(&s, pos,num);
			printf("�޸����ݳɹ�!\n");
			break;
		case 0:
			printf("�˳�����!\n");
			break;
		default:
			printf("������������������!\n");
			break;
		}
	}
	SeqListDestory(&s);
	return 0;
}