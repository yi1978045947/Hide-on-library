#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == val)
			count++;
		else
			nums[i - count] = nums[i];
	}
	return numsSize - count;
}
int main()
{
	int nums[] = { 1, 2, 3, 2, 2, 4, 5, 6, 7 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int val = 2;
	int ret = removeElement(nums, numsSize, val);
	printf("%d\n", ret);
}