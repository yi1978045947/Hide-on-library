#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int left = 0;
	int right = numsSize - 1;
	int* str = (int*)malloc(sizeof(int)* 2);
	*returnSize = 2;
	while (left < right)
	{
		if (nums[left] + nums[right] == target)
		{
			str[0] = nums[left];
			str[1] = nums[right];
			return str;
		}
		else if (nums[left] + nums[right]>target)
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	return NULL;
}
int main()
{
	return 0;
}