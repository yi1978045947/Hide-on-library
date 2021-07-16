#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

template<class T>
T FindKey(T* arr, int sz,T key )
{
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;	
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 10;
	int ret = FindKey(arr, sizeof(arr) / sizeof(arr[0]), key);
	cout << ret << endl;
	return 0;
}