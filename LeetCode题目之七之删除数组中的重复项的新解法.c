#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize < 2)
	{
		return numsSize;
	}
	int index = 0;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] != nums[index])
		{
			nums[++index] = nums[i];
		}
	}
	return index + 1;
}
int main()
{
	int nums[] = { 1, 2, 3, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = removeDuplicates(nums, numsSize);
	printf("%d\n", ret);
	return 0;
}