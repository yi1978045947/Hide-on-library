#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//��������:����ĳ������ʱ�Ͳ�����룬����������ʱ�Ͳ��������
#define __DEBUG__ 1
#define PRINT 1
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
#ifdef  __DEBUG__
		printf("bit education\n");
#endif
	}

#ifdef PRINT    //����
	printf("����\n");
#endif
#ifndef PRINT  //����
	printf("������\n");
#endif

#if defined PRINT    //����
	printf("bit\n");
#endif
#if !defined PRINT  //����
	printf("bit��\n");
#endif

#if 5-3
	printf("bit NB\n");
#elif 5-5
	printf("bit CA\n");
#elif
	printf("�Ǻ�\n");
#endif
	return 0;
}

//��������������ָ�

//1.
//#if �������ʽ
////... 
//#endif //�������ʽ��Ԥ��������ֵ��
//�磺
//#define __DEBUG__ 1 
//#if __DEBUG__ 
////.. 
//#endif 

//2.�����֧����������
//#if �������ʽ
////... 
//#elif �������ʽ
////... 
//#else 
////... 
//#endif 

//3.�ж��Ƿ񱻶���
//#if defined(symbol) 
//#ifdef symbol 
//#if !defined(symbol) 
//#ifndef symbol 

//4.Ƕ��ָ��
//#if defined(OS_UNIX) 
//#ifdef OPTION1 
//unix_version_option1();
//#endif 
//#ifdef OPTION2 
//unix_version_option2();
//#endif 
//#elif defined(OS_MSDOS) 
//#ifdef OPTION2 
//msdos_version_option2();
//#endif 
//#endif