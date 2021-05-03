#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
BTNode* CreateTreeNode(BTDataType x);           //�����ڵ�
void BinaryTreeDestory(BTNode* root);           //���ٶ�����

void PrevOrder(BTNode* root);                  //ǰ�����
void InOrder(BTNode* root);                    //�������
void PostOrder(BTNode* root);                  //�������
void BinaryTreeLevelOrder(BTNode* root);       //�������

int BinaryTreeLevelKSize(BTNode* root, int k); //���ҵ�k��ڵ����
BTNode* BinaryTreeFind(BTNode* root, int x);   //����������ֵΪx�Ľڵ�

int TreeSize(BTNode* root);                    //���Ľڵ����
int TreeLeafSize(BTNode* root);                //Ҷ�ӽڵ����

bool BinaryTreeComplete(BTNode* root);        //�ж����Ƿ�Ϊ��ȫ������