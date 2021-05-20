#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>  //老的编译器用iostream.h

//C++为了防止命名冲突，把自己库里面的东西都定义在一个std的命名空间中
//要使用标准库里面的东西，有三种方式
//1.指定命名空间--麻烦，每个地方都要指定，但也是最规范的方式
int c = 100;
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
//2.把std整个展开，相当于库里面的东西全部到全局域里面去了，使用起来方便
//但是可能会有与自己命名空间定义的冲突，规范工程中不推荐这种，日常练习可以用这种
using namespace std;

//3.对部分常用的库里面的东西展开->针对1和2的折中方案，项目中也经常使用
using std::cout;
using std::endl;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::b);
	printf("%d\n", N::Add(1, 2));
	printf("%d\n", N::Sub(1, 2));
	int c = 10;
	printf("%d\n", c);   //局部变量优先，所以c为10
	printf("%d\n", ::c); //指定访问左边域，空白表示全局域
}