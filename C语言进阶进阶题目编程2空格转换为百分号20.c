#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
void ReplaceSpace(char* str, int length)
{
	int i = 0;
	int spacecount = 0;
	for (i = 0; i < length; i++) //1.ͳ�ƿո����
	{
		if (str[i] == ' ')
		{
			spacecount++;
		}
	}
	int newlen = length + 2 * spacecount; //2.����滻��%20���ַ����µĳ��ȵ����λ��
	int pos = newlen - 1;  //�������һ���ַ����±�
	for (i = length - 1; i >= 0; i--) //3.�Ӻ���ǰ����ո�
	{
		if (str[i] == ' ')
		{
			str[pos--] = '0';
			str[pos--] = '2';
			str[pos--] = '%';
		}
		else //���ǿո����ԭ���ַ����¿�����ȥ��arr�ĺ���
		{
			str[pos--] = str[i];
		}
	}
}
int main()
{
	char arr[1024] = "we are happy.";
	int len = strlen(arr);
	ReplaceSpace(arr, len);
	printf("%s\n", arr);
	return 0;
}