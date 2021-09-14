#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<memory>
using namespace std;

// shared_ptr的缺陷：可能会引起循环引用

// 到底什么是循环引用？------- 例子：
//struct ListNode
//{
//	ListNode* next;
//	ListNode* prev;
//	int data;
//};
struct ListNode
{
	//shared_ptr<ListNode> next;
	//shared_ptr<ListNode> prev;
	weak_ptr<ListNode> next;
	weak_ptr<ListNode> prev;
	int data;

	ListNode(int x)
		: data(x)
		/*: next(nullptr)
		, prev(nullptr)
		, data(x)*/
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}
};

void TestLoopRef()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;    // 1
	cout << sp2.use_count() << endl;    // 1

	sp1->next = sp2;
	sp2->prev = sp1;

	cout << sp1.use_count() << endl;    // 2
	cout << sp2.use_count() << endl;    // 2
}

int main()
{
	// 编译失败----不能独立管理资源--->只能配合shared_ptr使用，来解决shared_ptr中存在的循环引用的问题
	// weak_ptr<int> wp(new int);
	TestLoopRef();
}
