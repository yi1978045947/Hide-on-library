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

	}
	bool Insert(const pair<K, V>& kv)
	{
		//按照搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK; //根节点颜色整成BLACK 
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)  //找到空位置
		{
			if (cur->_kv.first < kv.first)
			{
				//跟父节点连接到一起
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

		cur = new Node(kv);//插入的节点和父节点连接起来,构成搜索树
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

		//新插入的节点颜色给什么颜色 ？-->红的
		cur->_col = RED;

		while (parent&&parent->_col == RED)
		{
			//红黑树的调节关键看叔叔

			Node* grandfather = parent->_parent; 
			//情况1，如果uncle存在且为红色
			//情况2or3，uncle不存在或者uncle存在且为黑
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle&&uncle->_col == RED)         
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//情况3:双旋->变成单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//情况2(有可能是第三种情况变来的
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				//情况1，如果uncle存在且为红色
				//情况2or3，uncle不存在或者uncle存在且为黑
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//可能上面还有节点
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//情况3:双旋->变成单旋
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}

					//情况2(有可能是第三种情况变来的
					RotateL(grandfather);

					grandfather->_col = RED;
					parent->_col = BLACK;
				}
			}

		}


		_root->_col = BLACK; //不管最后根节点什么颜色，都把它变成黑色
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
	void InOrder()     //中序遍历
	{
		_InOrder(_root);   //类里面可以拿到_root
	}

	Node* Find(const K& key)  //红黑树的查找
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