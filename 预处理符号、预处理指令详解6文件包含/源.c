#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include"��ͷ.h" //ͷ�ļ��İ���->�൱�ڽ����˺���������
#include<stddef.h>
#define MY_OFFSET0F(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)
struct stu
{
	char c;
	int i;
	double d;
};
int main()
{
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	printf("%d\n", sum);
	printf("%d\n", offsetof(struct stu, c));
	printf("%d\n", offsetof(struct stu, i));
	printf("%d\n", offsetof(struct stu, d));	
	printf("%d\n", MY_OFFSET0F(struct stu, c));
	printf("%d\n", &(((struct stu*)0)->c));
	printf("%d\n", MY_OFFSET0F(struct stu, i));
	printf("%d\n", MY_OFFSET0F(struct stu, d));
	return 0;
}
//#include<stdio.h>Ӧ����c�����ṩ�Ŀ⺯����ͷ�ļ������ʹ��<>,������ֱ��ȥ��Ŀ¼��Ѱ��
//#include"��ͷ.h" Ӧ�����Զ����ͷ�ļ������ʹ��"",����ȥ��ǰ���̵�Ŀ¼�²��ң�����Ҳ�������ȥ��Ŀ¼�²���
//��ǰĿ¼ : D : \visua stdio 2013����\Ԥ������š�Ԥ����ָ�����6�ļ�����\Ԥ������š�Ԥ����ָ�����6�ļ�����
//
//	ÿ��ͷ�ļ��Ŀ�ͷд��
//#ifndef __TEST_H__ 
//#define __TEST_H__ 
//	ͷ�ļ�������
//#endif //__TEST_H__ 
//   ���ߣ�
//#pragma once 
//	�Ϳ��Ա���ͷ�ļ����ظ����롣