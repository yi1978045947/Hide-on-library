#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
int TreeDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	int diff = left - right;
	if (diff > 1 || diff < -1)
	{
		return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);
}
int main()
{
	return 0;
}