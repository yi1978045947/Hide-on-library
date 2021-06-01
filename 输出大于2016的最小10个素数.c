#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int index = 0;  //数组下标
	int arr[10]; //容量为10数组
	int n = 0;   //你要输入的值
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 2016; i < n; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d ", arr[index++] = j); //放到数组里面
		}
		if (index == 10)                //数组元素为10，那么退出程序
		{
			break;
		}
	}
	printf("\n");
	return 0;
}