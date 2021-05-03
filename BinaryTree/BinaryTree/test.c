#include"BinaryTree.h"
BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
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
void BinaryTreeLevelOrder(BTNode* root)
{
	struct Queue q;
	QueueInit(&q);
	if (root)        //根不为空，把根入队列
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q); //出队头的数据，根数据
		QueuePop(&q);                   //把数据从队头弹出去
		printf("%c ", front->data);
		if (front->left)               //把根的下一层就是左右字树数据入进去
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
}
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right,k-1);
}
BTNode* BinaryTreeFind(BTNode* root, int x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* Lret = BinaryTreeFind(root->left, x);
	if (Lret)
	{
		return Lret;
	}
	BTNode*  Rret = BinaryTreeFind(root->right, x);
	if (Rret)
	{
		return Rret;
	}
	return NULL;
}
bool BinaryTreeComplete(BTNode* root)
{
	struct Queue q;
	QueueInit(&q);
	if (root)  //根节点不为空,入队列
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q)) //遍历树直到找到第一个空节点
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
	while (!QueueEmpty(&q))  //因为上次循环由于碰到NULL退出来，在写层循环如果没有碰到非空，则是完全二叉树，否则不是
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			return false;
		}
	}
	return true;
}