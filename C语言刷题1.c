#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdio.h>
//int main()//  1.大v的打印
//{
//	printf("v   v\n v v\n  v\n");
//	return 0;
//}

//int main()  //2.转义字符的使用
//{
//	printf("%d\n", strlen("c:\test\040\test.c"));
//	return 0;
//}

//int main()  //3.计算整形家族在内存中的大小
//{
//	printf("The sizeof of char is %d bytes\n", sizeof(char));
//	printf("The size of short is %d bytes\n", sizeof(short));
//	printf("The size of int is %d bytes\n", sizeof(int));
//	printf("The size of long is %d bytes\n", sizeof(long));
//	printf("The size of long long is %d bytes\n", sizeof(long long));
//	printf("The size of double is %d bytes\n", sizeof(double));
//}

//int main()  //4.打印10进制数1234的8进制和16进制
//{
//	printf("0%o 0x%X\n", 1234, 1234);
//	return 0;
//}

//int main()  //5.反向输出，如输入1234，反向输出4321，或者另一个题得到二进制位模二除二
//{
//	int n = 0;
//	scanf("%d", &n);
//	while (n)
//	{
//		printf("%d ", n % 10);
//		n = n / 10;
//	}
//	return 0;
//}

int main()  //6.多组输入输出实现字母大小写的转换
{
	//int ch = getchar();
	//ch = ch + 32;
	//putchar(ch);
	//printf("\n");
	//return 0; //只能输入一个字符
	int ch = 0;  //getchar和putchar是在缓冲区里读取字符
	while ((ch = getchar())!=EOF)
	{
		printf("%c\n", ch + 32);
		getchar();
	}
	return 0;//输入多组字符
}

