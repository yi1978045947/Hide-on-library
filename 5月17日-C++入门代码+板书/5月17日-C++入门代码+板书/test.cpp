// C++ 兼容C的语法
//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//
//	return 0;
//}

// C/C++

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}

// namespace 定义的是一个域
// 解决C语言命名冲突问题
//#include <stdio.h>
//
//int main()
//{
//	// 命名冲突
//	// C语言的库里面，有两个函数用scanf和strlen名称
//	// 假设我的代码里面想用这个两个名称命名变量
//	int scanf = 10;
//	int strlen = 20;
//
//	// C语言解决不了冲突的问题
//	scanf("%d", &scanf);
//
//	printf("%d\n", scanf);
//	printf("%d\n", strlen);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include "List.h"
//
//// 命名冲突
//// C语言的库里面，有两个函数用scanf和strlen名称
//// 假设我的代码里面想用这个两个名称命名变量
//// 域
//namespace bit
//{
//	int scanf = 10;
//	int strlen = 20;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	// 嵌套定义命名空间
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//
//		// 还可以再套
//	}
//}
//
//int main()
//{
//	// C语言解决不了冲突的问题
//	// C++,命名空间，名字隔离
//	//scanf("%d", &scanf);
//
//	// 默认访问的布局或者全局
//	printf("%x\n", scanf);
//	printf("%x\n", strlen);
//
//	// 指定访问bit命名空间中
//	printf("%x\n", bit::scanf);
//	printf("%x\n", bit::strlen);
//	bit::Add(1, 2);
//	bit::N3::Sub(10, 3);
//	bit::ListNode* phead = NULL;
//
//	return 0;
//}
//

//#include <iostream.h>  // 老一点的C++标准用的这个，VC6.0可以用，没有std命名空间

//#include <iostream>
//#include <vector>
//#include <string>
//// C++库为了防止命名冲突，把自己库里面的东西都定义在一个std的命名空间中
//// 要使用标准库中的东西，有三种方式
//// 1、指定命名空间 -> 麻烦，每个地方要用都要指定，到那时他是最规范的方式
//// 2、把std整个展开，相当于库里面的东西都到全局域了 -> 
//// 看起来方便了，如果我们自己定义的东西跟库冲突了就没办法解决了。
//// 一夜回到解放前，所以规范的工程项目中是不推荐这种方式的。 -》日常练习就可以用
////using namespace std;
//
//// 3、对部分常用的库里面的东西展开 -> 针对1和2折中方案，项目中也会经常用
//using std::cout;
//using std::endl;
//
//int a = 0;
//
//int main()
//{
//	// 1、指定命名空间 -> 麻烦，每个地方要用都要指定，到那时他是最规范的方式
//	std::cout << "hello world" << std::endl;
//	std::vector<int> v;
//	std::string s;
//
//	cout << "hello world" << endl;
//
//	int a = 1;
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;

// cout 现在其实讲不清楚，我们储备知识还不足、大家先了解一下，记住他的使用
// ostream 类型全局对象 cout
// istream 类型全局对象 cin
// endl 全局的换行符号

//int main()
//{
//	std::cout << "hello world";
//	std::cout << "hello world" << std::endl << std::endl;
//
//	// 对比C语言printf scanf区别是什么 -》 自动识别类型(原理：函数重载+运算符重载，以后再介绍)
//	int a = 10;
//	int* p = &a;
//	printf("%d,%p\n", a, p);
//	std::cout << a << "," << p << std::endl;
//
//	char str[10];
//	std::cin >> a;
//	std::cin >> str;
//	std::cout << a << str << std::endl;
//
//	return 0;
//}

struct Person
{
	char name[10];
	int age;
};

//int main()
//{
//	int a = 0;
//	cin >> a;			// scanf("%d", &a);
//	cout << a << endl;
//
//	struct Person p = {"小李", 10};
//	printf("name:%s\nage:%d\n", p.name, p.age); // 格式化输出
//	cout << "name:" << p.age << "\n" << "age:" << p.age << endl;
//	// 建议：可以混着用，哪个好用就用哪个
//
//	return 0;
//}

// 缺省参数
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	TestFunc(10);
//	TestFunc();
//
//	return 0;
//}

//// 全缺省
//void TestFunc(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	TestFunc(1, 2, 3);
//	TestFunc();
//	TestFunc(1);
//	TestFunc(1,2);
//
//	return 0;
//}

// 半缺省
//void TestFunc(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//// 缺省参数的作用是什么，调用更灵活
//
//int main()
//{
//	TestFunc(1);
//	TestFunc(1, 2);
//	TestFunc(1, 2, 3);
//
//	return 0;
//}
//struct Stack
//{
//	int* a;
//	int size;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps, int InitCapacity = 4)
//{
//	ps->a = (int*)malloc(sizeof(int) * InitCapacity);
//	ps->size = 0;
//	ps->capacity = InitCapacity;
//}
//
//// 缺省参数-》调用时更灵活
//int main()
//{
//	struct Stack st1;
//	// 假设我知道栈里面至少要存100个数据
//	StackInit(&st1, 100);
//
//
//	struct Stack st2;
//	// 假设我知道栈里面最多要存10个数据
//	StackInit(&st2, 10);
//
//	struct Stack st3;
//	// 假设我不知道栈里面可能存多少数据
//	StackInit(&st2);
//
//	return 0;
//}

// C语言不允许定义同名函数
// C++可以-》函数重载 -》函数名相同，参数不同  （参数类型不同、或者个数不同）
//int Add(int left, int right)
//{
//	return left + right;
//}

//int Add(int left = 10, int right = 20)
//{
//	return left + right;
//}
//
//char Add(char left, char right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//// 构成重载，但是他是一个坑
//void f(int a, int b, int c = 1)
//{}
//
//void f(int a, int b)
//{}
//
//int main()
//{
//	cout << Add() << endl;
//	cout << Add(1, 2) << endl;  // 字面量  给的整形默认算常量
//	cout << Add('1', '2') << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	f(1, 2, 3);
//	// f(1, 2);
//
//	return 0;
//}

//void swap(int* a, int* b)
//{
//	// ...
//}
//
//void swap(double* a, double* b)
//{
//	// ...
//}
//
//// 学习这些细碎的语法
//// 1、这些语法一定程序是再对c语言的一些不好用地方做补充
//// 2、学习这些，也在为我们学习C++类和对象做铺垫
//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//
//	double m = 1.1, n = 2.2;
//	swap(&m, &n);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	// b是a的引用(别名)
//	int& b = a;
//	b = 20;
//
//	int& c = b;
//	c = 30;
//
//	return 0;
//}

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void swap(int& r1, int& r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

struct Stack
{
	int* a;
	int size;
	int capacity;
};

void StackInit(struct Stack* ps)
{}

void StackInit(struct Stack& s)
{}

int main()
{
	int a = 1, b = 2;
	swap(&a, &b);
	swap(a, b);

	struct Stack st;
	StackInit(&st);

	StackInit(st);

	return 0;
}