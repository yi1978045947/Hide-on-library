#define _CRT_SECURE_NO_WARNINGS   1
#include"AVLTree.h"

int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();
	//cout << t.IsBalanceTree() << endl;
	return 0;
}