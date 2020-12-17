#include <stdio.h>
#include<stdlib.h>

int cmp_int(const void* e1, const void* e2)
{
	return *(int *)e1 - *(int *)e2;
}

int cmp_float(const void* e1, const void* e2)
{
	return *(float*)e1 - *(float*)e2;
}
void test1()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}

void test2()
{
	float s[] = { 10.0,9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0 };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_float);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%f ", s[j]);
	}
	printf("\n");
}

int main()
{
	test1();
	test2();
}