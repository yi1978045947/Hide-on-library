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
BTNode* CreateTreeNode(BTDataType x);           //创建节点
void BinaryTreeDestory(BTNode* root);           //销毁二叉树

void PrevOrder(BTNode* root);                  //前序遍历
void InOrder(BTNode* root);                    //中序遍历
void PostOrder(BTNode* root);                  //后序遍历
void BinaryTreeLevelOrder(BTNode* root);       //层序遍历

int BinaryTreeLevelKSize(BTNode* root, int k); //查找第k层节点个数
BTNode* BinaryTreeFind(BTNode* root, int x);   //二叉树查找值为x的节点

int TreeSize(BTNode* root);                    //树的节点个数
int TreeLeafSize(BTNode* root);                //叶子节点个数

bool BinaryTreeComplete(BTNode* root);        //判断树是否为完全二叉树