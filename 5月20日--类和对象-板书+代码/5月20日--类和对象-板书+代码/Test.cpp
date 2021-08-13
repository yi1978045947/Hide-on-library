#include<iostream>
using namespace std;

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//
//	//// 在语法上，这里给a这块空间取了一个别名，没有新开空间
//	//int& ra = a;
//	//ra = 20;
//
//	//// 在语法上，这里定义个pa指针变量，开了4个字节，存储a的地址
//	//int* pa = &a;
//	//*pa = 20;
//
//	//int b = 10;
//	//int*& rpa = pa;
//	//rpa = &b;
//
//	int* p = NULL;
//	int*& rp = p;
//
//	cout << rp << endl;
//
//	return 0;
//}

//void Swap(int& a, int& b)
//{
//	int c = a;
//	a = b;
//	b = c;
//}
//
////
//// C语言为了小函数避免建立栈帧的小号，-》提供宏函数支持，预处理阶段展开
//// 既然C语言已经解决了，为什么C++还要提供inline函数呢？（宏函数的缺点）面试题考点
//// a：不支持调试  b：宏函数语法复杂，容易出错  c：没有类型安全的检查
//// 写一个ADD的宏函数
//// 
//
//// #define ADD(int x, int y) return x + y 典型的错误写法
//// 不能带分号
//// #define ADD(x, y) x+y;
//// #define ADD(x, y) (x)+(y)
//#define ADD(x, y) ((x)+(y))
//
//int main()
//{
//	int x = 0, y = 1;
//	Swap(x, y);
//
//	ADD(1, 2); // x+y;;
//	if (ADD(1,2))
//	{}
//
//	ADD(1, 2) * 4; // (1)+(2)*4;
//
//	return 0;
//}

// C++推荐频繁调用的小函数，定义成inline，会在调用的地方展开，没有栈帧开销
// 能不能所有函数都inline？
//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int c = Add(1, 2);
//	cout << c << endl;
//
//	return 0;
//}

// 以下语法，了解一下就ok
// auto
#include <map>
#include <string>
//int main()
//{
//	//int a = 10;
//	////int b = a;
//	//auto b = a; // 类型声明成auto，可以根据a的类型自动推导b的类型
//	//map<string, string> m;
//	////map<string, string>::iterator it = m.begin();
//	//// 这里可以根据m.begin()自动推导it的类型是map<string, string>::iterator，写起来比较简洁
//	//auto it = m.begin();
//	int x = 10;
//	auto a = &x;  // int* 
//	auto* b = &x; // int*
//	int& y = x;   // y的类型是什么？int
//	auto c = y;  // int 
//	auto& d = x; // d的类型是int， 但是这里指定了d是x的引用
//
//	// 打印变量的类型
//	cout << typeid(x).name() << endl;
//	cout << typeid(y).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;
//}

//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		cout << array[i] << " ";
//	cout << endl;
//
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//
//	// 范围for C++11新语法遍历，更简单，数组都可以
//	// 自动遍历，依次取出array中的元素，赋值给e，直到结束
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//
//	for (auto ee : array)
//	{
//		cout << ee << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}

//void f(int i)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int* p)
//{
//	cout << "f(int*)" << endl;
//}
//
////#ifndef NULL
////#ifdef __cplusplus
////#define NULL    0
////#else
////#define NULL    ((void *)0)
////#endif
////#endif
//
//// C++11
//int main()
//{
//	int* p1 = NULL; //  int* p1 = 0; 
//	int* p2 = nullptr;
//
//	f(0);
//	f(NULL);
//	f(nullptr);
//
//	return 0;
//}

typedef int STDataType;

// c语言
// 数据
//struct Stack
//{
//	STDataType* a;
//	int size;
//	int capacity;
//};
//// 函数方法 -- 数据和方法是分离的，重点关注的是过程-》函数方法
//void StackPush(struct Stack* ps, STDataType x);

// C++
// 类  -定义出一个新的类型
// 类由两部分构成：1、成员变量 (属性) 2、成员函数 (做的行为)
// C++中的struct兼容C的所有用法，同时C++中把struct升级成类
//struct Stack
//{
//	void Init(int initSize = 4)
//	{
//		a = (STDataType*)malloc(sizeof(STDataType) * initSize);
//		size = 0;
//		capacity = initSize;
//	}
//
//	void Push(STDataType x)
//	{
//		// ...
//		a[size] = x;
//		size++;
//	}
//
//	// ...
//
//	STDataType* a;
//	int size;
//	int capacity;
//};
//
//int main()
//{
//	//struct Stack st;
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	return 0;
//}

// xxx.h
// 在类设计中，一般情况，想给别人的(成员函数)访问定义成共有
//                       不想给别人访问(成员变量)的就定义成私有或保护
//struct Stack
class Stack
{
	void Pop()
	{}
public:
	void Init(int initSize = 4);
	void Push(STDataType x);

	// ...

private:
	STDataType* a; // 成员变量在这里是声明
	int size;
	int capacity;
};

// xxx.cpp
void Stack::Init(int initSize)
{
	a = (STDataType*)malloc(sizeof(STDataType) * initSize);
	size = 0;
	capacity = initSize;
}

void Stack::Push(STDataType x)
{
	// ...
	a[size] = x;
	size++;
}

//int main()
//{
//	//struct Stack st;
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	//st.size++;
//	//st.Pop();
//
//	Stack s1;
//	Stack s2;
//
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//
//
//
//	return 0;
//}

class A1 {
public:
	void f1(){}
private:
	int _a;
};

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 空类
class A3
{};

int main()
{
	cout << sizeof(A1) << endl;
	A1 aa;
	aa.f1();

	// 他们的大小是1，为什么呢？ 大小是1，给1个byte不是为了存储数据，是占位，表示对象存在过
	A2 a2;
	A2 aa2;
	A2 aaa2;
	cout << sizeof(a2) << endl;
	cout << &a2 << endl;
	cout << &aa2 << endl;
	cout << &aaa2 << endl;

	A3 a3;
	cout << sizeof(a3) << endl;

	return 0;
}