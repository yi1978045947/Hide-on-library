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
//	//// ���﷨�ϣ������a���ռ�ȡ��һ��������û���¿��ռ�
//	//int& ra = a;
//	//ra = 20;
//
//	//// ���﷨�ϣ����ﶨ���paָ�����������4���ֽڣ��洢a�ĵ�ַ
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
//// C����Ϊ��С�������⽨��ջ֡��С�ţ�-���ṩ�꺯��֧�֣�Ԥ����׶�չ��
//// ��ȻC�����Ѿ�����ˣ�ΪʲôC++��Ҫ�ṩinline�����أ����꺯����ȱ�㣩�����⿼��
//// a����֧�ֵ���  b���꺯���﷨���ӣ����׳���  c��û�����Ͱ�ȫ�ļ��
//// дһ��ADD�ĺ꺯��
//// 
//
//// #define ADD(int x, int y) return x + y ���͵Ĵ���д��
//// ���ܴ��ֺ�
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

// C++�Ƽ�Ƶ�����õ�С�����������inline�����ڵ��õĵط�չ����û��ջ֡����
// �ܲ������к�����inline��
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

// �����﷨���˽�һ�¾�ok
// auto
#include <map>
#include <string>
//int main()
//{
//	//int a = 10;
//	////int b = a;
//	//auto b = a; // ����������auto�����Ը���a�������Զ��Ƶ�b������
//	//map<string, string> m;
//	////map<string, string>::iterator it = m.begin();
//	//// ������Ը���m.begin()�Զ��Ƶ�it��������map<string, string>::iterator��д�����Ƚϼ��
//	//auto it = m.begin();
//	int x = 10;
//	auto a = &x;  // int* 
//	auto* b = &x; // int*
//	int& y = x;   // y��������ʲô��int
//	auto c = y;  // int 
//	auto& d = x; // d��������int�� ��������ָ����d��x������
//
//	// ��ӡ����������
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
//	// ��Χfor C++11���﷨���������򵥣����鶼����
//	// �Զ�����������ȡ��array�е�Ԫ�أ���ֵ��e��ֱ������
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

// c����
// ����
//struct Stack
//{
//	STDataType* a;
//	int size;
//	int capacity;
//};
//// �������� -- ���ݺͷ����Ƿ���ģ��ص��ע���ǹ���-����������
//void StackPush(struct Stack* ps, STDataType x);

// C++
// ��  -�����һ���µ�����
// ���������ֹ��ɣ�1����Ա���� (����) 2����Ա���� (������Ϊ)
// C++�е�struct����C�������÷���ͬʱC++�а�struct��������
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
// ��������У�һ�������������˵�(��Ա����)���ʶ���ɹ���
//                       ��������˷���(��Ա����)�ľͶ����˽�л򱣻�
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
	STDataType* a; // ��Ա����������������
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

// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};
// ����
class A3
{};

int main()
{
	cout << sizeof(A1) << endl;
	A1 aa;
	aa.f1();

	// ���ǵĴ�С��1��Ϊʲô�أ� ��С��1����1��byte����Ϊ�˴洢���ݣ���ռλ����ʾ������ڹ�
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