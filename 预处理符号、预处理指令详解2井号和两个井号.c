#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#define print(format,data)  printf("the value of "#data" is "format"\n",data)
                                                //"data" == #data�Ѳ������뵽�ַ�����
int main()
{
	float f = 4.5f;
	print("%f",f);
	printf("the value of f is %f\n", f);

	int a = 10;
	print("%d", a);
	printf("the value of a is %d\n", a);

	int b = 20;
	print("%d", b);
	printf("the value of b is %d\n", b);
	return 0;
}

##���԰�λ�������ߵķ��źϳ�һ������,������궨��ӷ�����ı�Ƭ�δ�����ʶ��,���������ӱ������һ���Ϸ��ı�ʶ����������������δ����ġ�

#define CAT(X,Y) X##Y
int main()
{
	int Class100 = 1000;
	printf("%d\n", CAT(Class, 100));
	return 0;
}