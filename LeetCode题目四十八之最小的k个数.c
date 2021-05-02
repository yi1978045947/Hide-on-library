#define _CRT_SECURE_NO_WARNINGS   1
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
typedef int HPDataType;
struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
};
void Swap(int* left, int* right);                          //交换两个数
void AdjustDown(int* a, int n, int parent);                //向下调整算法      
void AdjustUp(int*a, int child);                            //向上调整算法

void HeapInit(struct Heap* hp, HPDataType* a, int n);     //初始化堆
void HeapDestory(struct Heap* hp);                        //销毁堆

void HeapPush(struct Heap *hp, HPDataType x);             //堆的插入
void HeapPop(struct Heap* hp);                            //堆得删除

HPDataType HeapTop(struct Heap* hp);                      //取堆顶数据
HPDataType HeapSize(struct Heap* hp);                     //取得堆数据个数

bool HeapEmpty(struct Heap* hp);                          //堆得判空
void Swap(int* left, int* right)
{
	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child<n)//(n > 0)
	{
		if (child + 1 < n&&a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0) //孩子大于0,则继续循环，否则终止循环
	{
		if (a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else  //已成为堆
		{
			break;
		}
	}
}
void HeapInit(struct Heap* hp, HPDataType* a, int n)     //初始化堆
{
	assert(hp);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (hp->a == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	memcpy(hp->a, a, sizeof(HPDataType)*n);
	hp->size = n;
	hp->capacity = n;
	int i = 0;
	for (i = (hp->size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, hp->size, i);
	}
}
void HeapDestory(struct Heap* hp)                        //销毁堆
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

void HeapPush(struct Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)   //先判断容量是否充足
	{
		//用realloc在已有空间在开辟一块空间
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType)* hp->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = hp->capacity * 2;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}
void HeapPop(struct Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--; //删除掉堆底数据
	AdjustDown(hp->a, hp->size, 0);
}

HPDataType HeapTop(struct Heap* hp)
{
	assert(hp);
	assert(hp->size != 0);
	return hp->a[0];
}
HPDataType HeapSize(struct Heap* hp)
{
	assert(hp);
	return hp->size;
}

bool HeapEmpty(struct Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	struct Heap hp;
	HeapInit(&hp, arr, arrSize);
	int* ret = (int*)malloc(sizeof(int)*k);
	for (int i = 0; i<k; i++)
	{
		ret[i] = HeapTop(&hp);
		HeapPop(&hp);
	}
	*returnSize = k;
	return ret;
}
int main()
{
	struct Heap hp;
}