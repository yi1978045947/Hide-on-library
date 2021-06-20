#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
// 1.malloc/calloc/realloc的区别是什么
int main()
{
	int* p1 = (int*)malloc(sizeof(int)*10);
	int* p2 = (int*)calloc(4,sizeof(int));
	int* p3 = (int*)realloc(p1, sizeof(int) * 200);
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	//free(p1);
	free(p2);
	free(p3);
	return 0;
}