#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
void f()
{
	// 他的用法跟malloc和free是完全一样的，功能都是在堆上申请释放空间
	// 失败了处理方式不一样，malloc失败返回NULL，operator new失败以后抛异常
	void* p3 = malloc(0x7fffffff);
	if (p3 == NULL)
	{
		cout << "malloc fail" << endl;
	}
	void* p4 = operator new(11);
	char* p5 = new char[0x7fffffff];
	cout << "继续" << endl;
}
int main()
{
	try
	{
		f();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

