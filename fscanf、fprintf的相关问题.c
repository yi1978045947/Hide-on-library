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
//int main()   //fprintf���������
//{
//	struct stu s = { "����", 20, 66.5f };
//	struct stu* pb = &s;
//	FILE* pa = fopen("data.txt", "w"); //���ļ�
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else                             //��ʽ����д���ļ�
//	{
//		fprintf(pa, "%s %d %f", pb->name, pb->age, pb->score);
//		printf("�ļ�д��ɹ�!\n");
//		//printf("%s %d %f\n", s.name, s.age, s.score);
//	}
//	fclose(pa);                     //�ر��ļ�
//	pa = NULL;
//	return 0;
//}

int main()  //fscanf���������
{
	struct stu s = { 0 };
	struct stu* pb = &s; 
	FILE* pa = fopen("data.txt", "r");
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else    //��ʽ���Ķ�ȡ��fscanf���ļ����϶�ȡ���ݵ��ļ�����printf��ӡ���͵���Ļ��
	{
		fscanf( pa,"%s%d%f", pb->name, &(pb->age), &(pb->score));
		//fscanf( stdin, "%s%d%f", pb->name, &(pb->age), &(pb->score)); //Ҳ���ԴӼ����϶�ȡ
		printf("%s %d %f\n", s.name, s.age, s.score);
		//fprintf(stdout, "%s %d %f\n", s.name, s.age, s.score);
	}
	fclose(pa);
	pa = NULL;
	return 0;
}