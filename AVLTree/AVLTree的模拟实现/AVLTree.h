#include<iostream>
#include<map>
using namespace std;
#pragma once 

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;   //�ýڵ������
	AVLTreeNode<K, V>* _right;  //�ýڵ���Һ���
	AVLTreeNode<K, V>* _parent; //�ýڵ㸸��

	int _bf;  //ƽ������

	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V>  Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//���������������½ڵ�
		if (_root == nullptr)   //��ʱΪһ������
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;  //���ڵ���������
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first <= kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);  //�����½ڵ�
		if (parent->_kv.first < kv.first)  //�²���Ľڵ��keyֵ����parent�ڵ㣬�Ͳ嵽parent�ڵ���ұ�
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else                             //���뵽parent�ڵ�����
		{
			parent->_left = cur;
			cur->_parent = parent;
		}


		//����ƽ������
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else if (cur == parent->_left)
			{
				parent->_left--;
			}
			else if (0 == parent->_bf)
			{
				//˵��parent���ڵ������߶Ȳ��䣬���½���
				break;
			}
			else if (-1 == parent->_bf || 1 == parent->_bf)
			{
				//˵��parent���ڵ������߶ȱ�������Ҫ����
				cur = parent;
				parent = parent->_parent;
			}
			else if (-2 == parent->_bf || 2 == parent->_bf)
			{
				//parent���ڵ��������������ˣ���Ҫ��ת����һ��
				//��תǰ���Ǳ���������������������
				//��ת��ƽ�������
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}

				//��ת���֮��parent�������ĸ߶Ȼָ����ˣ�����ڵ���¸߶�
				//��������������ϲ�Ӱ�죬���½���
				break;
			}
		}
		return true;
	}

	void RotateL(Node* parent)  //����ת
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;

		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		//1.ԭ�� parent��������ĸ�������subR�Ǹ�
		//2.parentΪ������ֻ���������е��������ı����ӹ�ϵ����ôsubRҪ��������λ��

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left = parent)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}

		parent->_bf = 0;
		subR->_bf = 0;
	}

	void RotateR(Node* parent)   //����ת
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;  //��ת����ڵ��ָ��
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}

			subL->_parent = parent;
		}

		parent->_bf = 0;
		subL->_bf = 0;
	}

	//��ת·���ǵ��߾���˫��
	//��ת·�������߾���˫��
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;
		}


	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}
	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_InOrder(_root->_left);
		std::cout << _root->_kv.first<< ":"<<_root->_kv.second<<endl;
		_InOrder(_root->_right);
	}
	void InOrder()     //�������
	{
		_InOrder(_root);   //����������õ�_root
		std::cout << std::endl;
	}


	int MaxDepth(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int leftDepth = MaxDepth(root->_left);
		int rightDepth = MaxDepth(root->_right);
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	bool IsBalanceTree(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}
		int leftDepth = MaxDepth(root->_left);
		int rightDepth = MaxDepth(root->_right);
		if (abs(leftDepth - rightDepth) < 2)
		{
			return true;
		}
		return IsBalanceTree(root->_left) && IsBalanceTree(root->_right);
	}
private:
	Node* _root = nullptr;
};