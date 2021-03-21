#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))  //(((a++)>(b++)?(a++):(b++)))
int main()
{
	int a = 10;
	int b = 20;
	int m = 5;
	int n1 = m+1;  
	printf("m=%d,n1=%d\n", m, n1);
	int n2 = ++m;                //此时m为带有副作用，因为m的值也在变
	printf("m=%d,n1=%d\n", m, n2);
	int ret = MAX(a++, b++);
	printf("a=%d,b=%d\n", a, b);
	printf("ret=%d\n", ret);
	return 0;
}
当宏参数在宏的定义中出现超过一次的时候，如果参数带有副作用，那么你在使用这个宏的时候就可能出现危险，导致不可预测的后果。
副作用就是表达式求值的时候出现的永久性效果。

宏和函数的对比
1. 用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。所以宏比函数在程序
的规模和速度方面更胜一筹。
2. 更为重要的是函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用。反之这个宏怎可
以适用于整形、长整型、浮点型等可以用于来比较的类型。宏是类型无关的。

当然和宏相比函数也有劣势的地方：
1. 每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
2. 宏是没法调试的。
3. 宏由于类型无关，也就不够严谨。
4. 宏可能会带来运算符优先级的问题，导致程容易出现错。