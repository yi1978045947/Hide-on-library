#define _CRT_SECURE_NO_WARNINGS   1
#include"header.h"
void InitContact(struct Contact* pc) //初始化通讯录
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));//数组内存变为0，数组初始化
}
void AddContact(struct Contact* pc) //增加通讯录信息
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法加入信息!\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄:>");
		scanf("%d", &pc->data[pc->sz].age);
		printf("请输入性别:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pc->sz].tel);
		printf("请输入住址:>");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("添加成功!\n");
	}
}
void ShowContact(struct Contact* pc) //显示通讯录中信息
{
	int i = 0;
	printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "名字", "年龄", "性别", "电话", "住址");  //打印标题，其中中间的数字是空间可以有15个字符
	if (pc->sz == 0)
	{
		printf("通讯录为空哦,赶紧去加个人吧!\n");
	}
	else
	{
		for (i = 0; i < pc->sz; i++)
		{
			printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tel, pc->data[i].addr);
		}
	}
}
static int FindByName(struct Contact* pc,char name[] ) //按名字查找,static修饰函数,只能在自己所在的范围才能使用
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
void DelContact(struct Contact* pc)  //删除联系人信息
{
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空啊，不能删除哦!\n");
	}
	else
	{
		printf("请输入你要删除人的名字:>");
		scanf("%s", name);
		int pos = FindByName(pc, name);
		if (1 == pos)
		{
			printf("删除人的信息不存在!\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < pc->sz-1; j++) //pc->sz会造成指针越界
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("删除成功啦!\n");
		}
	}
}
void SearchContact(struct Contact* pc) //查找联系人信息
{
	char name[NAME_MAX] = { 0 };
	printf("请输入你要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("查找的人信息不存在!\n");
	}
	else
	{
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tel, pc->data[pos].addr);
	}
}
void ModifyContact(struct Contact* pc) //修改联系人的信息
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("修改人的信息不存在!\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &pc->data[pos].age);
		printf("请输入性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pos].tel);
		printf("请输入住址:>");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功!\n");
	}
}
static int Cmp_ByName(void* p1, void* p2)
{
	return strcmp(((struct PeoInfo*)p1)->name, ((struct PeoInfo*)p2)->name);
}

//交换两个元素的内容（width，是一个元素所占内存空间的大小，单位是字节）
static void Swap(void* p1, void* p2, int width)
{
	//一个字节一个字节的交换
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
	int flag = 1;//flag为1是是已经排好序，为0是是还没排好序，先默认它为1
	//冒泡排序
	for (i = 0; i < sz - 1; i++)//sz个元素，一共要比较sz-1趟，每一趟排序好一个元素
	{
		for (j = 0; j < sz - 1 - i; j++)//每趟要两两比较当前未排好序的元素个数-1次
		{
			if (cmp((char*)p + (j*width), (char*)p + ((j + 1)*width)) > 0)//判断是否要交换两个元素（既判断前一个元素的名字是否大于后一个元素的名字）
			{
				Swap((char*)p + (j*width), (char*)p + ((j + 1)*width), width);//交换两个成员的位置
				flag = 0;//已经判断这次是无序了，所以flag=0
			}
		}
		if (flag == 1)//若一趟两两比较下来flag仍然=1，则数组肯定有序了，跳出冒泡排序
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
	InitContact(pc);
	printf("清空通讯录成功!\n");
}