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
	if (q->val != p->val)
	{
		return false;
	}
	return __isSymmetric(q->left, p->right) && __isSymmetric(q->right, p->left);
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

�ݹ���ѵ����ڣ��ҵ����Եݹ�ĵ� Ϊʲô�ܶ��˾��õݹ�һ���ͻᣬһд�ͷϡ� ����˵���Լ�д�޷�д�������ؼ�������Եݹ�������

���ڴ��⣺ �ݹ�ĵ���ô�ң����õ���ĵ�һʱ�俪ʼ��˼·���£�

1.��ô�ж�һ�����ǲ��ǶԳƶ������� �𰸣�����������ڵ㣬Ϊ�գ���ô�ǶԳơ������Ϊ�յĻ������������������������Գ�ʱ�����Գ�

2.��ô��ô֪�����������������Բ��Գ��أ�������ֱ�ӽ�Ϊ���������� �𰸣�����������������������Һ��ӶԳƣ��������Һ��������������ӶԳƣ���ô��������������ͶԳơ�

��ϸ����仰���ǲ����е��ƣ���ô�о���һ������A����ʵ�֣�����ȥʵ��A��ʱ����Ҫ�õ�Aʵ�ֺ�Ĺ����أ�

����˼���������ʱ�򣬵ݹ���Ѿ������ˣ� �ݹ�㣺���ڳ����ж������������ԳƵ�����ʱ��������������ĺ��ӵĶԳ�����й�ϵ��