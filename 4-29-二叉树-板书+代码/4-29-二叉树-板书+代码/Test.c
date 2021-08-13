#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}
	
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	static int size = 0;
//
//	++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

// 思路一：遍历计数的方式
//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	++(*psize);
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 
		: TreeSize(root->left)
		+ TreeSize(root->right)
		+ 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// k > 0
int TreeKLevelSize(BTNode* root, int  k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return TreeKLevelSize(root->left, k - 1) +
		TreeKLevelSize(root->right, k - 1);
}

// 查找树里面值为x的那个节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	// 我自己不是
	if (root->data == x)
		return root;

	// 分别到左右子树中去找
	BTNode* lret = TreeFind(root->left, x);
	if (lret)
		return lret;

	BTNode* rret = TreeFind(root->right, x);
	if (rret)
		return rret;

	// 左右右边都没有找到
	return NULL;
}

// 二叉树销毁
//void BinaryTreeDestory(BTNode** pproot)
//{
//	if (*pproot == NULL)
//		return;
//
//	BinaryTreeDestory(&(*pproot)->left);
//	BinaryTreeDestory(&(*pproot)->right);
//	free(*pproot);
//	*pproot = NULL;
//}

// 一般，如果选择一级指针，存在野指针问题，调用BinaryTreeDestory的人，把指针置空
// 这样保持接口的一致性
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root = NULL;
}

void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");

	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
			return false;
	}

	QueueDestroy(&q);
	return true;
}
 
int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');
	BTNode* G = CreateTreeNode('G');


	A->left = B;
	A->right = C;
	B->left = D;
	B->right = G;
	C->left = E;
	C->right = F;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	//int size = 0;
	//TreeSize(A, &size);
	//printf("TreeSize:%d\n", size);

	//size = 0;
	//TreeSize(A, &size);
	//printf("TreeSize:%d\n", size);

	
	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeSize:%d\n", TreeSize(A));

	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(A, 3));
	printf("TreeFind:%p\n", TreeFind(A, 'E'));
	printf("TreeFind:%p\n", TreeFind(A, 'X'));

	TreeLevelOrder(A);

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A));

	BinaryTreeDestory(A);
	A = NULL;

	return 0;
}