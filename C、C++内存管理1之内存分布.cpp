#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string.h>
int globalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof (int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
	std::cout << "sizeof(num1):" <<sizeof(num1) << std::endl;
	std::cout << "sizeof(char2):"<<sizeof(char2) << std::endl;
	std::cout << "strlen(char2):" << strlen(char2) << std::endl;
	std::cout << "sizeof(pChar3):" << sizeof(pChar3) << std::endl;
	std::cout << "strlen(pChar4):" << strlen(pChar3) << std::endl;
	std::cout << "sizeof(ptr1):" << sizeof(ptr1) << std::endl;
}
int main()
{
	Test();
	return 0;
}