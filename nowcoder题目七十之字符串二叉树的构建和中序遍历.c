#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct TreeNode
{
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* CreateTreeNode(char* str, int *pi)
{
	assert(str);
	if (str[*pi]=='#')
	{
		(*pi)++;
		return NULL;
	}
	//����������ĸ��ڵ�
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = str[*pi];
	(*pi)++;
	//�����������������
	root->left = CreateTreeNode(str, pi);
	//�����������������
	root->right = CreateTreeNode(str, pi);
	return root;
}
void Inorder(struct TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);
	printf("%c ", root->val);
	Inorder(root->right);
}
int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	struct TreeNode* root = CreateTreeNode(str, &i);
	Inorder(root);
	printf("\n");
	return 0;
}