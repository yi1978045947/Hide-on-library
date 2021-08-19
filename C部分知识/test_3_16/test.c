#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include "add.h"
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//先声明后使用
//	int c = Add(a, b);
//	printf("c = %d\n", c);
//
//	return 0;
//}

//
//编辑器：vim
//


//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%s\n", __FUNCTION__);
//		/*printf("file:%s - line=%d date=%s time=%s : i=%d\n", 
//			   __FILE__, __LINE__, __DATE__, __TIME__, i);*/
//	}
//	return 0;
//}


//int main()
//{
//	//ANSI C的支持是不好的
//	printf("%d\n", __STDC__);
//
//	return 0;
//}


#include <stdio.h>

//#define定义标识符
//
//#define MAX 100
//
//#define STR "HEHE"
//#define reg register
//#define print printf("hehe\n")
//
//int main()
//{
//	reg int age;
//
//	printf("%d\n", MAX);//100
//	printf("%s\n", STR);//HEHE
//	print;//hehe
//	return 0;
//}


#include <stdio.h>

//#define SQUARE(X)  ((X)*(X))
//
//#define MAX 100
//
//#define DOUBLE(X) ((X)+(X))
//
//int main()
//{
//	printf("MAX = %d\n", MAX);
//	printf("%d\n", 2 * DOUBLE(5));
//	printf("%d\n", 2 * ((5)+(5)));
//	//printf("%d\n", SQUARE(3+2));//25?
//
//	//printf("%d\n", (3 + 2) * (3 + 2));
//	//printf("%d\n", 3 + 2 * 3 + 2);//11
//
//	//printf("%d\n", 3 * 3);
//
//	return 0;
//}

//
//#define print(data, format)  printf("the value of "#data" is "format"\n", data)
//                                                  //"data"
//int main()
//{
//	float f = 4.5f;
//	print(f, "%f");
//	//printf("the value of f is %f\n", f);
//
//	int a = 10;
//	print(a, "%d");
//	//printf("the value of a is %d\n", a);
//
//	int b = 20;
//	print(b, "%d");
//
//	//printf("the value of b is %d\n", b);
//
//	return 0;
//}

//int main()
//{
//	printf("hello world\n");
//	printf("hello " "world\n");
//
//	return 0;
//}

#define CAT(X,Y) X##Y


int main()
{
	int Class100 = 1000;
	//class 100
	printf("%d\n", CAT(Class, 100));

	return 0;
}