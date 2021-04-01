#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
//冒泡排序只对整形排序
void Bubble_Sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++) //趟数
	{
		for (j = 0; j < sz - i - 1;j++) //次数
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = 0;
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void qsort(void *base,
	       size_t num,
		   size_t width,
		   int(__cdecl *compare)(const void *elem1, const void *elem2)
		  );

struct stu
{
	char name[20];
	int age;
};
//e1和e2是要比较元素的两个地址
int cmp_int(const void* e1, const void* e2) //按照整形来排序
{
	return(*(int*)e1 - *(int*)e2);
}

int cmp_by_age(const void* e1, const void* e2)  //按照结构体中年龄来排序
{
	return (((struct stu*)e1)->age - ((struct stu*)e2)->age);
}

int cmp_by_name(const void* e1, const void* e2) //按照结构体中名字来排序
{
	return (strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name));
}

int main()
{
	//void*的指针变量，可以接收任意类型的地址
	//因为void*的指针，没有具体类型，所以不能进行解引用操作，不能++/--
	int a = 10;
	int* p = &a;
	int arr[] = { 1, 4, 5, 6, 3, 8, 9, 10, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//qsort实现对整形的排序
	qsort(arr, sz, sizeof(arr[0]), cmp_int); //数组名，数组大小，数据占多少字节，比较函数
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	struct stu Stu[] = { { "zhangsan", 15 }, { "lisi", 12 }, { "wangwu", 18 }, { "wanger", 14 } };
	int num = sizeof(Stu) / sizeof(Stu[0]);

	qsort(Stu, num, sizeof(Stu[0]), cmp_by_age); //按年龄来排序
	for (i = 0; i < num; i++)
	{
		printf("%d->%s ", Stu[i].age,Stu[i].name);
	}
	printf("\n");

	qsort(Stu, num, sizeof(Stu[0]), cmp_by_name); //按照名字来排序,相当于比较字符串
	for (i = 0; i < num; i++)
	{
		printf("%s->%d ", Stu[i].name, Stu[i].age);
	}
	printf("\n");

	return 0;
}