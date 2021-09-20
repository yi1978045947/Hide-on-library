#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
#include<memory>
int main()
{
	unique_ptr<int> up1(new int);
	// unique_ptr的设计思路非常的粗暴-防拷贝，也就是不让拷贝和赋值
	
	unique_ptr<int> up2(up1);

	unique_ptr<int> up3(new int);
	up3 = up1;
	return 0;
}