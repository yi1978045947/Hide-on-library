#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
int main()
{
	//以下三种方式开辟空间和释放空间的效果是一样的
	int* p1 = (int*)malloc(sizeof(int));      //malloc和free
	free(p1);

	int* p2 = new int;                        //new和delete
	delete p2;

	int* p3 = (int*)operator new(sizeof(int));//operator new与operator delete
	operator delete (p3);
	return 0;
}