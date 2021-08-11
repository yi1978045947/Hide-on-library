#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
struct stu
{
	char name[20];
	int age;
	float score;
};
//int main()
//{
//	struct stu s = { "鱼王", 20, 88.5f };
//	FILE* pa = fopen("data.txt", "wb");  //以二进制的形式写文件
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//写文件
//		fwrite(&s, sizeof(struct stu), 1, pa);
//	}
//	fclose(pa);
//	pa = NULL;
//	return 0;
//}
//int main()
//{
//	struct stu s = { 0 };
//	FILE* pa = fopen("data.txt", "rb");  //以二进制的形式读文件
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//读文件
//		fread(&s, sizeof(struct stu), 1, pa);
//		printf("%s %d %f\n", s.name, s.age, s.score); //判断是否读正确，所以打印出来
//	}
//	fclose(pa);
//	pa = NULL;
//	return 0;
//}

int main()
{
	int a = 10000;
	FILE* pa = fopen("bin.bat", "wb");
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		fwrite(&a, sizeof(int), 1, pa);
		printf("文件写入成功!\n");
		fclose(pa);
		pa = NULL;
	}
	return 0;
}