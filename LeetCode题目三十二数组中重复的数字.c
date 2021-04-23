#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int findRepeatNumber(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp_int);
	int i = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == nums[i + 1])
		{
			return nums[i];
		}
	}
	return -1;
}
int main()
{
	return 0;
}
