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
void Swap(int* left, int* right);                          //交换两个数
void AdjustDown(int* a, int n, int parent);                //向下调整算法      
void AdjustUp(int*a,int child);                    //向上调整算法

void HeapInit(struct Heap* hp, HPDataType* a, int n);     //初始化堆
void HeapDestory(struct Heap* hp);                        //销毁堆

void HeapPush(struct Heap *hp, HPDataType x);             //堆的插入
void HeapPop(struct Heap* hp);                            //堆得删除

HPDataType HeapTop(struct Heap* hp);                      //取堆顶数据
HPDataType HeapSize(struct Heap* hp);                     //取得堆数据个数

bool HeapEmpty(struct Heap* hp);                          //堆得判空

void HeapPrint(struct Heap* hp);                          //打印堆




