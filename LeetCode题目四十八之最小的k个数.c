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
void Swap(int* left, int* right);                          //����������
void AdjustDown(int* a, int n, int parent);                //���µ����㷨      
void AdjustUp(int*a, int child);                            //���ϵ����㷨

void HeapInit(struct Heap* hp, HPDataType* a, int n);     //��ʼ����
void HeapDestory(struct Heap* hp);                        //���ٶ�

void HeapPush(struct Heap *hp, HPDataType x);             //�ѵĲ���
void HeapPop(struct Heap* hp);                            //�ѵ�ɾ��

HPDataType HeapTop(struct Heap* hp);                      //ȡ�Ѷ�����
HPDataType HeapSize(struct Heap* hp);                     //ȡ�ö����ݸ���

bool HeapEmpty(struct Heap* hp);                          //�ѵ��п�
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
	while (child>0) //���Ӵ���0,�����ѭ����������ֹѭ��
	{
		if (a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else  //�ѳ�Ϊ��
		{
			break;
		}
	}
}
void HeapInit(struct Heap* hp, HPDataType* a, int n)     //��ʼ����
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
void HeapDestory(struct Heap* hp)                        //���ٶ�
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

void HeapPush(struct Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)   //���ж������Ƿ����
	{
		//��realloc�����пռ��ڿ���һ��ռ�
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
	hp->size--; //ɾ�����ѵ�����
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