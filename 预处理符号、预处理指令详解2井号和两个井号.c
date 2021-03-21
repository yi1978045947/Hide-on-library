#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#define print(format,data)  printf("the value of "#data" is "format"\n",data)
                                                //"data" == #data把参数插入到字符串中
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

##可以把位于它两边的符号合成一个符号,它允许宏定义从分离的文本片段创建标识符,这样的连接必须产生一个合法的标识符。否则其结果就是未定义的。

#define CAT(X,Y) X##Y
int main()
{
	int Class100 = 1000;
	printf("%d\n", CAT(Class, 100));
	return 0;
}