#define _CRT_SECURE_NO_WARNINGS   1
//#include<stdio.h>  ��������Ϸ
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
//		printf("��������Ҫ�µ�����:>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���!\n");
//		}
//		else if (guess < ret)
//		{
//			printf("��С��!\n");
//		}
//		else
//		{
//			printf("�¶���!\n");
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
//		printf("��ѡ��(1/0):>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ!\n");
//			break;
//		default:
//			printf("������������������!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//#include<stdio.h> ��߷���
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

//#include<stdio.h>  ��Сд��ĸת��
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