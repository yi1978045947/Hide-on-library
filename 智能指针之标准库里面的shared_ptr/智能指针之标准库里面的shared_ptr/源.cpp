#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
#include<memory>

int main()
{
	// shared_ptrͨ�����ü���֧������ָ�����Ŀ���

	shared_ptr<int> sp1(new int);
	shared_ptr<int> sp2(sp1);
	sp2 = sp1;
	return 0;
}