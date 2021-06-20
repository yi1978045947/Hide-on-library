#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
int main()
{
	int* p1 = new int;                        //C++动态的申请一个int类型的空间
	int* p2 = (int*)malloc(sizeof(int*));     //C动态申请一个int类型的空间
	delete p1;
	free(p2);

	int* p3 = new int[10];                    //C++动态申请10个int类型的空间
	int* p4 = (int*)malloc(sizeof(int*)* 10); //C动态申请1个int类型的空间
	delete[] p3;
	free(p4);

	int* p5 = new int(1);                      //C++动态申请1个int类型的空间并且初始化为1
	int* p6 = new int[3]{1, 2, 3};             //C++动态申请3个int类型的空间并且初始化
	delete p5;
	delete[] p6;
	return 0;
}
