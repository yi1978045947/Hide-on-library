#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<time.h>
void menu()
{
	printf("*****************************\n");
	printf("*******      1.Play      ****\n");
	printf("*******      0.Exit      ****\n");
	printf("*****************************\n");
}
void game()
{
	int i = 0;
	int ret = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你要猜测的数字:>");
		scanf("%d", &i);
		if (i > ret)
		{
			printf("猜大了哦!\n");
		}
		else if (i < ret)
		{
			printf("猜小了哦!\n");
		}
		else if (i == ret)
		{
			printf("恭喜你,猜对了!\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //生成随机数
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出程序!\n");
			break;
		default :
			printf("选择错误，请重新输入!\n");
			break;
		}
	} while (input);
	return 0;
}