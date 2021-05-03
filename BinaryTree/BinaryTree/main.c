#define _CRT_SECURE_NO_WARNINGS   1
#include"BinaryTree.h"
int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');
	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(A, 2));
	printf("BinaryTreeFind:0x%p\n", BinaryTreeFind(A,'B'));
	printf("BinaryTreeFind:0x%p\n", BinaryTreeFind(A,'G'));
	BinaryTreeLevelOrder(A);
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A));
	BinaryTreeDestory(A);
	A = NULL;
	return 0;
}