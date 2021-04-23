#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}; 

struct ListNode* BuyListNode(LTDataType x);                          //创建节点
struct ListNode* ListInit();                                         //初始化链表
void ListPushBack(struct ListNode* phead, LTDataType x);             //尾部插入数据
void ListPushFront(struct ListNode* phead, LTDataType x);            //头部插入数据
void ListPopBack(struct ListNode* phead);                            //尾部删除数据
void ListPopFront(struct ListNode* phead);                           //头部删除数据
struct ListNode* ListFind(struct ListNode* phead,LTDataType x);      //查找数据
void ListInsert(struct ListNode* pos, LTDataType x);                 //任意位置插入
void ListEarse(struct ListNode* pos);                                //任意位置删除
int  ListEmpty(struct ListNode* phead);                              //判断链表是否为空
int  ListSize(struct ListNode* phead);                               //判断链表大小
void ListDestory(struct ListNode* phead);                            //销毁链表
void ListPrint(struct ListNode* phead);
