#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
struct stu
{
	char name[20];
	int age;
	float score;
};
int main() //sprintf�ļ���д�뵽һ������������
{
	struct stu s = { "����", 20, 65.5f };
	char buff[200] = { 0 };
	//sprintf���԰�һ���ṹ��������ת��Ϊһ���ַ���
	sprintf(buff, "%s %d %f", s.name, s.age, s.score);
	printf("%s\n", buff); //�ӻ�����������ļ���ȡ����Ļ��

	struct stu tmp = { 0 };
	//scanf���԰�һ���ַ���ת��Ϊһ���ṹ��������
	sscanf(buff, "%s%d%f", tmp.name, &(tmp.age), &(tmp.score));
	printf("%s %d %f\n", tmp.name, tmp.age, tmp.score);
	return 0;
}

//����scanf,printf,fscanf,fprintf,sscanf,sprintf
//1.scanf��printf�����ڱ�׼������������ĸ�ʽ������������
//2.fscanf��fprintf���������еı�׼����������ĸ�ʽ������������
//3.sscanf��sprintf���԰ѽṹ��������ת��Ϊ�ַ�����Ҳ���԰��ַ����ж�ȡ��ʽ��������
//��ʽ������:ĳ�����ݵĸ�ʽ