#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _inorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	_inorderTraversal(root->left, arr, pi);
	arr[(*pi)++] = root->val;
	_inorderTraversal(root->right, arr, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	_inorderTraversal(root, arr, &i);
	return arr;
}
int main()
{
	return 0;
}