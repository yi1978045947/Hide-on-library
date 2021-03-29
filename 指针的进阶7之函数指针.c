#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
void test1(int* pa)
{

}
void test2(int(*pc)[5])
{

}
int add(int x, int y)
{
	return x + y;
}
int my_strlen(const char* str)
{
	int count = 0;
	assert(str);
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}
int main()
{
	int arr1[10];    //一维数组
	int* pa = arr1;  //首元素的地址
	int(*pb)[10] = &arr1;  //整个数组的地址
	test1(arr1);

	int arr2[3][5];
	int(*pc)[5] = arr2;  //首元素的地址，二维数组首元素的地址代表第一行的地址，所以用数组指针接收
	int(*pd)[3][5] = &arr2;
	test2(arr2);


	//整形指针---->存放整形的地址
	//数组指针---->存放数组的地址
	//函数指针---->存放函数的地址
	int a = 10;
	int* pe = &a;
	char arr3[10] = { 0 };
	char(*pf)[10] = &arr3;

	printf("%p\n", &add);
	printf("%p\n", add);  //&函数名和函数名都是函数的地址
	int(*pg)(int, int) = &add;  //pg就是函数指针
	int(*ph)(int, int) = add;  //ph和pg表达的意思一样

	//函数指针的调用
	int sum = (*pg)(2, 3); //==  int usm=add(2,3);
	int ret = (pg)(2, 3);
	printf("%d\n", ret);
	printf("%d\n", sum);

	int(*str)(const char*) = &my_strlen;
	int len = (*str)("bit education");
	printf("%d\n", len);

	//类型在()里面就是强制类型转换-->把0强制类型转换为函数指针类型，然后解引用调用0地址处的函数，该函数返回值为void，参数为无参数
	(*(void(*)())0) ();

	//这是一个函数声明
	//声明的函数是signal,signal函数有两个参数，第一个参数类型是int,第二个参数类型是函数指针
	//该函数的返回值是空，参数是int
	//signal函数的返回类型是一个函数指针，该函数指针指向的函数参数是int，返回类型是void
	void(*signal (int, void(*)(int)) ) (int);   //void(*)(int) signal(int, void(*)(int));
	/*void(*)(int) 起一个别名-->pfun_t;
	typedef void(*pfun_t)(int);
	pfun_t signal(int, pfun_t);
	*/
	return 0; 
}