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
//	struct stu s = { "����", 20, 88.5f };
//	FILE* pa = fopen("data.txt", "wb");  //�Զ����Ƶ���ʽд�ļ�
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//д�ļ�
//		fwrite(&s, sizeof(struct stu), 1, pa);
//	}
//	fclose(pa);
//	pa = NULL;
//	return 0;
//}
//int main()
//{
//	struct stu s = { 0 };
//	FILE* pa = fopen("data.txt", "rb");  //�Զ����Ƶ���ʽ���ļ�
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//���ļ�
//		fread(&s, sizeof(struct stu), 1, pa);
//		printf("%s %d %f\n", s.name, s.age, s.score); //�ж��Ƿ����ȷ�����Դ�ӡ����
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
		printf("�ļ�д��ɹ�!\n");
		fclose(pa);
		pa = NULL;
	}
	return 0;
}