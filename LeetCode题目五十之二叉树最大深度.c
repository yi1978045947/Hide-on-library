#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int RightDepth = maxDepth(root->left);
	int LeftDepth = maxDepth(root->right);
	return RightDepth > LeftDepth ? RightDepth + 1 : LeftDepth + 1;
}
int main()
{
	return 0;
}