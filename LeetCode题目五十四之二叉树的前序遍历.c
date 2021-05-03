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
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _preorderTraversal(struct TreeNode* root, int* arr, int *pi)
{
	if (root == NULL)
	{
		return;
	}
	arr[(*pi)++] = root->val;
	_preorderTraversal(root->left, arr, pi);
	_preorderTraversal(root->right, arr, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	if (root == NULL)
	{
		return NULL;
	}
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	_preorderTraversal(root, arr, &i);
	return arr;
}
int main()
{
	return 0;
}