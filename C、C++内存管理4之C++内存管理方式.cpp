#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
int main()
{
	int* p1 = new int;                        //C++��̬������һ��int���͵Ŀռ�
	int* p2 = (int*)malloc(sizeof(int*));     //C��̬����һ��int���͵Ŀռ�
	delete p1;
	free(p2);

	int* p3 = new int[10];                    //C++��̬����10��int���͵Ŀռ�
	int* p4 = (int*)malloc(sizeof(int*)* 10); //C��̬����1��int���͵Ŀռ�
	delete[] p3;
	free(p4);

	int* p5 = new int(1);                      //C++��̬����1��int���͵Ŀռ䲢�ҳ�ʼ��Ϊ1
	int* p6 = new int[3]{1, 2, 3};             //C++��̬����3��int���͵Ŀռ䲢�ҳ�ʼ��
	delete p5;
	delete[] p6;
	return 0;
}
