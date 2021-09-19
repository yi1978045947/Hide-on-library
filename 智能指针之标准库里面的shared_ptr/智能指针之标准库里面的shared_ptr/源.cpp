#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
#include<memory>

int main()
{
	// shared_ptr通过引用计数支持智能指针对象的拷贝

	shared_ptr<int> sp1(new int);
	shared_ptr<int> sp2(sp1);
	sp2 = sp1;
	return 0;
}