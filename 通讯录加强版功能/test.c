#define _CRT_SECURE_NO_WARNINGS   1
#include"header.h"
//void InitContact(struct Contact* pc) //��̬�İ汾��ʼ��ͨѶ¼
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));//�����ڴ��Ϊ0�������ʼ��
//}
void CheckCapacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr == NULL)
		{
			printf("��������ʧ��!\n");
			return;
		}
		else
		{
			//������������ɹ����ָ��ptr��ֵ��pc->data
			pc->data = ptr;
			pc->capacity += 2;
			printf("���������ɹ�!\n");
		}
	}
}
void LoadContact(struct Contact* pc)
{
	FILE* PfIn = fopen("contact.dat", "rb");
	if (PfIn == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, PfIn))
	{
		//1.����Ƿ�Ҫ��������
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(PfIn);
	PfIn = NULL;
}
void InitContact(struct Contact* pc)  //��̬�İ汾��ʼ��ͨѶ¼��ʵ��ͨѶ¼�Ķ�̬����
{
	pc->sz = 0;
	pc->capacity = DEFAULT_SIZE;
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SIZE*sizeof(struct PeoInfo));
	if (pc->data == NULL)
	{
		printf("��̬��ʼ��ͨѶ¼ʧ��!\n");
		exit(1);
	}
	LoadContact(pc);
}
//void AddContact(struct Contact* pc) //��̬�汾������ͨѶ¼��Ϣ
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷�������Ϣ!\n");
//	}
//	else
//	{
		//printf("����������:>");
		//scanf("%s", pc->data[pc->sz].name);
		//printf("����������:>");
		//scanf("%d", &pc->data[pc->sz].age);
		//printf("�������Ա�:>");
		//scanf("%s", pc->data[pc->sz].sex);
		//printf("������绰:>");
		//scanf("%s", pc->data[pc->sz].tel);
		//printf("������סַ:>");
		//scanf("%s", pc->data[pc->sz].addr);
		//pc->sz++;
		//printf("��ӳɹ�!\n");
//	}
//}

void AddContact(struct Contact* pc)
{
	CheckCapacity(pc);
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tel);
	printf("������סַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�!\n");
}
void ShowContact(struct Contact* pc) //��ʾͨѶ¼����Ϣ
{
	int i = 0;
	printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "����", "����", "�Ա�", "�绰", "סַ");  //��ӡ���⣬�����м�������ǿռ������15���ַ�
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��Ŷ,�Ͻ�ȥ�Ӹ��˰�!\n");
	}
	else
	{
		for (i = 0; i < pc->sz; i++)
		{
			printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tel, pc->data[i].addr);
		}
	}
}
static int FindByName(struct Contact* pc,char name[] ) //�����ֲ���,static���κ���,ֻ�����Լ����ڵķ�Χ����ʹ��
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(struct Contact* pc)  //ɾ����ϵ����Ϣ
{
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�հ�������ɾ��Ŷ!\n");
	}
	else
	{
		printf("��������Ҫɾ���˵�����:>");
		scanf("%s", name);
		int pos = FindByName(pc, name);
		if (1 == pos)
		{
			printf("ɾ���˵���Ϣ������!\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < pc->sz-1; j++) //pc->sz�����ָ��Խ��
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("ɾ���ɹ���!\n");
		}
	}
}
void SearchContact(struct Contact* pc) //������ϵ����Ϣ
{
	char name[NAME_MAX] = { 0 };
	printf("��������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("���ҵ�����Ϣ������!\n");
	}
	else
	{
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tel, pc->data[pos].addr);
	}
}
void ModifyContact(struct Contact* pc) //�޸���ϵ�˵���Ϣ
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("�޸��˵���Ϣ������!\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pos].name);
		printf("����������:>");
		scanf("%d", &pc->data[pos].age);
		printf("�������Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pos].tel);
		printf("������סַ:>");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�!\n");
	}
}
static int Cmp_ByName(void* p1, void* p2)
{
	return strcmp(((struct PeoInfo*)p1)->name, ((struct PeoInfo*)p2)->name);
}

//��������Ԫ�ص����ݣ�width����һ��Ԫ����ռ�ڴ�ռ�Ĵ�С����λ���ֽڣ�
static void Swap(void* p1, void* p2, int width)
{
	//һ���ֽ�һ���ֽڵĽ���
	while (width)
	{
		char tmp = *(char*)p1;
		*(char*)p1 = *(char*)p2;
		*(char*)p2 = tmp;
		++(char*)p1;
		++(char*)p2;
		width--;
	}
}

static void qsort(void* p, int sz, int width, int(*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	int flag = 1;//flagΪ1�����Ѿ��ź���Ϊ0���ǻ�û�ź�����Ĭ����Ϊ1
	//ð������
	for (i = 0; i < sz - 1; i++)//sz��Ԫ�أ�һ��Ҫ�Ƚ�sz-1�ˣ�ÿһ�������һ��Ԫ��
	{
		for (j = 0; j < sz - 1 - i; j++)//ÿ��Ҫ�����Ƚϵ�ǰδ�ź����Ԫ�ظ���-1��
		{
			if (cmp((char*)p + (j*width), (char*)p + ((j + 1)*width)) > 0)//�ж��Ƿ�Ҫ��������Ԫ�أ����ж�ǰһ��Ԫ�ص������Ƿ���ں�һ��Ԫ�ص����֣�
			{
				Swap((char*)p + (j*width), (char*)p + ((j + 1)*width), width);//����������Ա��λ��
				flag = 0;//�Ѿ��ж�����������ˣ�����flag=0
			}
		}
		if (flag == 1)//��һ�������Ƚ�����flag��Ȼ=1��������϶������ˣ�����ð������
		{
			break;
		}
	}
}
void SortContact(struct Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), Cmp_ByName);
}
void ClearContact(struct Contact* pc)
{
	free(pc->data);
	pc->sz = 0;
	pc->capacity = 0;
	pc->data = NULL;
	printf("���ͨѶ¼�ɹ�!\n");
}
void SaveContact(struct Contact* pc)
{
	FILE* PfOut = fopen("contact.dat", "wb");
	if (PfOut == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->data + i, sizeof(struct PeoInfo), 1, PfOut); //pc->data+i==&pc->data[i]
		}
	}
	fclose(PfOut);
	PfOut = NULL;
}