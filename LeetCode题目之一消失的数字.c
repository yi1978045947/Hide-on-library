#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int MissingNumber(int nums[], int sz) //解法1所以数之和减去少一个数的和，复杂度1-n那就是n
{
	int i = 0;
	int j = 0;
	int sum1 = 0;
	int sum2 = 0;
	int newlen = sz + 1;
	for (i = 0; i < newlen; i++) 
	{
		sum1 = sum1 + i;  //0到n的和
	}
	for (j = 0; j < sz; j++)
	{
		sum2 = sum2 + nums[j]; //数组的和
	}
	return sum1 - sum2; 
} 
int MissingNumber(int nums[], int sz) //解法2异或，复杂度n+n+1=2n+1那么复杂度就是n
{
	int x = 0;
	int newlen = sz + 1;
	int i = 0;
	for (i = 0; i < newlen; i++)
	{
		x = x^i;   
	}
	for (i = 0; i < sz; i++)
	{
		x = x^nums[i];
	}
	return x;
}
int main()
{
	int nums[] = {0,1, 2, 3, 4, 6, 7 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int digit = MissingNumber(nums, sz);
	printf("%d\n", digit);
}