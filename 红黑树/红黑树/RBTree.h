#include<iostream>
using namespace std;

#pragma once 

enum Color
{
	BLACK,
	RED,
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	
	pair<K, V> _kv;

	Color _col;

	RBTreeNode(const pair<K,V>& kv,Color col=RED)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(col)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:

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

	}
	bool Insert(const pair<K, V>& kv)
	{
		//�����������Ĺ�����в���
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK; //���ڵ���ɫ����BLACK 
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)  //�ҵ���λ��
		{
			if (cur->_kv.first < kv.first)
			{
				//�����ڵ����ӵ�һ��
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);//����Ľڵ�͸��ڵ���������,����������
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//�²���Ľڵ���ɫ��ʲô��ɫ ��-->���
		cur->_col = RED;

		while (parent&&parent->_col == RED)
		{
			//������ĵ��ڹؼ�������

			Node* grandfather = parent->_parent; 
			//���1�����uncle������Ϊ��ɫ
			//���2or3��uncle�����ڻ���uncle������Ϊ��
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle&&uncle->_col == RED)         
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//���3:˫��->��ɵ���
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//���2(�п����ǵ��������������
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				//���1�����uncle������Ϊ��ɫ
				//���2or3��uncle�����ڻ���uncle������Ϊ��
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������滹�нڵ�
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//���3:˫��->��ɵ���
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}

					//���2(�п����ǵ��������������
					RotateL(grandfather);

					grandfather->_col = RED;
					parent->_col = BLACK;
				}
			}

		}


		_root->_col = BLACK; //���������ڵ�ʲô��ɫ����������ɺ�ɫ
		return  true;
	}

	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_InOrder(_root->_left);
		std::cout << _root->_kv.first << ":" << _root->_kv.second << endl;
		_InOrder(_root->_right);
	}
	void InOrder()     //�������
	{
		_InOrder(_root);   //����������õ�_root
	}

	Node* Find(const K& key)  //������Ĳ���
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}

private:
	Node* _root = nullptr;
};
void TestRBTree()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> RBT;
	for (auto e : a)
	{
		RBT.Insert(make_pair(e, e));
	}
	RBT.InOrder();
}