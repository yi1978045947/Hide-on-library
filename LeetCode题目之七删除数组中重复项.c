#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int RemoveElement(int arr[], int sz)
{
	if (sz == 0)
	{
		return 0;
	}
	int dest = 0;
	int cur = 0;
	int next = 1;
	while (next < sz)
	{
		if (arr[cur] != arr[next])
		{
			arr[dest] = arr[cur];
			dest++;
			cur++;
			next++;
		}
		else
		{
			while ( next<sz && arr[cur] == arr[next])
			{
				next++;		
			}
			arr[dest] = arr[cur];
			dest++;
			cur = next;
			next++;
		}
	}
	if (cur < sz)
	{
		arr[dest] = arr[cur];
		dest++;
	}
	return dest;
}
int main()
{
	int arr[] = { 1, 1, 2, 3, 4, 5, 5, 6, 7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = RemoveElement(arr, sz);
	printf("%d\n", ret);
	return 0;
}