int search(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid]>target)
		{
			right = mid - 1;
		}
		else if (nums[mid]<target)
		{
			left = mid + 1;
		}
		else
		{
			 while(nums[mid-1]==nums[mid])
			 {
			     mid=mid-1;
			 }
			return mid;
		}
	}
	return -1;
}
int main()
{
	int nums[] = { 1, 2, 2, 3, 4, 5 };
	int target = 2;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = search(nums, numsSize, target);
	printf("%d\n", ret);
}