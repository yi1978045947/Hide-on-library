#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
int my_atoi(char* pa)
{
	int ret = 0; //����ֵ
	int sign = 1; //��־����
	assert(pa);
	while (*pa == ' ') //����ǰ��Ŀո��ַ�
	{
		pa++;
	}
	if (*pa == '-')	//�ж�������
	{
		sign = -1;
	}
	if (*pa == '-' || *pa == '+') //��������
	{
		pa++;
	}
	if (*pa >= '9' || *pa <= '0') //�������������ַ��������� / 0��ʱ������ת��
	{
		return 0;
	}
	while (*pa >= '0'&&*pa <= '9') //�����������ַ�ʱ���������ַ�ת������������������������ֵ��ret
	{
		ret = ret * 10 + *pa-'0' ; //
		pa++;
	}
	ret = ret*sign;
	return ret;
}
int main()  //atoi�ַ���ת��Ϊ����
{
	char a[] = "-10";
	char b[] = "20";
	int c = my_atoi(a) + my_atoi(b);
	printf("a:%d\n", my_atoi(a));
	printf("b:%d\n", my_atoi(b));
	printf("a+b=%d\n", c);
	return 0;
}
//1.�ȴ���ո�
//2.�����Ŵ���
//3.���ִ���