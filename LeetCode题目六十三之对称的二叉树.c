#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return _isSymmetric(q->left, p->right) && _isSymmetric(q->right,  p->left);
}
bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	return _isSymmetric(root->left, root->right);
}
int main()
{
	return 0;
}