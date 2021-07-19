#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<queue>
#include<functional>
using namespace std;
void test_priority_queue()
{
	//priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	cout << pq.size() << endl;
	cout << pq.empty() << endl;
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
int main()
{
	test_priority_queue();
	return 0;
}