#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<set>   //底层是树形结构的平衡二叉树

using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(6);
	s.insert(7);
	s.insert(4);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	set<int>::iterator pos1 = s.find(3);
	if (pos1 != s.end()) //有元素才删除
	{
		s.erase(pos1);
	}

	s.erase(5);
	//s.erase(100);

	set<int>::iterator pos2 = find(s.begin(), s.end(), 7);
	s.erase(pos2);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.erase(s.begin(), s.end());
}
void test_set2()
{
	set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(6);
	s.insert(7);
	s.insert(4);
	cout << s.size() << endl;
	cout << s.empty() << endl;
}
void test_set3()
{
	set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(6);
	s.insert(7);
	s.insert(4);
	set<int> copy(s);
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test_set1();   
	test_set2();
	test_set3();
	return 0;
}