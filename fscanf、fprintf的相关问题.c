#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<errno.h>
#include<string.h>
struct stu
{
	char name[20];
	int age;
	float score;
};
//int main()   //fprintf的相关问题
//{
//	struct stu s = { "鱼王", 20, 66.5f };
//	struct stu* pb = &s;
//	FILE* pa = fopen("data.txt", "w"); //打开文件
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else                             //格式化的写入文件
//	{
//		fprintf(pa, "%s %d %f", pb->name, pb->age, pb->score);
//		printf("文件写入成功!\n");
//		//printf("%s %d %f\n", s.name, s.age, s.score);
//	}
//	fclose(pa);                     //关闭文件
//	pa = NULL;
//	return 0;
//}

int main()  //fscanf的相关问题
{
	struct stu s = { 0 };
	struct stu* pb = &s; 
	FILE* pa = fopen("data.txt", "r");
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else    //格式化的读取，fscanf在文件流上读取数据到文件中在printf打印输送到屏幕上
	{
		fscanf( pa,"%s%d%f", pb->name, &(pb->age), &(pb->score));
		//fscanf( stdin, "%s%d%f", pb->name, &(pb->age), &(pb->score)); //也可以从键盘上读取
		printf("%s %d %f\n", s.name, s.age, s.score);
		//fprintf(stdout, "%s %d %f\n", s.name, s.age, s.score);
	}
	fclose(pa);
	pa = NULL;
	return 0;
}