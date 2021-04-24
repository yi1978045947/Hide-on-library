#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int search(int* nums, int numsSize, int target)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == target)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int nums[] = { 1, 3, 4, 5, 6, 4, 3, 5 };
	int target = 4;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = search(nums, numsSize, target);
	printf("%d\n", ret);
	return 0;
}