#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
int main()
{
	//1byte == 8bit
	//	1KB = 1024byte
	//	1MB = 1024KB
	//	1GB = 1024MB
	//	1TB = 1024GB

	void* p1 = malloc(0xffffffff);
	cout << p1 << endl;
	return 0;
}