#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//1.����test���������ʲô���
//void GetMemory(char* p)// �������
//{
//	p = (char*)malloc(100);
//}
//void test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//	printf("\n");
//}
//int main()
//{
//	test();
//	return 0;
//}
//
//void GetMemory(char** p)  //��ȷ����
//{
//	*p = (char*)malloc(100);
//}
//void test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	printf("\n");
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//2.test()�������г���ʲô���
//char* GetMemory()  //�������
//{
//    char p[] = "bit education";
//	return p;
//}
//void test()
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//	printf("\n");
//}
//int main()
//{
//	test();
//}

//char* GetMemory()  //��ȷ����
//{
//	static char p[] = "bit education";
//	return p;
//}
//void test()
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//	printf("\n");
//}
//int main()
//{
//	test();
//}

//3.test()�������еĽ����ʲô
//void GetMemory(char** p, int num) //������룬�������У������ڴ�й©
//{
//	*p = (char*)malloc(num);
//}
//void test()
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "bit education"); 
//	printf(str);
//	printf("\n");
//}
//int main()
//{
//	test();
//	return 0;
//}

//void GetMemory(char** p, int num) 
//{
//	*p = (char*)malloc(num);
//	free(p);
//	p = NULL;
//}
//void test()
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "bit education");
//	printf(str);
//	printf("\n");
//}
//int main()
//{
//	test();
//	return 0;
//}

//4.test()�������еĽ����ʲô

void test()
{
	char* str = (char*)malloc(100);
	strcpy(str, "bit");
	free(str);  
	if (str != NULL)
	{
		strcpy(str, "education");
		printf(str);
		printf("\n");
	}
}
int main()
{
	test();
	return 0;
}
















//struct s
//{
//	int a;
//	char b[0];
//};
//int main()
//{
//	printf("%d\n", sizeof(struct s));
//	return 0;
//}