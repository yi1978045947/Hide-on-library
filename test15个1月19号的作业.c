#define _CRT_SECURE_NO_WARNINGS   1
//#include<stdio.h>  猜数字游戏
//#include<time.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("***************************\n");
//	printf("********  1.play  *********\n");
//	printf("********  2.exit  *********\n");
//	printf("***************************\n");
//}
//void game()
//{
//	int ret = 0;
//	int guess = 0;
//	ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("请输入你要猜的数字:>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了!\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了!\n");
//		}
//		else
//		{
//			printf("猜对了!\n");
//			return 0;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do{
//		menu();
//		printf("请选择(1/0):>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏!\n");
//			break;
//		default:
//			printf("输入有误，请重新输入!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//#include<stdio.h> 最高分数
//int compare(int a, int b, int c, int tmp)
//{
//	if (a>b&&a>c)
//	{
//		tmp = a;
//	}
//	else if (b>a&&b>c)
//	{
//		tmp = b;
//	}
//	else if (c>b&&c>a)
//	{
//		tmp = c;
//	}
//	return tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int max = 0;
//	int tmp = 0;
//	while (scanf("%d%d%d", &a, &b, &c) != EOF)
//	{
//		max = compare(a, b, c, tmp);
//		printf("%d\n", max);
//	}
//	return 0;
//}

//#include<stdio.h>  大小写字母转换
//int main()
//{
//	char letter = '0';
//	while (scanf("%c", &letter) != EOF)
//	{
//		if (letter >= 'A' && letter <= 'Z')
//		{
//			printf("%c\n", letter + 32);
//		}
//		else if (letter >= 'a' && letter <= 'z')
//		{
//			printf("%c\n", letter - 32);
//		}
//	}
//	return 0;
//}