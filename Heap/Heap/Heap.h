#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef int HPDataType;
struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
};
void Swap(int* left, int* right);                          //����������
void AdjustDown(int* a, int n, int parent);                //���µ����㷨      
void AdjustUp(int*a,int child);                    //���ϵ����㷨

void HeapInit(struct Heap* hp, HPDataType* a, int n);     //��ʼ����
void HeapDestory(struct Heap* hp);                        //���ٶ�

void HeapPush(struct Heap *hp, HPDataType x);             //�ѵĲ���
void HeapPop(struct Heap* hp);                            //�ѵ�ɾ��

HPDataType HeapTop(struct Heap* hp);                      //ȡ�Ѷ�����
HPDataType HeapSize(struct Heap* hp);                     //ȡ�ö����ݸ���

bool HeapEmpty(struct Heap* hp);                          //�ѵ��п�

void HeapPrint(struct Heap* hp);                          //��ӡ��




