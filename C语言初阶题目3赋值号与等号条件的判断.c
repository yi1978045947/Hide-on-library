#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int x = 0;
	int y = 0;
	int count = 0;
	for (x = 0, y = 0; (y = 123) && (x < 4); x++)  //ע��y=123�Ǹ�ֵ�ţ����ǵ��ں�
	{
		count++;
	}
	printf("%d\n", count);
	return 0;
}