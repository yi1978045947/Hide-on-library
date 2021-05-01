#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int cmp_int(const void* e1, const void* e2)
{
	int aa = *(int*)e1;
	int bb = *(int*)e2;
	if (aa > bb)
	{
		return 1;
	}
	else if (aa<bb)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int singleNumber(int* nums, int numsSize)
{
	if (numsSize <= 3)
	{
		return nums[0];
	}
	qsort(nums, numsSize, sizeof(int), cmp_int);
	int i = 0;
	for ( i = 1; i < numsSize - 1; i++)
	{
		if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
		{
			return nums[i];
		}
	}
	if (nums[0] != nums[1])
	{
		return nums[0];
	}
	if (nums[numsSize - 1] != nums[numsSize - 2])
	{
		return nums[numsSize - 1];
	}
	//if (nums[i - 1] != nums[i - 2])
	//{
	//	return nums[i - 1];
	//}
}
int main()
{
	int nums[] = { 1, 2, 3, 2, 1, 1, 2, 4, 4, 4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = singleNumber(nums, numsSize);
	printf("%d\n", ret);
	return 0;
}