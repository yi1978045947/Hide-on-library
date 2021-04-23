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

struct ListNode* BuyListNode(LTDataType x);                          //�����ڵ�
struct ListNode* ListInit();                                         //��ʼ������
void ListPushBack(struct ListNode* phead, LTDataType x);             //β����������
void ListPushFront(struct ListNode* phead, LTDataType x);            //ͷ����������
void ListPopBack(struct ListNode* phead);                            //β��ɾ������
void ListPopFront(struct ListNode* phead);                           //ͷ��ɾ������
struct ListNode* ListFind(struct ListNode* phead,LTDataType x);      //��������
void ListInsert(struct ListNode* pos, LTDataType x);                 //����λ�ò���
void ListEarse(struct ListNode* pos);                                //����λ��ɾ��
int  ListEmpty(struct ListNode* phead);                              //�ж������Ƿ�Ϊ��
int  ListSize(struct ListNode* phead);                               //�ж������С
void ListDestory(struct ListNode* phead);                            //��������
void ListPrint(struct ListNode* phead);
