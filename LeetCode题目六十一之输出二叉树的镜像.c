#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* mirrorTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	root->left = mirrorTree(root->left);
	root->right = mirrorTree(root->right);
	return root;
}
int main()
{
	return 0;
}