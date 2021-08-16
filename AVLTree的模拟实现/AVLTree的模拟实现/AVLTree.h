#include<iostream>
#include<map>
using namespace std;
#pragma once 

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;   //该节点的左孩子
	AVLTreeNode<K, V>* _right;  //该节点的右孩子
	AVLTreeNode<K, V>* _parent; //该节点父亲

	int _bf;  //平衡因子

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
		//按照搜索树插入新节点
		if (_root == nullptr)   //此时为一个空树
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;  //父节点连接起来
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

		cur = new Node(kv);  //插入新节点
		if (parent->_kv.first < kv.first)  //新插入的节点的key值大于parent节点，就插到parent节点的右边
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else                             //插入到parent节点的左边
		{
			parent->_left = cur;
			cur->_parent = parent;
		}


		//更新平衡因子
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
				//说明parent所在的子树高度不变，更新结束
				break;
			}
			else if (-1 == parent->_bf || 1 == parent->_bf)
			{
				//说明parent所在的子树高度变量，需要更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (-2 == parent->_bf || 2 == parent->_bf)
			{
				//parent所在的子树出现问题了，需要旋转处理一下
				//旋转前提是保持他依旧是搜索二叉树
				//旋转成平衡二叉树
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

				//旋转完成之后，parent所在树的高度恢复到了，插入节点的新高度
				//如果是子树，对上层影响，更新结束
				break;
			}
		}
		return true;
	}

	void RotateL(Node* parent)  //左旋转
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

		//1.原来 parent是这颗树的根，现在subR是根
		//2.parent为根的树只是整颗树中的子树，改变链接关系，那么subR要顶替它的位置

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

	void RotateR(Node* parent)   //右旋转
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;  //旋转过后节点的指向
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

	//旋转路径是单线就是双旋
	//旋转路径是折线就是双旋
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
	void InOrder()     //中序遍历
	{
		_InOrder(_root);   //类里面可以拿到_root
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