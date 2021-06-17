#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<stdlib.h>
int main()
{
	int a = 1;
	int b = 2;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;

	void* p1 = malloc(10);
	void* p2 = realloc(p1, 200);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;

	int* c = (int*)malloc(sizeof(int));
	int* d = (int*)malloc(sizeof(int));
	std::cout << c << std::endl;
	std::cout << d << std::endl;


	return 0;
}