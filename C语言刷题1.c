#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdio.h>
//int main()//  1.��v�Ĵ�ӡ
//{
//	printf("v   v\n v v\n  v\n");
//	return 0;
//}

//int main()  //2.ת���ַ���ʹ��
//{
//	printf("%d\n", strlen("c:\test\040\test.c"));
//	return 0;
//}

//int main()  //3.�������μ������ڴ��еĴ�С
//{
//	printf("The sizeof of char is %d bytes\n", sizeof(char));
//	printf("The size of short is %d bytes\n", sizeof(short));
//	printf("The size of int is %d bytes\n", sizeof(int));
//	printf("The size of long is %d bytes\n", sizeof(long));
//	printf("The size of long long is %d bytes\n", sizeof(long long));
//	printf("The size of double is %d bytes\n", sizeof(double));
//}

//int main()  //4.��ӡ10������1234��8���ƺ�16����
//{
//	printf("0%o 0x%X\n", 1234, 1234);
//	return 0;
//}

//int main()  //5.���������������1234���������4321��������һ����õ�������λģ������
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

int main()  //6.�����������ʵ����ĸ��Сд��ת��
{
	//int ch = getchar();
	//ch = ch + 32;
	//putchar(ch);
	//printf("\n");
	//return 0; //ֻ������һ���ַ�
	int ch = 0;  //getchar��putchar���ڻ��������ȡ�ַ�
	while ((ch = getchar())!=EOF)
	{
		printf("%c\n", ch + 32);
		getchar();
	}
	return 0;//��������ַ�
}

