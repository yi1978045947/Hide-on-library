#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//int main()  //malloc������ʹ��
//{
//	/*int nums = 0;
//	scanf("%d", &nums);*/
//	int arr[10] = { 0 }; //��ջ��������40���ֽڵĿռ�
//	int* pa = (int*)malloc(sizeof(int)* 10); //�ڶ�������40���ֽڵĿռ�
//	if (pa == NULL)//����ʧ��
//	{
//		printf("�ڴ濪��ʧ��!\n");
//	}
//	else //���ٳɹ�
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(pa + i) = 0;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		printf("\n");
//		//����ʹ��ָ��pa��ָ��Ķ�̬�ڴ�
//		//�ֶ��ͷŶ�̬���ٵ��ڴ�
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//int main()  //calloc������ʹ��
//{
//	int* pa = (int*)calloc(10, sizeof(int)); //calloc������������(����������������С(�ֽ�Ϊ��λ))
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));//����ʧ�ܣ���strerror���ش������Ϣ
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(pa + 1));
//		}
//		printf("\n");
//		//�ռ䲻���ˣ����ӿռ䣬�����ռ�Ĵ�С��realloc
//		int* pb = (int*)realloc(pa, 80); //���µ�ָ�������վɵ�ָ��,realloc�������������µ�ָ��paָ���µ��ڴ棬��size��������´�С��
//		if (pb != NULL)
//		{
//			pa = pb;
//		}
//		for (i = 0; i < 20; i++)
//		{
//			printf("%d ", pb[i]);
//		}
//		printf("\n");
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//malloc������calloc����������
//1.������������ͬ��malloc��������ֻ��һ������������calloc�����������������Ͳ�����С����λ���ֽ�
//2.��ʼ����ͬ,malloc�������ٵĿռ�ʱ�򲻳�ʼ���ģ���calloc�������ٵĿռ��ǳ�ʼ����

//��̬�ڴ����
//1.��NULLָ����н����ò���
//int main()
//{
//	int* pa = (int*)malloc(INT_MAX);
//	if (pa == NULL)//û���ж�pa�Ƿ�Ϊ��
//	{
//		printf("����ʧ��!\n");
//	}
//	else
//	{
//		*pa = 0;
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//2.�Կ��ٿռ��Խ�����
//int main()
//{
//	int* pa =(int*) malloc(10 * sizeof(int));
//	if (pa == NULL)
//	{
//		printf("����ʧ��!\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i <= 11; i++)//���ٿռ�ʱԽ�����
//		{
//			*(pa + i) = 0;
//		}
//		for (i = 0; i <= 11; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//3.�ԷǶ�̬���ٵĿռ�ʹ��free�ͷ�
//int main()
//{
//	int a = 1;
//	int* pa = &a;
//	free(pa);
//	pa = NULL;
//	free(pa);
//}

//4.ʹ��free�ͷ�һ�鶯̬�ڴ濪�ٵĿռ�
//int main()
//{
//	int* pa = (int*)malloc(sizeof(int)* 10);
//	if (pa == NULL)
//	{
//		printf("���ٿռ�ʧ��!\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*pa++ = 0;
//		}
//		for (i = 0; i < 5; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

////5.��ͬһ���ڴ����ͷ�
//int main()
//{
//	int* pa = (int*)malloc(sizeof(int)* 10);
//	if (pa == NULL)
//	{
//		printf("����ʧ��!\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(pa + i) = 0;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		free(pa);
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//6.�Կ��ٵ��ڴ�ռ������ͷ�,�ڴ�й©����
int main()
{
	int* pa = (int*)malloc(sizeof(int)* 10);
	if (pa == NULL)
	{
		printf("����ʧ��!\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(pa + i) = 0;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", pa[i]);
		}
		return 0;
		//δʹ��free���ͷſ��ٵ��ڴ�ռ�
	}
	return 0;
}