#define _CRT_SECURE_NO_WARNINGS   1
#include<math.h>
#include<stdio.h>
#include<stdbool.h>
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
bool _isBalanced(struct TreeNode* root,int* depth)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (root == NULL)
	{
		*depth = 0;
		return true;
	}
	//后序遍历，从左子树遍历开始，在右子树
	if (_isBalanced(root->left, &leftHeight) == false)
	{
		return false;
	}
	if (_isBalanced(root->right,&rightHeight)==false)
	{
		return false;
	}
	*depth = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	return abs(leftHeight - rightHeight);
}
bool isBalanced(struct TreeNode* root)
{
	int depth = 0;
	return _isBalanced(root, &depth);
}
int main()
{
	return 0;
}