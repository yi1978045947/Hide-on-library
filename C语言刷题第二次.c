#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>

//int main()  //���뻺�����ĸ���,Ҫ�Ȱ�\n�ַ���ȡ��
//{
//	char password[20];
//	printf("�������������:>");
//	scanf("%s", password);
//	printf("��ȷ��(Y/N):>");
//	getchar();
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�!\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��!\n");
//	}
//	return 0;
//}

//int main() //7.��ӡ�ɻ�ͼ��
//{
//	printf("     **     \n");
//	printf("     **     \n");
//	printf("************\n");
//	printf("************\n");
//	printf("    *  *    \n");
//	printf("    *  *    \n");
//	return 0;
//}

//int main() //8.ʮ��������ABCDEF��ӡ��ʮ��������ָ�����Ϊ15
//{
//	printf("%15d\n", 0xABCDEF);
//	return 0;
//}

//int main()  //9.��ӡhello world�ķ���ֵ,printf���ص����ַ��ĸ���
//{
//	/*printf("%d\n", (printf("%d", printf("%d"), 43)));*/
//	int ret = printf("hello world");
//	printf("\n");
//	printf("%d\n", ret);
//	return 0;
//}

//int main() //10.ѧ��������Ϣ�������������������ѧ����ѧ�ţ����Ƴɼ�
//{
//	int id = 0;
//	double C = 0.0;
//	double math = 0.0;
//	double chinese = 0.0;
//	scanf("%d%lf%lf%lf", &id, &C, &math, &chinese);
//	printf("The each subject score of NO. %d is %.2lf,%.2lf,%.2lf\n", id, C, math, chinese);
//	return 0;
//}

//int main() //11.�������룬ÿ�����һ���ַ�
//{
//	int ch = 0;//�ַ���˹�������������Դ�ŵ�int������
//	while ((ch = getchar()) != EOF)
//	{
//		if ((ch >= 'A'&&ch<='Z')||(ch>='a'&&ch<='z'))
//		{
//			printf("Y\n");
//		}
//		else
//		{
//			printf("N\n");
//		}
//		getchar();//���������\n
//	}
//	return 0;
//}

//int main() //12.����һ���ַ�������һ��������
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		//��ӡ�ո�
//		for (j = 0; j < n - i - 1; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ�ַ�
//		for (j = 0; j <= i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main() //13.ת�������Ŀ�и���������ASCII���ַ�
//{
//	char arr[] = { 73, 72, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

//int main() //14.����ֻ��һ�У��������ڣ����������գ�����������û�зָ���,ע���ʽ����
//{
//	int year = 0;
//	int month = 0;
//	int date = 0;
//	scanf("%4d%2d%2d", &year, &month, &date);
//	printf("year=%4d\n", year);
//	printf("month=%02d\n", month);
//	printf("date=%02d\n", date);
//	return 0;
//}

int main() //15.�������룬ÿһ������һ����������2��n�η�
{
	int n = 0;
	int sum = 0;
	while (scanf("%d", &n)!=EOF)
	{
		sum = 1 << n;
	}
	printf("%d\n", sum);
	return 0;
}