#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
	{
		return true;
	}
	if (q == NULL || p == NULL)
	{
		return false;
	}
	if (q->val != p->val)
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
}
int main()
{
	return 0;
}